#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "hashMap.h"

struct hashLink {
	KeyType key; /*the key is what you use to look up a hashLink*/
	ValueType value; /*the value stored with the hashLink, a pointer to int in the case of concordance*/
	struct hashLink * next; /*notice how these are like linked list nodes*/
};
typedef struct hashLink hashLink;

struct hashMap {
	hashLink ** table; /*array of pointers to hashLinks*/
	int tableSize; /*number of buckets in the table*/
	int count; /*number of hashLinks in the table*/
};
typedef struct hashMap hashMap;

/*the first hashing function you can use*/
int stringHash1(char * str)
{
	int i;
	int r = 0;
	for (i = 0; str[i] != '\0'; i++)
		r += str[i];
	return r;
}

/*the second hashing function you can use*/
int stringHash2(char * str)
{
	int i;
	int r = 0;
	for (i = 0; str[i] != '\0'; i++)
		r += (i+1) * str[i]; /*the difference between stringHash1 and stringHash2 is on this line*/
	return r;
}

/* initialize the supplied hashMap struct*/
void _initMap (struct hashMap * ht, int tableSize)
{
	int index;
	if(ht == NULL)
		return;
	ht->table = (hashLink**)malloc(sizeof(hashLink*) * tableSize);
	ht->tableSize = tableSize;
	ht->count = 0;
	for(index = 0; index < tableSize; index++)
		ht->table[index] = NULL;
}

/* allocate memory and initialize a hash map*/
hashMap *createMap(int tableSize) {
	assert(tableSize > 0);
	hashMap *ht;
	ht = malloc(sizeof(hashMap));
	assert(ht != 0);
	_initMap(ht, tableSize);
	return ht;
}

/*
   Free all memory used by the buckets.
   */
void _freeLinks (struct hashLink **table, int tableSize)
{
	hashLink * temp;

	int i;
	for(i = 0; i < tableSize; i++)
	{
		while(table[i] != 0)
		{
			temp = table[i];
			table[i] = table[i]->next;
			free(temp);
		}
	}
}

/* Deallocate buckets, table, and hashTable structure itself.*/
void deleteMap(hashMap *ht) {


	assert(ht!= 0);
	/* Free all memory used by the buckets */
	_freeLinks(ht->table, ht->tableSize);
	/* Free the array of buckets */
	free(ht->table);
	/* free the hashMap struct */
	free(ht);
}

/*
   Resizes the hash table to be the size newTableSize
   */
void _setTableSize(struct hashMap * ht, int newTableSize)
{
	hashMap * temp = createMap(newTableSize);

	int i;
	for(i = 0; i < ht->tableSize; i++)
	{
		if(ht->table[i] == NULL)
		{
			continue;
		}

		hashLink * curr = ht->table [i];

		do
		{
			insertMap(temp, curr->key, curr->value);
			curr = curr->next;
		}while(curr != NULL);
	}

	_freeLinks(ht->table, ht->tableSize);
	ht->count = temp->count;
	ht->table = temp->table;
	ht->tableSize = temp->tableSize;

	temp->table = NULL;
	free(temp);
}

/*
   insert the following values into a hashLink, you must create this hashLink but
   only after you confirm that this key does not already exist in the table. For example, you
   cannot have two hashLinks for the word "taco".

   if a hashLink already exists in the table for the key provided you should
   replace the value for that key.  As the developer, you DO NOT FREE UP THE MEMORY FOR THE VALUE.
   We have to leave that up to the user of the hashMap to take care of since they may or may not
   have allocated the space with malloc.


   Also, you must monitor the load factor and resize when the load factor is greater than
   or equal LOAD_FACTOR_THRESHOLD (defined in hashMap.h).
   */
void insertMap (struct hashMap * ht, KeyType k, ValueType v)
{
	int index = stringHash1(k) % ht->tableSize;
	if(index < 0)
	{
		index += ht->tableSize;
	}

	hashLink * temp = ht->table[index];

	if(temp == NULL)
	{
		temp = malloc(sizeof(hashLink*));
		assert(temp != 0);
		temp->value = v;
		temp->key = k;
		temp->next = NULL;
	}
	else
	{
		while(temp)
		{
			if(strcmp(temp->key, k) == 0)
			{
				temp->value = v;
				return;
			}
			temp = temp->next;	
		}

		hashLink * newlink = malloc(sizeof(hashLink *));
		assert(newlink != 0);
		newlink->value = v;
		newlink->key = k;
		temp->next = newlink;
	}
	ht->count++;


	float loadfactor = ((float)ht->count) / ht->tableSize;
	if(loadfactor >= LOAD_FACTOR_THRESHOLD)
	{
		_setTableSize(ht, ht->tableSize*2);
	}
}

