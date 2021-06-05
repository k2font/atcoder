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

vector<vector<ll>> tree, l;
vector<ll> in, out, depth; int timer = 0;
void dfs(ll n) {
  timer++;
  in[n] = timer; // 入る時間をメモ
  l[depth[n]].push_back(in[n]);
  for(int i = 0; i < tree[n].size(); ++i) {
    if(n > tree[n][i]) continue;
    depth[tree[n][i]] = depth[n] + 1;
    dfs(tree[n][i]);
  }
  timer++;
  out[n] = timer;
}

int main() {
  ll N; cin >> N;
  vector<ll> P(N - 1);
  REP(i, N - 1) {
    cin >> P[i]; --P[i];
  }
  ll Q; cin >> Q;
  vector<ll> U(Q), D(Q); REP(i, Q) cin >> U[i] >> D[i];
  // 木の構築
  in.resize(N); out.resize(N); depth.resize(N);
  tree.resize(N); l.resize(N);
  REP(i, N - 1) {
    tree[P[i]].push_back(i + 1);
    tree[i + 1].push_back(P[i]);
  }
  // 根から各頂点までの距離を前計算する
  // DFS
  in.resize(N, 0); out.resize(N, 0); // 根っこは距離0
  dfs(0); // 0番目の根っこからスタート、根からの距離は0

  // あと1つ工夫が必要。
  // 経路の中にUは含まれているかを前処理しないとTLEする

  // 結構いい線行ってた
  
  // 各クエリを処理する
  REP(i, Q) {
    const auto& v = l[D[i]];
    U[i]--;
    cout << lower_bound(v.cbegin(), v.cend(), out[U[i]]) - lower_bound(v.cbegin(), v.cend(), in[U[i]]) << endl;
  }
}