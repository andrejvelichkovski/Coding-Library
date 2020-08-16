// Persistent sum segment tree, tested on SPOJ: MKTHNUM
// Current query type: query more properties on some range
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn = 100100;
int n, q;
int arr[maxn];

struct node {
public:
	node *left, *right;
	int val;

	node (int _val) : left(NULL), right(NULL), val(_val) {}
	node (node *l, node*r) : left(l), right(r), val(0) {
		if(l) val += l->val;
		if(r) val += r->val;
	}
};	

node* build(int li=0, int ri=n-1) {
	if(li == ri) return new node(0);
	else {
		int mid = (li + ri) / 2;
		return new node(build(li,mid), build(mid+1,ri));
	}
}

node* update(node *u, int uind, int uval, int li=0, int ri=n-1) {
	if(li == ri) return new node(u->val+uval);
	else {
		int mid = (li + ri) / 2;

		if(uind <= mid) return new node(update(u->left, uind,uval,li, mid),u->right);
		else return new node(u->left, update(u->right, uind,uval,mid+1, ri));
	}
}

int query(node *l, node*r, int k, int li=0, int ri=n-1) {
	if(li == ri) return li;
	else {
		int mid = (li + ri) / 2;
		int lft_sum = r->left->val - l->left->val;

		if(lft_sum >= k) return query(l->left, r->left, k, li, mid);
		else return query(l->right, r->right, k-lft_sum, mid+1, ri);
	}
}

node *pref[maxn];


int main() {
	pref[0] = build();
	for(int i=1;i<=n;i++) {
		pref[i] = update(pref[i-1], arr[i], 1);
	} 
}