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
template <class T> T up(T a, T div) { return (a + div - 1) / div; }

vector<vector<ll>> tree;
// vector<vector<bool>> isGoing;
vector<vector<bool>> visited;
void dfs(ll pos, ll start) {
  if(visited[start][pos] == true) return;
  visited[start][pos] = true;
  for(int i = 0; i < tree[pos].size(); ++i) {
    dfs(tree[pos][i], start);
  }
}

int main() {
  int N, M; cin >> N >> M;
  vector<ll> A(M), B(M); REP(i, M) cin >> A[i] >> B[i];
  tree.resize(N);
  REP(i, M) {
    --A[i]; --B[i];
    tree[A[i]].push_back(B[i]);
  }
  // // あるノードからあるノードまで行けるか？
  // isGoing.resize(N, vector<bool>(N, false));
  // REP(i, N) {
  //   isGoing[i][i] = true; // 自己ループは行ける
  // }

  // // 全ノードを試す
  // REP(i, N) {
  //   // DFSする
  //   visited.resize(N, false);
  //   dfs(i);
  // }

  visited.resize(N, vector<bool>(N, false));

  REP(i, N) {
    dfs(i, i);
  }

  ll ans = 0;
  REP(i, N) {
    REP(k, N) {
      if(visited[i][k] == true) ans++;
    }
  }
  cout << ans << endl;
}