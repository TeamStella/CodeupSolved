#include <iostream>
using namespace std;

int main() {
    int k, a;
    cin >> k >> a;

    int mf[1001];
    mf[1] = a;
    mf[2] = a;

    for (int i = 3; i <= k; ++i) {
        int sum = mf[i - 1] + mf[i - 2];
        if (sum >= 30) sum = 1;
        mf[i] = sum;
    }

    cout << mf[k] << endl;
    return 0;
}
