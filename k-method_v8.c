#include<stdio.h>
#include<math.h>
#include <stdlib.h>

/* holds the address of the array of which the sorted index
 * order needs to be found
 */
double *base_arr;
int n = 5;

//double base_arr[50];

/* Note how the compare function compares the values of the
 * array to be sorted. The passed value to this function
 * by `qsort' are actually the `idx' array elements.
 */
static int compar (const void *a, const void *b)
{
  int aa = *((int *) a), bb = *((int *) b);
  if (base_arr[aa] < base_arr[bb])
    return -1;
  if (base_arr[aa] == base_arr[bb])
    return 0;
  if (base_arr[aa] > base_arr[bb])
    return 1;
}

double k_method(int val, double a[], double a_idx[], double rmin, double rmax){
    // Armado de la recta Z(x) -------------------------------------------------
    // Z(x)= m*x+q -------------------------------------------------------------
    int i,j;
    double min = a[0];
    double max = a[0];
    double ymax=0;
    double ymin=0;
    double max_abs;
    double epsi;
    double vec_x[val];
    double vec_z[val];
    int vec_k[val];
    double m, q;
    int j_b, j_t;
    int k_start, k_end;
    int vectoreval[val];
    double vectorsalida[val];

    double x=0.0;
    printf("Entro a kmethod\n");

    for (i=0;i<val;i++)
   {
       printf("%f\n", a[i]);
       vec_x[i]=x;

       if (a[i] > max)
       {
           max = a[i];
       }
       else if (a[i] < min)
       {
           min = a[i];
       }
       x=x+1.0;
   }
   //vec_x[i+1]=i+1;

    ymax = max;
    ymin = min;

    printf("\n");

    printf("ymax:%f, ymin:%f\n", max, min);

    //hasta aca test

    if (fabs(ymax)>fabs(ymin))
        max_abs=fabs(ymax);
    else
        max_abs=fabs(ymin);

    printf("max_abs %f\n", max_abs);

    epsi = (2.22e-16)*max_abs;

    m = (ymax-ymin+2*epsi)/(val-1);
    q = ymin-epsi-m;

    for (i=1;i<=val;i++)
       vec_x[i]=i;

    for (i=2;i<val;i++)
        vec_z[i]=m*vec_x[i]+q;

    vec_k[1]=0;
    vec_k[val]=val;

    for (i=2;i<val;i++){
            printf("entra al for 1\n");
        for (j=1;j<val;j++){
            printf("entra al for 2\n");
            if (vec_z[i] >= a_idx[j] && vec_z[i] < a_idx[j+1]){
                printf("entra al if\n");
                vec_k[i]=j;
                printf("vec_k[%d]= %d\n",i, vec_k[i]);}
            //else vec_k[i]=0;
    }}

    for (i=1;i<=val;i++)
       printf("vec_k[%d]=%d\n",i,vec_k[i]);

    // Busqueda K-vector -------------------------------------------------------

    j_b = floor((rmin-q)/m);
    j_t = ceil((rmax-q)/m);
    printf("j_b %d\n", j_b);
    printf("j_t %d\n", j_t);

    k_start = vec_k[j_b]+1;
    k_end = vec_k[j_t];

    printf("ultimo\n");
    double k;
    int ks;
    ks=floor(abs(k_end-k_start));
    printf("ks: %f\n", ks);
    printf("k_start %d\n", k_start);
    printf("k_end %d\n", k_end);

    for (i = 0; i < val; i++)
    {
      printf ("%f ", a_idx[i]);
    }

    int ind=1;
    printf("entra?\n");
    for (i=k_start;i<=k_end;i++){
        printf("entro al for ult\n");
        vectoreval[ind]=i;
        printf("vectoreval[%d]= %d\n",ind, vectoreval[ind]);
        ind++;
        }

    for (i=0;i<val;i++)
       printf("a_idx[%d]=%f\n",i,a_idx[i]);

    j=1;
    for (i=k_start;i<=k_end;i++)
    {
        printf ("j=%d \n",j);
        printf ("i=%d \n",i);
        printf ("vectoreval[i]-1=%d \n",vectoreval[i-1]);
        vectorsalida[j]=a_idx[vectoreval[i-1]-1];
        printf ("vectorsalida[j]=%f \n", vectorsalida[j]);
        j++;
    }

    while(vectorsalida[1] < rmin)
     	vectorsalida[1] = 0;
    while(vectorsalida[j-1] > rmax)
    	vectorsalida[j-1] = 0;

    for (i=1;i<(j);i++)
       printf("vectorsalida[%d]=%f\n",i,vectorsalida[i]);
}

int main(){
    double arr[n], a0[n], a_idx[n];
    int r;
    double rd;
    int idx[n];
    int i;
    double rmin,rmax;
//    printf("Enter no of elements:");
//    scanf("%d",&n);
//    printf("Enter array elements:");
//
//    for(i=0;i<n;i++){
//        scanf("%lf",&arr[i]);
//        a0[i]=arr[i];
//    }

    time_t t;

    /* Intializes random number generator */
   srand((unsigned) time(&t));
   r=rand()%50;
   rd=r/100;
   printf("r: %f\n",r);
   printf("rd: %f\n",rd);


    rmin=2.0;
    rmax=3.0;
    printf("rmin: %f\n",rmin);
    printf("rmax: %f\n",rmax);



    // initialize initial index permutation of unmodified `arr'

    for (i = 0; i < n; i++)
      idx[i] = i;

  /* Assign the address of out original array to the static global
   * pointer, this will be used by the compare function to index
   * into the original array using `idx' values
   */
  base_arr = arr;

  qsort (&idx, n, sizeof (int), compar);

  printf ("\nOriginal list: ");
  for (i = 0; i < n; i++)
    {
      printf ("%f ", arr[i]);
    }

  printf ("\nSorted index: ");
  for (i = 0; i < n; i++)
    {
      printf ("%d ", idx[i]);
    }

  printf ("\nSorted array using arr[sorted_idx[i]]: ");
  for (i = 0; i < n; i++)
    {
      printf ("%f ", arr[idx[i]]);
      a_idx[i]=arr[idx[i]];
    }
    printf("\n");

    //test passed

    k_method(n,arr,a_idx,rmin,rmax);

    return(0);
}
