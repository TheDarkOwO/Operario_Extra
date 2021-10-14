#ifndef OPERARIO_H
#define OPERARIO_H

#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Operative
{
	friend istream& operator>>(istream&in, Operative&); //Flujo de datos de entrada
	friend ostream& operator<<(ostream& out, Operative);  //Flujo de datos de salida
	friend void MenuType();
	friend void MenuPerformance();
public:
	Operative();
	~Operative();
	float Average();
	long Bonification();
	long PayNet();
	long PerformanceBonus();
private:
	int WorkDays, OperatorType, WorkPerformance;
	string Name;
	int ExtraHours[31];

};


#endif
