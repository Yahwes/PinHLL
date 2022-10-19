#include <iostream>
#include <string>

using namespace std;

class Factory
{
public:
	Factory();
	Factory(int, int, int, int, int);
	int Rooms;
	int Floors;
	int Square;
	int YearOfConstrusction;
	int AmountOfWorkers;
	friend std::ostream& operator<<(std::ostream& os, const Factory& value);
	friend std::istream& operator>>(std::istream& is, Factory& value);
protected:
};

class ProcurementPlant : public virtual Factory
{
public:
	ProcurementPlant();
	void AddProduct(string);
	void DeleteProduct(string);
	~ProcurementPlant();
	friend std::ostream& operator<<(std::ostream& os, const ProcurementPlant& value);
	friend std::istream& operator>>(std::istream& is, ProcurementPlant& value);
protected:
	string* Product;
	int AmountOfProducts = 0;
protected:

};
class ProcessingPlant : public virtual Factory
{
public:
	ProcessingPlant();
	ProcessingPlant(int, int);
	void SetMaxVolumeForRecycledItems(int);
	void SetVolumeOfRecycledItems(int);
	void SetMaxVolumeForNotRecycledItems(int);
	void SetVolumeOfNotRecycledItems(int);
	friend std::ostream& operator<<(std::ostream& os, const ProcessingPlant& value);
	friend std::istream& operator>>(std::istream& is, ProcessingPlant& value);
protected:
	int MaxVolumeForRecycledItems = 0;
	int VolumeOfRecycledItems = 0;
	int MaxVolumeForNotRecycledItems = 0;
	int VolumeOfNotRecycledItems = 0;
private:
};

class Foundry : public ProcurementPlant
{
public:
	Foundry();
	void AddFoItem(string);
	~Foundry();
	friend std::ostream& operator<<(std::ostream& os, const Foundry& value);
	friend std::istream& operator>>(std::istream& is, Foundry& value);
protected:	
	string * FoItems;
	int FoNumberItems;
};
class MechanicalPlant : public ProcessingPlant
{
public:
	MechanicalPlant();
	void AddMechItem(string);
	~MechanicalPlant();
	friend std::ostream& operator<<(std::ostream& os, const MechanicalPlant& value);
	friend std::istream& operator>>(std::istream& is, MechanicalPlant& value);
protected:
	string * MechItems;
	int MechNumberItems;
};

class ManufacturingPlant : public Foundry,public MechanicalPlant
{
public:
	ManufacturingPlant();
	void AddExpenses(int);
	~ManufacturingPlant();
	friend std::ostream& operator<<(std::ostream& os, const ManufacturingPlant& value);
	friend std::istream& operator>>(std::istream& is, ManufacturingPlant& value);
protected:
	int Expenses;
};

Factory::Factory()
{
	Rooms = 0;
	Floors = 0;
	Square = 0;
	YearOfConstrusction = 0;
	AmountOfWorkers = 0;
}
Factory::Factory(int Rooms, int Floors, int Square, int YearOfConstraction, int AmountOfWorkers)
{
	this->Rooms = Rooms;
	this->Floors = Floors;
	this->Square = Square;
	this->YearOfConstrusction = YearOfConstraction;
	this->AmountOfWorkers = AmountOfWorkers;
}
std::ostream& operator<<(std::ostream& os, const Factory& value)
{
	os << endl << "Number of rooms: " << value.Rooms << endl;
	os << "Number of floors: " << value.Floors << endl;
	os << "Plant area: " << value.Square << endl;
	os << "Year of Construction: " << value.YearOfConstrusction << endl;
	os << "Number of workers: " << value.AmountOfWorkers << endl;
	return os;
}
std::istream& operator>>(std::istream& is, Factory& value) 
{ 
	is >> value.Rooms >> value.Floors >> value.Square >> value.YearOfConstrusction >> value.AmountOfWorkers; return is;}

