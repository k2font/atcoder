#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using P = pair<int, int>;
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
  vector<int> P(N), Q(N), tmp(N);
  REP(i, N) cin >> P[i];
  REP(i, N) cin >> Q[i];
  REP(i, N) tmp[i] = i + 1;
  int a, b, res;
  do {
    res++;
    for(int i = 0; i < N; ++i) {
      if(P[i] != tmp[i]) break;
      if(i == N - 1) a = res;
    }
    for(int i = 0; i < N; ++i) {
      if(Q[i] != tmp[i]) break;
      if(i == N - 1) b = res;
    }
  } while (next_permutation(tmp.begin(), tmp.end()));
  cout << abs(a - b) << endl;
}