#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
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

int main() {
  ll N; cin >> N;
  vector<ll> p(N); REP(i, N) cin >> p[i];
  map<ll, ll> m;
  REP(i, N) m[p[i]]++; // 前処理
  ll ans = 0;
  for(auto x : m) {
    if(x.first - ans == 0) ans++;
  }
  vector<ll> res;
  for(int i = N - 1; i >= 0; --i) {
    res.push_back(ans);
    m[p[i]]--;
    if(m[p[i]] <= 0) {
      if(p[i] < ans) ans = p[i];
    }
  }
  for(int i = res.size() - 1; i >= 0; --i) {
    cout << res[i] << endl;
  }
}