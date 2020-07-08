#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using P = pair<int, int>;
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
template<typename T>
struct edge {
    int from, to;
    T cost;
};
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
int M, K;
template<typename T>
T kruskal(vector<edge<T>> &edges, int V) {
    sort(edges.begin(), edges.end(), [](const edge<T> &a, const edge<T> &b) {
      return a.cost < b.cost;
    });
    UnionFind unionFind(V);
    T res = 0;
    vector<int> tmp;
    for (edge<T> &e: edges) {
      if (unionFind.merge(e.from - 1, e.to - 1)) {
        res += e.cost;
        tmp.push_back(e.cost);
      }
    }
    sort(all(tmp));
    int p = tmp.size() - 1;
    REP(i, K - 1) {
      res -= tmp[p];
      p--;
    }
    return res;
}

int main() {
  int N; cin >> N >> M >> K;
  vector<edge<int>> tree(M);
  REP(i, M) {
    int a, b, c; cin >> a >> b >> c;
    tree[i].from = a;
    tree[i].to = b;
    tree[i].cost = c;
  }
  cout << kruskal(tree, N) << endl;
}