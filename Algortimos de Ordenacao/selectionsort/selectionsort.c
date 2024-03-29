#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void swap(int *a, int *b)
{
    int m;
    m = *a;
    *a = *b;
    *b = m;
}

void selection_sort(int *v, unsigned int n)
{
    unsigned int i, j;
    int m;

    for (i = 0; i < (n - 1); i++)
    {
        m = i;
        for (j = (i + 1); j < n; j++)
        {
            if (v[m] > v[j])
                m = j;
        }
        swap(&v[m], &v[i]);
    }
}

int main()
{
    int n = 100;
    int i, j;
    float tempo = 0;
    struct timeval a, b;
    FILE *fp;
    fp = fopen("selection_sort.txt", "w");
    
    while (n <= 1000) {
        int A[n];
        for (j = 0; j < n; j++) {
            gettimeofday(&b, NULL);
            for (i = 0; i < n; i++) {
                A[i] = rand() % ((100 - 0 + 1) + 1);
            }
            selection_sort(A, n);
            gettimeofday(&a, NULL);
            tempo += (a.tv_sec + a.tv_usec * 1e-6) - (b.tv_sec + b.tv_usec * 1e-6);
        }
        fprintf(fp, "%d %f\n", n, (tempo * 1e6) / n);
        tempo = 0;           
        n = n + 100;
    }    
    return 0;
}

