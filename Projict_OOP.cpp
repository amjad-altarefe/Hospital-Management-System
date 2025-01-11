

#include <iostream>

using namespace std;

struct names
{
    string first;
    string middle;
    string last;
};
struct dateofbirth
{
    int day;
    int month;
    int year;
};
class person
{
    public:
   names name;
   dateofbirth date;
};
// Base class.
class Hospital
{
    private:
        //Composition:
        person info;
        int age;
    public:
        //default Constructor.
        Hospital();
        // parameters Constructor.
        Hospital(string n1, string n2 , string n3 , int g);
        //Destructors.
        ~Hospital(){}
        string fullName();
        void printFullName();
        void printAge();
        void print();
        void setFullName();
        void setAge();
        void set();
        
};
// First derived class.
class Doctor : public Hospital
{
    private:
        int salary;
        string specialty;
        static int counter_D;
    public:
        //default Constructor.
        Doctor();
        // parameters Constructor.
        Doctor (string n1, string n2 , string n3 , int g , int s , string sp);
        //Destructors.
        ~Doctor(){
            counter_D--;
        }
        void printSalary();
        void printSpecialty();
        void print();
        void setSalary();
        void setSpecialty();
        void set();
        int C_D ();
        friend int TSD(Doctor ob[] , int d );
        // operator function to give a raise.
        int operator+(int m);
};
// Second derived class.
class Nurse : public Hospital
{
    private:
        int salary;
        int experience;
        static int counter_N;
    public:
        //default Constructor.
        Nurse();
        // parameters Constructor.
        Nurse(string n1, string n2 , string n3 , int g , int s , int e);
        //Destructors.
        ~Nurse(){
            counter_N--;
        }
        void printSalary();
        void printExperience();
        void print();
        void setSalary();
        void setExperience();
        void set();
        int C_N ();
        friend int TSN(Nurse ob[] , int n );
        // operator function to give a raise.
        int operator+(int m);
};
// Third derived class.
class Patient : public Hospital
{
    private:
        string disease;
        static int counter_P;
    public:
        //default Constructor.
        Patient();
        // parameters Constructor.
        Patient(string n1, string n2 , string n3 , int g , string d);
        //Destructors.
        ~Patient(){
            counter_P--;
        }
        void printDisease();
        void print();
        void setDisease();
        void set();
        int C_P ();

};
//Static Members to store the number of people.
int Doctor::counter_D = 0;
int Nurse::counter_N = 0;
int Patient::counter_P = 0;
//friend function To calculate the total salaries of doctors.
int TSD(Doctor ob[] , int d );
//friend function To calculate the total salaries of Nurses.
int TSN(Nurse ob[] , int n );
// function To print the total salaries of doctors.
void printTSD(Doctor ob[] , int d);
// function To print the total salaries of Nurses.
void printTSN(Nurse ob[] , int n);

