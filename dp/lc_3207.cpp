#include <bits/stdc++.h>
using namespace std;

long long recursiveSolve(vector<int> &enemyEnergies, int currentEnergy)
{
    long long a = 0, b = 0;
    for (int i = 0; i < enemyEnergies.size(); i++)
    {
        if (enemyEnergies[i] != -1 && currentEnergy >= enemyEnergies[i])
        {
            // enemyEnergies[i]=-1;
            a = max(a, 1 + recursiveSolve(enemyEnergies, currentEnergy - enemyEnergies[i]));
        }
    }
    if (a >= 1)
    {
        for (int i = 0; i < enemyEnergies.size(); i++)
        {
            if (enemyEnergies[i] != -1)
            {
                enemyEnergies[i] = -1;
                b = max(b, recursiveSolve(enemyEnergies, currentEnergy + enemyEnergies[i]));
            }
        }
    }

    cout << endl;
    cout << "enemyEnergies: ";
    for (auto it : enemyEnergies)
        cout << it << " ";
    cout << "   currentEnergy: " << currentEnergy << "           a:" << a << " b:" << b << endl;

    return max(a, b);
}

long long maximumPoints(vector<int> &enemyEnergies, int currentEnergy)
{
    return recursiveSolve(enemyEnergies, currentEnergy);
}

int main()
{
    vector<int> s = {3, 2, 2};
    long long k = maximumPoints(s, 2);
    cout << endl
         << endl
         << endl
         << "answer is: " << k;
    cout << endl;
    return 0;
}