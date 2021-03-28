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
  ll H, W, X, Y; cin >> H >> W >> X >> Y; X--; Y--;
  vector<string> S(H); REP(i, H) cin >> S[i];
  ll ans = 0;
  for(int i = X; i < H; ++i) {
    if(S[i][Y] == '#') break;
    ans++;
  }

  for(int i = X; i >= 0; --i) {
    if(S[i][Y] == '#') break;
    ans++;
  }

  for(int i = Y; i < W; ++i) {
    if(S[X][i] == '#') break;
    ans++;
  }

  for(int i = Y; i >= 0; --i) {
    if(S[X][i] == '#') break;
    ans++;
  }
  cout << ans - 3 << endl;
}