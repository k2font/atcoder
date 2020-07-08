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
  ll N; cin >> N;
  vector<int> A;
  const char c[26] = {
    'a','b','c','d','e','f','g','h','i','j','k','l',
    'm','n','o','p','q','r','s','t','u','v','w','x','y','z'
  };
  int i = 0;
  while(N > 1) {
    ll tmp = N % 26;
    if(tmp == 0) A.push_back(26);
    else A.push_back(tmp);
    
    if(tmp == 0) N = N / 26 - 1;
    else N = N / 26;
  }
  if(N == 1) A.push_back(1);
  for(int i = A.size() - 1; i >= 0; --i) {
    cout << c[A[i] - 1];
  }
  cout << endl;
}