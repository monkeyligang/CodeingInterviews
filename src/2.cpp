//��ʵ��һ����������һ���ַ����еĿո��滻�ɡ�%20�������磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��

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