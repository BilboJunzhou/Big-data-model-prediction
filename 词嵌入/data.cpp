
#include "csv.h"
#include "data.h"
#include <time.h>
vector<vector<string>> dataMake(vector<vector<string>> strs) {
	// ����title��ǩ
	// map ����
	map<string, int> map_num1 = { {"80��", 2,},
								{"70��", 3,},
								{"60��", 4,},
								{"90��", 5,},
								{"50��", 6,},
								{"40��", 7,},
								{"00��", 8,},
								{"20��", 9,} };

	map<string, int> map_num2 = { {"21~40", 10,},
								{"41~60", 11,},
								{"61~80", 12,},
								{"1~20", 13,},
								{"80~100", 14,} };
	map<string, int> map_num3 = { {"5G", 15,},
								{"3G", 16,},
								{"4G", 17,},
								{"2G", 18,},
								{"δ֪", 19,} };

	// map�洢λ��
	ifstream infile("C:/Users/13747/Desktop/�����ݱ���/title2.csv", ios::in);
	string line;
	vector<string> title;
	getline(infile, line);
	int sizex = getLong(line);
	stringstream ss(line);
	string str;
	for (int i = 0; i < sizex; i++) {
		getline(ss, str, ',');
		title.push_back(str);
	}
	cout << title.size() << endl;

	map<string, int> map_num;
	for (int i = 0; i < title.size(); i++) {
		map_num.insert({ title[i],i });
	}
	// map�洢λ��end

	vector<vector<string>> data_train;
	data_train.push_back(title);
	for (int i = 0; i < strs.size(); i++) {
		vector<string> str_init(title.size(), "0");
		int mm = 0;
		str_init[0] = strs[i][0];
		// labe 1
		str_init[1] = strs[i][1];
		// labe 2
		int num = map_num1[strs[i][2]];
		str_init[num] = "1";
		// labe 3
		num = map_num2[strs[i][3]];
		str_init[num] = "1";
		// labe 4
		num = map_num3[strs[i][4]];
		str_init[num] = "1";
		// labe 5
		if (strs[i][5] == "1") {
			str_init[20] = "1";
		}
		if (strs[i][6] == "1") {
			str_init[21] = "1";
		}
		num = stoi(strs[i][7]) + 21;
		str_init[num] = "1";
		num = map_num[strs[i][8]];
		str_init[num] = "1";
		num = map_num[strs[i][10]];
		str_init[num] = "1";
		data_train.push_back(str_init);
	}


	return data_train;
}