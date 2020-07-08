#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define REP(i,n) for(ll i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
string char_to_string(char val) {
  return string(1, val);
}
int char_to_int(char val) {
  return val - '0';
}

int main() {
  int n; cin >> n;
  vector<int> v(n); REP(i, n) cin >> v[i];

  map<int, int> e_tmp, o_tmp;
  for(int i = 1; i < n; i = i + 2) {
    o_tmp[v[i]]++;
  }

  for(int i = 0; i < n; i = i + 2) {
    e_tmp[v[i]]++;
  }

  int o_max = 0;
  int e_max = 0;
  int o_num = 0;
  int e_num = 0;
  int o_max_2 = 0;
  int e_max_2 = 0;
  for(auto c : o_tmp) {
    if(o_max < c.second) {
      o_num = c.first;
      o_max = c.second;
    }
  }

  for(auto c : o_tmp) {
    if(o_max > c.second && c.second > o_max_2) {
      o_max_2 = c.second;
    }
  }

  for(auto d : e_tmp) {
    if(e_max < d.second) {
      e_num = d.first;
      e_max = d.second;
    }
  }

  for(auto c : o_tmp) {
    if(e_max > c.second && c.second > e_max_2) {
      e_max_2 = c.second;
    }
  }

  // cout << e_max_2 << " " << e_max << " " << o_max_2 << " " << o_max << endl;

  if(o_num == e_num) {
    cout << min(n - e_max_2 - o_max, n - e_max - o_max_2) << endl;
  } else {
    cout << n - e_max - o_max << endl;
  }
}