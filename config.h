/* **********************************************
*
* @File : config.h
* @Author : Pucci, Nadia Amira
* @Date : 06/04/2017
* @brief : The configurations to run the test cases
*
*********************************************** */

#ifndef _CONFIG_H
#define _CONFIG_H

#define IN_DATA /* Datos internos del planificador */
#ifdef IN_DATA
    #include "data.h"
#endif

#define RECEIVE_DATA /* Datos externos del planificador desde plataforma*/
#ifdef RECEIVE_DATA
    #include "tlmy.h"
#endif

/**
 * Structure declaration
 */
typedef struct data{
    /**< GPS data*/
    float range[MAX_GPS];               /**< Range from GPS*/
    float rateRange[MAX_GPS];          /**< Rate range (Doppler) from GPS*/
    float DOP[MAX_GPS];                  /**< Dilution of precision*/
    float posGPS[MAX_GPS][3];          /**< Position GPS (ecef) (m)*/
    float velGPS[MAX_GPS][3];          /**< Velocity GPS (ecef) (m/s)*/
    float timeGPS[MAX_GPS];          /**< GPS time if it is available (sec)*/
    int8_t timeCompGPS[MAX_GPS][6];  /**< GPS time: year, month, day, hour, min, sec*/
    float biasGPS[MAX_GPS];            /**< bias GPS*/

    /**< SM orbital data*/
    float posSM[3];           /**< Position x,y,z satellite for the current orbit from SM*/
    float velSM[3];           /**< Velocity x,y,z satellite for the current orbit from SM*/
    uint8_t typePropagation;              /**< Type orbit propagation*/
    float orbitParameters[6];        /**< Orbital parameters for the current orbit from SM*/
    float timeSM;           /**< Time from SM if it is available*/

    /**< Magnetic field data*/
    float Bmes[MAX_MAGN][3];     /**< Measured B magnetic field x,y,z axis from Magnetometer*/
    float Bcalc[3];            /**< Calculated B magnetic field x,y,z axis from SM, if it is available*/

    float Smes[MAX_SOLAR_S];                /**< Measured sun direction unit vector from sun sensor*/

    float qtn[4];               /**< Satellite attitude quaternion*/
    float timeQtn;           /**< Time associated for the quaternions, if it is available*/

    /**< Earth sensor data*/
    float attAngles[MAX_EARTH_S][3];           /**< ACS attitude angles yaw, roll, pitch*/
    float attAnglesRates[MAX_EARTH_S][3];      /**< Attitude angle rates (yaw, roll, pitch) */
    int timeEarthS;           /**< Time associated for the earth sensor measurement, if it is available*/

    /**< Housekeeping variables*/
    float tempIntrument[MAX_INTRUMENTS][10];      /**< 10 measured temperatures from the instruments*/
    float currentInstrument[MAX_INTRUMENTS][10];    /**< 10 measured currents from the instruments*/

}__attribute__ ((__packed__)) data_s;

typedef struct data_scenarios{
    /**< States*/
    uint8_t commState: 1;         /**< Comm Instrument state: 1st bit --> 0: no-transmitting, 1:transmitting;*/
    uint8_t InstrumentState[MAX_INTRUMENTS][2];      /**< Instrument state: 1st bit --> 0: off, 1:on; 4bits --> substates*/

    /**< New Scenarios*/
    int nNewScen;                  /**< Total scenarios number to include in the Plan */
//    uint16_t newScenState: 10;      /**< Active states of new scenarios bit 0 to 9 --> 0 inactive scenario; 1 active scenario*/
    uint16_t newScenState[MAX_SC_NEW];  /**< Active states of new scenarios --> 0 inactive scenario; 1 active scenario*/

    float vertXNewScen[MAX_SC_NEW][MAX_VERT_NEW]; /**<Latitudes of new scenarios*/
    float vertYNewScen[MAX_SC_NEW][MAX_VERT_NEW]; /**<Longitudes of new scenarios*/
}__attribute__ ((__packed__)) data_scen;


/**
 * Functions declaration
 */
void setGPS(data_s *ds);
float* getGPS(data_s *ds);
void setSMdata(data_s *ds);
float getSMdata(data_s *ds);
void setMagn(data_s *ds);
float getMagn(data_s *ds);
void setMagnSM(data_s *ds);
float getMagnSM(data_s *ds);
void setS(data_s *ds);
float getS(data_s *ds);
void setQtn(data_s *ds);
float getQtn(data_s *ds);
void setEarthS(data_s *ds);
float getEarthS(data_s *ds);

void setInstData(data_s *ds1);

void dataInit();
void config();

void setNewScen(data_scen *dscen);
float getNewScen(data_scen *dscen);

#endif
