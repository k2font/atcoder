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
  int N, Q; cin >> N >> Q;
  vector<ll> L(Q), R(Q), T(Q);
  REP(i, Q) cin >> L[i] >> R[i] >> T[i];
  vector<int> a(N); REP(i, N) a[i] = 0;
  REP(i, Q) {
    for(int k = L[i] - 1; k < R[i]; ++k) {
      a[k] = T[i];
    }
  }
  REP(i, N) cout << a[i] << endl;
}
