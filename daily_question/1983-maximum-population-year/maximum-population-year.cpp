class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int n=logs.size();
        vector<int>birth(n),death(n);
        for(int i=0;i<n;i++){
            birth[i]=logs[i][0];
            death[i]=logs[i][1];
        }
        sort(birth.begin(),birth.end());
        sort(death.begin(),death.end());
        int i=0,j=0,pop=0,max_pop=0,year=birth[0];
        while(i<n){
            if(birth[i]<death[j]) {
                pop++;
                if(max_pop<pop){
                   max_pop=pop;
                   year=birth[i];
                }
                i++;
            }
            else{
                pop--;
                j++;
            }
        }
        return year;
    }
};