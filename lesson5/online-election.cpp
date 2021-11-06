class TopVotedCandidate {
public:
    vector<pair<int, int>> event;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int maxPiao = 0;
        unordered_map<int, int> map;
        
        int leader = -1; 
        for(int i =0; i< persons.size(); i++) {
            if(map.find(persons[i]) == map.end()) {
                map[persons[i]] = 0;
            }
            map[persons[i]]++;
            maxPiao = max(map[persons[i]], maxPiao);
            if(map[persons[i]] == maxPiao) {
                event.push_back({persons[i], times[i]});
            }
        }
    }
    
    int q(int t) {
        int left = 0;
        int right = event.size() -1;
        while(left < right) {
            int mid = (left + right + 1) /2;

            if(event[mid].second <= t) {
                left = mid;
            } else {
                right = mid -1;
            }
        }

        return event[right].first;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */