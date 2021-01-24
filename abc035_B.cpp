#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using P = pair<ll, ll>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};
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

struct edge {
  ll to, cost;
};

int main() {
  string S; cin >> S;
  int T; cin >> T;
  ll ans = 0; map<char, int> m; ll tmp = 0;
  REP(i, S.size()) m[S[i]]++;
  REP(i, S.size()) {
    if(S[i] == '?') tmp++;
  }
  int x = abs(m['L'] - m['R']);
  int y = abs(m['U'] - m['D']);
  if(T == 1) ans = x + y + tmp;
  else {
    if(x + y >= tmp) ans = x + y - tmp;
    else {
      int f = x + y - tmp;
      if(f % 2 == 0) ans = 0;
      else ans = 1;
    }
  }
  cout << ans << endl;
}