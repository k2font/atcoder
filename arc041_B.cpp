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
  int N, M; cin >> N >> M;
  vector<vector<int>> b(N, vector<int>(M));
  REP(i, N) {
    string s; cin >> s;
    REP(k, M) {
      int a = char_to_int(s[k]);
      b[i][k] = a;
    }
  }
  vector<vector<int>> a(N, vector<int>(M));
  REP(i, N) {
    REP(k, M) {
      if(b[i][k] > 0) {
        a[i + 1][k] += b[i][k];
        int a = b[i][k];
        b[i][k] -= a; b[i + 1][k - 1] -= a;
        b[i + 1][k + 1] -= a; b[i + 2][k] -= a;
      }
    }
  }
  REP(i, N) {
    REP(k, M) {
      cout << a[i][k];
    }
    cout << endl;
  }
} 