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

int main() {
  ll N; cin >> N;
  vector<ll> a(N); REP(i, N) cin >> a[i];

  ll A = 0;
  ll B = 0;

  A = a[0];
  REP(i, N) {
    if(i == 0) continue;
    B += a[i];
  }

  ll C = 0;
  ll ans = 999999999999999999;
  REP(i, N - 1) {
    if(i != 0) {
      A += a[i];
      B -= a[i];
    }

    C = abs(A - B);
    if(ans > C) ans = C;
    // cout << A << " " << B << " " << ans << endl;
  }

  cout << ans << endl;
}