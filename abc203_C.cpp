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
  ll N, K; cin >> N >> K;
  vector<ll> A(N), B(N); REP(i, N) cin >> A[i] >> B[i];
  map<ll, ll> p;
  REP(i, N) {
    p[A[i]] += B[i];
  }
  ll res = K; ll genzai = 0; ll ans = 0;
  for(auto x : p) {
    // 次の村まで所持金が尽きるかどうか
    if(x.first - genzai > res) {
      // 次の友達に辿り着く前にすべての答えをgenzaiに突っ込む
      break;
    }
    // そうでなければその村に行く
    res -= (x.first - genzai);
    genzai += (x.first - genzai);

    res += p[x.first];
  }
  cout << genzai + res << endl;
}