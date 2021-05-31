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
    for(i=0; i < l ; i++) {
        candidate = (char*)malloc((l)*sizeof(char));
        strcpy(candidate,word);
        for (c = 'a'; c <= 'z'; c++) {
            candidate[i]=c;
            if(find_word_info(d,candidate)) {
                insert_word_info(suggestions,candidate);
            }
        }
    }
}



void candidates_by_insertion(char* word, HashTable *d, HashTable *suggestions) {
    char *candidate;
    int l = strlen(word);
    char c;
    for (c = 'a'; c <= 'z'; c++) {
        for (int c_position = 0; c_position < l + 1; ++c_position) {
            candidate = (char *) malloc((l + 1) * sizeof(char));
            int word_cont = 0;
            int contador = 0;
            for (int i = 0; i < c_position; ++i) {
                candidate[i] = word[word_cont];
                word_cont++;
                contador++;
            }
            candidate[c_position] = c;
            contador++;
            for (int j = contador; j < l + 1; ++j) {
                candidate[j] = word[word_cont];
                word_cont++;
            }
            if (find_word_info(d, candidate)) {
                insert_word_info(suggestions, candidate);
            }
        }
    }
}



void candidates_by_swapping(char* word, HashTable *d, HashTable *suggestions) {
    char *candidate;
    int l = strlen(word);
    char c;
    for (int c_position = 0; c_position < l; ++c_position) {
        int c2_position = c_position + 1;
        candidate = (char *) malloc((l) * sizeof(char));
        int word_cont = 0;
        int contador = 0;
        for (int i = 0; i < c_position; ++i) {
            candidate[i] = word[word_cont];
            word_cont++;
            contador++;
        }
        candidate[word_cont] = word[c2_position];
        word_cont++;
        candidate[word_cont] = word[c_position];
        word_cont++;

        for (int j = contador+2; j < l; ++j) {
            candidate[word_cont] = word[j];
            word_cont++;
        }
        if (find_word_info(d, candidate)) {
            insert_word_info(suggestions, candidate);
        }
    }


}

void candidates_by_deletion(char* word, HashTable *d, HashTable *suggestions) {

    char *candidate;
    int l = strlen(word);
    char c;
    for (int c_position = 0; c_position < l; ++c_position) {
        candidate = (char *) malloc((l - 1) * sizeof(char));
        int word_cont = 0;
        int contador = 0;
        for (int i = 0; i < c_position; ++i) {
            candidate[i] = word[word_cont];
            word_cont++;
            contador++;
        }
        contador++;

        for (int j = contador; j < l; ++j) {
            candidate[word_cont] = word[j];
            word_cont++;
        }
        if (find_word_info(d, candidate)) {
            insert_word_info(suggestions, candidate);
        }
    }
   
}

void generate_candidates(char* word,HashTable *dict,HashTable *substitutes) {
    init_table(substitutes,"Substitutions");
    candidates_by_substitution(word,dict,substitutes);
    candidates_by_insertion(word,dict,substitutes);
    candidates_by_swapping(word,dict,substitutes);
    candidates_by_deletion(word,dict,substitutes);
}