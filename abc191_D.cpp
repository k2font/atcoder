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
  long double X, Y, R; cin >> X >> Y >> R;
  R += 1e-14;
  ll left = ceil(X - R); ll right = floor(X + R);
  ll ans = 0;
  for(int i = left; i <= right; ++i) {
    long double y_p, y_n;
    long double tmp1, tmp2;
    long double sq = ((long double)i - X) * ((long double)i - X);

    tmp1 = (long double)Y + sqrtl(R * R - sq);
    y_p = floor(tmp1);

    tmp2 = (long double)Y - sqrtl(R * R - sq);
    y_n = ceil(tmp2);

    ans += (y_p - y_n) + 1;
  }
  cout << ans << endl;
}