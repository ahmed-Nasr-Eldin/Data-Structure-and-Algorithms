#include "BinarySearch.h"

int main()
{
	char * str ;
	unsigned char Found=0;
	unsigned char Division ;
	 long Index=0;
	 Emp_ptr Ptr = (Emp_ptr) (&Emp_Data[0]) ;

/************* Parsing the Data First *************/
Parse_The_Data("Employee_data.txt") ;
/************ Find the Employee with the ID 130 ****/
Found=Binary_search((Employee **)Emp_Data,12,&Index,130);
/************** Diplay all Elements*****/
display();
/****************** get the user division based on index*************/
Division=(Index)/(DIVISON_NUMBER-1) ;
switch(Division)
{
case 0 :
str="Finance" ;
break;
case 1:
	str="Accounting" ;
	break;
case 2 :
	str="HR" ;
break;
case 3:
	str="Engineering" ;
break;
default:
	str="Not Found" ;
}
if(Found)
{
	printf("name = %s Division = %s  salary =  %d  ID = %d" ,
		(Ptr+Index)->name,str,(Ptr+Index)->salary,(Ptr+Index)->Id);
}
return 0 ;
}
