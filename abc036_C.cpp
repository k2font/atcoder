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
  vector<ll> a(N); REP(i, N) cin >> a[i];
  // 座標圧縮用配列
  vector<pair<ll, ll>> alt;
  REP(i, N) alt.push_back(make_pair(a[i], i));
  sort(all(alt));
  vector<ll> b(N); REP(i, N) b[i] = alt[i].first;
  b.erase(unique(all(b)), b.end());
  vector<ll> ans(N);
  REP(i, N) {
    ans[alt[i].second] = lower_bound(all(b), alt[i].first) - b.begin();
  }
  REP(i, N) {
    cout << ans[i] << endl;
  }
}
