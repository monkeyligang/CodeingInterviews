//���½����ϱ�����ұ�С
//�����½ǿ�ʼ�Աȣ�������������������жϣ����С�������жϣ�������ֱ�ӷ���true
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int row = array.size();
        int col = array[0].size();
        int a=row-1;
        int b = 0;        
        while(a>=0&&b<col){
            if(target == array[a][b]){
                return true;
            }
            else if(target>array[a][b]){
                b++;
            }
            else if(target<array[a][b]){
                a--;
            }
        }
        return false;
    }
};