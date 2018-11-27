#include <bits/stdc++.h>
#include "lab24.h"

using namespace std;

istream* choose_in();
ostream* choose_out();

int main()
{
    setlocale(LC_ALL,"Ukrainian");
    cout << "������ ��i��. ����������� ������ 2-4. �����i��i ������i ������\n";

    Pol a, b, c;
    istream *ps;
    ps=choose_in(); a.input(*ps);
    ps=choose_in(); b.input(*ps);

    cout << "\n��������� ���� ���i���i�";
    c=a+b;
    ostream *fo;
    fo=choose_out(); c.output(*fo);
    if (&cout!=&(*fo))
    {
        (*((ofstream*)fo)).close();
        delete fo;
    }

    cout << "\n�������� ���� ���i���i�";
    c=a*b;
    fo=choose_out(); c.output(*fo);
    if (&cout!=&(*fo))
    {
        (*((ofstream*)fo)).close();
        delete fo;
    }

    cout << "\n�i����� ���� ���i���i�";
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
    cout << "\n������� �������� �����:\n   1 � ������ ����� �� ��������� ����i�����\n   2 - �������� � �����\n";
    do{
        cout << "����i�� ���� i� �������������� ������i�: ";
        cin >> p;
        if (cin.fail()) {cin.clear(); cin.sync();}
    } while (p!=1 && p!=2);
    if (p==1) return &cin;
    string FN;
    ifstream *ps=new ifstream;
    do{
        cout << "����i�� ���� �� ��i����� �����: ";
        cin >> FN;
        (*ps).open(FN);
        if (!(*ps)) cout<<"���� �� ��������\n";
    } while (!(*ps));
    return ps;
}

ostream* choose_out()
{
    int p;
    cout << "\n������� ��������� ����������: \n   1 � ��������� �� �����\n   2 � ��������� � ���� \n";
    do{
        cout << "����i�� ���� i� �������������� ������i�: ";
        cin >> p;
        if (cin.fail()) {cin.clear(); cin.sync();}
    } while (p!=1 && p!=2);
    if (p==1) return &cout;
    string FN;
    ofstream *ps=new ofstream;
    cout << "����i�� ���� �� ���i����� �����: ";
    cin >> FN;
    (*ps).open(FN);
    return ps;
}
