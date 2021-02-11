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

const ll INF = 1000000001;
const ll MAX_V = 100010;
vector<edge> G[MAX_V];
ll d[MAX_V]; // スタート地点から各ノードまでの最短距離
ll N, M; 

void dijkstra(ll s) {
  priority_queue<P, vector<P>, greater<P>> q;
  fill(d, d + N, INF); // dをすべてINFで埋める
  d[s] = 0; // スタート地点の重みは0
  q.push(P(0, s));
  while(!q.empty()) {
    P p = q.top(); q.pop(); // 先頭から値を取り出す
    ll v = p.second; // 次の行き先
    if(d[v] < p.first) continue;

    for(int i = 0; i < G[v].size(); ++i) {
      edge e = G[v][i]; // あるノートsから伸びる全ノードを確認する
      if(d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost;
        q.push(P(d[e.to], e.to));
      }
    }
  }
}

int main() {
  cin >> N >> M;
  vector<ll> A(M), B(M), C(M); REP(i, M) cin >> A[i] >> B[i] >> C[i];
  REP(i, M) {
    A[i]--; B[i]--;
    edge e = {B[i], C[i]}; // edgeには行き先の番号とその重みを入れる
    G[A[i]].push_back(e);
  }
  vector<ll> ans(N, INF);
  REP(i, M) {
    if(A[i] == B[i]) ans[A[i]] = C[i];
  }
  REP(i, M) {
    dijkstra(B[i]);
    chmin(ans[A[i]], d[A[i]] + C[i]);
  }
  REP(i, N) {
    if(ans[i] == INF) cout << -1 << endl;
    else cout << ans[i] << endl;
  }
}