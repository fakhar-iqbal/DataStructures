#include <iostream>
using namespace std;

//creating the structure of the node
struct node{
    int vertex;
    node* next;
};

// node* newNode(int data){
//     node* n = new node();
//     n->vertex = data;
//     n->next = nullptr;

//     return n;
// }
void createGraph(node* adjlist[],int num){
    int neighbours;
    node* last;
    // making every list a null pointer.
    for(int i=0;i<num;i++){
        adjlist[i] = nullptr;

    }
    for(int i=0;i<num;i++){
        last =  nullptr;
        cout<<"enter the number of neighbour nodes for "<<i<<":"<<endl;
        cin>>neighbours;
        for(int j=1;j<=neighbours;j++){
            cout<<"enter the neighbour "<<j<<" of node "<<i<<": "<<endl;
            int data;
            cin>>data;
            node* newNode = new node();
            newNode->vertex = data;
            newNode->next= nullptr;
            if(adjlist[i]==nullptr){
                adjlist[i] = newNode;
            }else{
                last->next = newNode;
            }
            last = newNode;
            
            


        }
    }
}

void displayGraph(node* adjlist[],int num){
    for(int i=0;i<num;i++){
        cout<<"neighbours of vertex "<<i<<" are: ";
        node* temp = adjlist[i];
        while(temp!=nullptr){
            cout<<temp->vertex<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
}
void deleteGraph(node* adjlist[], int num){
    for(int i=0;i<num;i++){
        node* temp = adjlist[i];
        while(temp!=nullptr){
            node* node =temp;
            temp = temp->next;
            delete node;
        }
    }
    cout<<"the graph is deleted!"<<endl;
}
int main(){
    cout<<"enter the number of nodes: "<<endl;
    int num;
    cin>>num;
    node* adjlist[num];
    createGraph(adjlist,num);
    displayGraph(adjlist,num);
    deleteGraph(adjlist,num);
    return 0;
}