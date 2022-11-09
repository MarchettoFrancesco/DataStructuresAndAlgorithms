#include <stdio.h>

void swapgiusto(char *x, char *y){ // questo asterisco significa è un puntatore
    char tmp;
    tmp = *x; // questo asterisco dice che voglio accedere a quel valore a cui punta il puntatore
    *x = *y;
    *y = tmp;
}
void swap(int x,int y){ 
    int tmp;
    tmp = x;
    x = y;
    y = tmp;
}
void swapgiusto1(int *x, int *y){ // questo asterisco significa è un puntatore
    int tmp;
    tmp = *x; // questo asterisco dice che voglio accedere a quel valore a cui punta il puntatore
    *x = *y;
    *y = tmp;
}

void reverse(char *stringa){
    int n;
    for (n = 0; stringa[n] != '\0'; n++){
    } // stringa[n] = '\0', stringa+n-1 è l'ultimo elemento della stringa

    for (int i = 0,j = n-1; i < j; i++,j--)
    {
        swapgiusto( &(stringa[i]), &(stringa[j]));
        // swap(stringa + i, stringa +j) uguale
    }

}

int main(){
    
   // prova dei swap per capire
   int a = 5;
   int b = 6;
    swap(a,b);
    printf("%d,%d\n", a,b);
    swapgiusto1(&a,&b);
    printf("%d,%d\n", a, b);

    // main reverse stringa
    char stringa[1000]; // occhio alla scelta del numero di caratteri, errore tipico sistemi operativi, scrive lo stesso anche se sono 2000 carat.
    scanf("%[^\n]s", stringa); // non serve & perchè stringa è gia un puntatore nella zona di memoria, metto [^\n] se no si fermerebbe allo spazio
    reverse(stringa);
    
    printf("%s\n\n",stringa);
    

return 0;

}