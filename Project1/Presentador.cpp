#include "Presentador.h"
#include "Tienda.h"

Presentador::Presentador() {
	tienda = new Tienda();
}
void Presentador::crearCamisa() {
	tienda->crearCamisa();
};
void Presentador::crearPantalon() {
	tienda->crearPantalon();
};
void Presentador::actualizarCamisaM(bool val) {
	tienda->actualizarManga(val);
};
void Presentador::actualizarCamisaC(bool val) {
	tienda->actualizarCuello(val);
};
void Presentador::actualizarPantalon(bool val) {
	tienda->actualizarPantalon(val);
};
void Presentador::actualizarCalidad(bool val) {
	tienda->actualizarCalidad(val);
};
void Presentador::actualizarPrecio(int val) {
	tienda->actualizarPrecioU(val);
};
void Presentador::actualizarCantidad(int val) {
	tienda->actualizarCantidad(val);
};
void Presentador::historialCotizacion() {
	tienda->imprimirHistorial();
};
const char* Presentador::getNombreT() {
	return tienda->getNombreT();
};
const char* Presentador::getDireccionT() {
	return tienda->getDireccionT();
};
const char* Presentador::getNombreV() {
	return tienda->getNombreV();
};
const char* Presentador::getApellidoV() {
	return tienda->getApellidoV();
};
int Presentador::getCodV() {
	return tienda->getCodV();
};

Presentador::~Presentador() {
	delete tienda;
}