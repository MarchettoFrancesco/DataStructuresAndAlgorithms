#include <iostream>
#include <vector>
#include <cmath>
#include "dataStructures/MaxHeap.h"


 using std::vector;
 using std::cout;
 using std::endl;

 // compiled with g++ -std=c++11 HeapSort.cpp dataStructures/MaxHeap.cpp


 /*
 HeapSort prende tempo theta(nlogn) sempre, non è stabile e non è in place

 nlogn perchè ho un ciclo for con heapify, nel peggiore dei casi faccio n volte heapify che costa logn -> nlogn
 heapify è logn perchè fa i confronti col genitore facendo salti di i/2
 */

 MaxHeap* buildHeap(vector<int> &arr){
     MaxHeap* MaxHeapD = new MaxHeap();
     for (int i = 0; i < arr.size(); i++)
     {
          MaxHeapD->insertItem(arr[i]);
     }
     MaxHeapD->printHeap();
     return MaxHeapD;
 }

 vector<int> HeapSort(vector<int> &array){
     MaxHeap* MaxHeapDaOrdinare = buildHeap(array);
     for (int i =array.size() ; i > 2  ; i--)
     {
          std::swap(MaxHeapDaOrdinare->vect[i], MaxHeapDaOrdinare->vect[1]);
          MaxHeapDaOrdinare->_size--;
          MaxHeapDaOrdinare->heapify(MaxHeapDaOrdinare->vect,1);
     }
     return MaxHeapDaOrdinare->vect;
 }

 int main(){
     MaxHeap* PriorityQueue = new MaxHeap();
     if (PriorityQueue ->isEmpty() )
     {
          cout << "The queue is empty, everything ok" << endl;
     } else {
          cout << "The queue is not empty, we have a problem" << endl;
     }
     // Prove corretto funzionamento Max Heap
     /*
     PriorityQueue->insertItem(14);
     PriorityQueue->insertItem(15);
     PriorityQueue->insertItem(16);
     PriorityQueue->printHeap();
     int max = PriorityQueue->getMax();
     cout << "The max is:" << max << endl;
     
     cout << "Now we removed the max:" << endl;
     PriorityQueue->removeMax();
     PriorityQueue->printHeap();
     */
     vector<int> array = {10,8,7,9,2,1,3,4,22};
     cout << "Il tuo array è:" << endl;
     printArray(array);

     array = HeapSort(array);
     cout << "Il tuo array ordinato è:" << endl;
     for (int i = 1; i < array.size(); i++)
     {
          cout << array[i] << endl;
     }

     vector<int> array2 = {1,15,2,4,77,8,3};
     cout << "Il tuo array è:" << endl;
     printArray(array2);

     array2 = HeapSort(array2);
     cout << "Il tuo array ordinato è:" << endl;
     for (int i = 1; i < array2.size(); i++)
     {
          cout << array2[i] << endl;
     }


     return 0;
 }

