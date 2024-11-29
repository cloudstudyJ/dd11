#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;

unsigned long long factorial(const unsigned int& num) {
    static unsigned long long dp[32]{ 1, 1, 2, };

    if (dp[num] != 0)
        return dp[num];

    else {
        dp[num] = num * factorial(num - 1);

        return dp[num];
    }
}

unsigned long long combination(int n, int r) { return (factorial(n) / ((factorial(n - r) * factorial(r)))); }

int main() {
    cout << combination(10, 5) << endl;
    cout << combination(20, 8) << endl;

    return 0;
}