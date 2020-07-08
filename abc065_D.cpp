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
bool compare_by_a(pair<int, pair<ll, ll>> a, pair<int, pair<ll, ll>> b) {
    if(a.second.first != b.second.first){
        return a.second.first < b.second.first;
    }else{
        return a.second.second < b.second.second;
    }
}
bool compare_by_b(pair<int, pair<ll, ll>> a, pair<int, pair<ll, ll>> b) {
    if(a.second.second != b.second.second){
        return a.second.second < b.second.second;
    }else{
        return a.second.first < b.second.first;
    }
}
template<typename T>
struct edge {
    int from, to; // クラスカル法に限って、fromもedgeに含めるといい
    T cost;
};
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

int main() {
  int N; cin >> N;
  vector<pair<int, pair<ll, ll>>> p(N);
  REP(i, N) {
    ll a, b; cin >> a >> b;
    auto tmp = make_pair(i, make_pair(a, b));
    p[i] = tmp;
  }
  vector<edge<ll>> tree;
  sort(all(p), compare_by_a);
  for(int i = 0; i < N - 1; ++i) {
    ll tmp = abs(p[i].second.first - p[i + 1].second.first);
    edge<ll> res;
    res.from = p[i].first;
    res.to = p[i + 1].first;
    res.cost = tmp;
    tree.push_back(res);
  }
  sort(all(p), compare_by_b);
  for(int i = 0; i < N - 1; ++i) {
    ll tmp = abs(p[i].second.second - p[i + 1].second.second);
    edge<ll> res;
    res.from = p[i].first;
    res.to = p[i + 1].first;
    res.cost = tmp;
    tree.push_back(res);
  }
  cout << kruskal(tree, N) << endl;
}