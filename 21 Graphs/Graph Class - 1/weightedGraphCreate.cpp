#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class Graph{
    public:
    unordered_map<int, list<pair<int, int>>> adjList; // adjacency list

    void addEdge(int u, int v, int weight, bool direction){ 
        if(direction == 0){ // direction = 0 -> undirected graph
            adjList[u].push_back({v, weight});
            adjList[v].push_back({u, weight});
        }
        else{ // direction = 1 -> directed graph
            adjList[u].push_back({v, weight});
        }
    }

    void printAdjList(int n){
        for(int i = 0; i < n; i++){
            cout << i << " -> ";
            cout << "{";
            for(auto it : adjList[i]){
                cout << "(" << it.first << ", " << it.second << "), ";
            }
            cout << "}";
            cout << endl;
        }
    }

    void printAdjList(){
        for(auto it : adjList){
            cout << it.first << " -> ";
            cout << "{";
            for(auto i : it.second){
                cout << "(" << i.first << ", " << i.second << "), ";
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
                if(!visited[it.first]){
                    queue.push_back(it.first);
                    visited[it.first] = true;
                }
            }
        }
    }

    void dfsHelper(int src, unordered_map<int, bool> &visited){
        visited[src] = true;
        cout << src << " ";
        for(auto it : adjList[src]){
            if(!visited[it.first]){
                dfsHelper(it.first, visited);
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
    g.addEdge(0, 3, 3, 1);
    g.addEdge(0, 5, 3, 1);
    g.addEdge(0, 2, 3, 1);
    g.addEdge(2, 5, 3, 1);
    g.addEdge(3, 5, 3, 1);
    g.addEdge(5, 4, 3, 1);
    g.addEdge(5, 6, 3, 1);
    g.addEdge(4, 1, 3, 1);
    g.addEdge(6, 1, 3, 1);
    int n = 7; // number of nodes
    g.printAdjList(n);
    // g.printAdjList();
    cout << endl;
    cout << "BFS Traversal: ";
    g.bfsTraversal(0);
    cout << endl;
    cout << "DFS Traversal: ";
    g.dfsTraversal(n);
    cout << endl;
    return 0;
}