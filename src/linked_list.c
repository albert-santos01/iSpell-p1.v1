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
    if (l->start != NULL)
        l->start->prev = newElem;
    newElem->prev = NULL;

    l->start = newElem;
}

/**
 * TODO: Iterates over the different nodes searching for a WordInfo that contains the given word.
 * Returns: A pointer to the node if found or NULL otherwise.
*/
Node* find_in_list(LinkedList l, char* word) {
    // YOUR CODE HERE
}

/**
 * TODO: Given a node and the list it belongs to, it removes it from the list freeing
 * its memory. It accounts for the start, and the prev/next pointers.
*/
void delete_node(LinkedList* l, Node* p) {
    // YOUR CODE HERE
}

/**
 * TODO: If a node in the list contains a WordInfo with the given word, it deletes it.
 * Returns true if a node was deleted and false otherwise.
*/
bool delete_from_list(LinkedList* l, char* word) {
    // YOUR CODE HERE
}

/**
 * TODO: Prints all word infos of the list using print_word_info.
*/
void print_list(LinkedList l) {
    Node* p;
    for (p = l.start; p != NULL; p = p->next)
        printf("%s\n", p->data);
}

