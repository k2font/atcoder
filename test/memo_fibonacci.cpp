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

vector<ll> memo(100, -1);

ll fibo(ll n) {
  if(n == 0) return 0;
  else if(n == 1) return 1;
  if(memo[n] != -1) return memo[n];
  return memo[n] = fibo(n - 1) + fibo(n - 2);
}

const ll INF = 2e18;
vector<ll> dp(100010, INF);
vector<ll> h;
ll frog1(ll n) {
  if(dp[n] < INF) return dp[n];

  if(n == 0) return 0;

  ll res = INF;
  chmin(res, frog1(n - 1) + abs(h[n] - h[n - 1]));
  if(n >= 2) chmin(res, frog1(n - 2) + abs(h[n] - h[n - 2]));
  return dp[n] = res;
}

int main() {
  // とりあえずフィボナッチ数列を書く
  // for(int i = 1; i <= 90; ++i) {
  //   cout << i << " 項目の値 " << fibo(i) << endl;
  // }

  // EDPCのfrog1をメモ化再帰で解く
  ll N; cin >> N;
  h.resize(N); REP(i, N) cin >> h[i];

  for(int i = 0; i < 100010; ++i) dp[i] = INF;

  cout << frog1(N - 1) << endl;
}