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
  int n; cin >> n;
  vector<pair<int, int>> p;
  REP(i, n) {
    int a, b; cin >> a >> b;
    p.push_back(make_pair(a, b));
  }
  sort(all(p));
  ll ans = 0;
  for(int i = 0; i < n - 1; ++i) {
    for(int k = i + 1; k < n; ++k) {
      ll tmp = 0;
      auto q = p[i], r = p[k];
      auto tmp_q = q, tmp_r = r;
      tmp_q.first -= r.first; tmp_q.second -= r.second;
      tmp_r.first -= q.first; tmp_r.second -= q.second;
      complex<double> comp(tmp_q.first, tmp_q.second);
      comp *= exp(complex<double>(.0, 90.0*M_PI / 180.0));
      complex<double> comp2(tmp_q.first, tmp_q.second);
      comp2 *= exp(complex<double>(.0, -90.0*M_PI / 180.0));

      double x, y; x = comp.real(); y = comp.imag();
      double x2, y2; x2 = comp2.real(); y2 = comp2.imag();
      bool flag1 = false, flag2 = false;
      for(int i = 0; i < n; ++i) {
        if(x == p[i].first && y == p[i].second) {
          flag1 = true;
          break;
        }

        if(x2 == p[i].first && y2 == p[i].second) {
          flag2 = true;
          break;
        }
      }
      double a = 0;
      if(flag1 && flag2) {
        a = sqrt(pow(x2 - x, 2) + pow(y2 - y, 2));
        tmp = a * a;
      }
      if(ans < tmp) ans = tmp;
    }
  }
  for(int i = 0; i < n - 1; ++i) {
    for(int k = i + 1; k < n; ++k) {
      ll tmp = 0;
      auto q = p[i], r = p[k];
      auto tmp_q = q, tmp_r = r;
      tmp_q.first -= r.first; tmp_q.second -= r.second;
      tmp_r.first -= q.first; tmp_r.second -= q.second;
      complex<double> comp(tmp_q.first, tmp_q.second);
      comp *= exp(complex<double>(.0, -90.0*M_PI / 180.0));
      complex<double> comp2(tmp_q.first, tmp_q.second);
      comp2 *= exp(complex<double>(.0, 90.0*M_PI / 180.0));

      double x, y; x = comp.real(); y = comp.imag();
      double x2, y2; x2 = comp2.real(); y2 = comp2.imag();
      bool flag1 = false, flag2 = false;
      for(int i = 0; i < n; ++i) {
        if(x == p[i].first && y == p[i].second) {
          flag1 = true;
          break;
        }

        if(x2 == p[i].first && y2 == p[i].second) {
          flag2 = true;
          break;
        }
      }
      double a = 0;
      if(flag1 && flag2) {
        a = sqrt(pow(x2 - x, 2) + pow(y2 - y, 2));
        tmp = a * a;
      }
      if(ans < tmp) ans = tmp;
    }
  }
  cout << ans << endl;
}