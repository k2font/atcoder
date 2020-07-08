#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)

int main(){
    int N, M; cin >> N >> M;
    vector<int> a(M), b(M); rep(i, M) cin >> a[i] >> b[i];

    map<int, int> res; rep(i, N) res[i] = 0;
    rep(i, M) {
        res[a[i] - 1]++;
        res[b[i] - 1]++;
    }

    rep(i, N) {
        cout << res[i] << endl;
    }
}