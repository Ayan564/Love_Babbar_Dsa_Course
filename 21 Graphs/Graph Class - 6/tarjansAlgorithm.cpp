#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<stack>
using namespace std;

class Graph{
    public:
    unordered_map<int, list<int>> adjList; // adjacency list

    void addEdge(int u, int v, bool direction){ 
        if(direction == 0){ // direction = 0 -> undirected graph
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        else{ // direction = 1 -> directed graph
            adjList[u].push_back(v);
        }
    }
    void printAdjList(int n){
        for(int i = 0; i < n; i++){
            cout << i << " -> ";
            cout << "{";
            for(auto it : adjList[i]){
                cout << it << ", ";
            }
            cout << "}";
            cout << endl;
        }
    }
    int countBridges(int src, vector<int> &tin, vector<int> &low, vector<bool> &visited, int  parent, int &timer){
        visited[src] = true;
        tin[src] = low[src] = timer++;
        int bridges = 0;

        for(auto it : adjList[src]){
            if(it == parent) continue; // skip the parent node
            if(!visited[it]){
                bridges += countBridges(it, tin, low, visited, src, timer);
                low[src] = min(low[src], low[it]);
                if(low[it] > tin[src]){
                    cout << "Bridge: " << src << " - " << it << endl;
                    bridges++;
                }
            } else {
                low[src] = min(low[src], tin[it]);
            }
        }
        return bridges;
    }
};

int main(){
    Graph g;
    g.addEdge(0, 1, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(0, 2, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(3, 4, 0);

    int n = 5; // number of nodes
    g.printAdjList(n);
    int timer = 0; // timer to keep track of time of insertion
    int src = 0; // source node
    int parent = -1; // parent node
    vector<int> tin(n, -1); // time of insertion
    vector<int> low(n, -1); // lowest time of insertion
    vector<bool> visited(n, false); // visited array
    int bridges = g.countBridges(src, tin, low, visited, parent, timer);
    cout << "Total Bridges: " << bridges << endl;

    return 0;
}