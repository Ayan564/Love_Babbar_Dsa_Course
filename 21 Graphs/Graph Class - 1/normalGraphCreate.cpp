#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
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

    bool cycleDetectionUndirectBFS(int src){
        queue<int> q;
        unordered_map<int, int> parent;
        unordered_map<int, bool> visited;
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
                else if(visited[nbr]  && nbr != parent[frontNode]){
                    return true; // cycle detected
                }
            }
        }
        return false; // no cycle detected
    }

    bool cycleDetectionUndirectedDFSHelper(int src, unordered_map<int, bool> &visited, int parent){
        visited[src] = true;
        for(auto nbr : adjList[src]){
            if(!visited[nbr]){
                if(cycleDetectionUndirectedDFSHelper(nbr, visited, src)){
                    return true; // cycle detected
                }
            }
            else if(visited[nbr] && nbr != parent){
                return true; // cycle detected
            }
        }
        return false; // no cycle detected
    }

    bool cycleDetectionUndirectedDFS(int src){
        unordered_map<int, bool> visited;
        for(int i = 0; i < adjList.size(); i++){
            if(!visited[i]){
                if(cycleDetectionUndirectedDFSHelper(i, visited, -1)){
                    return true; // cycle detected
                }
            }
        }
        return false; // no cycle detected
    }

    bool cycleDetectionDirectedDFSHelper(int src, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsTracker){
        visited[src] = true;
        dfsTracker[src] = true;
        for(auto nbr : adjList[src]){
            if(!visited[nbr]){
                if(cycleDetectionDirectedDFSHelper(nbr, visited, dfsTracker)){
                    return true; // cycle detected
                }
            }
            else if(visited[nbr] &&dfsTracker[nbr]){
                return true; // cycle detected
            }
        }
        dfsTracker[src] = false; // backtrack
        return false; // no cycle detected
    }

    bool cycleDetectionDirectedDFS(int src){
        unordered_map<int, bool> visited;
        unordered_map<int, bool> dfsTracker;
        for(int i = 0; i < adjList.size(); i++){
            if(!visited[i]){
                if(cycleDetectionDirectedDFSHelper(i, visited, dfsTracker)){
                    return true; // cycle detected
                }
            }
        }
        return false; // no cycle detected
    }
};

int main(){
    // Graph g;
    // g.addEdge(0, 1, 0);
    // g.addEdge(0, 2, 0);
    // g.addEdge(1, 3, 0);
    // g.addEdge(2, 4, 0);
    // int n = 4; // number of nodes
    // g.printAdjList(n);
    // // g.printAdjList();
    // cout << "BFS Traversal: ";
    // g.bfsTraversal(0);
    // cout << endl;
    // cout << "DFS Traversal: ";
    // g.dfsTraversal(n);
    // cout << endl;
    // bool cycle = false;
    // cout << "Cycle Detection using BFS: ";
    // for(int i = 0; i < n; i++){
    //     cycle = g.cycleDetectionUndirectBFS(i);
    // }
    // if(cycle){
    //     cout << "Cycle detected" << endl;
    // }
    // else{
    //     cout << "No cycle detected" << endl;
    // }
    // cycle = false;
    // cout << "Cycle Detection using DFS: ";
    // if(g.cycleDetectionUndirectedDFS(0)){
    //     cout << "Cycle detected" << endl;
    // }
    // else{
    //     cout << "No cycle detected" << endl;
    // }
    // cout << endl;

    Graph g;
    g.addEdge(4, 4, 1);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 3, 1);
    int n = 5; // number of nodes
    g.printAdjList(n);
    // g.printAdjList();
    cout << "BFS Traversal: ";
    g.bfsTraversal(0);
    cout << endl;
    cout << "DFS Traversal: ";
    g.dfsTraversal(n);
    cout << endl;
    bool cycle = false;
    cout << "Cycle Detection using DFS: ";
    if(g.cycleDetectionDirectedDFS(0)){
        cout << "Cycle detected" << endl;
    }
    else{
        cout << "No cycle detected" << endl;
    }
    return 0;
}