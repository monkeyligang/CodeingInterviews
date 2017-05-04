class Solution {
public:
    string LeftRotateString(string str, int n) {
        if(str == "")//如果字符串为空,返回空
            return "";
        if(n==0) //如果左移位为0，直接返回字符串，因为就没有移动
            return str;      
        return str.substr(n)+str.substr(0,n);
    }
};
