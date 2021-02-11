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
  int X, Y; cin >> X >> Y;
  int N; cin >> N;
  vector<int> x(N), y(N); REP(i, N) cin >> x[i] >> y[i];
  double ans = 100000000;
  REP(i, N) {
    if(i == N - 1) {
      double d = 0;
      double a = 0;
      if(x[0] - x[i] != 0) {
        a = (double)(y[0] - y[i]) / (double)(x[0] - x[i]);
      } else {
        a = (double)(y[0] - y[i]);
      }
      double b = abs(a * X - Y - x[i] * a + y[i]);
      d = b / sqrt(a * a + 1);
      ans = min(d, ans);
      continue;
    }
    double d = 0;
    double a = (double)(y[i + 1] - y[i]) / (double)(x[i + 1] - x[i]);
    double b = abs(a * X - Y - x[i] * a + y[i]);
    d = b / sqrt(a * a + 1);
    ans = min(d, ans);
  }
  cout << fixed << setprecision(15) << ans << endl;
}