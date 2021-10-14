#include "Operario.h"

Operative::Operative()
{
	Name = "";
	WorkDays = 31;
	for (int i = 0; i < 31; i++)
	{
		ExtraHours[i] = 0;
	}
	OperatorType = 1;
}
Operative::~Operative()
{

}

ostream& operator<<(ostream& Data, Operative Aux)
{
	string OperatorTypeP[] = { "Supervisor employee","Plant employee","Specialized employee" };
	string OperatorPerformance[] = { "May improve","Good","Very good","Exelent"};
	Data << "Name of the operator: ";
	Data << Aux.Name << endl;
	Data << "Worked days: ";
	Data << Aux.WorkDays << endl;
	Data << "Average extra hours: ";
	Data << Aux.Average() << endl;
	Data << "Operator type: ";
	Data << OperatorTypeP[Aux.OperatorType-1] << endl;
	Data << "Pay net: ";
	Data << Aux.PayNet() << " Pesos" << endl;
	Data << "Extra hours bonus: ";
	Data << Aux.Bonification() << " Pesos" << endl;
	Data << "Performance: ";
	if (81 <= Aux.WorkPerformance && Aux.WorkPerformance <= 100)
	{
		Data << OperatorPerformance[3] << endl;
		Data << "Bonus for performance: ";
		Data << Aux.PerformanceBonus() << " Pesos" << endl << endl;
	}
	else
	{
		if (61 <= Aux.WorkPerformance && Aux.WorkPerformance <= 80)
		{
			Data << OperatorPerformance[2] << endl;
			Data << "Bonus for performance: ";
			Data << Aux.PerformanceBonus() << " Pesos" << endl << endl;
		}
		else
		{
			if (41 <= Aux.WorkPerformance && Aux.WorkPerformance <= 60)
			{
				Data << OperatorPerformance[1] << endl;
				Data << "Bonus for performance: ";
				Data << Aux.PerformanceBonus() << " Pesos" << endl << endl;
			}
			else
			{
				Data << OperatorPerformance[0] << endl;
				Data << "Bonus for performance: ";
				Data << Aux.PerformanceBonus() << " Pesos" << endl << endl;
			}
		}
	}

	return Data;
}
void MenuType()
{
	cout << "|||   Operator type menu   |||\n\n";
	cout << "\n1. Supervisor employee.";
	cout << "\n2. Plant employee.";
	cout << "\n3. Specialized employee.";
	cout << "\n\nWrite the type of operator: ";
}

void MenuPerformance()
{
	cout << "|||   Performance menu   |||\n\n";
	cout << "\n   Exelent      81  -   100";
	cout << "\n   Very good    61  -   80";
	cout << "\n   Good         41  -   60";
	cout << "\n   May improve  0   -   40";
	cout << "\n\nHow was the performance of the operator: ";
}
istream& operator>>(istream& in, Operative& Aux)
{
	cout << "Name of the operator: ";
	in >> Aux.Name;
	system("cls");
	cout << "     |||   Operator data   |||\n\n";
	cout << "Worked days: ";
	
	do
	{
		in >> Aux.WorkDays;
		if (8 <= Aux.WorkDays && Aux.WorkDays <= 31)
		{
			for (int i = 0; i < Aux.WorkDays; i++)
			{
				cout << "\nHow many extra hours in the " << i + 1 << " day: ";
				in >> Aux.ExtraHours[i];
			}
			break;
		}
		else
		{
			cout << "Days must be between 8 and 31\n\n";
			cout << "Write again the Worked days: ";
		}
	} while (!(8 <= Aux.WorkDays && Aux.WorkDays <= 31));
	system("cls");
	do
	{
		MenuType();
		in >> Aux.OperatorType;
		if ((1 <= Aux.OperatorType && Aux.OperatorType <= 3))
		{
			break;
		}
		else
		{
			cout << "Invalid input\n\n";
			cout << "Write something to return\n";
			cin.ignore();
			cin.get();
			std::system("cls");
		}
	} while (!(1 <= Aux.OperatorType && Aux.OperatorType <= 3));
	system("cls");
	do
	{
		MenuPerformance();
		in >> Aux.WorkPerformance;
		if ((0 <= Aux.WorkPerformance && Aux.WorkPerformance <= 100))
		{
			break;
		}
		else
		{
			cout << "Invalid input\n\n";
			cout << "Write something to return\n";
			cin.ignore();
			cin.get();
			std::system("cls");
		}
	} while (!(0 <= Aux.WorkPerformance && Aux.WorkPerformance <= 100));
	std::system("cls");
	return in;
}
long Operative::PerformanceBonus()
{
	if (81 <= WorkPerformance && WorkPerformance <= 100)
	{
		switch (OperatorType)
		{
		case 1:
			return (WorkDays * 8 * 80000) * 0.5;
		case 2:
			return (WorkDays * 8 * 60000) * 0.5;
		case 3:
			return (WorkDays * 8 * 100000) * 0.5;
		default:
			break;
		}
	}
	else
	{
		if (61 <= WorkPerformance && WorkPerformance <= 80)
		{
			switch (OperatorType)
			{
			case 1:
				return (WorkDays * 8 * 80000) * 0.4;
			case 2:
				return (WorkDays * 8 * 60000) * 0.4;
			case 3:
				return (WorkDays * 8 * 100000) * 0.4;
			default:
				break;
			}
		}
		else
		{
			if (41 <= WorkPerformance && WorkPerformance <= 60)
			{
				switch (OperatorType)
				{
				case 1:
					return (WorkDays * 8 * 80000) * 0.3;
				case 2:
					return (WorkDays * 8 * 60000) * 0.3;
				case 3:
					return (WorkDays * 8 * 100000) * 0.3;
				default:
					break;
				}
			}
		}
	}
	return 0;
}
float Operative::Average()
{
	float Average = 0;
	for (int i = 0; i < WorkDays; i++)
	{
		Average+=ExtraHours[i];
	}
	Average = Average / WorkDays;
	return Average;
}

long Operative::Bonification()
{
	if (Average() > 4)
	{
		int BaseB = 0, NumAux;
		for (int i = 0; i < 31; i++)
		{
			NumAux = ExtraHours[i] - 4;
			if (NumAux >= 0)
				BaseB += NumAux;
		}
		switch (OperatorType)
		{
		case 1:
			return BaseB * (80000 * 0.7);
		case 2:
			return BaseB * (60000 * 0.5);
		case 3:
			return BaseB * (100000 * 0.3);
		default:
			break;
		}
	}
	return 0;
}
long Operative::PayNet()
{
	int AuxHours = 0;
	for (int i = 0; i < WorkDays; i++)
	{
		AuxHours += ExtraHours[i];
	}
	switch (OperatorType)
	{
	case 1:
		return (WorkDays * 8 * 80000) + ((80000 * 1.3) * AuxHours) + Bonification() + PerformanceBonus();
	case 2:
		return (WorkDays * 8 * 60000) + ((60000 * 1.5) * AuxHours) + Bonification() + PerformanceBonus();
	case 3:
		return (WorkDays * 8 * 100000) + ((100000 * 1.7) * AuxHours) + Bonification() + PerformanceBonus();
	default:
		break;
	}
	return 0;
}