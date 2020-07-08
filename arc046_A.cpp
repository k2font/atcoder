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

int N;
vector<int> zoro;
void dfs(int n) {
  if(to_string(n).size() == 7) return;
  if(to_string(n).size() == 1) {
    zoro.push_back(n);
  } else {
    for(int i = 0; i < to_string(n).size() - 1; ++i) {
      if(to_string(n)[i] != to_string(n)[i + 1]) {
        break;
      }
      if(i == to_string(n).size() - 2) {
        zoro.push_back(n);
      }
    }
  }
  for(int i = 1; i < 10; ++i) {
    int tmp = n * 10 + i;
    dfs(tmp);
  }
}

int main() {
  cin >> N;
  for(int i = 1; i < 10; ++i) dfs(i);
  sort(all(zoro));
  cout << zoro[N - 1] << endl;
}