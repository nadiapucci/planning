/* **********************************************
*
* @File : testcase_1.h
* @Author : Pucci, Nadia Amira
* @Date : 28/03/2017
* @brief : Test case 1. Funtions:
*
*********************************************** */


void suma(x,y)
{
    int s;
    s=x+y;
    printf("suma: %i",s);
 }

 void *testcase_1(){
     int a,b;
    a=2;
    b=5;
    suma(a,b);
     }
