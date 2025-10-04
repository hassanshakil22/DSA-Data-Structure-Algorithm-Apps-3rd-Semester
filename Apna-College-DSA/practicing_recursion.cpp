#include <iostream>

using namespace std;

void printNum(int n)
{
    if (n == 1)
    {
        cout << n << " ";
        return;
    }
    cout << n << " ";
    printNum(n - 1);
    cout << n << " ";
}

int factorial(int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
    ;
}

int sumOfN(int n){
    if (n==1) return 1;
    cout << n << endl;
    return n+sumOfN(n-1);
}


int main()
{
    printNum(5);
    cout << factorial(6) << endl;
    cout << sumOfN(6) << endl;
    return 0;
}