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
  vector<ll> A(N); REP(i, N) cin >> A[i];
  // 尺取法
  ll ans = 0;
  int right = 0;
  int sum = 0;
  for(int left = 0; left < N; ++left) {
    while(right < N && (sum ^ A[right]) == (sum + A[right])) {
      // 条件を満たし続けるまでsumとrightをカウントアップする
      sum += A[right];
      ++right;
    }
    // 条件を満たさなくなったら、いまのleftからrightを引く。
    // なぜなら、条件を満たす区間の部分区間もまた条件を満たすから(非自明なので怖い)
    ans += right - left;
    if(left == right) ++right; // もしleftがrightにたどり着いたら、rightを動かす
    else {
      sum -= A[left]; // leftが一つ左に動くので、a[left]分だけsumから削除する
    }
  }
  cout << ans << endl;
}