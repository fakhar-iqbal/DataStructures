#include <iostream>
#include <queue>
using namespace std;

class Stack{
    int size;
    queue<int> q1;
    queue<int> q2;

    public:
    Stack(){
        int N = 0;
    }

    void push(int x){
        q1.push(x);
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }

    int top(){
        
        return q1.front();
    }
    

};

int main(){
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout<<st.top();
    //here the last element 3 will pop out

    return 0;
}