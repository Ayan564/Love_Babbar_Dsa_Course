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
    unordered_map<int, list<pair<int, int>>> adjList; // adjacency list

    void addEdge(int u, int v, int wt, bool direction){ 
        if(direction == 0){ // direction = 0 -> undirected graph
            adjList[u].push_back({v, wt});
            adjList[v].push_back({u, wt});
        }
        else{ // direction = 1 -> directed graph
            adjList[u].push_back({v, wt});
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

    void topoDFS(int src, unordered_map<int, bool>& visited, stack<int>& ans){
        visited[src] = true;
        for(auto nbr : adjList[src]){
            if(!visited[nbr.first]){
                topoDFS(nbr.first, visited, ans);
            }
        }
        ans.push(src); // push the node to the stack after visiting all its neighbours
    }

    void shortestPathDFS(int src, int dest){
        stack<int> topoOrder;
        unordered_map<int, bool> visited;
        unordered_map<int, int> parent; // to store the path
        topoDFS(src, visited, topoOrder);
        int n = topoOrder.size();
        vector<int> dist(n, INT_MAX); // distance vector
        src = topoOrder.top(); topoOrder.pop();
        dist[src] = 0; // distance of source from itself is 0
        parent[src] = -1; // parent of source is -1
        for(auto nbr : adjList[src]){
            int node = nbr.first;
            int weightDistance = nbr.second;
            if(dist[node] > dist[src] + weightDistance){
                dist[node] = dist[src] + weightDistance;
                parent[node] = src; // update the parent of the node
            }
        }
        while(!topoOrder.empty()){
            int frontNode = topoOrder.top(); topoOrder.pop();
            for(auto nbr : adjList[frontNode]){
                int node = nbr.first;
                int weightDistance = nbr.second;
                if(dist[node] > dist[frontNode] + weightDistance){
                    dist[node] = dist[frontNode] + weightDistance;
                    parent[node] = frontNode; // update the parent of the node
                }
            }
        }
        cout << "Shortest Path from " << src << ": " << endl;
        for(int i = 0; i < n; i++){
            cout << "to " << i << " is " << dist[i] << endl;
        }
        cout << "Shortest Path from " << src << " to " << dest << ": ";
        vector<int> path;
        int node = dest;
        while(node != -1){
            path.push_back(node);
            node = parent[node];
        }
        reverse(path.begin(), path.end());
        for(auto it : path){
            cout << it << " ";
        }
        cout << endl;
    }
};

int main(){
    Graph g;
    g.addEdge(0, 1, 5, 1);
    g.addEdge(0, 2, 13, 1);
    g.addEdge(0, 4, 3, 1);
    g.addEdge(1, 2, 7, 1);
    g.addEdge(1, 4, 1, 1);
    g.addEdge(4, 3, 6, 1);
    g.addEdge(3, 2, 2, 1);
    int n = 7; // number of nodes
    g.printAdjList(n);
    int src = 0; // source node
    int dest = 2; // destination node
    g.shortestPathDFS(src, dest);
    return 0;
}