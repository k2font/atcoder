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

int main() {
  int n; cin >> n;
  vector<int> p(n); REP(i, n) cin >> p[i];

  int cnt = 0;
  REP(i, n - 1) {
    if(i == 0) continue;
    if((p[i - 1] < p[i] && p[i] < p[i + 1]) ||
      (p[i - 1] > p[i] && p[i] > p[i + 1])) cnt++;
  }
  cout << cnt << endl;
}