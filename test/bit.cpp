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
  int a = 45;
  int b = 25;

  // 101101 AND 011001 = 001001
  cout << a << " AND " << b << " = " << (a & b) << endl;
  // 101101 OR 011001 = 111101
  cout << a << " OR " << b << " = " << (a | b) << endl;

  int A = 45;
  int B = 25;

  cout << A << " AND " << B << " = " << (A & B) << endl;
  cout << bitset<8>(A) << " AND " << bitset<8>(B) << " = " << bitset<8>(A & B) << endl;

  // a番目のフラグが立っている状態
  cout << bitset<8>(1 << 4) << endl;
  if(A & (1 << 3)) cout << "hi" << endl;
  A |= (1 << 4);
  cout << A << endl;

  // {1, 3, 5}にフラグの立ったビット
  unsigned int bit = (1 << 1) | (1 << 3) | (1 << 5); // 1つ1つがORを表す
  cout << "{1, 3, 5} = " << bitset<8>(bit) << endl;

  // ビット{1, 3, 5}について、3番目のフラグが立っていること
  if(bit & (1 << 3)) {
    cout << "3 is in     " << bitset<8>(bit) << endl;
  }

  // 0番目にビットが立っていないこと
  if(!(bit & (1 << 0))) {
    cout << "0 is not in " << bitset<8>(bit) << endl;
  }

  // 新たなビットを用意する
  unsigned int bit2 = (1 << 0) | (1 << 3) | (1 << 4); // {0, 3, 4}
  cout << bitset<8>(bit) << " AND " << bitset<8>(bit2) << " = " << bitset<8>(bit & bit2) << endl;
  cout << bitset<8>(bit) << " AND " << bitset<8>(bit2) << " = " << bitset<8>(bit | bit2) << endl;

  // bitに6番目のフラグを立てる
  cout << "before: " << bitset<8>(bit) << endl;
  bit |= (1 << 6);
  cout << "after : " << bitset<8>(bit) << endl;


  // bit2から3番目のフラグを消す
  cout << "before: " << bitset<8>(bit2) << endl;
  bit2 &= ~(1 << 3);
  cout << "after : " << bitset<8>(bit2) << endl;
}