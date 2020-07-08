#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
  return string(1, val);
}
int char_to_int(char val) {
  return val - '0';
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
int vector_finder(std::vector<ll> vec, int number) {
  auto itr = std::find(vec.begin(), vec.end(), number);
  size_t index = std::distance( vec.begin(), itr );
  if (index != vec.size()) { // 発見できたとき
    return 1;
  }
  else { // 発見できなかったとき
    return 0;
  }
}

const int limit = 100010;
using edge = struct {int to; ll cost;}; // 重み付き木を作る場合の定石
vector<edge> tree[limit];
ll depth[limit];
void dfs(int v, int p, ll d) {
  depth[v] = d;
  for(auto &e : tree[v]) {
    if(e.to == p) continue; // 親しかいなくなった場合、探索終了
    dfs(e.to, v, d + e.cost);
  }
}

int main() {
  int N; cin >> N;
  for(int i = 0; i < N - 1; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    tree[a].push_back({b, c});
    tree[b].push_back({a, c});
  }
  int Q, K; cin >> Q >> K;
  vector<ll> x(Q), y(Q); REP(i, Q) cin >> x[i] >> y[i];

  dfs(K - 1, -1, 0);

  for(int i = 0; i < Q; ++i) {
    cout << depth[x[i] - 1] + depth[y[i] - 1] << endl;
  }
}