/* **********************************************
*
* @File : testcase_1.c
* @Author : Pucci, Nadia Amira
* @Date : 12/06/2017
* @brief : This function test the addNewScen function
*
*********************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#include <CUnit/CUnit.h>

#include "scenarios.h"

void test_addNewScen(void){
    nAdd = 10;
    data_scen dscen1;
    vec_nScen v_nscen;
    initNewScenVectors(&v_nscen);

//    addNewScen(dscen1, v_nscen, nAdd);
    CU_ASSERT_TRUE(addNewScen(dscen1, v_nscen, nAdd));
}

