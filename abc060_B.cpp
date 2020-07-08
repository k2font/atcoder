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
  int A, B, C; cin >> A >> B >> C;
  string ans = "NO";
  ll tmp = 0;
  for(int i = 0; i < pow(10, 8); ++i) {
    tmp += A;
    if(tmp % B == C) {
      ans = "YES";
      break;
    }
  }
  cout << ans << endl;
}