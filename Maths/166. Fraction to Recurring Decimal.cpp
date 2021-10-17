//https://leetcode.com/problems/fraction-to-recurring-decimal/
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==0) return "0";
        bool numNegative=0, denNegative=0;
        long long int num=long(numerator), den=long(denominator);
        string ans="";
        if(numerator<0) {
            numNegative=1;
            num=-num;
        }
        if(denominator<0){
            denNegative=1;
            den=-den;
        }
        long long int q=num/den;
        long long int r=num%den;
        ans+=to_string(q);
        if(r==0) ans=ans;
        else{
            ans+=".";
            unordered_map<long long int, long long int> mp;
            while(r){
                if(mp.find(r)!=mp.end()){
                    long long int len=mp[r];
                    ans.insert(len, "(");
                    ans+=")";
                    break;
                }
                else{
                    mp[r]=ans.size();
                    r*=10;
                    q=r/den;
                    r=r%den;
                    ans+=to_string(q);
                }
            }
        }
        if(numNegative && denNegative) ans=ans;
        else if(numNegative || denNegative) ans.insert(0,"-");
        return ans;
    }
};
