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

const ll INF = 1000000000001;
const ll MAX_V = 100010;
ll V, E;
vector<edge> G[MAX_V];
ll d[MAX_V]; // スタート地点から各ノードまでの最短距離

void dijkstra1(int s) {
  priority_queue<P, vector<P>, greater<P>> q;
  fill(d, d + V, INF); // dをすべてINFで埋める
  d[s] = 0; // スタート地点の重みは0
  q.push(P(0, s));
  while(!q.empty()) {
    P p = q.top(); q.pop(); // 先頭から値を取り出す
    int v = p.second; // 次の行き先
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

ll z[MAX_V]; // スタート地点から各ノードまでの最短距離
void dijkstra2(int s) {
  priority_queue<P, vector<P>, greater<P>> q;
  fill(z, z + V, INF); // dをすべてINFで埋める
  z[s] = 0; // スタート地点の重みは0
  q.push(P(0, s));
  while(!q.empty()) {
    P p = q.top(); q.pop(); // 先頭から値を取り出す
    int v = p.second; // 次の行き先
    if(z[v] < p.first) continue;

    for(int i = 0; i < G[v].size(); ++i) {
      edge e = G[v][i]; // あるノートsから伸びる全ノードを確認する
      if(z[e.to] > z[v] + e.cost) {
        z[e.to] = z[v] + e.cost;
        q.push(P(z[e.to], e.to));
      }
    }
  }
}

int main() {
  cin >> V >> E;
  vector<ll> A(E), B(E), C(E);
  REP(i, E) {
    cin >> A[i] >> B[i] >> C[i];
    --A[i]; --B[i];
  }
  REP(i, E) {
    edge e = {B[i], C[i]}; // edgeには行き先の番号とその重みを入れる
    G[A[i]].push_back(e);
    edge f = {A[i], C[i]}; // edgeには行き先の番号とその重みを入れる
    G[B[i]].push_back(f);
  }
  dijkstra1(0);
  dijkstra2(V - 1);
  for(int i = 0; i < V; ++i) {
    cout << d[i] + z[i] << endl;
  }
}