#ifndef VENDEDOR_H
#define VENDEDOR_H
#include<iostream>
#include "Prenda.h"
#include "Cotizacion.h"

class Prenda;
class Cotizacion;
class Camisa;
class Pantalon;
using namespace std;
class Vendedor
{
public:
	Vendedor();
	void realizarCotizacion(Camisa* prendaCam);
	void realizarCotizacion(Pantalon* prendaPan);
	const char* getFecHora();
	const char* getNombreV();
	const char* getApellidoV();
	int getCodV();
	Cotizacion* getCotizacion();
private:
	const char* nombreV;
	const char* apellidoV;
	int codVendedor;
	Cotizacion* cotizacion;
};
#endif