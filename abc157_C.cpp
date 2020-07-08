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
    int N, M; cin >> N >> M;
    vector<int> s(M), c(M); REP(i, M) cin >> s[i] >> c[i];
    for(int i = 0; i <= 1000; i++) {
        if(i == 1000) {
            cout << -1 << endl;
            break;
        }
        string tmp = to_string(i);
        if(tmp.size() != N) continue;
        bool flag = false;
        for(int k = 0; k < M; ++k) {
            if(char_to_int(tmp[s[k] - 1]) != c[k]) break;
            if(k == M - 1) {
                flag = true;
            }
        }
        if(flag == true || M == 0) {
            cout << tmp << endl;
            break;
        }
    }
}