// square root of n using binary search
// square root of n must exist between 0 and n

#include <bits/stdc++.h>
using namespace std;

float sqrt_helper(float low, float high, float n)
{
    float mid = (low + high) / 2;
    if (mid * mid == n)
        return mid;
    else if (mid * mid > n)
    {
        return sqrt_helper(low, mid, n);
    }
    else
        return sqrt_helper(mid, high, n);
}

float sqrtn(float n)
{
    //     if (n == 1)
    //         return 1;
    return sqrt_helper(1, n, n);
}
int main()
{
    cout << sqrt(33) << endl;
    cout << endl;
    return 0;
}