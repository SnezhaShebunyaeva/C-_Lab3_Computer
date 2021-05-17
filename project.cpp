#include <iostream>
#include "modelDataList.h"
#include "Help.h"
#include "menuEn.h"
#include <Windows.h>

/*
Модель компьютера характеризуется кодом и названием марки компьютера, типом процессора, 
частотой работы процессора, объемом оперативной памяти, объемом жесткого диска, 
объемом памяти видеокарты, стоимостью компьютера и количеством экземпляров.
Поиск по типу процессора, объему ОЗУ, памяти видеокарты и объему жесткого диска.
Реализовать виртуальный магазин ПК. Магазин должен иметь два режима работы
— клиент и сотрудник (выбирается в меню). Сотрудник имеет возможность
управления магазином: добавление, редактирование, удаление моделей ПК.
Предусмотреть вывод списка моделей ПК с сортировкой и/или фильтрацией по
выбранному полю. Пользователь имеет возможность поиска ПК по заданному
критерию (любое поле, для полей типа цены и объема памяти — предусмотреть
ввод диапазона) и покупки выбранного ПК. Предусмотреть хранение истории
покупок и просмотр истории сотрудником.
Шебуняева Снежана, 2 курс, 9 группа
*/

void purchaseModel(modelDataList& modelList)
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

	if (!modelList.modelDeque.empty()) {
		
		auto x = find_if(modelList.modelDeque.begin(), modelList.modelDeque.end(), inputElemem());
		int am = InputQuery("Add amount of models you want to purchase:", 1, 1000);
		if (x != modelList.modelDeque.end() && (*x).amount >= am) {
			int help = (*x).amount;
			(*x).amount = am;
			ofstream _file;
			_file.open("purchase_history.txt", ios::out);
			modelList.loadTo(_file, x);
			_file.close();
			(*x).amount = help - am;
		}
		else {
			cout << "Warning: could not purchase model";
		}
		cout << endl;
		system("pause");
		system("cls");
		cin.get();
	}
}



void workAsUser(modelDataList& models)
{
	menu menu_choice;
	menu_choice.Add("View all models");
	menu_choice.Add("Search models by filter");
	menu_choice.Add("Sort models");
	menu_choice.Add("Ourchase a PC");
	menu_choice.Add("Exit");
	int choice;

	do
	{
		menu_choice.Print();
		choice = menu_choice.Choice("");
		system("cls");
		switch (choice)
		{
			case 1:
			{
				ostream_iterator<Model> os(cout, "\n");
				copy(models.modelDeque.begin(), models.modelDeque.end(), os);
				system("pause");
				break;
			}
			case 2:
			{
				selection(models);
				break;
			}

			case 3:
			{
				deque<Model> result;
				result = models.modelDeque;
				sortSelection(result);
			}

			case 4:
			{
				purchaseModel(models);
				break;
			}
		}
		system("cls");
	} while (choice != 0);
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Rus");

	modelDataList modelList;
	ifstream _file;
	_file.open("all_models.txt");
	modelList.loadPartFrom(_file);
	system("cls");
	menu isWho;
	isWho.Add("Meneger");
	isWho.Add("User");
	isWho.Add("Exit");
	int choice;
	do
	{
		cout << "Enter as:" << endl;
		isWho.Print();
		choice = isWho.Choice("Enter as:");
		system("cls");
		switch (choice)
		{
		case 1:
			workAsMenedger(modelList);
			break;
		case 2:
			workAsUser(modelList);
			break;
		}
	} while (choice != 0);
	_file.close();
}
