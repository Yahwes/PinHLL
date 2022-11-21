#include <iostream>
#include <iterator>
using namespace std;

#define SET_EMTPY_EXCEPTION "Set is empty"
#define SET_FULL_EXCEPTION "Set is full"
#define SET_BEYOND_LIMIT "Going beyond the set"

void MyTerminate() {
    printf("Called MyTerminate\n");
    abort();
}
void MyUnexpected() {
    printf("Called MyUnexpected\n");
    abort();
}

template <class T>
class set
{
public:
private:
    T mass[7] = { 0,0,0,0,0,0,0};
    T* first;
    T* end;
public:

    set()
    {
        first = mass;
        end = mass;
    }
    
    void push(T val) {
        if (end == first)
        {
            *end++ = val;
            return;
        }
        if (end - first >= 7)
            throw "Set is full";
        insert(val);
    }
    T pop(int num){
        if (IsEmpty())
            throw "Set is empty";

        T memory = 0;
        bool check = 0;
        int i = 0;
        for (T* iter = first; iter <= end; iter++, i++)
        {
            if (i == num - 1)
            {
                check = true;
                memory = *iter;
            }

            if (check)
            {
               *iter = *(iter + 1);
            }
        }
        
        *end = 0;
        return memory;
    }

    bool IsEmpty()
    {
        return first == end;
    }

protected:
    void insert(T val)
    {
        T memory;
        bool check = 0;

        for (T* iter = first; iter <= end; iter++)
        {
            if (check)
            {
                T temp = memory;
                memory = *iter;
                *iter = temp;
                continue;
            }
            if (val == *iter)
            {
                return;
            }
            if (val < *iter)
            {
                memory = *iter;
                *iter = val;
                check = true;
            }
            

            if (iter == end && !check)
            {
                *iter = val;
            }
        }

        if (!check)
        {
            *end = val;
        }
        end++;
    }
};

int main()
{
    set_terminate(MyTerminate);
    set_unexpected(MyUnexpected);

    set<int> a;

    try
    {
        int z = 0;
        while (true)
        {
            cout << "a - pop(x)\nb - push(x)\nc - IsEmpty()\nd - exit" << endl;
            switch (getchar())
            {
            case 'a':
                int c;
                cin >> c;
                if (c > 8 || c < 0)
                {
                    throw("Going beyond the set");
                }
                a.pop(c);
                break;
            case 'b':
                int temp;
                cout << "Amount of numbers: ";
                cin >> temp;
                while (temp--)
                {
                    int b;
                    cin >> b;
                    a.push(b);
                }
                break;
            case 'c':
                if (a.IsEmpty())
                    cout << "is empty" << endl;
                else
                    cout << "not empty" << endl;
                break;
            case 'd':
                z = 1; break;
            case '\n':
                break;
            default:
                break;
            }
            if (z)
                break;
        }
    }
    catch (const char* msg)
    {
        if (!strcmp(msg, SET_EMTPY_EXCEPTION))
            cout << "EMPTY" << endl;
        else if (!strcmp(msg, SET_FULL_EXCEPTION))
            cout << "FULL" << endl;
        else if (!strcmp(msg, SET_BEYOND_LIMIT))
            cout << "BEYOUND THE LIMIT" << endl;
        else
            unexpected();
        return 0;
    }

	return 1;
}