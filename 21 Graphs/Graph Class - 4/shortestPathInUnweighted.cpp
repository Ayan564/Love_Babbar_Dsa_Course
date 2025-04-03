#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<algorithm>
#include<vector>
#include<stack>
#include<climits>
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
    void shortestPathBFS(int src, int dest){
        unordered_map<int, bool> visited;
        unordered_map<int, int> parent; // to store the path
        queue<int> q;
        q.push(src);
        visited[src] = true;
        parent[src] = -1; // parent of source is -1

        while(!q.empty()){
            int frontNode = q.front(); q.pop();
            for(auto nbr : adjList[frontNode]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = true;
                    parent[nbr] = frontNode;
                }
            }
        }
        // print the path from src to dest
        vector<int> path;
        int node = dest;
        while(node != -1){
            path.push_back(node);
            node = parent[node];
        }
        reverse(path.begin(), path.end());
        cout << "Shortest Path from " << src << " to " << dest << ": ";
        for(auto it : path){
            cout << it << " ";
        }
    }
};

int main(){
    Graph g;
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 1);
    g.addEdge(0, 4, 1);
    g.addEdge(1, 4, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(3, 2, 1);
    g.addEdge(4, 3, 1);
    int n = 7; // number of nodes
    g.printAdjList(n);
    int src = 0; // source node
    int dest = 2; // destination node
    g.shortestPathBFS(src, dest);
    return 0;
}