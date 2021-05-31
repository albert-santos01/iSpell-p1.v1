#include "linked_list.h"

/**
 * TODO: Initializes the start Node pointer so that the list is empty.
*/
void init_list(LinkedList* l) {
    l->start = NULL;
}

/**
 * TODO: Clears all the nodes of the list, freeing the memory and leaving the list as
 * it would have just been initialized.
*/
void clear_list(LinkedList *l) {
    Node* p;
    Node* q;
    for (p = l->start; p != NULL; p = q) {
        q = p->next;
        free(p);
    }
    l->start = NULL;
}

/**
 * TODO: Reserves memory for a new Node and inserts it in the given linked list,
 * changing the start pointer as well as the prev/next pointers accordingly.
*/
void insert_into_list(LinkedList* l, char* c) {
    Node* newElem = (Node*) malloc(sizeof(Node));
    strcpy(newElem->data, c);

    newElem->next = l->start;
    if (l->start != NULL){
        l->start->prev = newElem;
    }

    newElem->prev = NULL;

    l->start = newElem;
}

/**
 * Iterates over the different nodes searching for a WordInfo that contains the given word.
 * Returns: A pointer to the node if found or NULL otherwise.
*/
Node* find_in_list(LinkedList l, char* word) {
    // YOUR CODE HERE
    Node* aux= l.start;
    while (aux!=NULL){
        if(strcmp(aux->data, word) == 0){
            return aux;
        } else{
            aux = aux->next;
        }
    }
    return NULL;
}

/**
 *  Given a node and the list it belongs to, it removes it from the list freeing
 * its memory. It accounts for the start, and the prev/next pointers.
*/
void delete_node(LinkedList* l, Node* p) {
    // YOUR CODE HERE
    if (p->prev != NULL){
        p->prev->next = p->next;
    } else{
        l->start = p->prev;
    } if(p->next != NULL){
        p->next->prev = p->prev;
    }
    free(p);
}

/**
 *  If a node in the list contains a WordInfo with the given word, it deletes it.
 * Returns true if a node was deleted and false otherwise.
*/
bool delete_from_list(LinkedList* l, char* word) {
    // YOUR CODE HERE
    Node * aux= find_in_list(*l,word);
    if (aux != NULL){
        delete_node(l, aux);
        return true;
    }
    return false;
}

/**
 * TODO: Prints all word infos of the list using print_word_info.
*/
void print_list(LinkedList l) {
    Node* p;
    for (p = l.start; p != NULL; p = p->next){
        printf("%s\n", p->data);
    }

}

