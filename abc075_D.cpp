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
  int N, K; cin >> N >> K;
  vector<ll> x(N), y(N); REP(i, N) cin >> x[i] >> y[i];
  ll ans = 9e18;
  for(int i = 0; i < N; ++i) {
    for(int k = i + 1; k < N; ++k) {
      ll tmp = 0;
      for(int n = 0; n < N; ++n) {
        for(int m = n + 1; m < N; ++m) {
          int cnt = 0;
          REP(p, N) {
            if(min(x[i], x[k]) <= x[p] && x[p] <= max(x[i], x[k]) && min(y[n], y[m]) <= y[p] && y[p] <= max(y[n], y[m])) cnt++;
          }
          if(cnt == K) {
            ans = min(ans, (ll)(abs(x[i] - x[k])) * (ll)(abs(y[n] - y[m])));
          }
        }
      }
    }
  }
  cout << ans << endl;
}