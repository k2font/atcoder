#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using P = pair<ll, ll>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};
string char_to_string(char val) {
  return string(1, val);
}
int char_to_int(char val) {
  return val - '0';
}
char inverse_char(char c) {
  if(isupper(c)) return tolower(c);
  else return toupper(c);
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
  int N; cin >> N;
  vector<ll> A(N); REP(i, N) cin >> A[i];
  // bit全探索
  ll ans = 8e18;
  for(int bit = 0; bit < (1 << N); ++bit) { // 分ける方法を全探索。 10^6くらい
    ll tmp = 0; ll res = 0;
    int flag = 0;
    // フラグの初期化
    if(bit & (1 << 0)) { // bitが1の区間のみ取得
      // 末尾のbitが1
      flag = 1;
    } else if(bit & (0 << 0)) { // bitが0の区間のみ取得
      // 末尾のbitが0
      flag = 0;
    }
    for(int i = 0; i < N; ++i) {
      if(bit & (1 << i)) { // bitが1の区間のみ取得
        
        if(flag == 1) {
          if(tmp != 0) tmp |= A[i];
          else tmp = A[i];
        } else {
          if(res != 0) res ^= tmp;
          else res = tmp;
          tmp = A[i];
          flag = 1;
        }
      } else {
        
        if(flag == 0) {
          if(tmp != 0) tmp |= A[i];
          else tmp = A[i];
        } else {
          if(res != 0) res ^= tmp;
          else res = tmp;
          tmp = A[i];
          flag = 0;
        }
      }
      if(i == N - 1) {
        if(res != 0) res ^= tmp;
        else res = tmp;
      }
    }
    ans = min(res, ans);
  }
  cout << ans << endl;
}