#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define REP(i,n) for(ll i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
string char_to_string(char val) {
  return string(1, val);
}
int char_to_int(char val) {
  return val - '0';
}

int main() {
  int N; cin >> N;
  vector<vector<int>> A(2, vector<int>(N));
  REP(i, 2) {
    REP(k, N) {
      cin >> A[i][k];
    }
  }

  int cnt = 0;
  int flag = 0;

  REP(i, N) {
    int tmp = 0;
    REP(k, N) {
      tmp += A[flag][k];
      if(k == i) {
        flag = 1;
        tmp += A[flag][k];
      }

      if(tmp > cnt) cnt = tmp;
    }
    flag = 0;
  }
  cout << cnt << endl;
}