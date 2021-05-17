#include "Model.h"

istream& operator>>(istream& is, Model& model)
{
	//вспомогательные параметры
	int _code;
	string _mark;
	string _procType;
	int _procFreq;
	int _ramCap;
	int _hddCap;
	int _gcardCap;
	int _price;
	int _amount;

	cout << "Enter model information: " << endl;
	cout << endl;
	cout << "Code: "; is >> _code;
	cout << "Mark: "; is >> _mark;
	cout << "Processor type: "; is >> _procType;
	cout << "Processor frequency: "; is >> _procFreq;
	cout << "RAM capacity: "; is >> _ramCap;
	cout << "HDD capacity: "; is >> _hddCap;
	cout << "Graphics card capacity: "; is >> _gcardCap;
	cout << "Price: "; is >> _price;
	cout << "Total amount: "; is >> _amount;
	//просто последовательно читаем информацию с клавиатуры, присваивая ее параметрам, и создаем по ним новую модель
	model = Model(_code, _mark, _procType, _procFreq, _ramCap, _hddCap, _gcardCap, _price, _amount);

	return is;
}

ostream& operator<<(ostream& os, const Model& model)
{
	if (typeid(os) == typeid(ofstream))
	{
		os << model.code << endl;
		os << model.mark << endl;
		os << model.procType << endl;
		os << model.procFreq << endl;
		os << model.ramCap << endl;
		os << model.hddCap << endl;
		os << model.gcardCap << endl;
		os << model.price << endl;
		os << model.amount << endl;
	}
	else
	{
		os << "Model information: " << endl;
		os << "Code: " << model.code << endl;
		os << "Mark: " << model.mark << endl;
		os << "Processor type: " << model.procType << endl;
		os << "Processor frequency: " << model.procFreq << endl;
		os << "RAM capacity: " << model.ramCap << endl;
		os << "HDD capacity: " << model.hddCap << endl;
		os << "Graphics card capacity: " << model.gcardCap << endl;
		os << "Price: " << model.price << endl;
		os << "Total amount: " << model.amount << endl;
	}
	return os;
}
