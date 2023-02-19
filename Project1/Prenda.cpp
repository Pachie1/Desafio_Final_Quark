#include"Prenda.h"

Prenda::Prenda(bool calidad, int cant) {
	this->calidad = calidad;
	this->cant = cant;
};
void Prenda::actualizarCalidad(bool val) {
	calidad = val;
};
void Prenda::actualizarPrecioU(float val) {
	precioU = val;
};
void Prenda::actualizarCant(int val) {
	cant = val;
};
void Prenda::actualizarRN(int val) {
	RN = val;
};

const char* Prenda::getCalidad() {
	if (this->calidad == true) {
		return "Premium";
	}
	else {
		return "Standard";
	}
}
bool Prenda::getBoolCalidad() {
	return calidad;
};
float Prenda::getPrecioU() {
	return precioU;
};
int Prenda::getCant() {
	return cant;
};
int Prenda::getRN() {
	return RN;
};