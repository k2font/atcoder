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
  int N, M; cin >> N >> M;
  vector<int> a(N + 1, 0);
  REP(i, M) {
    int b; cin >> b;
    a[b] = 1;
  }
  const ll MOD = pow(10, 9) + 7;
  vector<int> dp(N + 1, 0);
  REP(i, N + 1) {
    if(i == 0) {
      dp[i] = 1;
      continue;
    }
    if(a[i] == 1) {
      dp[i] = 0;
      continue;
    } else {
      if(i - 1 >= 0) dp[i] += dp[i - 1];
      if(i - 2 >= 0) dp[i] += dp[i - 2];
      dp[i] %= MOD;
    }
  }
  cout << dp[N] << endl;
}