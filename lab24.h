#ifndef LAB24_H_INCLUDED
#define LAB24_H_INCLUDED
using namespace std;
typedef double T;
class Pol
{
    private:
        struct LN
        {
            T k;
            int deg;
            LN* next;
        };
        LN * first, * last;
        int Nmax;
    public:
        Pol();
        Pol(const Pol& a);
        ~Pol();
        Pol& operator = (const Pol& a);
        bool input(istream& f);
        void output(ostream& f);
        bool add(const T& k_, const int& deg_);
        bool del();
        void set0();
        Pol& operator + (const Pol& a) const;
        Pol& operator * (const Pol& a) const;
        Pol& operator / (const Pol& a) const;

};

#endif // LAB24_H_INCLUDED
