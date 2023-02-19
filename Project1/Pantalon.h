#ifndef Pantalon_H
#define Pantalon_H
#include<iostream>
#include"Prenda.h"


using namespace std;
class Pantalon : public Prenda
{
public:
	Pantalon() {};
	Pantalon(bool calidad, int cant, bool tPantalon);
	const char* getTipoPantalon();
	bool getBoolPantalon();
	void actualizarPantalon(bool val);
private:
	bool tPantalon = false;
};
#endif