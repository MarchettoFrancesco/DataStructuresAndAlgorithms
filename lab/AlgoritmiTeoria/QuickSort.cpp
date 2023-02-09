#include <iostream>
#include <vector>
#include <cmath>

 using std::vector;
 using std::cout;
 using std::endl;

/**
 * Quicksort
 * Nel caso migliore cioè con il perno piu o meno in mezzo abbiamo una complessità di nlogn
 * mentre se faccio due chiamate sbilanciate ottengo una complessità quadratica
 * 
 * nota: il perno si può scegliere in maniera più efficente con medians of medians, così da ottenere
 * nlogn anche nel caso peggiore per via della scelta più ottimizzata
 * 
*/
int partition(vector<int> &array, int p, int q){
    int i = p-1;
    int x = array[q];
    for(int j = p; j<=q; j++){
        if(array[j] <= x){
            i++;
            std::swap(array[i], array[j]);

        }
    }
    return i;
}
void quicksort(vector<int> &array, int p, int q){
    if(p<q){
        int r = partition(array, p, q);
        quicksort(array,p,r-1);
        quicksort(array, r+1, q);
    }
}



int main(){
    vector<int> array = {10,2,3,5,4,8,9,12,1,7};
    quicksort(array,0,array.size()-1); 
    for (int i = 0; i < array.size(); i++)
    {
        cout << array[i] << endl;
    }
    


    return 0;
}