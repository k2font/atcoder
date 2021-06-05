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
  // 座標圧縮解
  int W, N; cin >> W >> N;
  vector<int> L(N), R(N); REP(i, N) cin >> L[i] >> R[i];

  vector<int> alt;
  REP(i, N) {
    alt.push_back(L[i]); alt.push_back(R[i]);
  }
  sort(all(alt));
  alt.erase(unique(all(alt)), alt.end());

  vector<int> v(alt.size() + 10);
  REP(i, N) {
    int l = lower_bound(all(alt), L[i]) - alt.begin();
    int r = lower_bound(all(alt), R[i]) - alt.begin();
    int ans = 0;
    for(int k = l; k <= r; ++k) {
      ans = max(ans, v[k]);
    }
    cout << ans + 1 << endl;;
    for(int k = l; k <= r; ++k) {
      v[k] = ans + 1;
    }
  }
}