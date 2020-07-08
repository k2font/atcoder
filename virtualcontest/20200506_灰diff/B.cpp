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
  string S; cin >> S;
  string ans = "Yes";
  REP(i, S.size()) {
    if((i + 1) % 2 == 1) {
      if(S[i] == 'R' || S[i] == 'U' || S[i] == 'D') {

      } else {
        ans = "No";
      }
    } else {
      if(S[i] == 'L' || S[i] == 'U' || S[i] == 'D') {

      } else {
        ans = "No";
      }
    }
  }

  cout << ans << endl;
}