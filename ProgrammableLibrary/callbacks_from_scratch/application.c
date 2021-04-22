/**
 * @Author: jamil
 * @Date:   2021-03-06T13:43:28-06:00
 * @Last modified by:   jamil
 * @Last modified time: 2021-04-22T13:48:59-05:00
 */

 #include "dll.h"
 #include <stdlib.h>
 #include <string.h>
 #include <stdio.h>

 /*Application specific data structures*/
 typedef struct student_{

     char name[32];
     int age;
     int weight;
     unsigned int rollno;
 } student_t;

/*
static keyword insures that the function is local to this applicaton.c
file only. No other file could access it. This enables a differrent file to
have same name function.
*/

 static void
 print_student_details(student_t *student){

     printf("Name = %s\n",   student->name);
     printf("Age = %d\n",    student->age);
     printf("weight = %d\n", student->weight);
     printf("rollno = %u\n", student->rollno); //%u formats only unsigned int type
 }

 static void
 print_student_db(dll_t *student_db) {

     if(!student_db || !student_db->head) return;

     dll_node_t *head = student_db->head;
     student_t *data = NULL;

     while(head){
         data = head->data;
         print_student_details(data);
         head = head->right;
     }
 }

 /*Application specific data structures*/
 typedef struct employee_{

     char name[32];
     char designation[32];
     unsigned int salary;
     unsigned int emp_id;
 } employee_t;

 static void
 print_employee_details(employee_t *employee){

     printf("Name = %s\n",   employee->name);
     printf("Designation = %s\n",    employee->designation);
     printf("salary = %u\n", employee->salary);
     printf("emp_id = %u\n", employee->emp_id);
 }

 static void
 print_employee_db(dll_t *student_db) {

     if(!student_db || !student_db->head) return;

     dll_node_t *head = student_db->head;
     student_t *data = NULL;

     while(head){
         data = head->data;
         print_student_details(data);
         head = head->right;
     }
 }

 /*Search function specific to this application of seraching
 student*/

 student_t *
 search_student_by_rollno(dll_t *student_db,
                          unsigned int rollno/*search key*/){

     if(!student_db || !student_db->head) return NULL;

     dll_node_t *head = student_db->head;
     student_t *data = NULL;

     while(head){
         data = head->data;
         if(data->rollno == rollno)
             return data;
         head = head->right;
     }
 }


 /*Search function specific for application of employee*/

 employee_t *
 search_employee_by_emp_id(dll_t *employee_db,
                          unsigned int emp_id/*search key*/){

     if(!employee_db || !employee_db->head) return NULL;

     dll_node_t *head = employee_db->head;
     employee_t *data = NULL;

     while(head){
         data = head->data;
         if(data->emp_id == emp_id)
             return data;
         head = head->right;
     }
 }


 static int
 search_student_dll_by_rollno(void *data, void *key){
   student_t *student= (student_t *)data;
   unsigned int rollno= *(unsigned int *)key;
   if (student->rollno==rollno)
      return 0;
  return -1;
 }

 static int
 search_employee_dll_by_emid(void *data, void *key){
   employee_t *employee= (employee_t *)data;
   unsigned int emp_id= *(unsigned int *)key;
   if (employee->emp_id==emp_id)
      return 0;
  return -1;
 }

 int
 main(int argc, char **argv){

     /*Student database*/
     student_t *student1 = calloc(1, sizeof(student_t));
     strncpy(student1->name, "Jamil", strlen("Jamil"));
     student1->age = 31;
     student1->weight = 75;
     student1->rollno = 800000;

     student_t *student2 = calloc(1, sizeof(student_t));
     strncpy(student2->name, "Joseph", strlen("Joseph"));
     student2->age = 41;
     student2->weight = 70;
     student2->rollno = 800400;

     student_t *student3 = calloc(1, sizeof(student_t));
     strncpy(student3->name, "Rosa", strlen("Rosa"));
     student3->age = 25;
     student3->weight = 55;
     student3->rollno = 800300;

     /*Create a new Linked List*/

     dll_t *student_db = get_new_dll();
     register_search_function(student_db,search_student_dll_by_rollno);
     add_data_to_dll(student_db, student1);
     add_data_to_dll(student_db, student2);
     add_data_to_dll(student_db, student3);
     unsigned int searched_student_rollno=800400;
     student_t *student=(student_t *)(dll_search(student_db,(void *)&(searched_student_rollno)));
     if(!student){
         printf("Student record not found\n");
     }
     else{
         print_student_details(student);
     }

     /*Employee database*/
     employee_t *employee1 = calloc(1, sizeof(employee_t));
     strncpy(employee1->name, "Jamil", strlen("Jamil"));
     strncpy(employee1->designation, "President", strlen("President"));
     employee1->salary = 11131;
     employee1->emp_id = 10000;

     employee_t *employee2 = calloc(1, sizeof(employee_t));
     strncpy(employee2->name, "Huma", strlen("Huma"));
     strncpy(employee2->designation, "Manager", strlen("Manager"));
     employee2->salary = 127000;
     employee2->emp_id = 10001;

     employee_t *employee3 = calloc(1, sizeof(employee_t));
     strncpy(employee3->name, "Rosa", strlen("Rosa"));
     strncpy(employee3->designation, "CEO", strlen("CEO"));
     employee3->salary = 139000;
     employee3->emp_id = 10002;

     /*Create a new Linked List*/

     dll_t *employee_db = get_new_dll();
     register_search_function(employee_db,search_employee_dll_by_emid);
     add_data_to_dll(employee_db, employee1);
     add_data_to_dll(employee_db, employee2);
     add_data_to_dll(employee_db, employee3);
     unsigned int searched_employee_empid=10002;
     employee_t *employee=(employee_t *)(dll_search(employee_db,(void *)&(searched_employee_empid)));
     //employee_t *employee = search_employee_by_emp_id(employee_db, 10002);
     if(!employee){
         printf("Employee record not found\n");
     }
     else{
         print_employee_details(employee);
     }
     return 0;
 }
