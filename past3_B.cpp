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
  vector<vector<int>> S(Q);
  REP(i, Q) {
    int s; cin >> s;
    S[i].push_back(s);
    if(s == 1) {
      int t; cin >> t;
      S[i].push_back(t);
    } else {
      int t, p; cin >> t >> p;
      S[i].push_back(t);
      S[i].push_back(p);
    }
  }

  vector<ll> ans(M, N); // 問題ごとの得点
  vector<ll> par(N, 0); // 参加者ごとの現在の得点
  vector<vector<ll>> res(N);
  REP(i, Q) {
    if(S[i][0] == 1) {
      cout << par[S[i][1] - 1] << endl;
    } else if(S[i][0] == 2) {
      res[S[i][2] - 1].push_back(S[i][1]);
      par[S[i][1] - 1] += ans[S[i][2] - 1];
      REP(k, res[S[i][2] - 1].size()) {
        par[res[S[i][2] - 1][k] - 1]--;
      }
      ans[S[i][2] - 1]--;
    }
  }
}
