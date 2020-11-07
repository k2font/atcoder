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
  int X, Y, A, B, C; cin >> X >> Y >> A >> B >> C;
  vector<ll> p(A), q(B), r(C);
  REP(i, A) cin >> p[i];
  REP(i, B) cin >> q[i];
  REP(i, C) cin >> r[i];
  sort(all(p), greater<ll>()); sort(all(q), greater<ll>()); sort(all(r), greater<ll>());
  vector<ll> res;
  REP(i, X) res.push_back(p[i]);
  REP(i, Y) res.push_back(q[i]);
  REP(i, C) res.push_back(r[i]);
  sort(all(res), greater<ll>());
  ll ans = 0;
  for(int i = 0; i < (X + Y); ++i) {
    ans += res[i];
  }
  cout << ans << endl;
}