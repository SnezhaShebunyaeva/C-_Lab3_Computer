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

	//���������� ������� �� ��� ���, ���� ���� �� ������ 0 (����� �� ����������� ������ ��� ������� �������� add)
	void addModelData();

	void clearList();

	//������ ������� ������
	void modelPrint(deque<Model>::iterator x);

	//������ ���� �������
	void modelPrintPart();

	void modelPrintAllModel();
	
	bool Contains(deque<Model>::iterator x);

	//�������� �������� ������
	void modelDataRemove(deque<Model>::iterator x);

	//��������� ���������� � �������� ������
	void modelDataChange(deque<Model>::iterator x);

	//�������� ����� ��������� ������ � ����
	void loadTo(ofstream& _file, deque<Model>::iterator x);

	//�������� ���� ������� � ����
	void loadPartTo(ofstream& _file);

	//�������� ������� �� ������ � ��������� ���� 
	void loadResultTo(ofstream& _file);

	//�������� ������ ������ �� �����
	void loadFrom(ifstream& _file);

	//�������� ���� ������� �� �����
	void loadPartFrom(ifstream& _file);
};

