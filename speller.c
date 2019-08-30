#include <stdio.h>

//TODO
// 1. Load: loads the dictionary into that data structure we've created
// 2. Check: checks that data structure to see if a given word is in the dictionary
// 3. size: returns the number of words in the dictionary
// 4. unload: frees the dictionary from memory

int main(void)
{
	
	//linked lists 
	typedef struct node
	{
		char word[LENGTH +1];
		struct node *next;
	
	}
	node;
	node *node1 = malloc(sizeof(node));
	
	//Creating another space for the second node in memory
	node *node2 = malloc(sizeof(node));
	
	// Setting values for these node pointers using pointers
	// Note these are two inpendent nodes
	strcpy(node1->word, "Hello");
	strcpy(node2->word, "World");
	
	// How to link the inpedendenet nodes above
	node1->next = node2;
	
	// hash table is a linked list
	typedef struct node
	{
		char word [length + 1]
		struct node *next;
	}
	node;
	node *hasgtable[50];
	
	
	// Populate the hashtable with nodes containing dictionary words
	// make new word
	// scan dictionary word
	// complete the while loop does that
	while(fscan(file, "%s", word) ! = EOF)
	{
		...
	}
	
	// What goes inside the loop?
	// make a new word
	// malloc a node * for each new word
	// Below has to happen everytime malloc an new node
	node *new_node = malloc(sizeof(node));
	if (new_node == NULL)
	{
		unload();
		return false;
	}
	
	// if malloc succeeds
	// copy word into node
	strcpy(new_node->word, word);
	
	// How to insert into a linked list: correct
	// should alway point to beginning 
	new_node->next = head;
	// then assign the header to new node
	head = new_node
	
	// Hash function decides which words to which links
	// 1. takes a string
	// 2. returns an index
	// 		index < hte number of buckets
	// 3. deterministic
	//		the same value need to map to the same
	//		bucket every time 
	
	// after done with hash function
	// hash the word
	// 1. new_node->word has the word from the dictionary
	// 2. hashing new_node->wordd will give us the index of a bucket
	// 		in te hash table
	// 3. insert into the linked list
	// 4. link
	
	
	//Check
	/*
	 if the word exists, it can be found in the hash table
	 * which bucket would the word be in? hashtable[hash(word)]
	 * search in that linked list. strcasecmp  
	*/
	
	// traversing linked lists
	node *cursor = head;
	while (cursor !=NULL)
	{
		// do something
		cursor = cursor->next;
	}
	
	// freeing linked lists
	node *cursor = head;
	while (cursor !=NULL)
	{
		node *temp = cursor;
		cursor = cursor->next;
		free(tem);
	}

	valgrind -v --leak-check=full austinposwers.txt

}

//load
bool(const char* dictionary)
{
	FILE* fp = fopen(dictionary, "r");
	if (fp == NULL)
	{
		printf("Unable to open dictionary\n");
		return false;
	}
	node* new_node = NULL;
	
	while(!feof(fp))
	{
		new_node = malloc(sizeof(node));
		fscanf(fp, "%s", new_node->word);
		int index = 0;
		index = (tolower(new_node->word[0]) -'a') % 26;
	}
}
    // Insert words into hash table
while (fscanf(file, "%s", word) != EOF)
    {
        // First, create a node using malloc so that you can insert the word into the hash table
        node *newNode = malloc(sizeof(node));
        // Check to make sure the pointer does not return null... i.e. make sure it succeed
        if (newNode == NULL)
        {
            unload();
            return false;
        }
        //insert words into nodes, setting values to these nodes using strcpy
        strcpy(newNode->word, word);
        //link the nodes until the end i.e. NULL
        newNode->next = NULL;
        //increase loadedWords count to keep track
        loadedWords++;
        //insert linked list to hashtable
        int x = hashValue(newWord);

        //if the linked list is empty
        if (hashTable[x] == NULL)
        {
            hashTable[x] = newNode;
        }
        //if you need to insert into an existing linked list...
        else
        {
            newNode->next = hashTable[x];
            hashTable[x] = newNode;
        }
       // Close dictionary
    fclose(file);

    // Indicate success
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return loadedWords;
}
// Returns true if word is in dictionary else false
// Check if word is in dictionary, if it is, return true
bool check(const char *word)
{
    //convert all words to lowercase to simplify ASCII values process
    //first, create a new int so you can modify the input words... because const means you are using constant reference to the original input words and hence cannot modify it
    int length = strlen(word);
    char *newWord = malloc(length);

    //copy the newWord and make them lowercase
    for (int j = 0; j < length; j++)
    {
        newWord[j] = tolower(word[j]);
    }
    //Run data through hash function
    int x = hashValue(word);
    //declare the head of nodes
    node *head = NULL;
    //cursor to the head of nodes
    node *cursor = head = hashTable[x];
    //identify the linked list to search
    while (hashTable[x] != NULL)
    {
        //compare the two strings
        if (strcmp(cursor->word, word) == 0)
        {
            return true;
            cursor = cursor->next;
        }
        //continue to go through the lists to find the right linked list
        if (strcmp(newWord, cursor->word) == 0)
        {
            return true;
            cursor = cursor -> next;
        }

    }

    return false;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    //go into each bucket
    for (int k = 0; k < N; k++)
    {
        node *cursor = hashTable[k];
        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor -> next;
            free(temp);
        }
    }
    return false;
}
