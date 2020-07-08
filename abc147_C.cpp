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
  vector<int> A(N);
  vector<vector<int>> x(N), y(N);
  REP(i, N) {
    cin >> A[i];
    REP(k, A[i]) {
      int tmp_x, tmp_y;
      cin >> tmp_x >> tmp_y;
      x[i].push_back(tmp_x);
      y[i].push_back(tmp_y);
    }
  }

  int ans = 0;
  for(int bit = 0; bit < (1 << N); ++bit) {
    bool flag = false;
    REP(i, N) {
      if(!(bit & (1 << i))) continue;
      REP(k, A[i]) {
        if(y[i][k] == 1) {
          if( !(bit & (1 << (x[i][k] - 1))) ) {
            flag = true;
          }
        } else if(y[i][k] == 0) {
          if(bit & (1 << (x[i][k] - 1))) {
            flag = true;
          }
        }

        // cout << bitset<16>(bit) << " " << (x[i][k] - 1) << endl;
      }

      if(flag) break;
    }

    if(flag == false) {
      int check = __builtin_popcount(bit);
      if(ans < check) {
        ans = check;
      }
    }
  }

  cout << ans << endl;
}