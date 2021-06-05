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
  ll N; cin >> N;
  vector<ll> A(N - 1), B(N - 1); 
  REP(i, N - 1) {
    cin >> A[i] >> B[i]; A[i]--; B[i]--;
  }
  // 隣接リストの構築
  vector<vector<ll>> tree(N);
  REP(i, N - 1) {
    tree[A[i]].push_back(B[i]);
    tree[B[i]].push_back(A[i]);
  }
  ll Q; cin >> Q;
  vector<ll> K(Q);
  vector<vector<ll>> V(Q);
  REP(i, Q) {
    cin >> K[i];
    REP(k, K[i]) {
      ll tmp; cin >> tmp; tmp--;
      V[i].push_back(tmp);
    }
  }
  // 幅優先探索を繰り返して、通った辺の本数をカウントする
  REP(i, Q) {
    ll ans = 0;
    // 予め残すノードのみフラグとして残しておく
    vector<ll> l(N + 1, 0);
    REP(k, K[i]) l[V[i][k]]++;
    // 幅優先探索
    // 今回は、V[Q][0]を開始地点とする
    queue<pair<ll, ll>> q; q.emplace(V[i][0], 0); // (今いるノード, 通った辺)
    vector<ll> f(N + 1, 0); // 0の場合はまだ到達していない
    while(!q.empty()) {
      auto x = q.front(); q.pop();
      f[x.first] = 1;
      if(x.first == V[i][1]) { // もしそれが残す頂点であれば...
        cout << x.second << endl; break;
      }
      for(int k = 0; k < tree[x.first].size(); ++k) {
        if(f[tree[x.first][k]] == 1) continue;
        q.emplace(tree[x.first][k], x.second + 1);
      }
    }
  }
}