#include <bits/stdc++.h>
using namespace std;

int main() {
  for(double i = 0.01; i < 10.0; i = i + 0.01 ) {
    cout << fixed << setprecision(15) << i << " " << i * 100.0 << endl;
  }
}