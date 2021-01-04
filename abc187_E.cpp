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
  // 入力
  ll N; cin >> N;
  vector<vector<ll>> tree(N);
  vector<ll> A(N - 1), B(N - 1);
  REP(i, N - 1) {
    ll a, b; cin >> a >> b; --a; --b;
    A[i] = a; B[i] = b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }

  // 答え用配列を初期化する
  vector<ll> ans(N, 0);

  // 頂点aからbを通らずに到達できる点をすべて列挙する
  vector<vector<ll>> aa(N);
  vector<bool> f(N);
  REP(i, N - 1) {
    f.resize(N, false);
    queue<ll> q; q.push(A[i]); f[A[i]] = true; aa[i].push_back(A[i]);
    while(!q.empty()) {
      auto x = q.front(); q.pop();
      for(int k = 0; k < tree[x].size(); ++k) {
        if(tree[x][k] == B[i]) continue;
        if(f[tree[x][k]] == true) continue;
        q.push(tree[x][k]); aa[i].push_back(tree[x][k]);
        // cout << tree[x][k] << endl;
        f[tree[x][k]] = true;
      }
    }
  }

  // 頂点bからaを通らずに到達できる点をすべて列挙する
  vector<vector<ll>> bb(N);
  REP(i, N - 1) {
    f.resize(N, false);
    queue<ll> q; q.push(B[i]); f[B[i]] = true; bb[i].push_back(B[i]);
    while(!q.empty()) {
      auto x = q.front(); q.pop();
      for(int k = 0; k < tree[x].size(); ++k) {
        if(tree[x][k] == A[i]) continue;
        if(f[tree[x][k]] == true) continue;
        q.push(tree[x][k]); bb[i].push_back(tree[x][k]);
        // cout << tree[x][k] << endl;
        f[tree[x][k]] = true;
      }
    }
  }

  ll Q; cin >> Q;
  // 各クエリをO(1)で処理する
  REP(i, Q) {
    ll t, e, x; cin >> t >> e >> x;
    --e;
    if(t == 1) {
      for(int i = 0; i < aa[e].size(); ++i) {
        ans[aa[e][i]] += x;
      }
    } else {
      for(int i = 0; i < bb[e].size(); ++i) {
        ans[bb[e][i]] += x;
      }
    }
  }

  // 答えを出力する
  REP(i, N) {
    cout << ans[i] << endl;
  }
}
