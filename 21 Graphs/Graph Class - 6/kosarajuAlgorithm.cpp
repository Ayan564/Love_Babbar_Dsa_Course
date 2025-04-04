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
    void topoDFS(int src, unordered_map<int, bool>& visited, stack<int>& ans){
        visited[src] = true;
        for(auto nbr : adjList[src]){
            if(!visited[nbr]){
                topoDFS(nbr, visited, ans);
            }
        }
        ans.push(src); // push the node to the stack after visiting all its neighbours
    }
    void dfs(int src, unordered_map<int, bool>& visited, unordered_map<int, list<int>>& revAdjList){
        visited[src] = true;
        cout << src << " "; 
        for(auto nbr : revAdjList[src]){
            if(!visited[nbr]){
                dfs(nbr, visited, revAdjList);
            }
        }
    }
    int countScc(int n){
        // step 1: do DFS and push the nodes to a stack in topological order
        stack<int> topoOrder;
        unordered_map<int, bool> vis;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                topoDFS(i, vis, topoOrder);
            }
        }
        // step 2: reverse the graph
        unordered_map<int, list<int>> revAdjList;
        for(auto it : adjList){
            int u = it.first;
            for(auto v : it.second){
                revAdjList[v].push_back(u);
            }
        }
        // step 3: do DFS on the reversed graph in the order of the stack
        int count = 0;
        unordered_map<int, bool> visited;
        while(!topoOrder.empty()){
            int src = topoOrder.top(); topoOrder.pop();
            if(!visited[src]){
                cout << "SCC: ";    
                dfs(src, visited, revAdjList); // DFS on the reversed graph
                cout << endl;
                count++;
            }
        }
        return count;
    }
};

int main(){
    Graph g;
    g.addEdge(0, 3, 1);
    g.addEdge(3, 2, 1);
    g.addEdge(2, 1, 1);
    g.addEdge(1, 0, 1);
    g.addEdge(2, 4, 1);
    g.addEdge(4, 5, 1);
    g.addEdge(5, 6, 1);
    g.addEdge(6, 4, 1);
    g.addEdge(6, 7, 1);
    int n = 8; // number of nodes
    g.printAdjList(n);
    stack<int> topoOrder;
    unordered_map<int, bool> visited;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            g.topoDFS(i, visited, topoOrder);
        }
    }
    int sccCount = g.countScc(n);
    cout << "Number of Strongly Connected Components: " << sccCount << endl;
    return 0;
}