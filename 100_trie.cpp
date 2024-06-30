// Don't just read the comments, read the entire code, you'll get it then.
// A Trie is used instead of map because space utilisation is better in Trie as compared to map. For instance, if we wish to create a dictionary consisting of words like ARE, ARM, ARMORY, ARMS, ARENA, etc, a separate block will be created in a map for all these words but in a Trie the story is different, as it will create separate block only when new letters are encountered.
// Another advantage of Trie is that if we want to search words starting with AR, we will need very less comparisions than required in map.
// Time Complexity of Searching, Insertion and Deletion is O(l), where 'l' is the length of the word.
#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal; // To make sure that if TIME was added to the Trie, we don't get a positive reponse while checking for TIM.
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

    // INSERTION FUNCTION
    void insertUtil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }
        // assumption, word will be in CAPS
        int index = word[0] - 'A';
        TrieNode *child;

        // present
        if (root->children[index] != NULL)
            child = root->children[index];
        // absent
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive Call
        insertUtil(child, word.substr(1));
    }
    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    // SEARCH FUNCTION
    bool searchUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
            return root->isTerminal;
        int index = word[0] - 'A';
        TrieNode *child;
        if (root->children[index] != NULL)
            child = root->children[index];
        else
            return false;
        return searchUtil(child, word.substr(1));
    }
    bool search(string word)
    {
        return searchUtil(root, word);
    }

    // REMOVAL FUNCTION
    /*
     During delete operation we delete the key in bottom up manner using recursion. The following are possible conditions when deleting key from trie,
     * Key may not be there in trie. Delete operation should not modify trie.
     * Key present as unique key (no part of key contains another key (prefix), nor the key itself is prefix of another key in trie).  Delete all the nodes.
     * Key is prefix key of another long key in trie. Unmark the leaf node.
     * Key present in trie, having atleast one other key as prefix key. Delete nodes from end of key until first leaf node of longest prefix key.
     */
    // Returns true if the root has no child
    bool isEmpty(TrieNode *root)
    {
        for (int i = 0; i < 26; i++)
            if (root->children[i])
                return false;
        return true;
    }

    // Recursive function to delete a key from given Trie
    TrieNode *remove(TrieNode *root, string key, int depth = 0)
    {
        // If tree is empty
        if (!root)
            return NULL;

        // If last character of key is being processed
        if (depth == key.size())
        {
            // This node is no more end of word after removal of given key
            if (root->isTerminal)
                root->isTerminal = false;

            // If given is not prefix of any other word
            if (isEmpty(root))
            {
                delete (root);
                root = NULL;
            }
            return root;
        }

        // If not last character, recur for the child obtained using ASCII value
        int index = key[depth] - 'A';
        root->children[index] = remove(root->children[index], key, depth + 1);

        // If root does not have any child (its only child got deleted), and it is not end of another word.
        if (isEmpty(root) && root->isTerminal == false)
        {
            delete (root);
            root = NULL;
        }
        return root;
    }
    void removeWord(string key)
    {
        remove(root, key);
    }
};
int main()
{
    Trie *t = new Trie();

    t->insertWord("ARM");
    t->insertWord("TIME");
    t->insertWord("DO");
    t->insertWord("TIM");

    cout << "Tim Present or Not " << t->search("TIM") << "\n";
    cout << "Time Present or Not " << t->search("TIME") << "\n";
    t->removeWord("TIM");
    cout << "Tim Present or Not " << t->search("TIM") << "\n";
    cout << "Time Present or Not " << t->search("TIME") << "\n";
    return 0;
}