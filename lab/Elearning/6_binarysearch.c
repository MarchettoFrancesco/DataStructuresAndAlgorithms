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
// fine stampa e lettura array

int ricerca_dicotomica(int* a, int n, int chiave){
    int start=0;
    int end = n-1;

    while(start<=end){
        int mezzo = (start+end)/2;
        
        if (a[mezzo] == chiave)
        {
            return mezzo;
        } else if(a[mezzo] < chiave){
            start = mezzo + 1;
        } else {
            end = mezzo - 1;
        }
        
    }
    return -1;
}

int main(){
    int a[1000];
    int n=scanArray(a);
    printf("l'array inserito è");
    printArray(a,n);
    printf("\n");

    int chiave;
    scanf("%d", &chiave);

    int pos = ricerca_dicotomica(a,n,chiave);
    printf("%d", pos);
    return 0;
}