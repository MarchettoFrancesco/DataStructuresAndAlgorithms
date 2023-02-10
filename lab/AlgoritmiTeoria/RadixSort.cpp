#include <iostream>
#include <vector>

using namespace std;
/**
 * Radix Sort
 * 
 * posso ordinare n interi aventi d cifre in theta(n*d)
 * osservo da destra a sinistra se no dovrei ricordarmi della struttura
 * 
 * uso counting sort modificato per leggere le cifre per digits, con operazione (numero / exp) modulo 10
*/

int getMax(int* array, int n) {
  int max = array[0];
  for (int i = 1; i < n; i++)
    if (array[i] > max)
      max = array[i];
  return max;
}

void countingSort(int* arr,int length, int exp){
    const int max = 10;
    vector<int> c(max);
    vector<int> b(length);
    for (int j = 0; j <= max; j++)
    {
        c[j] = 0;
    }
    for (int i = 0; i < length; i++)
    {
        c[(arr[i]/exp) % 10] = c[(arr[i]/exp) % 10] + 1;
    }
    for (int i = 0; i <= max; i++)
    {
        c[i] = c[i] + c[i-1];
    }
    for (int j = length-1; j >= 0; j--)
    {
        b[c[(arr[j]/exp) % 10]-1] = arr[j];
        c[(arr[j]/exp) % 10]--;
    }
    for (int i = 0; i < length; i++){
    arr[i] = b[i];
    }
}

void radixSort(int* arr, int length){
    int max = getMax(arr, length);
    
    for (int i = 1; max/i > 0; i*=10)
    {
        countingSort(arr,length,i);
    }
    
}



int main(){
    int array[] = {77,11,22,34,76,89};
    const int length = sizeof(array)/sizeof(*array);
    radixSort(array, length);
    for (int i = 0; i < length; i++)
    {
        cout << array[i] << endl;
    }
    
    return 0;
}