// Checked on problem ADAINDEX from SPOJ
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn = 100100;

string curr;

class node {
public:
	node *child[26];
	int cnt;

	node() {
		cnt = 0;
		for(int i=0;i<26;i++) child[i] = NULL;
	}
	void insert_word(int ind) {
		cnt++;
		if(ind == curr.length()) return;

		int letter = curr[ind] - 'a';
		if(child[letter] == NULL) child[letter] = new node();
		child[letter]->insert_word(ind+1);
	}
	ll prefix_cnt(int ind) {
		if(ind == curr.length()) return cnt;

		int letter = curr[ind] - 'a';
		if(child[letter] == NULL) return 0;
		return child[letter]->prefix_cnt(ind+1);
	}
};

int main(){
	node *root = new node();
}
