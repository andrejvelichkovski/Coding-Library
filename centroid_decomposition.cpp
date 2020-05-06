#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define sz(x) int(x.size())
using namespace std;
const int maxn = 200100;
int n;
 
vector<int>g[maxn];

bool deleted[maxn];
int sbt_sz[maxn];
int par[maxn];
int tpar[maxn];
 
int result;
 
vector<int>curr_nodes;
 
void get_sizes(int node, int p) {
	sbt_sz[node] = 1;
	tpar[node] = p;
 
	for(int i:g[node]) {
		if(deleted[i] || i == p) continue;
 
		get_sizes(i, node);
		sbt_sz[node] += sbt_sz[i];
	}
}
 
void get_parents(int node, int p) {
	par[node] = p;
	for(int i:g[node]) {
		if(deleted[i] || i == p) continue;
		get_parents(i, node);
	}
}
 
int get_centroid(int node) {
	int min_sbtsize = INT_MAX;
	int centroid = -1;
 
	queue<int>q;
	q.push(node);
 
	while(!q.empty()) {
		int curr = q.front();
		q.pop();
 
		int max_sbtsize = 0;
		for(int i:g[curr]) {
			if(deleted[i]) continue;
 
			if(i == tpar[curr]) {
				max_sbtsize = max(max_sbtsize, sbt_sz[node] - sbt_sz[curr]);
				continue;
			}
 
			max_sbtsize = max(max_sbtsize, sbt_sz[i]);
			q.push(i);
		}
 
		if(max_sbtsize < min_sbtsize) {
			min_sbtsize = max_sbtsize;
			centroid = curr;
		}
	}
 
	return centroid;
}
 
void solve(int root) {
	get_sizes(root, -1); // Preprocess and find the subtree sizes of each node
	root = get_centroid(root); // Find the centroid in this tree
	get_parents(root, root); // Rerooting the tree at the centroid

	// Main part here
 
	deleted[root] = true;
	for(int i:g[root]) {
		if(!deleted[i]) {
			solve(i);
		}
	}
}
 
int main() {
	cin>>n;
 
	int a, b;
	for(int i=0;i<n-1;i++) {
		cin>>a>>b;
		g[a].pb(b);
		g[b].pb(a);
	}
 
	solve(1);
}