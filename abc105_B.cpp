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

string ans = "No";

void rec(int n) {
  if(n == 0) {
    ans = "Yes";
    return;
  }
  if(n - 4 < 0 && n - 7 < 0) return;
  if(n - 4 >= 0) rec(n - 4);
  if(n - 7 >= 0) rec(n - 7);
}

int main() {
  int N; cin >> N;
  rec(N);
  cout << ans << endl;
}