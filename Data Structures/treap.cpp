#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define sz(x) int(x.size())
using namespace std;
const int maxn = 200100;

class Treap {
public:
	ll data, priority;
	vector<Treap* >child;

	ll subtreesize, subtreesum, lazy;

	Treap (int data);
};

ll n, q, arr[maxn];

ll get_random() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	ll x = uniform_int_distribution<int>(0, n)(rng);
	return x;
}

void recalculate(Treap *curr) {
	if(curr == NULL) return;

	curr->subtreesize = 1;
	curr->subtreesum = curr->data + curr->lazy;
	for(Treap* i:curr->child) {
		if(i == NULL) continue;

		curr->subtreesize += i->subtreesize;
		curr->subtreesum += i->subtreesum + i->subtreesize * i->lazy;
	}
}

Treap::Treap (int data) {
	this->data = data;
	child = {NULL, NULL};
	this->priority = get_random();
	recalculate(this);
}

int getSubtreeSize(Treap *curr) {
	if(curr == NULL) return 0;
	else return curr->subtreesize;
}

void propagate(Treap *curr) {
	if(curr == NULL) return;
	if(curr->lazy == 0) return;

	curr->data += curr->lazy;

	for(Treap* i:curr->child) {
		if(i == NULL) continue;

		i->lazy += curr->lazy;
	}

	curr->lazy = 0;
	recalculate(curr);
}


vector<Treap*> split(Treap *curr, int left_size) {
	if(curr == NULL) return {NULL, NULL};

	propagate(curr);

	if(getSubtreeSize(curr->child[0]) >= left_size) {
		vector<Treap* >leftquery = split(curr->child[0], left_size);
		curr->child[0] = leftquery[1];

		recalculate(curr);
	//	recalculate(leftquery[0]);
		return {leftquery[0], curr};
	}
	else {
		int nw_size = -getSubtreeSize(curr->child[0]) + left_size - 1;
		vector<Treap* >rightquery = split(curr->child[1], nw_size);
		curr->child[1] = rightquery[0];

		recalculate(curr);
	//	recalculate(rightquery[1]);
		return {curr, rightquery[1]};
	}
}

Treap* merge(Treap *left, Treap *right) {
	if(left == NULL) return right;
	if(right == NULL) return left;

	propagate(left);
	propagate(right);

	if(left->priority < right->priority) {
		left->child[1] = merge(left->child[1], right);
		recalculate(left);
		return left;
	}
	else {
		right->child[0] = merge(left, right->child[0]);
		recalculate(right);
		return right;
	}
}

Treap *root;

ll query(int ql, int qr) {
	vector<Treap*> a = split(root, ql - 1);
	vector<Treap*> b = split(a[1], qr - ql + 1);

	//cout<<a[0]->subtreesum<<" "<<a[1]->subtreesum<<"\n";

	ll result = b[0]->subtreesum;
	root = merge(a[0], merge(b[0], b[1]));
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	/*for(int i=1;i<=10;i++) {
		cout<<get_random()<<"\n";;
	}*/

	cin>>n>>q;

	for(int i=1;i<=n;i++) {
		cin>>arr[i];
	}

	root = new Treap(arr[1]);

	for(int i=2;i<=n;i++) {
		Treap *temp = new Treap(arr[i]);

		//cout<<i<<": "<<temp->data<<" ";

		root = merge(root, temp);

		//cout<<root->subtreesum<<"\n";
	}

		
	ll a, b;
	while(q--) {
		cin>>a>>b;
		cout<<query(a, b)<<"\n";
	}

}