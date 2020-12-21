// Treap implementation based on the SecondThread lecture
// Tested on problem A from Codeforces Treap Lecture Contest
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
	this->lazy = 0;
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
		return {leftquery[0], curr};
	}
	else {
		int nw_size = -getSubtreeSize(curr->child[0]) + left_size - 1;
		vector<Treap* >rightquery = split(curr->child[1], nw_size);
		curr->child[1] = rightquery[0];

		recalculate(curr);
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

void iterate(Treap *curr) {
	if(curr == NULL) return;

	iterate(curr->child[0]);
	cout<<curr->data<<" ";
	iterate(curr->child[1]);
}

Treap *root;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	root = new Treap(0);

}