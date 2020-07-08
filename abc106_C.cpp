#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define REP(i,n) for(ll i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
string char_to_string(char val) {
  return string(1, val);
}
int char_to_int(char val) {
  return val - '0';
}

int main() {
  string S; cin >> S;
  ll K; cin >> K;
  
  int cnt = 0;
  char ans = 'a';
  REP(i, S.size()) {
    if(S[i] == '1') {
      cnt++;
    } else if(S[i] != '1') {
      ans = S[i];
      break;
    }
  }

  if(S[0] == '1') {
    if(K <= cnt) {
      cout << 1 << endl;
    } else {
      cout << ans << endl;
    }
  } else {
    cout << S[0] << endl;
  }
}