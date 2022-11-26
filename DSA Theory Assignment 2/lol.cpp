// Given a string of digits s, return the number of palindromic subsequences of s having length 5. Since the answer may be very large, return it modulo 109 + 7.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPalindromes(string s) {

        int n = s.length();
        vector<typename> ans;
        for(int i=0;i<n;i++){
            ans[s[i]-'0'].push_back(i);
        }
        int count = 0;
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                for(int k=0;k<5;k++){
                    for(int l=0;l<5;l++){
                        for(int m=0;m<5;m++){
                            if(i==j && j==k && k==l && l==m){
                                count += (ans[i].size()*(ans[i].size()-1)*(ans[i].size()-2)*(ans[i].size()-3)*(ans[i].size()-4))/120;
                            }
                            else if(i==j && j==k && k==l){
                                count += (ans[i].size()*(ans[i].size()-1)*(ans[i].size()-2)*(ans[i].size()-3))/24;
                            }
                            else if(i==j && j==k){
                                count += (ans[i].size()*(ans[i].size()-1)*(ans[i].size()-2))/6;
                            }
                            else if(i==j){
                                count += (ans[i].size()*(ans[i].size()-1))/2;
                            }
                            else{
                                count += ans[i].size()*ans[j].size()*ans[k].size()*ans[l].size()*ans[m].size();
                            }
                        }
                    }
                }
            }
        }
        return count;

    }
};

int main(){
    string s;
    cin>>s;
    Solution obj;
    cout<<obj.countPalindromes(s);
}