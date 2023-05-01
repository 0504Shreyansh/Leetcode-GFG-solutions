class Solution {
public:
    double average(vector<int>& salary) {
        int maximumSalary = 0;
        int minimumSalary = 1e7;
        for(auto currentSalary : salary) {
            maximumSalary = max(maximumSalary, currentSalary);
            minimumSalary = min(minimumSalary, currentSalary);
        }
        double totSalary = 0;
        double cntPeople = 0;
        for(auto currentSalary : salary) {
            if(currentSalary != maximumSalary && currentSalary != minimumSalary) {
                totSalary += currentSalary;
                cntPeople++;
            }
        }
        totSalary /= cntPeople;
        return totSalary;
    }
};