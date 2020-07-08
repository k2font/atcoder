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

vector<string> S;
vector<vector<bool>> F;
int island = 0;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};
void dfs(int i, int k) {
  F[i][k] = true;
  for(int m = 0; m < 4; ++m) {
    if(i + dx[m] < 0 || i + dx[m] >= 10) continue;
    if(k + dy[m] < 0 || k + dy[m] >= 10) continue;
    if(F[i + dx[m]][k + dy[m]] == true) continue;
    if(S[i + dx[m]][k + dy[m]] == 'o') dfs(i + dx[m], k + dy[m]);
  }
}

void check() {
  REP(i, 10) {
    REP(k, 10) {
      if(S[i][k] == 'o' && F[i][k] == false) {
        dfs(i, k);
        island++;
      }
    }
  }
}

int main() {
  S.resize(10); REP(i, 10) cin >> S[i];
  F.resize(10);
  REP(i, 10) {
    REP(k, 10) {
      F[i].push_back(false);
    }
  }

  check();

  if(island >= 1 && island <= 4) {
    string ans = "NO";
    REP(i, 10) {
      // 左上から○にして探索
      REP(k, 10) {
        // 一旦初期化
        island = 0;
        REP(m, 10) {
          REP(p, 10) {
            F[m][p] = false;
          }
        }

        if(S[i][k] == 'x') {
          S[i][k] = 'o';
          check();
          S[i][k] = 'x';
        }

        if(island == 1) {
          ans = "YES";
        }
      }
    }
    cout << ans << endl;
  } else {
    cout << "NO" << endl;
  }
}