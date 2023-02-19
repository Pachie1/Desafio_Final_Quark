#ifndef PRENDA_H
#define PRENDA_H
#include<iostream>

using namespace std;

class Prenda
{
	friend class Camisa;
	friend class Pantalon;
public:
	Prenda() {};
	Prenda(bool calidad, int cant);
	void actualizarCalidad(bool val);
	void actualizarPrecioU(float val);
	void actualizarCant(int val);
	void actualizarRN(int val);
	bool getBoolCalidad();
	const char* getCalidad();
	float getPrecioU();
	int getCant();
	virtual int getRN();
protected:
	bool calidad;
	float precioU = 0;
	int cant;
	int RN = 0;
};
#endif