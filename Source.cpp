#include<iostream>
#include<string>
#include<ctime>
#include <fstream>

using namespace std;

/// <summary>
/// ////////////////////////////////////////////////////////////////
/// </summary>

struct list {
	string count;
	list* next;
};

void AddListElem(string newListElem, list*& first) {
	list* newElem = new list;
	newElem->count = newListElem;
	newElem->next = NULL;
	if (first == NULL) {
		first = newElem;
	}
	else {
		list* tmp = first;
		while (tmp->next != NULL) {
			tmp = tmp->next;
		}
		tmp->next = newElem;
	}
}

void OutputList(list*& first) {
	list* tmp = first;
	while (tmp != NULL) {
		cout << tmp->count << " ";
		tmp = tmp->next;

	}
	cout << endl;
}

/// <summary>
/// ////////////////////////////////////////////////////////////////
/// </summary>

int doKey(string key) {
	int keyint;
	keyint = ((int)key[0] * (int)key[0] + (int)key[1] * (int)key[1] + (int)key[2] * (int)key[2] + (int)key[3] * (int)key[3] + (int)key[4] * (int)key[4] + (int)key[5] * (int)key[5]) % 2000;
	return keyint;
}

void genKeys(list* table[2000]) {
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
		AddListElem(temp, table[keytemp]);
	}
}

void checkTable(list* table[2000]) {
	int checkList[2000];
	for (int i = 0; i < 2000; i++) {
		list* temp = table[i];
		if (temp == NULL) {
			checkList[i] = 0;
		}
		else {
			int length = 0;
			list* tmp = temp;
			while (tmp->next != NULL) {
				tmp = tmp->next;
				length++;
			}
			checkList[i] = length;
		}
	}
	std::ofstream out("out.txt");
	std::streambuf* coutbuf = std::cout.rdbuf(); 
	std::cout.rdbuf(out.rdbuf()); 
	for (int i = 0; i < 2000; i++)
	{
		cout << i << " " << checkList[i] << " " << endl;
	}
}

void showTable(list* table[2000]) {
	for (int i = 0; i < 2000; i++) {
		list* temp = table[i];
		if (temp == NULL) {
			cout << i << ": " << "NULL";
		}
		else {
			cout << i << ": ";
			list* tmp = temp;
			while (tmp->next != NULL) {
				cout << tmp->count << " ";
				tmp = tmp->next;
			}
			cout << endl;
		}
	}
}

int main() {

	srand(time(0));
	list* table[2000];
	
	for (int i = 0; i < 2000; i++)
	{
		table[i] = NULL;
	}
	genKeys(table);
	showTable(table);

	
	
}