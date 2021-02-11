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
int vector_finder(std::vector<ll> vec, int number) {
  auto itr = std::find(vec.begin(), vec.end(), number);
  size_t index = std::distance( vec.begin(), itr );
  if (index != vec.size()) { // 発見できたとき
    return 1;
  }
  else { // 発見できなかったとき
    return 0;
  }
}

int main() {
  int N, M, Q; cin >> N >> M >> Q;
  vector<int> L(M), R(M); REP(i, M) cin >> L[i] >> R[i];
  vector<int> p(Q), q(Q); REP(i, Q) cin >> p[i] >> q[i];
  vector<vector<ll>> res(N + 1, vector<ll>(N + 1, 0));
  REP(i, M) {
    res[L[i]][R[i]]++;
  }
  // 二次元累積和
  REP(i, N + 1) {
    if(i == 0) continue;
    REP(k, N + 1) {
      if(k == 0) continue;
      res[i][k] += res[i - 1][k] + res[i][k - 1] - res[i - 1][k - 1];
    }
  }
  ll ans = 0;
  REP(i, Q) {
    ans = 0;
    ans += (res[q[i]][q[i]] - res[q[i]][p[i] - 1] - res[p[i] - 1][q[i]] + res[p[i] - 1][p[i] - 1]);
    cout << ans << endl;
  }
}