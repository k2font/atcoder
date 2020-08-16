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
struct edge {
  ll to, cost;
};

// 実験を繰り返して成立するパターンを見つける
// まずは何らかの偶奇で考える。
int main() {
  int N, K; cin >> N >> K;
  ll ans = 0;
  if(K % 2 == 1) {
    ans += N / K;
    cout << (ll)pow(ans, 3) << endl;
  } else {
    ll tmp = (N + (N % K)) / K;
    ans += (ll)pow(tmp, 3);
    ans += (ll)pow(N / K, 3);
    cout << ans << endl;
  }
}