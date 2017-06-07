/* **********************************************
*
* @File : comm_func.h
* @Author : Pucci, Nadia Amira
* @Date : 06/04/2017
* @brief : Common Functions
*
*********************************************** */

#ifndef _COMM_FUNC_H
#define _COMM_FUNC_H

double dot(double *a, double *b, int length);

extern void ecef2pos(const double *r, double *pos);

extern void pos2ecef(const double *pos, double *r);

#endif
