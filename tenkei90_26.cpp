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
  ll N; cin >> N;
  vector<vector<ll>> tree(N);
  REP(i, N - 1) {
    ll A, B; cin >> A >> B;
    A--; B--;
    tree[A].push_back(B);
    tree[B].push_back(A);
  }
  // BFSして根っこをansに格納する
  map<ll, vector<ll>> m;
  queue<pair<ll, ll>> q; vector<ll> f(N, -1); q.emplace(0, 0); f[0] = 0; m[0].push_back(0);
  ll maxn = 0;
  while(!q.empty()) {
    auto x = q.front(); q.pop();
    f[x.first] = x.second; m[x.second].push_back(x.first);
    for(int i = 0; i < tree[x.first].size(); ++i) {
      if(f[tree[x.first][i]] != -1) continue;
      q.emplace(tree[x.first][i], x.second + 1);
      maxn = max(maxn, x.second + 1);
    }
  }


  vector<ll> ans1, ans2;

  // 最も長い距離から探索して、1つ飛ばしでansに格納していく
  for(int i = maxn; i > 0; i -= 2) {
    REP(k, m[i].size()) {
      ans1.push_back(m[i][k]);
    }
  }

  // 最も長い距離 - 1から探索して、1つ飛ばしでansに格納していく
  for(int i = maxn - 1; i > 0; i -= 2) {
    REP(k, m[i].size()) {
      ans2.push_back(m[i][k]);
    }
  }


  // N/2個の頂点を出力する
  if(ans1.size() >= ans2.size()) {
    REP(i, N / 2) cout << ans1[i] + 1 << " ";
    cout << endl;
  } else {
    REP(i, N / 2) cout << ans2[i] + 1 << " ";
    cout << endl;
  }
}