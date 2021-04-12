#include <iostream>
#include <stdlib.h> //biblioteca folosita pentru a genera numere random
#include <string> 

using namespace std;


class Contract
{

private:
    string nrContract;
    int anul;
    string beneficiar;
    string furnizor;
    double valoare;
public:
    //Constructor fara parametrii
    Contract()
    {
       // cout<<endl<<"Constructor din clasa contract";
    }

    void setnrContract(string nrc)
    {
        this->nrContract = nrc;
    }

    void setAnul(int an)
    {
        this->anul = an;
    }

    void setBeneficiar(string b)
    {
        this->beneficiar = b;
    }

    void setFurnizor(string f)
    {
        this->furnizor = f;
    }

    void setValoare(double v)
    {
        this->valoare = v;
    }

    double getValoare()
    {
        return this->valoare;
    }

    string getnrContract()
    {
        return this->nrContract;
    }

    int getAnul()
    {
        return this->anul;
    }

    string getBeneficiar()
    {
        return this->beneficiar;
    }

    string getFurnizor()
    {
        return this->furnizor;
    }

    virtual void afis()
    {
        cout<<"Acesta este un contract simplu";
    }
    
    ~Contract()
    {
        cout<<endl<<endl<<"Contract distrus";
    }
};

class ContractInchiriere : public Contract
{
private:
    int nrLuni;
public:
    //constructor fara parametrii
    ContractInchiriere()
    {
        //cout<<"Constructor fara parametrii";
    }
    //constructor cu parametrii
    ContractInchiriere(string nrC, int an, string b, string f, double v, int nL)
    {
        this->setnrContract(nrC);
        this->setAnul(an);
        this->setBeneficiar(b);
        this->setFurnizor(f);
        this->setValoare(v);
        this->nrLuni = nL;
    }

    int getNrLuni()
    {
        return this->nrLuni;
    }
    //metoda care returneaza valaorea unui contract
    double getValoareContract()
    {
        return (this->nrLuni * this->getValoare());
    }

   virtual  void afis()
    {
        cout<<endl<<"Acesta este un contract de inchiriere";
    }
    ~ContractInchiriere()
    {
        cout<<endl<<endl<<"ContractInchiriere distrus";
    }
};


class Dosar
{
public:
    int nrContracteInchiriere = 10;
    ContractInchiriere *vectorContracte[10]; //vector de pointeri care contracte

    //constructorul clasei dosar
    Dosar()
    {
        generazaContracteInchiriere(); //se apeleaza metoda de generare random a contractelor
    }
    ~Dosar(){// destructor
        cout<<endl<<endl<<"Apel destructor din clasa dosar.";
    }
    void generazaContracteInchiriere()
    {
        cout << "Generez contractele..."<<endl;
        for(int i = 0; i < this->nrContracteInchiriere; i++)
        {
            double valoareRandom = rand()%100 + i; //generez random o valoare pentru contract
            int durataRandom = rand() % 24; //generez random o durata pentru contract
            //construiesc vectorul de contracte
            vectorContracte[i] = new ContractInchiriere("nr"+std::to_string(i), 2020+i, "beneficiar"+std::to_string(i), "furnizor"+std::to_string(i), valoareRandom, durataRandom);;
        }
    }
    //metoda care afiseaza contractele din dosar
    void afiseazaContractele()
    {
        for(int i = 0; i < this->nrContracteInchiriere; i++)
        {
            cout<< "Contract Nr.: " << vectorContracte[i]->getnrContract() << ", Anul: " <<  vectorContracte[i]->getAnul()<<
                ", Beneficiar: " << vectorContracte[i]->getBeneficiar() <<
                ", Furnizor: " <<vectorContracte[i]->getFurnizor() <<
                ", Val produs: " <<  vectorContracte[i]->getValoare()<<
                ", Nr. luni: " << vectorContracte[i]->getNrLuni()<< endl;
        }
    }

    //metoda care itereaza prin contracte si afiseaza valoarea fiecaruia
    void afiseazaValoareperContract()
    {
        cout<<endl<< "~~~ Valoarea fiecarui contract ~~~~"<<endl;
        for(int i = 0; i < this->nrContracteInchiriere; i++)
        {
            cout<< "Contract Nr.: " << vectorContracte[i]->getnrContract() << " valoare: "<< vectorContracte[i]->getValoareContract() << endl;
        }
    }

    //metoda care calculeaza valoarea totala a contractelor din dosar
    void calculeazaValoareTotalaContracte()
    {
        double total = 0;
        for(int i = 0; i < this->nrContracteInchiriere; i++)
        {
            total += vectorContracte[i]->getValoareContract();
        }
        cout<< endl<< "Valoarea totala a dosarului este: " << total<<endl<<endl;
    }

    static void metodaStatica(){
        cout<<"Apelul unei metode statice";
    }
};


int main()
{
    Dosar dosar;
    dosar.afiseazaContractele();
    dosar.afiseazaValoareperContract();
    dosar.calculeazaValoareTotalaContracte();
    Dosar::metodaStatica();

    //Upcasting
    Contract *c;
    ContractInchiriere ci;
    c = &ci;
    c->afis();

    //Downcasting
    cout<<endl;
    Contract ct;
    ContractInchiriere* c1 = (ContractInchiriere*)&ct;
    c1->afis();

    return 0;
}
