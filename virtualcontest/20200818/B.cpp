#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using P = pair<ll, ll>;
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
struct edge {
  ll to, cost;
};

int main() {
  ll N, Q; cin >> N >> Q;
  vector<ll> a(N - 1), b(N - 1); REP(i, N - 1) cin >> a[i] >> b[i];
  vector<ll> p(Q), x(Q); REP(i, Q) cin >> p[i] >> x[i];
  vector<vector<ll>> tree(N);
  REP(i, N - 1) {
    a[i]--; b[i]--;
    tree[a[i]].push_back(b[i]);
    tree[b[i]].push_back(a[i]);
  }
  vector<ll> ans(N, 0);
  // 部分木の根に答えを足す
  REP(i, Q) {
    p[i]--; ans[p[i]] += x[i];
  }
  queue<pair<ll, ll>> q; q.push(P(0, ans[0])); // P(親の頂点番号, その頂点が持つカウンタの値)
  vector<bool> flag(N, false); flag[0] = true;
  while(!q.empty()) {
    auto x = q.front(); q.pop();
    int p = x.first; int a = x.second;
    for(int i = 0; i < tree[p].size(); ++i) {
      if(flag[tree[p][i]]) continue;
      ans[tree[p][i]] += a;
      q.push(P(tree[p][i], ans[tree[p][i]]));
      flag[tree[p][i]] = true;
    }
  }
  REP(i, N) {
    cout << ans[i] << " ";
  }
  cout << endl;
}