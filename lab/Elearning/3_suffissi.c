#include <stdio.h>

void stampasuffissi(char *string){
    int count = 0;
   for (int i = 0; string[i] != '\0' ; i++)
   {
    count++;
   }
   for (int m = 0; m <count; m++)
   {
    for (int j = m; j < count; j++)
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
     
    stampasuffissi(string);

    return 0;
}