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
  int H, W, N; cin >> H >> W >> N;

  int cnt = 0;
  int ans = 0;
  bool flag = false;

  if(H >= W) {
    while(true) {
      cnt += H;
      ans++;
      if(cnt >= N) {
        flag = true;
        break;
      }
      if(W == ans) break;
    }
  } else if(H < W) {
    while(true) {
      cnt += W;
      ans++;
      if(cnt >= N) {
        flag = true;
        break;
      }
      if(H <= ans) break;
    }
  }

  if(flag == false) {
    if(H >= W) {
      while(true) {
        cnt += W;
        ans++;
        if(cnt >= N) {
          flag = true;
          break;
        }
        if(H <= ans) break;
      }
    } else if(H < W) {
      while(true) {
        cnt += H;
        ans++;
        if(cnt >= N) {
          flag = true;
          break;
        }
        if(W <= ans) break;
      }
    }
  }

  cout << ans << endl;
}