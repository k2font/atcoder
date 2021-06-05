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

vector<ll> C;

vector<vector<ll>> tree;
vector<ll> res; // その頂点にたどり着いたか？
vector<ll> ans; // 答え

map<ll, ll> _tmp;
void dfs(ll pnt) {
  res[pnt] = 1; _tmp[C[pnt]]++;
  if(_tmp[C[pnt]] == 1) ans.push_back(pnt);
  for(int i = 0; i < tree[pnt].size(); ++i) {
    if(res[tree[pnt][i]] == 1) continue;
    dfs(tree[pnt][i]);
  }
  _tmp[C[pnt]]--;
}

int main() {
  ll N; cin >> N;
  C.resize(N); REP(i, N) cin >> C[i];
  vector<ll> A(N - 1), B(N - 1);
  REP(i, N - 1) {
    cin >> A[i] >> B[i];
    --A[i]; --B[i];
  }
  tree.resize(N); res.resize(N);
  REP(i, N - 1) {
    tree[A[i]].push_back(B[i]);
    tree[B[i]].push_back(A[i]);
  }
  dfs(0); sort(all(ans));
  REP(i, ans.size()) cout << ans[i] + 1 << endl;
}