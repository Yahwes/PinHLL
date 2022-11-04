#include <iostream>
#include <string>

using namespace std;

	class Factory
{
public:
	Factory();
	virtual void Count() = 0;
	virtual void Print() = 0;
	Factory(int, int, int, int, int);
	int Rooms;
	int Floors;
	int Square;
	int YearOfConstrusction;
	int AmountOfWorkers;
	virtual ~Factory() {};
protected:
};

class ProcurementPlant : public virtual Factory
{
public:
	ProcurementPlant();
	ProcurementPlant(int, int, int, int, int, int);
	void Count() override;
	void Print() override;
	~ProcurementPlant();
protected:
	int AmountOfProducts = 0;
protected:

};
class ProcessingPlant : public virtual Factory
{
public:
	ProcessingPlant();
	ProcessingPlant(int, int, int, int, int,int, int);
	void Count() override;
	void Print() override;
	void SetMaxVolumeForRecycledItems(int);
	void SetVolumeOfRecycledItems(int);
	void SetMaxVolumeForNotRecycledItems(int);
	void SetVolumeOfNotRecycledItems(int);
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
	Foundry(int, int, int, int, int);
	void Count() override;
	void Print() override;
	~Foundry();
protected:
	int FoNumberItems;
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

ProcurementPlant::ProcurementPlant()
{
	AmountOfProducts = 0;
}
ProcurementPlant::ProcurementPlant(int room, int floor, int sqr, int year, int workers, int a)
{
	Rooms = room;
	Floors = floor;
	Square = sqr;
	YearOfConstrusction = year;
	AmountOfWorkers = workers;
	AmountOfProducts = a;
}
ProcurementPlant::~ProcurementPlant()
{
};
void ProcurementPlant::Count()
{
	cout << "Number of products per number of employees: " << double(AmountOfWorkers) / AmountOfProducts << endl;
}
void ProcurementPlant::Print()
{
	cout << endl << "Number of rooms: " << Rooms << endl;
	cout << "Number of floors: " << Floors << endl;
	cout << "Plant area: " << Square << endl;
	cout << "Year of Construction: " << YearOfConstrusction << endl;
	cout << "Number of workers: " << AmountOfWorkers << endl;
	cout << "Number of Product: " << AmountOfProducts << endl;
	cout << endl;
}

ProcessingPlant::ProcessingPlant()
{

}
ProcessingPlant::ProcessingPlant(int room, int floor, int sqr, int year, int workers, int Rec, int Not)
{
	Rooms = room;
	Floors = floor;
	Square = sqr;
	YearOfConstrusction = year;
	AmountOfWorkers = workers;
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
void ProcessingPlant::Count()
{
	cout << "Average area per room: " << double(Square) / Rooms << endl;
}
void ProcessingPlant::Print()
{
	cout << endl << "Number of rooms: " << Rooms << endl;
	cout << "Number of floors: " << Floors << endl;
	cout << "Plant area: " << Square << endl;
	cout << "Year of Construction: " << YearOfConstrusction << endl;
	cout << "Number of workers: " << AmountOfWorkers << endl;
	cout << "Maximum volume of recycled items: " << MaxVolumeForRecycledItems << endl;
	cout << "Maximum volume of not recycled items: " << MaxVolumeForNotRecycledItems << endl;
	cout << "Volume of recycled items: " << VolumeOfRecycledItems << endl;
	cout << "Volume of not recycled items: " << VolumeOfNotRecycledItems << endl;
}

Foundry::Foundry()
{
	FoNumberItems = 0;
}
Foundry::Foundry(int room, int floor, int sqr, int year, int workers)
{
	Rooms = room;
	Floors = floor;
	Square = sqr;
	YearOfConstrusction = year;
	AmountOfWorkers = workers;
	FoNumberItems = 0;
}
Foundry::~Foundry()
{
}
void Foundry::Count()
{
	cout << "Number of rooms per floor: " << Rooms / Floors << endl;
}
void Foundry::Print()
{
	cout << endl << "Number of rooms: " << Rooms << endl;
	cout << "Number of floors: " << Floors << endl;
	cout << "Plant area: " << Square << endl;
	cout << "Year of Construction: " << YearOfConstrusction << endl;
	cout << "Number of workers: " << AmountOfWorkers << endl;
	cout << "Number of Product: " << AmountOfProducts << endl;
	cout << endl;
}

int main()
{
	Factory** mass = new Factory* [3];
	
	mass[0] = new ProcurementPlant(10, 2, 10000, 1983, 50, 5);
	mass[1] = new ProcessingPlant(10, 1, 5000, 1963, 32, 1100, 500);
	mass[2] = new Foundry(30, 3, 15025, 1999, 60);

	for (int i = 0; i < 3; i++)
	{
		mass[i]->Count();
		mass[i]->Print();
		cout << endl;
		delete mass[i];
	}
	
	delete[] mass;
	return 1;
}