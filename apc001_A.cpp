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
  ll X, Y; cin >> X >> Y;

  ll i = 0;
  ll ans = -1;
  while(true) {
    if(X % Y == 0) {
      break;
    }

    i = i + X;
    if(i % Y != 0) {
      ans = i;
      break;
    }

    if(i > pow(10, 18)) break;
  }

  cout << ans << endl;
}