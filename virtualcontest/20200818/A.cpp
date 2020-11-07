#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using P = pair<ll, ll>;
string char_to_string(char val) {
  return string(1, val);
}
int char_to_int(char val) {
  return val - '0';
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
  double N, K; cin >> N >> K;
  double ans = 0;

  REP(i, N) {
    int res = i + 1; double tmp = 1.0 / N;
    while(res < K) {
      res *= 2;
      tmp *= 0.5;
    }
    ans += tmp;
  }
  cout << fixed << setprecision(20) << ans << endl;
}