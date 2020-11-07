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
  const int MOD = 10007;
  ll a = 0; ll b = 0; ll c = 1;
  for(int i = 3; i < N; ++i) {
    ll tmp = a + b + c;
    a = b; b = c; c = tmp;
    a %= MOD; b %= MOD; c %= MOD;
  }
  if(N >= 3) cout << c << endl;
  else if(N == 1) cout << 0 << endl;
  else if(N == 2) cout << 0 << endl;
}
