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
  ll X; cin >> X;
  int ans = 0;
  for(int i = 1; i < 500; ++i) {
    if(X == pow(i, 4)) ans = i;
  }
  cout << ans << endl;
}