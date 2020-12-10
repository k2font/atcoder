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

const int INF = pow(10, 9) + 7;

int main() {
  ll r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
  if(r1 == r2 && c1 == c2) {
    cout << 0 << endl;
    return 0;
  } else if (
    r1 + c1 == r2 + c2 ||
    r1 - c1 == r2 - c2 ||
    abs(r1 - r2) + abs(c1 - c2) <= 3
  ) {
    cout << 1 << endl;
    return 0;
  } else {
    // 2の場合
    if((r1 + c1 + r2 + c2) % 2 == 0) {
      cout << 2 << endl;
      return 0;
    } else if(abs(r1 - r2) + abs(c1 - c2) <= 6) {
      cout << 2 << endl;
      return 0;
    } else if(abs(r1 + c1 - r2 - c2) <= 3) {
      cout << 2 << endl;
      return 0;
    } else if(abs(r1 - c1 - r2 + c2) <= 3) {
      cout << 2 << endl;
      return 0;
    }
  }
  cout << 3 << endl;
}