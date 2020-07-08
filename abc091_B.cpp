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
  int N; cin >> N;
  vector<string> s(N); REP(i, N) cin >> s[i];
  int M; cin >> M;
  vector<string> t(M); REP(i, M) cin >> t[i];
  map<string, int> m1, m2;
  REP(i, N) {
    m1[s[i]]++;
  }
  REP(i, M) {
    m2[t[i]]++;
  }
  int ans = 0;
  int res = 0;
  for(auto x: m1) {
    int a = x.second;
    int b = m2[x.first];
    ans = max(0, a - b);
    if(res < ans) res = ans;
  }
  cout << res << endl;
}