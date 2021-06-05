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
  int N, K; cin >> N >> K;
  string S; cin >> S;

  // 前処理
  // あるインデックスの右にある文字cの中で最も左側にあるインデックスを格納しておく
  vector<vector<int>> v(N + 1, vector<int>(26, 0));
  REP(i, 26) v[N][i] = N;
  for(int i = N - 1; i >= 0; --i) {
    REP(k, 26) {
      if((int)(S[i] - 'a') == k) {
        v[i][k] = i;
      } else {
        v[i][k] = v[i + 1][k];
      }
    }
  }

  // 1文字ずつ貪欲に決定する
  string ans = "";
  int c = 0;
  REP(i, K + 1) {
    if(i == 0) continue;
    REP(k, 26) {
      int vPos = v[c][k]; // その文字が今見ているインデックスより右のどの場所に存在するか？
      int maxn = (N - vPos - 1) + i; // そのインデックスより右の文字を使って残り作れる文字列の長さ
      if(maxn >= K) {
        ans += (char)('a' + k); // 条件を満たしていれば付け足す
        c = vPos + 1;
        break;
      }
    }
  }
  cout << ans << endl;
}