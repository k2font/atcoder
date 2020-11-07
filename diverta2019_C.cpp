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
  vector<string> s(N); REP(i, N) cin >> s[i];
  ll ans = 0;
  REP(i, N) {
    REP(k, s[i].size() - 1) {
      if(s[i][k] == 'A' && s[i][k + 1] == 'B') ans++;
    }
  }
  ll BA = 0; ll A = 0; ll B = 0;
  REP(i, N) {
    if(s[i][0] == 'B' && s[i][s[i].size() - 1] == 'A') BA++;
    else if(s[i][0] == 'B') B++;
    else if(s[i][s[i].size() - 1] == 'A') A++;
  }
  if(BA > 0) {
    ans += (BA - 1);
    if(A > 0 && B > 0) ans += 2;
    else if(A + B > 0) ans++;
    ans += min(max(A - 1, (ll)0), max(B - 1, (ll)0));
  } else if(BA == 0) ans += min(A, B);
  cout << ans << endl;
}