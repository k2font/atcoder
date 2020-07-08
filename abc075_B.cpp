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

const int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int dy[8] = {1, 1, 1, 0, -1, -1, -1, 0};

int main() {
    int H, W; cin >> H >> W;
    vector<string> S(H); REP(i, H) cin >> S[i];
    for(int i = 0; i < H; ++i) {
        for(int k = 0; k < W; ++k) {
            if(S[i][k] == '#') cout << '#';
            else {
                int tmp = 0;
                for(int m = 0; m < 8; ++m) {
                    if(i + dx[m] < 0 || i + dx[m] >= H) continue;
                    if(k + dy[m] < 0 || k + dy[m] >= W) continue;
                    if(S[i + dx[m]][k + dy[m]] == '#') tmp++;
                }
                cout << tmp;
            }
        }
        cout << endl;
    }
}