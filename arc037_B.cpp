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
vector<vector<int>> tree;
vector<bool> flag;
bool f = false;
bool dfs(int i, int b) {
  flag[i] = true;
  for(int k = 0; k < tree[i].size(); ++k) {
    if(flag[tree[i][k]] == false) {
      dfs(tree[i][k], i);
    } else if(flag[tree[i][k]] == true) {
      if(b != tree[i][k]) {
        f = true;
      }
    }
  }
  if(f == true) {
    return false;
  } else{
    return true;
  }
}

int main() {
  cin >> N >> M; tree.resize(N + 1); flag.resize(N + 1, false);
  REP(i, M) {
    int u, v; cin >> u >> v;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }

  int ans = 0;
  for(int i = 1; i <= N; ++i) {
    if(flag[i] == false) {
      f = false;
      if(dfs(i, 0) == true) {
        ans++;
      }
    }
  }
  cout << ans << endl;
}