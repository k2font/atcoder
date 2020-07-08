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
  int N; cin >> N;
  vector<string> S(N); REP(i, N) cin >> S[i];
  ll ans = 0;
  ll f_ab = 0, l_ab = 0;
  REP(i, N) {
    if(S[i][0] == 'B') f_ab++;
    if(S[i][S[i].size() - 1] == 'A') l_ab++;
    for(int k = 0; k < S[i].size() - 1; ++k) {
      if(S[i][k] == 'A' && S[i][k + 1] == 'B') ans++;
    }
  }
  if(f_ab == l_ab) ans = ans + f_ab - 1;
  else ans += min(f_ab, l_ab);
  cout << ans << endl;
}