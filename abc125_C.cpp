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

// 最大公約数
int GCD(int a, int b) {
  return b ? GCD(b, a%b) : a;
}

int main() {
  ll N; cin >> N;
  vector<ll> A(N); REP(i, N) cin >> A[i];
  int ans = 0;
  // 累積GCDを求める
  vector<ll> left(N + 1, 0);
  vector<ll> right(N + 1, 0);
  REP(i, N) left[i + 1] = GCD(left[i], A[i]);
  for(int i = N - 1; i >= 0; --i) {
    right[i] = GCD(right[i + 1], A[i]);
  }
  REP(i, N) {
    ans = max(ans, GCD(left[i], right[i + 1]));
  }
  cout << ans << endl;
}