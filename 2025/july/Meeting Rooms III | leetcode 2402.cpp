// https://leetcode.com/problems/meeting-rooms-iii/description/?envType=daily-question&envId=2025-07-11


class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<int, vector<int>, greater<int> > available;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>> > engaged;
        vector<int> freq(n, 0);

        for(int i=0; i<n; i++) available.push(i);
        for(auto& meeting : meetings){
            int st = meeting[0], end = meeting[1];

            while(!engaged.empty() && engaged.top().first <= st){
                available.push(engaged.top().second);
                engaged.pop();
            }

            if(!available.empty()){
                int room = available.top(); available.pop();
                freq[room]++;
                engaged.push({end, room});
            } else {
                pair<long long, int> curr = engaged.top(); engaged.pop();
                
                long long meetEndTime = curr.first + (end-st);
                freq[curr.second]++;
                engaged.push({meetEndTime, curr.second});
            }
        }

        int room = 0;
        for(int i=1; i<n; i++){
            if(freq[i] > freq[room]) room = i;
        }
        return room;
    }
};
