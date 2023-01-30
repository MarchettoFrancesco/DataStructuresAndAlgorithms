#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/*
It is LIFO (last-in, first-out) data structure.
std::stack allows to push(insert) and pop(remove) only from back.

FUNCTIONS PROVIDED:
empty() – Returns whether the stack is empty – Time Complexity : O(1)
size() – Returns the size of the stack – Time Complexity : O(1)
top() – Returns a reference to the top most element of the stack – Time Complexity : O(1)
push(g) – Adds the element ‘g’ at the top of the stack – Time Complexity : O(1)
pop() – Deletes the top most element of the stack – Time Complexity : O(1)
*/

void print(std::stack<int> stack) {
    while(!stack.empty()){
    cout << stack.top() << endl;
    stack.pop(); 
    }
}


int main(){
    std::stack<int> stack;
    stack.push(2);
    stack.push(3);
    stack.push(4);
    print(stack);

    return 0;
}