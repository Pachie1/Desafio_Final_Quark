#include"Vendedor.h"
#include <chrono>
#include <ctime>
#include <stdio.h>


Vendedor::Vendedor() {
	cotizacion = new Cotizacion();
	codVendedor = 1;
	nombreV = "Gaspar";
	apellidoV = "Ormachea";
};

void Vendedor::realizarCotizacion(Camisa* prendaCam) {
	cotizacion->actualizarprendaCotizada(prendaCam);
	cotizacion->actualizarCantPrendCoti(prendaCam->getCant());
	time_t value = time(NULL);
	char buff[26];
	ctime_s(buff, sizeof buff, &value);
	cotizacion->actualizarFecHora(buff);
	cotizacion->actualizarCodVen(codVendedor);
	cotizacion->imprimirCoti();
}

void Vendedor::realizarCotizacion(Pantalon* prendaPan) {
	cotizacion->actualizarprendaCotizada(prendaPan);
	cotizacion->actualizarCantPrendCoti(prendaPan->getCant());
	time_t value = time(NULL);
	char buff[26];
	ctime_s(buff, sizeof buff, &value);
	cotizacion->actualizarFecHora(buff);
	cotizacion->actualizarCodVen(codVendedor);
	cotizacion->imprimirCoti();
}

const char* Vendedor::getFecHora() {
	time_t value = time(NULL);
	char buff[26];
	ctime_s(buff, sizeof buff, &value);
	return buff;
};
const char* Vendedor::getNombreV() {
	return nombreV;
};
const char* Vendedor::getApellidoV() {
	return apellidoV;
};
int Vendedor::getCodV() {
	return codVendedor;
};

Cotizacion* Vendedor::getCotizacion() {
	return this->cotizacion;
}