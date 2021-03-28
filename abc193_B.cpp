#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using P = pair<ll, ll>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};
string char_to_string(char val) {
  return string(1, val);
}
int char_to_int(char val) {
  return val - '0';
}
char inverse_char(char c) {
  if(isupper(c)) return tolower(c);
  else return toupper(c);
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
  int N; cin >> N;
  vector<ll> A(N), P(N), X(N); REP(i, N) cin >> A[i] >> P[i] >> X[i];
  vector<pair<ll, pair<ll, ll>>> p(N);
  REP(i, N) {
    p[i] = make_pair(A[i], make_pair(P[i], X[i]));
  }
  sort(all(p));
  ll ans = 10000000000;
  REP(i, N) {
    if(A[i] < X[i]) {
      chmin(ans, P[i]);
    }
  }
  if(ans != 10000000000) cout << ans << endl;
  else cout << -1 << endl;
}