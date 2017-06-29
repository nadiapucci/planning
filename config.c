/* **********************************************
*
* @File : config.c
* @Author : Pucci, Nadia Amira
* @Date : 06/04/2017
* @brief : The configurations to run the test cases
*
*********************************************** */
#include "config.h"
//#include "scenarios.c"

#define FIXED_SCENARIOS /* definir los escenarios del plan de misión */
#define GPS            /* La misión cuenta con GPS */

#ifdef FIXED_SCENARIOS   //MAL MUY MAL
    #include "scenarios.c"
#endif // FIXED

#ifdef GPS

#else

#endif // FIXED

data_s d_s1;

/**
*@brief Set the variables of GPS from telemetry
*
*@param data_s *ds1: data structure
*@return void
*/
void setGPS(data_s *ds1){
    int i,j,a=0;
    for(i=0;i<1;i++){
        for(j=0;j<MAX_GPS;j++){
            if(i<N_GPS){
                ds1->range[i]=bufData[i][j];
                ds1->rateRange[i]=bufData[i+1][j];
                ds1->DOP[i]=bufData[i+2][j];
                ds1->timeGPS[i]=bufData[i+7][j];
                ds1->biasGPS[i]=bufData[i+10][j];}
            else{
                ds1->range[i]=0.0;
                ds1->rateRange[i]=0.0;
                ds1->DOP[i]=0.0;
                ds1->timeGPS[i]=0.0;
                ds1->biasGPS[i]=0.0;}
        printf("\nrange: %f\n",ds1->range[i]);
        printf("\nrateRange: %f\n",ds1->rateRange[i]);
        printf("\nDOP: %f\n",ds1->DOP[i]);
        printf("\ntime: %f\n",ds1->timeGPS[i]);
        printf("\nbias: %f\n",ds1->biasGPS[i]);}
    }
    a=0;
    for(i=3;i<5;i++){
        for(j=0;j<3;j++){
            if(a<N_GPS){
                ds1->posGPS[a][j]=bufData[i][j];
                ds1->velGPS[a][j]=bufData[i+MAX_GPS][j];
            }
            else{
                ds1->posGPS[a][j]=0.0;
                ds1->velGPS[a][j]=0.0;
            }
            printf("\nposGPS: %f\n",ds1->posGPS[a][j]);
            printf("\nvelGPS: %f\n",ds1->velGPS[a][j]);
            printf("\na: %i",a);
        }
        a++;
        j=0;
    }
    //int8_t timeCompGPS[N_GPS][6];  /**< GPS time: year, month, day, hour, min, sec*/
    a=0;
    for(i=8;i<10;i++){
        for(j=0;j<6;j++){
            if(a<N_GPS){
                ds1->timeCompGPS[a][j]=bufData[i][j];
            }
            else{
                ds1->timeCompGPS[a][j]=0;
            }
            printf("\ntimeCompGPS: %i\n",ds1->timeCompGPS[a][j]);
        }
        a++;
        j=0;
    }
}

float* getRangeGPS(){
    printf("range: %f\n",d_s1.range[0]);
    return d_s1.range;
};

/**
*@brief Set the variables of orbital data service module from telemetry
*
*@param data_s *ds1: data structure
*@return void
*/
void setDataSM(data_s *ds1){
    int i,j;
    for(i=11;i<12;i++){
        for(j=0;j<3;j++){
            ds1->posSM[j]= bufData[i][j];
            ds1->velSM[j]= bufData[i+1][j];

            printf("\nposSM: %f\n",ds1->posSM[j]);
            printf("\nvelSM: %f\n",ds1->velSM[j]);
        }

    }
    ds1->typePropagation=bufData[i+1][0];
    printf("\ntype: %i\n",ds1->typePropagation);

    for(i=i+2;i<15;i++){
        for(j=0;j<6;j++){
            ds1->orbitParameters[j]=bufData[i][j];
            printf("\norbitParameters: %f\n",ds1->orbitParameters[j]);
        }}
    ds1->timeSM=bufData[i+3][0];
    printf("\ntimeSM: %f\n",ds1->timeSM);
}

/**
*@brief Set the variables of Magnetometers from telemetry
*
*@param data_s *ds1: data structure
*@return void
*/
void setMagn(data_s *ds1){
    int i,j,a=0;
    for(i=16;i<18;i++){
        for(j=0;j<3;j++){
            if(a<N_MAGN){
                ds1->Bmes[a][j]=bufData[i][j];
             }
            else{
                ds1->Bmes[a][j]=0.0;
                    }
            printf("\nBmes: %f\n",ds1->Bmes[a][j]);
        }
        a++;

    }
}

/**
*@brief Set the variables of Magnetic Field from telemetry calculated for Service Platform
*
*@param data_s *ds1: data structure
*@return void
*/
void setMagnSM(data_s *ds1){
    int j=0, i=18;
    for(j=0;j<3;j++){
        ds1->Bcalc[j]=bufData[i][j];
        printf("\nBcalc: %f\n",ds1->Bcalc[j]);
             }
}

//void setS{} //19

/**
*@brief Set the variables of Quaternions from telemetry
*
*@param data_s *ds1: data structure
*@return void
*/
void setQtn(data_s *ds1){
    int i,j;
    i=20;
    for(j=0;j<4;j++){
        ds1->qtn[j]=bufData[i][j];
        printf("\nqtn: %f\n",ds1->qtn[j]);
             }
    i++;
    j=0;
    ds1->timeQtn=bufData[i][j];
    printf("\ntimeQtn: %f\n",ds1->timeQtn);
}

