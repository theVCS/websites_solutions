#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
#define INF 1000000000
#define endl "\n"
#define all(x) (x).begin(), (x).end()

struct process
{
    int at, bt, prior, abt, st, ct, wt, tat, rt;

    process()
    {
        at = bt = prior = abt = st = ct = wt = tat = rt = -1;
    }
};

bool cmp(process a, process b)
{
    return a.at < b.at;
}

class PrePriorSch
{
private:
    int n;
    vector<process> pro;
    float avgwt, avgtat, avgrt;

public:
    PrePriorSch()
    {
        avgwt = avgtat = avgrt = 0;

        // cout << "Enter the no of process ";
        cin >> n;

        process p;

        REP(i, 0, n)
        {
            cin >> p.at >> p.bt >> p.prior;
            p.abt = p.bt;
            pro.push_back(p);
        }

        sort(all(pro), cmp);
    }

    void runProcess()
    {
        int currTime = 0;
        int currIndex = 1;
        priority_queue<pii, vector<pii>> q;
        q.push({pro[0].prior, 0});

        while (!q.empty())
        {
            pii p = q.top();
            q.pop();

            bool flag = true;

            // checking if element have same priority
            while (!q.empty())
            {
                if (q.top().first == p.first)
                {
                    flag = false;
                    q.pop();
                    queue<int> readyQue;

                    readyQue.push(p.second);
                    int qt = 2;

                    while (!readyQue.empty())
                    {
                        int proIndex = readyQue.front();
                        readyQue.pop();

                        if (pro[proIndex].st == -1)
                        {
                            pro[proIndex].st = currTime;
                        }

                        if (pro[proIndex].bt > qt)
                        {
                            pro[proIndex].bt -= qt;
                            currTime += qt;
                        }
                        else
                        {
                            currTime += pro[proIndex].bt;
                            pro[proIndex].bt = 0;
                        }

                        while (!q.empty() && pro[q.top().second].at <= currTime && q.top().first == p.first)
                        {
                            readyQue.push(q.top().second);
                            q.pop();
                        }

                        if (pro[proIndex].bt)
                            readyQue.push(proIndex);

                        pro[proIndex].ct = currTime;
                    }
                }

                if (flag)
                {
                    cout << p.second << endl;

                    // setting the starting time
                    if (pro[p.second].st == -1)
                        pro[p.second].st = currTime;

                    // setting completion time
                    currTime += pro[p.second].bt; // increasing currtime by one
                    pro[p.second].ct = currTime;
                    pro[p.second].bt = 0;

                    // checking if the processes after currIndex has come in queue
                    while (currIndex < n && pro[currIndex].at <= currTime)
                    {
                        p.first = pro[currIndex].prior;
                        p.second = currIndex++;
                        q.push(p);
                    }
                }
            }

            REP(i, 0, n)
            {
                pro[i].tat = pro[i].ct - pro[i].at;
                pro[i].wt = pro[i].tat - pro[i].abt;
                pro[i].rt = pro[i].st - pro[i].at;

                avgtat += pro[i].tat;
                avgwt += pro[i].wt;
                avgrt += pro[i].rt;
            }

            avgtat /= 1.0 * n;
            avgwt /= 1.0 * n;
            avgrt /= 1.0 * n;
        }
    }

    void print()
    {
        cout << "AT"
             << "\t"
             << "BT"
             << "\t"
             << "CT"
             << "\t"
             << "TAT"
             << "\t"
             << "WT"
             << "\t"
             << "RT" << endl;

        for (process p : pro)
        {
            cout << p.at << "\t" << p.abt << "\t" << p.ct << "\t" << p.tat << "\t" << p.wt << "\t" << p.rt << endl;
        }

        cout << "Average Waiting Time -> " << avgwt << endl;
        cout << "Average Turn Around Time -> " << avgtat << endl;
        cout << "Average Response Time -> " << avgrt << endl;
    }
};

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    PrePriorSch p;
    p.runProcess();
    p.print();

    return 0;
}
