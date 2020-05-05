// Segment tree implementation, tested on GSS3 from SPOJ
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define sz(x) int(x.size())
using namespace std;
const int maxn = 100100;
const ll inf = 1e12;
ll n, q, arr[maxn];

class node {
public:
	ll val;
}tree[4*maxn];

node leaf_value(ll val) {
	return {val};
}

node merge_values(node a, node b) {
	return {a.val + b.val};
}

void build(int li=0, int ri=n-1, int index=1) {
	if(li == ri) {
		tree[index] = leaf_value(arr[li]);
	}
	else {
		int mid = (li + ri) / 2;

		build(li, mid, 2*index);
		build(mid+1, ri, 2*index+1);

		tree[index] = merge_values(tree[2*index], tree[2*index+1]);
	}
}

void update(int uind, ll uval, int li=0, int ri=n-1, int index=1) {
	if(li == ri) {
		tree[index] = leaf_value(uval);
	}
	else {
		int mid = (li + ri) / 2;

		if(uind <= mid) update(uind, uval, li, mid, 2*index);
		else update(uind, uval, mid+1, ri, 2*index+1);

		tree[index] = merge_values(tree[2*index], tree[2*index+1]);
	}
}

node empty_node;
node query(int ql, int qr, int li=0, int ri=n-1, int index=1) {
	if(li > qr || ri < ql) return empty_node;
	else if(li >= ql && ri <= qr) return tree[index];
	else {
		int mid = (li + ri) / 2;

		return merge_values(query(ql, qr, li, mid, 2*index), query(ql, qr, mid+1, ri, 2*index+1));
	}
}
 

int main() {
	empty_node = {0};
}