/**
*@brief Set the variables of Earth Sensors from telemetry
*
*@param data_s *ds1: data structure
*@return void
*/
void setEarthS(data_s *ds1){
    int i,j,a=0;

    for(i=22;i<23;i++){
        for(j=0;j<3;j++){
            if(a<N_EARTH_S){
                ds1->attAngles[a][j]=bufData[i][j];
                ds1->attAnglesRates[a][j]=bufData[i+1][j];
            }
            else{
                ds1->attAngles[a][j]=0.0;
                ds1->attAnglesRates[a][j]=0.0;
            }
            printf("\nattAngles: %f\n",ds1->attAngles[a][j]);
            printf("\nattAnglesRates: %f\n",ds1->attAnglesRates[a][j]);
            printf("\na: %i",a);
        }
        a++;
        j=0;
    }
    i=24;
    j=0;
    ds1->timeEarthS=bufData[i][j];
    printf("\ntimeEarthS: %i\n",ds1->timeEarthS);
}

/**
*@brief Set the variables of Instrument Data from telemetry
*
*@param data_s *ds1: data structure
*@return void
*/
void setInstData(data_s *ds1){
    int i, j, a=0;

    for(i=25;i<(25+MAX_INTRUMENTS);i++){
        for(j=0;j<10;j++){
            if(a<N_INTRUMENTS){
                ds1->tempIntrument[a][j]=bufData[i][j];
                ds1->currentInstrument[a][j]=bufData[i+MAX_INTRUMENTS][j];
            }
            else{
                ds1->tempIntrument[a][j]=0.0;
                ds1->currentInstrument[a][j]=0.0;
            }
            printf("\ntempIntrument: %f\n",ds1->tempIntrument[a][j]);
            printf("\ncurrentInstrument: %f\n",ds1->currentInstrument[a][j]);
            printf("\na: %i",a);
            }
            a++;
    }
}

/**
*@brief Brief description of the function.
*
* Detailed description of the function. This part may
* refer to the parameters of the method, like
* @p param1.
*
*@param param1 param1 description.
*@param param2 param2 description.
*@return Return value description.
*/
void dataInit(){};

void setNewScen(data_scen *dscen){
    int i,j, nsn,a=0;
    i=35;
    dscen->commState=bufData[i][0];
    printf("\ncommState: %i\n",dscen->commState);

    for(i=36;i<(36+MAX_INTRUMENTS);i++){
        for(j=0;j<2;j++){
            if(a<N_INTRUMENTS)
                dscen->InstrumentState[a][j]=bufData[i][j];
            else
                dscen->InstrumentState[a][j]=8; //para no confundir con el estado
                printf("\nInstrumentState: %i\n",dscen->InstrumentState[a][j]);
        }
        a++;
    }

    dscen->nNewScen=bufData[i][0]; //41
    nsn=dscen->nNewScen;
    printf("\nnNewScen: %i\n",dscen->nNewScen);

    i++;
    for(j=0;j<MAX_SC_NEW;j++){
        dscen->newScenState[j]=bufData[i][j];
        printf("\nnewScenState: %i\n",dscen->newScenState[j]);
    }

    a=0;
    for(i++;i<53;i++){ //43
        for(j=0;j<MAX_VERT_NEW;j++){
            if(a<=nsn-1){
                dscen->vertXNewScen[a][j]=bufData[i+a][j];
                dscen->vertYNewScen[a][j]=bufData[i+a+1][j];
            }
            else{
                dscen->vertXNewScen[a][j]=0.0;
                dscen->vertYNewScen[a][j]=0.0;
            }
            printf("\nvertXNewScen: %f\n",dscen->vertXNewScen[a][j]);
            printf("\nvertYNewScen: %f\n",dscen->vertYNewScen[a][j]);
            printf("\na: %i",a);
        }
        a++;
    }
}

//void init(data_s *d_s1){
//    float *range;
//    int i;
//    setGPS(d_s1);
//    range=getRangeGPS(d_s1);
//
//    for(i=0;i<N_GPS;i++){
//        printf("\nrange[%i] get: %f\n",i,&range);
//        range++;}
//};
//
//void config(){
//    data_s d_s1;
//    init(&d_s1);
//}

/**
*@brief Basic Configurations for the satellite components
*
*@param none
*@return void
*/
void config(){
//    data_s d_s1; /* Data structure initialization */
    float *range;
    int i;
    //d_s1.range=2.34;
    //printf("\n%f \n",d_s1.range);
    //setRangeGPS(&d_s1);
    setGPS(&d_s1);
    range=getRangeGPS();

    for(i=0;i<N_GPS;i++){
        printf("\nrange[%i] get: %f\n",i,&range);
        range++;}
//
////    setDataSM(&d_s1);
////    setMagn(&d_s1);
////    setMagnSM(&d_s1);
////    setQtn(&d_s1);
////    setEarthS(&d_s1);
////    setInstData(&d_s1);
//
    data_scen d_scen1;
    setNewScen(&d_scen1);
    printf("\ncantidad: %i\n",d_scen1.nNewScen);
//
    scenarios(d_scen1);

};

//int main(){
//return(0);
//}
