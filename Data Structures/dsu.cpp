#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define sz(x) int(x.size())
using namespace std;
const int maxn = 100100;

class dsu {
public:
    int uparent[maxn];
    int usize[maxn];

    void init(int _n) {
        for(int i=0;i<=_n;i++) {
            uroot[i] = i;
            usize[i] = 1;
        }
    }
    int ufind(int x) {
        while(x != uparent[x]) {
            x = uparent[x];
        }
        return x;
    }
    void unite(int x, int y) {
        x = ufind(x);
        y = ufind(y);

        if(x == y) return;

        if(usize[x] > usize[y]) {
            uparent[y] = x;
            usize[x] += usize[y];
        }
        else {
            uparent[x] = y;
            usize[y] += usize[x];
        }
    }
};

int main() {

}