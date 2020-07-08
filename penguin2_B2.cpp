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
  int N; cin >> N;
  string P; cin >> P;
  int x, y, flag;
  x = 0; y = 0; flag = 1;
  vector<char> p;
  REP(i, P.size()) {
    if(P[i] == 'F' || P[i] == 'B' || P[i] == 'R' || P[i] == 'L') {
      if(i == 0) {
        p.push_back(P[i]);
        continue;
      }
      if(i != 0 && (P[i - 1] == 'F' || P[i - 1] == 'B' || P[i - 1] == 'R' || P[i - 1] == 'L')) {
        p.push_back(P[i]);
      }
    } else {
      if(P[i + 1] == '[') {
        vector<char> tmp;
        int k = i + 2;
        while(true) {
          tmp.push_back(P[k]);
          if(P[k] == ']') break;
          k++;
        }
        for(int t = 0; t < char_to_int(P[i]); ++t) {
          for(int b = 0; b < tmp.size(); ++b) {
            p.push_back(tmp[b]);
          }
        }
        tmp.clear();
      } else {
        for(int k = 0; k < char_to_int(P[i]); ++k) {
          p.push_back(P[i + 1]);
        }
      }
    }
  }
  REP(i, p.size()) {
    if(p[i] == 'F') {
      if(flag == 1) {
        y++;
      } else if(flag == 2) {
        x++;
      } else if(flag == 3) {
        y--;
      } else if(flag == 4) {
        x--;
      }
    } else if(p[i] == 'B') {
      if(flag == 1) {
        y--;
      } else if(flag == 2) {
        x--;
      } else if(flag == 3) {
        y++;
      } else if(flag == 4) {
        x++;
      }
    } else if(p[i] == 'R') {
      if(flag == 4) {
        flag = 1;
      } else {
        flag++;
      }
    } else if(p[i] == 'L') {
      if(flag == 1) {
        flag = 4;
      } else {
        flag--;
      }
    }
  }
  cout << x << " " << y << endl;
}
