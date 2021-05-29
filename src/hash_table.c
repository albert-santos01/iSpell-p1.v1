#include "hash_table.h"



/**
 * Hash function by plegamiento
 *
 */

int hash_mod(char *word,int n) {

    int l= strlen(word);
    char c;
    int total=0;
    for (int i = 0; i <l ; ++i) {
        total += word[i]* pow(10,l-i);
    }
    //TODO: Mirar si delvolver -1 en caso de wtf
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
 *  Clears all lists leaving the HashTable struct as if it was just initialized.
*/
void clear_table(HashTable* dictionary) {
    for (int i = 0; i < N; ++i) {
        clear_list(&dictionary->list[i]);
    }
    dictionary->size=0;
    strcpy(dictionary->name,"empty");

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
    int has_key= hash_mod(word,N);
    if(find_word_info(dictionary,word)){
        return false;
    } else{
        insert_into_list(&dictionary->list[has_key],word);
        dictionary->size++;
        return true;
    }

}



/**
 * Deletes the WordInfo corresponding to word from the dictionary by checking from
 *  which list to delete it and calling delete_from_list.
 *  Returns true if a WordInfo for the given word was present in the dictionary
 *  and could be deleted succesfully or false otherwise.
*/
bool delete_word_info(HashTable* dictionary, char* word) {
    int has_key= hash_mod(word,N);
    dictionary->size--;
    return delete_from_list(&dictionary->list[has_key],word);

     // YOUR CODE HERE
}



/**
 * TODO: PREGUNTAR SI SE HACE ASI PUTA!!!!!!!!!!!!!!!!!!!!!!1111
 *
 * Prints the number of words in the dictionary followed by the words in the dictionary.
    if empty, it prints "The dictionary is empty".
*/
void print_table(HashTable* dictionary) {
    // YOUR CODE HERE
    if (dictionary->size!=0){
        printf("The dictionary %s has %d words\n The words are:\n",dictionary->name,dictionary->size);
        for (int i = 0; i <N ; ++i) {
            print_list(dictionary->list[i]);
        }
    } else{
        printf("The dictionary is empty");
    }
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


