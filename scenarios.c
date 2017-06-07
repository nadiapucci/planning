/* **********************************************
*
* @File : scenarios.c
* @Author : Pucci, Nadia Amira
* @Date : 06/04/2017
* @brief : This function realizes the Scenarios Initialization
*
*********************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

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
    //investigar un poco m�s y completar!
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
    //investigar un poco m�s y completar!
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
*@brief Numbers of New Scenario Available to add
*@param bool news[]
*@param bool isbusy[]
*@param bool isenable[]
*@returns
*/
int nNewScenAvailable(bool news[], bool isbusy[], bool isenable[]){
    int i;
    int contAvail=0, contDisavail=0;
    for(i=0;i<MAX_SC_NEW;i++){
        if(news[i]==0){
            if(isbusy[i]==0)
                contAvail++;
//            else if(isbusy[i]==1 && isenable[i]==0)
//                contDisavail++;
//            else if(isbusy[i]==1 && isenable[i]==1)
//                contDisavail++;
        }
        if(news[i]==1){
            if(isbusy[i]==0)
                contAvail++;
            else if(isbusy[i]==1 && isenable[i]==0)
                contAvail++;
//            else if(isbusy[i]==1 && isenable[i]==1){
//                contDisavail++;
//                }
        }
    }
    return contAvail;
}

//bool *initNewsVector(){
//    bool news[MAX_SC_NEW]={0};      /**<bool news: free scenario number. 0: Free, 1:New*/
//    return news;
//}
//bool *itinIsbusyVector(){
//    bool isbusy[MAX_SC_NEW]={0};    /**<bool isbusy: scenario availability. 0: Empty, 1:Busy*/
//    return isbusy;
//}
//bool *itinIsenableVector(){
//    bool isenable[MAX_SC_NEW]={0};  /**<bool isenable: scenario enable. 0:disable, 1:enable*/
//    return isenable;
//}

void initNewScenVectors(vec_nScen *v_nscen){
    int i;
    for(i=0;i<MAX_SC_NEW;i++){
        v_nscen->news[i]=0;
        v_nscen->isbusy[i]=0;
        v_nscen->isenable[i]=0;
    }
}


/**
*@brief Add New Scenarios
*@param data_scen *d_scen
*@returns
*/
void addNewScen(data_scen *d_scen, vec_nScen *v_nscen){
//void addNewScen(data_scen *d_scen){
    printf("entra a addNewScen\n");

    float latitudeScen[MAX_SC_NEW][MAX_VERT_NEW] = {0};
    float longitudeScen[MAX_SC_NEW][MAX_VERT_NEW] = {0};

//    bool news[MAX_SC_NEW]={0};      /**<bool news: free scenario number. 0: Free, 1:New*/
//    bool isbusy[MAX_SC_NEW]={0};    /**<bool isbusy: scenario availability. 0: Empty, 1:Busy*/
//    bool isenable[MAX_SC_NEW]={0};  /**<bool isenable: scenario enable. 0:disable, 1:enable*/

    int n_scen; /**<number of scenarios to add*/
    int i, nScenAvailable=0, contBE=0, create=0;
    int temp, n;

    char filename[10] = "tlmy.txt";
    FILE *file;

    printf("The namefile for test case selected is %s\n", filename);
//    printf("Title file is %s\n", title);

    file = fopen( filename, "w" );
    printf( "File: %s -> ", filename);
    if(file)
        printf( "Created (OPEN)\n" );
    else
    {
        printf( "Error\n" );
    }


    n_scen=d_scen->nNewScen;
    printf("n_scen: %i\n",d_scen->nNewScen);
    temp=n_scen;
    printf("temp: %i\n",temp);

    n=nNewScenAvailable(v_nscen->news,v_nscen->isbusy,v_nscen->isenable); //ctos escenarios hay disponibles?
    printf("n: %i\n",n);

    while(temp>0){
    printf("temp: %i\n",temp);
    for(i=0;i<MAX_SC_NEW;i++){
        if(v_nscen->news[i]==0){
            if(v_nscen->isbusy[i]==0){ //state 000 100 101 no se deberia pero lo tenes que cubrir lo mismo
            //000 & 001
                loadLatitudeNScen (d_scen, latitudeScen,i);
                loadLongitudeNScen (d_scen, longitudeScen,i);
                //con esta indico cuales escenarios tengo disponibles
                printf("Escenario desocupado\n");
                v_nscen->isbusy[i] = 1;
                v_nscen->isenable[i] = d_scen->newScenState[i];
                temp--;
                printf("temp: %i\n",temp);}
            else if(v_nscen->isbusy[i]==1 && v_nscen->isenable[i]==1){
                //aca indico que no tengo escenarios disponibles para guardar nuevos
                contBE++;
                //contador que te cuente cuandtos tenes en este estado
                //si es 10 no tenes espacio
                //si es menor a diez te da los espacios disponibles 10-cont
                printf("Estado 011. Escenario creado, ocupado y habilitado\n");
                //return
            }
        }

        if(v_nscen->news[i]==1){
            if(v_nscen->isbusy[i]==0 ){//state 100 & 101
                //guardar el escenario
//                loadScen(&d_scen.vertYNewScen[i][MAX_VERT_NEW], &d_scen.vertXNewScen[i][MAX_VERT_NEW], &latitudeScen[i][MAX_VERT_NEW], &longitudeScen[i][MAX_VERT_NEW]);
                loadLatitudeNScen (d_scen, latitudeScen,i);
                loadLongitudeNScen (d_scen, longitudeScen,i);
                v_nscen->isbusy[i] = 1;
                v_nscen->isenable[i] = d_scen->newScenState[i];
                printf("Estado 100. Generar nuevo escenario. Posici�n vac�a y deshabilitada\n");
                temp--;}
            else if(v_nscen->isbusy[i]==1 && v_nscen->isenable[i]==0){
                loadLatitudeNScen (d_scen, latitudeScen,i);
                loadLongitudeNScen (d_scen, longitudeScen,i);
                v_nscen->isbusy[i] = 1;
                v_nscen->isenable[i] = d_scen->newScenState[i];
                printf("Estado 110. Sobreescribir escenario deshabilitado, para ingresar uno nuevo\n");
                temp--;}
            else if(v_nscen->isbusy[i]==1 && v_nscen->isenable[i]==1){
                //devolver que no hay escenarios disponibles
                printf("Estado 111. Estado no posible\n");
                }
        }
    }
    }
//    for (i = 0; i < MAX_SC_NEW; i++){
//        fprintf (file, "%i", news[i]);
//    }
//    fprintf (file, "\n");
//    for (i = 0; i < MAX_SC_NEW; i++){
//        fprintf (file, "%i", isbusy[i]);
//    }
//    fprintf (file, "\n");
//    for (i = 0; i < MAX_SC_NEW; i++){
//        fprintf (file, "%i", isenable[i]);
//    }
}
//llamar los metodos para generar la telemetria

