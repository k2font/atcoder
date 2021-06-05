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
  vector<ll> X(N), Y(N); REP(i, N) cin >> X[i] >> Y[i];
  double ans = 0;
  REP(i, N) {
    REP(k, N) {
      REP(m, N) {
        double ax, ay, bx, by;
        ax = (double)(X[i] - X[k]); ay = (double)(Y[i] - Y[k]);
        bx = (double)(X[m] - X[k]); by = (double)(Y[m] - Y[k]);
        double cost = (double)(ax * bx + ay * by) / (double)(sqrt(ax * ax + ay * ay) * sqrt(bx * bx + by * by));
        ans = max(ans, acos(cost) * 180.0 / M_PI );
      }
    }
  }
  cout << fixed << setprecision(15) << ans << endl;
}