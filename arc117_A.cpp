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
  int A, B; cin >> A >> B;
  vector<ll> ans;
  ll a = 0; ll e1 = 9e5;
  REP(i, A) {
    ans.push_back(e1);
    a += e1; e1--;
  }

  ll e2 = -1;
  REP(i, B - 1) {
    ans.push_back(e2); a += e2;
    e2--;
  }
  ans.push_back(-a);
  REP(i, ans.size()) cout << ans[i] << endl;
}