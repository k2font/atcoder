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
int vector_finder(std::vector<int> vec, int number) {
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
  vector<string> S(H);
  REP(i, H) {
    cin >> S[i];
  }

  int cnt = 0;
  int max_n = 0;
  int max_idx = 0;
  for(int i = 0; i < H; ++i) {
    int tmp = 0;
    for(int k = 0; k < W; ++k) {
      if(S.at(i).at(k) == '1') {
        cnt++;
        tmp++;
      }
    }
    if(max_n < tmp) {
      max_n = tmp;
      max_idx = i;
    }
  }

  

  if(cnt <= K) cout << ans << endl;
}
