#include "Operario.h"
void PrincipalMenu();
int main()
{
    Operative Op[10];
    char Option = '0'; int Amount = 0, Aux = 0, AuxOp = 0; long Bonus = 0;
    while (Option != '3')
    {
        PrincipalMenu();
        cin >> Option;
        system("cls");
        switch (Option)
        {
        case '1':
        {
            Aux = 1;
            while (!(1 <= Amount && Amount <= 10))
            {
                cout << "     |||   Operator data menu   |||\n\n";
                cout << "Write the amount of operator you want to register: ";
                cin >> Amount;
                if (1 <= Amount && Amount <= 10)
                {
                    break;
                }
                else
                {
                    cout << "\nNumber must be between 1 and 10\n";
                }
            }
            system("cls");
            for (int i = 0; i < Amount; i++)
            {
                cout << "     |||   Operator data menu   |||\n\n";
                cout << "        |||   Operator " << i + 1 << "   |||\n\n";
                cin >> Op[i];
                Bonus =Bonus + Op[i].Bonification() + Op[i].PerformanceBonus();
            }
            break;
        }
        case '2':
        {
            if (Aux == 1)
            {
                for (int i = 0; i < Amount; i++)
                {
                    cout << "|||   Operator " << i + 1 << "   |||\n\n";
                    cout << Op[i];
                }
                cout << "Total bonus: ";
                cout << Bonus << " Pesos" << endl;
                cin.ignore();
                cin.get();
                system("cls");
            }
            else
            {
                cout << "\n\n\t\tError!!!!!\n\n";
                cout << "You need to enter the data before priting it\n";
                cin.ignore();
                cin.get();
                system("cls");
            }
            break;
        }
        case '3':
            exit(0);
        default:
            cout << "Invalid option\n";
            cin.ignore();
            cin.get();
            system("cls");
            break;
        }

    }
    return 0;
}

void PrincipalMenu()
{
    cout << "|||   Principal menu   |||\n";
    cout << "\n1. Register operators";
    cout << "\n2. Print Data";
    cout << "\n3. End program.";
    cout << "\n\n\nChoose one option: ";
}