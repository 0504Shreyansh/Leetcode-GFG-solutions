class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> qR, qD;
        int n = senate.size();
        for(int i = 0; i < n; i++) {
            (senate[i] == 'R') ? qR.push(i) : qD.push(i);
        }
        while(!qR.empty() && !qD.empty()) {
            int idxR = qR.front();
            int idxD = qD.front();
            qR.pop(); qD.pop();
            (idxR < idxD) ? qR.push(idxR+n) : qD.push(idxD+n);
        }
        return (qR.size() > 0) ? "Radiant" : "Dire";
    }
};