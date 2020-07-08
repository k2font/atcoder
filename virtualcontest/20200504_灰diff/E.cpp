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

vector<ll> divisor(ll n) {
  vector<ll> ret;
  for(ll i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }

  sort(begin(ret), end(ret));
  return (ret);
}

int main() {
  ll N; cin >> N;

  vector<ll> div;
  div = divisor(N);

  ll ans = pow(10, 13) + 7;
  ll a = 0;
  ll b = 0;
  REP(i, div.size()) {
    ll tmp = 0;
    tmp = N / div[i];
    if(ans > abs(div[i] - tmp)) {
      ans = abs(div[i] - tmp);
      a = div[i];
      b = tmp;
    }
  }
  cout << (a - 1) + (b - 1) << endl;
}