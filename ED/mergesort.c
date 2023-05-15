#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void merge(int *v,int i,int m,int f){

    int a=i;
    int b=m+1;
    int k;
    int *w = (int *)malloc( (f-i+1)*sizeof(int) );

    for( k=0; k <= (f-i) ; k++){
             if(b>f || (a<=m && v[a] < v[b] ) ){
                    w[k] = v[a];
                    a++;     
             }
             else{
                  w[k] = v[b];
                  b++;
             }
     }
     for( k=0; k <= (f-i) ; k++){
             v[i+k] = w[k];
     }
     free(w);
}
void merge_sort(int *A,int i,int f){

     int  m;
     if (i<f){
            m=(i+f)/2;
            merge_sort(A,i,m);
            merge_sort(A,m+1,f);
            merge(A,i,m,f);    
    }
}     

int main(){

	int i,j;
	float tempo;
	struct timeval a,b;
	float v;
	FILE *fp;
	int n=100;
    fp = fopen ("merge_sort.txt", "w");
	int t;
	while(n<=10000){
	    int A[n];
		tempo=0;
		for(j=0;j<100;j++){
        gettimeofday(&b,NULL);
         for(i=0;i<n;i++){
		    A[i]=rand()%((100-0+1)+1);
		}
        merge_sort(A,0,n);
        gettimeofday(&a,NULL);
	    tempo=(a.tv_sec+a.tv_usec*1e-6)-(b.tv_sec+b.tv_usec*1e-6)+tempo;
		}
		fprintf(fp,"%d %f\n",n,(tempo*1e6)/100);
		n=n+100;
	}	
	return 0;

}