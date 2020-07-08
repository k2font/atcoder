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
  int N; cin >> N;
  string S; cin >> S;

  vector<int> tmp(2);
  REP(i, N) {
    if(i == 0) {
      tmp[0] = 0;
      continue;
    } else {
      if(S[i] == 'E') {
        tmp[1]++;
      }
    }
  }

  ll ans = pow(10, 9) + 7;
  REP(i, N) {
    if(i != 0) {
      if(S[i - 1] == 'W') tmp[0]++;
      if(S[i] == 'E') tmp[1]--;
    }
    ll c = tmp[0] + tmp[1];
    if(ans > c) ans = c;
  }

  cout << ans << endl;
}