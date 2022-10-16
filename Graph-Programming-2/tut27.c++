// Word Ladder II [https://bit.ly/3As1nQw]

#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> findSequences(string beginWord, string endWord, vector<string> &wordList)
{
    unordered_set<string> st(wordList.begin(), wordList.end());
    queue<vector<string>> q;
    q.push({beginWord});
    vector<string> usedOnLevel;
    usedOnLevel.push_back(beginWord);
    int level = 0;
    vector<vector<string>> ans;
    while (!q.empty())
    {
        vector<string> vec = q.front();
        q.pop();

        // erase all words that has been used in the previous levels to transform
        if (vec.size() > level)
        {
            level++;
            for (auto it : usedOnLevel)
            {
                st.erase(it);
            }
            usedOnLevel.clear();
        }

        string word = vec.back();

        // store the answers
        if (word == endWord)
        {
            // the first sequence where we reached end
            if (ans.size() == 0)
            {
                ans.push_back(vec);
            }
            else if (ans[0].size() == vec.size())
            {
                ans.push_back(vec);
            }
        }
        for (int i = 0; i < word.size(); i++)
        {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if (st.count(word) > 0)
                {
                    vec.push_back(word);
                    q.push(vec);

                    // mark as visited on the level
                    usedOnLevel.push_back(word);
                    vec.pop_back();
                }
            }
            word[i] = original;
        }
    }
    return ans;
}

int main()
{
    string startWord = "der", targetWord = "dfs";
    vector<string> wordList = {"des", "der", "dfr", "dgt", "dfs"};

    vector<vector<string>> ans = findSequences(startWord, targetWord, wordList);
    if (ans.size() == 0)
    {
        cout << -1;
    }
    else
    {
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
