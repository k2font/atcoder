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
  ll N; cin >> N;
  vector<ll> P(N); REP(i, N) cin >> P[i]; REP(i, N) --P[i];
  vector<ll> tmp(N); REP(i, N) tmp[P[i]] = i;
  ll ans = 0; set<ll> s;
  for(int i = N - 1; i >= 0; --i) {
    int p = tmp[i];
    ll C = 0;
    s.insert(p);
    vector<ll> l(2, -1); vector<ll> r(2, N);
    auto it = s.find(p);
    REP(k, 2) {
      if(it == s.begin()) break;
      --it;
      l[k] = *it;
    }
    auto it2 = s.find(p);
    REP(k, 2) {
      ++it2;
      if(it2 == s.end()) break;
      r[k] = *it2;
    }
    vector<ll> ls(2);
    ls[0] = p - l[0]; ls[1] = l[0] - l[1];
    vector<ll> rs(2);
    rs[0] = r[0] - p; rs[1] = r[1] - r[0];
    C = ls[0] * rs[1] + ls[1] * rs[0];
    ans += C * (i + 1);
  }
  cout << ans << endl;
}