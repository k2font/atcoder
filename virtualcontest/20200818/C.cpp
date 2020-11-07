#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using P = pair<ll, ll>;
string char_to_string(char val) {
  return string(1, val);
}
int char_to_int(char val) {
  return val - '0';
}
template<class T> inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template<class T> inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
struct edge {
  ll to, cost;
};

int main() {
  ll N; cin >> N;
  vector<ll> A(N + 1); REP(i, N + 1) cin >> A[i];
  // vector<ll> maxnvec(N + 1, 0);
  if (N == 0) {
        if (A[0] == 1) {
          cout << 1 << endl;
          return 0;
        }
        else {
          cout << -1 << endl;
          return 0;
        }
    }

    if (A[0] != 0) {
      cout << -1 << endl;
      return 0;
    }

    ll tot = 0;
    REP(i, N + 1) tot += A[i];

    ll cur = 1;
    ll ans = 1;
    REP(i, N + 1) {
      if(i == 0) continue;
        cur *= 2;

        if (cur < A[i]) {
          cout << -1 << endl;
          return 0;
        }

        ans += min(cur, tot);
        cur = min(cur, tot) - A[i];
        tot -= A[i];
    }
  cout << ans << endl;
}