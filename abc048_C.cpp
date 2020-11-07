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
  ll N, x; cin >> N >> x;
  vector<ll> a(N); REP(i, N) cin >> a[i];
  ll ans = 0;
  if(a[0] > x) {
    ll tmp = (a[0] - x);
    a[0] = x;
    ans += tmp;
  }
  for(int i = 0; i < N - 1; ++i) {
    ll tmp = a[i] + a[i + 1];
    if(tmp > x) {
      a[i + 1] -= (tmp - x);
      ans += (tmp - x);
    }
  }
  cout << ans << endl;
}