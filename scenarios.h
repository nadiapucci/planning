/* **********************************************
*
* @File : scenarios.h
* @Author : Pucci, Nadia Amira
* @Date : 06/04/2017
* @brief : This function realizes the Fixed Scenarios Initialization
*
*********************************************** */

#ifndef _SCENARIOS_H
#define _SCENARIOS_H

//#include "data.h"

//typedef struct vertp{
//    int nvp;
//    float vertx[MAX_VERT_FIXED];
//    float verty[MAX_VERT_FIXED];
//}__attribute__ ((__packed__)) vert_p;

typedef struct vertp{
    int nvp[MAX_SC_FIXED];
    float vertx[MAX_SC_FIXED][MAX_VERT_FIXED];
    float verty[MAX_SC_FIXED][MAX_VERT_FIXED];
}__attribute__ ((__packed__)) vert_p;

typedef struct vertp_new{
    int nvp_new[MAX_SC_NEW];
    float vertx_new[MAX_SC_NEW][MAX_VERT_NEW];
    float verty_new[MAX_SC_NEW][MAX_VERT_NEW];
}__attribute__ ((__packed__)) vert_pnew;

typedef struct vectorsNewScen{
    bool news[MAX_SC_NEW];      /**<bool news: free scenario number. 0: Free, 1:New*/
    bool isbusy[MAX_SC_NEW];    /**<bool isbusy: scenario availability. 0: Empty, 1:Busy*/
    bool isenable[MAX_SC_NEW];  /**<bool isenable: scenario enable. 0:disable, 1:enable*/
}__attribute__ ((__packed__)) vec_nScen;

void initScenFixed(int ids, int nsc, vert_p *vp, float latScen[], float longScen[]);

int pnPoly(int scen, vert_p *vp,float X,float Y);

void newScen(int ids, int nsc, vert_pnew *vpnew, float latScen[], float longScen[]);

void addNewScen(data_scen *d_scen, vec_nScen *v_nscen);

float *loadScen(data_scen *d_scen, float latitudeScen[MAX_SC_NEW][MAX_VERT_NEW], float longitudeScen[MAX_SC_NEW][MAX_VERT_NEW],int i);

float *loadLatitudeNScen(data_scen *d_scen, float latitudeScen[MAX_SC_NEW][MAX_VERT_NEW], int i);

float *loadLongitudeNScen(data_scen *d_scen, float longitudeScen[MAX_SC_NEW][MAX_VERT_NEW], int i);

int scenarios();

#endif
