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
  ll A, R, N; cin >> A >> R >> N;
  vector<ll> ans;
  ll INF = pow(10, 9);
  ll i = 1;
  ll r = 1;
  if(R == 1) {

  } else {
      while(true) {
      if(i == 1) r = 1;
      else r = r * R;
      ll tmp = A * r;
      i++;
      if(tmp > INF || tmp < 0) break;  
      ans.push_back(tmp);
    }
  }
  if(R == 1) {
    cout << A << endl;
  } else if(ans.size() >= N) {
    cout << ans[N - 1] << endl;
  } else {
    cout << "large" << endl;
  }
}
