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
struct edge {
  ll to, cost;
};

int main() {
  int N; cin >> N;
  vector<int> B(N);
  vector<vector<int>> P(N, vector<int>(11));
  REP(i, N) {
    unsigned int b = 0;
    REP(k, 10) {
      int p; cin >> p;
      if(p == 1) b |= (1 << k); // 1つ1つがORを表す
    }
    B[i] = b;
  }
  REP(i, N) {
    REP(k, 11) {
      cin >> P[i][k];
    }
  }
  ll ans = -pow(10,17);
  for(int bit = 0; bit < (1 << 10); ++bit) {
    if(bit == 0) continue;
    unsigned int c;
    ll res = 0;
    for(int i = 0; i < N; ++i) {
      int cnt = 0;
      c = (bit & B[i]);
      cnt = __builtin_popcount( c );
      res += P[i][cnt];
    }
    if(ans < res) ans = res;
  }
  cout << ans << endl;
}