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
  int N, M; cin >> N >> M;
  vector<ll> a(M); REP(i, M) cin >> a[i];
  vector<ll> m(N + 1); REP(i, N + 1) m[i] = 0;
  vector<ll> ans;
  for(ll i = M - 1; i >= 0; --i) {
    if(m[a[i]] != 1) ans.push_back(a[i]);
    m[a[i]] = 1;
  }
  REP(i, N + 1) {
    if(i == 0) continue;
    if(m[i] == 0) ans.push_back(i);
  }
  REP(i, N + 1) {
    if(ans[i] == 0) continue;
    cout << ans[i] << endl;
  }
}