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
    void shortestPathUsingDijkstra(int src, int n, int dest){
        vector<int> dist(n+1, INT_MAX); // distance vector
        set<pair<int, int>> st; // set to store {distance, node}
        dist[src] = 0;
        st.insert({0, src});
        while(!st.empty()){
            auto topElement = *(st.begin()); // get the node with minimum distance
            int topNodeDistance = topElement.first;
            int topNode = topElement.second;
            st.erase(st.begin());

            for(auto nbr : adjList[topNode]){ // iterate through the neighbours of the node
                int nbrNode = nbr.first;
                int nbeDistance = nbr.second;
                if(topNodeDistance + nbeDistance < dist[nbrNode]){
                    auto result = st.find({dist[nbrNode], nbrNode});
                    if(result != st.end()){
                        st.erase(result);
                    }
                    dist[nbrNode] = topNodeDistance + nbeDistance;
                    st.insert({dist[nbrNode], nbrNode});
                }
            }
        }
        cout << "Shorest path from 0:"<< endl;
        for(int i = 0; i < n; i++){
            cout << "to " << i << " distance: " << dist[i] << endl;
        }
        cout << "Shortest path from " << src << " to " << dest << " is: " << dist[dest] << endl;
    }
};

int main(){
    Graph g;
    g.addEdge(0, 5, 9, 0);
    g.addEdge(0, 3, 6, 0);
    g.addEdge(5, 4, 2, 0);
    g.addEdge(4, 3, 11, 0);
    g.addEdge(5, 1, 14, 0);
    g.addEdge(4, 1, 9, 0);
    g.addEdge(4, 2, 10, 0);
    g.addEdge(3, 2, 15, 0);
    g.addEdge(2, 1, 7, 0);
    int n = 6; // number of nodes
    g.printAdjList(n);
    int src = 0; // source node
    int dest = 2; // destination node
    g.shortestPathUsingDijkstra(src, n, dest);
    return 0;
}