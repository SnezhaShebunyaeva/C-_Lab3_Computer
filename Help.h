#pragma once
#include <string>
#include <fstream>
#include "menuEn.h"
#include <algorithm>
using namespace std;

//поиск модели по всем характеристикам
struct searchModelData
{
	int code;
	string mark;
	string procType;
	int procFreq;
	int ramCap;
	int hddCap;
	int gcardCap;
	int price;
	int amount;

	searchModelData(int _code, string _mark, string _procType, int _procFreq, int _ramCap,
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
	bool operator()(const Model& e)
	{
		return (e.code == code) && (e.mark == mark) && (e.procType == procType) && (e.procFreq == procFreq)
			&& (e.ramCap == ramCap) && (e.hddCap == hddCap) && (e.gcardCap == gcardCap)
			&& (e.price == price) && (e.amount == amount);
	}
};

//поиск по процессору
struct isProcType
{
	string  procType;

	isProcType(string _procType)
	{
		procType = _procType;
	}

	bool operator()(const Model& e)
	{
		return e.procType == procType;
	}
};

//поиск по озу
struct isRamCap
{
	int  ramCap;

	isRamCap(int _ramCap)
	{
		ramCap = _ramCap;
	}

	bool operator()(const Model& e)
	{
		return e.ramCap == ramCap;
	}
};

//поиск по видеокарте
struct isGCardCap
{
	int gcardCap;

	isGCardCap(int _gcardCap)
	{
		gcardCap = _gcardCap;
	}

	bool operator()(const Model& e)
	{
		return e.gcardCap == gcardCap;
	}
};

//поиск по жд
struct isHDDCap
{
	int hddCap;

	isHDDCap(int _hddCap)
	{
		hddCap = _hddCap;
	}

	bool operator()(const Model& e)
	{
		return e.hddCap == hddCap;
	}
};

struct isMark
{
	string mark;

	isMark(string _mark)
	{
		mark = _mark;
	}
	bool operator()(const Model& e)
	{
		return e.mark == mark;
	}
};

struct isCode
{
	int code;

	isCode(int _code)
	{
		code = _code;
	}

	bool operator()(const Model& e)
	{
		return e.code == code;
	}
};

struct isPrice
{
	int price;

	isPrice(int _price)
	{
		price = _price;
	}

	bool operator()(const Model& e)
	{
		return e.price == price;
	}
};

struct isAmount
{
	int amount;

	isAmount(int _amount)
	{
		amount = _amount;
	}

