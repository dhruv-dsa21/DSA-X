class Solution {
public:
    int ansq(int query,vector<int> nums,int count){
        for(int i=0;i<nums.size();i++){  
         if(query>=nums[i]){
              query-=nums[i];
              count++;
         }
           
        }
     return count;
    }
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int m = queries.size();
        int n = nums.size();
        vector<int> presum;
        sort(nums.begin(),nums.end());
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            presum.push_back(sum);
        }
        vector<int> ans(m,0);
        for(int i=0;i<m;i++){
             for(int j=0;j<n;j++){
                 if(presum[j]<=queries[i]){
                     ans[i] = j+1;
                 }else{
                     break;
                 }
             }
        }
        return ans;
    }
};