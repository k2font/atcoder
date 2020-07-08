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

int n, x; 
vector<int> h;
vector<bool> flag;
vector<vector<int>> tree;
int dfs(int p, int chd) {
  int ans = 0;
  for(int k = 0; k < tree[chd].size(); ++k) {
    if(p == tree[chd][k]) continue;
    int res = dfs(chd, tree[chd][k]);
    //cout << res << endl;

    //cout << "tree: " << tree[chd][k] << endl;
    if(res > 0) ans += res + 2;
    else if(h[tree[chd][k] - 1] == 1) ans += 2;
  }
  return ans;
}

int main() {
  cin >> n; cin >> x;
  h.resize(n); REP(i, n) cin >> h[i];
  tree.resize(n + 1);
  REP(i, n - 1) {
    int a, b; cin >> a >> b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  int ans = dfs(-1, x);
  cout << ans << endl;
}