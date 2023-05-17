#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int maior (int *A,int n){
    int m=A[0];
    int i;
    for(i=0;i<n;i++){
        if(A[i]>m){
            m=A[i];
            
        }
        
    }
    return m;
}

int menor (int *A,int n){
    int m=A[0];
    int i;
    for(i=0;i<n;i++){
        if (A[i] < m){
            m=A[i];
            
        }
        
    }
    return m;
}

void distribution_sort(int *v, int n) {
    int i, a = 0;
    int max = maior(v, n);
    int min = menor(v, n);
    int *w = (int *)malloc((max - min + 1) * sizeof(int));  // Alocação dinâmica
    for (i = 0; i <= max - min; i++) {
        w[i] = 0;
    }
    for (i = 0; i < n; i++) {
        w[v[i] - min]++;
    }
    for (i = 0; i <= max - min; i++) {
        while (w[i] > 0) {
            v[a] = i + min;
            a++;
            w[i] = w[i] - 1;
        }
    }
    free(w);  // Liberar a memória alocada
}

int main(){
	int i,j;
	float tempo;
	struct timeval a,b;
	//float v;
	FILE *fp;
	int n=0;
    fp = fopen ("distribution_sort.txt", "w");
	while(n<=1000){
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