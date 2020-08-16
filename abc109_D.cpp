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

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};

int main() {
  int H, W; cin >> H >> W;
  vector<vector<int>> a(H, vector<int>(W));
  vector<pair<int, int>> from, to;
  int cnt = 0;
  REP(i, H) {
    REP(k, W) {
      cin >> a[i][k];
      if(a[i][k] % 2 == 1) cnt++;
    }
  }
  int res = 0;
  if(cnt % 2 == 1) {
    for(int i = 0; i < H; ++i) {
      if(i % 2 == 0) {
        for(int k = 0; k < W; ++k) {
          if(k == W - 1) {
            if(res * 2 == cnt - 1) break;
            // 下の段に渡す
            if(a[i][k] % 2 == 1) {
              from.push_back(make_pair(i, k));
              to.push_back(make_pair(i + 1, k));
              a[i][k]--; a[i + 1][k]++;
              if(a[i + 1][k] % 2 == 0) res++;
            }
            continue;
          } else {
            // それ以外
            if(a[i][k] % 2 == 1) {
              from.push_back(make_pair(i, k));
              to.push_back(make_pair(i, k + 1));
              a[i][k]--; a[i][k + 1]++;
              if(a[i][k + 1] % 2 == 0) res++;
            }
          }
        }
      } else {
        for(int k = W - 1; k >= 0; --k) {
          if(k == 0) {
            if(res * 2 == cnt - 1) break;
            // 下の段に渡す
            if(a[i][k] % 2 == 1) {
              from.push_back(make_pair(i, k));
              to.push_back(make_pair(i + 1, k));
              a[i][k]--; a[i + 1][k]++;
              if(a[i + 1][k] % 2 == 0) res++;
            }
            continue;
          } else {
            if(a[i][k] % 2 == 1) {
              from.push_back(make_pair(i, k));
              to.push_back(make_pair(i, k - 1));
              a[i][k]--; a[i][k - 1]++;
              if(a[i][k - 1] % 2 == 0) res++;
            }
          }
        }
      }
      if(res * 2 == cnt - 1) break;
    }
  } else {
    for(int i = 0; i < H; ++i) {
      if(i % 2 == 0) {
        for(int k = 0; k < W; ++k) {
          if(k == W - 1) {
            if(res * 2 == cnt - 1) break;
            // 下の段に渡す
            if(a[i][k] % 2 == 1) {
              from.push_back(make_pair(i, k));
              to.push_back(make_pair(i + 1, k));
              a[i][k]--; a[i + 1][k]++;
            }
            continue;
          } else {
            // それ以外
            if(a[i][k] % 2 == 1) {
              from.push_back(make_pair(i, k));
              to.push_back(make_pair(i, k + 1));
              a[i][k]--; a[i][k + 1]++;
            }
          }
        }
      } else {
        for(int k = W - 1; k >= 0; --k) {
          if(k == 0) {
            if(res * 2 == cnt - 1) break;
            // 下の段に渡す
            if(a[i][k] % 2 == 1) {
              from.push_back(make_pair(i, k));
              to.push_back(make_pair(i + 1, k));
              a[i][k]--; a[i + 1][k]++;
            }
            continue;
          } else {
            if(a[i][k] % 2 == 1) {
              from.push_back(make_pair(i, k));
              to.push_back(make_pair(i, k - 1));
              a[i][k]--; a[i][k - 1]++;
            }
          }
        }
      }
      if(res * 2 == cnt - 1) break;
    }
  }
  cout << from.size() << endl;
  REP(i, from.size()) {
    cout << from[i].first + 1 << " " << from[i].second + 1 << " ";
    cout << to[i].first + 1 << " " << to[i].second + 1 << endl;
  }
}