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
  int N; cin >> N;
  if(N % 3 != 0) {
    cout << "No" << endl;
  } else {
    int n = N / 3; // 集合1つ分に含まれる要素数
    cout << "Yes" << endl;
    cout << 3 + (n + 1 - 2) << endl;
    for(int m = 0; m < N; m += n) {
      cout << n + 1 << " ";
      REP(i, n + 1) {
        if(m + 1 + i > N) cout << 1;
        else cout << m + 1 + i;
        if(i != n) cout << " ";
      }
      cout << endl;
    }
    if(N >= 4) {
      for(int i = 2; i < n + 1; ++i) {
        cout << n << " ";
        REP(k, 3) {
          cout << i + k * n;
          if(k != 2) cout << " ";
        }
        cout << endl;
      }
    }
  }
}