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

struct TopologicalSort {
    vector<vector<int>> E; TopologicalSort(int N) { E.resize(N); }
    void add_edge(int a, int b) { E[a].push_back(b); }
    bool visit(int v, vector<int>& order, vector<int>& color) { color[v] = 1;
        for (int u : E[v]) { if (color[u] == 2) continue; if (color[u] == 1) return false;
        if (!visit(u, order, color)) return false; } order.push_back(v); color[v] = 2; return true; }
    bool sort(vector<int> &order) { int n = E.size(); vector<int> color(n);
        for (int u = 0; u < n; u++) if (!color[u] && !visit(u, order, color)) return false;
        reverse(order.begin(), order.end()); return true; } };

int main() {
  int N, M; cin >> N >> M;
  TopologicalSort ts(N);
  vector<vector<ll>> tree(N + 1);
  REP(i, N - 1 + M) {
    int a, b; cin >> a >> b;
    a--; b--;
    tree[a].push_back(b);
    // トポロジカルソート用配列に突っ込む
    ts.add_edge(a, b);
  }

  vector<int> ord;
  ts.sort(ord); // トポロジカルソートとその結果をordに格納する
  REP(i, ord.size()) {
    cout << ord[i] + 1 << endl;
  }

  vector<int> depth(101010);

  for(auto x : ord) {
    for(auto y : tree[x]) {
      chmax(depth[y], depth[x] + 1);
    }
  }

  vector<int> ans(101010);
  int root = ord[0];
  ans[root] = -1;
  REP(cu, N) {
    for(auto x : tree[cu]) {
      if(depth[cu] + 1 == depth[x]) ans[x] = cu;
    }
  }
  REP(i, N) {
    cout << ans[i] + 1 << endl;
  }
}