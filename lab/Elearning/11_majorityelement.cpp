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
// ======= FINE SCAN ========= Es 11 inizio

/*
Scrivere un programma che riceva in input un array (non necessariamente ordinato) di lunghezza arbitraria 𝑛 contenente interi 
(non necessariamente positivi), e che restituisca in output, se esiste, l'elemento maggioritario, ovvero l'elemento dell'array 
che occorre un numero di volte strettamente maggiore di 𝑛2. Se tale elemento non esiste, l'algoritmo dovrà stampare la stringa "No majority".
*/

int majorityElementofA(const vector<int> &v){
    int major = v[0];
    int count = 0;
    for (int i = 0; i < v.size(); i++)
    {
       if (v[i] == major)
       {
            count ++;
       } else {
            count --;
       }

       if (count == 0)
       {
        major = v[i];
        count = 1;
       }
       
    }
    count = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == major)
        {
            count++;
        }
        
    }
    if (count > v.size()/2)
    {
       return major;
    } else {
        return -1;
    }
    
}

int main(){
    vector<int> v;
    cin >> v;
    int risultato = majorityElementofA(v);
    if (risultato == -1)
    {
        cout << "No majority" << endl;
    } else{
        cout << risultato << " " << endl ;
    }
    
    

    return 0;
}