ProcurementPlant::ProcurementPlant()
{
	AmountOfProducts = 0;
	Product = nullptr;
}
void ProcurementPlant::AddProduct(string Product)
{
	string *temp;
	temp = new string[this->AmountOfProducts];
	for (int i = 0; i < AmountOfProducts; i++)
	{
		temp[i] = this->Product[i];
	}
	delete[] this->Product;
	AmountOfProducts++;
	this->Product = new string[AmountOfProducts];
	for (int i = 0; i < AmountOfProducts - 1; i++)
	{
		this->Product[i] = temp[i];
	}
	this->Product[AmountOfProducts - 1] = Product;
	delete[] temp;
}
void ProcurementPlant::DeleteProduct(string Product)
{
	int i = 0, j = 0;
	bool check = 1;
	this->AmountOfProducts--;
	string* temp = new string[this->AmountOfProducts + 1];
	while (j < AmountOfProducts + 1)
	{
		if (Product == this->Product[j] && check)
		{
			check = 0;
		}
		else
		{ 
			temp[i] = this->Product[j];
			i++;
		}
		j++;
	}
	delete[] this->Product;
	if (check)
		AmountOfProducts++;
	this->Product = new string[this->AmountOfProducts];
	for (i = 0; i < AmountOfProducts; i++)
	{
		this->Product[i] = temp[i];
	}
	if (check) {
		this->Product[AmountOfProducts - 1] = temp[AmountOfProducts - 1];
	}
	delete[] temp;
}
ProcurementPlant::~ProcurementPlant()
{
	delete[]this->Product;
};
std::ostream& operator<<(std::ostream& os, const ProcurementPlant& value)
{	
	os << endl << "Number of rooms: " << value.Rooms << endl;
	os << "Number of floors: " << value.Floors << endl;
	os << "Plant area: " << value.Square << endl;
	os << "Year of Construction: " << value.YearOfConstrusction << endl;
	os << "Number of workers: " << value.AmountOfWorkers << endl;
	os << "Number of Product: " << value.AmountOfProducts << endl;
	os << "Products: ";
	for (int i = 0; i < value.AmountOfProducts; i++)
	{
		os << value.Product[i];
		if (i != value.AmountOfProducts - 1) os << ", ";
	}
	os << endl;
	return os;
}
std::istream& operator>>(std::istream& is, ProcurementPlant& value)
{
	is >> value.Rooms >> value.Floors >> value.Square >> value.YearOfConstrusction >> value.AmountOfWorkers;
	is >> value.AmountOfProducts;
	value.Product = new string[value.AmountOfProducts];
	for (int i = 0; i < value.AmountOfProducts; i++) is >> value.Product[i];
	return is;
}

ProcessingPlant::ProcessingPlant()
{

}
ProcessingPlant::ProcessingPlant(int Rec, int Not)
{
	VolumeOfRecycledItems = Rec;
	VolumeOfNotRecycledItems = Not;
	if (!VolumeOfRecycledItems) MaxVolumeForRecycledItems = Not;
	else if (!VolumeOfNotRecycledItems) MaxVolumeForNotRecycledItems = Rec;
	else
	{
		MaxVolumeForRecycledItems = Rec + Not;
		MaxVolumeForNotRecycledItems = MaxVolumeForRecycledItems;
	}
}
void ProcessingPlant::SetMaxVolumeForRecycledItems(int value)
{
	MaxVolumeForRecycledItems = value;
}
void ProcessingPlant::SetVolumeOfRecycledItems(int value)
{
	VolumeOfRecycledItems = value;
}
void ProcessingPlant::SetMaxVolumeForNotRecycledItems(int value)
{
	MaxVolumeForNotRecycledItems = value;
}
void ProcessingPlant::SetVolumeOfNotRecycledItems(int value)
{
	VolumeOfNotRecycledItems = value;
}
std::ostream& operator<<(std::ostream& os, const ProcessingPlant& value)
{
	os << endl << "Number of rooms: " << value.Rooms << endl;
	os << "Number of floors: " << value.Floors << endl;
	os << "Plant area: " << value.Square << endl;
	os << "Year of Construction: " << value.YearOfConstrusction << endl;
	os << "Number of workers: " << value.AmountOfWorkers << endl;
	os << "Maximum volume of recycled items" << value.MaxVolumeForRecycledItems << endl;
	os << "Maximum volume of not recycled items" << value.MaxVolumeForNotRecycledItems << endl;
	os << "Volume of recycled items" << value.VolumeOfRecycledItems << endl;
	os << "Volume of not recycled items" << value.VolumeOfNotRecycledItems << endl;
	return os;
}
std::istream& operator>>(std::istream& is, ProcessingPlant& value)
{
	is >> value.Rooms >> value.Floors >> value.Square >> value.YearOfConstrusction >> value.AmountOfWorkers;
	is >> value.MaxVolumeForRecycledItems >> value.MaxVolumeForNotRecycledItems >> value.VolumeOfRecycledItems >> value.VolumeOfNotRecycledItems;
	return is;
}

