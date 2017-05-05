class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.size()!=5) return false;
        sort(numbers.begin(),numbers.end());
        int i=0;
        while(numbers[i]==0) i++;
        if(numbers[4]-numbers[i]>4) return false;
        for(int j=i;j<4;j++){
            if(numbers[j]==numbers[j+1]) return false;
        }
        return true;
    }
};


/*class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.size()<1)
            return false;
        int jokercount = 0;
        sort(numbers.begin(),numbers.end());
        int i=0;

        while(!numbers[i]){
            jokercount++;
            i++;
        }
        
        for(;i<numbers.size()-1;i++){
            if(numbers[i+1]-numbers[i]>5 || numbers[i+1]-numbers[i] == 0 )
                return false;
            else if(numbers[i+1]-numbers[i] == 2)
                jokercount -=1;
            else if(numbers[i+1]-numbers[i] == 3)
                jokercount -=2;
            else if(numbers[i+1]-numbers[i] == 4)
                jokercount -=3;
            else if(numbers[i+1]-numbers[i] == 5)
                jokercount -=4;
        }
        return jokercount<=4&&jokercount>=0;
    }
};*/
