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

struct UnionFind {
  vector<int> par; // 親の番号

  // n要素で初期化する
  UnionFind(int N) : par(N) {
    for(int i = 0; i < N; ++i) par[i] = i;
  }

  // 木の根を求める
  int root(int x) {
    if(par[x] == x) {
      return x; // 根
    } else {
      return par[x] = root(par[x]); // 経路圧縮(根っこを再帰で探る)    
    }
  }

  void unite(int x, int y) { // xとyの木を併合
    int rx = root(x);
    int ry = root(y);
    if(rx == ry) return; // xとyの根が同じ場合はすでに併合している
    par[rx] = ry;
  }

  bool same(int x, int y) { // x と y が同じ集合に属するか否か
    return root(x) == root(y);
  }

  int size(int x) {
    return par[root(x)];
  }
};

int main() {
  int N, M; cin >> N >> M;
  vector<int> A(M), B(M); REP(i, M) cin >> A[i] >> B[i];
  UnionFind uf(N);
  ll ans = N * (N - 1) / 2;
  vector<ll> res;
  for(int i = M - 1; i >= 0; --i) {
    res.push_back(ans);
    if(uf.same(A[i] - 1, B[i] - 1)) continue;
    ll sa = uf.size(A[i]); ll sb = uf.size(B[i]);
    ans = ans - sa * sb;
    uf.unite(A[i] - 1, B[i] - 1);
  }
  for(int i = 0; i < M; ++i) {
    cout << res[i] << endl;
  }
}