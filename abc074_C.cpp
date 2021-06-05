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
  int A, B, C, D, E, F; cin >> A >> B >> C >> D >> E >> F;
  double node = 0.0; int ans1 = 0; int ans2 = 0;
  for(int x = 0; x <= 100; ++x) {
    for(int y = 0; y <= 100; ++y) {
      for(int z = 0; z <= 100; ++z) {
        for(int w = 0; w <= 100; ++w) {
          double tmp = 0.0;
          int water = A * x + B * y; int sugar = C * z + D * w;
          tmp = (double)sugar / (double)(water * 100 + sugar);
          if(sugar > water * E) break;
          if(water * 100 + sugar > F) break;
          if(tmp > node) {
            node = tmp; ans1 = 100 * A * x + 100 * B * y + C * z + D * w; ans2 = C * z + D * w;
          }
        }
      }
    }
  }
  if(node == 0.0) ans1 = A * 100;
  cout << ans1 << " " << ans2 << endl;
}