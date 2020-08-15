#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn = 4100;
const int maxk = 810;
ll dp[maxk][maxn];

void solve(int l, int r, int optl, int optr, int d) {
	if(l > r) return;

	int mid = (l + r) / 2;

	int optind = optl;
	// initialize dp[mid]
	for(int i=optl+1;i<=min(mid, optr);i++) {
		// update dp[mid] if needed
		if() {
			
			optind = i; 
		}
	}

	// recursively call for left and right parts
	if(l != r) {
		solve(l, mid-1, optl, optind, d);
		solve(mid+1, r, optind, optr, d);
	}
}

int main() {
		
}