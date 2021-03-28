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
  ll N, K; cin >> N >> K;
  vector<ll> p(N); REP(i, N) cin >> p[i];
  vector<ll> rui(N + 1, 0);
  REP(i, N) p[i]++;
  REP(i, N) rui[i + 1] = rui[i] + p[i];
  ll tmp = 0;
  for(int i = 0; i + K <= N; ++i) {
    tmp = max(tmp, rui[i + K] - rui[i]);
  }
  double ans = (double)tmp / (double)2.0;
  cout << fixed << setprecision(10) << ans << endl;
}
