//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution 
{
  public:
    struct Job
    {
        int id,deadline,profit;
        Job(int i,int d,int p)
        {
            id=i;
            deadline=d;
            profit=p;
        }
    };
    vector<int> findMaxJobsAndProfit(vector<Job> &jobs,int &maxDeadline)
    {
        //all jobs have to be finished by maxDeadline
        //0 to maxDeadline-1 are available time slots
        
        vector<bool> scheduled(maxDeadline,false); //time intervals
        int cnt=0,profit=0;
        
        for(int i=0;i<jobs.size();i++)
        {
            bool flag=false;
            for(int j=jobs[i].deadline-1;j>=0;j--)
            {
                if(!scheduled[j])
                {
                    flag=true;
                    cnt++;
                    profit+=jobs[i].profit;
                    scheduled[j]=true;
                    break;
                }
            }
        }
        
        return {cnt,profit};
    }
    vector<int> JobSequencing(vector<int> &id, vector<int> &deadline, vector<int> &profit) 
    {
        int n=id.size();
        vector<Job> jobs;
        int maxDeadline=0;
        for(int i=0;i<n;i++)
        {
            jobs.emplace_back(Job(id[i],deadline[i],profit[i]));
            maxDeadline=max(maxDeadline,deadline[i]);
        }
        sort(jobs.begin(),jobs.end(),[](Job &j1,Job &j2){
            if(j1.profit==j2.profit)
                j1.deadline > j2.deadline; //we'll try to extend the jobs to the deadline so that more and more jobs can be scheduled
            return j1.profit > j2.profit;
        });
        vector<int> ans = findMaxJobsAndProfit(jobs,maxDeadline);
        return ans;
    }
};



//{ Driver Code Starts.
//            Driver program to test methods
int main() {
    int t;
    // testcases
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> jobIDs, deadlines, profits;
        string temp;
        getline(cin, temp);
        istringstream ss1(temp);
        int x;
        while (ss1 >> x)
            jobIDs.push_back(x);

        getline(cin, temp);
        istringstream ss2(temp);
        while (ss2 >> x)
            deadlines.push_back(x);

        getline(cin, temp);
        istringstream ss3(temp);
        while (ss3 >> x)
            profits.push_back(x);

        int n = jobIDs.size();

        Solution obj;
        vector<int> ans = obj.JobSequencing(jobIDs, deadlines, profits);
        cout << ans[0] << " " << ans[1] << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends