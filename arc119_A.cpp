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

ll INF = 1e18;
ll mul(ll a, ll b) {
  if(a == 0 or b == 0) return 0;
  if(INF / a < b) return INF;
  return a * b;
}

int main() {
  ll N; cin >> N; ll ans = INF + 100; ll B = 1;
  ll aans = 0; ll bans = 0; ll cans = 0;
  for(int b = 0; b <= 62; ++b) {
    if(b != 0) B *= 2;
    if(b + (N / B) + (N % B) < ans) {
      bans = b; aans = N / B; cans = N % B;
      ans = b + (N / B) + N % B;
    }
  }
  cout << ans << endl;
}