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
  int N, M, Q; cin >> N >> M >> Q;
  vector<int> L(M), R(M); REP(i, M) cin >> L[i] >> R[i];
  vector<int> p(Q), q(Q); REP(i, Q) cin >> p[i] >> q[i];
  vector<int> res(N + 1, 0);
  REP(i, M) {
    res[L[i] - 1]++; res[R[i]]--;
  }
  REP(i, N) res[i + 1] += res[i];
  for(int i = 0; i < N + 1; ++i) {
    cout << res[i] << endl;
  }
}