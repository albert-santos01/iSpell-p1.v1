//
// EDA2
//

#include "generate_candidates.h"
#include "linked_list.h"
#include "utils.h"

void candidates_by_substitution(char* word,HashTable *d, HashTable *suggestions) {

    char *candidate;
    int l= strlen(word);
    char c;
    int i;
    for(i=0;i<l;i++) {
        candidate = (char*)malloc((l+2)*sizeof(char));
        strcpy(candidate,word);
        candidate
        for (c = 'a'; c <= 'z'; c++) {


            if(find_word_info(d,candidate)) {
                insert_word_info(suggestions,candidate);
            }
        }
    }

}


void candidates_by_insertion(char* word, HashTable *d, HashTable *suggestions) {
    char *candidate;
    int l= strlen(word);
    char c;
    int i;
    for(i=0;i<l;i++) {
        candidate = (char*)malloc((l+1)*sizeof(char));
        strcpy(candidate,word);
        for (c = 'a'; c <= 'z'; c++) {
            swap_to_position(candidate,c,i);
            if(find_word_info(d,candidate)) {
                insert_word_info(suggestions,candidate);
            }
        }
    }


    
}



void candidates_by_swapping(char* word, HashTable *d, HashTable *suggestions) {



}

void candidates_by_deletion(char* word, HashTable *d, HashTable *suggestions) {

   
}

void generate_candidates(char* word,HashTable *dict,HashTable *substitutes) {
    init_table(substitutes,"Substitutions");
    candidates_by_substitution(word,dict,substitutes);
    candidates_by_insertion(word,dict,substitutes);
    candidates_by_swapping(word,dict,substitutes);
    candidates_by_deletion(word,dict,substitutes);
}