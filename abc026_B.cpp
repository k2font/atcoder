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
  vector<double> R(N); REP(i, N) cin >> R[i];
  sort(all(R));
  bool flag = true;
  double ans = 0;
  for(int i = N - 1; i >= 0; --i) {
    if(flag) ans += R.at(i) * R[i];
    else ans -= R[i] * R[i];
    flag = !flag;
  }
  double PI = (double)3.1415926535;
  cout << fixed << setprecision(15) << ans * PI << endl;
}