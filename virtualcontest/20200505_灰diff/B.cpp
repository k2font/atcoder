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
  vector<vector<int>> A(3, vector<int>(3));
  REP(i, 3) {
    REP(k, 3) {
      cin >> A[i][k];
    }
  }
  int N; cin >> N;
  vector<int> b(N); REP(i, N) cin >> b[i];

  vector<vector<int>> ans = {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
  };

  REP(i, N) {
    REP(k, 3) {
      REP(m, 3) {
        if(b[i] == A[k][m]) ans[k][m] = 1;
      }
    }
  }

  if((ans[0][0] == 1 && ans[0][1] == 1 && ans[0][2] == 1) ||
      (ans[1][0] == 1 && ans[1][1] == 1 && ans[1][2] == 1) || 
      (ans[2][0] == 1 && ans[2][1] == 1 && ans[2][2] == 1) || 
      (ans[0][0] == 1 && ans[1][0] == 1 && ans[2][0] == 1) || 
      (ans[0][1] == 1 && ans[1][1] == 1 && ans[2][1] == 1) || 
      (ans[0][2] == 1 && ans[1][2] == 1 && ans[2][2] == 1) ||
      (ans[0][0] == 1 && ans[1][1] == 1 && ans[2][2] == 1) ||
      (ans[0][2] == 1 && ans[1][1] == 1 && ans[2][0] == 1)) {
        cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}