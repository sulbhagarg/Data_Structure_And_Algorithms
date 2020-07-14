/* Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string. */

class Solution {
public:
    string multiply(string num1, string num2) {
        vector<string> rows;
        int n=num1.length();
        int m=num2.length();
        int t=0, flag=0;
        for(int i=m-1;i>=0;i--){
            int x=num2[i]-'0';
            string row;
            for(int k=0;k<t;k++)
                row+="0";
            t++;
            for(int j=n-1;j>=0;j--){
                int y=num1[j]-'0';
                int mul=x*y+flag;
                flag=mul/10;
                mul=mul%10;
                char ch=mul+48;
                row+=ch;
            }
            while(flag){
                char ch=(flag%10)+48;
                row+=ch;
                flag/=10;
            }
            rows.push_back(row);
        }
        string ans="";
        int len=0;
        for(int i=0;i<rows.size();i++){
            if(len<rows[i].length())
                len=rows[i].length();
        }
        flag=0;
        for(int i=0;i<len;i++){
            int num=flag;
            for(int j=0;j<rows.size();j++){
                if(i>=rows[j].length()){
                    num+=0;
                } else {
                    int temp=rows[j][i]-'0';
                    num+=temp;
                }
            }
            int temp=num%10;
            char ch=temp+48;
            ans+=ch;
            flag=num/10;
        }
        while(flag){
            char ch=(flag%10)+48;
            ans+=ch;
            flag/=10;
        }
        reverse(ans.begin(), ans.end());
        for(int i=0;i<ans.length()-1;i++){
            if(ans[i]=='0'){
                ans=ans.substr(1);
                i--;
            } else break;
        }
        return ans;
    }
};
