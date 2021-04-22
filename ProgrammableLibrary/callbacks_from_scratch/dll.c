/**
 * @Author: jamil
 * @Date:   2021-03-06T13:43:28-06:00
 * @Last modified by:   jamil
 * @Last modified time: 2021-04-22T13:47:31-05:00
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
   dll->search_function=NULL;
   return dll;
}

void
register_search_function(dll_t *dll,int (*search_function)(void *, void *)){
  dll->search_function=search_function;
}

void *
dll_search(dll_t *dll, void *key){

  if (!dll || !dll->head) return NULL;

  dll_node_t *head=dll->head;
  while(head){
    if(dll->search_function(head->data,key)==0)
      return (void *)head->data;   //casting the return type as a void type
                                    //pointer for the library function return to be
                                    //agnostic of the application data type
    head=head->right;
  }
  return NULL;
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
