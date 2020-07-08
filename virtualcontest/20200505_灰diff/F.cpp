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

int main() {
  int N, M, C; cin >> N >> M >> C;
  vector<int> B(M); REP(i, M) cin >> B[i];
  vector<vector<int>> A(N, vector<int>(M));
  REP(i, N) {
    REP(k, M) {
      cin >> A[i][k];
    }
  }

  int cnt = 0;
  REP(i, N) {
    int tmp = 0;
    REP(k, M) {
      tmp = tmp + A[i][k] * B[k];
    }
    tmp += C;
    if(tmp > 0) cnt++;
  }

  cout << cnt << endl;
}