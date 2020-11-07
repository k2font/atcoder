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
  int H, W; cin >> H >> W;
  vector<string> a(H); REP(i, H) cin >> a[i];
  map<char, int> m;
  REP(i, H) {
    REP(k, W) {
      m[a[i][k]]++;
    }
  }
  string ans = "Yes";
  if(H % 2 == 0 && W % 2 == 0) {
    for(auto x : m) {
      if(x.second % 4 != 0) ans = "No";
    }
  } else if(H % 2 == 0) {
    
  } else if(W % 2 == 0) {

  } else {
    
  }
  cout << ans << endl;
}
