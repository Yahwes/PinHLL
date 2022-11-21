#include <iostream>
#include <string>
#include<fstream>
#include <vector>

#define FileName "Plants.txt"
#define CAN_NOT_OPEN_FILE_EXCEPTION "Failed to open file" 

using namespace std;

class Garden;
class Plant
{
private:
	string name;
	unsigned int age;
	float growth;
	friend class Garden;
public:
	friend Garden;
	Plant() : name(""), age(0), growth(0) {}
	Plant(string name,unsigned int age, float growth) : name(name), age(age) 
	{
		if (growth >= 0)
			this->growth = growth;
		else
			this->growth = 0;
	}
	bool operator ==(const Plant& value)
	{
		return name == value.name;
	}

	float Pour()
	{
		growth += float(rand() % 5);
		return growth;
	}
	int Wait(int years)
	{
		if (years >= 0)
		{
			age += years;
			growth += float((rand() % 5) * years);
		}
	}
	
	string ToString()
	{
		string result = "";
		string check = "";
		bool a= 0;
		for (auto i : to_string(growth))
		{
			check += i;
			if (a)
				break;
			if (i == '.')
				a = 1;
		}
		result += ("Name: " + name + "\nAge: " + to_string(age) + "\nGrowth: " + check + " cm\n");
		return result;
	}
	
	friend istream& operator>>(istream&, Plant&);
};
ostream& operator<<(ostream& os, Plant& plant)
{
	os << plant.ToString();
	return os;
}
istream& operator>>(istream& is, Plant& plant)
{
	string temp;
	for (int i = 0; i < 3;)
	{
		is >> temp;
		if (temp == "Name:")
		{
			is >> plant.name;
			i++;
		}
		else if(temp == "Age:")
		{
			is >> temp;
			plant.age = stoi(temp);
			i++;
		}
		else if(temp == "Growth:")
		{
			is >> temp;
			plant.growth = stof(temp);
			i++;
		}
	}
	return is;
}

class Garden
{
public:
	Garden() {}

