#include <stdio.h>
//printf e scanf
#include <stdlib.h>

void myprint(int a, int b){
	printf("%d + %d = %d", a, b, a+b);
	short int y;
	long int z;
    long long int w;
    char c;
    float f;
    double g; // 0.1 + 0.1 + 0.1 =! 0.3, 0.1 in binario non viene rappresentato in modo esatto
}

 struct nodo_lista1{
        int value;
        struct nodo_lista1 *next;
    }; //presuppone che gli si dia il nome del tipo di dato e i campi

//definisco un nuovo tipo di dato chiamato mio nodo che è uno struct nodo lista

typedef struct nodo_lista{
    int value;
    struct nodo_lista *next;
} mio_nodo;


// ---- SWAP -----
/*
nel mio spazio di memoria creo uno stack nuovo dove vengono create le variabili temp, x ed y dove vengono copiati i valori che assegno nel main
devo passare gli indirizzi di memoria quindi i puntatori
*/
void swap(int x,int y){ 
    int tmp;
    tmp = x;
    x = y;
    y = tmp;
}
void swapgiusto(int *x, int *y){ // questo asterisco significa è un puntatore
    int tmp;
    tmp = *x; // questo asterisco dice che voglio accedere a quel valore a cui punta il puntatore
    *x = *y;
    *y = tmp;
}

// ---- MAIN ----

int main(){
    int a=5;
    int b=7;
    int n;
    myprint(a,b);
   
    int arr[10] = {1,2,3};
    for (int i = 0; i < 10; i++)
    {
       printf("\n %d", arr[i]);
    }
    
    //scanf non dico la variabile n, ma l'indirizzo di memoria
    char stringa[10] = "Hello"; // si può non dichiarare la dimensione se lo si inizializza subito e lui ti allocherà il necessario
    for (int i = 0; i < 10; i++)
    {
       printf("\n %c %x\n",(int) stringa[i],(int) stringa[i]); // prendi il carattere converti in intero e passalo per valore
       // stampa carattere per carattere finche non trova zero, se non di interi
    }
    //lo spazio allocato è in byte, un singolo intero sono 4 byte, 100 interi 400 byte
    // i puntatori sono long int hanno dimensioni pari ad 8, 
    printf("Spazio allocato dalla stringa: %ld \n", sizeof(stringa));


   struct nodo_lista nodo1; // senza typedef
    mio_nodo nodo2; // con typedef

    nodo1.value = 7;
    nodo1.next = NULL;



    return 0;
}

