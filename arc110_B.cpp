#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using P = pair<ll, ll>;
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
struct edge {
  ll to, cost;
};

int main() {
  int N; cin >> N;
  string T; cin >> T;
  if(N == 1) {
    if(T == "0") cout << (ll)pow(10, 10) << endl;
    else cout << 2 * (ll)pow(10, 10) << endl;
    return 0;
  }
  // そのパターンが存在するかチェック
  vector<vector<char>> t(3);
  t[0] = {'1'}; t[1] = {'1'}; t[2] = {'0'};
  int s = 0;
  if(T[0] == '1' && T[1] == '1') s = 0;
  else if(T[0] == '1' && T[1] == '0') s = 1;
  else if(T[0] == '0' && T[1] == '1') s = 2;
  else {
    cout << 0 << endl;
    return 0;
  }
  REP(i, N) {
    if(T[i] == t[s][0]) {
    } else {
      cout << 0 << endl;
      return 0;
    }
    ++s;
    if(s >= 3) s = 0;
  }
  // 存在する場合は計算する
  ll a = pow(10, 10);
  ll b = 0;
  REP(i, N) {
    if(T[i] == '0') b++;
  }
  if(T[T.size() - 1] == '0') cout << a - b + 1 << endl;
  else cout << a - b << endl;
}