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
char inverse_char(char c) {
  if(isupper(c)) return tolower(c);
  else return toupper(c);
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
  int N, M; cin >> N >> M;
  vector<ll> u(M), v(M), c(M);
  REP(i, M) {
    cin >> u[i] >> v[i] >> c[i];
    u[i]--; v[i]--;
  }
  vector<int> ans(N, -1);
  vector<vector< pair<ll, ll> >> tree(N);
  REP(i, M) {
    tree[u[i]].push_back(P(v[i], c[i]));
    tree[v[i]].push_back(P(u[i], c[i]));
  }
  queue<int> q; q.push(0);
  ans[0] = 1;
  while(!q.empty()) {
    auto parent = q.front(); q.pop();
    for(int i = 0; i < tree[parent].size(); ++i) {
      int child = tree[parent][i].first;
      int tag = tree[parent][i].second;
      if(ans[child] != -1) continue;
      if(ans[parent] == tag) ans[child] = tag + 1;
      else ans[child] = tag;
      q.push(child);
    }
  }
  bool f = false;
  REP(i, N) {
    if(ans[i] == -1) f = true;
  }
  if(f) cout << "No" << endl;
  else {
    REP(i, N) {
      cout << ans[i] << endl;
    }
  }
}