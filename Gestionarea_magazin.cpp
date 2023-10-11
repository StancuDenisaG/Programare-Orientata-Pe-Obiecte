#include <iostream>
#include <string.h>
#include<vector>
#include<list>
#include<fstream>
using namespace std;
class Produs{
private:
	const int Cod_Produs;
	string Nume;
	string Descriere;
	float Pret;
	int Cantitate;
	bool In_Stoc;
	int Nr_Produse_In_Stoc;

public:
   float calculeazaReducere(){

        return Pret-(50*Pret)/100;

    }
    static int Contor;
    //CONSTRUCTORI:
    Produs();
    Produs(string Nume, float Pret);
    Produs(string Nume, string Descriere, float Pret, int Cantitate, bool In_Stoc, int Nr_Produse_In_Stoc);
  //  Produs(string Nume, string Descriere, float Pret, int Cantitate, bool In_Stoc, int Nr_Produse_In_Stoc);
    Produs(Produs& prod);

     //Operatorul =:
    Produs& operator=(const Produs& prod);



    //SETTERS:
    void setNume(string nume);
	void setDescriere(string descriere);
	void setCantitate(int cantitate);
	void setPret(float pret);
	void setIn_Stoc(bool in_stoc);
    void setNr_Produse_In_Stoc(int Nr_Produse_In_Stoc);

    //CITIRE, AFISARE
    friend ostream& operator<<(ostream& out, const Produs& pr);
    friend istream& operator>>(istream& in, Produs& pr);

    //GETTERS:
    const int getCod_Produs();
    string getNume();
    string getDescriere();
    int getCantitate();
    float getPret();
    bool getIn_Stoc();
    int getNr_Produse_In_Stoc();

    //Operator --
    const Produs& operator--();
    const Produs operator--(int);

    //Operator +:
    Produs operator+=(int x);
    //Operator -:
    Produs operator-=(int y);

    //DESTRUCTOR:
   ~Produs();
};
int Produs::Contor=100;

//Op --
const Produs& Produs::operator--()
{

    this->Nr_Produse_In_Stoc--;
    return *this;
}
//Op --
const Produs Produs::operator--(int)
{

    Produs aux(*this);
    this->Nr_Produse_In_Stoc--;

    return aux;

}
//Operator +:
Produs Produs::operator+=(int x)
{ this->Nr_Produse_In_Stoc+=x;
        return *this;


}
//Operator -:
Produs Produs::operator-=(int y){

        this->Nr_Produse_In_Stoc-=y;
        return *this;
    }

//CITIRE, AFISARE
istream& operator>>(istream& in,  Produs& pr){
    cout<<"\nNume produs: ";
    in>>pr.Nume;
    cout<<"\nDescriere: ";
    in>>pr.Descriere;
    cout<<"\nPret: ";
    in>>pr.Pret;
    cout<<"\nCantitate produs: ";
    in>>pr.Cantitate;
    cout<<"\nNr produse in stoc: ";
    in>>pr.Nr_Produse_In_Stoc;


    return in ;
}

ostream& operator<<(ostream& out, const Produs& pr)
{


    out<<"\nCod produs: "<<pr.Cod_Produs<<pr.Contor;
    out<<"\nNume produs: "<<pr.Nume;
    out<<"\nDescriere: "<<pr.Descriere;
    out<<"\nCantitate: "<<pr.Cantitate;
    out<<"\nPret: "<<pr.Pret;
    out<<"\nIn stoc: ";
    if(pr.Cantitate>0)
        out<<"Produsul este in stoc";
    else
        out<<"Produsul nu este in stoc";
    out<<"\nNumar de produse in stoc: "<<pr.Nr_Produse_In_Stoc;
    return out;

}


//SETTERS:
void Produs::setNume(string nume)
{
    Nume=nume;
    }

void Produs::setDescriere(string descriere)
{
    Descriere=descriere;
	}
