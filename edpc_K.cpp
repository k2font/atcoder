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
  int N; cin >> N;
  int K; cin >> K;
  vector<int> a(N); REP(i, N) cin >> a[i];
  vector<int> dp(K + 100, 0);
  REP(i, K + 1) {
    REP(m, N) {
      if(i - a[m] >= 0 && dp[i - a[m]] == 0) dp[i] = 1;
    }
  }
  if(dp[K] == 1) cout << "First" << endl;
  else cout << "Second" << endl;
}