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

int main() {
  int N; cin >> N;
  vector<ll> x(N), y(N), h(N); REP(i, N) cin >> x[i] >> y[i] >> h[i];
  for(ll i = 0; i <= 100; ++i) {
    for(ll k = 0; k <= 100; ++k) {
      ll res = 0;
      REP(m, N) {
        ll tmp = abs(i - x[m]) + abs(k - y[m]) + h[m];
        if(m != 0 && tmp != res) break;
        res = tmp;
        ll t = abs(i - x[m]) + abs(k - y[m]);
        if(h[m] > 0 && res - h[i] != t) break;
        if(h[m] == 0 && res > t) break;
        if(m == N - 1) {
          cout << i << " " << k << " " << res << endl;
          return 0;
        }
      }
    }
  }
}