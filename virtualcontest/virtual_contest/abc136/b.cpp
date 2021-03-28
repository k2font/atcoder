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

ll g1(ll n) {
  string p = to_string(n);
  sort(all(p)); reverse(all(p));
  return stoll(p);
}

ll g2(ll n) {
  string p = to_string(n);
  sort(all(p));
  return stoll(p);
}

ll f(ll n) {
  return g1(n) - g2(n);
}

int main() {
  ll N, K; cin >> N >> K;
  ll ans = N;
  REP(i, K) {
    ans = f(ans);
  }
  cout << ans << endl;
}
