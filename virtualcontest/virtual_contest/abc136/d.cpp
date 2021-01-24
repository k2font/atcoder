#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using P = pair<ll, ll>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};
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
  int N; cin >> N;
  vector<ll> a(N - 1), b(N - 1); REP(i, N - 1) cin >> a[i] >> b[i];
  int Q; cin >> Q;
  vector<ll> t(Q), e(Q), x(Q); REP(i, Q) cin >> t[i] >> e[i] >> x[i];
  vector<vector<ll>> tree(N);
  REP(i, N - 1) {
    --a[i]; --b[i];
    tree[a[i]].push_back(b[i]);
    tree[b[i]].push_back(a[i]);
  }

  vector<ll> depth(N, 0);
  // BFSで根からの深さを計算しておく
  queue<ll> q; q.push(0); // 0から足し合わせる
  vector<bool> f(N, false);
  while(!q.empty()) {
    auto x = q.front(); q.pop();
    f[x] = true;
    for(int i = 0; i < tree[x].size(); ++i) {
      if(f[tree[x][i]] == true) continue;
      depth[tree[x][i]] = depth[x] + 1;
      q.push(tree[x][i]);
    }
  }

  vector<ll> ans(N, 0);
  // 0を根と定める
  // まずはいもす法の下準備をする
  REP(i, Q) {
    --e[i];
    if(t[i] == 1) {
      // 深い方へ行く場合
      if(depth[a[e[i]]] < depth[b[e[i]]]) {
        ans[b[e[i]]] -= x[i];
        ans[0] += x[i];
      } else {
        ans[a[e[i]]] += x[i];
      }
    } else if(t[i] == 2) {
      // 深い方へ行く場合
      if(depth[a[e[i]]] < depth[b[e[i]]]) {
        ans[b[e[i]]] += x[i];
      } else {
        ans[a[e[i]]] -= x[i];
        ans[0] += x[i];
      }
    }
  }

  // 最後に根から葉まで足し合わせる
  vector<bool> f2(N, false);
  queue<ll> q2; q2.push(0); // 0から足し合わせる
  while(!q2.empty()) {
    auto x = q2.front(); q2.pop();
    f2[x] = true;
    for(int i = 0; i < tree[x].size(); ++i) {
      if(f2[tree[x][i]] == true) continue;
      ans[tree[x][i]] += ans[x];
      q2.push(tree[x][i]);
    }
  }
  REP(i, N) cout << ans[i] << endl;
}