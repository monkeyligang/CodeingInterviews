//新建一个map记录每个字符出现的次数，然后从前向后，找到第一个计数为1的字符
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if(str=="")
            return -1;
        map<char,int>mp;//map键值对
        for(int i=0;i<str.length();i++){
            mp[str.at(i)]++;
        }
        for(int i=0;i<str.length();i++){
            if(mp[str.at(i)] == 1)
                return i;
        }
        return -1;
    }
};
