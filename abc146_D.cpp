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
vector<vector<pair<int, int>>> tree;
vector<bool> flag;
vector<int> ans;
void dfs(int i, int p, int e) {
  flag[i] = true;
  for(int k = 0; k < tree[i].size(); ++k) {
    if(flag[tree[i][k].first] == true) continue;
    if(p == e) {
      ans[tree[i][k].second + 1] = e + 1;
      dfs(tree[i][k].first, e + 1, 1);
      e += 2;
    } else {
      ans[tree[i][k].second + 1] = e;
      dfs(tree[i][k].first, e, 1);
      e++;
    }
  }
}

int main() {
  cin >> N;
  tree.resize(N + 1); ans.resize(N + 1, 0); flag.resize(N + 1, false);
  REP(i, N - 1) {
    int a, b; cin >> a >> b;
    tree[a].push_back(make_pair(b, i));
    tree[b].push_back(make_pair(a, i));
  }
  REP(i, N + 1) {
    sort(all(tree[i]));
  }
  dfs(1, 0, 1);
  map<int, int> m;
  for(int i = 1; i < N; ++i) m[ans[i]]++;
  cout << m.size() << endl;
  for(int i = 1; i < N; ++i) {
    cout << ans[i] << endl;
  }
}