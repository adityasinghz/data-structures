#include <bits/stdc++.h>
using namespace std;

string divisorsSame(int n)
{
    // To store the count of even
    // factors and odd factors
    int even_div = 0, odd_div = 0;

    // Loop till [1, sqrt(N)]
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {

            // If divisors are equal
            // add only one
            if (n / i == i)
            {

                // Check for even
                // divisor
                if (i % 2 == 0)
                {
                    even_div++;
                }

                // Odd divisor
                else
                {
                    odd_div++;
                }
            }

            // Check for both divisor
            // i.e., i and N/i
            else
            {

                // Check if i is odd
                // or even
                if (i % 2 == 0)
                {
                    even_div++;
                }
                else
                {
                    odd_div++;
                }

                // Check if N/i is odd
                // or even
                if (n / i % 2 == 0)
                {
                    even_div++;
                }
                else
                {
                    odd_div++;
                }
            }
        }
    }

    // Return true if count of even_div
    // and odd_div are equals
    if (even_div > odd_div)
        return "SELL";
    else if (odd_div > even_div)
        return "SELL";
    return "PASS";
}

int main()
{
    long n;
    cin >> n;
    string answer = divisorsSame(n);
    cout << answer << endl;
}
