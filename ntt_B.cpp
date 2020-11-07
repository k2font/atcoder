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
  ll A, B, X, N; cin >> A >> B >> X >> N;
  string ans = "NO";
  if(B == 1) {
    if(A >= N) {
      ans = "YES";
    } else {
      ans = "NO";
    }
  } else if(B == 0) {
    if(X == 1) {
      if(A >= N) {
        ans = "YES";
      } else {
        ans = "NO";
      }
    } else {
      if(N == 0) {
        ans = "YES";
      } else {
        ans = "NO";
      }
    }
  } else if(A == 0) {
    if(N == 0) {
      ans = "YES";
    } else {
      ans = "NO";
    }
  } else {
    for(ll i = 0; i < X - 1; ++i) {
      A *= B;
      if(A >= N || A < 0) {
        ans = "YES";
        break;
      }
    }
  }
  cout << ans << endl;
}
