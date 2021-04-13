//Створити базовий клас ПЕРЕВЕЗЕННЯ АВТОМОБІЛЕМ(задаються номер автомобіля, дані про водія).
//Створити похідний клас ВАНТАЖНЕ ПЕРЕВЕЗЕННЯ(задаються кількість тон, вартість перевезення 1 тони на 1 кілометр).
//Для введених даних про замовлені перевезення визначити сумарний дохід, 
//який приніс кожен водій і відсортувати їх за зростанням.

#include <iostream>
#include <string>

#define M 5

using namespace std;

class BaseTransportCar
{
private:
    string numcar;
    string firstnamedriver;
    string secondnamedriver;

public:

    BaseTransportCar() // конструктор без параметрів
    {
        numcar = "--0000--";
        firstnamedriver = "None";
        secondnamedriver = "None";
    }

    BaseTransportCar(string nc, string fstname, string secname) // конструктор з параметрами
    {
        this->numcar = nc;
        this->firstnamedriver = fstname;
        this->secondnamedriver = secname;
    }

    ~BaseTransportCar() { } // деструктор

    void SetNumcar() 
    {
        cin >> numcar;
    }

    string GetNumcar() 
    {
        return numcar;
    }

    void SetFstname() 
    {
        cin >> firstnamedriver;
    }

    string GetFstname() 
    {
        return firstnamedriver;
    }

    void SetSecname() 
    {
        cin >> secondnamedriver;
    }

    string GetSecname() 
    {
        return secondnamedriver;
    }

    void SetBaseInform()
    {
        SetNumcar();
        SetFstname();
        SetSecname();
    }

    void PrintBaseInform()
    {
        cout << GetNumcar() << "\t";
        cout << GetFstname() << ' ';
        cout << GetSecname() << "\t\t";
    }

};


class WeightTransport : public BaseTransportCar
{
private:
    int kstton;
    int kstdistance;
    int kstprice;
    int income;

public:

    WeightTransport() : BaseTransportCar()   // конструктор без параметрів
    {
        kstton = 0;
        kstdistance = 0;
        kstprice = 0;
        income = 1;
    }

    WeightTransport(string nc, string fstname, string secname, int kton, int kdistance, int kprice, int inc) : BaseTransportCar(nc, fstname, secname) // конструктор з параметрами
    {
        kstton = kton;
        kstdistance = kdistance;
        kstprice = kprice;
        income = inc;
    }

    ~WeightTransport() { } // деструктор

    void Setkstton(int kton) 
    {
        kstton = kton;
    }

    int Getkstton() 
    {
        return kstton;
    }

    void Setkstdistance(int kdista) 
    {
        kstdistance = kdista;
    }

    int Getkstdistance() 
    {
        return kstdistance;
    }

    void SetPrice(int pce) 
    {
        kstprice = pce;
    }

    int GetPrice() 
    {
        return kstprice;
    }

    void SetIncome(int inc) 
    {
        income = inc;
    }

    int GetIncome() 
    {
        return income;
    }

    void SetAllInform(WeightTransport* Inform)
    {
        for (int i = 0; i < M; i++)
        {
            cout << i + 1 << ": ";
            Inform[i].SetBaseInform();
            cin >> Inform + i;
            cout << "\n";
        }
    }

    void PrintAllInform(WeightTransport* Inform)
    {
        cout << "Номер машини:\t" << "Дані про водія: \t" << "К-сть тонн:\t" << "Відстань:\t" << "Ціна:\t" << "\tДохід:" << endl;
        for (int i = 0; i < M; i++)
        {
            if (Inform[i].GetIncome() != 0)
            {
                Inform[i].PrintBaseInform();
                cout << Inform + i << endl;
            }
        }
    }

    void Income(WeightTransport* Inform)
    {
        for (int i = 0; i < M; i++)
        {
            if (Inform[i].income != 0)
            {
                Inform[i].income = Inform[i].kstton * Inform[i].kstdistance * Inform[i].kstprice;
            }
            else {
                while (Inform[i].income == 0)
                {
                    i += 1;
                }
                Inform[i].income = Inform[i].kstton * Inform[i].kstdistance * Inform[i].kstprice;
            }

            for (int j = i + 1; j < M; j++)
            {

                if (Inform[i].GetFstname() == Inform[j].GetFstname() && Inform[i].GetSecname() == Inform[j].GetSecname())
                {
                    Inform[i].income += Inform[j].kstton * Inform[j].kstdistance * Inform[j].kstprice;
                    Inform[i].kstton += Inform[j].kstton;
                    Inform[i].kstdistance += Inform[j].kstdistance;
                    Inform[i].kstprice = 0;
                    Inform[j].income = 0;
                }
            }
        }
    }

    void Sort(WeightTransport* Inform) //сортування обміном
    {
        WeightTransport temp;
        int i, j;
        for (i = 1; i < M; i++) //цикл кроків сортування
        {
            for (j = 0; j < M - i; j++)      // цикл порівняння і перестановки елементів
   {
    if (Inform[j].income > Inform[j + 1].income)
    {
     temp = Inform[j];          // temp - змінна для перестановки елементів
     Inform[j] = Inform[j + 1];
     Inform[j + 1] = temp;
    }
   }

  }

 }


 friend istream& operator >>(istream& in, WeightTransport* WeightTransport);
 friend ostream& operator <<(ostream& out, const WeightTransport* WeightTransport);

};

istream& operator >>(istream& in, WeightTransport* WeightTransport)
{

 in >> WeightTransport->kstton;
 in >> WeightTransport->kstdistance;
 in >> WeightTransport->kstprice;

 return in;
}

ostream& operator<< (ostream& out, const WeightTransport* WeightTransport)
{
 out << WeightTransport->kstton << " тонн\t\t" << WeightTransport->kstdistance << " km\t\t" << WeightTransport->kstprice << " $/1 km\t" << WeightTransport->income << endl;
 return out;
}


int main()
{
 system("chcp 1251");
 WeightTransport Inform[M];
 cout << "Початкові значення:\n";
 Inform[0].PrintAllInform(Inform);
 cout << "Введіть інші дані:\n";
 cout << "Введіть дані по номеру машини і по даним водія(ім'я та фамілія),\n"
  "а також по кількості тонн, по відстані(в км) та по ціні перевезення за 1 км(в доларах): \n";
 Inform[0].SetAllInform(Inform); 
 cout << endl;
 Inform[0].Income(Inform);
 cout << "Змінені вами дані:\n";
 Inform[0].PrintAllInform(Inform);
 cout << "Сортування..." << endl;
 Inform[0].Sort(Inform);
 Inform[0].PrintAllInform(Inform);


 system("pause");
 return 0;
}