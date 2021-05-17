#include "modelDataList.h"
#include "menuEn.h"

modelDataList::modelDataList() :modelDeque(), helpDeque() {}

void modelDataList::addModelData()
{
	ofstream _file;
	istream_iterator<Model> is;
	int choice;
	menu menu_choice;
	menu_choice.Add("yes");
	menu_choice.Add("no");

	do
	{
		is = cin;
		modelDeque.push_front(*is);
		cout << endl;
		cout << endl;
		cout << "Model was added successfully." << endl;
		cout << endl;
		cout << endl;
		auto x = modelDeque.begin();
		_file.open(modelListHistory, ios::app);
		loadTo(_file, x);
		_file.close();
		cin.get();
		cout << "Add a new model?" << endl;
		menu_choice.Print();
		choice = menu_choice.Choice("Add a new model? (yes/no)");
		system("cls");
	} while (choice == 2);
}

void modelDataList::clearList()
{
	modelDeque.clear();
	helpDeque.clear();
}

void modelDataList::modelPrint(deque<Model>::iterator x)
{
	cout << *x;
}

void modelDataList::modelPrintPart()
{
	copy(helpDeque.begin(), helpDeque.end(), ostream_iterator<Model>(cout, ""));
}

void modelDataList::modelPrintAllModel()
{
	copy(modelDeque.begin(), modelDeque.end(), ostream_iterator<Model>(cout, ""));
}

bool modelDataList::Contains(deque<Model>::iterator x)
{
	return true;
}

void modelDataList::modelDataRemove(deque<Model>::iterator x)
{
	if (x != modelDeque.end())
	{
		modelDeque.erase(x);
		cout << endl;
		cout << endl;
		cout << "Model information was removed successfully." << endl;
		cout << endl;
		cout << endl;
	}
}

void modelDataList::modelDataChange(deque<Model>::iterator x)
{
	istream_iterator<Model> is(cin);
	*x = *is;
	cout << endl;
	cout << endl;
	cout << "Model information was changed successfully." << endl;
	cout << endl;
	cout << endl;
}

void modelDataList::loadTo(ofstream& _file, deque<Model>::iterator x)
{
	ostream_iterator<Model> is(_file);
	*is = *x;
	cout << endl;
	cout << endl;
	cout << "Added to file successfully." << endl;
	cout << endl;
	cout << endl;
}

void modelDataList::loadPartTo(ofstream& _file)
{
	copy(modelDeque.begin(), modelDeque.end(), ostream_iterator<Model>(_file));
	cout << endl;
	cout << endl;
	cout << "Added to file successfully." << endl;
	cout << endl;
	cout << endl;
}

void modelDataList::loadResultTo(ofstream& _file)
{
	copy(helpDeque.begin(), helpDeque.end(), ostream_iterator<Model>(_file));
	cout << endl;
	cout << endl;
	cout << "Added to file successfully." << endl;
	cout << endl;
	cout << endl;
}

void modelDataList::loadFrom(ifstream& _file)
{
	istream_iterator<Model> is(_file);
	modelDeque.push_front(*is);
	cout << endl;
	cout << endl;
	cout << "Loaded from file successfully." << endl;
	cout << endl;
	cout << endl;
}

void modelDataList::loadPartFrom(ifstream& _file)
{
	istream_iterator<Model> is(_file);
	while (!_file.eof())
	{
		modelDeque.push_front(*is);
		++is;
	}
	cout << endl;
	cout << endl;
	cout << "Loaded from file successfully." << endl;
	cout << endl;
	cout << endl;
}
