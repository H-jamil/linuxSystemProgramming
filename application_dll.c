/**
 * @Author: jamil
 * @Date:   2021-02-19T23:35:45-06:00
 * @Last modified by:   jamil
 * @Last modified time: 2021-02-19T23:48:15-06:00
 */



/*
 * =====================================================================================
 *
 *       Filename:  application_dll.c
 *
 *    Description: An test application source file containing all the test cases
 *
 *        Version:  1.0
 *        Created:  02/19/2021 23:18:38
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jamil Hasibul (https://sites.google.com/site/jamilhasibul113/,   https://github.com/H-jamil ), mdhasibul.jamil@siu.edu
 *   Organization:  Southern Illinois University Carbondale
 *
 * =====================================================================================
 */

#include "dll.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


/* Application specific data structure */


typedef struct person_ {
    char name[30];
    unsigned int age;
    unsigned int weight;
    }person_t;


void
print_person_details(person_t *person){
    printf("Name = %s\n",   person->name);
    printf("Age = %d\n",    person->age);
    printf("weight = %d\n", person->weight);
    }

void
print_person_db(dll_t *person_db) {

    if(!person_db || !person_db->head) return;

    dll_node_t *head = person_db->head;
    person_t *data = NULL;

    while(head){
        data = head->data;
        print_person_details(data);
        head = head->right;
    }
}

int
main(int argc, char **argv){

    person_t *person1 = calloc(1, sizeof(person_t));
    strncpy(person1->name, "Jamil", strlen("Jamil"));
    person1->age = 28;
    person1->weight = 90;
    person_t *person2 = calloc(1, sizeof(person_t));
    strncpy(person2->name, "Joseph", strlen("Joseph"));
    person2->age = 41;
    person2->weight = 70;
    person_t *person3 = calloc(1, sizeof(person_t));
    strncpy(person3->name, "Rosa", strlen("Rosa"));
    person3->age = 25;
    person3->weight =97 ;

    /*Create a new Linked List*/

    dll_t *person_db = get_new_dll();
    add_data_to_dll(person_db, person1);
    add_data_to_dll(person_db, person2);
    add_data_to_dll(person_db, person3);
    print_person_db(person_db);
    return 0;

}