int main()
{
    int x1 , x2 , x3 , x4 , x5 , x6 , y1 , y2  , y3 , s;
    bool a1 = true;
    //Main Menu.
    do{
        try
        {
            cout << "-----------------------------------------------------------\n";
            cout << "\t\t Choose the option you want \n";
            cout << "-----------------------------------------------------------\n";
            cout << "1- Doctor.\n";
            cout << "2- Nurse.\n";
            cout << "3- Patient.\n";
            cout << "To exit, enter 0.\n\n";
            cout << "Enter your choice: ";
            cin >> x1;
            switch (x1)
            {
                case 0 :
                case 1 :
                case 2 :
                case 3 :
                break;
                default:
                throw x1;
            }
        }
            catch (int)
            {
                cout << "This number does not exist. " << endl;
            }
            catch (...)
            {
                cout << "You entered wrong. " << endl;
               
            }
        system("cls");
        switch (x1)
        {
            case 1 :
            {
                cout << "-----------------------------------------------------------\n";
                cout << "\t\t\t Doctor \n";
                cout << "-----------------------------------------------------------\n";
                int d ;
                cout << "Enter the number of doctors: ";
                cin >> d;
                Doctor doc[d] ;
                system("cls");
                bool b1 = true;
                do{
                    cout << "1- View doctors information.\n";
                    cout << "2- Edit the information.\n\n";
                    cout << "To exit, enter 0.\n\n";
                    cout << "Enter your choice: ";
                    cin >> x2;
                    system("cls");
                    switch (x2)
                    {
                        case 1 :
                        {
                            cout << "-----------------------------------------------------------\n";
                            cout << "Enter the doctor's number: ";
                            cin >> s ;
                            s--;
                            cout << "-----------------------------------------------------------\n";
                            bool b2 = true;
                            do{
                                cout << "1- Print Name.\n";
                                cout << "2- Print Age.\n";
                                cout << "3- Print Salary.\n";
                                cout << "4- Print Total salary.\n";
                                cout << "5- Print Specialty.\n";
                                cout << "6- Print all information.\n\n";
                                cout << "To exit, enter 0.\n\n";
                                cout << "Enter your choice: ";
                                cin >> x3;
                                system("cls");
                                switch (x3)
                                {
                                    case 1 :
                                    {
                                        cout << "-----------------------------------------------------------\n";
                                        doc[s].printFullName();
                                        cout << "-----------------------------------------------------------\n";
                                        break;
                                    }
                                    case 2 :
                                    {
                                        cout << "-----------------------------------------------------------\n";
                                        doc[s].printAge();
                                        cout << "-----------------------------------------------------------\n";
                                        break;
                                    }
                                    case 3 :
                                    {
                                        cout << "-----------------------------------------------------------\n";
                                        doc[s].printSalary();
                                        cout << "-----------------------------------------------------------\n";
                                        break;
                                    }
                                    case 4 :
                                    {
                                        cout << "-----------------------------------------------------------\n";
                                        printTSD(doc , d);
                                        cout << "-----------------------------------------------------------\n";
                                        break;
                                    }
                                    case 5 :
                                    {
                                        cout << "-----------------------------------------------------------\n";
                                        doc[s].printSpecialty();
                                        cout << "-----------------------------------------------------------\n";
                                        break;
                                    }
                                    case 6 :
                                    {
                                        cout << "-----------------------------------------------------------\n";
                                        doc[s].print();
                                        cout << "-----------------------------------------------------------\n";
                                        break;
                                    }
                                    case 0 :
                                    {
                                        b2 = false;
                                        break;
                                    }
                                }
                            }while(b2);    
                        }
                        break;
                        case 2 :
                        {
                            bool b5 = true;
                            do{
                                cout << "-----------------------------------------------------------\n";
                                cout << "\t\t Number of doctors : " << doc[0].C_D() << endl;
                                cout << "-----------------------------------------------------------\n";
                                cout << "1- Add a new doctor.\n";
                                cout << "2- Editing the information of a specific doctor.\n\n";
                                cout << "To exit, enter 0.\n\n";
                                cout << "Enter your choice: ";
                                cin >> y1;
                                system("cls");
                                switch(y1)
                                {
                                    case 1 :
                                    {
                                        d++;
                                        Doctor doc[d-1];
                                        
                                    }
                                    break;
                                    case 2 : 
                                    {
                                        cout << "-----------------------------------------------------------\n";
                                        cout << "Enter the doctor's number: ";
                                        cin >> s ;
                                        s--;
                                        cout << "-----------------------------------------------------------\n";
                                        bool b2 = true;
                                        do{
                                            cout << "1- Name editing.\n";
                                            cout << "2- Age editing.\n";
                                            cout << "3- Give a raise.\n";
                                            cout << "4- Specialty editing.\n";
                                            cout << "5- Editing all information.\n\n";
                                            cout << "To exit, enter 0.\n\n";
                                            cout << "Enter your choice: ";
                                            cin >> x3;
                                            system("cls");
                                            switch (x3)
                                            {
                                                case 1 :
                                                {
                                                    cout << "-----------------------------------------------------------\n";
                                                    doc[s].setFullName();
                                                    cout << "-----------------------------------------------------------\n";
                                                    system("cls");
                                                    break;
                                                }
                                                case 2 :
                                                {
                                                    cout << "-----------------------------------------------------------\n";
                                                    doc[s].setAge();
                                                    cout << "-----------------------------------------------------------\n";
                                                    system("cls");
                                                    break;
                                                }
                                                case 3 :
                                                {
                                                    cout << "-----------------------------------------------------------\n";
                                                    cout<<"Enter raise amount: ";
                                                    int salar1;
                                                    cin>>salar1;
                                                    doc[s]+salar1;
                                                    cout << "-----------------------------------------------------------\n";
                                                    system("cls");
                                                    break;
                                                }
                                                case 4 :
                                                {
                                                    cout << "-----------------------------------------------------------\n";
                                                    doc[s].setSpecialty();
                                                    cout << "-----------------------------------------------------------\n";
                                                    system("cls");
                                                    break;
                                                }
                                                case 5 :
                                                {
                                                    cout << "-----------------------------------------------------------\n";
                                                    doc[s].set();
                                                    cout << "-----------------------------------------------------------\n";
                                                    system("cls");
                                                    break;
                                                }
                                                case 0 :
                                                {
                                                    b2 = false;
                                                    break;
                                                }
                                            }
                                        }while(b2);    
                                    }
                                        break;
                                    case 0 :
                                    b5 = false;
                                    break;
                                }
                            }while(b5);
                        }
                        break;
                        case 0 :
                        b1 = false;
                        break;
                    }
                }while(b1);
            }
            break;
            case 2 :
            {
                    cout << "-----------------------------------------------------------\n";
                    cout << "\t\t\t Nurse \n";
                    cout << "-----------------------------------------------------------\n";
                    int n;
                    cout << "Enter the number of Nurses: ";
                    cin >> n;
                    Nurse nur[n];
                    system("cls");
                    bool b3 = true;
                    do{
                        cout << "1- View nurse's information.\n";
                        cout << "2- Edit the information.\n\n";
                        cout << "To exit, enter 0.\n\n";
                        cout << "Enter your choice: ";
                        cin >> x3;
                    system("cls");
                    switch (x3)
                    {
                        case 1 :
                        {
                            cout << "-----------------------------------------------------------\n";
                            cout << "Enter the Nurse's number: ";
                            cin >> s ;
                            s--;
                            cout << "-----------------------------------------------------------\n";
                            bool b4 = true;
                            do{
                                cout << "1- Print Name.\n";
                                cout << "2- Print Age.\n";
                                cout << "3- Print Salary.\n";
                                cout << "4- Print total Salary.\n";
                                cout << "5- Print experience.\n";
                                cout << "6- Print all information.\n\n";
                                cout << "To exit, enter 0.\n\n";
                                cout << "Enter your choice: ";
                                cin >> x3;
                                system("cls");
                                switch (x3)
                                {
                                    case 1 :
                                    {
                                        cout << "-----------------------------------------------------------\n";
                                        nur[s].printFullName();
                                        cout << "-----------------------------------------------------------\n";
                                        break;
                                    }
                                    case 2 :
                                    {
                                        cout << "-----------------------------------------------------------\n";
                                        nur[s].printAge();
                                        cout << "-----------------------------------------------------------\n";
                                        break;
                                    }
                                    case 3 :
                                    {
                                        cout << "-----------------------------------------------------------\n";
                                        nur[s].printSalary();
                                        cout << "-----------------------------------------------------------\n";
                                        break;
                                    }
                                    case 4 :
                                    {
                                        cout << "-----------------------------------------------------------\n";
                                        printTSN(nur , n);
                                        cout << "-----------------------------------------------------------\n";
                                        break;
                                    }
                                    case 5 :
                                    {
                                        cout << "-----------------------------------------------------------\n";
                                        nur[s].printExperience();
                                        cout << "-----------------------------------------------------------\n";
                                        break;
                                    }
                                    case 6 :
                                    {
                                        cout << "-----------------------------------------------------------\n";
                                        nur[s].print();
                                        cout << "-----------------------------------------------------------\n";
                                        break;
                                    }
                                    case 0 :
                                    {
                                        b4 = false;
                                        break;
                                    }
                                }
                            }while(b4);    
                        }
                        break;
                        case 2 :
                        {
                            bool b6 = true;
                            do{
                                cout << "-----------------------------------------------------------\n";
                                cout << "\t\t Number of nurses : " << nur[0].C_N() << endl;
                                cout << "-----------------------------------------------------------\n";
                                cout << "1- Add a new nurse.\n";
                                cout << "2- Editing the information of a specific nurse.\n\n";
                                cout << "To exit, enter 0.\n\n";
                                cout << "Enter your choice: ";
                                cin >> y2;
                                system("cls");
                                switch(y2)
                                {
                                    case 1 :
                                    {
                                        n++;
                                        Nurse nur[n-1];
                                    }
                                    break;
                                    case 2 : 
                                    {
                                        cout << "-----------------------------------------------------------\n";
                                        cout << "Enter the nurse's number: ";
                                        cin >> s ;
                                        s--;
                                        cout << "-----------------------------------------------------------\n";
                                        bool b2 = true;
                                        do{
                                            cout << "1- Name editing.\n";
                                            cout << "2- Age editing.\n";
                                            cout << "3- Give a raise.\n";
                                            cout << "4- Experience editing.\n";
                                            cout << "5- Editing all information.\n\n";
                                            cout << "To exit, enter 0.\n\n";
                                            cout << "Enter your choice: ";
                                            cin >> x3;
                                            system("cls");
                                            switch (x3)
                                            {
                                                case 1 :
                                                {
                                                    cout << "-----------------------------------------------------------\n";
                                                    nur[s].setFullName();
                                                    cout << "-----------------------------------------------------------\n";
                                                    system("cls");
                                                    break;
                                                }
                                                case 2 :
                                                {
                                                    cout << "-----------------------------------------------------------\n";
                                                    nur[s].setAge();
                                                    cout << "-----------------------------------------------------------\n";
                                                    system("cls");
                                                    break;
                                                }
                                                case 3 :
                                                {
                                                    cout << "-----------------------------------------------------------\n";
                                                    int raiseam;
                                                    cout<<"Enter raise amount: ";
                                                    cin>>raiseam;
                                                    nur[s]+raiseam;
                                                    cout << "-----------------------------------------------------------\n";
                                                    system("cls");
                                                    break;
                                                }
                                                case 4 :
                                                {
                                                    cout << "-----------------------------------------------------------\n";
                                                    nur[s].setExperience();
                                                    cout << "-----------------------------------------------------------\n";
                                                    system("cls");
                                                    break;
                                                }
                                                case 5 :
                                                {
                                                    cout << "-----------------------------------------------------------\n";
                                                    nur[s].set();
                                                    cout << "-----------------------------------------------------------\n";
                                                    system("cls");
                                                    break;
                                                }
                                                case 0 :
                                                {
                                                    b2 = false;
                                                    break;
                                                }
                                            }
                                        }while(b2);    
                                    }
                                    break;
                                    case 0 :
                                    b6 = false;
                                    break;
                                }
                            }while(b6);
                        }
                        break;
                        case 0 :
                        b3 = false;
                        break;
                    }
                }while(b3);
            }
            break;
            case 3 :
            {
                    cout << "-----------------------------------------------------------\n";
                    cout << "\t\t\t Patient \n";
                    cout << "-----------------------------------------------------------\n";
                    int p;
                    cout << "Enter the number of Patient: ";
                    cin >> p;
                    Patient pat[p];
                    system("cls");
                    bool b5 = true;
                    do{
                        cout << "1- View Patient information.\n";
                        cout << "2- Edit the information.\n\n";
                        cout << "To exit, enter 0.\n\n";
                        cout << "Enter your choice: ";
                        cin >> x4;
                    system("cls");
                    switch (x4)
                    {
                        case 1 :
                        {
                            cout << "-----------------------------------------------------------\n";
                            cout << "Enter the Nurse's number: ";
                            cin >> s ;
                            s--;
                            cout << "-----------------------------------------------------------\n";
                            bool b4 = true;
                            do{
                                cout << "1- Print Name.\n";
                                cout << "2- Print Age.\n";
                                cout << "3- Print Disease.\n";
                                cout << "4- Print all information.\n\n";
                                cout << "To exit, enter 0.\n\n";
                                cout << "Enter your choice: ";
                                cin >> y3;
                                system("cls");
                                switch (y3)
                                {
                                    case 1 :
                                    {
                                        cout << "-----------------------------------------------------------\n";
                                        pat[s].printFullName();
                                        cout << "-----------------------------------------------------------\n";
                                        break;
                                    }
                                    case 2 :
                                    {
                                        cout << "-----------------------------------------------------------\n";
                                        pat[s].printAge();
                                        cout << "-----------------------------------------------------------\n";
                                        break;
                                    }
                                    case 3 :
                                    {
                                        cout << "-----------------------------------------------------------\n";
                                        pat[s].printDisease();
                                        cout << "-----------------------------------------------------------\n";
                                        break;
                                    }
                                    case 4 :
                                    {
                                        cout << "-----------------------------------------------------------\n";
                                        pat[s].print();
                                        cout << "-----------------------------------------------------------\n";
                                        break;
                                    }
                                    case 0 :
                                    {
                                        b4 = false;
                                        break;
                                    }
                                }
                            }while(b4);    
                        }
                        break;
                        case 2 :
                        {
                            bool b7 = true;
                            do{
                                cout << "-----------------------------------------------------------\n";
                                cout << "\t\t Number of patient : " << pat[p].C_P() << endl;
                                cout << "-----------------------------------------------------------\n";
                                cout << "1- Add a new patient.\n";
                                cout << "2- Editing the information of a specific patient.\n\n";
                                cout << "To exit, enter 0.\n\n";
                                cout << "Enter your choice: ";
                                cin >> y2;
                                system("cls");
                                switch(y2)
                                {
                                    case 1 :
                                    {
                                        
                                        p++;
                                        pat[p-1];
                                        
                                    }
                                    break;
                                    case 2 : 
                                    {
                                        cout << "-----------------------------------------------------------\n";
                                        cout << "Enter the doctor's number: ";
                                        cin >> s ;
                                        s--;
                                        cout << "-----------------------------------------------------------\n";
                                        bool b2 = true;
                                        do{
                                            cout << "1- Name editing.\n";
                                            cout << "2- Age editing.\n";
                                            cout << "3- Disease editing.\n";
                                            cout << "4- Editing all information.\n\n";
                                            cout << "To exit, enter 0.\n\n";
                                            cout << "Enter your choice: ";
                                            cin >> x3;
                                            system("cls");
                                            switch (x3)
                                            {
                                                case 1 :
                                                {
                                                    cout << "-----------------------------------------------------------\n";
                                                    pat[s].setFullName();
                                                    cout << "-----------------------------------------------------------\n";
                                                    system("cls");
                                                    break;
                                                }
                                                case 2 :
                                                {
                                                    cout << "-----------------------------------------------------------\n";
                                                    pat[s].setAge();
                                                    cout << "-----------------------------------------------------------\n";
                                                    system("cls");
                                                    break;
                                                }
                                                case 3 :
                                                {
                                                    cout << "-----------------------------------------------------------\n";
                                                    pat[s].setDisease();
                                                    cout << "-----------------------------------------------------------\n";
                                                    system("cls");
                                                    break;
                                                }
                                                case 4 :
                                                {
                                                    cout << "-----------------------------------------------------------\n";
                                                    pat[s].set();
                                                    cout << "-----------------------------------------------------------\n";
                                                    system("cls");
                                                    break;
                                                }
                                                case 0 :
                                                {
                                                    b2 = false;
                                                    break;
                                                }
                                            }
                                        }while(b2);    
                                    }
                                    break;
                                    case 0 :
                                    b7 = false;
                                    break;
                                }
                            }while(b7);
                        }
                        break;
                        case 0 :
                        b5 = false;
                        break;
                    }
                    }while(b5);
            break;
            }
           
            case 0 :
            a1 = false;
            break;
            default :
            break;

        }
    }while(a1);

    return 0;
}

