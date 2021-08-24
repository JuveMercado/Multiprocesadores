#include<stdio.h>
#include<omp.h>
static long num_pasos = 1000;
double paso;
//#define NUM_THREADS 1

void main()
{
    int NUM_THREADS, j;
    for(NUM_THREADS=1; NUM_THREADS<1000; NUM_THREADS++){

    int i, nthreads;
    double pi, sum[NUM_THREADS];
    paso = 1.0/num_pasos;
    omp_set_num_threads(NUM_THREADS);
    const double startTime = omp_get_wtime();
    #pragma omp parallel
    {
        int i, id, nthrds; double x;
        id = omp_get_thread_num();
        nthrds = omp_get_num_threads();
        if(id==0)
            nthreads=nthrds;
            for (i=id, sum[id]=0.0; i<num_pasos; i=i+nthrds)
            {
                x=(i+0.5)*paso;
                sum[id]+=4.0/(1.0+x*x);
            }
    }

    for (i=0,pi=0.0;i<nthreads;i++){
        pi+=sum[i]*paso;
    }
    const double endTime = omp_get_wtime();
    //printf("%d. pi = (%lf)\n", NUM_THREADS, pi);
    printf("%lf\n", (endTime - startTime));
    }
}
