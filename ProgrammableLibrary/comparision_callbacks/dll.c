/**
 * @Author: jamil
 * @Date:   2021-03-06T13:43:28-06:00
 * @Last modified by:   jamil
 * @Last modified time: 2021-03-07T23:02:23-06:00
 */
#include "dll.h"
#include <memory.h>
#include <stdlib.h>

/* Public Function Implementation to create and return
* new empty doubly linked list*/

dll_t *
get_new_dll(){

   dll_t *dll = calloc(1, sizeof(dll_t));
   dll->head = NULL;
   dll->key_match = NULL;
   dll->comparison_fn=NULL;
   return dll;
}

void
register_key_match_callback(dll_t *dll,
                             int (*key_match)(void *, void *)){

    dll->key_match = key_match;
}

void
register_comparison_callback(dll_t *dll,
                            int (*comparison_cb)(void *, void *)){

    dll->comparison_fn = comparison_cb;
}

/*Generic Search function*/
void *
dll_search_by_key (dll_t *dll, void *key){

    if(!dll || !dll->head) return NULL;

    dll_node_t *head = dll->head;

    while(head){
        if(dll->key_match(head->data, key) == 0)
            return (void *)head->data;
        head = head->right;
    }
    return NULL;
}


int
dll_priority_insert_data (dll_t *dll, void *data){

    if(!dll)
        return -1;

    /*if DLL is empty or the first entry is less than incoming entry
    -1 means second term is big, +1 means first term is big*/
    if(!dll->head || dll->comparison_fn(dll->head->data, data) == -1){
        add_data_to_dll(dll, data);
        return 0;
    }
    else {
        dll_node_t *data_node = calloc(1, sizeof(dll_node_t));
        data_node->data = data;
        data_node->left = NULL;
        data_node->right = NULL;
        dll_node_t *current = dll->head;
        while (current->right != NULL
              && dll->comparison_fn(current->right->data, data)== 1){
                current=current->right;
              }
        data_node->right=current->right;
        data_node->left=current;
        current->right=data_node;
      }
    return 1;
}
/* Public Function Implementation to add a new application
*  * data to DLL */
int
add_data_to_dll (dll_t *dll, void *app_data){

   if(!dll || !app_data) return -1;

   dll_node_t *dll_new_node = calloc(1, sizeof(dll_node_t));
   dll_new_node->left = NULL;
   dll_new_node->right = NULL;
   dll_new_node->data = app_data;

   /*Now add this to the front of DLL*/
   if(!dll->head){
       dll->head = dll_new_node;
       return 0;
   }

   dll_node_t *first_node = dll->head;
   dll_new_node->right = first_node;
   first_node->left = dll_new_node;
   dll->head = dll_new_node;
   return 0;
}
