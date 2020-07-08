#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define REP(i,n) for(ll i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
string char_to_string(char val) {
  return string(1, val);
}
int char_to_int(char val) {
  return val - '0';
}

int main() {
  int N; cin >> N;
  vector<string> S(N); REP(i, N) cin >> S[i];

  map<string, int> m;

  REP(i, N) {
    m[S[i]]++;
  }

  int ans = 0;
  for(auto x : m) {
    if(x.second > 0) {
      ans++;
    }
  }

  cout << ans << endl;
}