#include <bits/stdc++.h>
using namespace std;

int main(){
    int H, A;
    cin >> H >> A;

    int count = 0;

    while(H > 0) {
        H = H - A;
        count++;
    }

    cout << count << endl;
}
