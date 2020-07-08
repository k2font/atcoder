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
struct edge {
    ll to, cost;
};

int N;
vector<vector<edge>> tree;
vector<int> ans;
vector<bool> flag;
void dfs(int i) {
  flag[i] = true;
  for(int k = 0; k < tree[i].size(); ++k) {
    if(flag[tree[i][k].to] == false) {
      if(tree[i][k].cost % 2 == 0) {
        ans[tree[i][k].to] = ans[i];
      } else {
        ans[tree[i][k].to] = 1 - ans[i];
      }
      dfs(tree[i][k].to);
    }
  }
}

int main() {
  cin >> N; tree.resize(N + 1); ans.resize(N + 1); flag.resize(N + 1, false);
  REP(i, N - 1) {
    ll a, b, c; cin >> a >> b >> c;
    edge e1 = {b, c};
    tree[a].push_back(e1);
    edge e2 = {a, c};
    tree[b].push_back(e2);
  }
  dfs(1);
  for(int i = 1; i <= N; ++i) {
    cout << ans[i] << endl;
  }
}