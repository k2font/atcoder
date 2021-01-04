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
  int T; cin >> T;
  // t個のテストケースに答える
  REP(i, T) {
    ll N, S, K; cin >> N >> S >> K;
    // -1かどうか判定

    // (N - S)がKで割り切れる時
    if((N - S) % K == 0) cout << (N - S) / K << endl;
    else { // そうじゃない時はシミュレーション
      ll ans = (N - S) / K;
      ll a = (N - S) % K;
      ans += (N - S) / K * ((N - S) + (a));
      // bool f = false;
      // int c = 0;
      // while(true) {
      //   c++;
      //   ll b = N + a;
      //   if(b % K == 0) {
      //     ans += b / K;
      //     break;
      //   } else {
      //     if(b % K == a) {
      //       cout << -1 << endl;
      //       f = true;
      //       break;
      //     }
      //     a = b % K;
      //     ans += b / K;
      //   }
      // }
      // if(f == true) continue;
      cout << ans << endl;
    }
  }
}
