#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <deque>
#include "Model.h"


using namespace std;
class modelDataList
{
private:
	string modelListHistory = "all_models.txt";
	string purchasingHistory = "purchase_history.txt";
public:
	deque<Model> modelDeque;
	deque<Model> helpDeque;

	modelDataList();

	//добавление моделей до тех пор, пока юзер не нажмет 0 (чтобы не приходилось каждый раз вручную вызывать add)
	void addModelData();

	void clearList();

	//печать текущей модели
	void modelPrint(deque<Model>::iterator x);

	//печать всех моделей
	void modelPrintPart();

	void modelPrintAllModel();
	
	bool Contains(deque<Model>::iterator x);

	//удаление заданной модели
	void modelDataRemove(deque<Model>::iterator x);

	//изменение информации о заданной модели
	void modelDataChange(deque<Model>::iterator x);

	//загрузка одной выбранной модели в файл
	void loadTo(ofstream& _file, deque<Model>::iterator x);

	//загрузка всех моделей в файл
	void loadPartTo(ofstream& _file);

	//загрузка выборки по поиску в отдельный файл 
	void loadResultTo(ofstream& _file);

	//загрузка первой модели из файла
	void loadFrom(ifstream& _file);

	//загрузка всех моделей из файла
	void loadPartFrom(ifstream& _file);
};

