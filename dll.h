/**
 * @Author: jamil
 * @Date:   2021-02-19T23:39:31-06:00
 * @Last modified by:   jamil
 * @Last modified time: 2021-02-19T23:47:22-06:00
 */



/*
 * =====================================================================================
 *
 *       Filename:  dll.h
 *
 *    Description: Header file containing the data structures of a doubly link list
 *
 *        Version:  1.0
 *        Created:  02/19/2021 22:12:53
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jamil Hasibul (https://sites.google.com/site/jamilhasibul113/,   https://github.com/H-jamil ), mdhasibul.jamil@siu.edu
 *   Organization:  Southern Illinois University Carbondale
 *
 * =====================================================================================
 */

#ifndef __DLL__
#define __DLL__
#include <stdio.h>
#include <stdlib.h>

typedef struct dll_node_{
    void *data;
    struct dll_node_ *left;
    struct dll_node_ *right;
    }dll_node_t;


typedef struct dll_{
    struct dll_node_t *head;
    }dll_t;

dll_t *
get_new_dll();

int
add_data_to_dll(dll_t *dll, void *app_data);

#endif
