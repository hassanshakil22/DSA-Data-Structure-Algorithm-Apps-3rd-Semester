#include <bits/stdc++.h>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    int target = 0;
    for (char c : s1) {
        if (c == '+') target++;
        else target--;
    }
    int current = 0, q = 0;
    for (char c : s2) {
        if (c == '+') current++;
        else if (c == '-') current--;
        else q++; 
    }

    int diff = target - current;


    if ((diff + q) % 2 != 0 || abs(diff) > q) {
        cout << fixed << setprecision(12) << 0.0 << "\n"; // doing this to keep non exponential and decimal uptil 10 places
        return 0;
    }

    int k = (diff + q) / 2;
    double ways = 1;
    for (int i = 1; i <= k; i++) {
        ways *= (q - i + 1);
        ways /= i;
    }

    double total = pow(2, q);
    double probability = ways / total;

    cout << fixed << setprecision(12) << probability << "\n";
    return 0;
}