void Produs::setCantitate(int cantitate){
	     Cantitate=cantitate;
	}
void Produs::setPret(float pret)
{
    Pret=pret;
	}

void Produs::setNr_Produse_In_Stoc(int nr_produse_in_stoc)
{
    Nr_Produse_In_Stoc=nr_produse_in_stoc;
    }


void Produs::setIn_Stoc(bool in_stoc){


        In_Stoc=in_stoc;

	}

//GETTERS:
const int Produs::getCod_Produs(){
   return Cod_Produs;
}
string Produs::getNume(){
   return Nume;
}
string Produs::getDescriere(){
    return Descriere;
}
int Produs::getCantitate(){
    return Cantitate;
}
float Produs::getPret(){
    return Pret;
}
bool Produs::getIn_Stoc(){
    return In_Stoc;}
int Produs::getNr_Produse_In_Stoc(){
    return Nr_Produse_In_Stoc;
}

//CONSTRUCTORI:

Produs::Produs(): Cod_Produs(Contor++){

  this->Nume="Produs";
  this->Descriere="Nu are descriere";
  this->Cantitate=0;
  this->Pret=0;
  this->In_Stoc=false;
  this->Nr_Produse_In_Stoc=0;


}

Produs::Produs( string Nume, string Descriere, float Pret, int Cantitate, bool In_Stoc, int Nr_Produse_In_Stoc):Cod_Produs(Contor++){
    this->Nume=Nume;
    this->Descriere=Descriere;
    this->Pret=Pret;
    this->Cantitate=Cantitate;
    this->In_Stoc=In_Stoc;
    this->Nr_Produse_In_Stoc=Nr_Produse_In_Stoc;
};
Produs::Produs(string Nume,float Pret): Cod_Produs(Contor++){
    this->Nume=Nume;
    this->Pret=Pret;
};
Produs::Produs(Produs& prod):Cod_Produs(prod.Cod_Produs){
    this->Nume=prod.Nume;
    this->Descriere=prod.Descriere;
    this->Pret=prod.Pret;
    this->Cantitate=prod.Cantitate;
    this->In_Stoc=prod.In_Stoc;
    this->Nr_Produse_In_Stoc=prod.Nr_Produse_In_Stoc;
};


//Operatorul =
Produs& Produs::operator=(const Produs& prod)
{
    if(this!=&prod)
	{   this->Nume=prod.Nume;
        this->Descriere=prod.Descriere;
        this->Pret=prod.Pret;
        this->Cantitate=prod.Cantitate;
        this->In_Stoc=prod.In_Stoc;
        this->Nr_Produse_In_Stoc=prod.Nr_Produse_In_Stoc;
	}
	return *this;}



//Destructor:
Produs::~Produs(){

}

//Clasa pt relatia IS A:
class Persoana{
private:
    int Varsta;
    string Adresa;

    //const int Cod_client;
public:
    //static int Contor_cod_client;
    //Constructori:
    Persoana();
    Persoana(int Varsta, string Adresa);
    Persoana(Persoana& per);
    //Setters:
    void setVarsta(int varsta);
    void setAdresa(string adresa);
    //Getters:
    int getVarsta();
    string getAdresa();
    //citire si afisare virtuala:
    virtual ostream& AfisareVirtuala(ostream& out)const;
    virtual istream& CitireVirtuala (istream& in);

    //Citire si afisare:
    friend ostream& operator<<(ostream& out, const Persoana& p);
    friend istream& operator>>(istream& in, Persoana& p);
      //Operatorul =:
    Persoana& operator=(const Persoana& per);
    //Destructor
    ~Persoana();
};
//Citire si afisare virtuala:
ostream& Persoana::AfisareVirtuala (ostream& out) const{

    out<<"\nVarsta: "<<Varsta;
    out<<"\nAdresa: "<<Adresa;
    return out;


}

