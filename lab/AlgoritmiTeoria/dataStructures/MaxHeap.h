#include <iostream>
#include <vector>
#include <cmath>

 using std::vector;
 using std::cout;
 using std::endl;

 // compiled with g++ -std=c++11

 class MaxHeap {
    private:
         
         double parent(int i) {return floor(i/2);};
         int left(int i){return 2*i; };
         int right(int i){return 2*i+1;};
    public:
    int _size ;
         vector<int> vect = {-1};
        bool isEmpty() const {return _size == 0;};
        int getMax() const{return vect[1];};
        void insertItem(int val);
        void removeMax();
        void heapify(vector<int> &vect, int i);
        void printHeap();
 };
 void printArray(vector<int> arr);

