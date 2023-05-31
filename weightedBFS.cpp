#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//defining a node along with its weight
struct node{
    int vertex;
    int weight;
};

void BFS(vector<vector<node>> &graph, int startNode){
    int numNode = graph.size();
    //making a queue for BfS
    queue<int> BFSq;
    //vector of visited nodes
    vector<bool> visited(numNode,false);

    //push first node and make it visited
    BFSq.push(startNode);
    visited[startNode] = true;

    //adding neighbors to queue
    while(!BFSq.empty()){
        int currentNode = BFSq.front();
        cout<<currentNode<<" ";
        BFSq.pop();
        //making a vector for its neighbors
        vector<node> neighbors = graph[currentNode];

        for(node neighbor: neighbors){
            if(!visited[neighbor.vertex]){
                visited[neighbor.vertex] = true;
                BFSq.push(neighbor.vertex);
            }
        }
    }
    cout<<endl;
}

int main(){
    
    vector<vector<node>> graph = {
        {{1,4},{2,2}},   //node 0 is connected to 1 and 2 with weight 4,2 respectively.
        {{3,1},{4,5}},
        {{5,3}},
        {},
        {{3,2}},
        {}
    };

    int startNode = 0;
    cout<<"BFS traversal of weighted graph is: "<<endl;
    BFS(graph,startNode);



    return 0;
}