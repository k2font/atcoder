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

int N, M, Q;
vector<int> a, b, c, d;
ll ans = 0;
void dfs(vector<int> &A, int tmp) {
  if(A.size() == N) {
    ll tmp = 0;
    REP(i, Q) {
      if(A[b[i] - 1] - A[a[i] - 1] == c[i]) {
        tmp += d[i];
      }
    }
    if(ans < tmp) ans = tmp;
    return;
  }

  for(int i = tmp; i <= M; ++i) {
    A.push_back(i);
    dfs(A, i);
    A.pop_back();
  }
}

int main() {
  cin >> N >> M >> Q;
  a.resize(Q); b.resize(Q); c.resize(Q); d.resize(Q);
  REP(i, Q) cin >> a[i] >> b[i] >> c[i] >> d[i];
  vector<int> A;
  dfs(A, 1);
  cout << ans << endl;
}