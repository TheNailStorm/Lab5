#include <iostream>
#include <windows.h>
using namespace std;

//2 Варіант
//Дата(три числа) :
//   День, місяць, рік
//    Збільшити рік на 1
//    Зменшити дату на 2 дні
class Date {
private:
    int day; // Поле для зберігання дня
    int month; // Поле для зберігання місяця
    int year; // Поле для зберігання року

public:
    // Конструктор без параметрів
    Date() {
        day = 1;
        month = 1;
        year = 2000;
        cout << "Конструктор без параметрів класу Date викликаний для об'єкта " << this << endl;
    }

    // Конструктор з параметрами
    Date(int d, int m, int y) : day(d), month(m), year(y) {
        cout << "Конструктор з параметрами класу Date викликаний для об'єкта " << this << endl;
    }

    // Конструктор копіювання
    Date(const Date& other) : day(other.day), month(other.month), year(other.year) {
        cout << "Конструктор копіювання класу Date викликаний для об'єкта " << this << endl;
    }
    // Деструктор класу Date
    ~Date() {
        cout << "Деструктор класу Date викликаний для об'єкта " << this << endl;
    }
    // Метод для установки значення поля day
    void setDay(int d) {
        day = d;
    }
    // Метод для установки значення поля month
    void setMonth(int m) {
        month = m;
    }
    // Метод для установки значення поля year
    void setYear(int y) {
        year = y;
    }
    // Метод для отримання значення поля day
    int getDay() const {
        return day;
    }
    // Метод для отримання значення поля month
    int getMonth() const {
        return month;
    }
    // Метод для отримання значення поля year
    int getYear() const {
        return year;
    }
    // Метод для збільшення року на 1
    void increaseYearByOne() {
        year++;
    }
    // Метод для зменшення дати на 2 дні
    void decreaseDateByTwoDays() {
        day -= 2;
        if (day < 1) {
            month--;
            if (month < 1) {
                month = 12;
                year--;
            }
            switch (month) {
            case 2:
                if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                    day += 29; // Високосний рік
                }
                else {
                    day += 28; // Невисокосний рік
                }
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                day += 30; // Місяці з 30 днями
                break;
            default:
                day += 31; // Місяці з 31 днем
                break;
            }
        }
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Date date1; // Виклик конструктора без параметрів
    Date date2(1, 1, 2022); // Виклик конструктора з параметрами
    Date date3(date2); // Виклик конструктора копіювання
}