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

int main() {
  int N, M; cin >> N >> M;
  vector<ll> A(M), B(M); vector<char> C(M); REP(i, M) cin >> A[i] >> B[i] >> C[i];
  // 1とNから同時にDFSする

  // 元のグラフを構築する
  vector<vector<pair<ll, ll>>> tree(N + 10);
  REP(i, M) {
    --A[i]; --B[i];
    tree[A[i]].emplace_back(B[i], C[i]);
    tree[B[i]].emplace_back(A[i], C[i]);
  }

  // 2乗グラフの構築をする
  vector<vector<vector<pair<ll, ll>>>> tree2(N + 10, vector<vector<pair<ll, ll>>>(N + 10));
  REP(ai, N) {
    REP(bj, N) {
      for(auto eci : tree[ai]) {
        int ei, ci;
        tie(ei, ci) = eci;

        for(auto ecj : tree[bj]) {
          int ej, cj;
          tie(ej, cj) = ecj;

          if(ci == cj) {
            tree2[ai][bj].emplace_back(ei, ej);
            tree2[ei][ej].emplace_back(ai, bj);
          }
        }
      }
    }
  }

  // BFSする
  const ll INF = 1e18;
  ll ans = INF;
  vector<vector<ll>> used(N, vector<ll>(N));
  queue<tuple<ll, ll, ll>> q;
  q.emplace(0, N - 1, 0);
  while(!q.empty()) {
    ll x, y, cost;
    tie(x, y, cost) = q.front();
    q.pop();

    if(x == y) ans = min(ans, 2 * cost);

    for(auto yi : tree[x]) {
      if(y == yi.first) {
        ans = min(ans, 2 * cost + 1);
      }
    }

    for(auto xyi : tree2[x][y]) {
      int xi, yi;
      tie(xi, yi) = xyi;

      if(used[xi][yi] == 1) continue;
      used[xi][yi] = 1;
      q.emplace(xi, yi, cost + 1);
    }
  }
  if(ans == INF) ans = -1;
  cout << ans << endl;
}