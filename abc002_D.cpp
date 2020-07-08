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

bool check_connect(int state, vector<vector<int>> edge, int N) {
  REP(i, N) {
    // もしビットが立っていたら...
    if(state & (1 << i)) {
      // ノードiから全ノード1~Nを見て、エッジが存在するかを確認する
      REP(k, N) {
        // stateのビットが立っていたら...
        if(i == k) continue;
        if(state & (1 << k)) {
          // edgeのi番目の中にkがいなかったら...
          if(find(all(edge[i]), k) == edge[i].end()) {
            // falseを返却する
            return false;
            // なお、これは1度でもありえる場合、かならずfalseを返すようにする
          }
        }
        // なぜiとkについてstateのビットを気にする必要があるかというと、
        // 今回はbitでありうる派閥の組み合わせを管理したいから
        // ビットが立っていない部分は、派閥の組み合わせの中に存在しないものと考える
      }
    }
  }
  return true;
}

int main() {
  int N, M; cin >> N >> M;
  vector<int> x(M), y(M); REP(i, M) cin >> x[i] >> y[i], x[i]--, y[i]--;
  vector<vector<int>> tree(N);
  for(int i = 0; i < M; ++i) {
    tree[x[i]].push_back(y[i]);
    tree[y[i]].push_back(x[i]);
  }
  int ans = 0;
  // 全探索を開始
  for(int bit = 0; bit < (1 << N); ++bit) {
    if(check_connect(bit, tree, N)) ans = max(ans, __builtin_popcount(bit));
  }
  cout << ans << endl;
}