istream& Persoana::CitireVirtuala(istream& in){

    cout<<"\nVarsta: ";
    in>>this->Varsta;
    cout<<"\nAdresa: ";
    in>>this->Adresa;
    return in;

}

istream& operator>>(istream & in,Persoana& pr)
{
    return pr.CitireVirtuala(in);
}
 ostream& operator<<(ostream & out,const Persoana& pr)
{
    return pr.AfisareVirtuala(out);
}




//Setters:
void Persoana::setVarsta(int varsta){
     Varsta=varsta;
}
void Persoana::setAdresa(string adresa){
     Adresa=adresa;
}
//Getters:
int Persoana:: getVarsta(){
       return Varsta;
    };
string Persoana:: getAdresa(){
       return Adresa;
}

//Op =
Persoana& Persoana::operator=(const Persoana& per)
{
    if(this!=&per){

        this->Varsta=per.Varsta;
        this->Adresa=per.Adresa;
    };}

//Constructori:
Persoana::Persoana(){
    this->Varsta=0;
    this->Adresa="Nu a fost introdusa";
}
Persoana::Persoana(int Varsta, string Adresa){
    this->Varsta=Varsta;
    this->Adresa=Adresa;
}
Persoana::Persoana(Persoana& per){
    this->Varsta=per.Varsta;
	this->Adresa=per.Adresa;

}
//Destructor:
Persoana::~Persoana(){

}




class Client: public Persoana{
private:
    const int Cod_client;
    char* Nume_client;
    string Prenume;
    char Sex;
    int Nr_produse;
    Produs* Produse;//HAS A- clasa produs
   // int* Bucati_produse;
    //float* Pret_produse;
    //float Total;
public:
    static int Contor_cod_client;

    //Constructori:
    Client();
    Client(int Varsta, string Adresa,char* Nume_client, string Prenume, char Sex);//:Persoana(Varsta, Adresa);
    Client(int Varsta, string Adresa, char* Nume_client, string Prenume, char Sex, int Nr_produse, Produs* Produse/*/int* Bucati_produse, float* Pret_produse/*/);//:Persoana(int Varsta, string Adresa);
    Client(Client& cl);//:Persoana(cl);

     //Operatorul =:
    Client& operator=(const Client& cl);


    //Setters:
    void setNume_client(char* nume_client);
    void setPrenume(string prenume);
    void setSex(char sex);
    void setNr_produse(int nr_produse);
    void setProduse(Produs* produse, int n );
    //void setBucati_produse(int* bucati_produse, int n );
   // void setPret_produse(float* pret_produse, int n);
    //void setTotal(float total);

      //CITIRE, AFISARE virtuala
    virtual ostream& AfisareVirtuala(ostream& out)const;
    virtual istream& CitireVirtuala (istream& in);

    //Getters:
    const int getCod_client();
    char* getNume_client();
    string getPrenume();
    char getSex();
    int getNr_produse();
    Produs* getProduse();
    //int* getBucati_produse();
    //float* getPret_produse();

    //Op indexare:
    int operator[](int index);


    friend float TOTAL(Client c);


    //Destructor:
    ~Client();


};
int Client::Contor_cod_client=0;

//CITIRE, AFISARE
 istream& Client::CitireVirtuala(istream& in){

    Persoana::CitireVirtuala(in);
    cout<<"\nNume : ";
    in>>Nume_client;
    cout<<"\nPrenume: ";
    in>>Prenume;
    cout<<"F/M: ";
    in>>Sex;
    cout<<"/nNr produse:";
    in>>Nr_produse;
    if(Produse!=NULL)
        delete[] Produse;
    Produse=new Produs[Nr_produse];
    cout<<"\nProduse: ";
    for(int i=0; i<Nr_produse; i++)
        in>>Produse[i];
   /*/ if(Bucati_produse!=NULL)
        delete[] Bucati_produse;
    Produse=new Produs[Nr_produse];
    cout<<"\nBucati produs: ";
    for(int i=0; i<Nr_produse; i++)
        in>>Bucati_produse[i];
    if(Pret_produse!=NULL)
        delete[] Pret_produse;
    Pret_produse=new float[Nr_produse];
    cout<<"\nPretul produselor: ";
    for(int i=0; i<Nr_produse; i++)
        in>>Pret_produse[i];/*/

    return in ;
}

