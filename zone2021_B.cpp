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
  double D, H; cin >> D >> H;
  vector<double> d(N), h(N); REP(i, N) cin >> d[i] >> h[i];
  const double INF = 0;
  double ans = INF;
  REP(i, N) {
    double tmp = (H - h[i]) / (D - d[i]) * d[i];
    double res = h[i] - tmp;
    if(res < 0) continue;
    ans = max(ans, res);
  }
  if(ans == INF) cout << 0.0 << endl;
  else cout << fixed << setprecision(15) << ans << endl;
}