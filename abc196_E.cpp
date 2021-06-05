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
  ll N; cin >> N;
  vector<ll> a(N), t(N); REP(i, N) cin >> a[i] >> t[i];
  ll Q; cin >> Q;
  vector<ll> x(Q); REP(i, Q) cin >> x[i];
  ll low = -1e18; ll high = 1e18; ll add = 0;
  REP(i, N) {
    if(t[i] == 1) {
      low += a[i]; high += a[i]; // t==1の操作はグラフを上に押し上げる操作。
      add += a[i]; // t==1の操作はいつ行ってもいいので、とりあえずaddに貯めておく
    } else if(t[i] == 2) {
      chmax(low, a[i]); chmax(high, a[i]);
    } else {
      chmin(low, a[i]); chmin(high, a[i]);
    }
  }

  REP(i, Q) {
    cout << clamp(x[i] + add, low, high) << endl;
  }
}