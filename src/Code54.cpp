class Solution
{
private:      
    vector<char>str;
    map<char,int> mp; 
public:
  //Insert one char from stringstream
    void Insert(char ch)
    {
        str.push_back(ch);
        mp[ch]++;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        vector<char>::iterator iter;
        for(iter=str.begin();iter!=str.end();iter++){
            if(mp[*iter] == 1)
                return *iter;
        }
        return '#';
    }

};
