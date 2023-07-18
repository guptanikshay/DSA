#include <bits/stdc++.h>
using namespace std;

int main()
{
	// your code goes here
	int t;
	cin >> t;
	while (t--)
	{
		int n, flag = 0;
		cin >> n;
		char s[n];
		map<char, vector<int>> index;
		for (int i = 0; i < n; i++)
		{
			cin >> s[i];
			index[s[i]].push_back(i);
		}
		if (n % 3 == 1)
			cout << "YES\n";
		else if (n % 3 == 0)
		{
			for (auto i : index)
			{
				if (i.second.size() % 3 == 0)
				{
					for (int j = 0; j < i.second.size() - 1; j++)
					{
						if ((i.second[j + 1] - i.second[j] - 1) % 3 == 0)
							flag = 1;
						else
							flag = 0;
					}
					if (flag)
					{
						cout << "YES\n";
						break;
					}
				}
			}
			if (!flag)
				cout << "NO\n";
		}
		else
		{
			for (auto i : index)
			{
				if (i.second.size() > 1)
				{
					for (int j = 0; j < i.second.size() - 1; j++)
					{
						if ((i.second[j + 1] - i.second[j] - 1) % 3 == 0)
						{
							flag = 1;
							break;
						}
					}
					if (flag)
					{
						cout << "YES\n";
						break;
					}
				}
			}
			if (!flag)
				cout << "NO\n";
		}
	}
	return 0;
}
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
// 				temp = root->children[first[i] - 'a'];
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