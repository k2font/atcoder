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
  vector<string> S(n); REP(i, n) cin >> S[i];
  vector<map<char, int>> m(n);
  map<char, int> a;
  for(char i = 'a'; i <= 'z'; ++i) {
    a[i] = 0;
  }
  REP(i, n) {
    REP(k, S[i].size()) {
      m[i][S[i][k]]++;
    }
  }
  REP(i, S[0].size()) {
    a[S[0][i]]++;
  }
  for(char i = 'a'; i <= 'z'; ++i) {
    for(int k = 1; k < n; ++k) {
      a[i] = min(a[i], m[k][i]);
    }
  }
  string ans = "";
  for(auto x : a) {
    for(int i = 0; i < x.second; ++i) {
      ans += x.first;
    }
  }
  cout << ans << endl;
}
