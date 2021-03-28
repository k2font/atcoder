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
  ll N; cin >> N;
  vector<ll> A(N); REP(i, N) cin >> A[i];
  ll ans = 0;

  // TLEを回避したい
  // O(N)で計算したい
  // 式変形!
  ll a = 0;
  REP(i, N) {
    a += A[i] * A[i];
  }

  ll b = 0;
  ll tmp = 0;
  for(int i = N - 1; i >= 1; --i) {
    tmp += A[i];
    b += A[i - 1] * tmp;
  }

  ans = (N - 1) * a - 2 * b;

  cout << ans << endl;
}