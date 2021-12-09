#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, int>
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define RREP(i, a, b) for (int i = a; i >= b; i--)
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238

#define maxN 1000001
#define INF 1000000000
#define mod 1000000007
#define printd(x) cout << fixed << setprecision(10) << x
// int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
// int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
// int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

const int sz = 26;

template <class T>
class Trie
{
    struct Node
    {
        bool endOfWord;
        Node *arr[sz];

        Node()
        {
            endOfWord = false;
            REP(i, 0, sz - 1)
            arr[i] = NULL;
        }
    };

    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(T &s)
    {
        Node *temp = root;

        for (char c : s)
        {
            int index = c - 'a';

            if (temp->arr[index] == NULL)
                temp->arr[index] = new Node();

            temp = temp->arr[index];
        }

        temp->endOfWord = true;
    }

    bool search(string &s, int in)
    {
        Node *temp = root;

        REP(i, in, s.size() - 1)
        {
            int index = s[i] - 'a';

            if (temp->arr[index] == NULL)
                return false;

            temp = temp->arr[index];
        }

        return true;
    }
};

bool cmp(string &a, string &b)
{
    return a.size() < b.size();
}

map<string,int>mp;

bool cmp1(string &s, string &b)
{
    return mp[s]<mp[b];
}

class Solution
{
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
    {
        vector<string> res;

        REP(i,0,words.size()-1)mp[words[i]] = i;

        sort(words.begin(), words.end(), cmp);
        Trie<string> trie;

        for (string word : words)
        {
            // if (trie.search(word))
            // res.push_back(word);
            int index = 0;

            while (true)
            {
                int curr = trie.search(word, index);

                if (curr == index)
                    break;

                if (curr == word.size())
                {
                    res.push_back(word);
                    break;
                }
            }

            trie.insert(word);
        }

        sort(res.begin(), res.end(), cmp1);
        return res;
    }
};

void solve()
{
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    int t = 1;

    // cin >> t;

    REP(tc, 1, t)
    {
        // cout<<"Case "<<tc<<":"<<endl;
        solve();
    }

    return 0;
}