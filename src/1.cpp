//左下角向上变大，向右变小
//从左下角开始对比，如果大于则向右移来判断，如果小向上移判断，如果相等直接返回true
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