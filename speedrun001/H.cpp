#include <bits/stdc++.h>
#include <atcoder/all>
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
  vector<ll> A(N); REP(i, N) cin >> A[i];
  const ll INF = pow(10, 18) + 7; // dpテーブルに用いる初期値
  // dp[共通部分列の長さ] = 共通部分列の末尾の最小値と定義する
  vector<ll> dp(N, INF);

  // dpテーブルを更新する。
  // 数列Aの要素を1から順に精査する。
  REP(i, N) { // 数列Aのi番目を走査
    // dp[k] >= A[i]となる最小のイテレータを見つける
    auto it = lower_bound(all(dp), A[i]);
    // 該当のdpテーブルの位置にある値をA[i]で更新する
    *it = A[i];
  }
  ll ans = 0;
  // dpテーブルを更新したら、最後に答えとなる値を抽出
  REP(i, N) {
    if(dp[i] != INF) ans = i + 1; // INFを持たないdpテーブルの添字のうち最大となる値が答え
    else break;
  }
  cout << ans << endl;
}