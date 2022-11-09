#include <stdio.h>

void stampaprefissi(char *string){
    int count = 0;
   for (int i = 0; string[i] != '\0' ; i++)
   {
    count++;
   }
   for (int m = count; m > 0; m--)
   {
    for (int j = 0; j < m; j++)
    {
        printf("%c",string[j]);
    }
    printf("\n");
   }
   
   
}

int main(){
    char string[1000];
    printf("Scrivi una stringa:");
    scanf("%[^\n]s", string);
     
    stampaprefissi(string);

    return 0;
}