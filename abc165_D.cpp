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
  ll A, B, N; cin >> A >> B >> N;
  ll ans = 0;
  if(N < B) {
    ll tmp = A * N;
    ans = tmp / B;
  } else {
    ll tmp3 = A * (B - 1);
    ll E = tmp3 / B;

    ll tmp = A * N;
    ll C = tmp / B;
    ll tmp2 = N / B;
    ll D = A * tmp2;
    // ans = max(E, C - D);
    ans = E;
  }
  cout << ans << endl;
}