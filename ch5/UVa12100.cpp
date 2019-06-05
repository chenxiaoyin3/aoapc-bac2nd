/*
题意要理解清楚
要注意erase的用法和m的变化
*/
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int t,n,m;
    cin >> t;
    while(t--){
        cin >> n >> m;
        vector<int> jobs;
        for(int i = 0; i < n; i++){
            int job;
            cin >> job;
            jobs.push_back(job);
        }
        int time = 1;
        while(!jobs.empty()){
            vector<int>::iterator it = max_element(jobs.begin(), jobs.end());
            if(it == jobs.end())break;
            int index = it - jobs.begin();
            if(index == m && index == 0){//打印所关注任务
                cout << time << endl;
                break;
            }
            if(index != 0){//放在队尾,不打印
                if(m > 0)m--;
                else if(m == 0)m = jobs.size() - 1;
                jobs.push_back(jobs[0]);
                jobs.erase(jobs.begin());
            }
            else{//打印队首
                if(index < m)m--;
                jobs.erase(it);
                time++;
            }
        }
    }
    return 0;
}
