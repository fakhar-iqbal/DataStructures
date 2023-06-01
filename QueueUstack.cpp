#include <iostream>
#include <stack>
using namespace std;

class Queue{

    int size;
    //we will use 2 stacks
    stack<int> s1;
    stack<int> s2;
    public:
    Queue(){
        size = 0;

    }

    void push(int val){
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();

        }
        s1.push(val);
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
    }

    int top(){
        return s2.top();
    }
    void pop(){
        s2.pop();
    }
};
int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout<<q.top()<<endl;
    q.push(4);
    cout<<q.top()<<endl;

    return 0;
}
