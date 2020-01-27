//Miłosz Magiera


#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;

class Instrument{
    public:
        Instrument( const char* n ) : name{n} { } 
        // dopisz reszte
         virtual const char* graj() = 0;
         const char* graj()const {
            cout<<"Instrument jest virtualny"<<endl;
        }
        
        
        private:
        const string name;
};

// dopisz klasy Skrzypce i Fortepian, publicznie dziedziczące z Instrument

class Struna  {
    public:
    Struna(const double lenght) {
            len = lenght;
        };
        double dlugosc( double d = 0.0 ){         // zdefiniuj
            if (d == 0. ) {
                return d;
            }
            else {

            }
            }
        private:
            double len { 0. };
}; 



class  Skrzypce : public Instrument 
{
private:
   vector<Struna> struny;

public:
    Skrzypce(const char* n){}
    const char* graj(){
        cout<<"Grasz teraz na skrzypcach."<<endl;
    }
    void struna(Struna s){
        struny.push_back(s);
    }
    Struna* struna(size_t number){
        if(struny.size ()<= number+1 && number+1>0)
        return *struny[number];

    }
    size_t struny(){
        return struny.size();
    }
};

class Fortepian :public Instrument
{
private:
    size_t klawisze;
public:
    Fortepian(size_t numbert){
        klawisze=numbert;
    }
    size_t klawisze (){
        return klawisze;
    }
    void klawisze(size_t numbert){
        klawisze=numbert;

    }
    const char* graj(){
        cout<<"Teraz gra fortepian"<<endl;
    }
};



int main() {
   Instrument *p1 = new Skrzypce("Stradivari");
   Instrument *p2 = new Fortepian("Steinway");
   dynamic_cast<Fortepian*>(p2)->klawisze(88);
   cout << "Instrument " << p1->nazwa() << " gra " << p1->graj() << endl;
   cout << "Instrument " << p2->nazwa() << " gra " << p2->graj() << endl;
   Fortepian* pf = dynamic_cast<Fortepian*>(p2);
   cout << "Fortepian ma " << pf->klawisze() << " klawiszy" << endl;
   Skrzypce* ps = dynamic_cast<Skrzypce*>(p1);
   ps->struna(Struna(60.)); // dodaje strune
   ps->struna(Struna(62.)); // dodaje kolejna strune
   cout << "Skrzypce maja " << ps->struny() << " struny" << endl;
   cout << "Struna 1 ma dlugosc " << ps->struna(1)->dlugosc() << endl;
   ps->struna(1)->dlugosc(70.); // zmiana dlugosci
   cout << "Struna 1 ma teraz dlugosc " << ps->struna(1)->dlugosc() << endl;
   delete p1;
   delete p2;
};