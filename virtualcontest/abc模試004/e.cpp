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

vector<bool> flag;
vector<int> ans;
vector<vector<int>> tree;
int N, K;
const ll MOD = pow(10, 9) + 7;

void dfs(int start, int p, int dist) {
  if(start == p) {
    REP(i, N + 1) {
      flag[i] = false;
    }
  }
  flag[p] = true;
  if(dist == 3) return; // 距離が2ならそれ以上探索しない
  if(dist != 0) {
    if(ans[p] != pow(10, 9)) ans[start] = min(ans[start], max(ans[p] - 1, 1));
  }
  for(int i = 0; i < tree[p].size(); ++i) {
    if(flag[tree[p][i]] == true) continue;
    dfs(start, tree[p][i], dist + 1);
  }
}

int main() {
  cin >> N >> K;
  tree.resize(N + 1);
  ans.resize(N + 1, pow(10, 9));
  flag.resize(N + 1, false);
  REP(i, N - 1) {
    int a, b; cin >> a >> b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }

  // DFS
  ans[1] = K;
  for(int i = 1; i <= N; ++i) {
    dfs(i, i, 0);
  }

  // 答え計算
  ll res = 1;
  REP(i, N + 1) {
    if(i == 0) continue;
    res *= ans[i];
    res %= MOD;
  }
  cout << res << endl;
}