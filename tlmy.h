/* **********************************************
*
* @File : tlmy.h
* @Author : Pucci, Nadia Amira
* @Date : 06/04/2017
* @brief : Telemetry data from platform
*
*********************************************** */

#ifndef _TLMY_H
#define _TLMY_H

float bufData[64][64]={
                //GPS
                {2.0, 0.0},              //range 1 y 2                          //fila 0
                {3.0, 0.0},               //rateRange 1 y 2
                {4.0, 0.0},               //DOP 1 y 2

                {1.0, 2.0, 3.0},          //pos gps1
                {5.0, 6.0, 8.0},          //pos gps2
                {1.0, 2.0, 3.0},          //vel gps1
                {5.0, 6.0, 1.0},          //vel gps2

                {0.0, 0.0},                //time 1 y 2
                {5, 0, 0, 0, 0, 0},       //time ymdhms gps1
                {0, 0, 0, 8, 0, 0},       //time ymdhms gps2
                {0.0, 0.0},               //bias 1 y 2
                //SM                                                            //fila 11
                {11.0, 0.0, 0.0},          //pos
                {12.0, 0.0, 0.0},          //vel
                {5},                      //typeprop
                {6.0, 0.0, 0.0, 0.0, 0.0, 0.0},       //orbital elements
                {0.0},                    //time
                //magn
                {1.0, 0.0, 0.0},          //magn1 field x,y,z                   //fila 16
                {2.0, 0.0, 0.0},          //magn2 field x,y,z
                {3.0, 0.0, 0.0},          //magn calc SM
                //ss
                {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
                //qtn
                {5.0, 6.0, 0.0, 0.0},     //qtn
                {7.0},                    //time
                //es
                {8.0, 0.0, 0.0},          //es1 yaw, roll, pitch
                {9.0, 0.0, 0.0},          //es2 yaw, roll, pitch
                {12},                    //time
                //temp instrum
                {1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
                {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
                {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
                {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
                {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
                //current instrum
                {2.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
                {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
                {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
                {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
                {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, //33
                //flags
                {1}, //comm state
                {0, 0},
                {0, 0},
                {0, 0},
                {0, 0},
                {0, 0},
                {4},                                                      //number of new scenarios //
                {0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
                {-30.0, -30.0, -31.0, -31.0, -31.0, -31.0, -32.0, -33.0, -34.0, -34.0, -34.0, -34.0, -34.0, -34.0, -34.0, -33.0, -33.0, -32.0, -31.0, -30.0},        //vertx n0[max_vert]   //Lat +/-90
                {-57.0, -56.0, -55.0, -55.0, -55.0, -54.0, -53.0, -53.0, -54.0, -54.0, -55.0, -56.0, -57.0, -57.0, -58.0, -58.0, -58.0, -58.0, -58.0, -57.0},        //verty n0[max_vert] //Long +/-180
               // 0,
//                {-65.0, -62.0, -58.0, -56.0, -54.0, -57.0, -58.0, -61.0, -65.0, -67.0, -66.0, -68.0, -70.0, -73.0, -71.0, -71.0, -70.0, -69.0, -68.0, -67.0},        //verty n0[max_vert]
//                {-22.0, -22.0, -25.0, -27.0, -25.0, -30.0, -33.0, -38.0, -44.0, -49.0, -54.0, -54.0, -52.0, -50.0, -44.0, -39.0, -35.0, -28.0, -26.0, -22.0},        //vertx n0[max_vert]
               // 0,
                {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},        //vertx n0[max_vert]
                {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},

                {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},        //vertx n0[max_vert]
                {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},        //verty n0[max_vert]
               // 0,
                {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},        //vertx n0[max_vert]
                {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},        //verty n0[max_vert]
               // 0,
                {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},        //vertx n0[max_vert]
                {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},        //verty n0[max_vert]
               // 0,
                {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},        //vertx n0[max_vert]
                {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},        //verty n0[max_vert]
               // 0,
                {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},        //vertx n0[max_vert]
                {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},        //verty n0[max_vert]
               // 0,
                {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},        //vertx n0[max_vert]
                {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},        //verty n0[max_vert]
               // 0,
                {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},        //vertx n0[max_vert]
                {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},        //verty n0[max_vert]
               // 0,
                {4.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 6.0},        //vertx n0[max_vert]
                {6.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 8.0}        //verty n0[max_vert]
                 };

#endif
