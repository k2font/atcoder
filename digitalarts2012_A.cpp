#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using P = pair<ll, ll>;
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
struct edge {
  ll to, cost;
};

int main() {
  int N; cin >> N;
  ll res = 0; ll ans = pow(10, 9);
  for(int i = 1; i <= 320; ++i) {
    res = i * i;
    ll tmp = N - res;
    if(tmp < 0) break;
    ll a = abs(i - (i + (tmp / i))) + (tmp % i);
    if(ans > a) ans = a;
  }
  cout << ans << endl;
}
