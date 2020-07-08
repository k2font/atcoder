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

int N;
void dfs(ll cur, int use, ll &counter) {
  if(cur > N) return; // 終了条件
  if(use == 0b111) {
    // cout << cur << endl;
    ++counter; // 7, 5, 3のうち、それまでどれを含めたか?
  }

  dfs(cur * 10 + 7, use | 0b001, counter);
  dfs(cur * 10 + 5, use | 0b010, counter);
  dfs(cur * 10 + 3, use | 0b100, counter);
}

int main() {
  cin >> N;
  ll res = 0;
  dfs(0, 0, res);
  cout << res << endl;
}