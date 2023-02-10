#include <iostream>
#include <vector>

using namespace std;
/**
 * 
 * Lavora in theta(n+max) -> theta(n) ma solo nella condizione che l'input soddisfi:
 * arr[0-max] -> max O(n)
*/
vector<int> countingSort(vector<int> arr, int max){
    vector<int> c(max);
    vector<int> b(arr.size());
    for (int j = 0; j <= max; j++)
    {
        c[j] = 0;
    }
    for (int i = 0; i < arr.size(); i++)
    {
        c[arr[i]] = c[arr[i]] + 1;
    }
    for (int i = 0; i <= max; i++)
    {
        c[i] = c[i] + c[i-1];
    }
    for (int j = arr.size()-1; j >= 0; j--)
    {
        b[c[arr[j]]-1] = arr[j];
        c[arr[j]]--;
    }
    return b;
}

int main(){
    vector<int> arr = {6,4,5,2,3,17,18,15,1};
    arr = countingSort(arr, 18);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }
    
    return 0;
}