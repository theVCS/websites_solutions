#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define RREP(i, a, b) for (int i = a; i >= b; i--)
// #define endl "\n"
#define all(x) (x).begin(), (x).end()

int m, n;

struct history
{
    string user, page;
    ll enterTime, exitTime;
};
vector<history> his;

int val(string s)
{
    int ans = 0;
    int p = 1;

    reverse(all(s));

    for (char c : s)
    {
        ans += (c - '0') * p;
        p *= 10;
    }

    return ans;
}

bool check(string s, string t)
{
    for (int i = 0, j = t.size() - 1; j < s.size(); i++, j++)
    {
        bool flag = true;

        REP(k,i,j)
        {
            if(s[k]!=t[k-i])
            {
                flag = false;
                break;
            }
        }

        if(flag)return true;
    }

    return false;
}

map<string,int>mapper;

void changer(string &s)
{
    for(auto e: mapper)
    {
        if(check(s, e.first))
        {
            s = e.first;
            return;
        }
    }
}

void addHistory(string &s)
{
    history h;
    int index = 0;
    string str;

    while (true)
    {
        if (s[index] == ',')
        {
            index++;
            break;
        }
        str.push_back(s[index++]);
    }

    h.user = str;
    str.clear();

    while (true)
    {
        if (s[index] == ',')
        {
            index++;
            break;
        }

        str.push_back(s[index++]);
    }

    while (str.front() == '/')
    {
        str.erase(str.begin());
    }

    int sz = 0;
    string p;
    for (char c : str)
    {
        if (c == '/')
            break;
        p.push_back(c);
    }

    str = p;
    changer(str);
    h.page = str;
    str.clear();

    time_t t = time(0);
    tm *now = localtime(&t);

    while (true)
    {
        if (s[index] == '-')
        {
            index++;
            break;
        }

        str.push_back(s[index++]);
    }

    now->tm_year = val(str);
    str.clear();

    //month
    while (true)
    {
        if (s[index] == '-')
        {
            index++;
            break;
        }

        if (s[index] == '0' && str.size() == 0)
        {
            index++;
            continue;
        }

        str.push_back(s[index++]);
    }

    now->tm_mon = val(str);
    str.clear();

    //day
    while (true)
    {
        if (s[index] == ' ')
        {
            index++;
            break;
        }

        if (s[index] == '0' && str.size() == 0)
        {
            index++;
            continue;
        }

        str.push_back(s[index++]);
    }

    now->tm_mday = val(str);
    str.clear();

    // hr
    while (true)
    {
        if (s[index] == ':')
        {
            index++;
            break;
        }

        str.push_back(s[index++]);
    }

    now->tm_hour = val(str);
    str.clear();

    // min
    while (true)
    {
        if (s[index] == ':')
        {
            index++;
            break;
        }

        str.push_back(s[index++]);
    }

    now->tm_min = val(str);
    str.clear();

    // min
    while (true)
    {
        if (s[index] == ',')
        {
            index++;
            break;
        }

        str.push_back(s[index++]);
    }

    now->tm_sec = val(str);
    str.clear();
    h.enterTime = 31556952LL * (now->tm_year - 2000) + 2630000LL * (now->tm_mon) + 86400LL * (now->tm_mday) + 3600LL * (now->tm_hour) + 60LL * (now->tm_min) + (now->tm_sec);

    //year
    while (true)
    {
        if (s[index] == '-')
        {
            index++;
            break;
        }

        str.push_back(s[index++]);
    }
    now->tm_year = val(str);
    str.clear();

    //month
    while (true)
    {
        if (s[index] == '-')
        {
            index++;
            break;
        }

        if (s[index] == '0' && str.size() == 0)
        {
            index++;
            continue;
        }

        str.push_back(s[index++]);
    }
    now->tm_mon = val(str);
    str.clear();

    //day
    while (true)
    {
        if (s[index] == ' ')
        {
            index++;
            break;
        }

        if (s[index] == '0' && str.size() == 0)
        {
            index++;
            continue;
        }

        str.push_back(s[index++]);
    }
    now->tm_mday = val(str);
    str.clear();

    // hr
    while (true)
    {
        if (s[index] == ':')
        {
            index++;
            break;
        }

        str.push_back(s[index++]);
    }
    now->tm_hour = val(str);
    str.clear();

    // min
    while (true)
    {
        if (s[index] == ':')
        {
            index++;
            break;
        }

        str.push_back(s[index++]);
    }
    now->tm_min = val(str);
    str.clear();

    // sec
    while (index < s.size())
    {
        str.push_back(s[index++]);
    }
    now->tm_sec = val(str);
    str.clear();

    h.exitTime = 31556952LL * (now->tm_year - 2000) + 2630000LL * (now->tm_mon) + 86400LL * (now->tm_mday) + 3600LL * (now->tm_hour) + 60LL * (now->tm_min) + (now->tm_sec);

    his.push_back(h);
}

string s, str;

