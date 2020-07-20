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
  int H, W, K; cin >> H >> W >> K;
  vector<string> c(H); REP(i, H) cin >> c[i];
  vector<string> copy(H); copy = c;
  int ans = 0;
  for(int bit1 = 0; bit1 < (1 << H); ++bit1) {
    for(int bit2 = 0; bit2 < (1 << W); ++bit2) {

      for(int i = 0; i < H; ++i) {
        if(bit1 & (1 << i)) {
          REP(k, W) {
            copy[i][k] = '@';
          }
        }
      }

      for(int i = 0; i < W; ++i) {
        if(bit2 & (1 << i)) {
          REP(k, H) {
            copy[k][i] = '@';
          }
        }
      }

      int tmp = 0;
      REP(i, H) {
        REP(k, W) {
          if(copy[i][k] == '#') tmp++;
        }
      }
      if(tmp == K) ans++;
      copy = c;
    }
  }
  cout << ans << endl;
}