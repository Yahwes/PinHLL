#include <iostream>

class scale
{
public:
    template<class T>
    int GetSize(T& VALUE) 
    { return sizeof(VALUE); }
};

class integer
{
public:
    integer();
    
    void operator = (const integer&);
    integer(int);
    integer(const integer&);
    integer(const integer&&);
    void operator() (integer&);
    integer& operator ++();
    integer operator ++(int);
    integer operator +(const integer );
    integer operator *(const integer);
    bool operator >(const integer&);
    bool operator >=(const integer&);
    bool operator !=(const integer&);
    friend integer& operator --(integer&);
    friend integer operator --(integer&, int);
    friend integer operator -(const integer&, const integer&);
    friend integer operator /(const integer&,const integer&);
    friend integer operator -(const integer& value1, int value2);
    friend integer operator/(const integer& value1, int value2);
    friend bool operator <(const integer&, const integer&);
    friend bool operator <(const integer&, int value2);
    friend bool operator <=(const integer&,const integer&);
    friend bool operator <=(const integer&, int value2);
    friend bool operator ==(const integer&,const integer&);
    friend bool operator ==(const integer&, int value2);
    friend std::ostream& operator<<(std::ostream& os, const integer& value);
    friend std::istream& operator>>(std::istream& is, integer& value);
    operator char();
    operator int();
    operator float();
    operator double();
private:
    int number;
};



integer::integer() { this->number = 0; }

//Перегрузка операторов-члена класса:
integer::integer(const integer& value) { this->number = value.number;}
integer::integer(const integer&& value) { this->number = value.number; }

void integer::operator = (const integer& other) { this->number = other.number; }
void integer::operator () (integer& value) { this->number = value.number; }
integer::integer(int a) { this->number = a; }
integer& integer::operator++() 
{ 
    this->number++;
    return *this;
}
integer integer::operator++(int value)
{
    integer temp(*this);
    this->number++;
    return temp;
}
integer& operator--(integer& value)
{
    value.number--;
    return value;
}
integer operator--(integer& other, int value)
{
    integer temp(other);
    other.number--;
    return temp;
}
integer integer::operator+(const integer value)
{
    integer temp;
    temp.number = this->number + value.number;
    return temp;
}
integer integer::operator*(const integer value)
{
    integer temp;
    temp.number = this->number * value.number;
    return temp;
}
bool integer::operator >(const integer& value) { return this->number > value.number; }
bool integer::operator >=(const integer& value) { return this->number >= value.number; }
bool integer::operator !=(const integer& other) { return this->number != other.number; }

//Перегрузка дружественых функций операторов
integer operator-(const integer& value1, const integer& value2)
{
    integer temp;
    temp.number = value1.number - value2.number;
    return temp;
}
integer operator/(const integer& value1, const integer& value2)
{
    integer temp;
    temp.number = value1.number / value2.number;
    return temp;
}
integer operator-(const integer& value1, int value2)
{
    integer temp;
    temp.number = value1.number - value2;
    return temp;
}
integer operator/(const integer& value1, int value2)
{
    integer temp;
    temp.number = value1.number / value2;
    return temp;
}
bool operator <(const integer& value1, const integer& value2) { return value1.number < value2.number; }
bool operator <=(const integer& value1, const integer& value2) { return value1.number <= value2.number; }
bool operator ==(const integer& value1, const integer& value2) { return value1.number == value2.number; }
bool operator <(const integer& value1, int value2) { return value1.number < value2; }
bool operator <=(const integer& value1, int value2) { return value1.number <= value2; }
bool operator ==(const integer& value1, int value2) { return value1.number == value2; }
std::ostream& operator<<(std::ostream& os, const integer& value) { os << value.number; return os; }
std::istream& operator>>(std::istream& is, integer& value) { is >> value.number; return is; }


//Функции преобразования
integer::operator char() { return char(this->number); }
integer::operator int() { return (this->number); }
integer::operator float() { return float(this->number); }
integer::operator double() { return double(this->number); }

