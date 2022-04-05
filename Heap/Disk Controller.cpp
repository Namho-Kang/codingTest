#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a, vector<int> b)
{
    if (a[0] == b[0])
    {
        return a[1] < b[1];
    }
    return a[0] < b[0];
}

int solution(vector<vector<int>> jobs) {
    int jobsSize = jobs.size();
    sort(jobs.begin(), jobs.end(), cmp);
    int start = 0, end = 0, totalTime = 0;

    while (!jobs.empty())
    {
        int iIndex = -1;
        int leastTime = 1001;
        for (int i = 0; i < jobs.size(); i++)
        {
            if (jobs[i][0] <= end)
            {
                if (jobs[i][1] < leastTime)
                {
                    leastTime = jobs[i][1];
                    iIndex = i;
                }
            }
			else break;
        }

        if (iIndex == -1)
        {
            iIndex = 0;
            start = jobs[iIndex][0];
            leastTime = jobs[iIndex][1];
        }
        else
            start = max(end, jobs[iIndex][0]);
        end = start + leastTime;
        totalTime += (end - jobs[iIndex][0]); 
        jobs.erase(jobs.begin() + iIndex);
    }

    return totalTime / jobsSize;
}