Foundry::Foundry()
{
	FoItems = nullptr;
	FoNumberItems = 0;
}
void Foundry::AddFoItem(string item)
{
	string* temp;
	temp = new string[this->FoNumberItems];
	for (int i = 0; i < FoNumberItems; i++)
	{
		temp[i] = this->FoItems[i];
	}
	delete[] this->FoItems;
	FoNumberItems++;
	this->FoItems = new string[FoNumberItems];
	for (int i = 0; i < FoNumberItems - 1; i++)
	{
		this->FoItems[i] = temp[i];
	}
	this->FoItems[FoNumberItems - 1] = item;
	delete[] temp;
}
Foundry::~Foundry()
{
	delete[]this->FoItems;
}
std::ostream& operator<<(std::ostream& os, const Foundry& value)
{
	os << endl << "Number of rooms: " << value.Rooms << endl;
	os << "Number of floors: " << value.Floors << endl;
	os << "Plant area: " << value.Square << endl;
	os << "Year of Construction: " << value.YearOfConstrusction << endl;
	os << "Number of workers: " << value.AmountOfWorkers << endl;
	os << "Number of Product: " << value.AmountOfProducts << endl;
	os << "Products: ";
	for (int i = 0; i < value.AmountOfProducts; i++)
	{
		os << value.Product[i];
		if (i != value.AmountOfProducts - 1) os << ", ";
	}
	os << endl;
	os << "Number of Items: " << value.FoNumberItems << endl;
	os << "Items: ";
	for (int i = 0; i < value.FoNumberItems; i++)
	{
		os << value.FoItems[i];
		if (i != value.FoNumberItems - 1) os << ", ";
	}
	os << endl;
	return os;
}
std::istream& operator>>(std::istream& is, Foundry& value)
{
	is >> value.Rooms >> value.Floors >> value.Square >> value.YearOfConstrusction >> value.AmountOfWorkers;
	is >> value.AmountOfProducts;
	value.Product = new string[value.AmountOfProducts];
	for (int i = 0; i < value.AmountOfProducts; i++) is >> value.Product[i];
	is >> value.FoNumberItems;
	value.FoItems = new string[value.FoNumberItems];
	for (int i = 0; i < value.FoNumberItems; i++) is >> value.FoItems[i];
	return is;
}

MechanicalPlant::MechanicalPlant()
{
	MechItems = nullptr;
	MechNumberItems = 0;
}
void MechanicalPlant::AddMechItem(string item)
{
	string* temp;
	temp = new string[this->MechNumberItems];
	for (int i = 0; i < MechNumberItems; i++)
	{
		temp[i] = this->MechItems[i];
	}
	delete[] this->MechItems;
	MechNumberItems++;
	this->MechItems = new string[MechNumberItems];
	for (int i = 0; i < MechNumberItems - 1; i++)
	{
		this->MechItems[i] = temp[i];
	}
	this->MechItems[MechNumberItems - 1] = item;
	delete[] temp;
}
MechanicalPlant::~MechanicalPlant()
{
	delete[]this->MechItems;
}
std::ostream& operator<<(std::ostream& os, const MechanicalPlant& value)
{
	os << endl << "Number of rooms: " << value.Rooms << endl;
	os << "Number of floors: " << value.Floors << endl;
	os << "Plant area: " << value.Square << endl;
	os << "Year of Construction: " << value.YearOfConstrusction << endl;
	os << "Number of workers: " << value.AmountOfWorkers << endl;
	os << "Maximum volume of recycled items" << value.MaxVolumeForRecycledItems << endl;
	os << "Maximum volume of not recycled items" << value.MaxVolumeForNotRecycledItems << endl;
	os << "Volume of recycled items" << value.VolumeOfRecycledItems << endl;
	os << "Volume of not recycled items" << value.VolumeOfNotRecycledItems << endl;
	os << endl;
	os << "Number of Items: " << value.MechNumberItems << endl;
	os << "Items: ";
	for (int i = 0; i < value.MechNumberItems; i++)
	{
		os << value.MechItems[i];
		if (i != value.MechNumberItems - 1) os << ", ";
	}
	os << endl;
	return os;
}
std::istream& operator>>(std::istream& is, MechanicalPlant& value)
{
	is >> value.Rooms >> value.Floors >> value.Square >> value.YearOfConstrusction >> value.AmountOfWorkers;
	is >> value.MaxVolumeForRecycledItems >> value.MaxVolumeForNotRecycledItems >> value.VolumeOfRecycledItems >> value.VolumeOfNotRecycledItems;
	is >> value.MechNumberItems;
	value.MechItems = new string[value.MechNumberItems];
	for (int i = 0; i < value.MechNumberItems; i++) is >> value.MechItems[i];
	return is;
}