int main()
{
    integer a, b, check;

    std::cout << "Enter a: ";
    std::cin >> a;
    std::cout << "Enter b: ";
    std::cin >> b;

    std::cout << "\n\n";
    std::cout << "Check before: " << check << std::endl;
    check = a;
    std::cout << "Check after 'check = a': " << check << std::endl;

    std::cout << "\n\n";
    std::cout << "Check before: " << check << std::endl;
    check(b);
    std::cout << "Check after 'check(b)': " << check << std::endl;

    std::cout << "\n\n";
    std::cout << "A before: " << a << std::endl;
    std::cout << "A after 'a++': " << a++ << std::endl;

    std::cout << "\n\n";
    std::cout << "A before: " << a << std::endl;
    std::cout << "A after '++a': " << ++a << std::endl;

    std::cout << "\n\n";
    std::cout << "Check before: " << check << std::endl;
    check = a + b;
    std::cout << "Check after 'check = a + b': " << check << std::endl;

    std::cout << "\n\n";
    std::cout << "Check before: " << check << std::endl;
    check = a * b;
    std::cout << "Check after 'check = a * b': " << check << std::endl;

    std::cout << "\n\n";
    std::cout << "After 'a > b': " << (a > b) << std::endl;

    std::cout << "\n\n";
    std::cout << "After 'a >= b': " << (a >= b) << std::endl;

    std::cout << "\n\n";
    std::cout << "After 'a != b': " << (a != b) << std::endl;
    
    std::cout << "\n\n";
    std::cout << "Check before: " << check << std::endl;
    std::cout << "Check after 'check--': " << check-- << std::endl;
    
    std::cout << "\n\n";
    std::cout << "Check before: " << check << std::endl;
    std::cout << "Check after '--check': " << --check << std::endl;

    std::cout << "\n\n";
    std::cout << "Check before: " << check << std::endl;
    check = a - b;
    std::cout << "Check after 'check = a - b': " << check << std::endl;

    std::cout << "\n\n";
    std::cout << "Check before: " << check << std::endl;
    check = a / b;
    std::cout << "Check after 'check = a / b': " << check << std::endl;

    int c;
    std::cout << "\nEnter integer number : ";
    std::cin >> c;

    std::cout << "\n";
    std::cout << "Check before: " << check << std::endl;
    check = a - c;
    std::cout << "Check after 'check = a - c': " << check << std::endl;

    std::cout << "\n\n";
    std::cout << "Check before: " << check << std::endl;
    check = b / c;
    std::cout << "Check after 'check = b / c': " << check << std::endl;
    
    std::cout << "\n\n";
    std::cout << "After 'a < b': " << (a < b) << std::endl;

    std::cout << "\n\n";
    std::cout << "After 'a <= b': " << (a <= b) << std::endl;

    std::cout << "\n\n";
    std::cout << "After 'a == b': " << (a == b) << std::endl;
    
    std::cout << "\n\n";
    std::cout << "After 'a < c': " << (a < c) << std::endl;

    std::cout << "\n\n";
    std::cout << "After 'b <= c': " << (b <= c) << std::endl;

    std::cout << "\n\n";
    std::cout << "After 'check == c': " << (check == c) << std::endl;
    
    std::cout << "\n\n";
    std::cout << "A before: " << a << std::endl;
    std::cout << "Result 'char(a)': " << char(a);

    std::cout << "\n\n";
    std::cout << "B before: " << b << std::endl;
    std::cout << "Result 'int(b)': " << int(b);
    
    std::cout << "\n\n";
    std::cout << "Check before: " << check << std::endl;
    std::cout << "Result 'float(check)': " << float(check);
    
    std::cout << "\n\n";
    std::cout << "A before: " << a << std::endl;
    std::cout << "Result 'double(a)': " << double(a) << std::endl << std::endl;

    scale d;
    std::cout << "After 'd.GetSize(check)': " << d.GetSize(check);
    return 1;
}