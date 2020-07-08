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
int vector_finder(std::vector<ll> vec, int number) {
  auto itr = std::find(vec.begin(), vec.end(), number);
  size_t index = std::distance( vec.begin(), itr );
  if (index != vec.size()) { // 発見できたとき
    return 1;
  }
  else { // 発見できなかったとき
    return 0;
  }
}

int main() {
  int N; cin >> N;
  vector<int> a(N); REP(i, N) cin >> a[i];
  ll dp[110][30] = {0};
  dp[1][a[0]] = 1;
  for(int i = 1; i < N - 1; ++i) {
    for(int k = 0; k <= 20; ++k) {
      if(k - a[i] >= 0) dp[i + 1][k - a[i]] += dp[i][k];
      if(k + a[i] <= 20) dp[i + 1][k + a[i]] += dp[i][k];
    }
  }
  cout << dp[N - 1][a[N - 1]] << endl; 
}