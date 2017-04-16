/*********************************************************************************
 *
 * @file BinarySearh.c
 * @Author Ahmed Nasr Eldin
 *
 *
 */




#include "BinarySearch.h"


/************ Two Dimensional array of Employees *************/
Employee Emp_Data[DIVISON_NUMBER][EMPLOYEE_NUMBER] ;
/**************************************************
 */

/******************************************************
 @Constraints :
 data Entered From the file must be in the following format
 FirstName LastName
 ID
 Salary.
 * you must to enter the full path of the file.
 * if it's not in the same project directory.
 *****************************************************************/
unsigned char Parse_The_Data(const char * str)
{
FILE * fp ;
int i=0;
int  j=0;
char first [10] ;
char last [10] ;
fp = (FILE*)fopen(str,"r") ;
for(j=0;j<DIVISON_NUMBER;j++)
{
for(i=0;i<EMPLOYEE_NUMBER;i++)
{
fscanf(fp,"%s %s %d %d",first,last,&Emp_Data[j][i].Id,&Emp_Data[j][i].salary) ;
strcpy(Emp_Data[j][i].name,first);
strcat(Emp_Data[j][i].name," ");
strcat(Emp_Data[j][i].name,last);
}
}
}
/*************************************************************************************
 *
 * Function used to display all the parsed data fromm the File
 *
 *
 ************************************************************************************/
void display()
{
int i=0,j=0;
for(j=0;j<DIVISON_NUMBER;j++)
{
for(i=0;i<EMPLOYEE_NUMBER;i++)
{

printf("name= %s ID =%d salary= %d \n",Emp_Data[j][i].name,Emp_Data[j][i].Id,Emp_Data[j][i].salary);
}
}


}

/*********************************************************************************************
 *  @brief  Binary search Function For Two Dimensional Array with time complexity OLog(N)
 *          where N=Dimension1*Dimension2 ,
 * 	@param EMP_data [IN] two dimensional array of Structure Employee3
 * 	@param size [in] size of two dimensional array [Width*length]
 * 	@param Index [out] get the Index of the Found data or -1 if data not found
 *  @param ID [In] the ID of the Employee you want his data
 *
 *********************************************************************************************/
unsigned char Binary_search(Employee ** Emp_data,unsigned long size,long * Index,long ID)
{

unsigned char Found = 0 ;
unsigned long midPoint=0;
 long first=0;
 long last =size-1 ;
Emp_ptr Ptr_Employee = (Emp_ptr) (&Emp_data[0]);  /***** Access the Two dimensional array as single array***/
unsigned char moreTosearch = first<=last ; /*Variable used for readability */

while((!Found)&& moreTosearch)
{
midPoint=(last+first)/2;
if((Ptr_Employee+midPoint)->Id==ID)
{
	Found=1;

}
else if(ID>(Ptr_Employee+midPoint)->Id)
{
	first=midPoint+1;

}
else
{
	last=midPoint-1;

}
//midPoint=(first+last)/2;
moreTosearch = first<=last ;
}
if(Found)
	*Index=midPoint;
else
	*Index=-1 ;
return Found;
}
