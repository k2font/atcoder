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
template <class T> T up(T a, T div) { return (a + div - 1) / div; }

int main() {
  ll N; cin >> N;
  vector<ll> x(N), y(N); REP(i, N) cin >> x[i] >> y[i];
  ll max_x, min_x, max_y, min_y;
  sort(all(x)); sort(all(y));
  max_x = x[N - 1]; max_y = y[N - 1]; min_x = x[0]; min_y = y[0];
  // cout << max(abs(max_x - min_x), abs(max_y - min_y)) << endl; // もし最も大きい値を求めるなら
  ll max_x2, min_x2, max_y2, min_y2;
  max_x2 = x[N - 2]; max_y2 = y[N - 2]; min_x2 = x[1]; min_y2 = y[1];
  ll tmpx = max(abs(max_x2 - min_x), abs(max_x - min_x2));
  ll tmpy = max(abs(max_y2 - min_y), abs(max_y - min_y2));
  cout << max(tmpx, tmpy) << endl;

  vector<ll> t;
  REP(i, N) {
    REP(k, N) {
      if(i >= k) continue;
      cout << x[i] << " " << y[i] << " " << x[k] << " " << y[k] << " " << max(abs(x[i] - x[k]), abs(y[i] - y[k])) << endl;
    }
  }
}