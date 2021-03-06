/**
* @Author: jamil
* @Date:   2021-03-06T13:43:28-06:00
 * @Last modified by:   jamil
 * @Last modified time: 2021-03-06T13:45:26-06:00
*/
/*Header file for Doubly Linked List*/

typedef struct dll_node_{

   void *data;
   struct dll_node_ *left;
   struct dll_node_ *right;
} dll_node_t;

typedef struct dll_{
   dll_node_t *head;
} dll_t;


/* Public Function declaration to create and return
* a new empty doubly linked list*/
dll_t *
get_new_dll();

/*  Public Function declaration to add the appication
*  data to DLL*/
int
add_data_to_dll(dll_t *dll, void *appn_data);
