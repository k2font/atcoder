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
  int N;
  cin >> N;

  vector<ll> ans;
  ans.push_back(6);
  ans.push_back(10);
  ans.push_back(15);

  map<ll, ll> m;
  for(int i = 1; i < 10000 / 6; ++i) m[6 * i]++;
  for(int i = 1; i < 10000 / 10; ++i) m[10 * i]++;
  for(int i = 1; i < 10000 / 15; ++i) m[15 * i]++;

  int n = 0;
  for(auto x : m) {
    if(x.first == 6 || x.first == 10 || x.first == 15) continue;
    ans.push_back(x.first); n++;
    if(n == N - 3) break;
  }

  REP(i, N) {
    cout << ans[i] << " ";
  }
  cout << endl;
}