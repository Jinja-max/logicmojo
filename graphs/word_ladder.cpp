#include <bits/stdc++.h>
using namespace std;

int isConnected(string word, string s)
{
    int m = word.length();
    int n = s.length();
    if (m != n)
        return 0;
    int diff = 0;
    for (int i = 0; i < m; i++)
    {
        if (word[i] != s[i])
            diff++;
        if (diff > 1)
            return 0;
    }
    return diff;
}
int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    int m = wordList.size();
    int vis[m] = {0};
    queue<string> q;
    q.push(beginWord);
    int level = 1;
    while (!q.empty())
    {
        int l = q.size();
        while (l-- != 0)
        {
            string front = q.front();
            q.pop();
            for (int i = 0; i < wordList.size(); i++)
            {
                if (!vis[i] && isConnected(front, wordList[i]))
                {
                    if (wordList[i] == endWord)
                        return level + 1;
                    vis[i] = 1;
                    q.push(wordList[i]);
                }
            }
        }
        level++;
    }
    return 0;
}

int main()
{
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    cout << ladderLength(beginWord, endWord, wordList);
    cout << endl;
    return 0;
}