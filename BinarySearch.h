/*********************************************************************************
 *
 * @file BinarySearh.c
 * @Author Ahmed Nasr Eldin
 *
 *
 */


/*********************************************************************************
 * 								Included  files
 *
 *******************************************************************************/
#include <stdio.h>
#include <strings.h>
/***********************************************************
 *
 * I am going to use a binary search
 * for searching for two dimensional array of structure Employees
 *
 *
 */

typedef enum {
	Finance,
	Accounting,
	HR,
	Engineering
}divisions;
typedef struct{

	char   name [20] ;
	int Id ;
	int salary ;

}Employee,*Emp_ptr;
#define EMPLOYEE_NUMBER 3
#define DIVISON_NUMBER 4
unsigned char Parse_The_Data(const char * str) ;
void display();
unsigned char Binary_search(Employee ** Emp_data,unsigned long size,long * Index,long ID);
extern Employee Emp_Data[DIVISON_NUMBER][EMPLOYEE_NUMBER] ;
