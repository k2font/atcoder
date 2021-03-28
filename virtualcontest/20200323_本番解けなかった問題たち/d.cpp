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

int main() {
  ll N, K; cin >> N >> K;
  vector<char> D(K); REP(i, K) cin >> D[i];
  ll ans = 0; bool f2 = false;
  for(int i = N; i < 100000; ++i) {
    string s = to_string(i);
    bool f = false;
    REP(k, s.size()) {
      REP(m, K) {
        if(s[k] == D[m]) {
          f = true;
          break;
        }
      }
      if(f == true) break;
      if(k == s.size() - 1) {
        ans = i; f2 = true;
        break;
      }
    }
    if(f2 == true) break;
  }
  cout << ans << endl;
}