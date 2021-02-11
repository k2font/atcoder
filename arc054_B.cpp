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
  double P; cin >> P;
  // 3分探索
  // 目的関数
  auto f = [P](double x) {
    return x + P / pow(2, x / 1.5);
  };

  // 左端
  double low = 0;

  // 右側
  double high = 1e10;

  // とりあえず1000回繰り返す
  int c = 1000;
  while (--c) {
    double c1 = (low * 2 + high) / 3;
    double c2 = (low + high * 2) / 3;

    // もしf(c2)のほうが小さいなら、lowを更新する
    if(f(c1) > f(c2)) low = c1;
    else high = c2;
    // cout << fixed << setprecision(15) << f(high) << endl;
  }

  cout << fixed << setprecision(15) << f(high) << endl;
}