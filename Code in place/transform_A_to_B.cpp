// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     long long a, b;
//     cin >> a >> b;

//     vector<long long> path;
//     path.push_back(b);
//     while (b > a) {
//         if (b % 10 == 1) {
//             b /= 10;
//             path.push_back(b);
//         } 
//         else if (b % 2 == 0) {
//             b /= 2;
//             path.push_back(b);
//         }  
//         else {
//             break;
//         }
//     }

//     if (b == a) {
//         cout << "YES\n";
//         cout << path.size() << "\n";
//         reverse(path.begin(), path.end());
//         for (auto x : path) cout << x << " ";
//         cout << "\n";
//     } else {
//         cout << "NO\n";
//     }
// }



#include <stdio.h>


int main 