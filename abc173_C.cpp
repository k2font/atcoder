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
  int H, W; cin >> H >> W;
  int K; cin >> K;
  vector<string> c(H); REP(i, H) cin >> c[i];
  vector<string> cp(H);
  REP(i, H) {
    cp[i] = c[i];
  }
  int ans = 0;
  for(int a = 0; a < (1 << H); ++a) {
    for(int b = 0; b < (1 << W); ++b) { // cpを赤で埋める
      for(int i = 0; i < H; ++i) {
        if(a & (1 << i)) {
          REP(k, W) {
            cp[i][k] = '@';
          }
        }
      }
      for(int i = 0; i < W; ++i) {
        if(b & (1 << i)) {
          REP(k, H) {
            cp[k][i] = '@';
          }
        }
      }
      int tmp = 0;
      REP(i, H) { // #の数を数える
        REP(k, W) {
          if(cp[i][k] == '#') tmp++;
        }
        if(i == H - 1) {
          if(tmp == K) {
            ans++;
          }
        }
      }
      REP(i, H) { // もとに戻す
        REP(k, W) {
          cp[i][k] = c[i][k];
        }
      }
    }
  }
  cout << ans << endl;
}