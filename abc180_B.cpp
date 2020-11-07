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
  ll N; cin >> N;
  vector<ll> x(N); REP(i, N) cin >> x[i];
  ll m = 0; ll u = 0; ll c = 0;
  REP(i, N) {
    m += abs(x[i]);
  }
  REP(i, N) {
    u += abs(x[i]) * abs(x[i]);
  }
  REP(i, N) {
    c = max(c, abs(x[i]));
  }
  cout << m << endl;
  cout << fixed << setprecision(20) << sqrt(u) << endl;
  cout << c << endl;
}