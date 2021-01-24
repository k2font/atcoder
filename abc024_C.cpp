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
  ll N, D, K; cin >> N >> D >> K;
  vector<ll> L(D), R(D); REP(i, D) cin >> L[i] >> R[i];
  vector<ll> S(K), T(K); REP(i, K) cin >> S[i] >> T[i];
  REP(i, K) {
    int ans = 0;
    REP(m, D) {
      // 正の方向に移動する時
      if(S[i] < T[i]) {
        // SがLとRの範囲外にいれば移動できない
        if(S[i] < L[m] || R[m] < S[i]) {
          ++ans;
          continue;
        }
        if(L[m] <= T[i] && T[i] <= R[m]) {
          ++ans;
          cout << ans << endl;
          break;
        } else {
          S[i] = R[m];
        }
        ++ans;
      } else { // 負の方向に移動する時
        // SがLとRの範囲外にいれば移動できない
        if(S[i] < L[m] || R[m] < S[i]) {
          ++ans;
          continue;
        }
        if(L[m] <= T[i] && T[i] <= R[m]) {
          ++ans;
          cout << ans << endl;
          break;
        } else {
          S[i] = L[m];
        }
        ++ans;
      }
    }
  }
}
