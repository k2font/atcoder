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
      ll res = 0; ll H = 1;
      REP(m, N) {
        if(h[m] > 0) H = abs(i - x[m]) + abs(k - y[m]) + h[m];
      }
      int ok = 1;
      REP(m, N) {
        if(max(H - abs(x[m] - i) - abs(y[m] - k), (ll)0) != h[m]) ok = 0;
      }
      if(ok) {
        cout << i << " " << k << " " << H << endl;
        return 0;
      }
    }
  }
}