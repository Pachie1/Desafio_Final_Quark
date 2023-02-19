#ifndef COTIZACION_H
#define COTIZACION_H
#include<iostream>
#include "Prenda.h"
#include "Vendedor.h"
#include "Camisa.h"
#include "Pantalon.h"


class Prenda;
class Vendedor;
class Camisa;
class Pantalon;
using namespace std;
class Cotizacion
{
public:
	Cotizacion();
	Cotizacion(int numIde, int codVen, Pantalon* prendCotizadaP, int cantPrendCoti);
	Cotizacion(int numIde, int codVen, Camisa* prendCotizadaC, int cantPrendCoti);
	void actualizarNumIde(int numIdeV);
	void actualizarCodVen(int codVenV);
	void actualizarFecHora(char* fecHoraV);
	void actualizarprendaCotizada(Camisa* prendaCam);
	void actualizarprendaCotizada(Pantalon* prendaPan);
	void actualizarCantPrendCoti(int cantPrendCotiv);
	void actualizarTotalCoti(Prenda* prendCotizada);
	void imprimirCoti();
private:
	int numIde;
	int codVen = 0;
	const char* fecHora = "0";
	Pantalon* prendCotizadaP;
	Camisa* prendCotizadaC;
	bool tipoRopa;
	int cantPrendCoti = 0;
	float totalCoti = 0;
	float calcularTotal(Prenda* prendCotizada);
};
#endif