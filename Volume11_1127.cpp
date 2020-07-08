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
    int from, to; // クラスカル法に限って、fromもedgeに含めるといい
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
template<typename T>
T kruskal(vector<edge<T>> &edges, int V) {
    sort(edges.begin(), edges.end(), [](const edge<T> &a, const edge<T> &b) {
        return a.cost < b.cost;
    });
    UnionFind unionFind(V);
    T res = 0;
    for (edge<T> &e: edges) {
        if (unionFind.merge(e.to, e.from)) {
            res += e.cost;
        }
    }
    return res;
}
int n;
vector<double> x, y, z, r;
int main() {
  vector<double> ans;
  while(true) {
    cin >> n;
    if(n == 0) break;
    x.resize(n); y.resize(n); z.resize(n); r.resize(n);
    REP(i, n) {
      cin >> x[i] >> y[i] >> z[i] >> r[i];
    }
    vector<vector<double>> cost(n, vector<double>(n, 0.0));
    for(int i = 0; i < n; ++i) {
      for(int k = i; k < n; ++k) {
        if(i == k) continue;
        double line = sqrt(pow(x[i] - x[k], 2) + pow(y[i] - y[k], 2) + pow(z[i] - z[k], 2)) - r[i] - r[k];
        if(0 <= line) cost[i][k] = line;
        else cost[i][k] = 0;
      }
    }
    vector<edge<double>> tree;
    for(int i = 0; i < n; ++i) {
      for(int k = i; k < n; ++k) {
        edge<double> tmp; tmp.from = i; tmp.to = k; tmp.cost = cost[i][k];
        tree.push_back(tmp);
      }
    }
    ans.push_back(kruskal(tree, n));
  }
  REP(i, ans.size()) {
    cout << fixed << setprecision(3) << ans[i] << endl;
  }
}