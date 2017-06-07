/* **********************************************
*
* @File : scenarios.c
* @Author : Pucci, Nadia Amira
* @Date : 06/04/2017
* @brief : This function realizes the Fixed Scenarios Initialization
*
*********************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "scenarios.h"
//#include "config.h"
//#include "data.h"

/**
 * @brief Fixed Polygone Initialization for Scenarios
 *As requirement of this planner software the limits are 10 fixed scenarios
 *with until 50 points (longitude and latitude) as maximum
 */
void initScenFixed(int ids, int nsc, vert_p *vp, float latScen[], float longScen[]){
//    printf("\nEntro a init_scenf\n");
    //investigar un poco más y completar!
    int f,c,j;

    //Inicializa todos los escenarios
    //En el caso que los escenarios esten inactivos se igualan a 0
    vp->nvp[ids]=nsc;
    printf ("size %i\n", vp->nvp[ids]);

     //for(f=0; f<maxn_scf; ++f){
     for(f=ids; f<ids+1; f++){
            printf ("fila %i\n", f);
        for(c=0; c<MAX_VERT_FIXED; c++){
            printf ("vp->nvp: %i c: %i\n",vp->nvp[ids],c);
            if(vp->nvp[ids]>c){
                vp->vertx[f][c]=latScen[c];
                vp->verty[f][c]=longScen[c];}
            else{
                vp->vertx[f][c]=0.0;
                vp->verty[f][c]=0.0;}
                printf ("lat: %f\n", vp->vertx[f][c]);
                printf ("long: %f\n", vp->verty[f][c]);
        }
    }
}

/**
*@brief Determines if a point, in this case the satellite is inside the polygon. There will be as many calls as polygons to check.
*
*@param float X and float Y are the Lon/Lat of the satellite position
*@param int nvert the number of polygon's vertices
*@param float vertx[] and float verty[] which are the Lon/Lat defining the polygon
*@returns The output c will be 1 or 0 if it is inside or outside the zone/polygon of interest (ROI)
*/

int pnPoly(int scen, vert_p *vp,float X,float Y)
{
  int i, j, c = 0;
  int nvert;
  nvert=vp->nvp[scen];
  for (i = 0, j = nvert-1; i < nvert; j = i++)
  {
    if(((vp->verty[scen][i]>Y)!=(vp->verty[scen][j]>Y))&&(X<(vp->vertx[scen][j]-vp->vertx[scen][i])*(Y-vp->verty[scen][i])/(vp->verty[scen][j]-vp->verty[scen][i])+vp->vertx[scen][i]))
       c = !c;
  }
  return c;
}

/* check if endpoints straddle (are on opposite sides) of X axis
* (i.e., the Y's differ); if so, +X ray could intersect this edge.
*/
/* check if endpoints are on same side of the Y axis (i.e., X's
* are the same); if so, it's easy to test if edge hits or misses.
*/
/* if edge's X values both right of the point, must hit */
/* compute intersection of pgon segment with +X ray, note
* if >= point's X; if so, the ray hits it.
*/



/**
*@brief New scenarios
*For new scenarios, the limits are 10 new scenarios and until 20 points (longitude and latitude) as maximum
*@param int nvert the number of polygon's vertices.
*@param float vertx[] and float verty[] which are the Lon/Lat defining the polygon
*@returns
*/

void newScen(int ids, int nsc, vert_pnew *vpnew, float latScen[], float longScen[]){
//    printf("\nEntro a init_scenf\n");
    //investigar un poco más y completar!
    int f,c,j;

    //Inicializa todos los escenarios
    //En el caso que los escenarios esten inactivos se igualan a 0
    vpnew->nvp_new[ids]=nsc;
    printf ("size %i\n", vpnew->nvp_new[ids]);

     //for(f=0; f<maxn_scf; ++f){
     for(f=ids; f<ids+1; f++){
            printf ("fila %i\n", f);
        for(c=0; c<MAX_VERT_FIXED; c++){
            printf ("vpnew->nvp: %i c: %i\n",vpnew->nvp_new[ids],c);
            if(vpnew->nvp_new[ids]>c){
                vpnew->vertx_new[f][c]=latScen[c];
                vpnew->verty_new[f][c]=longScen[c];}
            else{
                vpnew->vertx_new[f][c]=0.0;
                vpnew->verty_new[f][c]=0.0;}
                printf ("lat: %f\n", vpnew->vertx_new[f][c]);
                printf ("long: %f\n", vpnew->verty_new[f][c]);}
        }
}

