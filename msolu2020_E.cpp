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
  int N; cin >> N;
  vector<int> X(N), Y(N), P(N); REP(i, N) cin >> X[i] >> Y[i] >> P[i];
  ll ans = 0;
  REP(i, N) {
    ans += min(abs(X[i]), abs(Y[i])) * P[i];
  }
  cout << ans << endl; // 0の場合
  for(int i = 1; i <= N; ++i) {
    // bit全探索
    ll res = pow(10, 12); // 最小値候補
    for(int bit = 0; bit < (1 << N); ++bit) {
      if(__builtin_popcount(bit) != i) continue;
      ll tmp_x = 0; ll tmp_y = 0;
      for(int i = 0; i < N; ++i) {
        if(bit & (1 << i)) {
          int t = X[i];
          REP(k, N) {
            // x = X[i]としたとき
            tmp_x += min(abs(t - X[k]), min(abs(X[k]), abs(Y[k]))) * P[k];
          }

          REP(k, N) {
            // y = Y[i]としたとき
            tmp_y += min(abs(t - X[k]), min(abs(X[k]), abs(Y[k]))) * P[k];
          }
        }
      }
      if(res > min(tmp_x, tmp_y)) res = min(tmp_x, tmp_y);
      tmp_x = 0; tmp_y = 0;
    }
    cout << res << endl;
  }
}