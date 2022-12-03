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
/*
    si restituisca, se esiste, un intervallo [𝑖,𝑗] di posizioni nell'array 𝑉, con 𝑖≤𝑗, tale che 𝑉[𝑖]+𝑉[𝑖+1]+…+𝑉[𝑗]=𝑆.
    Provare a implementare 2 versioni dell'algoritmo che abbiano i seguenti tempi asintotici di esecuzione: 
    - 𝑜(𝑛^3), 
    - Θ(𝑛).
*/
typedef struct{
    int i,j;
    int somma; 
} int_pair;
// n^2
int_pair intervallo_datasomma(int *arr, int n, int s){
    int i = 0,j=1;
    int b = arr[i];
    for ( i ,j ; i < j,j<n; j++)
    {
        if (arr[i] == s)
        {
            return (int_pair){i, i};
        } else {
            
            b = b + arr[j];
            if (b == s)
            {
                return (int_pair){i,j};
            }
        }
    }
    for (int m = 0; m < n; m++)
    {
        b = b-arr[m];
        if (b == s)
        {
            return (int_pair) {m+1,n-1};
        }
        
    }
    // lineare ma non funziona sempre, vedi elearing per vecchio fatto che funzionava ma quadratico
    
    return (int_pair) {-1,-1}; // return funzione
}

// fare lineare



int main(){
    int arr[1000];
    int n=scanArray(arr);
    
    int s;
    scanf("%d", &s);

    int_pair risultato = intervallo_datasomma(arr,n,s);
    printf("%d %d \n", risultato.i,risultato.j);

    return 0;
}