#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define sz(x) int(x.size())
using namespace std;
const ll maxn = 100100;
const ll mod = 1e9 + 7;

ll fact[maxn], invfact[maxn];

ll power(ll a, ll b) {
	if(b == 0) return 1LL;
	else if(b == 1) return a % mod;
	else {
		if(b%2 == 0) {
			ll half = power(a, b/2);
			return (half*half)%mod;
		}
		else {
			return a*power(a, b-1)%mod;
		}
	}
}

ll ncr(ll n, ll k) {
	ll result = (fact[n] * invfact[k]) % mod;
	result *= invfact[n-k]; result %= mod;
	return result;
}

void preprocess() {
	fact[0] = invfact[0] = 1LL;
	for(ll i=1LL;i<maxn;i++) {
		fact[i] = (i * fact[i-1]) % mod;
		invfact[i] = power(fact[i], mod-2);
	}
}

int main() {
	
}