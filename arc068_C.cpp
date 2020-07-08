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
  ll x; cin >> x;
  ll ans = x / 11 * 2;
  if(x % 11 < 7 && x % 11 > 0) {
    ans += 1;
  } else if(x % 11 < 11 && x % 11 != 0) {
    ans += 2;
  }
  cout << ans << endl;
}