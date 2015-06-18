/**
 * dictionary.h
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Declares a dictionary's functionality.
 */

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>

// maximum length for a words
#define LENGTH 45

// size of hash-table array
#define HASHSIZE 160000

/**
 * Nodes for each word in the dictionary.
 */
typedef struct node {
	char word[LENGTH + 1];
	struct node* next;
}
node;

/**
 * Create new node with word and a null next pointer. 
 * Returns pointer to the new node if successful, else NULL.
 */
node* create(const char* word);

/**
 * Insert node pointed to by inserting at sorted position in the linked list beginning with head. 
 * Returns the pointer to the head of the linked list.
 */
node* insert(node* inserting, node* head);

/**
 * Copies a string s to t in lower case.
 */
void stotlower(char* t, const char* s);

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word);

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary);

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void);

/**
 * Unloads dictionary from memory.  Returns true if successful.
 */
bool unload(void);

#endif // DICTIONARY_H
