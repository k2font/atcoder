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
  double A, B, C; cin >> A >> B >> C;
  vector<double> a = {A, B, C}; sort(all(a));
  double maxn = (A + B + C) * (A + B + C) * 3.14159265359;
  double minn = 0;
  if(a[0] + a[1] >= a[2]) minn = 0;
  else if(a[0] + a[1] < a[2]) minn = a[2] - (a[1] + a[0]);
  cout << fixed << setprecision(20) << maxn - (minn * minn * 3.14159265359) << endl;
}
