#include <iostream>
#include <cstring>
#include <list>

 using namespace std;

class HashTable{
    private:
        static const int hashGroups = 10;
        list<pair<int, string>> table[hashGroups];
    public:
        bool isEmpty() const;
        int hashFunction(int key);
        void insertItem(int key, string value);
        void removeItem(int key);
        string searchTable(int key);
        void printTable();

};

bool HashTable::isEmpty() const{
    int sum = 0;
    for(int i = 0; i<hashGroups; i++){
        sum += table[i].size();
    }
    if (sum == 0)
    {
        return true;
    } else {
        return false;
    }
}


int HashTable::hashFunction(int key){

     return key % hashGroups;
}

void HashTable::insertItem(int key, string value){

    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto bItr = begin(cell); // iteratore sulla table 
    bool keyExist = false;
    for(; bItr != end(cell); bItr++){
        if (bItr->first == key)
        {
            keyExist = true;
            bItr->second =  value;
            cout << "Key exists, value has beeen replaced" << endl;
            break;
        }
        
    }
    if (!keyExist)
    {
        cell.emplace_back(key, value);

    }
    return;
}


void HashTable::removeItem(int key){

    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto bItr = begin(cell); // iteratore sulla cella 
    bool keyExist = false;
    for(; bItr != end(cell); bItr++){
        if (bItr->first == key)
        {
            keyExist = true;
            bItr = cell.erase(bItr);
            cout << "Pair removed" << endl;
            break;
        }
        
    }
    if (!keyExist)
    {
        cout << "Key not found, item not removed" << endl;

    }
    return;
}

void HashTable::printTable() {
    for(int i; i<hashGroups; i++){
    if (table[i].size() == 0) continue;
    auto bItr = table[i].begin();
    for (; bItr != table[i].end(); bItr++) {
        cout << "[INFO] Key: " << bItr->first << " Value: " << bItr->second << endl;
    }
    }
}

int main(){
    HashTable hashtable;
    (hashtable.isEmpty())? cout << "Hashtable is empty" <<endl : cout << "Is not" <<endl; 
    hashtable.insertItem(101,"Francesco");
    hashtable.insertItem(201,"Pietro");
    hashtable.insertItem(102,"Franco");
    hashtable.insertItem(202,"Maria");
    hashtable.insertItem(301,"Grazia");
    hashtable.insertItem(401,"Lorenzo");
    hashtable.insertItem(501,"Francesco");

    hashtable.printTable();
    hashtable.insertItem(101,"Rick");
    hashtable.printTable();
    hashtable.removeItem(201); 

    (hashtable.isEmpty())? cout << "Hashtable is empty" <<endl : cout << "Is not" <<endl; 

    return 0;
}