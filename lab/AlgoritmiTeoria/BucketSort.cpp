#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

/*
Bucket Sort
A vettore 0<= A[i] < 1 ... uniformemente distribuiti in [0, 1]
suddivido in blocchi uguali e mi aspetto di  avere circa lo stesso numero di elementi

non è in place,
è stabile solo se l'algoritmo lo è e scandisco da destra

*/

void bucketSort(float *array, int size) {
   vector<float> bucket[size];
   for(int i = 0; i<size; i++)  {          //put elements into different buckets
      bucket[int(size*array[i])].push_back(array[i]);
   }
   for(int i = 0; i<size; i++) {
      sort(bucket[i].begin(), bucket[i].end());       //sort individual vectors
   }
   int index = 0;
   for(int i = 0; i<size; i++) {
      while(!bucket[i].empty()) {
         array[index++] = *(bucket[i].begin());
         bucket[i].erase(bucket[i].begin());
      }
   }
}

int main(){
    float array[] = {0.25, 0.36, 0.58 ,0.41, 0.29 ,0.22, 0.45, 0.79, 0.01 ,0.69};
    bucketSort(array, 10);
    for (int i = 0; i < 10; i++)
    {
        cout << array[i] << endl;
    }
    

    return 0;
}