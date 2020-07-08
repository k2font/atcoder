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
    vector<int> par;
    
    UnionFind(int n) : par(n, -1) { }

    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }
    
    bool issame(int x, int y) {
        return root(x) == root(y);
    }
    
    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    
    int size(int x) {
        return -par[root(x)];
    }
};

int main() {
  int N, M, K; cin >> N >> M >> K;
  vector<int> ans(N + 1, 0);

  vector<int> A(M), B(M);
  REP(i, M) {
    cin >> A[i] >> B[i];
    ans[A[i]]++; ans[B[i]]++;
  }

  UnionFind uf(N + 1);
  REP(i, M) uf.merge(A[i], B[i]);

  vector<int> C(K), D(K);
  REP(i, K) {
    cin >> C[i] >> D[i];
    // もしブロック関係が同じグループ下に存在しなければ、「友達候補」の候補に入らない
    if(!uf.issame(C[i], D[i])) continue;
    ans[C[i]]++; ans[D[i]]++;
  }

  for(int i = 1; i <= N; ++i) {
    cout << uf.size(i) - ans[i] - 1 << " ";
  }
  cout << endl;
}