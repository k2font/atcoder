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

int main() {
  int N; cin >> N;
  vector<int> B(N - 1); REP(i, N - 1) cin >> B[i];
  vector<ll> res(N, -1); // 0-indexed 給料
  vector<vector<ll>> tree(N);
  REP(i, N - 1) {
    B[i]--; // 0-indexed
    tree[B[i]].push_back(i + 1);
    tree[i + 1].push_back(B[i]);
  }
  REP(i, N) {
    if(tree[i].size() == 1 && i != 0) res[i] = 1;
  }
  for(int i = N - 1; i >= 0; --i) {
    if(res[i] == -1) {
      vector<int> p; p.clear();
      REP(k, tree[i].size()) {
        int child = tree[i][k];
        int tmp = res[child];
        // cout << i << " " << tmp << endl;
        if(tmp < 0) continue;
        p.push_back(tmp);
      }
      // cout << i << " 配列の結果: " << *max_element(all(p)) << " " << *min_element(all(p)) << " " << *max_element(all(p)) + *min_element(all(p)) + 1 << endl;
      res[i] = *max_element(all(p)) + *min_element(all(p)) + 1;
    }
  }
  cout << res[0] << endl;
}
