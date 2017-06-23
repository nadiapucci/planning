/* **********************************************
*
* @File : common.h
* @Author : Pucci, Nadia Amira
* @Date : 06/04/2017
* @brief : Common Functions
*
*********************************************** */

#ifndef _COMMON_H
#define _COMMON_H

double dot(const double *a, const double *b, int length);

extern void ecef2pos(const double *r, double *pos);

extern void pos2ecef(const double *pos, double *r);

#endif
