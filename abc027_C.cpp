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
  ll N; cin >> N;
  string ans = "Takahashi";
  int tmp = 1; ll S = N;
  for(int i = 1; i <= 100; ++i) {
    if(S <= 1) break;
    S /= 2;
    ++tmp; // 木の深さ
  }
  if(tmp % 2 == 1) {
    ll t = 1;
    for(int i = 0; i <= 100; ++i) {
      if(i % 2 == 0) {
        t *= 2; t++;
      } else {
        t *= 2;
      }

      if(t > N) {
        if(t % 2 == 0) {
          ans = "Takahashi";
        } else {
          ans = "Aoki";
        }
        break;
      }
    }
  } else {
    ll t = 1;
    for(int i = 0; i <= 100; ++i) {
      if(i % 2 == 0) {
        t *= 2;
      } else {
        t *= 2; t++;
      }

      if(t > N) {
        if(t % 2 == 0) {
          ans = "Aoki";
        } else {
          ans = "Takahashi";
        }
        break;
      }
    }
  }
  cout << ans << endl;
}