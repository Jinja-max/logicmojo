#include <bits/stdc++.h>

using namespace std;

struct Bomb
{
    int x;
    int y;
    int countdown;
    int casualties;
    Bomb(int _x, int _y, int _countdown, int _casualties)
        : x(_x), y(_y), countdown(_countdown), casualties(_casualties) {}
};

struct State
{
    int time;
    int currentIndex;
    vector<int> visited;
    int totalCasualties;
    State(int _time, int _currentIndex, const vector<int> &_visited, int _totalCasualties)
        : time(_time), currentIndex(_currentIndex), visited(_visited), totalCasualties(_totalCasualties) {}
};

struct CompareStates
{
    bool operator()(const State &s1, const State &s2) const
    {

        return s1.time > s2.time;
    }
};

bool isValidEdge(int u, int v, vector<bool> inMST)
{
    if (u == v)
        return false;
    if (inMST[u] == false && inMST[v] == false)
        return false;
    else if (inMST[u] == true && inMST[v] == true)
        return false;
    return true;
}

void primMST(int cost[][10])
{
    vector<bool> inMST(10, false);

    inMST[0] = true;
    int edge_count = 0, mincost = 0;
    while (edge_count < 10 - 1)
    {
        int min = INT_MAX, a = -1, b = -1;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (cost[i][j] < min)
                {
                    if (isValidEdge(i, j, inMST))
                    {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }
        if (a != -1 && b != -1)
        {
            printf("Edge %d:(%d, %d) cost: %d \n",
                   edge_count++, a, b, min);
            mincost = mincost + min;
            inMST[b] = inMST[a] = true;
        }
    }
    printf("\n Minimum cost= %d \n", mincost);
}

int calculateMSTHeuristic(const vector<Bomb> &bombs, const vector<int> &visited)
{
    int remainingBombs = bombs.size() - visited.size();
    if (remainingBombs == 0)
        return 0;

    return 0;
}

// A* search algorithm to minimize casualties and time
pair<int, int> minimizeCasualties(const vector<Bomb> &bombs)
{
    int n = bombs.size();

    priority_queue<State, vector<State>, CompareStates> pq;

    State initial(0, 0, {0}, 0);
    pq.push(initial);

    while (!pq.empty())
    {
        State currentState = pq.top();
        pq.pop();

        if (currentState.visited.size() == n)
        {

            return {currentState.time, currentState.totalCasualties};
        }

        for (int i = 0; i < n; ++i)
        {
            if (find(currentState.visited.begin(), currentState.visited.end(), i) == currentState.visited.end())
            {

                int travelTime = abs(bombs[currentState.currentIndex].x - bombs[i].x) + abs(bombs[currentState.currentIndex].y - bombs[i].y);

                vector<int> newVisited = currentState.visited;
                newVisited.push_back(i);
                int newTime = currentState.time + travelTime + bombs[i].countdown;
                int newTotalCasualties = currentState.totalCasualties + bombs[i].casualties;

                int heuristic = calculateMSTHeuristic(bombs, newVisited);

                State newState(newTime, i, newVisited, newTotalCasualties);
                pq.push(newState);
            }
        }
    }

    return {-1, -1};
}

int main()
{
    vector<Bomb> bombs = {
        {1, 1, 8, 20},
        {2, 2, 3, 40},
        {3, 3, 11, 10}};

    pair<int, int> result = minimizeCasualties(bombs);

    int minTime = result.first;
    int minCasualties = result.second;
    minCasualties = 0;
    if (minTime != -1)
    {
        cout << "Minimum time to defuse all bombs: " << minTime << " seconds" << endl;
        cout << "Corresponding minimum casualties: " << minCasualties << endl;
    }
    else
    {
        cout << "Unable to defuse all bombs within the given constraints." << endl;
    }

    return 0;
}
