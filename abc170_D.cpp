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

map< int, int > prime_factor(int n) {
  map< int, int > ret;
  for(int i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}

int main() {
  int N; cin >> N;
  vector<int> A(N); REP(i, N) cin >> A[i];
  sort(all(A));
  map<int, int> m;
  int ans = 0;
  for(int i = 0; i < N; ++i) {
    bool flag = false;
    for(auto a : m) {
      if(A[i] % a.first == 0) {
        flag = true;
        break;
      }
    }
    if(flag == false) {
      ans++;
    }

    auto x = prime_factor(A[i]);
    for(auto a : x) {
      m[a.first]++;
    
    for(auto a : m) {
      cout << a.first << " ";
    }
    cout << endl;
  }
  if(A[N - 1] - A[0] == 0) {
    cout << 0 << endl;
  } else {
    cout << ans << endl;
  }
}
