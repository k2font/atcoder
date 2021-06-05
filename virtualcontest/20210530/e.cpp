#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using P = pair<ll, ll>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};
string char_to_string(char val) {
  return string(1, val);
}
int char_to_int(char val) {
  return val - '0';
}
char inverse_char(char c) {
  if(isupper(c)) return tolower(c);
  else return toupper(c);
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
struct edge {
  ll to, cost;
};
template <class T> T up(T a, T div) { return (a + div - 1) / div; }

int main() {
  ll Q, L; cin >> Q >> L;
  vector<pair<ll, ll>> stack;
  ll size = 0; ll top = 0; bool f = false;
  REP(i, Q) {
    string q; cin >> q;
    if(q == "Push") {
      ll N, M; cin >> N >> M;
      if(f == true) continue;
      size += N;
      if(size > L) {
        cout << "FULL" << endl;
        f = true;
        continue;
      }
      stack.push_back(make_pair(M, N)); top = M;
    } else if(q == "Pop") {
      ll N; cin >> N;
      if(f == true) continue;
      if(size < N) {
        cout << "EMPTY" << endl; f = true;
        continue;
      }
      ll t = N; int z = 0;
      for(int k = stack.size() - 1; k >= 0; --k) {
        t -= stack[k].second;
        if(0 <= t) {
          z++;
        } else if(t < 0) {
          stack[k].second = abs(t);
          break;
        }
      }
      REP(i, z) {
        stack.pop_back();
      }
      top = stack[stack.size() - 1].first;
      size -= N;
    } else if(q == "Top") {
      if(f == true) continue;
      if(stack.size() == 0) {
        cout << "EMPTY" << endl; f = true;
        continue;
      }
      cout << top << endl;
    } else if(q == "Size") {
      if(f == true) continue;
      cout << size << endl;
    }
  }
  if(f == false) cout << "SAFE" << endl;
}