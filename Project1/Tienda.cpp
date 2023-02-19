#include <List>
#include <typeinfo>
#include"Tienda.h"
#include"Vendedor.h"
#include"Prenda.h"
#include"Camisa.h"
#include"Pantalon.h"

Tienda::Tienda() {
	nombreT = "Tienda SA";
	direccion = "EsaCalle 111";
	vendedor = new  Vendedor();
	prenda = new Prenda();
	stock = inicializarStock();
	list<Cotizacion*> historial;
};

const char* Tienda::getNombreT() {
	return nombreT;
};
const char* Tienda::getDireccionT() {
	return direccion;
};
const char* Tienda::getNombreV() {
	return vendedor->getNombreV();
};
const char* Tienda::getApellidoV() {
	return vendedor->getApellidoV();
};
int Tienda::getCodV() {
	return vendedor->getCodV();
};

list<Prenda*> Tienda::inicializarStock() {

	list<Prenda*> stock;
	//Camisas creacion
	stock.push_back(new Camisa(true, 100, false, true));
	stock.push_back(new Camisa(false, 100, false, true));
	stock.push_back(new Camisa(true, 150, false, false));
	stock.push_back(new Camisa(false, 150, false, false));

	stock.push_back(new Camisa(true, 75, true, true));
	stock.push_back(new Camisa(false, 75, true, true));
	stock.push_back(new Camisa(true, 175, true, false));
	stock.push_back(new Camisa(false, 175, true, false));

	//Pantalones creacion
	stock.push_back(new Pantalon(false, 750, true));
	stock.push_back(new Pantalon(true, 750, true));

	stock.push_back(new Pantalon(false, 250, false));
	stock.push_back(new Pantalon(true, 250, false));
	
	return stock;
}

list<Prenda*> Tienda::Stock() {
	return stock;
}

void Tienda::crearCamisa() {
	prendaCam = new Camisa();
	cout << "--Camisa creada--" << endl;
	tipoRopa = true;
}

void Tienda::crearPantalon() {
	prendaPan = new Pantalon();
	cout << "--Pantalon creado--" << endl;
	tipoRopa = false;
}

void Tienda::actualizarManga(bool val) {
	if (val == true) {
		prendaCam->actualizarRN(1);
		prendaCam->actualizarManga(true);
	}
	else {
		prendaCam->actualizarRN(0);
		prendaCam->actualizarManga(false);
	}
};
void Tienda::actualizarCuello(bool val) {
	if (val == true) {
		prendaCam->actualizarCuello(true);
		if (prendaCam->getRN() == 1) {
			prendaCam->actualizarRN(3);
		}
		else {
			prendaCam->actualizarRN(2);
		}
	}
	else {
		prendaCam->actualizarCuello(false);
	}

};
void Tienda::actualizarPantalon(bool val) {
	if (val == true) {
		prendaPan->actualizarRN(4);
		prendaPan->actualizarPantalon(true);
	}
	else {
		prendaPan->actualizarRN(0);
		prendaPan->actualizarPantalon(false);
	}
};

void Tienda::actualizarCalidad(bool val) {
	if (tipoRopa) {
		if (val == true) {
			prendaCam->actualizarCalidad(true);
		}
		else {
			prendaCam->actualizarCalidad(false);
		}
	}
	else {
		if (val == true) {
			prendaPan->actualizarCalidad(true);
		}
		else {
			prendaPan->actualizarCalidad(false);
		}
	}
};

void Tienda::actualizarPrecioU(float val) {
	if (tipoRopa) {
		prendaCam->actualizarPrecioU(val);
	}
	else {
		prendaPan->actualizarPrecioU(val);
	}
};

void Tienda::actualizarCantidad(float val) {
	if (tipoRopa) {
		prendaCam->actualizarCant(val);
		cout << "Stock disponible: " << corroborarStock(prendaCam->getBoolCalidad(), prendaCam->getBoolManga(), prendaCam->getBoolCuello()) << endl;
		cout << "Stock requerido: " << prendaCam->getCant() << endl;
		if (corroborarStock(prendaCam->getBoolCalidad(), prendaCam->getBoolManga(), prendaCam->getBoolCuello()) >= prendaCam->getCant()) {
			vendedor->realizarCotizacion(prendaCam);
			ingresarCotizacion();
		}
		else {
			cout << "---No hay suficiente Stock---" << endl;
		}
	}
	else {
		prendaPan->actualizarCant(val);
		cout << "Stock disponible: " << corroborarStock(prendaPan->getBoolCalidad(), prendaPan->getBoolPantalon()) << endl;
		cout << "Stock requerido: " << prendaPan->getCant() << endl;
		if (corroborarStock(prendaPan->getBoolCalidad(), prendaPan->getBoolPantalon()) >= prendaPan->getCant()) {
			vendedor->realizarCotizacion(prendaPan);
			ingresarCotizacion();
		}
		else {
			cout << "---No hay suficiente Stock---" << endl;
		}
	}
};

int Tienda::corroborarStock(bool calidad, bool tManga, bool tCuello) {
	int _producto = 0;

	if (Stock().empty()) {
		return _producto;
	}

	for (Prenda* prod : Stock()) {
		if (dynamic_cast<Camisa*>(prod)) {
			Camisa* camisa = dynamic_cast<Camisa*>(prod);
			if (camisa->getBoolManga() == tManga && camisa->getBoolCuello() == tCuello && camisa->getBoolCalidad() == calidad) {
				_producto = camisa->getCant();
				return _producto;
			}
		}
	}

	return _producto;
}



int Tienda::corroborarStock(bool calidad, bool tPantalon) {
	int _producto = 0;

	if (Stock().empty()) {
		return _producto;
	}

	for (Prenda* prod : Stock()) {
		if (dynamic_cast<Pantalon*>(prod)) {
			Pantalon* pantalon = dynamic_cast<Pantalon*>(prod);
			if (pantalon->getBoolPantalon() == tPantalon && pantalon->getBoolCalidad() == calidad) {
				_producto = pantalon->getCant();
				return _producto;
			}
		}
	}

	return _producto;
}

void Tienda::ingresarCotizacion() {
	if (tipoRopa) {
		nuevaCotizacion = new Cotizacion((historial.size()+1), vendedor->getCodV(), prendaCam, prendaCam->getCant());
	}
	else {
		nuevaCotizacion = new Cotizacion((historial.size() + 1), vendedor->getCodV(), prendaPan, prendaPan->getCant());
	}
	historial.push_front(nuevaCotizacion);
}

void Tienda::imprimirHistorial() {
	for (Cotizacion* cotizacion : historial) {
		cotizacion->imprimirCoti();
	}
}
