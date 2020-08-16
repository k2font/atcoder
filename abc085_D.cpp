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
  ll H; cin >> H;
  vector<ll> a(N), b(N); REP(i, N) cin >> a[i] >> b[i];
  ll ans = 0; sort(all(b)); ll max_n = *max_element(all(a));
  for(int i = N - 1; i >= 0; --i) {
    if(b[i] < max_n) break;
    H -= b[i]; ans++;
    if(H <= 0) {
      cout << ans << endl;
      return 0;
    }
  }
  ll p = 0;
  if(H % max_n == 0) p = H / max_n;
  else p = (H / max_n) + 1;
  ans += p;
  cout << ans << endl;
}