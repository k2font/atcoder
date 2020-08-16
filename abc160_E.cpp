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
  ll X, Y, A, B, C; cin >> X >> Y >> A >> B >> C;
  vector<ll> p(A); REP(i, A) cin >> p[i];
  vector<ll> q(B); REP(i, B) cin >> q[i];
  vector<ll> r(C); REP(i, C) cin >> r[i];
  ll ans = 0;
  sort(all(p), greater<ll>());
  sort(all(q), greater<ll>());
  sort(all(r), greater<ll>());
  vector<ll> tmp;
  REP(i, X) tmp.push_back(p[i]);
  REP(i, Y) tmp.push_back(q[i]);
  REP(i, C) tmp.push_back(r[i]);
  sort(all(tmp), greater<int>());
  for(int i = 0; i < (X + Y); ++i) {
    ans += tmp[i];
  }
  cout << ans << endl;
}