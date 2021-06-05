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
  int N; cin >> N;
  vector<int> A(2 * N + 1); for (int i = 1; i <= 2 * N; i++) cin >> A[i];
  // 区間DPをする
  vector<vector<ll>> dp(2 * N + 1, vector<ll>(2 * N + 1, 2e18));
  for (int i = 1; i <= 2 * N; i++) {
    if(i < 2 * N) dp[i][i + 1] = abs(A[i] - A[i + 1]); // 初期値の計算
    // 与えられた区間すべての差を求めておく
  }

  for(int i = 3; i <= 2 * N; i += 2) {
    for (int k = 1; k <= 2 * N - i; k++) {
      int l = k; int r = k + i;
      for(int m = l; m < r; ++m) {
        dp[l][r] = min(dp[l][r], dp[l][m] + dp[m + 1][r]);
      }
      dp[l][r] = min(dp[l][r], dp[l + 1][r - 1] + abs(A[l] - A[r]));
    }
  }

  cout << dp[1][2 * N] << endl;
}