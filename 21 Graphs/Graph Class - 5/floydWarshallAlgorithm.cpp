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
    void shortestPathUsingFloydWarshall(int src, int n, int dest){
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX)); // distance matrix
        for(int i = 0; i < n; i++) dist[i][i] = 0; // distance from node to itself is 0
        for(auto a : adjList){
            int u = a.first;
            for(auto b : a.second){
                int v = b.first;
                int wt = b.second;
                dist[u][v] = wt; // distance from u to v is wt
            }
        }
        for(int helper = 0; helper < n; helper++){
            for(int src = 0; src < n; src++){
                for(int dest = 0; dest < n; dest++){
                    if(dist[src][helper] != INT_MAX && dist[helper][dest] != INT_MAX){
                        dist[src][dest] = min(dist[src][dest], dist[src][helper] + dist[helper][dest]);
                    }
                }
            }
        }
        cout << "Distance matrix:" << endl;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(dist[i][j] == INT_MAX) cout << "INF ";
                else cout << dist[i][j] << " ";
            }
            cout << endl;
        }
        cout << "Shortest path from " << src << " to " << dest << " is: " << dist[src][dest] << endl;
    }
};

int main(){
    Graph g;
    g.addEdge(0, 2, -2, 1);
    g.addEdge(1, 0, 4, 1);
    g.addEdge(1, 2, 3, 1);
    g.addEdge(3, 1, -1, 1);
    g.addEdge(2, 3, 2, 1);
    int n = 4; // number of nodes
    g.printAdjList(n);
    int src = 0; // source node
    int dest = 2; // destination node
    g.shortestPathUsingFloydWarshall(src, n, dest);
    return 0;
}