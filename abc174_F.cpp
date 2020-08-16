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
  ll N, Q; cin >> N >> Q;
  vector<ll> c(N); REP(i, N) cin >> c[i];
  vector<ll> l(Q), r(Q); REP(i, Q) cin >> l[i] >> r[i];
  vector<ll> shurui(N + 1);
  vector<ll> rui(N + 1, 0);
  REP(i, N) {
    if(shurui[c[i]] == 0) rui[i + 1] = rui[i] + 1;
    else rui[i + 1] = rui[i];
    shurui[c[i]] = 1;
  }
  REP(i, Q) {
    cout << rui[r[i]] - rui[l[i] - 1] << endl;
  }
}