ostream& Client::AfisareVirtuala(ostream& out) const{

    Persoana::AfisareVirtuala(out);

    out<<"\nCod Client: "<<Cod_client<<Contor_cod_client;
    out<<"\nNume client: "<<Nume_client;
    out<<"\nPrenume: "<<Prenume;
    out<<"\nF/M: "<<Sex;
    out<<"\nLista produse: "<<Produse;
  /*/  out<<"\nBucati produse: "<<Bucati_produse;
    out<<"\n Pret prooduse: "<<Pret_produse;/*/
    return out;

};

//Constructori:
Client::Client():Persoana(), Cod_client(Contor_cod_client++){
Nume_client=new char[strlen("Client")+1];
    strcpy( this->Nume_client,"Client");
this->Prenume=" ";
this->Sex='x';
this->Nr_produse=0;
/*/this->Pret_produse=NULL;
this->Bucati_produse=NULL;/*/
this->Produse=NULL;


};
Client::Client(int Varsta, string Adresa, char* Nume_client, string Prenume, char Sex):Persoana(Varsta, Adresa),Cod_client(Contor_cod_client++){
Nume_client=new char[strlen(Nume_client)+1];
    strcpy( this->Nume_client,Nume_client);
this->Prenume=Prenume;
this->Sex=Sex;
};

Client::Client(int Varsta, string Adresa, char* Nume_client, string Prenume, char Sex, int Nr_produse, Produs* Produse /*/int* Bucati_produse, float* Pret_produse/*/):Persoana(Varsta, Adresa), Cod_client(Contor_cod_client++){
Nume_client=new char[strlen(Nume_client)+1];
    strcpy( this->Nume_client,Nume_client);
this->Prenume=Prenume;
this->Sex=Sex;
this->Nr_produse=Nr_produse;
this->Produse=new Produs[Nr_produse];
    for(int i=0; i<Nr_produse; i++)
        this->Produse[i]=Produse[i];
/*/this->Bucati_produse=new int[Nr_produse];
    for (int i=0; i<Nr_produse; i++)
        this->Bucati_produse[i]=Bucati_produse[i];
this->Pret_produse=new float[Nr_produse];
    for (int i=0; i<Nr_produse; i++)
        this->Pret_produse[i]=Pret_produse[i];/*/

}

Client::Client(Client& cl):Persoana(cl), Cod_client(Contor_cod_client){
Nume_client=new char[strlen(cl.Nume_client)+1];
    strcpy( this->Nume_client,cl.Nume_client);
this->Prenume=cl.Prenume;
this->Sex=cl.Sex;
this->Nr_produse=cl.Nr_produse;
this->Produse=new Produs[Nr_produse];
    for(int i=0; i<Nr_produse; i++)
        this->Produse[i]=cl.Produse[i];
/*/this->Bucati_produse=new int[Nr_produse];
    for(int i=0; i<Nr_produse; i++)
        this->Bucati_produse[i]=cl.Bucati_produse[i];
this->Pret_produse=new float[Nr_produse];
    for (int i=0; i<Nr_produse; i++)
        this->Pret_produse[i]=cl.Pret_produse[i];/*/

}


//Operatorul =
Client& Client::operator=(const Client& cl)
{
    if(this!=&cl)
	{ Persoana::operator=(cl);
	    if (this->Nume_client!=NULL)
          delete[] Nume_client;
      if(this->Produse!=NULL)
          delete[] Produse;
     /*/ if (this->Bucati_produse!=NULL)
          delete[] Bucati_produse;
      if (this->Pret_produse!=NULL)
          delete[] Pret_produse;/*/

		Nume_client=new char[strlen(cl.Nume_client)+1];
        strcpy( this->Nume_client,cl.Nume_client);
        this->Prenume=cl.Prenume;
        this->Sex=cl.Sex;
        this->Nr_produse=cl.Nr_produse;
        this->Produse=new Produs[Nr_produse];
        for(int i=0; i<Nr_produse; i++)
           this->Produse[i]=cl.Produse[i];
      /*/  this->Pret_produse=new float[Nr_produse];
           for (int i=0; i<Nr_produse; i++)
               this->Pret_produse[i]=cl.Pret_produse[i];/*/

	}
	return *this;}

//Op []:
/*/int Client::operator[](int index)
{
    if (0<=index && index<this->Nr_produse)
        return Produse[index];
    else
        cout<<"Index gresit";
}/*/



//Setters:
void Client::setNume_client(char* nume_client){
    if(this->Nume_client!=NULL)
        delete[] this->Nume_client;
    this->Nume_client=new char[strlen(nume_client)+1];
    strcpy(this->Nume_client,nume_client);

}
void Client::setPrenume(string prenume){
     Prenume=prenume;
}
void Client::setSex(char sex){
     Sex=sex;
}
void Client::setNr_produse(int nr_produse){
     Nr_produse=nr_produse;
}
void Client::setProduse(Produs* produse, int n){
     this->Nr_produse=n;
     if (Produse!=NULL)
        delete[] Produse;
     Produse=new Produs [n];
     for(int i=0; i<n; i++)
        this->Produse[i]=produse[i];


}
/*/void Client::setBucati_produse(int* bucati_produse, int n){
     this->Nr_produse=n;
     if (Bucati_produse!=NULL)
        delete[] Bucati_produse;
     Bucati_produse=new int[n];
     for (int i=0; i<n; i++)
        this->Bucati_produse[i]=bucati_produse[i];}

void Client::setPret_produse(float* pret_produse, int n){
     this->Nr_produse=n;
     if (Pret_produse!=NULL)
        delete[] Pret_produse;
     Pret_produse=new float[n];
     for (int i=0; i<n; i++)
        this->Pret_produse[i]=pret_produse[i];/*/




//Getters:
   const int Client::getCod_client(){
     return Cod_client;}

    char* Client:: getNume_client(){
       return this->Nume_client;
    };
    string Client:: getPrenume(){
       return Prenume;
    };
    char Client:: getSex(){
       return Sex;
    };
    int Client::getNr_produse(){
       return Nr_produse;
    };
    Produs* Client::getProduse(){
      return this->Produse;
    };
    /*/int* Client::getBucati_produse(){
      return this->Bucati_produse;
    };
    float* Client::getPret_produse(){
      return this->Pret_produse;}/*/

  //TOTAL

 /*/ float TOTAL(Client c)
{

    float t=0;
    for(int i=0; i<c.Nr_produse; i++)
        t=t+p.Pret[i]*p.Cantitate[i];
    return t;

}/*/

//Destructor:
Client::~Client(){
if (this->Nume_client!=NULL)
    delete[] Nume_client;
if(this->Produse!=NULL)
    delete[] Produse;
/*/if (this->Bucati_produse!=NULL)
    delete[] Bucati_produse;
if (this->Pret_produse!=NULL)
    delete[] Pret_produse;/*/
}

