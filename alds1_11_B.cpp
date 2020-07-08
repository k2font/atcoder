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

int n;
vector<int> u, k;
vector<int> d, f;
vector<vector<int>> v;

int a = 0;
void dfs(int _n) {
  a++;
  d[_n] = a;
  for(int i = 0; i < k[_n]; ++i) {
    if(d[v[_n][i] - 1] != 0) {
      continue;
    }
    dfs(v[_n][i] - 1);
  }
  a++;
  f[_n] = a;
}

int main() {
  cin >> n;
  u.resize(n); k.resize(n);
  d.assign(n, 0); f.assign(n, 0);
  v.resize(n);
  REP(i, n) {
    cin >> u[i] >> k[i];
    REP(m, k[i]) {
      int a; cin >> a;
      v[i].push_back(a);
    }
  }
  for(int i = 0; i < n; ++i) {
    if(d[i] == 0) dfs(i);
  }
  REP(i, n) {
    cout << u[i] << " " << d[i] << " " << f[i] << endl;
  }
}
