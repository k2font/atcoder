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
  int N; cin >> N;
  vector<ll> C(N - 1), S(N - 1), F(N - 1);
  REP(i, N - 1) cin >> C.at(i) >> S.at(i) >> F.at(i);

  vector<ll> ans(N);
  REP(i, N) {
    if(i == N - 1) {
      ans.at(i) = 0;
      break;
    }
    ans.at(i) = S.at(i);
  }

  REP(i, N) {
    for(int k = i; k < N - 1; ++k) {
      if(ans.at(i) < S.at(k)) {
        ans.at(i) = S.at(k);
      } else if(ans.at(i) % F.at(k) == 0) {

      } else {
        ans.at(i) = ans.at(i) + F.at(k) - (ans.at(i) % F.at(k));
      }
      ans.at(i) += C.at(k);
    }
  }

  REP(i, N) {
    cout << ans.at(i) << endl;
  }
}