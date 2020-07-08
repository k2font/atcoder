#include <bits/stdc++.h>
using namespace std;

int main(){
    int A, B, C; cin >> A >> B >> C;

    int cnt5 = 0;
    if((A == 5 && B == 5 && C == 7) || (A == 7 && B == 5 && C == 5) || (A == 5 && B == 7 && C == 5)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}