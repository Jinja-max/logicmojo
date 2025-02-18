#include <bits/stdc++.h>
using namespace std;

string removeKdigits(string num, int k)
{

    if (k >= num.length())
        return "0";
    int i = 0;
    while (k != 0 && i < num.size() - 1)
    {
        if (num[i] > num[i + 1])
        {
            num.erase(i, 1);
            cout << num << " " << i << endl;
            k--;
        }
        else
            i++;
    }
    i = num.length() - 1;
    while (k != 0 && i >= 1)
    {
        if (num[i - 1] <= num[i])
        {
            num.erase(i, 1);
            cout << num << " " << i << endl;
            k--;
        }
        else
            i--;
    }
    while (num[0] == '0' && num.size() > 1)
        num.erase(0, 1);
    return num;
}

int main()
{
    cout << removeKdigits("1234567890", 9) << endl;
    cout << endl;
    return 0;
}