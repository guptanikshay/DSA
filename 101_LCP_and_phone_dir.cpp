// LONGEST COMMON PREFIX: Write a function to find the longest common prefix string amongst an array of strings. If there is no common prefix, return an empty string "". For instance, if you have [flowers, flow, flight], the LCP is 'fl'.
// class TrieNode
// {
// public:
// 	char data;
// 	TrieNode *children[26];
// 	TrieNode(char c)
// 	{
// 		data = c;
// 		for (int i = 0; i < 26; i++)
// 			children[i] = NULL;
// 	}
// };
// class Trie
// {
// public:
// 	TrieNode *root;
// 	Trie()
// 	{
// 		root = new TrieNode('\0');
// 	}
// 	void insertUtil(TrieNode *root, string word)
// 	{
// 		if (word.length() == 0)
// 			return;
// 		int index = word[0] - 'a';
// 		TrieNode *child;
// 		if (root->children[index])
// 			child = root->children[index];
// 		else
// 		{
// 			child = new TrieNode(word[0]);
// 			root->children[index] = child;
// 		}
// 		insertUtil(child, word.substr(1));
// 	}
// 	void insert(string word)
// 	{
// 		insertUtil(root, word);
// 	}
// 	int childCount(TrieNode *root)
// 	{
// 		if (!root)
// 			return 0;
// 		int count = 0;
// 		for (int i = 0; i < 26; i++)
// 		{
// 			if (root->children[i])
// 				count++;
// 		}
// 		return count;
// 	}
// 	void LCP(string first, string &ans)
// 	{
// 		TrieNode *temp = root;
// 		for (int i = 0; i < first.length(); i++)
// 		{
// 			if (childCount(temp) == 1)
// 			{
// 				ans.push_back(first[i]);
// 				temp = root->children[(int)(first[i] - 'a')];
// 			}
// 			else
// 				break;
// 		}
// 	}
// };
// string longestCommonPrefix(vector<string> &strs)
// {
// 	Trie *t = new Trie();
// 	for (int i = 0; i < strs.size(); i++)
// 	{
// 		t->insert(strs[i]);
// 	}
// 	int min = 201;
// 	string mini;
// 	for (auto i : strs)
// 	{
// 		if (i.length() < min)
// 		{
// 			mini = i;
// 			min = i.length();
// 		}
// 	}
// 	string ans = "";
// 	t->LCP(mini, ans);
// 	return ans;
// }

// IMPLEMENT A PHONE DIRECTORY: You will be given a string and you are supposed to print all the strings in the given array that have this string as a prefix. Just like in 'Contacts' app, when we search for 'li', for instance, we will get all the contacts starting with 'li', that's what you need to implement.
#include <bits/stdc++.h>
using namespace std;
class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;
    TrieNode(char c)
    {
        data = c;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode('\0');
    }
    void insertUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }
        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL)
            child = root->children[index];
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }
    void insertWord(string word)
    {
        insertUtil(root, word);
    }
    void printSuggestions(TrieNode *curr, vector<string> &temp, string prefix)
    {
        if (curr->isTerminal)
            temp.push_back(prefix);
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            TrieNode *next = curr->children[ch - 'a'];
            if (next)
            {
                prefix.push_back(ch);
                printSuggestions(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }
    vector<vector<string>> getSuggestions(string str)
    {
        TrieNode *prev = root;
        vector<vector<string>> output;
        string prefix = "";
        for (int i = 0; i < str.length(); i++)
        {
            char lastch = str[i];
            prefix.push_back(lastch);
            TrieNode *curr = prev->children[lastch - 'a'];
            if (!curr)
                break;
            vector<string> temp;
            printSuggestions(curr, temp, prefix);
            output.push_back(temp);
            temp.clear();
            prev = curr;
        }
        return output;
    }
};
vector<vector<string>> phoneDirectory(vector<string> &contactList, string &queryStr)
{
    //    Write your code here.
    Trie *t = new Trie();
    for (int i = 0; i < contactList.size(); i++)
        t->insertWord(contactList[i]);

    return t->getSuggestions(queryStr);
}

int main()
{

    return 0;
}