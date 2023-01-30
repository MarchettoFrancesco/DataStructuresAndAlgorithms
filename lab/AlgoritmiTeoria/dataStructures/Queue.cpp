#include <iostream>
#include <queue>

using namespace std;

/*
    La Queue è una struttura dati di tipo FIFO, first in first out
    offre front,back .. push,pop,size,empty
*/
void print(std::queue<int> queue){
    while(!queue.empty()){
        cout << queue.front() << endl;
        queue.pop();
    }
}

int main(){
    std::queue<int> queue;
    queue.push(2);
    queue.push(4);
    queue.push(3);
    print(queue);




    return 0;
}