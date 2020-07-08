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

int main() {
  int N; cin >> N;
  vector<int> x(N - 1), y(N - 1); REP(i, N - 1) cin >> x[i] >> y[i];
  int Q; cin >> Q;
  vector<int> a(Q), b(Q); REP(i, Q) cin >> a[i] >> b[i];
  vector<vector<int>> tree(N + 1);
  REP(i, N - 1) {
    tree[x[i]].push_back(y[i]);
    tree[y[i]].push_back(x[i]);
  }
  REP(k, Q) {
    int ans = 0;
    vector<int> flag(N + 1, 0);
    queue<pair<int, int>> q; q.push(make_pair(a[k], 0));
    while(!q.empty()) {
      auto tmp = q.front(); q.pop();
      flag[tmp.first] = 1;
      if(tmp.first == b[k]) {
        ans = tmp.second;
        break;
      }
      for(int i = 0; i < tree[tmp.first].size(); ++i) {
        if(flag[tree[tmp.first][i]] == 1) continue;
        q.push(make_pair(tree[tmp.first][i], tmp.second + 1));
      }
    }
    cout << ans + 1 << endl;
  }
}