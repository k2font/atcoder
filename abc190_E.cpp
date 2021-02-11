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

const ll INF = 1e9;
vector<vector<int>> dp;
vector<vector<int>> dist;
ll N, M;
int K;

int main() {
  cin >> N >> M;
  vector<ll> A(M), B(M); REP(i, M) cin >> A[i] >> B[i];
  REP(i, M) {
    --A[i]; --B[i];
  }
  vector<vector<int>> to(N); // tree
  REP(i, M) {
    to[A[i]].push_back(B[i]);
    to[B[i]].push_back(A[i]);
  }
  cin >> K;
  vector<ll> C(K); REP(i, K) cin >> C[i];
  REP(i, K) --C[i]; // 0-indexedにしておく

  // bitDPで使用するグラフ
  dist.resize(K, vector<int>(K));

  // BFSを表すラムダ式
  auto bfs = [&](int sv) {
    vector<int> dist(N, INF);
    queue<int> q;
    dist[sv] = 0;
    q.push(sv);
    while(!q.empty()) {
      int v = q.front(); q.pop();
      for(int u : to[v]) {
        if(dist[u] != INF) continue;
        dist[u] = dist[v] + 1;
        q.push(u);
      }
    }
    return dist;
  };

  // K個のノードを持ったグラフが生まれる
  // これを使ってbitDPする
  REP(i, K) {
    vector<int> d = bfs(C[i]);
    REP(j, K) {
      dist[i][j] = d[C[j]];
    }
  }

  dp.resize((1 << K), vector<int>(K, INF)); // DPテーブルには余裕をもたせる、テーブルは0で初期化しておく
  REP(i, K) dp[1<<i][i] = 1;
  REP(s, (1 << K)) {
    REP(i, K) {
      if(!(s >> i & 1)) continue;
      REP(j, K) {
        if(s >> j & 1) continue;
        chmin(dp[s | 1 << j][j], dp[s][i] + dist[i][j]);
      }
    }
  }
  int ans = INF;
  REP(i, K) {
    chmin(ans, dp[(1 << K) - 1][i]);
  }
  if(ans != INF) cout << ans << endl;
  else cout << -1 << endl; // 到達不可能なノードが存在した
}