/**
*@brief Control New Scenarios
*@param int nNewScen: number of new scenarios
*@param int busy: scenario availability. 0: Empty, 1:Busy
*@param int enable
*@returns
*/
//void addNewScen(data_scen *d_scen){
//    printf("entra a control_nscen\n");
//    //int news: number of new scenario
//    //int busy: scenario availability. 0: Empty, 1:Busy
//    //int enable: Enable or disable the scenario. 0:Disable, 1:Enable
//    int news[MAX_SC_NEW]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//    int busy[MAX_SC_NEW]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//    int enable[MAX_SC_NEW]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//    int n_scen, temp, i;
//
//    n_scen=d_scen->nNewScen;
//    temp=1;
//    printf("temp: %i\n",temp);
//    printf("n_scen: %i\n",d_scen->nNewScen);
//
//    while(temp!=0){
//        for(i=0;i<MAX_SC_NEW;i++){
//            if(news[i]==0){
//                if(busy[i]==0 && enable[i]==0) //state 000
//                    printf("Estado 000. Generar nuevo escenario\n");
//                else if(busy[i]==0 && enable[i]==1)
//                    printf("Estado 001. Estado no posible\n");
//                else if(busy[i]==1 && enable[i]==0)
//                    printf("Estado 010. Escenario creado, ocupado pero no habilitado\n");
//                else if(busy[i]==1 && enable[i]==1)
//                    printf("Estado 011. Escenario creado, ocupado y habilitado\n");}
//            else if(news[i]==1){
//                if(busy[i]==0 && enable[i]==0) //state 000
//                    printf("Estado 100. Generar nuevo escenario. Posición vacía y deshabilitada\n");
//                else if(busy[i]==0 && enable[i]==1)
//                    printf("Estado 101. Estado no posible\n");
//                else if(busy[i]==1 && enable[i]==0)
//                    printf("Estado 110. Sobreescribir escenario deshabilitado, para ingresar uno nuevo\n");
//                else if(busy[i]==1 && enable[i]==1)
//                    printf("Estado 111. Estado no posible\n");}
//        }
//        temp--;
//        printf("temp: %i\n");
//    }
//
//}

void addNewScen(data_scen *d_scen){
    printf("entra a control_nscen\n");
    //int news: number of new scenario
    //int busy: scenario availability. 0: Empty, 1:Busy
    //int enable: Enable or disable the scenario. 0:Disable, 1:Enable
    int news[MAX_SC_NEW]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int busy[MAX_SC_NEW]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int enable[MAX_SC_NEW]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int n_scen, temp, i;

    n_scen=d_scen->nNewScen;
    temp=1;
    printf("temp: %i\n",temp);
    printf("n_scen: %i\n",d_scen->nNewScen);

    while(temp!=0){
        for(i=0;i<MAX_SC_NEW;i++){
            if(news[i]==0){
                if(busy[i]==0 && enable[i]==0) //state 000
                    printf("Estado 000. Generar nuevo escenario\n");
                else if(busy[i]==1 && enable[i]==0)
                    printf("Estado 010. Escenario creado, ocupado pero no habilitado\n");
                else if(busy[i]==1 && enable[i]==1)
                    printf("Estado 011. Escenario creado, ocupado y habilitado\n");}
            else if(news[i]==1){
                if(busy[i]==0 && enable[i]==0) //state 000
                    printf("Estado 100. Generar nuevo escenario. Posición vacía y deshabilitada\n");
                else if(busy[i]==0 && enable[i]==1)
                    printf("Estado 101. Estado no posible\n");
                else if(busy[i]==1 && enable[i]==0)
                    printf("Estado 110. Sobreescribir escenario deshabilitado, para ingresar uno nuevo\n");
                else if(busy[i]==1 && enable[i]==1)
                    printf("Estado 111. Estado no posible\n");}
        }
        temp--;
        printf("temp: %i\n");
    }

}

//int main(){
int scenarios(){
    vert_p vp1;
    float xs=-106.0;
    float ys=35.0;
    int c,d;

    initScenFixed(0,NSC0,&vp1,latSc0,longSc0);
    initScenFixed(1,NSC1,&vp1,latSc1,longSc1);
    initScenFixed(2,NSC2,&vp1,latSc2,longSc2);

    c=pnPoly(0,&vp1,xs,ys);
    printf ("c=%i\n",c);

    d=pnPoly(1,&vp1,xs,ys);
    printf ("d=%i\n",d);

    data_scen dscen1;
    addNewScen(&dscen1);

    return 0;
}

