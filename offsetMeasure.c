/*
 * =====================================================================================
 *
 *       Filename:  offsetMeasure.c
 *
 *    Description: prints the offset of any field of a struct
 *
 *        Version:  1.0
 *        Created:  02/18/2021 10:04:07
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jamil Hasibul (https://sites.google.com/site/jamilhasibul113/,   https://github.com/H-jamil ), mdhasibul.jamil@siu.edu
 *   Organization:  Southern Illinois University Carbondale
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "glthread.h"

/* following macro calculates the offset of a field in a given structure */

/*  #define offsetof(struct_name,field_name) \
    (unsigned int)&(((struct_name *)0)->field_name)
*/

#define offset(struct_name, fld_name) \
    (unsigned int)&(((struct_name *)0)->fld_name)

typedef struct emp_{
    char name[28];
    unsigned int salary;
    char designation[20];
    unsigned int emp_id;
    glthread_t glthread;
    } emp_t;

//GLTHREAD_TO_STRUCT(thread_to_person, emp_t, glthread);

int main(int argc, char **argv){
    //emp_t *person1=calloc(1,sizeof(emp_t));
    //emp_t person1;
    unsigned int offsetValue;
    offsetValue=offset(emp_t,salary);
    printf("field = %s\n","salary");
    printf("offset = %d\n", offsetValue);
    return 0;
    }
