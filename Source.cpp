#include<iostream>
#include<string>
#include<ctime>
#include <fstream>

using namespace std;


int doKey(string key) {
	int keyint;
	keyint = ((int)key[0] * (int)key[0] + (int)key[1] * (int)key[1] + (int)key[2] * (int)key[2] + (int)key[3] * (int)key[3] + (int)key[4] * (int)key[4] + (int)key[5] * (int)key[5]) % 2000;
	return keyint;
}

void addKeys(string count, int key, string table[2000]) {
	bool bad = true;
	for (int i = key; i < 2000; i++) {
		if (table[i].empty()) {
			table[i] = count;
			bad = false;
			break;
		}
	}
	if (bad) {
		
	}
}

void genKeys(string table[2000]) {
	for (int i = 0; i < 6000; i++)
	{
		string temp;
		temp += (char)(rand() % 10 + 48);
		temp += (char)(rand() % 26 + 65);
		temp += (char)(rand() % 26 + 65);
		temp += (char)(rand() % 26 + 65);
		temp += (char)(rand() % 26 + 65);
		temp += (char)(rand() % 10 + 48);
		int keytemp = doKey(temp);
		addKeys(temp, keytemp, table);
			
	}
}

void showTable(string table[2000]) {
	for (int i = 0; i < 2000; i++) {
		string temp = table[i];
		if (temp.empty()) {
			cout << i << ": " << "NULL"<<endl;
		}
		else {
			cout << i << ": "<<temp<<endl;
		}
	}
}

void search(string count, string table[2000]) {
	int temp = doKey(count);
	for (int i = temp; !table[i].empty(); i++) {
		if (table[i] == count) {
			cout << i << ":" << count<<endl;
			break;
		}
	}
}

void search(int key, string table[2000]) {
	cout << key << ":" << table[key] << endl;
}

void outExcel(string table[2000]) {
	std::ofstream out("out.txt");
	std::streambuf* coutbuf = std::cout.rdbuf();
	std::cout.rdbuf(out.rdbuf());
	
	for (int i = 0; i < 2000; i++)
	{
		if (table[i].empty()) {
			cout << i << " " << 0 << endl;
		}
		else {
			cout << i << " " << 1 << endl;
		}
		
	}
}
int main() {

	srand(time(0));
	string table[2000];
	//addKeys("2FGHF1", doKey("2FGHF1"), table);
	//addKeys("1FGHF2", doKey("1FGHF2"), table);
	genKeys(table);
	showTable(table);
	outExcel(table);
	//search("1FGHF2", table);
	

	
	
}