#ifndef TIENDA_H
#define TIENDA_H
#include<iostream>
#include <List>
#include"Vendedor.h"
#include"Prenda.h"
#include"Camisa.h"
#include"Pantalon.h"

class Prenda;
class Vendedor;
class Camisa;
class Pantalon;
using namespace std;
class Tienda 
{
public:
	Tienda();
	list<Prenda*> Stock();
	list<Prenda*> inicializarStock();
	int corroborarStock(bool calidad, bool tManga, bool tCuello);
	int corroborarStock(bool calidad, bool tPantalon);
	void actualizarManga(bool val);
	void actualizarCuello(bool val);
	void actualizarPantalon(bool val);
	void actualizarCalidad(bool val);
	void actualizarPrecioU(float val);
	void actualizarCantidad(float val);
	void crearCamisa();
	void crearPantalon();
	const char* getNombreT();
	const char* getDireccionT();
	const char* getNombreV();
	const char* getApellidoV();
	int getCodV();

	void ingresarCotizacion();
	void imprimirHistorial();
private:
	Vendedor* vendedor;
	Cotizacion* nuevaCotizacion;
	Prenda* prenda;
	list<Prenda*> stock;
	list<Cotizacion*> historial;
	Camisa* prendaCam;
	Pantalon* prendaPan;
	bool tipoRopa;
	const char* nombreT;
	const char* direccion;
};
#endif