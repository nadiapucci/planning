/* **********************************************
*
* @File : data.h
* @Author : Pucci, Nadia Amira
* @Date : 06/04/2017
* @brief : Pre-setting data
*
*********************************************** */
#define N_XYZ 3
#define N_GPS 2         /**< total gps available*/
#define MAX_GPS 2       /**< max gps supported*/
#define N_MAGN 2        /**< total magn available*/
#define MAX_MAGN 2      /**< max magn supported*/
#define N_INTRUMENTS 1     /**< total instruments available*/
#define MAX_INTRUMENTS 5   /**< max instruments supported*/
#define N_EARTH_S 2        /**< total earth sensor available*/
#define MAX_EARTH_S 2      /**< max earth sensor supported*/
#define N_SOLAR_S 12       /**< total solar sensor available*/
#define MAX_SOLAR_S 12     /**< max solar sensor supported*/
#define MAX_SC_FIXED 10    /**< max fixed scenarios*/
#define MAX_SC_NEW 10   /**< max new scenarios*/
#define MAX_VERT_FIXED 50  /**< max numbers of fixed scenarios vertices*/
#define MAX_VERT_NEW 20    /**< max numbers of new scenarios vertices*/
#define NSC0 5     /**< numbers of new scenario 1 vertices*/
#define NSC1 5     /**< numbers of new scenario 2 vertices*/
#define NSC2 8     /**< numbers of new scenario 3 vertices*/

/**<latitudes of new scenario 1*/
static float latSc0[NSC0] = {-115.0, -115.0, -107.0, -102.0, -102.0};
/**<longitudes of new scenario 1*/
static float longSc0[NSC0] = {37.0, 32.0, 33.0, 31.0, 35.0};

/**<latitudes of new scenario 2*/
static float latSc1[NSC1] = {-120.0, -120.0, -102.0, -102.0, -95.0};
/**<longitudes of new scenario 2*/
static float longSc1[NSC1] = {33.0, 28.0, 28.0, 25.0, 25.0};

/**<latitudes of new scenario 3*/
static float latSc2[NSC2] = {-120.0, -120.0, -102.0, -102.0, -95.0, -80.0, -83.0, -82.0};
/**<longitudes of new scenario 3*/
static float longSc2[NSC2] = {33.0, 28.0, 28.0, 25.0, 25.0, 24.0, 23.0, 23.0};

