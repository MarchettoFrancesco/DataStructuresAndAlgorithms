// Meysam Aghighi

#include <iostream>
#include <cmath>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstdio>
using namespace std;

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

int Size, arr[100000],P[100000],M[100000],S[100000];


int main(){
    int  prefxlength,  p, q,  m,  aus, k;
    while(scanf("%d",&Size)==1){
        for (int i=0;i<Size;i++)
            scanf("%d",&arr[i]);

         prefxlength = 0;
        for (int i=0; i<Size;i++){
             p = 1;
            q =  prefxlength;
            while ( p <= q){
                 m = ceil(( p+q)/2.0);
                if ( arr[M[ m]] <  arr[i])
                     p =  m+1;
                else
                    q =  m-1;
            }
             aus =  p;
            P[i] = M[ aus-1];
            M[ aus] = i;

            if ( aus >  prefxlength)
                 prefxlength =  aus;
        }
        k = M[prefxlength];
        for (int i= prefxlength-1;i>=0;i--){
            S[i] = k;
            k = P[k];
        }
        cout << prefxlength << "\n" <<endl;
        
        for (int i=0;i< prefxlength-1;i++)
            cout << S[i] << endl;
        cout << S[ prefxlength-1] << "\n" << endl;
            

    }
    return 0;
}