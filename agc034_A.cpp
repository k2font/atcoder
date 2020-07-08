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
  int N, A, B, C, D; cin >> N >> A >> B >> C >> D;
  string S; cin >> S;
  string ans = "No";
  if(C < D) {
    while(B != D) {
      if(S[B + 1] == '.') {
        B = B + 2;
      } else if(S[B] == '.') {
        B++;
      } else {
        break;
      }

      if(B > D) {
        B--;
      }
    }

    while(A != C) {
      if(S[A + 1] == '.') {
        A = A + 2;
      } else if(S[A] == '.') {
        A++;
      } else {
        break;
      }

      if(A > C) {
        A--;
      }
    }

    if(A == C && B == D) {
      ans = "Yes";
    }
  } else {
    bool flag = false;
    for(int i = 0; i < N - 2; ++i) {
      if(S[i] == '.' && S[i + 1] == '.' && S[i + 2] == '.') {
        flag = true;
      }
    }

    if(flag == true) {
      while(B != D) {
        if(S[B + 1] == '.') {
          B = B + 2;
        } else if(S[B] == '.') {
          B++;
        } else {
          break;
        }

        if(B > D) {
          B--;
        }
      }

      while(A != C) {
        if(S[A + 1] == '.') {
          A = A + 2;
        } else if(S[A] == '.') {
          A++;
        } else {
          break;
        }

        if(A > C) {
          A--;
        }
      }

      if(A == C && B == D) {
        ans = "Yes";
      }
    }
  }
  cout << ans << endl;
}
