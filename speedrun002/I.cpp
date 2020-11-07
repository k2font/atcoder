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
  vector<ll> A(N), B(N); REP(i, N) cin >> A[i] >> B[i];
  int ans = 0;
  for(int i = 1; i < N; ++i) {
    ll a = A[ans]; ll b = B[ans];
    ll ta = A[i]; ll tb = B[i];
    while(a > 0 && ta > 0) {
      a -= tb; ta -= b;
    }
    if(a <= 0) ans = i;
    if(i == N - 1 && a <= 0 && ta <= 0) ans = -1;
  }
  if(ans != -1) cout << ans + 1 << endl;
  else cout << ans << endl;
}