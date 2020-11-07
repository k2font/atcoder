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
  ll ans = 0;
  map<ll, ll> m; m[0] = 1;
  reverse(all(S));
  ll tmp = 0, ten = 1;
  REP(i, S.size()) {
    tmp += char_to_int(S[i]) * ten;
    tmp %= 2019;
    ten *= 10; ten %= 2019;
    m[tmp]++;
  }
  for(auto x: m) {
    ans += 0.5 * x.second * (x.second - 1);
  }
  cout << ans << endl;
}