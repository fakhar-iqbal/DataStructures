#include<iostream>
#include<vector>
using namespace std;

class Graph{
private:
    int vertices;
    vector<vector<pair<int,int>>> adjacencyList;

public:
    Graph(int v){
        vertices = v;
        adjacencyList.resize(vertices);
    }

    void addEdges(int u, int v, int weight){
        adjacencyList[u].push_back(make_pair(v,weight));
        adjacencyList[v].push_back(make_pair(u,weight));


    }

    void printGraph(){
        for(int i=0; i<vertices;i++){
            cout<<"vertex "<<i<<"->";
            for(auto edge: adjacencyList[i]){
                int v = edge.first;
                int weight = edge.second;
                cout<<"("<<v<<","<<weight<<")";
            }
            cout<<endl;
        }



    }

    void deleteGraph(){
        adjacencyList.clear();
    }


};
int main(){

    int choice, vertices;
    cout<<"enter the number of vertices in the graph"<<endl;
    cin>>vertices;

    Graph graph(vertices);

    while(true){
        cout<<"\nMenu"<<endl;
        cout<<"1. Add an edge"<<endl;
        cout<<"2. print the graphs information"<<endl;
        cout<<"3. delete the graph"<<endl;
        cout<<"4. exit"<<endl;
        cout<<"enter the choice"<<endl;
        cin>>choice;


        switch(choice){
            case 1:
            int u,v,weight;
            cout<<"enter the source vertex: "<<endl;
            cin>>u;
            cout<<"enter the destination source"<<endl;
            cin>>v;
            cout<<"enter the weight"<<endl;
            cin>>weight;
            graph.addEdges(u,v,weight);
            break;
            case 2:
            cout<<"\nGraphs Information:"<<endl;
            graph.printGraph();
            break;
            case 3:
            graph.deleteGraph();
            cout<<"graph deleted!"<<endl;
            break;
            case 4:
            cout<<"exiting!"<<endl;
            exit(0);
            
            default:
            cout<<"Invalid command!"<<endl;
        }
    }
    return 0;
}