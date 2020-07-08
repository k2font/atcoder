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
  ll A, B, C; cin >> A >> B >> C;

  ll ans = -1;
  ll tmp_a = A;
  ll tmp_b = B;
  ll tmp_c = C;
  if(A == B && A == C && B == C && (A/2) % 2 == 1) {
    ans = -1;
  } else {
    for(int i = 0; i < pow(10,8); ++i) {
      if(tmp_a % 2 == 1 || tmp_b % 2 == 1 || tmp_c % 2 == 1) {
        ans = i;
        break;
      }
      tmp_a = B/2 + C/2; tmp_b = A/2 + C/2; tmp_c = A/2 + B/2;
      A = tmp_a; B = tmp_b; C = tmp_c;
    }
  }

  cout << ans << endl;
}