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
  double a, b, c; cin >> a >> b >> c;
  double tmp = b * b - 4 * a * c;
  if(tmp < 0) {
    cout << "imaginary" << endl;
    return 0;
  }
  double res1 = -b + sqrt(tmp); res1 /= (2 * a);
  double res2 = -b - sqrt(tmp); res2 /= (2 * a);
  if(res1 == res2) cout << fixed << setprecision(20) << res1 << endl;
  else cout << fixed << setprecision(20) << min(res1, res2) << " " << max(res1, res2) << endl;
}