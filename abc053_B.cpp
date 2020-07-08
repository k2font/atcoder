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
  string s; cin >> s;
  int a = 0;
  int b = 0;

  REP(i, s.size()) {
    if(s[i] == 'A') {
      a = i;
      break;
    }
  }

  for(int i = s.size() - 1; i >= 0; --i) {
    if(s[i] == 'Z') {
      b = i;
      break;
    }
  }

  cout << b - a + 1 << endl;
}