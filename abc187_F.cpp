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
  int N, M; cin >> N >> M;
  vector<ll> A(M), B(M); REP(i, M) cin >> A[i] >> B[i];
  vector<vector<int>> G(N, vector<int>(N, false));
  REP(i, M) {
    A[i]--; B[i]--;
    G[A[i]][B[i]] = G[B[i]][A[i]] = true;
  }

  vector<bool> ok(1 << N, true); // ok[bit]: 頂点集合bitがクリークかどうかを確認する
  for(int bit = 0; bit < (1 << N); ++bit) {
    vector<int> vs;
    for(int i = 0; i < N; ++i) {
      if(bit & (1 << i)) {
        vs.push_back(i);
      }
    }
    for(int i = 0; i < vs.size() && ok[bit]; ++i) {
      for(int j = i + 1; j < vs.size() && ok[bit]; ++j) {
        if(!G[vs[i]][vs[j]]) ok[bit] = false;
      }
    }
  }

  const int INF = 1 << 30;
  vector<int> dp(1 << N, INF);
  dp[0] = 0;
  for(int bit = 0; bit < (1 << N); ++bit) {
    if(dp[bit] >= INF) continue;
    int cbit = (1 << N) - 1 - bit;
    for(int add = cbit; ; add = (add - 1) & cbit) {
      if(!add) break;
      if(ok[add]) chmin(dp[bit | add], dp[bit] + 1);
    }
  }
  cout << dp[(1 << N) - 1] << endl;
}