/*
   this returns the value (which is void*) stored in a hashLink specified by the key k.

   if the user supplies the key "taco" you should find taco in the hashTable, then
   return the value member of the hashLink that represents taco.

   if the supplied key is not in the hashtable return NULL.
   */
ValueType atMap (struct hashMap * ht, KeyType k)
{
	int index = stringHash1(k) % ht->tableSize;

	if(index < 0)
	{
		index += ht->tableSize;
	}

	hashLink * curr = ht->table[index];

	while(curr != NULL)
	{
		if(strcmp(curr->key, k) == 0)
		{
			return curr->value;
		}
		curr = curr->next;
	}
	return NULL;
}

/*
   a simple yes/no if the key is in the hashtable.
   0 is no, all other values are yes.
   */
int containsKey (struct hashMap * ht, KeyType k)
{
	//Find correct bucket, the check to see if 
	//element is in that linked list.
	int index = stringHash1(k) % ht->tableSize;

	if(index < 0)
	{
		index += ht->tableSize;
	}

	hashLink * curr = ht->table[index];

	while(curr != NULL)
	{
		if(strcmp(curr->key, k) == 0)
		{
			return 1;
		}
		curr = curr->next;
	}
	return 0;
}

/*
   find the hashlink for the supplied key and remove it, also freeing the memory
   for that hashlink. it is not an error to be unable to find the hashlink, if it
   cannot be found do nothing (or print a message) but do not use an assert which
   will end your program.
   */
void removeKey (struct hashMap * ht, KeyType k)
{
	int index = stringHash1(k) % ht->tableSize;
	hashLink * remove;

	if(index < 0)
	{
		index += ht->tableSize;
	}
	hashLink * temp = ht->table[index];


	while(temp != 0)
	{
		if(strcmp(temp->key, k) == 0)
		{
			remove = temp->next;
			temp->next = temp->next->next;
			free(remove->value);
			free(remove->key);
			free(remove);
			ht->count--;
			return;
		}
		temp = temp->next;
	}
	return;
}

/*
   returns the number of hashLinks in the table
   */
int size (struct hashMap *ht)
{
	return ht->count;

}

/*
   returns the number of buckets in the table
   */
int capacity(struct hashMap *ht)
{
	return ht->tableSize;
}

/*
   returns the number of empty buckets in the table, these are buckets which have
   no hashlinks hanging off of them.
   */
int emptyBuckets(struct hashMap *ht)
{
	int empty = 0;
	int i;

	for(i = 0; i < ht->tableSize; i++)
	{
		if(ht->table[i] == 0)
		{
			empty++;
		}
	}
	return empty;
}

/*
   returns the ratio of: (number of hashlinks) / (number of buckets)

   this value can range anywhere from zero (an empty table) to more then 1, which
   would mean that there are more hashlinks then buckets (but remember hashlinks
   are like linked list nodes so they can hang from each other)
   */
float tableLoad(struct hashMap *ht)
{
	float table = (float)ht->count/ht->tableSize;

	return table;
}

/* print the hashMap */
void printMap (struct hashMap * ht, keyPrinter kp, valPrinter vp)
{
	int i;
	struct hashLink *temp;
	for(i = 0;i < capacity(ht); i++){
		temp = ht->table[i];
		if(temp != 0) {
			printf("\nBucket Index %d -> ", i);
		}
		while(temp != 0){
			printf("Key:");
			(*kp)(temp->key);
			printf("| Value: ");
			(*vp)(temp->value);
			printf(" -> ");
			temp=temp->next;
		}
	}
}

/* print the keys/values ..in linear form, no buckets */
void printKeyValues (struct hashMap * ht, keyPrinter kp, valPrinter vp)
{
	int i;
	struct hashLink *temp;
	for(i = 0;i < capacity(ht); i++){
		temp = ht->table[i];
		while(temp != 0){
			(*kp)(temp->key);
			printf(":");
			(*vp)(temp->value);
			printf("\n");
			temp=temp->next;
		}
	}
}
