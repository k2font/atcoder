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
  vector<string> S(N); REP(i, N) cin >> S[i];
  map<string, int> m;
  REP(i, N) m[S[i]]++;
  vector<string> ans; int res = 0;
  for(auto x : m) if(res < x.second) res = x.second;
  for(auto x : m) {
    if(x.second == res) ans.push_back(x.first);
  }
  sort(all(ans));
  REP(i, ans.size()) {
    cout << ans[i] << endl;
  }
}