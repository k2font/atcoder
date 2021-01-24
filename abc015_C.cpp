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

int N, K;
vector<vector<int>> n;
string ans = "Nothing";
void dfs(vector<int> v) {
  if(v.size() == N) {
    int t = v[0];
    REP(i, N) {
      if(i == 0) continue;
      t ^= v[i];
    }
    if(t == 0) ans = "Found";
    return;
  }
  int i = v.size();
  for(int k = 0; k < K; ++k) {
    v.push_back(n[i][k]);
    dfs(v);
    v.pop_back();
  }
}

int main() {
  cin >> N >> K;
  n.resize(N, vector<int>(K));
  REP(i, N) {
    REP(k, K) {
      cin >> n[i][k];
    }
  }
  vector<int> tmp;
  dfs(tmp);
  cout << ans << endl;
}
