#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  string S;
  cin >> N >> S;
  
  int count = 1;
  
  for(int i = 1; i < N; ++i) {
    if(S.at(i) == S.at(i - 1)) {
      continue;
    } else {
      count++;
    }
  }
  
  cout << count << endl;
}
