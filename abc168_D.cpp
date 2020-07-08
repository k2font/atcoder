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

int N, M; 
const int limit = 100010;
vector<vector<ll>> graph;
vector<pair<ll, ll>> depth;

void dfs(int v, int p, ll path) {
  if(depth[v].first > path) depth[v] = make_pair(path, p);
  for(auto &e : graph[v]) {
    if(depth[e].first <= path + 1) continue;
    if(path + 1 >= N) continue;
    dfs(e, v, path + 1);
  }
}

int main() {
  cin >> N >> M;
  graph.resize(N + 1);
  depth.assign(limit, make_pair(-1, 0));
  REP(i, M) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  queue<int> que;
  que.push(1);
  depth[0] = make_pair(0, 0);
  while (!que.empty()) {
      int v = que.front(); que.pop();
      for (auto nv : graph[v]) {
          if (depth[nv].first == -1) {
              depth[nv] = make_pair(depth[v].first + 1, v);
              que.push(nv);
          }
      }
  }

  // dfs(1, -1, 0);
  cout << "Yes" << endl;
  for(int i = 2; i <= N; ++i) {
    cout << depth[i].second << endl;
  }
}