//clasa pt extinderea IS A:
class Asociat{
private:
    bool Parteneriat;
    int Luni_parteneriat;

public:
    //Constructori:
    Asociat(){
    this->Parteneriat=false;
    this->Luni_parteneriat=0;
    };
    Asociat(bool Parteneriat, int Luni_parteneriat){
    this->Parteneriat=Parteneriat;
    this->Luni_parteneriat=Luni_parteneriat;
    };
    Asociat(const
            Asociat& as){
    this->Parteneriat=as.Parteneriat;
	this->Luni_parteneriat=as.Luni_parteneriat;
	};
    //Setters:
    void setParteneriat(bool parteneriat){
    Parteneriat=parteneriat;
    };
    void setLuni_parteneriat(int luni_parteneriat){
    Luni_parteneriat=luni_parteneriat;
    };
    //Getters:
    bool getParteneriat(){
    return Parteneriat;
    };
    int getLuni_parteneriat(){
    return Luni_parteneriat;
};
    //Citire si afisare:
    friend ostream& operator<<(ostream& out, const Asociat& a){
        out<<"\nParteneriat: "<<a.Parteneriat;
        out<<"\nLuni: "<<a.Luni_parteneriat;
    };
    friend istream& operator>>(istream& in, Asociat& a){

    cout<<"\nParteneriat: ";
    in>>a.Parteneriat;
    cout<<"/nLuni: ";
    in>>a.Luni_parteneriat;
    };
      //Operatorul =:
    Asociat& operator=(const Asociat& as){
        if(this!=&as){

        this->Parteneriat=as.Parteneriat;
        this->Luni_parteneriat=as.Luni_parteneriat;}
    };
    //Destructor
    ~Asociat(){
    };
};








 class Furnizor: public Asociat{
 private:
     const int Cod_furnizor;
     string Nume_furnizor;
     string Adresa;
 public:
    static int Contor_cod_furnizor;
    //Setters:
    void setNume_furnizor(string nume_furnizor);
    void setAdresa(string adresa);

    //Getters:
    string getNume_furnizor();
    string getAdresa();

    //Constructori
    Furnizor();
    Furnizor(bool Parteneriat,int Luni_parteneriat,  string Nume_furnizor);
    Furnizor(bool Parteneriat, int Luni_parteneriat, string Nume_furnizor, string Adresa);
    Furnizor(const Furnizor& fr);


    //Operatorul =:
    Furnizor& operator=(const Furnizor& fr);

    //Citire si afisare
    friend ostream& operator<<(ostream& out, const Furnizor& f);
    friend istream& operator>>(istream& in, Furnizor& f);


    //Op ==:
    bool operator==(const Furnizor& f);

    //Destructor:

    ~Furnizor();

};
int Furnizor::Contor_cod_furnizor=1000;
//Citire, afisare

istream& operator>>(istream& in, Furnizor& f)
{
    in>>(Asociat&)f;
    cout<<"\nNume: ";
    in>>f.Nume_furnizor;
    cout<<"\nAdresa: ";
    in>>f.Adresa;
    return in;
}

ostream& operator<<(ostream& out, const Furnizor& f)
{
    out<<(Asociat&)f;
    out<<"\nNume: "<<f.Nume_furnizor;
    out<<"\nAdresa: "<<f.Adresa;
    return out;
}


	//GETTERS
string Furnizor::getNume_furnizor()
{
	 return Nume_furnizor;
}

string Furnizor::getAdresa()
{
	return Adresa;
}

	//SETTERS
void Furnizor::setNume_furnizor(string nume_furnizor)
{
	Nume_furnizor=nume_furnizor;
}

void Furnizor::setAdresa(string adresa)
{
	Adresa=adresa;
}

//Constructori:

Furnizor::Furnizor():Asociat(), Cod_furnizor(Contor_cod_furnizor++)
{
	this->Nume_furnizor="Anonim";
	this->Adresa="Nu exista";
}

Furnizor::Furnizor(bool Parteneriat,int Luni_parteneriat,string Nume_furnizor):Asociat(Parteneriat, Luni_parteneriat), Cod_furnizor(Contor_cod_furnizor++)
{
	this->Nume_furnizor=Nume_furnizor;
}

