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
  int H, W; cin >> H >> W;
  vector<string> S(H); REP(i, H) cin >> S[i];
  ll ans = 0;
  REP(i, H) {
    REP(k, W - 1) {
      if(S[i][k] == '.' && S[i][k + 1] == '.') ans++;
    }
  }
  REP(i, W) {
    REP(k, H - 1) {
      if(S[k][i] == '.' && S[k + 1][i] == '.') ans++;
    }
  }
  cout << ans << endl;
}