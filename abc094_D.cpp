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
  int n; cin >> n;
  vector<double> a(n); REP(i, n) cin >> a[i];
  sort(all(a));
  long long tmp = a[n - 1];
  ll tmp2 = 0;
  ll diff = pow(10,9);
  ll ans = 0;
  REP(i, n - 1) {
    if(diff > abs(tmp / 2.0 - a[i])) {
      diff = abs(tmp / 2.0 - a[i]);
      tmp2 = a[i];
    }
  }
  cout << tmp << " " << tmp2 << endl;
}