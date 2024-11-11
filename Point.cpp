//#include<iostream>
//#include<time.h>
//using namespace std;
//
//template<class T >
//class MyArray
//{
//    T* mas = nullptr;
//    int size;
//public:
//    MyArray();
//    void Output();
//    ~MyArray();
//    T operator[](int index);
//    int GetSize()const
//    {
//        return size;
//    }
//    T* GetPtr()const
//    {
//        return mas;
//    }
//    void SetSize(int s)
//    {
//        size = s;
//    }
//    void SetPtr(T* ptr)
//    {
//        mas = ptr;
//    }
//};
//template<class T>MyArray<T>::MyArray()
//{
//    size = 10;
//    mas = new T[10];
//    for (int i = 0; i < size; i++)
//    {
//        mas[i] = rand() % 100 * 1.2;
//    }
//}
//template<class T>void MyArray<T>::Output()
//{
//    for (int i = 0; i < size; i++)
//    {
//        cout << mas[i] << "\t";
//    }
//    cout << endl << endl;
//}
//template<class T>MyArray<T>::~MyArray()
//{
//    if (mas != nullptr)
//    {
//        delete[] mas;
//    }
//}
//template<class T>T MyArray<T>::operator[](int index)
//{
//    return mas[index];
//}
//
//void main()
//{
//    srand(time(0));
//    MyArray<int> obj1;
//    obj1.Output();
//
//    MyArray<char> obj2;
//    obj2.Output();
//
//    MyArray<double>obj3;
//    obj3.Output();
//
//
//
//
//    system("pause");
//}



//Реализовать собственный класс Point(с перегрузками), и использовать в шаблоне класса.
//
//class Point
//{
//  int x;
//  int y;
//public:
//};
//
//int main()
//{
//  MyArray<Point> obj1;
//}



#include <iostream>  
#include <time.h>  
using namespace std;

template<class T>
class MyArray {
    T* mas = nullptr;
    int size;
public:
    MyArray();
    void Output();
    ~MyArray();
    T operator[](int index);
    int GetSize() const {
        return size;
    }
    T* GetPtr() const {
        return mas;
    }
    void SetSize(int s) {
        size = s;
    }
    void SetPtr(T* ptr) {
        mas = ptr;
    }
};

template<class T> MyArray<T>::MyArray() {
    size = 10;
    mas = new T[10];
    for (int i = 0; i < size; i++) {
        mas[i] = T();  
    }
}

template<class T> void MyArray<T>::Output() {
    for (int i = 0; i < size; i++) {
        cout << mas[i] << "\t";
    }
    cout << endl << endl;
}

template<class T> MyArray<T>::~MyArray() {
    if (mas != nullptr) {
        delete[] mas;
    }
}

template<class T> T MyArray<T>::operator[](int index) {
    return mas[index];
}

class Point {
    int x;
    int y;
public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    friend ostream& operator<<(ostream& os, const Point& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }

    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }

    bool operator==(const Point& other) const {
        return (x == other.x) && (y == other.y);
    }
};

int main() 
{
    srand(static_cast<unsigned int>(time(0)));

    MyArray<int> obj1;
    obj1.Output();

    MyArray<char> obj2;
    obj2.Output();

    MyArray<double> obj3;
    obj3.Output();

    MyArray<Point> obj4;
    obj4.Output(); 

    for (int i = 0; i < obj4.GetSize(); ++i) {
        obj4[i] = Point(rand() % 100, rand() % 100);  
    }

    cout << "Points in obj4:" << endl;
    obj4.Output(); 

    system("pause");


}