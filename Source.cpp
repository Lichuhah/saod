#include<iostream>
#include<string>
#include<ctime>
#include <fstream>
#include<vector>

using namespace std;

const int sectorsamount = 10000;
const int keyamount = 10000;

/////////////////////////////хэш-функция//////////////////////////////////////////
int doKey(string key) {
	int keyint;
	keyint = ((int)key[0] * (int)key[0] + (int)key[1] * (int)key[1] + (int)key[2] * (int)key[2] + (int)key[3] * (int)key[3] + (int)key[4] * (int)key[4] + (int)key[5] * (int)key[5]) % sectorsamount;
	return keyint;
}


/////////////////////////////куча значений и их просмотр//////////////////////////////////////////
void genKey(string key[keyamount]) {
	for (int i = 0; i < keyamount; i++)
	{
		string temp;
		temp += (char)(rand() % 10 + 48);
		temp += (char)(rand() % 26 + 65);
		temp += (char)(rand() % 26 + 65);
		temp += (char)(rand() % 26 + 65);
		temp += (char)(rand() % 26 + 65);
		temp += (char)(rand() % 10 + 48);
		key[i] = temp;
	}
}

void showKey(string key[keyamount]) {
	for (int i = 0; i < keyamount; i++)
	{
		cout << key[i] << " ";
	}
}


/////////////////////////////таблица для проверки и её просмотр/////////////////////////////////////////
struct Key {
	vector<string> counts;
};

void createTableForCheck(Key tableForCheck[sectorsamount], string key[keyamount]) {
	for (int i = 0; i < keyamount; i++)
	{
		string temp = key[i];
		int keytemp = doKey(temp);
		tableForCheck[keytemp].counts.push_back(temp);
	}
}

void showTableForCheck(Key tableForCheck[sectorsamount]) {
	for (int i = 0; i < sectorsamount; i++) {
		cout << i << ": ";
		for (int j = 0; j < tableForCheck[i].counts.size(); j++) {
			cout << tableForCheck[i].counts[j] << " ";
		}
		cout << endl;
	}
}

void outExcel(Key tableForCheck[sectorsamount]) {
	std::ofstream out("out.txt");
	std::streambuf* coutbuf = std::cout.rdbuf();
	std::cout.rdbuf(out.rdbuf());
	for (int i = 0; i < sectorsamount; i++) {
		int lenght = tableForCheck->counts.size();
		cout << i << " " << lenght << endl;
	}
}


/////////////////////////////хэш-таблица, ее просмотр, добавление и удаление элемента//////////////////////////////////////////
void addCount(string count, string table[sectorsamount], Key badKey[sectorsamount]){
	bool bad = true;
	int tempkey = doKey(count);
	if (table[tempkey].empty()) {
		table[tempkey] = count;
	}
	else {
		bad = true;
		for (int j = tempkey; j < sectorsamount; j++) {
			if (table[j].empty()) {
				table[j] = count;
				bad = false;
				break;
			}
		}
		if (bad) {
			for (int j = 0; j < tempkey; j++) {
				if (table[j].empty()) {
					table[j] = count;
					bad = false;
					break;
				}
			}
		}
		if (bad) {
			badKey[tempkey].counts.push_back(count);
		}
	}
}

void createTable(string table[sectorsamount], string key[keyamount], Key badKey[sectorsamount]) {
	for (int i = 0; i < keyamount; i++) {
		string tempcount = key[i];
		addCount(tempcount, table, badKey);
	}
}

void showTable(string table[sectorsamount]) {
	for (int i = 0; i < sectorsamount; i++) {
		cout << i << ": " << table[i] << endl;
	}
}

void findByValue(string count, string table[sectorsamount]) {
	bool nofind = true;
	int tempkey = doKey(count);
	if (table[tempkey] == count) {
		cout << tempkey;
	}
	else {
		for (int i = tempkey; i < sectorsamount; i++) {
			if (table[i] == count) {
				cout << i;
				nofind = false;
				break;
			}
		}
		if (nofind) {
			cout << "ну-ка нахуй ты где";
			for (int i = 0; i < tempkey; i++) {
				if (table[i] == count) {
					cout << i;
					nofind = false;
					break;
				}
			}
		}
		if (nofind) {
			cout << "Такого элемента нет";
		}
	}
}

void deleteElement(int key, string table[sectorsamount], Key badKey[sectorsamount]) {
	table[key].clear();
	if (badKey[key].counts.empty()) {
		for (int i = 0; i < sectorsamount; i++) {
			if (!badKey[i].counts.empty()) {
				table[key] = badKey[i].counts[0];
				badKey[i].counts.erase(badKey[i].counts.begin());
				break;
			}
		}
	}
	else {
		table[key] = badKey[key].counts[0];
		badKey[key].counts.erase(badKey[key].counts.begin());
	}
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() {

	srand(time(0));
	string key[keyamount];
	Key keyTableForCheck[sectorsamount];
	Key badKey[sectorsamount];
	string table[sectorsamount];
	genKey(key);
	//showKey(key);
//	cout << endl << "______________________________________________________" << endl;
//	createTableForCheck(keyTableForCheck, key);
	//showTableForCheck(keyTableForCheck);
//	cout << endl << "______________________________________________________" << endl;
	createTable(table, key, badKey);
	//showTable(table);
	cout << endl << "______________________________________________________" << endl;
//	showTableForCheck(badKey);
	cout << table[rand() % sectorsamount];
	string a;
	cin >> a;
	findByValue(a, table);
	/*int a;
	cin >> a;
	deleteElement(a, table, badKey);
	cout << endl << "______________________________________________________" << endl;
	showTable(table);
	cout << endl << "______________________________________________________" << endl;
	showTableForCheck(badKey);*/
	
}