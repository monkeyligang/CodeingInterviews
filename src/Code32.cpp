
class Solution {
public:
	static bool compare(const string& s1, const string& s2){      //比较函数
		string str1 = s1 + s2;
		string str2 = s2 + s1;
		return str1<str2;
	}
	string PrintMinNumber(vector<int> numbers) {
		string result = "";
		if (numbers.size() <= 0)
			return result;
		vector<string>numbersToString;
		for (int i = 0; i<numbers.size(); i++){
			stringstream ss;
			string s;
			ss << numbers[i];
			ss >> s;
			numbersToString.push_back(s);
		}
		sort(numbersToString.begin(), numbersToString.end(), compare);
		for (int i = 0; i<numbersToString.size(); i++){
			result += numbersToString[i];
		}
		return result;
	}
};
