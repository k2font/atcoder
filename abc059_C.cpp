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
  int n; cin >> n;
  vector<ll> a(n + 1, 0); REP(i, n) cin >> a[i];
  // 前から貪欲に求めていく
  // 先頭が正の場合と負の場合の2通りを考える。答えが小さい方を出力する
  // 正にしたい数は-1になるように変更する。逆もしかり。
  // 前から累積和っぽいものを求めていけばいい。
  ll ans = 0;

  // 先頭が正
  ll tmp = 0;
  REP(i, n) {
    tmp += a[i];
    if(i % 2 == 0) {
      if(tmp <= 0) {
        ans = ans + 1 - tmp;
        tmp = 1;
      }
    } else {
      if(tmp >= 0) {
        ans = ans + tmp + 1;
        tmp = -1;
      }
    }
  }

  // 先頭が負
  ll ans2 = 0;
  tmp = 0;
  REP(i, n) {
    tmp += a[i];
    if(i % 2 == 1) {
      if(tmp <= 0) {
        ans2 = ans2 + 1 - tmp;
        tmp = 1;
      }
    } else {
      if(tmp >= 0) {
        ans2 = ans2 + tmp + 1;
        tmp = -1;
      }
    }
  }

  cout << min(ans, ans2) << endl;
}