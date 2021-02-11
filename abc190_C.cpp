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
  int N; cin >> N; int M; cin >> M;
  vector<ll> A(M), B(M); REP(i, M) cin >> A[i] >> B[i];
  int K; cin >> K;
  vector<ll> C(K), D(K); REP(i, K) cin >> C[i] >> D[i];
  // bit全探索
  // bitに1が立っていればDにボールを入れる
  ll ans = 0; // 最大いくつの条件が満たされているか
  // bit全探索
  for(int bit = 0; bit < (1 << K); ++bit) {
    vector<ll> t(N + 1, 0);
    for(int i = 0; i < K; ++i) {
      if(bit & (1 << i)) {
        t[C[i]]++;
      } else {
        t[D[i]]++;
      }
    }
    ll res = 0;
    REP(i, M) {
      if(t[A[i]] > 0 && t[B[i]] > 0) res++;
    }
    chmax(ans, res);
  }
  cout << ans << endl;
}
