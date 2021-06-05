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
  ll T; cin >> T;
  double L, X, Y; cin >> L >> X >> Y;
  int Q; cin >> Q;
  REP(i, Q) {
    double E; cin >> E;
    // 高橋くんの座標を求める
    double a = 360.0 * (E / T);
    double y = -L / 2 * sin(M_PI * a / 180.0);
    double z = L / 2 - (L / 2 * cos(M_PI * a / 180.0));
    
    // 俯角を求める
    double ans = 0.0;
    double b = sqrt(pow(X, 2) + pow(Y - y, 2));
    ans = atan2(z, b) * (180.0 / M_PI);
    cout << fixed << setprecision(15) << ans << endl;
  }
}