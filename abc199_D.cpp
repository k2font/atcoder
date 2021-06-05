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
  ll N, M; cin >> N >> M;
  vector<ll> A(M), B(M);
  REP(i, M) {
    cin >> A[i] >> B[i]; A[i]--; B[i]--;
  }

  vector<vector<ll>> tree(N);
  REP(i, M) {
    tree[A[i]].push_back(B[i]);
    tree[B[i]].push_back(A[i]);
  }

  vector<ll> sai(N, 0), kei(N, 0);
  vector<bool> f(N);
  ll ans = 1;

  REP(i, N) {
    queue<ll> q; q.push(i); 
    // つながっている部分だけ計算
    while(!q.empty()) {
      auto x = q.front(); q.pop();
      if(kei[x] == 1) continue; // そのノードは計算したか？
      if(sai[x] >= 3 && N >= 4) ans *= 0;
      else {
        if(sai[x] == 0) ans *= 3;
        else if(sai[x] == 1) ans *= 2;
        else if(sai[x] == 2) ans *= 1;
        else ans *= 0;
      }
      kei[x] = 1; // 計算したらフラグを立てる

      if(f[x] == true) continue; // そのノードはすでに見たか？
      f[x] = true; // フラグを立てる

      for(int i = 0; i < tree[x].size(); ++i) {
        sai[tree[x][i]]++;
        if(f[tree[x][i]] == true) continue;
        q.push(tree[x][i]);
      }
    }
  }

  cout << ans << endl;
}