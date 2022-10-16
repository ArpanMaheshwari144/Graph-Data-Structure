// Word Ladder - I [https://bit.ly/3PuJxk3]

#include <bits/stdc++.h>
using namespace std;

int wordLadderLength(string startWord, string targetWord, vector<string> &wordList)
{
    queue<pair<string, int>> q;
    q.push({startWord, 1});
    unordered_set<string> st(wordList.begin(), wordList.end());
    st.erase(startWord);
    while (!q.empty())
    {
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();
        if (word == targetWord)
        {
            return steps;
        }

        for (int i = 0; i < word.size(); i++)
        {
            char originalWord = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;

                // if word was exists in the set
                if (st.find(word) != st.end())
                {
                    st.erase(word);
                    q.push({word, steps + 1});
                }
            }
            word[i] = originalWord;
        }
    }
    return 0;
}

int main()
{
    string startWord = "der", targetWord = "dfs";
    vector<string> wordList = {"des", "der", "dfr", "dgt", "dfs"};

    int ans = wordLadderLength(startWord, targetWord, wordList);
    cout << "The length of the smallest transformation sequence from " << startWord << " to " << targetWord << " is : " << ans;

    return 0;
}
