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
  ll N, M; cin >> N >> M;
  vector<ll> a(N); REP(i, N) cin >> a[i];
  ll ans = 0;
  vector<ll> ruis(N + 1); REP(i, N + 1) ruis[i] = 0;
  REP(i, N + 1) {
    if(i == 0) {
      ruis[0] = 0;
      continue;
    }
    ruis[i] = ruis[i - 1] + a[i - 1];
  }
  for(int i = 0; i <= N; ++i) {
    for(int k = i + 1; k <= N; ++k) {
      ll tmp = ruis[k] - ruis[i];
      ll tmp2 = tmp % M;
      if(ans < tmp2) ans = tmp2;
    }
  }
  cout << ans << endl;
}
