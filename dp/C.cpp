// https://qiita.com/drken/items/dc53c683d6de8aeacf5a#a-%E5%95%8F%E9%A1%8C---frog-1
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
  vector<int> a(N), b(N), c(N);
  REP(i, N) {
    cin >> a[i] >> b[i] >> c[i];
  }

  // vector<vector<int>> dp(100010, vector<int>(3));
  ll dp[100010][3];
  REP(i, 100010) {
    REP(k, 3) {
      dp[i][k] = 0; // 最大値を求めたいので、初期値は3を入れる
    }
  }

  dp[0][0] = 0;
  dp[0][1] = 0;
  dp[0][2] = 0;

  for(int i = 1; i <= N; ++i) {
    chmax(dp[i][0], dp[i - 1][1] + a[i - 1]);
    chmax(dp[i][0], dp[i - 1][2] + a[i - 1]);
    chmax(dp[i][1], dp[i - 1][0] + b[i - 1]);
    chmax(dp[i][1], dp[i - 1][2] + b[i - 1]);
    chmax(dp[i][2], dp[i - 1][0] + c[i - 1]);
    chmax(dp[i][2], dp[i - 1][1] + c[i - 1]);
  }

  ll max_num = 0;
  max_num = max(dp[N][0], dp[N][1]);
  max_num = max(max_num, dp[N][2]);
  cout << max_num << endl;
}