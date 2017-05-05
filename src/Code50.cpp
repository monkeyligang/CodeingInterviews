class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if(length<0)
            return false;
        int *assit = new int[length];//辅助数组
        for(int i=0;i<length;i++)
            assit[i] = 0;
        for(int i=0;i<length;i++){
            assit[numbers[i]]++;
            if( assit[numbers[i]]>1){
                *duplication = numbers[i];//重复数字
                return true;
            }
        }
        return false;
    }
};
