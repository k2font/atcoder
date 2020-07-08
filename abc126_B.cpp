#include <bits/stdc++.h>
using namespace std;

int main() {
    string S; cin >> S;

    int f = (S[0] - '0') * 10 + S[1] - '0';
    int s = (S[2] - '0') * 10 + S[3] - '0';

    if(f < 13 && s < 13 && f != 0 && s != 0) {
        cout << "AMBIGUOUS" << endl;
    } else if((f >= 13 || f == 0) && s < 13 && s > 0) {
        cout << "YYMM" << endl;
    } else if(f < 13 && f > 0 && (s >= 13 || s == 0)) {
        cout << "MMYY" << endl;
    } else {
        cout << "NA" << endl;
    }
}