Furnizor::Furnizor(bool Parteneriat, int Luni_parteneriat, string Nume_furnizor, string Adresa):Asociat(Parteneriat, Luni_parteneriat), Cod_furnizor(Contor_cod_furnizor++)
{
	this->Nume_furnizor=Nume_furnizor;
	this->Adresa=Adresa;
}

Furnizor::Furnizor(const Furnizor& fr):Asociat(fr), Cod_furnizor(fr.Cod_furnizor)
{
	this->Nume_furnizor=fr.Nume_furnizor;
	this->Adresa=fr.Adresa;
}
//Operatorul =
Furnizor& Furnizor::operator=(const Furnizor& fr)
{
    if(this!=&fr)
	{   Asociat::operator=(fr);
		this->Nume_furnizor=fr.Nume_furnizor;
		this->Adresa=fr.Adresa;
	}
	return *this;}


//Op ==:
bool Furnizor::operator==(const Furnizor& f)
{ if(this->Nume_furnizor==f.Nume_furnizor)
            return true;
        return false;



}

//Destructor:

Furnizor::~Furnizor()
{

}
//Clasa abstracta pura
class profit{
public:
    virtual double calculeazaProfit()=0;
};


class Factura: public profit{
private:
    string Serie;
    const int Nr_factura;
    string Prod;
    int Bucati;
    double Suma;

public:
    static int Contor_nrfactura;
    double calculeazaProfit(){
        cout<<"Profitul este: ";
        return this->Suma*5.5-this-> Suma;
    }
    //Getters:
    string getSerie();
    const int getNr_factura();
    string getProd();
    int getBucati();
    double getSuma();

    //Setters:
    void setSerie(string serie);
    void setProd(string prod);
    void setBucati(int bucati);
    void setSuma(double suma);

    //Constructori:
    Factura();
    Factura(string Serie, string Prod);
    Factura(string Serie, string Prod, int Bucati, double Suma );
    Factura(Factura& fc);

       //Operatorul =:
    Factura& operator=(const Factura& fc);

       //Operator ==:

    bool operator<=(const Factura& ft);


      //CITIRE, AFISARE
    friend ostream& operator<<(ostream& out, const Factura& ft);
    friend istream& operator>>(istream& in, Factura& ft);

  //op explicit:
    explicit operator int(){
       return (int) this->Suma;

    };

  //Destructor:
    ~Factura();

};

int Factura::Contor_nrfactura=111;

//Getters:
string Factura::getSerie(){
   return Serie;
};
const int Factura::getNr_factura(){
    return Nr_factura;
};
string Factura::getProd(){
     return this->Prod;
};
int Factura::getBucati(){
     return Bucati;
};
double Factura::getSuma(){
     return Suma;
};

//Setters:
void Factura::setSerie(string serie){
         Serie=serie;
    }

void Factura::setProd(string prod){
	     Prod=prod;
	}
void Factura::setBucati(int bucati){
	    Bucati=bucati;
	}
void Factura::setSuma(double suma){
	     Suma=suma;
	}

//CITIRE, AFISARE
istream& operator>>(istream& in,  Factura& ft){
    cout<<"\nSerie: ";
    in>>ft.Serie;
    cout<<"/nProdus: ";
    in>>ft.Prod;
    cout<<"Bucati produs: ";
    in>>ft.Bucati;
    cout<<"\nSuma: ";
    in>>ft.Suma;

    return in ;
}

ostream& operator<<(ostream& out, const Factura& ft)
{


    out<<"\nSerie: "<<ft.Serie<<ft.Contor_nrfactura;
    out<<"\nProdus: "<<ft.Prod;
    out<<"\nBucati: "<<ft.Bucati;
    out<<"\nSuma: "<<ft.Suma;

    return out;

}

//Constructori:

Factura::Factura():Nr_factura(Contor_nrfactura++)
{
	this->Serie="Nu exista";
	this->Prod="Produs";
	this->Bucati=0;
	this->Suma=0.00;
}

