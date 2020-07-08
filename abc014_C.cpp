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
  int n; cin >> n;
  vector<int> a(n), b(n); REP(i, n) cin >> a[i] >> b[i];
  vector<int> ans(1000010, 0);
  REP(i, n) {
    ans[a[i]]++; ans[b[i] + 1]--;
  }
  REP(i, 1000001) ans[i + 1] += ans[i];
  int res = 0;
  REP(i, 1000001) {
    if(res < ans[i]) res = ans[i];
  } 
  cout << res << endl;
}