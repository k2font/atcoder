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
  vector<double> A(Q), B(Q); REP(i, Q) cin >> A[i] >> B[i];
  // すべての円錐の体積をあらかじめ計算しておく
  vector<pair<pair<ll, ll>, double>> vol(N);
  REP(i, N) {
    double a = pow(R[i], 2) * 3.14159265359 * H[i] * (double)(1.0 / 3.0);
    vol[i] = make_pair(make_pair(X[i], X[i] + H[i]), a);
  }
  sort(all(vol));
  // AとBの範囲に、max100個の円錐が含まれるかどうかを逐次探索
  // 具体的にはX[i] ~ X[i] + T[i]
  // A〜Bまでに含まれる円錐が、左側が含まれているのか右側が含まれているのかを見て、体積を計算する
  REP(i, Q) {
    double ans = 0.0;
    REP(k, N) {
      double f = vol[k].first.first; double s = vol[k].first.second;
      double d = vol[k].second;
      if(A[i] <= f && s <= B[i]) {
        // すっぽり
        ans += d; // 事前に求めたものを足すだけ
      } else {
        // 部分的
        if(A[i] <= s && s <= B[i] && A[i] > f) {
          ans += d * (pow((s - A[i]), 3) / pow((s - f), 3));
        } else if(A[i] <= f && f < B[i] && B[i] < s) {
          double a = d * ((pow(s - f, 3) - pow(s - B[i], 3)) / pow((s - f), 3));
          ans += a;
        } else if(f < A[i] && B[i] < s) {
          double a = d * (pow(s - A[i], 3) / pow(s - f, 3));
          double b = d * (pow(s - B[i], 3) / pow(s - f, 3));
          ans += a - b;
        }
      }
    }
    cout << fixed << setprecision(10) << ans << endl;
  }
}