#pragma once

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Model
{
public:

	int code;
	string mark;
	string procType;
	int procFreq;
	int ramCap;
	int hddCap;
	int gcardCap;
	int price;
	int amount;

	//просто конструктор
	Model(int _code, string _mark, string _procType, int _procFreq, int _ramCap,
		int _hddCap, int _gcardCap, int _price, int _amount)
	{
		code = _code;
		mark = _mark;
		procType = _procType;
		procFreq = _procFreq;
		ramCap = _ramCap;
		hddCap = _hddCap;
		gcardCap = _gcardCap;
		price = _price;
		amount = _amount;
	}
	Model() {	}

	//перегрузка присваивания для удобства
	Model& operator=(const Model& model)
	{
		code = model.code;
		mark = model.mark;
		procType = model.procType;
		procFreq = model.procFreq;
		ramCap = model.ramCap;
		hddCap = model.hddCap;
		gcardCap = model.gcardCap;
		price = model.price;
		amount = model.amount;

		return *this;
	}
	friend istream& operator>>(istream& is, Model& model);
	friend ostream& operator<<(ostream& os, const Model& model);
};
