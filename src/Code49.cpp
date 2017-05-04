class Solution {
private:
    bool operation=true;     
public:
    int StrToInt(string str) {
        if(str == "")
            return 0;
        
        int i=0;
        int result=0;
        if(str[0] == '+'){
            operation = true;
            i++; 
        }
        else if(str[0] == '-'){
            operation = false;
            i++;
        }
            
        for(;i<str.length();i++){
                if(str[i]>='0' && str[i]<= '9'){
                     result = result*10+(str[i]-'0');
                }
                else{
                    return 0;
                }
        }
        if(!operation)
           result = -result;
        return result;            
    }
};
