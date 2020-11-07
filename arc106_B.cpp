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
  ll N, M; cin >> N >> M;
  vector<ll> a(N), b(N), c(M), d(M);
  REP(i, N) cin >> a[i];
  REP(i, N) cin >> b[i];
  REP(i, M) cin >> c[i] >> d[i];
  vector<vector<ll>> tree(N);
  REP(i, M) {
    c[i]--; d[i]--;
    tree[c[i]].push_back(d[i]);
    tree[d[i]].push_back(c[i]);
  }
  vector<bool> ans(N, false);
  REP(i, N) {
    ll tmp_a = 0; ll tmp_b = 0;
    queue<ll> q; q.push(i);
    while(!q.empty()) {
      auto x = q.front(); q.pop();
      if(ans[x] == true) continue;
      ans[x] = true; tmp_a += a[x]; tmp_b += b[x];
      for(int k = 0; k < tree[x].size(); ++k) {
        q.push(tree[x][k]);
      }
    }
    if(tmp_a != tmp_b) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}