Hospital::Hospital()
{
    cout << "Enter First Name: ";
    cin >> info.name.first;
        cout << "Enter Middle Name: ";
        cin >> info.name.middle;
            cout << "Enter Last Name: ";
            cin >> info.name.last;
    cout << "Enter day of birth: ";
    cin >> info.date.day;
        cout << "Enter month of birth: ";
        cin >> info.date.month;
            cout << "Enter year of birth: ";
            cin >> info.date.year;
    age = 2023 - info.date.year;
}
Hospital::Hospital(string n1, string n2 , string n3 , int g)
{
    info.name.first = n1;
    info.name.middle = n2;
    info.name.last = n3;
    
    age = g;
}
string Hospital::fullName()
{
    string N;
    N = (info.name.first + " " + info.name.middle + " " + info.name.last);
    return N;

}
void Hospital::printFullName()
{
    cout << "Full Name: " << fullName() << endl;
}
void Hospital::printAge()
{
    cout << "Age: " << age << endl;
}
void Hospital::print()
{
    printFullName();
    printAge();
}
void Hospital::setFullName()
{
    cout << "Enter First Name: ";
    cin >> info.name.first;
        cout << "Enter Middle Name: ";
        cin >> info.name.middle;
            cout << "Enter Last Name: ";
            cin >> info.name.last;
}
void Hospital::setAge()
{
    cout << "Enter day of birth: ";
    cin >> info.date.day;
        cout << "Enter month of birth: ";
        cin >> info.date.month;
            cout << "Enter year of birth: ";
            cin >> info.date.year;
    age = 2023 - info.date.year;
}
void Hospital::set()
{
    setFullName();
    setAge();
}
Doctor::Doctor()
{
    cout << "Enter the specialty: ";
    cin >> specialty;
        cout << "Enter the salary: ";
        cin >> salary;
    counter_D++;
}
Doctor::Doctor(string n1, string n2 , string n3 , int g , int s , string sp) : Hospital(n1,n2,n3,g)
{
    salary = s;
    specialty =sp;
    counter_D++;
}
void Doctor::printSalary()
{
    cout << "Salary: " <<salary<<endl;
}
void Doctor::printSpecialty()
{
    cout << "Specialty: "<<specialty<<endl;
}
void Doctor::print()
{
    Hospital::print();
    printSalary();
    printSpecialty();
}
void Doctor::setSalary()
{
    cout << "Enter the salary: ";
    cin >> salary;
}
void Doctor::setSpecialty()
{
    cout << "Enter the specialty: ";
    cin >> specialty;
}
void Doctor::set()
{
    Hospital::set();
    setSalary();
    setSpecialty();
    counter_D++;
}
Nurse::Nurse()
{
    cout << "Enter number of years of experience: ";
    cin >>experience;
        cout << "Enter the salary: ";
        cin >> salary;
    counter_N++;
}
Nurse::Nurse(string n1, string n2 , string n3 , int g , int s , int e) : Hospital(n1,n2,n3,g)
{
    salary = s ;
    experience = e ;
    counter_N++;
}
void Nurse::printSalary()
{
    cout << "Salary: "<<salary<<endl;
}
void Nurse::printExperience()
{
    cout << "Years of experience: "<<experience<<endl;
}
void Nurse::print()
{
    Hospital::print();
    printSalary();
    printExperience();
}
void Nurse::setSalary()
{
    cout << "Enter the salary: ";
    cin >> salary;
}
void Nurse::setExperience()
{
    cout << "Enter number of years of experience: ";
    cin >>experience;
}   
void Nurse::set()
{
    Hospital::set();
    setSalary();
    setExperience();
    counter_N++;
}
Patient::Patient()
{
    cout << "Enter the type of disease: ";
    cin >> disease;
    counter_P++;
}
Patient::Patient(string n1, string n2 , string n3 , int g , string d) : Hospital(n1,n2,n3,g)
{
    disease = d;
    counter_P++;
}
void Patient::printDisease()
{
    cout << "Disease: "<<disease<<endl;
}
void Patient::print()
{
    Hospital::print();
    printDisease();
}
void Patient::setDisease()
{
    cout << "Enter the type of disease: ";
    cin >> disease;
}   
void Patient::set()
{
    Hospital::set();
    setDisease();
    counter_P++;
}
int TSD(Doctor ob[] , int d )
{
    int sum = 0;
    for (int i = 0 ; i < d ; i++ )
        sum += ob[i].salary;
    return sum ;
}
int TSN(Nurse ob[] , int n )
{
    int sum = 0;
    for (int i = 0 ; i < n ; i++ )
        sum += ob[i].salary;
    return sum ;
}
void printTSD(Doctor ob[] , int d)
{
    cout << "The sum of doctors salaries = " << TSD(ob ,d) << endl;
}
void printTSN(Nurse ob[] , int n)
{
    cout << "The sum of nurses salaries = " << TSN(ob ,n) << endl;
}
int Doctor::C_D()
{
    int *p;
    p = &counter_D;
    return *p;
}
int Nurse::C_N()
{
    int *p;
    p = &counter_N;
    return *p;
}
int Patient::C_P()
{
    int *p;
    p = &counter_P;
    return *p;
}
int Doctor::operator+(int m)
{
    salary+=m;
    return salary;
}
int Nurse::operator+(int m)
{
    salary+=m;
    return salary;
}