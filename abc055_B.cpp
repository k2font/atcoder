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
  ll N; cin >> N;

  ll ans = 1;
  ll INF = pow(10, 9) + 7;
  REP(i, N) {
    ans = ans * (i + 1);
    ans = ans % INF;
  }

  cout << ans << endl;
}