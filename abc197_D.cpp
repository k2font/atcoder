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

#define PI 3.141592653589793

double ansx(double x1, double y1, double x2, double y2, double degree) {
  double rty = degree * PI / 180.0;
  // cout << rty << " " << sin( rty ) << endl;
  double atai_x = (x2 - x1) * cos( rty ) - (y2 - y1) * sin( rty );
  return atai_x;
}

double ansy(double x1, double y1, double x2, double y2, double degree) {
  double rty = degree * PI / 180.0;
  double atai_y = (x2 - x1) * sin( rty ) + (y2 - y1) * cos( rty );
  return atai_y;
}

int main() {
  double N; cin >> N;
  double x0, y0; cin >> x0 >> y0;
  double x2, y2; cin >> x2 >> y2;
  double cx = 0.0; double cy = 0.0;
  cx = (x0 + x2) / 2.0; cy = (y0 + y2) / 2.0;
  double theta = 360.0 / N;
  // cout << cx << " " << cy << " " << theta << endl;
  cout << fixed << setprecision(10) << ansx(cx, cy, x0, y0, theta) + cx << " " << ansy(cx, cy, x0, y0, theta) + cy << endl;
}