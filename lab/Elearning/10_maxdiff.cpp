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
// ======= FINE SCAN ========= Es 10 inizio

typedef struct{
    int i,j;
} int_pair;

int_pair max_diff(const vector<int> &v){
    vector<int> e(v.size());
    vector<int> f(v.size());
    e[0] = v[0];
    f[0] = 0;
    for(int i = 1; i < v.size(); i++){
        if (v[i] < e[i-1]){
            e[i] = v[i];
            f[i] = i;
        }
        else{
            e[i] = e[i-1];
            f[i] = f[i-1];
        }
    }
    int_pair p = (int_pair) {0,0};
    int md = v[0] - e[0];  
    for(int j=1; j < v.size(); j++){
        if (v[j] - e[j] > md){
            md = v[j] - e[j];
            p.j = j;
            p.i = f[j];
        }
        else{
            e[j] = e[j-1];
        }

    }
    return p;
    
    
        
}
int main(){
    vector<int> v;
    cin >> v;
    int_pair p = max_diff(v);
    cout << p.i << " " << p.j << endl ;
    return 0;
}