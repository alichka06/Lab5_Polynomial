#include <bits/stdc++.h>
#include "lab24.h"

using namespace std;

Pol::Pol(): first(nullptr), last(nullptr), Nmax(0) {};
Pol::Pol(const Pol& a): first(nullptr), last(nullptr), Nmax(a.Nmax)
{
    LN * p=a.first;
    while(p!=nullptr)
    {
        add(p->k, p->deg);
        p=p->next;
    }
};
Pol::~Pol()
{
    set0();
};
Pol& Pol::operator = (const Pol& a)
{
    if (this==&a) return *this;
    set0();
    Nmax=a.Nmax;
    LN * p=a.first;
    while(p!=nullptr)
    {
        add(p->k, p->deg);
        p=p->next;
    }
    return *this;
};
bool Pol::input(istream& f)
{
    double d1, d2;
    if (&f==&cin) cout << "¬ведiть максимальну степiнь: ";
    f >> Nmax;
    if (&f==&cin) cout << "¬ведiть коефiцiент та степiнь монома: ";
    while (f >> d1 && f>>d2)
    {
        //f >> d2;
        if (d2>=0)
        {
            int m=add(d1,d2);
            if (m==0) return 0;
        }
        else
            if (&f==&cin) cout << "¬iд'мна степiнь монома:(\n";
        if (&f==&cin) cout << "¬ведiть коефiцiент та степiнь монома: ";
    }
    f.clear();
    f.sync();
    return 1;
};
void Pol::output(ostream& f)
{
    LN* p = first;
    if (&f!=&cout)
    {
        cout << "\nOutput\n";
        f << Nmax << "\n";
        while (p != nullptr)
        {
            f << p->k << " " << p->deg << "\n";
            p=p->next;
        }
    }
    else
    {
        bool t=0;
        if (first==nullptr) {cout << "0"; return ;}
        while (p!=nullptr)
        {

            if (p->k < 0 && p->k!=-1) {cout << p->k; t=1;}
            if (p->k==-1)
            {
                t=1;
                cout << "-";
                if (p->deg==0) cout << '1';
            }
            if (p->k > 0 && p->k!=1)
                if (t==0) {cout << p->k; t=1;} else cout << "+" << p->k;
            if (p->k==1)
            {
                if (t==0) t=1; else cout << '+';
                if (p->deg==0) cout << '1';
            }
            if (p->k!=0 && p->deg!=0)
            {
                if (p->k==1 || p->k==-1) cout << "x"; else cout << "*x";
                if (p->deg!=1) cout << "^" << p->deg;
            }
            p=p->next;
        }
        cout << "\n\n";
    }
};
bool Pol::add(const T& k_, const int& deg_)
{
    if (Nmax<deg_) Nmax=deg_;
    if (first == nullptr)
    {
        last=first=new(nothrow) LN;
        if (first==nullptr) return 0;
        first->k=k_;
        first->deg=deg_;
        first->next=nullptr;
        return 1;
    }
    if (first->deg == deg_) {first->k += k_; return 1;}
    if (first->deg < deg_)
    {
        LN* p=new(nothrow) LN;
        if (p == nullptr) return 0;
        p->k=k_;
        p->deg=deg_;
        p->next=first;
        first=p;
        return 1;
    }
    LN* p=first;
    while (p->next!=nullptr && p->next->deg > deg_)
        p=p->next;
    if (p->next!=nullptr && p->next->deg==deg_) {p->next->k+=k_; return 1;}
    LN* t=new(nothrow) LN; if (t==nullptr) return 0;
    t->k=k_; t->deg=deg_;
    if (p->next==nullptr) {t->next=nullptr; last=t;} else t->next=p->next;
    p->next=t;
    return 1;
};

void Pol::set0()
{
    Nmax=0;
    while(first!=nullptr)
    {
        LN* t=first;
        first=first->next;
        delete t;
    }
    last=nullptr;
};

Pol& Pol:: operator + (const Pol& a) const
{
    Pol* res=new Pol;
    res->Nmax=Nmax+a.Nmax;
    LN* p=first;
    while (p!=nullptr)
    {
        res->add(p->k, p->deg);
        p=p->next;
    }
    p=a.first;
    while (p!=nullptr)
    {
        res->add(p->k, p->deg);
        p=p->next;
    }
    while (res->del());
    return *res;
};

Pol& Pol:: operator * (const Pol& a) const
{
    Pol* res=new Pol;
    res->Nmax=Nmax*a.Nmax;
    LN* p=first;
    res->Nmax=Nmax+a.Nmax;
    while (p!=nullptr)
    {
        LN* temp=a.first;
        while (temp!=nullptr)
        {
            res->add((temp->k)*(p->k), (temp->deg)+(p->deg));
            temp=temp->next;
        }
        p=p->next;
    }
    return *res;
};

Pol& Pol:: operator / (const Pol& a) const
{
    Pol* res=new Pol;
    if (Nmax<a.Nmax) return *res;
    res->Nmax=Nmax-a.Nmax;
    Pol temp=(*this);
    while (temp.Nmax>=a.Nmax)
    {
        T k1=(temp.first->k)/(a.first->k);
        int deg1=(temp.first->deg)-(a.first->deg);
        res->add(k1, deg1);
        LN* p=a.first;
        while (p!=nullptr)
        {
            temp.add((p->k)*(-k1), (p->deg)+deg1);
            p=p->next;
        }
        while (temp.del());
    }
    return *res;
};

bool Pol:: del()
{
    if (first==nullptr) return 0;
    if (first->k==0)
    {
        LN* p=first;
        first=first->next;
        if (first==nullptr) {Nmax=0; last=nullptr;} else Nmax=first->deg;
        delete p;
        return 1;
    }
    LN * temp=first;
    while (temp->next!=nullptr && temp->next->k!=0)
        temp=temp->next;
    if (temp->next==nullptr) return 0;
    LN* d=temp->next;
    if (last==d) last=temp;
    temp->next=d->next;
    delete d;
    return 1;
}
