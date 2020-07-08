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

int N, Q; 
vector<int> a, b; 
vector<int> p, x;
vector<vector<int>> tree;
vector<ll> cnt;
vector<bool> flag;
void dfs(int _p, int count) {
  if(_p != 1) cnt[_p] += count;
  flag[_p] = true;
  for(int i = 0; i < tree[_p].size(); ++i) {
    if(flag[tree[_p][i]] == true) continue;
    dfs(tree[_p][i], cnt[_p]);
  }
}

int main() {
  cin >> N >> Q;
  tree.resize(N + 1);
  a.resize(N - 1); b.resize(N - 1);
  REP(i, N - 1) {
    int A, B; cin >> A >> B;
    tree[A].push_back(B);
    tree[B].push_back(A);
  }
  p.resize(Q); x.resize(Q); REP(i, Q) cin >> p[i] >> x[i];
  cnt.resize(N + 1);
  for(int i = 0; i < Q; ++i) {
    cnt[p[i]] += x[i];
  }
  flag.assign(N + 1, false);
  dfs(1, cnt[1]);
  for(int i = 1; i <= N; ++i) {
    cout << cnt[i] << " ";
  }
  cout << endl;
}
