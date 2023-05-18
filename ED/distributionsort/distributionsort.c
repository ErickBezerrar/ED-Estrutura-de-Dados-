#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int maior(int *A, int n) {
    int m = A[0];
    int i;
    for (i = 1; i < n; i++) {
        if (A[i] > m) {
            m = A[i];
        }
    }
    return m;
}

int menor(int *A, int n) {
    int m = A[0];
    int i;
    for (i = 1; i < n; i++) {
        if (A[i] < m) {
            m = A[i];
        }
    }
    return m;
}


void distribution_sort(int *v,int n)
{
	int i,a=0;
	int max,min;
    max=maior(v,n);
    min=menor(v,n);
	int w[max];
	for(i=0;i<max;i++){
		w[i]=0;
	}
	for(i=0;i<n;i++){
		w[v[i]-min]++;
	}
	for(i=0;i<max;i++){
		while(w[i]>0){
			v[a]=i+min;
			a++;
			w[i]=w[i]-1;
		}
	}

}

int main()
{
	int i,j;
	float tempo;
	struct timeval a,b;
	FILE *fp;
	int n=100;
    fp = fopen ("distribution_sort.txt", "w");
	while(n<=10000){
	    int A[n];
		tempo=0;
		for(j=0;j<100;j++){
        gettimeofday(&b,NULL);
         for(i=0;i<n;i++){
		    A[i]=rand()%((100-0+1)+1);
		}
		distribution_sort(A,n);
        gettimeofday(&a,NULL);
	    tempo=(a.tv_sec+a.tv_usec*1e-6)-(b.tv_sec+b.tv_usec*1e-6);
		}
		fprintf(fp,"%d %f\n",n,tempo*1e6);
		n=n+100;
	}	
	return 0;

}