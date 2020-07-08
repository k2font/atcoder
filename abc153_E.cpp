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
  int H, N; cin >> H >> N;
  vector<int> A(N), B(N); REP(i, N) cin >> A[i] >> B[i];
  int dp[N + 10][H + 10];
  REP(i, N + 10) {
    REP(k, H + 10) {
      dp[i][k] = pow(10, 9) + 7;
    }
  }
  dp[0][0] = 0;
  dp[0][A[0]] = B[0];
  for(int i = 0; i < N; ++i) {
    for(int k = 0; k <= H; ++k) {
      if(k <= A[i]) {
        dp[i + 1][k] = min(dp[i][k], B[i]);
      } else {
        dp[i + 1][k] = min(dp[i][k], dp[i + 1][k - A[i]] + B[i]);
      }
    }
  }
  cout << dp[N][H] << endl;
}