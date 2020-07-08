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

int vector_finder(std::vector<ll> vec, int number) {
  auto itr = std::find(vec.begin(), vec.end(), number);
  size_t index = std::distance( vec.begin(), itr );
  if (index != vec.size()) { // 発見できたとき
    return 1;
  }
  else { // 発見できなかったとき
    return 0;
  }
}

int main() {
  ll N, M; cin >> N >> M;
  vector<ll> H(N); REP(i, N) cin >> H[i];
  vector<long long> A(M), B(M); REP(i, M) cin >> A[i] >> B[i];

  vector<vector<ll>> a(N + 1);

  REP(i, M) {
    if(vector_finder(a[A[i]], B[i]) == 0) {
      a[A[i]].push_back(B[i]);
      a[B[i]].push_back(A[i]);
    }
  }

  // check1: 上記でN + 1番目を指定できていないことがおかしい
  // 対策: at関数を使って値にアクセスする
  // check2: 添字が地獄。
  // 対策: 添字と問題文をよく読む
  vector<ll> ans(N + 1);
  for(int i = 1; i <= N; ++i) {
    REP(k, a[i].size()) {
      if(i > a[i][k]) continue;

      if(H[i - 1] > H[a[i][k] - 1]) {
        ans[i]++;
      } else if(H[i - 1] < H[a[i][k] - 1]) {
        ans[a[i][k]]++;
      }
    }
  }

  // 対策3: こんな大変な方法はとらない！

  ll cnt = 0;
  for(int i = 1; i <= N; ++i) {
    if(ans[i] == a[i].size()) cnt++;
  }

  cout << cnt << endl;
}
