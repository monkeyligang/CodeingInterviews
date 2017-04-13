//请实现一个函数，将一个字符串中的空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

class Solution {
public:
	void replaceSpace(char *str, int length) {
		int spacenum = 0;
		for (int i = 0; i < length; i++){
			if (str[i] == ' ')
				spacenum++;
		}
		int newlen = length-1 + spacenum * 2;
		int index = length - 1;
		for (; index>=0; index--){
			if (str[index] == ' '){
				str[newlen--] = '0';
				str[newlen--] = '2';
				str[newlen--] = '%';
			}
			else{
				str[newlen--] = str[index];
			}
		}
	}
};