#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

ostream &operator << (ostream &out, const vector<int> &vec) {
    for (int i = 0; i < vec.size(); i++)
        out << vec[i] << " ";
    return out;
}

istream &operator >> (istream &in, vector<int> &vec) {
    // scan line of text 
    string line;
    getline(in, line);

    // convert line of text into a new input stream
    istringstream is(line);
    
    // convert new input stream into array
    int value;
    while (is >> value)
        vec.push_back(value);

    return in;
}

void SelectionSort(int A[], int n){

    int key = 0;
    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i+1; j < n; j++)
        {
            if (A[j] < A[min])
            {
                min = j;
            }
            
        }
        if (min != i)
        {
            key = A[i];
            A[i] = A[min];
            A[min] = key;
        }
    }
    
}

int main(){
    int A[6] = {2,1,4,5,6,3};
    int n = 6;

    SelectionSort(A,n);
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    

    return 0;
}