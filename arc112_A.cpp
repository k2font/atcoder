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
  int T; cin >> T;
  vector<ll> L(T), R(T); REP(i, T) cin >> L[i] >> R[i];
  REP(i, T) {
    ll ans = 0;
    ll tmp = (R[i] + 2 * L[i]) * (R[i] - 2 * L[i] + 1) * 0.5;
    ll minus = (2 * L[i] - 1) * (R[i] - 2 * L[i] + 1);
    ans += (tmp - minus);
    if(tmp < 0 && minus < 0) ans = 0;
    cout << ans << endl;
  }
}