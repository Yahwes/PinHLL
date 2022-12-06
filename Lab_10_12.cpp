#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<fstream>
using namespace std;


class Plant
{
private:
	string name;
	unsigned int age;
	float growth;
public:
	friend Plant CreatePlant(vector<string>);
	Plant() : name(""), age(0), growth(0) {}
	Plant(string name, unsigned int age, float growth) : name(name), age(age)
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
		bool a = 0;
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

	bool full()
	{
		if (name != "" && age != 0 && growth != 0)
			return true;
		return false;
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
	string remember = "-";
	for (int i = 0; i < 3;)
	{
		is >> temp;
		if (temp == remember)
			break;
		else
			remember = temp;
		if (temp == "Name:")
		{
			is >> plant.name;
			i++;
		}
		else if (temp == "Age:")
		{
			is >> temp;
			plant.age = stoi(temp);
			i++;
		}
		else if (temp == "Growth:")
		{
			is >> temp;
			plant.growth = stof(temp);
			i++;
		}

	}
	return is;
}

vector<string> GetWords(string line)
{
    vector<string> words;
	unsigned i = 0;

    while (1) {
		
		string word = "";

		for (; i < line.size(); i++)
		{
			if (line[i] == ' ') { i++; break; }

			word += line[i];
		}
       
		if (word == "")
			break;

		words.push_back(word);
	}
    return words;
}
vector<string> GetLines(ifstream* file)
{
    vector<string> words;
 
    while (!file->eof())
    {
        string temp;
        getline(*file, temp);
        words.push_back(temp);
    }
    return words;
}

Plant CreatePlant(vector<string> words)
{
	Plant res;

	for (auto i : words)
	{
		bool string_check = 0;
		bool float_check = 0;
		bool int_check = 0;
		for (auto j : i)
		{
			if (j != '.' && !(j <= '9' && j >= '0'))
				string_check = 1;
			if (j == '.')
				float_check = 1;
			if (j >= '0' && j <= '9')
				int_check = 1;
		}
		if (string_check) {res.name = i; continue;}
		if (float_check) { res.growth = stof(i); continue; }
		if (int_check) { res.age = atoi(i.c_str()); continue; }
		if (res.full()) break;

		throw "Erorr string in file";
	}

	return res;
}

int main()
{
    vector<string> lines;
    try
    {
        ifstream in("input.txt");
        if (in.is_open())
            cout << "File input.txt is opened" << endl;
        else
            throw "File opening error";

        lines = GetLines(&in);
        in.close();
        cout << "File input.txt is closed" << endl;
    }
    catch (const char* message) {
        cout << string(message) << endl;
        terminate();
    }

    for (auto line : lines)
    {
        vector<string> words = GetWords(line);

        try
        {
			Plant result = CreatePlant(words);

            ofstream out("output.txt", std::ios_base::app);
            if (out.is_open())
                cout << "File output.txt is opened" << endl;
            else
                throw "File opening error";
            out << result << endl;
            out.close();
            cout << "File output.txt is closed" << endl;
        }
        catch (const char* message)
        {
            cout << string(message) << endl;
            terminate();
        }
    }

    return 0;
}
