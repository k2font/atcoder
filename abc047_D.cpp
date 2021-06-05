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
  ll N, T; cin >> N >> T;
  vector<ll> A(N); REP(i, N) cin >> A[i];
  int profit = 0; int sml = A[0]; int pattern = 0;
  for(int i = 1; i < N; ++i) {
    if(sml > A[i]) {
      sml = A[i];
    } else if(A[i] - sml > profit) {
      profit = A[i] - sml;
      pattern = 1; // 現在見えている利益より大きい区間が見つかったらパターン数を初期化
    } else if(A[i] - sml == profit) {
      pattern++;
    }
  }
  cout << pattern << endl;
}