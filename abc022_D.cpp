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

vector<vector<ll>> d;
void warshall_floyd(int n){
    for (int k = 0; k < n; ++k){
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                d[i][j] = min(d[i][j], d[i][k] + d[j][k]);
            }
        }
    }
}

int main() {
  int N, M; cin >> N >> M;
  const int INF = 1001001001;
  d.resize(N + 10, vector<ll>(N + 10));
  REP(i, N) {
    REP(k, N) {
      d[i][k] = INF;
    }
    d[i][i] = 0; // 自己ループはすべて0にする
  }
  vector<edge> tree;
  REP(i, M) {
    ll u, v, l; cin >> u >> v >> l; --u; --v;
    // TODO: 0に隣接する辺は取り除くようにする
    if(u == 0) {
      tree.push_back({v, l});
      continue;
    } else if(v == 0) {
      tree.push_back({u, l});
      continue;
    }
    d[v][u] = l; 
    d[u][v] = l;
  }
  warshall_floyd(N);

  // vとuの全組み合わせを探索し、最短経路を計算する
  ll ans = INF;
  for(auto u : tree) {
    for(auto v : tree) {
      if(u.to == v.to) continue;
      ll l = u.cost + d[u.to][v.to] + v.cost;
      ans = min(ans, l);
    }
  }
  if(ans == INF) cout << -1 << endl;
  else cout << ans << endl;
}