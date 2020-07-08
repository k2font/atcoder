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
  string ans = "YES";
  if(S.size() >= 10) ans = "NO";
  string tmp = "KIHBR";
  int k = 0;
  REP(i, S.size()) {
    if(tmp[k] != S[i] || S[i] != 'A') {
      ans = "NO";
      break;
    }
    if(tmp[k] == S[i]) k++;
  }

  cout << ans << endl;
}