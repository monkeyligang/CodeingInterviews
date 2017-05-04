//利用栈的思想把，先进后出
class Solution {
public:
    string ReverseSentence(string str) {
        if(str.length()<=1)
            return str;
        stack<string> temp; //栈做为字符串缓存
        string tempstr; //
        for(int i=0;i<str.length();i++){ //循环分割字符串
            if(str[i]==' '&&tempstr.length()>0){
                temp.push(tempstr);
                tempstr ="";
            }
            else{
                tempstr+=str[i];
            }
        }
        temp.push(tempstr);//将最后一个字符串入栈
        
        //顺序出栈,得到反转的字符串
        tempstr="";
        while(!temp.empty()){
            tempstr = tempstr+temp.top()+" ";
            temp.pop();
        }
        return tempstr.substr(0,tempstr.length()-1);//去掉最后一个空格       
    }
};