/**
*@brief Load Scenario (Lats and Longs)
*@param data_scen *d_scen
*@param float latitudeScen[MAX_SC_NEW][MAX_VERT_NEW]
*@param float longitudeScen[MAX_SC_NEW][MAX_VERT_NEW]
*@param int i
*@returns
*/
float *loadScen(data_scen *d_scen, float latitudeScen[MAX_SC_NEW][MAX_VERT_NEW], float longitudeScen[MAX_SC_NEW][MAX_VERT_NEW],int i){
    int j;
    for(j=0; j <= MAX_VERT_NEW; j++){
        latitudeScen[i][j] = d_scen->vertYNewScen[i][j];
        longitudeScen[i][j] = d_scen->vertXNewScen[i][j];
    }
    //return *latitudeScen, *longitudeScen;
}

/**
*@brief Load Latitude Scenario
*@param data_scen *d_scen
*@param float latitudeScen[MAX_SC_NEW][MAX_VERT_NEW]
*@param int i
*@returns
*/
float *loadLatitudeNScen(data_scen *d_scen, float latitudeScen[MAX_SC_NEW][MAX_VERT_NEW], int i){
    int j;
    for(j=0; j <= MAX_VERT_NEW; j++){
//        latitudeScen[j] = vertXNewScen[j];
        latitudeScen[i][j]=d_scen->vertXNewScen[i][j];
    }
    return *latitudeScen;
}

/**
*@brief Load Longitude Scenario
*@param data_scen *d_scen
*@param float latitudeScen[MAX_SC_NEW][MAX_VERT_NEW]
*@param int i
*@returns
*/
float *loadLongitudeNScen(data_scen *d_scen, float longitudeScen[MAX_SC_NEW][MAX_VERT_NEW], int i){
    int j;
    for(j=0; j <= MAX_VERT_NEW; j++){
        longitudeScen[i][j] = d_scen->vertYNewScen[i][j];
    }
    return *longitudeScen;
}


/**
*@brief Execute scenarios functions
*@param
*@returns
*/
//int main(){
int scenarios(){
    vert_p vp1;
    float xs=-106.0;
    float ys=35.0;
    int c,d,n;

    /**<Load Fixed Scenarios*/
    initScenFixed(0,NSC0,&vp1,latSc0,longSc0);
    initScenFixed(1,NSC1,&vp1,latSc1,longSc1);
    initScenFixed(2,NSC2,&vp1,latSc2,longSc2);

    c=pnPoly(0,&vp1,xs,ys);
    printf ("c=%i\n",c);

    d=pnPoly(1,&vp1,xs,ys);
    printf ("d=%i\n",d);

    data_scen dscen1;

    vec_nScen v_nscen;
    initNewScenVectors(&v_nscen);
    addNewScen(&dscen1,&v_nscen



    return 0;
}

