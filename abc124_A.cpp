#include <bits/stdc++.h>
using namespace std;

int main(){
    int A, B;
    cin >> A >> B;

    int ctn = 0;

    if(A > B) {
        ctn += A;
        A--;
    } else {
        ctn += B;
        B--;
    }

    if(A > B) {
        ctn += A;
        A--;
    } else {
        ctn += B;
        B--;
    }

    cout << ctn << endl;
}