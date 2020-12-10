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

// いもす法
int main() {
  ll N, W; cin >> N >> W;
  vector<ll> S(N), T(N), P(N);
  REP(i, N) {
    cin >> S[i] >> T[i] >> P[i];
  }
  int m = 200001;
  vector<ll> t(m + 1, 0);
  REP(i, N) {
    t[S[i]] += P[i]; t[T[i]] -= P[i];
  }
  REP(i, m) {
    t.at(i + 1) += t.at(i);
  }
  string ans = "Yes";
  REP(i, m + 1) {
    if(t[i] > W) ans = "No";
  }
  cout << ans << endl;
}