struct intent
{
    ll duration;
    ll frequency;
    ll recency;
    string x;

    intent(string s)
    {
        x = s;
        duration = frequency = recency = 0;
    }
};


struct user
{
    string userName;
    ll enterTime;
    vector<intent> inte;

    user()
    {
        for(auto e: mapper)
        {
            inte.push_back(intent(e.first));
        }
    }
};
int ind = -1;
vector<user> users;
map<string, int> mp;

void addUser(string &s)
{
    user u;
    int index = 0;
    string str;

    // user name
    while (true)
    {
        if (s[index] == ',')
        {
            index++;
            break;
        }
        str.push_back(s[index++]);
    }

    u.userName = str;
    str.clear();

    time_t t = time(0);
    tm *now = localtime(&t);

    //year
    while (true)
    {
        if (s[index] == '-')
        {
            index++;
            break;
        }

        str.push_back(s[index++]);
    }
    now->tm_year = val(str);
    str.clear();

    //month
    while (true)
    {
        if (s[index] == '-')
        {
            index++;
            break;
        }

        if (s[index] == '0' && str.size() == 0)
        {
            index++;
            continue;
        }

        str.push_back(s[index++]);
    }
    now->tm_mon = val(str);
    str.clear();

    //day
    while (true)
    {
        if (s[index] == ' ')
        {
            index++;
            break;
        }

        if (s[index] == '0' && str.size() == 0)
        {
            index++;
            continue;
        }

        str.push_back(s[index++]);
    }
    now->tm_mday = val(str);
    str.clear();

    // hr
    while (true)
    {
        if (s[index] == ':')
        {
            index++;
            break;
        }

        str.push_back(s[index++]);
    }
    now->tm_hour = val(str);
    str.clear();

    // min
    while (true)
    {
        if (s[index] == ':')
        {
            index++;
            break;
        }

        str.push_back(s[index++]);
    }
    now->tm_min = val(str);
    str.clear();

    // sec
    while (index < s.size())
    {
        str.push_back(s[index++]);
    }
    now->tm_sec = val(str);
    str.clear();

    u.enterTime = 31556952LL * (now->tm_year - 2000) + 2630000LL * (now->tm_mon) + 86400LL * (now->tm_mday) + 3600LL * (now->tm_hour) + 60LL * (now->tm_min) + (now->tm_sec);

    users.push_back(u);
    mp[u.userName]=++ind;
}

bool cmp1(intent a, intent b)
{
    if(a.duration == b.duration && a.frequency == b.frequency)
        return a.recency > b.recency;
    
    if(a.duration == b.duration)
        return a.frequency > b.frequency;
    
    return a.duration > b.duration;
}

bool cmp2(user a, user b)
{
    return a.userName < b.userName;
}

void addIntent()
{
    for(auto e: his)
    {
        int index = mp[e.user];
        int x = mapper[e.page];

        if(users[index].enterTime - e.exitTime > 7200 || e.exitTime - e.enterTime < 5)continue;

        users[index].inte[x].frequency++;
        users[index].inte[x].duration+=e.exitTime-e.enterTime;
        users[index].inte[x].recency = e.exitTime;
    }

    for(auto &e: users)
    {
        sort(all(e.inte), cmp1);
    }

    sort(all(users), cmp2);
}

void solve()
{

    // cout<<check("disputes", "dispute")<<endl;
    mapper["change_pin"];
    mapper["dispute"];
    mapper["flights"];
    mapper["hotels"];
    mapper["offers"];
    mapper["payment"];
    mapper["referral"];
    mapper["rewards"];
    mapper["statement"];
    mapper["transaction"];

    int timer = -1;

    for(auto &e: mapper)
    {
        e.second = ++timer;
    }

    cin >> m;

    REP(i, 1, m)
    {
        // getline(cin, s);
        cin >> s;
        cin >> str;
        s = s + ' ' + str;
        cin >> str;
        s = s + ' ' + str;
        // cin>>s;
        addHistory(s);
    }

    // for (auto e : his)
    // {
    //     cout << e.user << " " << e.page << " " << e.enterTime << " " << e.exitTime << endl;
    // }

    cin >> n;

    REP(i, 1, n)
    {
        cin >>s;
        cin >>str;
        s = s + ' ' + str;
        addUser(s);
    }

    // for(auto e: users)
    // {
    //     cout<<e.userName<<" "<<e.enterTime<<endl;
    // }

    // for(auto e: mp)
    // {
    //     cout<<e.first<<" "<<e.second<<endl;
    // }

    addIntent();

    for(auto e: users)
    {
        cout<<e.userName<<',';
        cout<<e.inte[0].x<<","<<e.inte[1].x<<","<<e.inte[2].x;
        cout<<endl;
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // ifstream filptr("input.txt");
    // ofstream outpter("output.txt");

    // filptr >> input;
    // outpter << output;

    int t = 1;

    //cin >> t;

    while (t--)
    {
        solve();
    }

    //filptr.close();
    //outpter.close();

    return 0;
}