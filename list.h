#pragma once
#include <cstddef>
#include <iostream>
using namespace std;
class list {
	double count;
	list* next;
public:
	list() {
		count = NULL;
		next = NULL;
	}
	list(double count) {
		this->count = count;
		next = NULL;
	}
	void AddListElem(double count) {
		list newElem;
		newElem.count = count;
		newElem.next = NULL;
		list temp = *this;
		if (this->count == NULL) {
			this->count = newElem.count;
			cout << "fff";
		}
		else {
			cout << this->next;
			while (this->next != NULL) {
				temp = *temp.next;
			}
			temp.next = &newElem;
		}
	}
	void OutputList() {
		list tmp = *this;
		while (tmp.count != NULL) {
			cout << tmp.count << " ";
			tmp = *tmp.next;

		}
		cout << endl;
	}

};