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
ll INF = 2e18;
ll mul(ll a, ll b) {
  if(a == 0 or b == 0) return 0;
  if(INF / a < b) return INF;
  return a * b;
}

int main() {
  ll X, Y; cin >> X >> Y;
  ll A, B; cin >> A >> B;
  ll ans = 0;
  if(X >= B) {
    ans = ((Y - 1) - X) / B;
  } else {
    // 増分がBに達するまでAをかける
    ll cnt = 0;
    while(true) {
      if(mul(A, X) >= X + B) break;
      if(mul(A, X) >= Y) break;
      X *= A;
      cnt++;
    }
    ans += cnt;
    // ここから残りをB足す
    ll tmp = (Y - 1) - X;
    ans += (tmp / B);
  }
  cout << ans << endl;
}