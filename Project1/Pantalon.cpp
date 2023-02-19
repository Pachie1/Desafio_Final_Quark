#include"Pantalon.h"
#include"Prenda.h"

Pantalon::Pantalon (bool calidad, int cant, bool tPantalonV) : Prenda(calidad, cant){
	this->tPantalon = tPantalonV;
};

void Pantalon::actualizarPantalon(bool val) {
	tPantalon = val;
}
bool Pantalon::getBoolPantalon() {
	return tPantalon;
}
const char* Pantalon::getTipoPantalon() {
	if (tPantalon == true) {
		return "Pantalon chupin";
	};
	if (tPantalon == false) {
		return "Pantalon";
	};
}