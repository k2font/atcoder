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

// UnionFindを示す構造体
struct UnionFind {
  vector<int> par; // 親の番号

  // n要素で初期化する
  // 問題のindexによっては、添字が変化する可能性がある
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
};

int main() {
  int n, q; cin >> n >> q;
  UnionFind uf(n);

  REP(i, q) {
    int a, b, c; cin >> a >> b >> c;
    if(a == 0) {
      uf.unite(b, c);
    } else if(a == 1) {
      int ans = -1;
      if(uf.same(b, c)) ans = 1;
      else ans = 0;
      cout << ans << endl;
    }
  }
}
