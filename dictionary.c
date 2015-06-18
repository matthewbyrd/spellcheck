/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 *
 * Relies on dictionary being a list of newline-demarcated unique lower-case words.
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "dictionary.h"

/**
 * Array for the hashtable.
 */
node* table[HASHSIZE];

/**
 * Create new node with word and a null next pointer. 
 * Returns pointer to the new node if successful, else NULL.
 */
node* create(const char* word)
{
	// allocate memory for the node
	node* new = malloc(sizeof(node));
	if (new == NULL)
	{
		printf("CREATE ERROR: cannot assign memory for new node\n");
		return NULL;
	}
	
	// set up the node
	if (strlen(word) <= LENGTH)
	{
		strcpy(new->word, word);
		new->next = NULL;
		return new;
	}
	else
	{
		printf("CREATE ERROR: word [%s] exceeds maximum length\n", word);
		return NULL;
	}
}

/**
 * Insert node pointed to by inserting at sorted position in the linked list beginning with head. 
 * Returns the pointer to the head of the linked list.
 */
node* insert(node* inserting, node* head)
{
	node* ptr = head;
	node* prev = head;
	
	if (head == NULL)
	{
		head = inserting;
		return head;
	}
	
	while ( ptr != NULL && strcmp(ptr->word, inserting->word) < 0 )
	{
		prev = ptr;
		ptr = ptr->next;
	}
	
	if (ptr == head)
	{
		inserting->next = head;
		head = inserting;
	}
	else 
	{
		inserting->next = ptr;
		prev->next = inserting;
	}
	
	return head;
}

/**
 * Form hashval for string s.
 */
unsigned int hash(char* s)
{
	unsigned hashval;
	
	for (hashval = 0; *s != '\0'; s++)
	{
		hashval = tolower(*s) + 31 * hashval;
	}
	return hashval % HASHSIZE;
}

/**
 * Converts a string s to lower case.
 */
void stolower(char* s)
{
	while (*s++ != '\0')
	{
		tolower(*s);
	}
}


/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    node* ptr = table[hash(word)];
	while (ptr != NULL)
	{
		if 
	}
}

/**
 * Loads dictionary into memory.  
 * Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // open the dictionary file
	FILE* dict_file = fopen(dictionary, "r");
	
	if (dict_file == NULL)
	{
		return false;
	}
	
	char word[LENGTH + 1];
	node temp;
	int hashval;
	
	// read the file word by word
	while (fscanf(dict_file, "%s", word) == 1)
	{
		// create a node for new word
		temp = *create(word);
		
		// get the hash value
		hashval = hash(word);
		
		// add that word into the appropriate place in the hashtable
		table[hashval] = insert(&temp, table[hashval]);
	}
	return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return 0;
}

/**
 * Unloads dictionary from memory.  
 * Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    return false;
}
