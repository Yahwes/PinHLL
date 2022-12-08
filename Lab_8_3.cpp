#include <iostream>
#include <string>
using namespace std;

template<class T>
class SinglyLinkedList
{
private:
	class Node
	{
	public:
		Node* next;
		T value;

		Node(T value) :value(value) {}
		Node() {}
		~Node() {}
	};
public:
    class Iterator
    {
    private:
        Node* node;

    public:
        Iterator() : node(0) { }
        Iterator(Node* dn) : node(dn) { }
        Iterator(const Iterator& it) : node(it.node) { }

        Iterator& operator=(const Iterator& it)
        {
            node = it.node;
            return *this;
        }
        bool operator==(const Iterator& it)
        {
            return (node == it.node);
        }
        bool operator!=(const Iterator& it) 
        {
            return (node != it.node);
        }
        Iterator& operator++()
        {
            if (node == 0)
                throw "incremented an empty iterator";

            node = node->next;
            return *this;
        }
        Iterator operator++(int) { Iterator temp = *this; node = node->next; return temp; }
        T& operator*() 
        {
            if (node == 0)
                throw "tried to dereference an empty iterator";
            
            return node->value;
        }
        T* operator->() { return node; }

    };
private:
    Node* head;
    Node* last;
    int count = 0;
    Iterator head_iterator;
public:
    bool ClassUnique;
    
    SinglyLinkedList(bool ClassUnique = false)
    {
        head = last = nullptr;
        this->ClassUnique = ClassUnique;
    }
    bool IsUnique(T value)
    {
        if (!ClassUnique)
            return true;

        bool isExist = (Search(value) != nullptr && head != nullptr);
        if (isExist)
            throw "Value is already exist";

        return !isExist;
    }
    void PushBegin(T value)
    {
        if (!IsUnique(value))
            return;
        Node* node = new Node<T>(value);
        node->next = head;
        head = node;
        count++;
    }
    void Push(T value)
    {
        if (!IsUnique(value))
            return;
        Node* node = new Node(value);

        if (head == nullptr)
        {
            head = last = node;
        }
        else
        {
            last->next = node;
            last = node;
        }
        count++;
    }
    Node* Search(T value)
    {
        Node* current = head;
        while (current != nullptr)
        {
            if (current->value == value)
                return current;
            current = current->next;
        }
        return nullptr;
    }
    bool Remove(T value)
    {
        Node* current = head;

        current = Search(value);

        if (current != nullptr)
        {
            Node* temp = head;
            if (current == temp)
            {
                head = temp->next;
                count--;
                return true;
            }
            while (temp->next != current)
                temp = temp->next;
            temp->next = current->next;
            if (current->next == nullptr)
                last = temp;

            count--;
            return true;
        }
        return false;
    }
    void Print()
    {
        for (auto i : *this)
            cout << i << " ";
        cout << endl;
    }

    Iterator begin() { return Iterator(head); }
    Iterator end() { return Iterator(nullptr); }
};


template <class A>
void SomethingType()
{
    rewind(stdin);
    cout << "Do you need unique list? \n Y - Yes | N - No\nYou choose: ";
    bool ClassUnique = (getchar() == 'Y');

    SinglyLinkedList<A> array = *(new SinglyLinkedList<A>(ClassUnique));
    A OK;
    char temp;
    bool End = false;
    try
    {
        while (!End)
        {
            cout << "a - Enter element\nb - Print\nc - Find element\nd - Delete element\ne - End\nYou choose: ";
            rewind(stdin);
            switch (getchar())
            {
            case 'a':
                cout << "Push element: ";
                rewind(stdin);
                cin >> OK;
                //BLYAT_A
                temp = getchar();
                if (temp != '\n')
                    throw "Incorrect input";

                array.Push(OK);
                break;
            case 'b':
                array.Print();
                break;
            case 'c':
                rewind(stdin);
                cout << "What element to look for: ";
                cin >> OK;
                //BLYAT_C
                temp = getchar();
                if (temp != '\n')
                    throw "Incorrect input";

                if (array.Search(OK) == NULL)
                    cout << "Not exist" << endl;
                else
                    cout << "Exist" << endl;
                break;
            case 'd':
                rewind(stdin);
                cout << "Which element to delete: ";
                cin >> OK;
                //BLYAT_D
                temp = getchar();
                if (temp != '\n')
                    throw "Incorrect input";

                array.Remove(OK);
                break;
            case 'e':
                End = true;
                break;
            default:
                break;
            }
        }
    }
    catch (const char* message)
    {
        cout << string(message);
        terminate();
    }
}


int main()
{
    string type;
    int check = 1;
    do
    {
        cout << "Input variable type (int/float/double/string): ";
        cin >> type;

        if (!type.compare("int"))
            SomethingType<int>();
        else if (!type.compare("float"))
            SomethingType<float>();
        else if (!type.compare("double"))
            SomethingType<double>();
        else if (!type.compare("string"))
            SomethingType<string>();
        else
            check++;
        check--;
    } while (check);

	return 1;
}
