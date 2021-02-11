#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using P = pair<ll, ll>;
const int dx[4] = {1, 1, -1, -1};
const int dy[4] = {1, -1, -1, 1};
string char_to_string(char val) {
  return string(1, val);
}
int char_to_int(char val) {
  return val - '0';
}
char inverse_char(char c) {
  if(isupper(c)) return tolower(c);
  else return toupper(c);
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
  int H, W; cin >> H >> W;
  vector<string> S(H); REP(i, H) cin >> S[i];
  int ans = 0;
  REP(i, H) {
    REP(k, W) {
      int tmp = 0;
      if(S[i][k] == '#') tmp++;
      if(i + 1 < H && S[i + 1][k] == '#') tmp++;
      if(k + 1 < W && S[i][k + 1] == '#') tmp++;
      if(i + 1 < H && k + 1 < W && S[i + 1][k + 1] == '#') tmp++;
      if(tmp == 1 || tmp == 3) ans++;
    }
  }
  cout << ans << endl;
}