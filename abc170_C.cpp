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
  int X, N; cin >> X >> N;
  vector<int> p(N); REP(i, N) cin >> p[i];
  if(N == 0) {
    cout << X << endl;
  } else {
    sort(all(p));
    int res = 0;
    for(int i = 0; i < N; ++i) {
      if(p[i] == X) {
        res = i;
        break;
      }
    }
    int a = 0;
    int b = 0;
    // 右へ
    for(int i = res; i < N; ++i) {
      if(i == N - 1) {
        a = p[i] + 1;
        break;
      }
      if(abs(p[i] - p[i + 1]) != 1) {
        a = p[i] + 1;
        break;
      }
    }
    // 左へ
    for(int i = res; i >= 0; --i) {
      if(i == 0) {
        b = p[i] - 1;
        break;
      }
      if(abs(p[i] - p[i - 1]) != 1) {
        b = p[i] - 1;
        break;
      }
    }

    int A = abs(X - a);
    int B = abs(X - b);
    if(A > B) {
      cout << b << endl;
    } else if(A < B) {
      cout << a << endl;
    } else if(A == B) {
      cout << min(a, b) << endl;
    }
  }
}
