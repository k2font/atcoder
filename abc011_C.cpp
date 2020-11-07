#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using P = pair<ll, ll>;
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
  int N; cin >> N;
  int A, B, C; cin >> A >> B >> C;
  string ans = "YES"; int cnt = 0;
  if(N == A || N == B || N == C) {
    cout << "NO" << endl;
    return 0;
  }
  while(N > 0) {
    cnt++;
    if(N - 3 == A || N - 3 == B || N - 3 == C) {
      if(N - 2 == A || N - 2 == B || N - 2 == C) {
        if(N - 1 == A || N - 1 == B || N - 1 == C) {
          cout << "NO" << endl;
          return 0;
        } else {
          N--;
        }
      } else {
        N -= 2;
      }
    } else {
      N -= 3;
    }
    if(cnt == 100) {
      if(N > 0) {
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  cout << ans << endl;
}
