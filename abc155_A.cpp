#include <bits/stdc++.h>
using namespace std;

int main(){
    int A, B, C;
    cin >> A >> B >> C;

    if((A == B && B != C && A != C)
    || (A == C && B != C && A != B)
    || (A != B && A != C && C == B))
    {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}