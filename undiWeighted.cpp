#include <iostream>
#include <vector>
#include<tuple>
using namespace std;

struct node{
    int vertex;
    int weight;
    node* next;
};

void createGraph(vector<vector<pair<int,int>>> graph, int num){
    
    for(int i=0;i<num;i++){
        int u,v,weight;
    cout<<"enter the source vertex: "<<endl;
    cin>>u;
    cout<<"enter the destination vertex: "<<endl;
    cin>>v;
    cout<<"enter the weight: "<<endl;
    cin>>weight;

    graph[u].push_back(make_pair(v,weight));
    graph[v].push_back(make_pair(u,weight));
    }
    
}
void printing(vector<vector<pair<int,int>>> graph){
    if(graph.size()==0){
        cout<<"graph is empty!"<<endl;
    }else{
        int u,weight;
    for(int i=0;i<graph.size();i++){
        cout<<"vertex "<<i<<" -> ";
        for(auto edge: graph[i]){
            u = edge.first;
            weight = edge.second;
            cout<<"( neighbour: "<<u<<" , weight: "<<weight;
            
        }
        cout<<endl;
    }
    }
}
void deleteGraph(vector<vector<pair<int,int>>> graph){
    graph.clear();
}
int main(){
    vector<vector<pair<int,int>>> graph;
    int num;
    cout<<"enter the number of vertices : "<<endl;
    cin>>num;
    graph.resize(num);
    cout<<"creating graph"<<endl;
    createGraph(graph,num);
    cout<<"printing graph"<<endl;
    printing(graph);
    cout<<"deleting graph"<<endl;
    deleteGraph(graph);
    cout<<"printing graph"<<endl;
    printing(graph);

    
     
    return 0;
}