#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<climits>
#include<set>
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
    void shortestPathUsingBellmanford(int src, int n, int dest){
        vector<int> dist(n+1, INT_MAX); // distance vector
        dist[src] = 0;
        for(int i = 0; i < n-1; i++){
            // relaxation step
            for(auto a : adjList){
                int u = a.first;
                for(auto b : a.second){
                    int v = b.first;
                    int wt = b.second;
                    if(dist[u] != INT_MAX && dist[u] + wt < dist[v]) dist[v] = dist[u] + wt;
                }
            }
        }
        bool negativeCycle = false;
        for(auto a : adjList){
            int u = a.first;
            for(auto b : a.second){
                int v = b.first;
                int wt = b.second;
                if(dist[u] != INT_MAX && dist[u] + wt < dist[v]){
                    negativeCycle = true;
                    break;
                }
            }
        }
        if(negativeCycle){
            cout << "Negative cycle detected" << endl;
        }
        else{
            cout << "No negative cycle detected" << endl;
        }
        // cout << "Shorest path from 0:"<< endl;
        // for(int i = 0; i < n; i++){
        //     cout << "to " << i << " distance: " << dist[i] << endl;
        // }
        // cout << "Shortest path from " << src << " to " << dest << " is: " << dist[dest] << endl;
    }
};

int main(){
    Graph g;
    // g.addEdge(0, 1, -1, 1);
    // g.addEdge(1, 4, 2, 1);
    // g.addEdge(0, 2, 4, 1);
    // g.addEdge(3, 2, 5, 1);
    // g.addEdge(4, 3, -3, 1);
    // g.addEdge(1, 2, 3, 1);
    // g.addEdge(1, 3, 2, 1);
    // g.addEdge(3, 1, 1, 1);
    // int n = 5; // number of nodes
    // g.printAdjList(n);
    // int src = 0; // source node
    // int dest = 2; // destination node
    // g.shortestPathUsingBellmanford(src, n, dest);

    g.addEdge(0, 1, -1, 1);
    g.addEdge(1, 0, -2, 1);
    int n = 2; // number of nodes
    int src = 0; // source node
    int dest = 1; // destination node
    g.printAdjList(n);
    g.shortestPathUsingBellmanford(0, n, dest);
    return 0;
}