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
  int N; cin >> N;
  vector<ll> h(N); REP(i, N) cin >> h[i];
  ll ans = 0;
  while(true) {
    bool f = false; bool t = false;
    REP(i, N) {
      if(h[i] != 0) {
        if(i == N - 1) ans++;
        h[i]--; f = true; t = true;
      }
      else if(h[i] == 0 && t == true) {
        ans++;
        t = false;
      }
    }
    if(f == false) break;
  }
  cout << ans << endl;
}