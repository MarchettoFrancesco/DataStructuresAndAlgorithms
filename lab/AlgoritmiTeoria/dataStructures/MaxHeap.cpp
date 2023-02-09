#include <iostream>
#include <vector>
#include <cmath>

 using std::vector;
 using std::cout;
 using std::endl;

 // compiled with g++ -std=c++11

 class MaxHeap {
    private:
         
         double parent(int i) const {return floor(i/2);};
         int left(int i) const {return 2*i; };
         int right(int i) const {return 2*i+1;};
    public:
    int _size = 0 ;
         vector<int> vect = {-1};
        bool isEmpty() const {return _size == 0;};
        int getMax() const{return vect[1];};
        void insertItem(int val);
        void removeMax();
        void heapify(vector<int> &vect, int i);
        void printHeap();
 };

/* Metodo per inserire un elemento nella Heap,
  la dimensione della heap deve essere minore del vettore,
  aumento la size, inserisco il valore alla fine,
  associo i alla posizione del valore;
  Ora procedo con lo swap verso su, se la chiave del genitore è
  minore del figlio
*/
 void MaxHeap::insertItem(int val){
     if(_size +1 >= vect.size()){
          vect.push_back(0);
          insertItem(val);
     } else {
          _size++;
          vect[_size] = val;
          int i = _size;
          while (i > 1 && vect[parent(i)] < vect[i] )
          {
               std::swap(vect[parent(i)], vect[i]);
               i = parent(i);
          }  
     }
 }

/* Metodo Heapify per fare il shift down, nella cancellazione
  scende controllando figlio destro e sinistro in base alle
  disugualianze swappa a sinistra o destra
*/
 void MaxHeap::heapify(vector<int> &vect,int i){

     int m = i;
     if (left(i) < _size && vect[i] < vect[left(i)]){
          m = left(i);
     }
     if(right(i) < _size && vect[m] < vect[right(i)]){
          m = right(i);
     }
     if(m != i){
          std::swap(vect[i], vect[m]);
          heapify(vect,m);
     }
 }

/* Metodo removeMax, sostituisco massimo e ultimo elemento,
 diminuisco la size e faccio scendere l'ultimo elemento con heapify
 perchè torni nella posizione corretta

*/
 void MaxHeap::removeMax(){
     if (_size > 0)
     {
          std::swap(vect[1], vect[_size]);
          _size--;
          heapify(vect,1);
          
     }
     
 }

 void MaxHeap::printHeap(){
     for (int i = 0; i < 1+_size; i++)
     {
          cout << vect[i] << endl;
     }
     
 }

 void printArray(vector<int> arr){
     for (int i = 0; i < arr.size(); i++)
     {
          cout << arr[i] << endl;
     }
     
 }
