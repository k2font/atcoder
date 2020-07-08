#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
    return string(1, val);
}

int main(){
    int N; cin >> N;
    vector<int> L(N); REP(i, N) cin >> L[i];

    sort(all(L));
    ll res = 0;

    for(int i = 0; i < N; ++i) {
        for(int j = i + 1; j < N; ++j) {
            // lower_boundから配列の先頭のイテレータを引くと、ある要素以下の個数を算出できる。
            int k = lower_bound(L.begin(), L.end(), L[i] + L[j]) - L.begin();

            res += max(k - (j + 1), 0);
        }
    }

    cout << res << endl;
}