
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <string>
#include <sstream>

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


vector<int> longestIncreasingSubsequence(const std::vector<int>& array)
{
    vector<int> lis;
    vector<int> lengths(array.size(), 1);
    vector<int> prev(array.size(), -1);

    for (int i = 0; i < array.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (array[i] > array[j] && lengths[i] < lengths[j] + 1)
            {
                lengths[i] = lengths[j] + 1;
                prev[i] = j;
            }
        }
    }
    int max_index = 0;
    for (int i = 0; i < array.size(); i++)
    {
        if (lengths[i] > lengths[max_index])
        {
            max_index = i;
        }
    }
    while (max_index != -1)
    {
        lis.push_back(max_index);
        max_index = prev[max_index];
    }
    reverse(lis.begin(), lis.end());
    return lis;
}

int main()
{
    int m;
    cin >> m;
    
    vector<int> array;
    cin >> array;

    vector<int> lis = longestIncreasingSubsequence(array);
    cout << lis.size() << "\n" << endl;
    for (int index : lis)
    {
        cout << index << " " << endl;
    }
    cout << "\n" << endl;
    
    

    return 0;
}
