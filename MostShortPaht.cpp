#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <string>
#include <sstream>
using namespace std;

void handle_string(string s,vector<int> & index,vector<int> &num) {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '+' || s[i] == '-' || s[i] == '*') {
			index.push_back(i);
		}
	}
	index.push_back(s.size());
	stringstream ss;
	int val;
	int begin = 0;
	for (int i = 0; i < index.size(); i++) {
		int off = index[i]-begin;
		string str = s.substr(begin, off);
		ss << str;
		ss >> val;
		begin = index[i] + 1;
		num.push_back(val);
		ss.clear();
	}
}


int sum(string s, vector<int> & index, vector<int> &num) {
	index.pop_back();
	
	int sum = num[0];
	int cur = 1;
	for (int i = 0; i < index.size(); i++) {
		if (s[index[i]] == '+') {
			if (cur < num.size()) {
				sum = sum + num[cur];
				cur++;
			}
			else {
				break;
			}
		}

		if (s[index[i]] == '-') {
			if (cur < num.size()) {
				sum = sum - num[cur];
				cur++;
			}
			else {
				break;
			}
		}

		if (s[index[i]] == '*') {
			if (cur < num.size()) {
				sum = sum * num[cur];
				cur++;
			}
			else {
				break;
			}
		}
	}

	return sum;
}

int main() {
	//string s = "3+10*2";
	string s;
	cin >> s;
	vector<int> index;
	vector<int> num;


	handle_string(s,index,num);
	cout<<sum(s, index, num);


	return 0;
}
