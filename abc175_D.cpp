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
struct edge {
  ll to, cost;
};

int main() {
  int N; cin >> N;
  ll K; cin >> K;
  vector<ll> P(N), C(N), check(N + 1, 0);
  REP(i, N) cin >> P[i];
  REP(i, N) cin >> C[i];
  ll ans = 0;
  vector<pair<ll, ll>> A; // (a, b)
  vector<vector<ll>> B; // ループ上のスコアを格納する
  vector<ll> t;
  queue<ll> q; ll a = 0; int b = 0;
  REP(i, N) {
    if(check[P[i]] == 0) {
      q.push(P[i]);
    }
    while(!q.empty()) {
      b++;
      ll tmp = q.front(); q.pop(); check[tmp] = 1; tmp--; 
      t.push_back(C[tmp]);
      a += C[tmp];
      if(check[P[tmp]] == 0) q.push(P[tmp]);
    }
    if(b != 0) {
      A.push_back(make_pair(a, b));
      B.push_back(t);
    }
    a = 0; b = 0; t.clear();
  }
  REP(i, A.size()) {
    if(A[i].first > 0) {
      if(K >= b) {
        ans += a * (K / b);
        ll tmp = ans;
        REP(k, A[i].second) {
          int c = 0;
          while(K % b > c) {
            c++;
            tmp += B[i][k];
            if(ans < tmp) ans = tmp;
          }
        }
      }
    } else {

    }
  }
  cout << ans << endl;
}