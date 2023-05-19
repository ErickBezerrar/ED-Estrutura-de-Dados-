#include <stdio.h>
#include <sys/time.h>

int partition(int *v,int i,int f){
    int p=i;
	int b=i+1;
	int k,a;
	for(k=i+1;k<=f;k++){
		if(v[p]>v[k]){
			a=v[k];
			v[k]=v[b];
			v[b]=a;
			b++;
		}
	}
	a=v[b-1];
	v[b-1]=v[p];
	v[p]=a;
	return b-1;
}

void quick_sort(int *A,int i,int f){
	int p,m,aux;
    if (i<f){
		
			m=(i+f)/2;
			aux=A[i];
			A[i]=A[m];
			A[m]=aux;

            p=partition(A,i,f);
			quick_sort(A,i,p-1);
			quick_sort(A,p+1,f);
    }
}     

int main()
{
  	int i;
	float tempo;
	struct timeval a,b;
	FILE *fp;
	int n=100;
    fp = fopen ("quick_sort_melhor_caso.txt", "w");
	while(n<=1000){
	    int A[n];

         for(i=0;i<n;i++){
		    A[i]=i;
		}

        gettimeofday(&b,NULL);
        quick_sort(A,0,n-1);
        gettimeofday(&a,NULL);
	    tempo=(a.tv_sec+a.tv_usec*1e-6)-(b.tv_sec+b.tv_usec*1e-6);
		fprintf(fp,"%d %f\n",n,tempo*1e6);
		n=n+100;
	}	
	return 0;

}