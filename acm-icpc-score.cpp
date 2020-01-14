#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Team
{
    string sName;
    int time, numProb, *arr;
};

bool compareTeams(Team t1, Team t2)
{
    if(t1.numProb == t2.numProb){
        return t1.time < t2.time;
    }
    return t1.numProb > t2.numProb;
}

int main()
{
    int iT, iP, iS, iTime;
    string sTeamName;
    char cProblemName, cJudgement;

    // input
    cin >> iT >> iP;
    vector<Team> teams;
    for (int iTeamIndex = 0; iTeamIndex < iT; ++iTeamIndex)
    {
        teams.push_back(Team());
        cin >> sTeamName;
        teams[iTeamIndex].sName = sTeamName;
        teams[iTeamIndex].numProb = 0;
        teams[iTeamIndex].time = 0;
        teams[iTeamIndex].arr = new int[iP];
        for (int iProblemIndex = 0; iProblemIndex < iP; ++iProblemIndex)
        {
            teams[iTeamIndex].arr[iProblemIndex] = 0;
        }
    }
    cin >> iS;
    for (int iSolutionIndex = 0; iSolutionIndex < iS; ++iSolutionIndex)
    {
        cin >> sTeamName >> cProblemName >> iTime >> cJudgement;
        for (int iTeamIndex = 0; iTeamIndex < iT; ++iTeamIndex)
        {
            if (teams[iTeamIndex].sName == sTeamName)
            {
                if (cJudgement == 'A')
                {
                    teams[iTeamIndex].numProb++;
                    teams[iTeamIndex].time += iTime + (20 * teams[iTeamIndex].arr[cProblemName - 'A']);
                }
                teams[iTeamIndex].arr[cProblemName - 'A']++;
            }
        }
    }
    sort(teams.begin(), teams.end(), compareTeams);
    for (int iTeamIndex = 0; iTeamIndex < iT; ++iTeamIndex)
    {
        cout << iTeamIndex + 1 << " - " << teams[iTeamIndex].sName << ' ' << teams[iTeamIndex].numProb << ' ';
        if (teams[iTeamIndex].time == 0)
        {
            cout << '-' << endl;
        }
        else
        {
            cout << teams[iTeamIndex].time << endl;
        }
    }

    return 0;
}
