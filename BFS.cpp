#include <iostream>
#include<queue>
#include <vector>
using namespace std;


//creating BFS traversal method

void BFS(vector<vector<int>> &graph, int startNode){
    int numNodes = graph.size();
    //vector for visited nodes
    vector<int> visited(numNodes,false);

    //queue for BFS traversing
    queue<int> BFSQue;

    //set the startNode as visited and push it in the BFSQue
    visited[startNode] = true;
    BFSQue.push(startNode);

    while(!BFSQue.empty()){
        //deque a node, print it
        int currentNode = BFSQue.front();
        cout<<currentNode<<" ";
        BFSQue.pop();

        //grab the neighbors and push it in to the queue
        vector<int> &neighbours = graph[currentNode];
        for(int neighbor: neighbours){
            if(!visited[neighbor]){
                visited[neighbor] = true;
                BFSQue.push(neighbor);
            }
        }
    }
    
}


int main(){

    //vector for an unweighted directed graph;
    vector<vector<int>> graph = {
        {1,2},    //0 is connected to 1 and 2
        {0,2,3},  // 1 is connected to 0,2,3
        {0,1,3},  //same for down all
        {1,2,4},
        {3,5},
        {4}
    };
    int startNode = 0;
    cout<<"BFS traversal of graph: "<<endl;
    BFS(graph,startNode);


    return 0;
}