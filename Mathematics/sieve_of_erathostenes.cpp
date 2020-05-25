#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define sz(x) int(x.size())
using namespace std;
const int maxn = 1000100;
vector<bool>prime(maxn, true);
ll spf[maxn];

void generate_sieve() {
	prime[0] = prime[1] = false;
	for(ll i=2LL;i<maxn;i++) {
		if(prime[i]) {
			for(ll j=i*i;j<maxn;j+=i) {
				prime[j] = false;
			}
		}
	}
}

// Function that generates the smallest prime factor of a number
// Can be used to factorize a number in O(logN)
void generate_spf() {
	spf[1] = 1;
	for(ll i=2LL;i<maxn;i++) {
		if(spf[i] == 0) {
			spf[i] = i;
			for(ll j=1LL*i*i;j<maxn;j+=i) {
				if(spf[j] == 0) { 
					spf[j] = i;
				}
			}
		}
	}
}

// Factorizes a number in O(log N) assuming x <= maxn
// Product(result[i].first ^ result[i].second) = x
vector<pair<ll,ll> > factorize_lg(ll x) {
	vector<pair<ll, ll> > result;
	while(x > 1) {
		result.pb(mp(spf[x], 0));

		while(spf[x] == result.back().first) {
			result.back().second++;
			x /= spf[x];
		}
	}
	return result;
}

vector<pair<ll,ll> > factorize_sqrt(ll x) {
	vector<pair<ll, ll> > result;
	for(ll i=2;i*i<=x;i++) {
		if(x % i == 0) {
			result.pb(mp(i, 0));
			while(x % i == 0) {
				result.back().second++;
				x /= i;
			}
		}
	}
	return result;
}


int main() {

}