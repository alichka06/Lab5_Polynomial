#include <bits/stdc++.h>
#include "lab24.h"

using namespace std;

istream* choose_in();
ostream* choose_out();

int main()
{
    setlocale(LC_ALL,"Ukrainian");
    cout << "Федина Алiна. Лабораторна робота 2-4. Динамiчнi зв’язанi списки\n";

    Pol a, b, c;
    istream *ps;
    ps=choose_in(); a.input(*ps);
    ps=choose_in(); b.input(*ps);

    cout << "\nДодавання двох полiномiв";
    c=a+b;
    ostream *fo;
    fo=choose_out(); c.output(*fo);
    if (&cout!=&(*fo))
    {
        (*((ofstream*)fo)).close();
        delete fo;
    }

    cout << "\nМноження двох полiномiв";
    c=a*b;
    fo=choose_out(); c.output(*fo);
    if (&cout!=&(*fo))
    {
        (*((ofstream*)fo)).close();
        delete fo;
    }

    cout << "\nДiлення двох полiномiв";
    c=a/b;
    fo=choose_out(); c.output(*fo);
    if (&cout!=&(*fo))
    {
        (*((ofstream*)fo)).close();
        delete fo;
    }
    return 0;
}

istream* choose_in()
{
    int p;
    cout << "\nСпособи введення даних:\n   1 – ввести числа за допомогою клавiатури\n   2 - введення з файлу\n";
    do{
        cout << "Вкажiть один iз ЗАПРОПОНОВАНИХ способiв: ";
        cin >> p;
        if (cin.fail()) {cin.clear(); cin.sync();}
    } while (p!=1 && p!=2);
    if (p==1) return &cin;
    string FN;
    ifstream *ps=new ifstream;
    do{
        cout << "Введiть шлях до вхiдного файлу: ";
        cin >> FN;
        (*ps).open(FN);
        if (!(*ps)) cout<<"Файл не знайдено\n";
    } while (!(*ps));
    return ps;
}

ostream* choose_out()
{
    int p;
    cout << "\nСпособи виведення результату: \n   1 – виведення на екран\n   2 – виведення у файл \n";
    do{
        cout << "Вкажiть один iз ЗАПРОПОНОВАНИХ способiв: ";
        cin >> p;
        if (cin.fail()) {cin.clear(); cin.sync();}
    } while (p!=1 && p!=2);
    if (p==1) return &cout;
    string FN;
    ofstream *ps=new ofstream;
    cout << "Введiть шлях до вихiдного файлу: ";
    cin >> FN;
    (*ps).open(FN);
    return ps;
}
