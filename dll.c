/**
 * @Author: jamil
 * @Date:   2021-02-19T23:43:33-06:00
 * @Last modified by:   jamil
 * @Last modified time: 2021-02-19T23:45:11-06:00
 */



/*
 * =====================================================================================
 *
 *       Filename:  dll.c
 *
 *    Description:  Contains all the function bodies of the doubly link list
 *
 *        Version:  1.0
 *        Created:  02/19/2021 22:57:29
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jamil Hasibul (https://sites.google.com/site/jamilhasibul113/,   https://github.com/H-jamil ), mdhasibul.jamil@siu.edu
 *   Organization:  Southern Illinois University Carbondale
 *
 * =====================================================================================
 */

#include "dll.h"
#include <memory.h>

 dll_t *
 get_new_dll(){

    dll_t *dll=calloc(1,sizeof(dll_t));
    dll->head=NULL;
    return dll;
 }
/* Function implement the new nodes in a LIFO manner or create a stack */
 int
 add_data_to_dll(dll_t *dll,void *app_data){
    if (!dll || !app_data)
        return -1;
    dll_node_t *dll_new_node=calloc(1,sizeof(dll_node_t));
    dll_new_node->left=NULL;
    dll_new_node->right=NULL;
    dll_new_node->data=app_data;

    if (!dll->head){
        dll->head=dll_new_node;
        return 0;
    }
    dll_node_t *first_node=dll->head;
    first_node->left=dll_new_node;
    dll_new_node->right=first_node;
    dll->head=dll_new_node;
    return 0;
  }
