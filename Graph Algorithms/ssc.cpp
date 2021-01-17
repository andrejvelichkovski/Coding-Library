/* Implementation of the Strongly Connected Components algorithm in C++
Consider reading some tutorial on the internet if it is unclear what the algorithm does */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 100100;

class graph {
    // adjacent list containing all the adjacent nodes for each node
    vector<vector<int> > adj, reverse_adj; 
    vector<bool> visited; // saves whether each node has been visited yet or not

    vector<vector<int> > components; // saves each strongly connect component in a vector

    vector<bool> order; // used for the SSC algorithm
    vector<int> emptyVector;
public:
    int N; // # of nodes in the graph
    int componentCount;

    // Initializes empty graph with N nodes
    graph(int _N) {
        N = _N;

        visited.resize(N, false);
        componentCount = 0;

        for(int i=0;i<N;i++) {
            vector<int>x;
            adj.push_back(x);
            reverse_adj.push_back(x);
        }
    }

    // Addes new edge to the graph
    void add_edge(int a, int b) {
        adj[a].push_back(b);
        reverse_adj[b].push_back(a);
    }

    // performs the first dfs pass for the algorithm
    void first_dfs(int node) {
        for(int i:adj[node]) {
            if(!visited[i]) {
                first_dfs(i);
            }
        }
        order.push_back(node);
    }

    void second_dfs(int node) {
        components.back().push_back(node);
        for(int i:reverse_adj[node]) {
            if(!visited[i]) {
                second_dfs(i);
            }
        }
    }

    // Calculates all the strongly connected components in a graph
    // Stores them as vector of vectors of integers
    void calculate_scc() {
        for(int i=0;i<N;i++) {
            if(!visited[i]) {
                first_dfs(i);
            }
        }

        // necessary step for the algorithm
        reverse(order.begin(), order.end());
        for(int i=0;i<N;i++) {
            visited[i] = false;
        }

        for(int i=0;i<N;i++) {
            if(visited[i]) continue;

            components.push_back(emptyVector);
            second_dfs(i);
        }

        componentCount = int(components.size());
        order.clear();
    }

    // Getters below
    vector<vector<int> > get_all_components() {
        return components;
    }
    
    int get_component_count() {
        return componentCount;
    }
};

int main() {

}