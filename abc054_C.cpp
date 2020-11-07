#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using P = pair<ll, ll>;
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
struct edge {
  ll to, cost;
};

int main() {
  int N, M; cin >> N >> M;
  vector<vector<int>> tree(N + 1);
  REP(i, M) {
    int a, b; cin >> a >> b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  REP(i, N + 1) sort(all(tree[i]));
  vector<int> array(N); REP(i, N) array[i] = (i + 1);
  int ans = 0;
  do{
    if(array[0] != 1) continue;
    bool flag = true;
    for(int i = 0; i < array.size() - 1; ++i){
      if(!binary_search(all(tree[array[i]]), array[i + 1])) {
        flag = false;
        break;
      }
    }
    if(flag) ans++;
  } while(next_permutation(all(array)));
  cout << ans << endl;
}