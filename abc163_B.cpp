#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
    return string(1, val);
}
int char_to_int(char val) {
    return val - '0';
}

int main() {
    int N, M; cin >> N >> M;
    vector<int> A(M); REP(i, M) cin >> A[i];

    ll sum_num = accumulate(all(A), 0LL);

    ll ans = N - sum_num;
    if(ans < 0) {
      cout << -1 << endl;
    } else if(ans >= 0) {
      cout << ans << endl;
    }
}