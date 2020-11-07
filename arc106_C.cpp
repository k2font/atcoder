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
  if(M < 0) { // 高橋くんの解法は区間スケジューリング問題の最適解なので、必ず高 > 青となる。
    cout << -1 << endl;
  } else if(M == 0) { // それ以外はMが0以上の答えがある
    for(int i = 1; i <= 2 * N; i += 2) {
      cout << i << " " << i + 1 << endl;
    }
  } else {
    if(M >= N - 1) {
      cout << -1 << endl;
      return 0;
    } else if(M <= N - 2) {
      int tmp = N - M; int a = 0;
      for(int i = 1; i < 2 * M + 2; i += 2) {
        cout << i + 1 << " " << i + 2 << endl;
        if(i == 2 * M + 1) a = i + 2;
      }
      cout << 1 << " " << a + 1 << endl;
      for(int i = a + 2; i <= 2 * N; i += 2) {
        cout << i << " " << i + 1 << endl;
      }
    }
  }
}