#include "hash_table.h"


/**
 * TODO: Hash function by plegamiento
 *
 */

int hash_mod(char *word,int n) {

    int l=strlen(word);
    char c;
    long long int total=0;
     
    // YOUR CODE HERE 
	
    return total%n;
}

/**
 * TODO: Initializes the members of the HashTable struct: its size and all the lists
*/
void init_table(HashTable* dictionary, char* name) {
    dictionary->size = 0;
    strcpy(dictionary->name, name);
    for (int i = 0; i < N; ++i)
        init_list(&(dictionary->list[i]));
}

/**
 * TODO: Clears all lists leaving the HashTable struct as if it was just initialized.
*/
void clear_table(HashTable* dictionary) {
   
   // YOUR CODE HERE
}

/**
 * TODO: Looks for a  word by checking which list to search
 *  and calling find_in_list.
 *  Returns true if the word exists and false otherwise
*/
bool find_word_info(HashTable* dictionary, char* word) {
    
    int hash_key = hash_mod(word,N);
    if (hash_key != -1){
        Node* n = find_in_list(dictionary->list[hash_key], word);
        if (n != NULL) {
            return true;

        }
    }
    return false;
}


/**
 * TODO: Inserts a word into the dictionary except if it exists already.  
 *  Returns true if insertion was successful or false otherwise.
*/
bool insert_word_info(HashTable* dictionary, char* word) {
   // YOUR CODE HERE
}



/**
 * TODO: Deletes the WordInfo corresponding to word from the dictionary by checking from
 *  which list to delete it and calling delete_from_list.
 *  Returns true if a WordInfo for the given word was present in the dictionary
 *  and could be deleted succesfully or false otherwise.
*/
bool delete_word_info(HashTable* dictionary, char* word) {
     // YOUR CODE HERE
}



/**
 * TODO: Prints the number of words in the dictionary followed by the words in the dictionary.
    if empty, it prints "The dictionary is empty".
*/
void print_table(HashTable* dictionary) {
    // YOUR CODE HERE
}

/**
 * TODO: Prints words in the dictionary a bucket at a time
*/
void print_table_by_bucket(HashTable* dictionary) {
    if (dictionary->size > 0){
        printf("%s has %i elements:\n", dictionary->name, dictionary->size);
        for (int i = 0; i < N; ++i) {
            printf("Bucket #%d\n", i);
            print_list(dictionary->list[i]);
        }
    } else {
        printf("The %s table is empty.\n", dictionary->name);
    }
}


