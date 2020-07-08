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

int main() {
  int N, M, Q; cin >> N >> M >> Q;
  vector<vector<int>> graph(N + 1);
  REP(i, M) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  vector<int> c(N); REP(i, N) cin >> c[i];
  vector<vector<int>> s(Q);
  REP(i, Q) {
    int a; cin >> a;
    s[i].push_back(a);
    if(a == 1) {
      int b; cin >> b;
      s[i].push_back(b);
    } else if(a == 2) {
      int b, c; cin >> b >> c;
      s[i].push_back(b);
      s[i].push_back(c);
    }
  }

  REP(i, Q) {
    if(s[i][0] == 1) {
      cout << c[s[i][1] - 1] << endl;
      REP(k, graph[s[i][1]].size()) {
        c[graph[s[i][1]][k] - 1] = c[s[i][1] - 1];
      }
    } else if(s[i][0] == 2) {
      cout << c[s[i][1] - 1] << endl;
      c[s[i][1] - 1] = s[i][2];
    }
  }
}
