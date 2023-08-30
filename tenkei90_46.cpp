#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using P = pair<ll, ll>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};
string char_to_string(char val) {
  return string(1, val);
}
int char_to_int(char val) {
  return val - '0';
}
char inverse_char(char c) {
  if(isupper(c)) return tolower(c);
  else return toupper(c);
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
template <class T> T up(T a, T div) { return (a + div - 1) / div; }

int main() {
  ll N; cin >> N;
  vector<ll> A(46), B(46), C(46);
  REP(i, N) {
    ll a; cin >> a;
    A[(a % 46)]++;
  }
  REP(i, N) {
    ll b; cin >> b;
    B[(b % 46)]++;
  }
  REP(i, N) {
    ll c; cin >> c;
    C[(c % 46)]++;
  }

  ll ans = 0;
  REP(i, 46) {
    if(A[i] == 0) continue;
    REP(k, 46) {
      if(B[k] == 0) continue;
      REP(j, 46) {
        if((i + k + j) % 46 > 0) continue;
        ans += (A[i] * B[k] * C[j]);
      }
    }
  }
  cout << ans << endl;
}