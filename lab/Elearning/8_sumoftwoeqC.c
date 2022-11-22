#include <stdio.h>
#include <stdlib.h>


// Stampa e lettura Array
void printArray(int *a, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}

#define MAX_LINE_SIZE 10000   // maximum size of a line of input

int scanArray(int *a) {
    // scan line of text
    char line[MAX_LINE_SIZE];
    scanf("%[^\n]", line);
    getchar();

    // convert text into array
    int size = 0, offset = 0, numFilled, n;
    do {
        numFilled = sscanf(line + offset, "%d%n", &(a[size]), &n);
        if (numFilled > 0) {
            size++;
            offset += n;
        }
    } while (numFilled > 0);

    return size;
}

// nlogn
typedef struct{
    int i;
    int j;
} coppia;
//prova
coppia ricerca(){
    coppia c;
    c.i = 0;
    c.j = 10;
    return c;
    return (coppia ) {0,10};
}
// O(nlogn)
coppia sumoftwo_equalsC (int* a, int n, int chiave){
    
    int k = n-1;
    
    for (int i = 0; i < n; i++)
    {
        k = n-1;
        while (i<k)
        {
             if (a[i] + a[k] == chiave)
            {
                return  (coppia) {i,k};
            } else if (a[i] + a[k] > chiave){
                k--;
            } else {
                k=i;
            }
        }
    }
    return (coppia) {-1,-1};
}

// lineare
typedef struct{
    int i,j;
} int_pair;

int_pair cerca_somma(int *v, int n, int s){
    for (int i = 0, j = n-1; i < j;)
    {
        if (v[i] + v[j] == s)
        {
            return (int_pair) {i,j};
        } else if (v[i] + v[j] > s){
            j--;
        } else {
            i++;
        }
        
    } return (int_pair) {-1,-1};
    
}

int main(){
    /*
    int a[1000];
    int n=scanArray(a);

    int chiave;
    scanf("%d", &chiave);

    coppia pos = sumoftwo_equalsC(a,n,chiave);
    printf("%d %d", pos.i, pos.j);
    */
    // versione prof lineare
    int arr[1000];
    int b=scanArray(arr);

    int s;
    scanf("%d", &s);

    int_pair p = cerca_somma(arr,b,s);
    printf("%d %d \n", p.i,p.j);


    return 0;
}