#ifndef Vista_H
#define Vista_H
#include<iostream>
#include "Tienda.h"

using namespace std;
class Presentador;
class Vista
{
public:
	Vista();
	void fraseGenerica();
	void menuInicio();
	void menuHisto();
	void menuCoti();
	void menuCamisaM();
	void menuCamisaC();
	void menuPantalon();
	void menuCalidad();
	void menuPrecio();
	void menuCantidad();
	virtual ~Vista();

private:
	Presentador* presentador;
};
#endif