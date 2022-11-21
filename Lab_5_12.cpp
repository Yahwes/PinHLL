#include <iostream>
using namespace std;

template <class T>
class set
{
public:
	set()
	{
		first = nullptr;
		end = nullptr;
		count = 0;
	}
	~set()
	{
		clear();
	}
	void push(T value)				//добавление в список
	{
		if (!count)
		{
			count++;
			first = new node;
			first->data = value;
			end = first;
			return;
		}
		node* ptr = first;
		for (int i = 0; i < count; i++)
		{
			if (ptr->data == value)
			{
				break;
			}
			if (ptr->data > value)
			{
				node* NEW = new node;
				NEW->data = value;
				NEW->previous = ptr->previous;
				NEW->next = ptr;

				if (ptr->previous)
				{
					node* back = ptr->previous;
					back->next = NEW;
				}
				if (!i)
					first = NEW;
				ptr->previous = NEW;
				count++;
				break;
			}
			if (i == count - 1)
			{
				node* NEW = new node;
				NEW->data = value;
				ptr->next = NEW;
				NEW->previous = ptr;
				count++;
				end = NEW;
				break;
			}
			ptr = ptr->next;
		}
	}
	void pop(T value)
	{
		if (!count)
			return;
		node* ptr = first;
		for (int i = 0; i < count; i++)
		{
			if (ptr->data == value)
			{
				node* next, * previous;
				next = ptr->next;
				previous = ptr->previous;
				next->previous = previous;
				previous->next = next;
				count--;
				delete ptr;
				break;
			}
			ptr = ptr->next;
		}
	}

	void print_all()						//печать списка
	{
		node* ptr = first;

		while (ptr)
		{
			cout << ptr->data << "\n";
			ptr = ptr->next;
		}
	}
	void print_all_rev()					//печать списка в обратном порядке
	{
		node* ptr = end;

		while (ptr)
		{
			cout << ptr->data << "\n";
			ptr = ptr->previous;
		}
	}
	void print_count()						//размерность множества
	{
		cout << count << endl;
	}
	int search(T value)
	{
		if (!count)
			return -1;
		node* ptr = first;
		int i;
		for (i = 0; i < count; i++)
		{
			if ((ptr->data) == value)
			{
				return i + 1;
			}
			ptr = ptr->next;
			if (i == count - 1)
			{
				return -1;
			}
		}
		return -1;
	}

	void clear()						//очистить список
	{
		while (first)
		{
			node* ptr = first;
			first = ptr->next;
			delete ptr;
		}
		end = first;
		count = 0;
	}
	bool clear_one(int num)				//удалить элемент
	{
		if(!count || !num || num > count + 1)
			return false;

		node* ptr = first;

		for(int cnt = 0;ptr;cnt++)
		{
			if (num - 1 == cnt) {
				node* ptr_prev = ptr->previous;
				node* ptr_next = ptr->next;

				if (ptr_prev)
					ptr_prev->next = ptr_next;
				if (ptr_next)
					ptr_next->previous = ptr_prev;

				if (!cnt)
					first = ptr->next;
				if (cnt == count - 1)
					end = ptr->previous;
				delete ptr;

				count--;
				return true;
			}
			ptr = ptr->next;
		}
		return false;
	}

	bool operator >(const set& val)
	{
		return this->count > val.count;
	}
	bool operator <(const set& val)
	{
		return this->count < val.count;
	}
	bool operator >=(const set& val)
	{
		return this->count >= val.count;
	}
	bool operator <=(const set& val)
	{
		return this->count <= val.count;
	}
	bool operator !=(const set& val)
	{
		return this->count != val.count;
	}
	bool operator ==(const set& val)
	{
		return this->count == val.count;
	}
	void operator = (const set& val)
	{
		this->clear();
		this->count = val.count;
		node* ptr = val.first;
		for (int i = 0; i < count; i++)
		{
			this->push(ptr.data);
			ptr = ptr.next;
		}
	}
	void operator +=(const set& val)
	{
		node* ptr = val.first;
		for (int i = 0; i < val.count; i++)
		{
			this->push(ptr->data);
			ptr = ptr->next;
		}
	}
protected:
	struct node
	{
	public:
		T data = 0;

		node* next = nullptr;
		node* previous = nullptr;
	};

	node* first;
	node* end; 
	int count;

private:

	set(const set& val)
	{
		this->clear();
		node* ptr = val.first;
		this->count = val.count;
		for (int i = 0; i < count; i++)
		{
			this->push(ptr.data);
			ptr = ptr.next;
		}
	}
};

int main()
{
	set<int> a;
	for (int i = 0; i < 5; i++)
	{
		a.push(rand());
	}
	a.print_all();
	cout << endl;
	a.print_all_rev();
	cout << endl;
	a.print_count();
	cout << endl;
	a.clear_one(a.search(41));
	a.print_all();
	a.clear_one(2);
	cout << endl;
	a.print_all();
	set <int> b;
	b.push(5);
	b.push(10);
	cout << "a > b:" << (a > b) << endl;
	cout << "a < b:" << (a < b) << endl;
	cout << "a >= b:" << (a >= b) << endl;
	cout << "a <= b:" << (a <= b) << endl;
	cout << "a == b:" << (a == b) << endl;
	cout << "a != b:" << (a != b) << endl;
	cout << "a.search(3): " << a.search(3) << endl << "a.search(6334): " << a.search(6334) << endl;
	a += b;
	cout << "a += b: " << endl;
	a.print_all();
	cout << endl;
	a.clear();
	a.print_all();
	return 1;
}	