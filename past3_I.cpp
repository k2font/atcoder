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
  int N, Q; cin >> N >> Q;
  vector<vector<int>> query(Q);
  REP(i, Q) {
    int a; cin >> a;
    query[i].push_back(a);
    if(a != 3) {
      int b, c;
      cin >> b >> c;
      query[i].push_back(b);
      query[i].push_back(c);
    }
  }
  vector<int> row(N), col(N);
  REP(i, N) {
    row[i] = i;
    col[i] = i;
  }
  bool flag = false;
  REP(i, Q) {
    if(query[i][0] == 1) {
      if(flag == true) { // 転置した結果(つまりrowとcolを逆にアクセスする)
        swap(col[query[i][1] - 1], col[query[i][2] - 1]);
      } else {
        swap(row[query[i][1] - 1], row[query[i][2] - 1]);
      }
    } else if(query[i][0] == 2) {
      if(flag == true) { // 転置した結果(つまりrowとcolを逆にアクセスする)
        swap(row[query[i][1] - 1], row[query[i][2] - 1]);
      } else {
        swap(col[query[i][1] - 1], col[query[i][2] - 1]);
      }
    } else if(query[i][0] == 3) {
      if(flag == false) {
        flag = true;
      } else if(flag == true) {
        flag = false;
      }
    } else if(query[i][0] == 4) {
      if(flag == true) { // 転置した結果(つまりrowとcolを逆にアクセスする)
        ll p = row[query[i][2] - 1];
        ll q = col[query[i][1] - 1];
        ll ans = N * p + q;
        cout << ans << endl;
      } else if(flag == false) { // 普通にアクセス
        ll p = row[query[i][1] - 1];
        ll q = col[query[i][2] - 1];
        ll ans = N * p + q;
        cout << ans << endl;
      }
    }
/*
    cout << "flag " << flag << endl;
    REP(m, N) {
      cout << row[m] << " ";
    }
    cout << endl;
    REP(m, N) {
      cout << col[m] << " ";
    }
    cout << endl;
    cout << "========" << endl; */
  }
}