	bool operator()(const Model& e)
	{
		return e.amount == amount;
	}
};

searchModelData inputElemem()
{
	int code;
	string mark;
	string procType;
	int procFreq;
	int ramCap;
	int hddCap;
	int gcardCap;
	int price;
	int amount;
	cout << "Enter code: ";  cin >> code; cout << endl;
	cout << "Enter mark: ";  cin >> mark; cout << endl;
	cout << "Enter processor type: ";  cin >> procType; cout << endl;
	cout << "Enter processor frequence: ";  cin >> procFreq; cout << endl;
	cout << "Enter RAM capacity: ";  cin >> ramCap; cout << endl;
	cout << "Enter HDD capacity: ";  cin >> hddCap; cout << endl;
	cout << "Enter graphics card capacity: ";  cin >> gcardCap; cout << endl;
	cout << "Enter price: ";  cin >> price; cout << endl;
	cout << "Enter amount: ";  cin >> amount; cout << endl;
	return searchModelData(code, mark, procType, procFreq,
		ramCap, hddCap, gcardCap, price, amount);
}

void workAsMenedger(modelDataList& modelList)
{
	ofstream _file;
	ifstream f;

	modelDataList history;

	menu* doing = new menu();
	doing->Add("Add model");
	doing->Add("Change model information");
	doing->Add("Remove model");
	doing->Add("View user history");
	doing->Add("Print all models");
	doing->Add("Exit");
	int choice;
	do
	{
		doing->Print();
		choice = doing->Choice("");
		system("cls");
		switch (choice)
		{
		case 1:
			modelList.addModelData();
			break;
		case 2:
		{
			if (!modelList.modelDeque.empty()) {

				auto x = find_if(modelList.modelDeque.begin(), modelList.modelDeque.end(), inputElemem());
				cout << endl;
				cout << endl;
				modelList.modelPrint(x);		//выводим юзеру то, что получилось в итоге
				modelList.modelDataChange(x);	//меняем информацию
				system("pause");
				_file.open("all_models.txt");
				modelList.loadPartTo(_file);
				_file.close();
			}
			else
				cout << "Warning: list is empty" << endl;
			cin.get();
			break;
		}

		case 3:
		{
			if (!modelList.modelDeque.empty()) {
				auto x = find_if(modelList.modelDeque.begin(), modelList.modelDeque.end(), inputElemem());
				cout << endl;
				cout << endl;
				modelList.modelDataRemove(x);	//удаляем из списка
				_file.open("all_models.txt");
				modelList.loadPartTo(_file);
				system("pause");
				_file.close();
				cin.get();
			}
			else
				cout << "Warning: list is empty" << endl;
			break;
		}

		case 4:
		{
			f.open("purchase_history.txt");
			history.loadPartFrom(f);
			_file.close();
			ostream_iterator<Model> os(cout, "\n");
			copy(history.modelDeque.begin(), history.modelDeque.end(), os);
			history.clearList();
			system("pause");
		}
		case 5:
			modelList.modelPrintAllModel();
			system("pause");
		}
		system("cls");
	} while (choice != 0);
	delete doing;
}

int InputQuery(string str, int min, int max)
{
	int choise;
	cout << str;
	cin >> choise;
	while (choise < min || choise > max) {
		cout << "Warning: incorrect value, try again" << endl;
		cin >> choise;
	}
	return choise;
}

string InputString(string message)
{
	string str;
	do {
		cout << message << endl;
		cin >> str;
	} while (str == "" && cout << "Warning: incorrect value, try again\n");
	return str;
}

menu* selectionMenu()
{
	menu* result = new menu();
	result->Add("RAM capacity");					//объем озу
	result->Add("Processor type");				//тип процессора
	result->Add("Graphics card capacity");		//объем видеокарты
	result->Add("HDD capacity");				//объем жд
	result->Add("Mark");						//марка
	result->Add("Code");						//код
	result->Add("Price");					//цена
	result->Add("Amount");					//количество
	result->Add("Exit");
	return result;
}

void selection(modelDataList& models)
{
	menu* select = selectionMenu();
	cout << "Sort models by:" << endl;
	select->Print();
	int choice = select->Choice("Sort models by:");
	int help1;
	string help2;
	delete select;
	switch (choice)
	{
	case 1:
	{
		system("cls");
		help1 = InputQuery("Add RAM capacity: ", 1, 100);
		system("cls");
		copy_if(models.modelDeque.begin(), models.modelDeque.end(), back_inserter(models.helpDeque), isRamCap(help1));
		models.modelPrintPart();
		break;
	}
	case 2:
	{
		system("cls");
		help2 = InputString("Add Processor type: ");
		system("cls");
		copy_if(models.modelDeque.begin(), models.modelDeque.end(), back_inserter(models.helpDeque), isProcType(help2));
		models.modelPrintPart();
		break;
	}
	case 3:
	{
		system("cls");
		help1 = InputQuery("Add Graphics card capacity: ", 1, 1000);
		system("cls");
		copy_if(models.modelDeque.begin(), models.modelDeque.end(), back_inserter(models.helpDeque), isGCardCap(help1));
		models.modelPrintPart();
		break;
	}
	case 4:
	{
		system("cls");
		help1 = InputQuery("Add HDD capacity: ", 1, 1000);
		system("cls");
		copy_if(models.modelDeque.begin(), models.modelDeque.end(), back_inserter(models.helpDeque), isHDDCap(help1));
		models.modelPrintPart();
		break;
	}
	case 5:
	{
		system("cls");
		help2 = InputString("Add Mark: ");
		system("cls");
		copy_if(models.modelDeque.begin(), models.modelDeque.end(), back_inserter(models.helpDeque), isMark(help2));
		models.modelPrintPart();
		break;
	}
	case 6:
	{
		system("cls");
		help1 = InputQuery("Add Code: ", 1, 1000);
		system("cls");
		copy_if(models.modelDeque.begin(), models.modelDeque.end(), back_inserter(models.helpDeque), isCode(help1));
		models.modelPrintPart();
		break;
	}
	case 7:
	{
		system("cls");
		help1 = InputQuery("Add Price: ", 10000, 100000);
		system("cls");
		copy_if(models.modelDeque.begin(), models.modelDeque.end(), back_inserter(models.helpDeque), isPrice(help1));
		models.modelPrintPart();
		break;
	}
	case 8:
	{
		system("cls");
		help1 = InputQuery("Add Amount: ", 1, 1000);
		system("cls");
		copy_if(models.modelDeque.begin(), models.modelDeque.end(), back_inserter(models.helpDeque), isAmount(help1));
		models.modelPrintPart();
		break;
	}
	}
	cin.get();
	system("pause");
}

menu* sortMenu()
{
	menu* result = new menu;
	result->Add("RAM capacity");				//объем озу
	result->Add("Processor type");			//тип процессора
	result->Add("Graphics card capacity");	//объем видеокарты
	result->Add("HDD capacity");				//объем жд
	result->Add("Mark");						//марка
	result->Add("Code");						//код
	result->Add("Price");					//цена
	result->Add("Amount");					//количество
	result->Add("Exit");
	return result;
}

menu* sortDirection()
{
	menu* result = new menu;
	result->Add("Direct");
	result->Add("Indirrect");
	return result;
}
void sortSelection(deque<Model>& selection)
{
	menu* menu_sort = sortMenu();
	cout << "Sort models by:" << endl;
	menu_sort->Print();
	int choice = menu_sort->Choice("Sort models by:");
	delete menu_sort;
	system("cls");
	menu* menu_dir = sortDirection();
	cout << "Select sorting direction:" << endl;
	menu_dir->Print();
	bool dir = (menu_dir->Choice("Select sorting direction:") == 0);
	delete menu_dir;
	system("cls");
	switch (choice)
	{
	case 1:
	{
		if (dir)
		{
			struct sortByRAMCap
			{
				bool operator() (Model model1, Model model2)
				{
					return model1.ramCap < model2.ramCap;
				}
			} sortRAM;
			sort(selection.begin(), selection.end(), sortRAM);
		}
		else
		{
			struct sortByRAMCap
			{
				bool operator() (Model model1, Model model2)
				{
					return model1.ramCap > model2.ramCap;
				}
			} sortRAM;
			sort(selection.begin(), selection.end(), sortRAM);
		}
	}
	break;
	case 2:
	{
		if (dir)
		{
			struct sortByProcType
			{
				bool operator() (Model model1, Model model2)
				{
					return model1.procType < model2.procType;
				}
			} sortPT;
			sort(selection.begin(), selection.end(), sortPT);
		}
		else
		{
			struct sortByProcType
			{
				bool operator() (Model model1, Model model2)
				{
					return model1.procType > model2.procType;
				}
			} sortPT;
			sort(selection.begin(), selection.end(), sortPT);
		}
	}
	break;
	case 3:
	{
		if (dir)
		{
			struct sortByGC
			{
				bool operator() (Model model1, Model model2)
				{
					return model1.gcardCap < model2.gcardCap;
				}
			} sortGC;
			sort(selection.begin(), selection.end(), sortGC);
		}
		else
		{
			struct sortByGC
			{
				bool operator() (Model model1, Model model2)
				{
					return model1.gcardCap > model2.gcardCap;
				}
			} sortGC;
			sort(selection.begin(), selection.end(), sortGC);
		}
	}
	break;
	case 4:
	{
		if (dir)
		{
			struct sortByHDD
			{
				bool operator() (Model model1, Model model2)
				{
					return model1.hddCap < model2.hddCap;
				}
			} sortHDD;
			sort(selection.begin(), selection.end(), sortHDD);
		}
		else
		{
			struct sortByHDD
			{
				bool operator() (Model model1, Model model2)
				{
					return model1.hddCap > model2.hddCap;
				}
			} sortHDD;
			sort(selection.begin(), selection.end(), sortHDD);
		}
	}
	break;
	case 5:
	{
		if (dir)
		{
			struct sortByMark
			{
				bool operator() (Model model1, Model model2)
				{
					return model1.mark < model2.mark;
				}
			} sortMark;
			sort(selection.begin(), selection.end(), sortMark);
		}
		else
		{
			struct sortByMark
			{
				bool operator() (Model model1, Model model2)
				{
					return model1.mark > model2.mark;
				}
			} sortMark;
			sort(selection.begin(), selection.end(), sortMark);
		}
	}
	break;
	case 6:
	{
		if (dir)
		{
			struct sortByCode
			{
				bool operator() (Model model1, Model model2)
				{
					return model1.code < model2.code;
				}
			} sortCode;
			sort(selection.begin(), selection.end(), sortCode);
		}
		else
		{
			struct sortByCode
			{
				bool operator() (Model model1, Model model2)
				{
					return model1.code > model2.code;
				}
			} sortCode;
			sort(selection.begin(), selection.end(), sortCode);
		}
	}
	break;
	case 7:
	{
		if (dir)
		{
			struct sortByPrice
			{
				bool operator() (Model model1, Model model2)
				{
					return model1.price < model2.price;
				}
			} sortPrice;
			sort(selection.begin(), selection.end(), sortPrice);
		}
		else
		{
			struct sortByPrice
			{
				bool operator() (Model model1, Model model2)
				{
					return model1.price > model2.price;
				}
			} sortPrice;
			sort(selection.begin(), selection.end(), sortPrice);
		}
	}
	break;
	case 8:
	{
		if (dir)
		{
			struct sortByAmount
			{
				bool operator() (Model model1, Model model2)
				{
					return model1.amount < model2.amount;
				}
			} sortAmount;
			sort(selection.begin(), selection.end(), sortAmount);
		}
		else
		{
			struct sortByAmount
			{
				bool operator() (Model model1, Model model2)
				{
					return model1.amount > model2.amount;
				}
			} sortAmount;
			sort(selection.begin(), selection.end(), sortAmount);
		}
	}
	break;
	}
}