//lc 10
//somewhat similar to wildcard matching leet 40
class Solution {
public:

    int rec(string &s,string &p,int i,int j){
        // base cases
        // both khatm
        if(i==s.size()&&j==p.size()) return true;
        // p khatm s nhi
        if(i<s.size()&&j==p.size()) return false;
        // s khatm p nhi
        if(i==s.size()&&j<p.size()){
            // p ke saare bache hue mein har dusra * hai toh true (zero time repeat krlege) vrna false        
            int k=j+1;
            for(;k<p.size();k=k+2){
            if(p[k]!='*') return false;
            }
            if(k==p.size()+1) return true; // last element * hi hona chahie
             return false;
        }

        int ans;
        //agar p ka next * hai
        if((j<p.size()-1)&&p[j+1]=='*'){ 
            // //curr matches or is .
            // if(p[j]==s[i]||p[j]=='.'){
            //     //zero time repeat
            //     int option1=rec(s,p,i,j+2);
            //     //one time repeat
            //     int option2=rec(s,p,i+1,j);

            //     ans=option1||option2;
            // }
            // else{
            // //no match
            // //repeat zero time
            // ans=rec(s,p,i,j+2);
            // }

            //or

            //repeat zero time 
            int option1=rec(s,p,i,j+2);
            //repeat one time (only if it matches or is .)
            int option2=false;
            if(p[j]==s[i]||p[j]=='.'){
                option2=rec(s,p,i+1,j);
            }
            ans=option1||option2;

        }
        else if(s[i]==p[j]||p[j]=='.'){ // char match ya p ka char is .
            ans=rec(s,p,i+1,j+1);
        }
        else{ // no match and no next *
            ans=false;
        }
        return ans;

    }



    bool isMatch(string s, string p) {
        int i=0;
        int j=0;
        int ans=rec(s,p,i,j);
        return ans;
    }
};