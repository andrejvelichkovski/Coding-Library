#include <bits/stdc++.h>
using namespace std;
const int maxn = 100100;

class graph {
    // adjacent list containing all the adjacent nodes for each node
    vector<vector<int> > adj; 
    vector<int> dist; // distance from the source to each node        
    vector<bool> visited; // saves whether each node has been visited yet or not
public:
    int N; // # of nodes in the graph

    // Initializes empty graph with N nodes
    graph(int _N) {
        N = _N;

        dist.resize(N, -1);
        visited.resize(N, false);

        for(int i=0;i<N;i++) {
            vector<int>x;
            adj.push_back(x);
        }
    }

    // Addes new edge to the graph
    void add_edge(int a, int b) {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Calculates the distances to each reachable node starting from source
    // Takes vector as input, if you want to enable just a single source use {x}, where x is the node
    void calculate_distances(vector<int>sources) {
        queue<int>q;

        for(int i:sources) {
            q.push(i);
            dist[i] = 0;
            visited[i] = true;
        }

        while(!q.empty()) {
            int curr = q.front();
            q.pop();

            for(int i:adj[curr]) {
                if(!visited[i]) {
                    visited[i] = true;
                    dist[i] = dist[curr] + 1;
                    q.push(i);
                }
            }
        }
    }

    // Getters below

    // Returns the distance from source to node
    int get_dist_node(int node) {
        return dist[node];
    }
    // Returns the visited status for each node
    bool check_visited_node(int node) {
        return visited[node];
    }
    // Returns vector with all the distances for each node
    vector<int> get_distances() {
        return dist;
    }
    // Returns vector with the visited status for each node
    vector<bool> get_visited_status() {
        return visited;
    }

    // Additional functions below

    // Resets arrays to make easier for future calculations with new sources
    void reset_graph() {
        for(int i=0;i<N;i++) {
            dist[i] = -1;
            visited[i] = false;
        }
    }
};

int main() {

}