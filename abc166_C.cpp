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
  int N, M; cin >> N >> M;
  vector<ll> H(N); REP(i, N) cin >> H[i];
  vector<vector<ll>> graph(N + 1);
  REP(i, M) {
    ll a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  vector<ll> ans(N + 1); REP(i, N + 1) ans[i] = 0;
  for(int i = 1; i <= N; ++i) {
    ll tmp = 0;
    for(int k = 0; k < graph[i].size(); ++k) {
      if(tmp < H[graph[i][k] - 1]) {
        tmp = H[graph[i][k] - 1];
      }
    }
    ans[i] = tmp;
  }
  ll res = 0;
  for(int i = 1; i <= N; ++i) {
    if(ans[i] < H[i - 1]) res++;
  }
  cout << res << endl;
}