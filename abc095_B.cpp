#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
    return string(1, val);
}

int main(){
    int N, X; cin >> N >> X;
    vector<int> m(N); REP(i, N) cin >> m[i];

    sort(all(m));
    for(int i = 0; i < N; ++i) {
        if(i == 0) continue;
        X -= m[i];
    }

    int res = X / m[0];

    cout << res + (N - 1) << endl;
}