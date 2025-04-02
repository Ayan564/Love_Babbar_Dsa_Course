#include<iostream>
#include<unordered_map>
#include<list>
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

    void printAdjList(){
        for(auto it : adjList){
            cout << it.first << " -> ";
            cout << "{";
            for(auto i : it.second){
                cout << i << ", ";
            }
            cout << "}";
            cout << endl;
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

    void bfsTraversal(int src){
        list<int> queue;
        unordered_map<int, bool> visited;
        queue.push_back(src);
        visited[src] = true;

        while(!queue.empty()){
            int frontNode = queue.front();
            cout << frontNode << " ";
            queue.pop_front();
            for(auto it : adjList[frontNode]){
                if(!visited[it]){
                    queue.push_back(it);
                    visited[it] = true;
                }
            }
        }
    }

    void dfsHelper(int src, unordered_map<int, bool> &visited){
        visited[src] = true;
        cout << src << " ";
        for(auto it : adjList[src]){
            if(!visited[it]){
                dfsHelper(it, visited);
            }
        }
    }

    void dfsTraversal(int n){
        unordered_map<int, bool> visited;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfsHelper(i, visited);
            }
        }
    }
};

int main(){
    Graph g;
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    int n = 4; // number of nodes
    g.printAdjList(n);
    // g.printAdjList();
    cout << "BFS Traversal: ";
    g.bfsTraversal(0);
    cout << endl;
    cout << "DFS Traversal: ";
    g.dfsTraversal(n);
    cout << endl;
    return 0;
}