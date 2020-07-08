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

int main() {
  int A, B, C; cin >> A >> B >> C;

  int max_num = max({A, B, C});
  int min_num = min({A, B, C});
  int mid_num = 0;
  int cnt = 0;

  string max_str = "";
  string min_str = "";
  string mid_str = "";
  if(max_num == A) {
    max_str = "A";
  } else if(max_num == B) {
    max_str = "B";
  } else {
    max_str = "C";
  }

  if(min_num == A) {
    min_str = "A";
  } else if(min_num == B) {
    min_str = "B";
  } else {
    min_str = "C";
  }

  if(max_str != "A" && min_str != "A") {
    mid_str = "A";
    mid_num = A;
  } else if(max_str != "B" && min_str != "B") {
    mid_str = "B";
    mid_num = B;
  } else {
    mid_str = "C";
    mid_num = C;
  }

  cnt = cnt + (max_num - mid_num);
  mid_num += cnt;
  min_num += cnt;

  int hantei = max_num - min_num;
  if(hantei == 2) {
    cnt++;
  } else {
    if(hantei % 2 == 0) {
      cnt += (max_num - min_num) / 2;
    } else {
      cnt += (max_num - min_num) / 2 + 1;
      cnt++;
    }
  }

  cout << cnt << endl;
}