Factura::Factura(string Serie, string Prod):Nr_factura(Contor_nrfactura++)
{
    this->Serie=Serie;
    this->Prod=Prod;
}

Factura::Factura(string Serie, string Prod, int Bucati, double Suma):Nr_factura(Contor_nrfactura++)
{
    this->Serie=Serie;
    this->Prod=Prod;
    this->Bucati=Bucati;
    this->Suma=Suma;

}

Factura::Factura(Factura& fc):Nr_factura(fc.Contor_nrfactura){
    this->Serie=fc.Serie;
    this->Prod=fc.Prod;
    this->Bucati=fc.Bucati;
    this->Suma=fc.Suma;
};

//Operatorul =:

Factura& Factura::operator=(const Factura& fc)
{
    if(this!=&fc)
	{ this->Serie=fc.Serie;
    this->Prod=fc.Prod;
    this->Bucati=fc.Bucati;
    this->Suma=fc.Suma;
	}
	return *this;}

//Op <=

bool Factura::operator<=(const Factura& ft){
    if (this->Bucati<=ft.Bucati)
       return true;
    return false;
}


//Destructor:

Factura::~Factura()
{

}


int main(){
vector<Produs*> Reduceri;
Produs pr1("Nivea","Crema de maini", 7.5, 2, 1, 34 );
Produs pr2("Furter","Balsam hidratant pentru par" , 8.5, 2, 1, 20);
Produs pr3 ("Avene","Crema de fata",  11.4, 2, 1, 45);
Reduceri.push_back(&pr3);
Reduceri.push_back(&pr2);
Reduceri.push_back(&pr1);
/*/for(Produs*n : Reduceri)
        cout<<*n;/*/

list <Produs*> Reduceri2;

    Reduceri2.push_back(&pr3);
    Reduceri2.push_back(&pr2);
    Reduceri2.push_back(&pr1);

   /*/ list <Produs*>::iterator it;
    cout<<"\n Produsele se afla la 50% reducere!"<<"\n Noile preturi:";

    for(it=Reduceri2.begin(); it!=Reduceri2.end(); it++)
        cout<<"\n"<<(*it)->calculeazaReducere();/*/



Produs* listaProduse[100];
Furnizor* listaFurnizori[100];
int k=1;
int i = 0;
int j=0;
while(k==1){
    cout<<"\n 1 Introducere produs ";
    cout<<"\n 2 Introducere furnizor";
    cout<<"\n 3 Afisare produs";
    cout<<"\n 4 Iesire";
    cout<<"\n 5 Afisare furnizor";
    cout<<"\n 6 Client";
    cout<<"\n 7 Reduceri"<<endl;
    int comanda;
    cin>>comanda;
    switch(comanda){
        case 1:{
                listaProduse[i]=new Produs();
                cin>>*listaProduse[i];
                i++;
                break;

            //break;

            }
            case 2:{

                listaFurnizori[j]=new Furnizor();
                cin>>*listaFurnizori[j];
                j++;
                break;



            }
            case 3:{
                for(int m=0; m<i; m++)
                    cout<<*listaProduse[k]<<endl;
                break;





            }
            case 4:{

                k=0;
                break;

            }

            case 5:{
              for(int l=0; l<j; l++)
                    cout<<*listaFurnizori[l]<<endl;
                break;


            }

            case 6:{
                Client cl;
                cin>>cl;
                cout<<cl;
                break;
            }

            case 7:{
                for(Produs*n : Reduceri)
                    cout<<*n;
                list <Produs*>::iterator it;
                cout<<"\n Produsele se afla la 50% reducere!"<<"\n Noile preturi:";
                for(it=Reduceri2.begin(); it!=Reduceri2.end(); it++)
                    cout<<"\n"<<(*it)->calculeazaReducere();
                    break;



            }

}}




    return 0;
};