ManufacturingPlant::ManufacturingPlant()
{
	Expenses = 0;
};
void ManufacturingPlant::AddExpenses(int value)
{
	Expenses += value;
}
ManufacturingPlant::~ManufacturingPlant()
{
};
std::ostream& operator<<(std::ostream& os, const ManufacturingPlant& value)
{
	os << endl << "Number of rooms: " << value.Rooms << endl;
	os << "Number of floors: " << value.Floors << endl;
	os << "Plant area: " << value.Square << endl;
	os << "Year of Construction: " << value.YearOfConstrusction << endl;
	os << "Number of workers: " << value.AmountOfWorkers << endl;
	os << "Number of Product: " << value.AmountOfProducts << endl;
	os << "Products: ";
	for (int i = 0; i < value.AmountOfProducts; i++)
	{
		os << value.Product[i];
		if (i != value.AmountOfProducts - 1) os << ", ";
	}
	os << endl;
	os << "Number of Foundry Items: " << value.FoNumberItems << endl;
	os << "Foundry Items: ";
	for (int i = 0; i < value.FoNumberItems; i++)
	{
		os << value.FoItems[i];
		if (i != value.FoNumberItems - 1) os << ", ";
	}
	os << endl;
	os << "Maximum volume of recycled items: " << value.MaxVolumeForRecycledItems << endl;
	os << "Maximum volume of not recycled items: " << value.MaxVolumeForNotRecycledItems << endl;
	os << "Volume of recycled items: " << value.VolumeOfRecycledItems << endl;
	os << "Volume of not recycled items: " << value.VolumeOfNotRecycledItems << endl;
	os << "Number of Mechanical Plant Items: " << value.MechNumberItems << endl;
	os << "Mechanical Plant Items: ";
	for (int i = 0; i < value.MechNumberItems; i++)
	{
		os << value.MechItems[i];
		if (i != value.MechNumberItems - 1) os << ", ";
	}
	os << endl;
	os << "Expenses: " << value.Expenses;
	return os;
}
std::istream& operator>>(std::istream& is, ManufacturingPlant& value)
{
	cout << "Enter number of rooms: ";
	is >> value.Rooms;
	cout << "Number of floors: ";
	is >> value.Floors;
	cout << "Plant of factory in cubic meters: ";
	is >> value.Square;
	cout << "Year of construction: ";
	is >> value.YearOfConstrusction;
	cout << "Number of workers: ";
	is >> value.AmountOfWorkers;
	cout << "Number of products: ";
	is >> value.AmountOfProducts;
	cout << "These products: ";
	value.Product = new string[value.AmountOfProducts];
	for (int i = 0; i < value.AmountOfProducts; i++) is >> value.Product[i];
	cout << "Number of Foundry items: ";
	is >> value.FoNumberItems;
	cout << "Foundry items: ";
	value.FoItems = new string[value.FoNumberItems];
	for (int i = 0; i < value.FoNumberItems; i++) is >> value.FoItems[i];
	cout << "Maximum volume of recycled items: ";
	is >> value.MaxVolumeForRecycledItems;
	cout << "Maximum volume of not recycled items : ";
	is >> value.MaxVolumeForNotRecycledItems;
	cout << "Volume of recycled items: ";
	is >> value.VolumeOfRecycledItems;
	cout << "Volume of not recycled items: ";
	is >> value.VolumeOfNotRecycledItems;
	cout << "Number of Mechanical Plant Items: ";
	is >> value.MechNumberItems;
	cout << "Mechanical Plant Items: ";
	value.MechItems = new string[value.MechNumberItems];
	for (int i = 0; i < value.MechNumberItems; i++) is >> value.MechItems[i];
	cout << "Expenses: ";
	is >> value.Expenses;
	return is;
}

int main()
{
	ManufacturingPlant a;
	cout << "Before:" << endl << a << endl << endl;
	cin >> a;
	cout << a << endl;

	a.AddProduct("Phone");
	a.DeleteProduct("Laptop");
	a.AddExpenses(5);
	a.AddFoItem("Wheel");
	a.AddMechItem("Wheel");
	a.SetMaxVolumeForNotRecycledItems(50);
	a.SetMaxVolumeForRecycledItems(100);
	a.SetVolumeOfNotRecycledItems(20);
	a.SetVolumeOfRecycledItems(10);

	cout << a;
	return 1;
}
