#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define sz(x) int(x.size())
using namespace std;
const int maxn = 200100;
const int maxlog = 20;
vector<int>g[maxn];
int n;

int depth[maxn];
int opent[maxn], sbtsize[maxn], br;
int parent[maxn][maxlog];

void dfs_preprocess(int node, int p, int d) {
	opent[node] = br++;
	sbtsize[node] = 1;
	parent[node][0] = p;
	depth[node] = d;

	for(int i:g[node]) {
		if(i == p) continue;
		dfs_preprocess(i, node, d + 1);
		sbtsize[node] += sbtsize[i];
	}
}

void preprocess() {
	for(int lvl=1;lvl<maxlog;lvl++) {
		for(int i=1;i<=n;i++) {
			if(parent[i][lvl-1] != -1) {
				parent[i][lvl] = parent[parent[i][lvl-1]][lvl-1];
			}
		}
	}
}

int lca(int a, int b) {
	if(depth[a] > depth[b]) swap(a, b);
	if(opent[b] >= opent[a] && opent[b] < opent[a] + sbtsize[a]) return a;

	for(int lvl=maxlog-1;lvl>=0;lvl--) {
		if(parent[a][lvl] == -1) continue;

		int nxt = parent[a][lvl];
		if(!(opent[b] >= opent[nxt] && opent[b] < opent[nxt] + sbtsize[nxt])) {
			a = nxt;
		}
	}
	return parent[a][0];
}

int d(int a, int b) {
	return depth[a] + depth[b] - 2*depth[lca(a, b)];
}

int main() {

}