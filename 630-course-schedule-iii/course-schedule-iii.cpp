class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),[](auto &a,auto &b){
            return a[1]<b[1];
        });

        int day=0;
        //int count=0;
        priority_queue<int>pq;

        int n=courses.size();
        for(int i=0;i<n;i++){
            day+=courses[i][0];
            pq.push(courses[i][0]);
            if(day>courses[i][1]){
                day-=pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};