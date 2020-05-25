#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define sz(x) int(x.size())
using namespace std;
const int maxn = 100100;
ll n, m;

struct dijkstra {
public:
	vector<pair<ll, ll> >g[maxn];
	int n;

	ll dist[maxn], parent[maxn];
	bool visited[maxn];

	void init(int _n) {
		n = _n;

		for(int i=0;i<n;i++) {
			dist[i] = LLONG_MAX;
			parent[i] = -1;
			visited[i] = false;
		}
	}
	void add_edge(ll i, ll j, ll cost) {
		g[i].pb(mp(j, cost));
		g[j].pb(mp(i, cost));
	}
	void calculate(int _start) {
		priority_queue<pair<ll, ll>, vector<pair<ll,ll> >, greater<pair<ll,ll> > > pq;
		pq.push(mp(0, _start));
		dist[_start] = 0;

		while(!pq.empty()) {
			ll node = pq.top().second;
			pq.pop();

			if(visited[node]) {
				continue;
			}
			
			visited[node] = true;

			for(auto i:g[node]) {
				if(!visited[i.first] && dist[i.first] > i.second + dist[node]) {
					parent[i.first] = node;
					dist[i.first] = i.second + dist[node];
					pq.push(mp(dist[i.first], i.first));
				}
			}
		}

	}
}g;

int main() {

}