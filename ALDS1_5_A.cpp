#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using P = pair<int, int>;
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
  int n; cin >> n;
  vector<int> A(n); REP(i, n) cin >> A[i];
  int q; cin >> q;
  vector<int> m(q); REP(i, q) cin >> m[i];
  vector<string> a(q, "no");
  for(int bit = 0; bit < (1 << n); ++bit) {
    int sum = 0;
    for(int i = 0; i < n; ++i) {
      if(bit & (1 << i)) {
        sum += A[i];
      }
    }
    REP(i, q) {
      if(m[i] == sum) a[i] = "yes";
    }
  }
  REP(i, a.size()) {
    cout << a[i] << endl;
  }
}