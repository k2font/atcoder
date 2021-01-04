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
  int N, Q; cin >> N >> Q;
  vector<double> X(N), R(N), H(N); REP(i, N) cin >> X[i] >> R[i] >> H[i];
  vector<int> A(Q), B(Q); REP(i, Q) cin >> A[i] >> B[i];
  // すべての円錐の体積をあらかじめ計算しておく
  vector<double> vol(N);
  REP(i, N) {
    vol[i] = pow(R[i], 2) * 3.14 * H[i] * (double)(1.0 / 3.0);
  }
  // AとBの範囲に、max100個の円錐が含まれるかどうかを逐次探索
  // 具体的にはX[i] ~ X[i] + T[i]
  // A〜Bまでに含まれる円錐が、左側が含まれているのか右側が含まれているのかを見て、体積を計算する
  REP(i, Q) {
    double ans = 0.0;
    REP(k, N) {
      if(A[i] <= X[k] && X[k] + H[k] <= B[i]) {
        // すっぽり
        ans += vol[k]; // 事前に求めたものを足すだけ
      } else if(true) {
        // 部分的
      }
    }
    cout << fixed << setprecision(10) << ans << endl;
  }
}