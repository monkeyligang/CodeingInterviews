class Solution {
public:
	int movingCount(int threshold, int rows, int cols)
	{
		//定义二维数组
		int **range;
		range = new int*[rows];
		for (int i = 0; i < rows; i++){
			range[i] = new int[cols];
		}
		for (int i = 0; i < rows; i++){
			for (int j = 0; j < cols; j++){
				range[i][j] = 0;
			}
		}
		return cal(range, threshold, rows, cols, 0, 0);
	}
	int cal(int **range, int threshold, int rows, int cols, int x, int y){
		int count = 0;
		if (x>=0 &&x <rows && y>=0 && y <cols && (divide(x) + divide(y)) <= threshold && range[x][y] == 0){
			range[x][y] = 1;
			count = 1 + cal(range, threshold, rows, cols, x + 1, y) +
				cal(range, threshold, rows, cols, x - 1, y) +
				cal(range, threshold, rows, cols, x, y + 1) +
				cal(range, threshold, rows, cols, x, y - 1);
		}
		return count;
	}
	//按位计算
	int divide(int input){
		int sum = 0;
		while (input){
			sum += input % 10;
			input = input / 10;
		}
		return sum;
	}

};
