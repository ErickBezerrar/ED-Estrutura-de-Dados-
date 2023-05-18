#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>

void bubble_sort(int *v,int n){
    int i,j,k;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(v[j]<v[i]){
                k=v[j];
                v[j]=v[i];
                v[i]=k;   
            }
        }
    }
}    

int main(){
    int n=100;
	int i,j;
	float tempo;
	struct timeval a,b;
	float v;
	FILE *fp;
    fp = fopen ("bubble_sort.txt", "w");
	while(n<=1000){
		int A[n];
                       
         for(i=0;i<n;i++){
		    A[i]=rand();
		}
               
        gettimeofday(&b,NULL);
        bubble_sort(A,n);
        gettimeofday(&a,NULL);
	    tempo=(a.tv_sec+a.tv_usec*1e-6)-(b.tv_sec+b.tv_usec*1e-6);
		fprintf(fp,"%d %f\n",n,tempo*1e6);
		n=n+100;			
	}	
	return 0;

}
