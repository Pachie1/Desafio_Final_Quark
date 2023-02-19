#include"Camisa.h"
#include"Prenda.h"

Camisa::Camisa(bool calidad, int cant, bool tManga, bool tCuello) : Prenda(calidad, cant) {
	this->tManga = tManga;
	this->tCuello = tCuello;
}

void Camisa::actualizarManga(bool val) {
	tManga = val;
}

void Camisa::actualizarCuello(bool val) {
	tCuello = val;
}
	
bool Camisa::getBoolManga() {
	return tManga;
}
bool Camisa::getBoolCuello() {
	return tCuello;
}

const char* Camisa::getTipoManga() {
	if (tManga == true) {
		return "Manga corta";
	};
	if (tManga == false) {
		return "Manga Larga";
	};
}

const char* Camisa::getTipoCuello() {
	if (tCuello == true) {
		return "Cuello Mao";
	};
	if (tCuello == false) {
		return "Cuello Normal";
	};
}