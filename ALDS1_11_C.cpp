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
  int n; cin >> n;
  vector<int> u(n), k(n); 
  vector<vector<int>> v(n);
  REP(i, n) {
    cin >> u[i] >> k[i];
    REP(m, k[i]) {
      int p; cin >> p;
      v[i].push_back(p);
    }
  }

  vector<int> ans; ans.assign(n + 1, -1);
  queue<int> Q;
  Q.push(1); ans[Q.front()] = 0;
  while(!Q.empty()) {
    int i = Q.front();
    Q.pop();
    for(int m = 0; m < k[i - 1]; ++m) {
      if(ans[v[i - 1][m]] == -1) {
        Q.push(v[i - 1][m]);
        ans[v[i - 1][m]] = ans[i] + 1;
      }
    }
  }
  for(int i = 1; i < n + 1; ++i) {
    cout << i << " " << ans[i] << endl;
  }
}
