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
  int N;
  double T, A;
  cin >> N >> T >> A;
  vector<int> H(N); REP(i, N) cin >> H[i];

  double ans = pow(10, 9) + 7;
  int cnt = 0;
  REP(i, N) {
    double d = T - H[i] * 0.006;
    // cout << "d " << d << endl;
    if(abs(A - d) < ans) {
      ans = abs(A - d);
      cnt = i + 1;
    }
  }
  cout << cnt << endl;
}