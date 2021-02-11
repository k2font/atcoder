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
  int N; cin >> N;
  vector<ll> A(N); REP(i, N) cin >> A[i];
  // とりあえず得点計算フェーズ
  ll ans = 0;
  REP(i, N) {
    if(i == N - 1) {
      ans += A[i];
      break;
    }
    if(A[i + 1] <= A[i]) {
      ans += A[i];
    }
  }
  // -1かどうか判定するフェーズ
  if(N == 1 && A[0] != 0) ans = -1;
  REP(i, N) {
    if(i == N - 1) continue;
    if(A[i] > i) ans = -1;
    if(A[i + 1] - A[i] > 1) ans = -1;
  }
  cout << ans << endl;
}