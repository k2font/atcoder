#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
    return string(1, val);
}

int main(){
    int N, K; cin >> N >> K;
    vector<int> l(N); REP(i, N) cin >> l[i];

    sort(all(l), greater<int>());

    int cnt = 0;
    for(int i = 0; i < K; ++i) {
        cnt += l[i];
    }

    cout << cnt << endl;
}