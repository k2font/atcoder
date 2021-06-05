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
  vector<int> a(M), b(M); REP(i, M) cin >> a[i] >> b[i];
  vector<vector<int>> tree(N);
  REP(i, M) {
    tree[a[i]].push_back(b[i]);
    tree[b[i]].push_back(a[i]);
  }
  int A = -1; int B = -1; int C = -1; int ans = 0;
  REP(i, N) {
    REP(k, N) {
      REP(n, N) {
        map<int, int> m;
        REP(a, tree[i].size()) m[tree[i][a]]++;
        REP(a, tree[k].size()) m[tree[k][a]]++;
        REP(a, tree[n].size()) m[tree[n][a]]++;
        int res = m.size();
        if(ans < res) {
          A = i; B = k; C = n; ans = res;
        }
        m.clear();
      }
    }
  }
  cout << A << " " << B << " " << C << endl;
}