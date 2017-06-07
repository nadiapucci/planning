/* **********************************************
*
* @File : main.c
* @Author : Pucci, Nadia Amira
* @Date : 28/03/2017
* @brief : Main code for run different test cases
*
*********************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <pthread.h>
#include <math.h>

/** Configurations
 * This function initialize the structure and set values.
 */
 #include "config.c"

/**
 * Test cases
 */
#include "testcase_1.h"
#include "testcase_2.h"

void *thTestSelection(void *msj) {

	int tcase; /**< integer value */
	char tcasec[1];
	char filename[15] = "testcase.txt";
    char title[15]="Test case: ";

    printf("%s \n", msj);

	printf("Insert the test case number: "); /**< Enter the test case number*/
	scanf("%d",&tcase); //Leyendo el número solicitado
//	printf("The test case selected is %d\n", tcase); //Mostrando el número ingresado por teclado
	itoa (tcase,tcasec,10);
//	printf("tcasec %s\n", tcasec);

	//guardar el numero de test case para poder accederlo desde el main
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

    strcat(title,tcasec);
//    printf("Title file is %s\n", title);
 	fputs( title, file );
 	fputs( "\n", file );
 	fclose ( file );

	// Sale del hilo
	pthread_exit(NULL);
}


/**
 @brief This main func
 @ return nothing
 */
int main(void) {
    const char *message1 = "Thread Test Case Selection"; //imprime mensaje para saber que esta haciendo
    const char *message2 = "Thread Test Case Running";
    pthread_t thTestCase;
    //dclaración de threads para test cases
    pthread_t thtcase;
    int stat, i=0, tc;
    FILE *file;
    char filename[15] = "testcase.txt";
    char buffer[15];

    printf("File :%s\n", __FILE__ );
    printf("Date :%s\n", __DATE__ );
    printf("Time :%s\n", __TIME__ );
//    printf("Line :%d\n", __LINE__ );
//    printf("ANSI :%d\n", __STDC__ );

    // Thread que selecciona el Test Case a ejecutar
    stat = pthread_create(&thTestCase, NULL, thTestSelection, (void*) message1);
    if ( 0 != stat ) { raise(SIGINT); }

    // Esperamos a que finalice el thread de seleccion
	stat = pthread_join(thTestCase, NULL);
	if ( 0 != stat ) { raise(SIGINT); }

	//Para iniciar el hilo del test seleccionado
	file = fopen( filename, "r" );
    if(file)
        printf( "Creado (ABIERTO)\n" );
    else
    {
        printf( "Error (NO ABIERTO)\n" );
    }

    fgets(buffer, sizeof(buffer) ,file);
    while(buffer[i]!='\n'){
        i++;
    }
    tc=atoi(&buffer[i-1]);

    //deberia ejecutar la configuracion segun corresponda al test

//	//Generar un puntero al test case correspondiente y lanzarlo
//    switch(tc){
//        case 1:
//            // Thread que selecciona el Test Case a ejecutar
//            stat = pthread_create(&thtcase, NULL, testcase_1(), (void*) message2);
//            if ( 0 != stat ) { raise(SIGINT); }
//            break;
//        case 2:
//            stat = pthread_create(&thtcase, NULL, testcase_2(), (void*) message2);
//            if ( 0 != stat ) { raise(SIGINT); }
//            break;
//    }

// Esperamos a que finalice el thread de seleccion
//	stat = pthread_join(thtcase, NULL);
//	if ( 0 != stat ) { raise(SIGINT); }

//    init_scenf(); /*inicializar scenarios fijos */

    config();

    return 0;
}

