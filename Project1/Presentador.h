#ifndef Presentador_H
#define Presentador_H
#include<iostream>
#include "Tienda.h"

using namespace std;
class Tienda;
class Presentador
{
public:
	Presentador();
	void crearCamisa();
	void crearPantalon();
	void actualizarCamisaM(bool val);
	void actualizarCamisaC(bool val);
	void actualizarPantalon(bool val);
	void actualizarCalidad(bool val);
	void actualizarPrecio(int val);
	void actualizarCantidad(int val);
	void historialCotizacion();
	const char* getNombreT();
	const char* getDireccionT();
	const char* getNombreV();
	const char* getApellidoV();
	int getCodV();
	virtual ~Presentador();

private:
	Tienda* tienda;
};
#endif
