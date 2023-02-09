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
// ======= FINE SCAN ========= inizio

/*
Insertion Sort, algoritmo di ordinamento, complessità lineare nel caso migliore e quadratica nel caso peggiore
E' inplace e stabile 
*/

void InsertionSort(int A[], int n){

    for(int j = 2; j<n; j++){
        int key = A[j];
        int i = j-1;
        while (i >= 0 && A[i] > key)
        {
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = key;

    }
}

int main(){
    int c[6] = {2,3,4,5,1,6};
    InsertionSort(c, sizeof(c)/ sizeof(c[0]));

    for (int i = 0; i <  sizeof(c)/ sizeof(c[0]); i++)
    {
        cout << c[i] << " ";
    }
    
    


    return 0;
}