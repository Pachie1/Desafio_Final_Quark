#include"Cotizacion.h"


Cotizacion::Cotizacion() {
	this->numIde = 0;
};

Cotizacion::Cotizacion(int numIde, int codVen, Pantalon* prendCotizadaP, int cantPrendCoti) {
	this->numIde = numIde;
	this->fecHora = "0";
	this->codVen = codVen;
	this->prendCotizadaP = prendCotizadaP;
	this->tipoRopa = false;
	this->cantPrendCoti = cantPrendCoti;
	this->totalCoti = calcularTotal(prendCotizadaP);
}
Cotizacion::Cotizacion(int numIde, int codVen, Camisa* prendCotizadaC, int cantPrendCoti) {
	this->numIde = numIde;
	this->fecHora = "0";
	this->codVen = codVen;
	this->prendCotizadaC = prendCotizadaC;
	this->tipoRopa = true;
	this->cantPrendCoti = cantPrendCoti;
	this->totalCoti = calcularTotal(prendCotizadaC);
}

void Cotizacion::actualizarNumIde(int numIdeV) {
	numIde = numIdeV;
};

void Cotizacion::actualizarCodVen(int codVenV) {
	codVen = codVenV;
};
void Cotizacion::actualizarFecHora(char* fecHoraV) {
	fecHora = fecHoraV;
};
void Cotizacion::actualizarprendaCotizada(Camisa* prendaCam) {
	prendCotizadaC = prendaCam;
	actualizarTotalCoti(prendCotizadaC);
	tipoRopa = true;
};
void Cotizacion::actualizarprendaCotizada(Pantalon* prendaPan) {
	prendCotizadaP = prendaPan;
	actualizarTotalCoti(prendCotizadaP);
	tipoRopa = false;
};
void Cotizacion::actualizarCantPrendCoti(int cantPrendCotiV) {
	cantPrendCoti = cantPrendCotiV;
};
void Cotizacion::actualizarTotalCoti(Prenda* prendCotizada) {
	totalCoti = calcularTotal(prendCotizada);
};

float Cotizacion::calcularTotal(Prenda* prendCotizada) {
	float total=0;
	switch (prendCotizada->getRN())
	{
	case(1):
		prendCotizada->actualizarPrecioU(prendCotizada->getPrecioU() - prendCotizada->getPrecioU() * 0.1);
		break;
	case(2):
		prendCotizada->actualizarPrecioU(prendCotizada->getPrecioU() + prendCotizada->getPrecioU() * 0.03);
		break;
	case(3):
		prendCotizada->actualizarPrecioU(prendCotizada->getPrecioU() - prendCotizada->getPrecioU() * 0.1);
		prendCotizada->actualizarPrecioU(prendCotizada->getPrecioU() + prendCotizada->getPrecioU() * 0.03);
		break;
	case(4):
		prendCotizada->actualizarPrecioU(prendCotizada->getPrecioU() - prendCotizada->getPrecioU() * 0.12);
		break;
	default:
		break;
	}
	if (prendCotizada->getBoolCalidad() == true) {
		prendCotizada->actualizarPrecioU(prendCotizada->getPrecioU() + prendCotizada->getPrecioU() * 0.3);
	}
	return total = prendCotizada->getPrecioU() * prendCotizada->getCant();
};

void Cotizacion::imprimirCoti() {
	cout << "-------------------------------------------------------------------" << endl;
	cout << "Numero de Identificacion: " << this->numIde << endl;
	cout << "Fecha y Hora: " << this->fecHora << endl;
	cout << "Codigo del vendedor: " << this->codVen << endl;
	if (this->tipoRopa == true) {
		cout << "Prenda cotizada: " << "Camisa" << " - " << this->prendCotizadaC->getTipoManga() << " - " << this->prendCotizadaC->getTipoCuello() << " - " << this->prendCotizadaC->getCalidad() << endl;
		cout << "Precio unitario: " << this->prendCotizadaC->getPrecioU() << endl;
	}
	if (this->tipoRopa == false) {
		cout << "Prenda cotizada: " << "Pantalon" << " - " << this->prendCotizadaP->getTipoPantalon() << " - " << this->prendCotizadaP->getCalidad() << endl;
		cout << "Precio unitario: " << this->prendCotizadaP->getPrecioU() << endl;
	}
	cout << "Cantidad de unidades cotizadas: " << this->cantPrendCoti << endl;
	cout << "Precio Total: $" << this->totalCoti << endl;
	cout << "-------------------------------------------------------------------" << endl;
};