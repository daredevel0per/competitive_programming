class Solution {
public:
    vector<vector<int>> k2sum(vector<int>&nums,int i, int target){
        int l=i+1;
        int r=nums.size()-1;
        set<vector<int>>ans;
        while (l<r){
            int sum=nums[l]+nums[r];
            if (sum==target){
                vector<int>temp;
                temp.push_back(nums[l]);
                temp.push_back(nums[r]);
                ans.insert(temp);
                l++;
            }
            else if (sum>target){
                r--;
            }
            else {
                l++;
            }
        }
        vector<vector<int>>res(ans.begin(),ans.end());
        return res;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        set<vector<int>>ans;
        int target=0;
        for (int i=0; i<n-2; i++){
            if (i>0 && nums[i]==nums[i-1]){
                continue;
            }
            vector<vector<int>>twosum=k2sum(nums,i,target-nums[i]);
            if (twosum.size()>0){
                for (auto j:twosum){
                    vector<int>temp;
                    temp.push_back(nums[i]);
                    temp.push_back(j[0]);
                    temp.push_back(j[1]);
                    ans.insert(temp);
                }
            }
        }
        vector<vector<int>>res(ans.begin(),ans.end());
        return res;
    }
};
