#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>

void ordenacao_insercao(int *A,int n)
{
     int k;
     int i;
     int aux;
     for(i=1;i<n;i++){
        k=i-1;
        while((k>=0)&&(A[k]>A[k+1])){
            aux=A[k+1];
            A[k+1]=A[k];
            A[k]=aux;
            k=k-1;
        }
     }
     
}    

int main()
{
    int n=1000;
	int i;
	float tempo;
	struct timeval a,b;
	FILE *fp;
    fp = fopen ("ordenacao_insertion_sort.txt", "w");
	while(n<=10000){
		int A[n];
        for(i=0;i<n;i++){
    		A[i]=rand();
        }
        gettimeofday(&b, NULL);
        ordenacao_insercao(A,n);
        gettimeofday(&a,NULL);
        tempo=(a.tv_sec+a.tv_usec*1e-6)-(b.tv_sec+b.tv_usec*1e-6);
		fprintf(fp,"%d %f\n",n,tempo*1e6);
		n=n+100;			
	}	
	return 0;

}