	void AddPlant(Plant a)
	{
		Plants.push_back(a);
	}
	void WriteData(string _FileName, bool binary)
	{
		if (!binary)
		{
			WriteDataToTextFile(_FileName);
			return;
		}

		try
		{
			ofstream File(_FileName, ios_base::binary);
			if (!File.is_open())
				throw CAN_NOT_OPEN_FILE_EXCEPTION;
			for (auto a : Plants)
			{
				string line = a.ToString();
				File.write(line.c_str(), line.size());
				File.put('\r');
				File.put('\n');
			}

			File.close();
		}
		catch (const char* message)
		{
			cout << string(message) << endl;
			terminate();
		}
	}
	void GetData(string _FileName, bool binary)
	{
		if (!binary)
		{
			GetDataFromTextFile(_FileName);
			return;
		}

		Plants.clear();

		try
		{
			ifstream File(_FileName, ios_base::binary);

			if (!File.is_open())
				throw CAN_NOT_OPEN_FILE_EXCEPTION;

			Plant a;
			char PlantDataString[90];
			while (true)
			{
				vector<string> data;
				for (int k = 0; k < 3; k++)
				{
					File.getline(PlantDataString, 40);
					if (*PlantDataString == '\0')
						return;
					char* tmp = PlantDataString;

					if (PlantDataString[0] == '\r')
					{
						k--;
						continue;
					}

					char word[30];
					for (int i = 0, j = 0; true;)
					{
						if (PlantDataString[i] == ' ' || PlantDataString[i] == '\n' || PlantDataString[i] == '\0')
						{
							word[j] = '\0';
							if (j != 0)
								data.push_back(word);
							j = 0;
							if (PlantDataString[i] == '\0' || PlantDataString[i] == '\n')	
								break;
							i++;
							continue;
						}
						word[j++] = PlantDataString[i++];
					}

					if (data.size() == 0) break;
					else
					{
						if (data[0] == "Name:")
						{
							a.name = data[1];
						}
						else if (data[0] == "Age:")
						{
							a.age = 0;
							for(int q = 0;data[1][q] != '\0';q++)
								a.age = a.age * 10 + data[1][q] - '0';
						}
						else if (data[0] == "Growth:")
						{
							a.growth = 0;
							for (int q = 0; data[1][q] != '\0'; q++)
							{
								if (data[1][q] == '.')
								{
									q++;
									a.growth = a.growth + (float(data[1][q] - '0') / 10);
									break;
								}
								a.growth = a.growth * 10 + data[1][q] - '0';
								
							}
						}
						data.clear();
					}

					if (k == 2)
					{
						Plants.push_back(a);
					}
				}
			}

			File.close();
		}
		catch (const char* message)
		{
			cout << string(message) << endl;
			terminate();
		}
	}
	void PrintData(string _FileName, bool binary)
	{
		try {
			ifstream File(_FileName, ios_base::binary);

			if (!File.is_open())
				throw CAN_NOT_OPEN_FILE_EXCEPTION;

			while (true)
			{
				char PlantDataString[90];
				
				File.getline(PlantDataString, 90);

				if (PlantDataString[0] == '\0')
					return;
				cout << PlantDataString << endl;
			}

			File.close();

		}
		catch (const char* message)
		{
			cout << string(message) << endl;
			terminate();
		}
	}
	void PrintReverseData(string _FileName, bool binary)
	{
		try
		{
			ifstream File(_FileName, ios_base::binary);
			if (!File.is_open())
				throw CAN_NOT_OPEN_FILE_EXCEPTION;
			File.seekg(0, ios::end);

			while (true)
			{
				char PlantDataString[90];
				
				if (File.tellg() == 0)
					break;

				bool check = 0;
				while (!(check && 0))
				{
					File.seekg(-1, ios::cur);
					char c = File.get();
					File.seekg(-1, ios::cur);
					if (c == '\n' || File.tellg() == 0)
					{
						if (check) break;
						check = 1;
					}
				}

				File.seekg(1, ios::cur);

				File.getline(PlantDataString, 90);

				cout << PlantDataString << endl;
			
				check = 0;
				while (!(check && 0))
				{
					File.seekg(-1, ios::cur);
					char c = File.get();
					File.seekg(-1, ios::cur);
					if (c == '\n' || File.tellg() == 0)
					{
						if (check) break;
						check = 1;
					}
				}

				if (File.tellg() != 0)
					File.seekg(1, ios::cur);
			}

			File.close();
		}
		catch (const char* message)
		{
			cout << string(message) << endl;
			terminate();
		}
	}
	string FindByName(string Name, string _FileName, bool binary)
	{
		GetData(_FileName, binary);
		if (Plants.size() == 0)
			return "";

		for (auto a : Plants)
		{
			if (a.name == Name)
				return a.ToString();
		}
		return "";
	}
	string DeletePlantByName(string Name, string _FileName, bool binary)
	{
		GetData(_FileName, binary);
		
		string search;
		
		for (auto a : Plants)
		{
			if (a.name == Name)
			{
				search = a.ToString();
				Plants.erase(std::find(Plants.begin(), Plants.end(), a));
			}
		}

		WriteData(_FileName, binary);
		return search;
	}
private:
	vector<Plant> Plants;
	void WriteDataToTextFile(string _FileName)
	{
		try
		{
			ofstream File(_FileName);

			if (!File.is_open())
				throw CAN_NOT_OPEN_FILE_EXCEPTION;


			for (auto a : Plants)
			{
				string line = a.ToString();
				File << line << endl;
			}

			File.close();
		}
		catch (const char* message)
		{
			cout << string(message) << endl;
			terminate();
		}
	}
	void GetDataFromTextFile(string _FileName)
	{
		Plants.clear();
		try
		{
			ifstream File(_FileName);
			if (!File.is_open())
				throw CAN_NOT_OPEN_FILE_EXCEPTION;
			
			while (true)
			{
				Plant a;
				File >> a;

				if (a.age == 0)
					break;

				Plants.push_back(a);
			}
			
			File.close();
		}
		catch (const char* message)
		{
			cout << string(message) << endl;
			terminate();
		}
	}
};

int main()
{
	Garden garden;

	int count = 0;
	cout << "Input count of plants: ";
	cin >> count;
	
	for (int i = 0; i < count; i++)
	{
		Plant temp;
		cin >> temp;
		garden.AddPlant(temp);
	}

	bool binary;
	cout << "Is file binary?\n1 - Yes\n0 - No\nYou choose: ";
	cin >> binary;

	garden.WriteData(FileName, binary);

	cout << "Data from file: \n";
	garden.PrintData(FileName, binary);
	cout << endl << "Reverse data from file: \n";
	garden.PrintReverseData(FileName, binary);

	string Name;
	cout << "Input plant name for deleting: ";
	cin >> Name;
	cout << endl << garden.DeletePlantByName(Name, FileName, binary) << endl;

	cout << "Input plant name for find: ";
	cin >> Name;
	cout << endl << garden.FindByName(Name, FileName, binary) << endl;

	return 1;
}