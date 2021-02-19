#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include "glthread.h"

#define offset(struct_name, fld_name) \
    (unsigned int)&(((struct_name *)0)->fld_name)

typedef struct emp_ {
    char name[30];
    unsigned int salary;
    char designation[30];
    unsigned int emp_id;
    glthread_node_t glnode;
} emp_t;


struct emp_ *
start_address(glthread_node_t *node_t){
  unsigned int offsetValue;
  offsetValue=offset(emp_t,glnode);
  printf("offset = %d\n", offsetValue);
  // printf("glnode address received= %d\n", (unsigned int)node_t);
  return (struct emp_*)(node_t-offsetValue);
}

void
print_emp_details(emp_t *emp){

    // printf("emp_t address emp = %d\n", (unsigned int)emp);
    // // unsigned int calculatedValue;
    // // calculatedValue=(15 *(unsigned int)node_t+(unsigned int)emp1)/16;
    // // printf("calculatedValue of emp= %d\n",calculatedValue );
    // // emp_t *emp;
    // // emp=calculatedValue;
    // // printf("emp_t address emp= %d\n", (unsigned int)emp);
    printf("Employee name = %s\n", emp->name);
    printf("salary = %u\n", emp->salary);
    printf("designation = %s\n", emp->designation);
    printf("emp_id = %u\n", emp->emp_id);
}

// void
// print_emp_details(emp_t *emp){
//     // unsigned int offsetValue;
//     // offsetValue=offset(emp_t,glnode);
//     // printf("offset = %d\n", offsetValue);
//     // printf("glnode address received= %d\n", (unsigned int)node_t);
//     // emp_t *emp=node_t-offsetValue;
//     printf("emp_t address = %d\n", (unsigned int)emp);
//     printf("Employee name = %s\n", emp->name);
//     printf("salary = %u\n", emp->salary);
//     printf("designation = %s\n", emp->designation);
//     printf("emp_id = %u\n", emp->emp_id);
// }


int
main(int argc, char **argv){
  emp_t *emp1=calloc(1,sizeof(emp_t));
  // printf("Actual emp_t address before= %d\n", (unsigned int)emp1);
  strncpy(emp1->name,"Jamil", strlen("Jamil"));
  emp1->salary= 1000;
  strncpy(emp1->designation,"R&D Engineer",strlen("R&D Engineer"));
  emp1->emp_id=113;
  glthread_node_init((&emp1->glnode));
  // printf("glnode address send= %d\n", (unsigned int)(&emp1->glnode));
  print_emp_details(start_address(&emp1->glnode));
  //print_emp_details(emp1);
  // printf("Actual emp_t address after= %d\n", (unsigned int)emp1);

  return 0;
}
