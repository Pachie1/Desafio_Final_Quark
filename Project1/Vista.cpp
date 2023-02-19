#include "Vista.h"
#include "Tienda.h"
#include "Presentador.h"

Vista::Vista() {
	presentador = new Presentador();
	fraseGenerica();
	menuInicio();
}

void Vista::fraseGenerica() {
	cout <<  endl;
	cout << "COTIZADOR EXPRESS - COTIZAR" << endl;
	cout << "-------------------------------------------------------------------" << endl;
	cout << "Presione 3 para volver al Vista principal" << endl;
	cout << "-------------------------------------------------------------------" << endl;
}
void Vista::menuInicio() {
	cout << "COTIZADOR EXPRESS - Vista PRINCIPAL" << endl;
	cout << "-------------------------------------------------------------------" << endl;
	cout << "Nombre de la tienda: " << presentador->getNombreT() << " | " << "Direccion de la tienda: " << presentador->getDireccionT() << endl;
	cout << "-------------------------------------------------------------------" << endl;
	cout << "Nombre y Apellido del vendedor: " << presentador->getNombreV() << " " << presentador->getApellidoV() << " | " << "Codigo del vendedor: " << presentador->getCodV() << endl;
	cout << "-------------------------------------------------------------------" << endl;
	cout << "" << endl;
	int input;
	cout << "SELECCIONE UNA OPCION DEL Vista: " << endl;
	cout << "1- Historial de Cotizaciones" << endl;
	cout << "2- Realizar cotizacion" << endl;
	cout << "3- Salir" << endl;
	do
	{
		cin >> input;
		if (cin.fail())
		{
			cout << "--------------------------------------------------" << endl;
			cout << "Input invalido, porfavor ingrese 1, 2 o 3." << endl;
			cout << "--------------------------------------------------" << endl;
			cin.clear();
			cin.ignore(500, '\n');
		}
		else {
			if (input == 1) {
				cout << "--------------------------------------------------" << endl;
				menuHisto();
			}
			if (input == 2) {
				cout << "--------------------------------------------------" << endl;
				menuCoti();
			}
			if (input == 3) {
				EXIT_SUCCESS;
			}
		}

	} while (input != 3);
}

void Vista::menuHisto() {
	int input;
	presentador->historialCotizacion();
	cout << "-------------------------------------------------------------------" << endl;
	cout << "Presione 3 para volver al menu principal" << endl;
	cout << "-------------------------------------------------------------------" << endl;
	do {
		cin >> input;
		if (cin.fail())
		{
			cout << "--------------------------------------------------" << endl;
			cout << "Input invalido, porfavor ingrese 1, 2 o 3." << endl;
			cout << "--------------------------------------------------" << endl;
			cin.clear();
			cin.ignore(500, '\n');
		}
		else {
			if (input == 1) {
				cout << "--------------------------------------------------" << endl;
				menuHisto();
			}
			if (input == 2) {
				cout << "--------------------------------------------------" << endl;
				menuCoti();
			}
			if (input == 3) {
				menuInicio();
			}

		}
	} while (input != '3');
}

void Vista::menuCoti() {
	int input;
	fraseGenerica();
	cout << "PASO 1: Seleccione la prenda a cotizar:" << endl;
	cout << "1) Camisa" << endl;
	cout << "2) Pantalon" << endl;
	cout << "-------------------------------------------------------------------" << endl;
	do {
		cin >> input;
		if (cin.fail())
		{
			cout << "--------------------------------------------------" << endl;
			cout << "Input invalido, porfavor ingrese 1, 2 o 3." << endl;
			cout << "--------------------------------------------------" << endl;
			cin.clear();
			cin.ignore(500, '\n');
		}
		else {
			if (input == 1) {
				presentador->crearCamisa();
				menuCamisaM();
			}
			if (input == 2) {
				presentador->crearPantalon();
				menuPantalon();
			}
			if (input == 3) {
				menuInicio();
			}

		}
	} while (input != 3);
}

void Vista::menuCamisaM() {
	int input;
	fraseGenerica();
	cout << "PASO 2.a: La camisa a cotizar, ¿Es Manga Corta?:" << endl;
	cout << "1) Si" << endl;
	cout << "2) No" << endl;
	cout << "-------------------------------------------------------------------" << endl;
	do {
		cin >> input;
		if (cin.fail())
		{
			cout << "--------------------------------------------------" << endl;
			cout << "Input invalido, porfavor ingrese 1, 2 o 3." << endl;
			cout << "--------------------------------------------------" << endl;
			cin.clear();
			cin.ignore(500, '\n');
		}
		else {
			if (input == 1) {
				presentador->actualizarCamisaM(true);
				menuCamisaC();
			}
			if (input == 2) {
				presentador->actualizarCamisaM(false);
				menuCamisaC();
			}
			if (input == 3) {
				menuInicio();
			}
		}
	} while (input != 3);
}

void Vista::menuCamisaC() {
	int input;
	fraseGenerica();
	cout << "PASO 2.a: La camisa a cotizar, ¿Es Cuello Mao?:" << endl;
	cout << "1) Si" << endl;
	cout << "2) No" << endl;
	cout << "-------------------------------------------------------------------" << endl;
	do {
		cin >> input;
		if (cin.fail())
		{
			cout << "--------------------------------------------------" << endl;
			cout << "Input invalido, porfavor ingrese 1, 2 o 3." << endl;
			cout << "--------------------------------------------------" << endl;
			cin.clear();
			cin.ignore(500, '\n');
		}
		else {
			if (input == 1) {
				presentador->actualizarCamisaC(true);
				menuCalidad();
			}
			if (input == 2) {
				presentador->actualizarCamisaC(false);
				menuCalidad();
			}
			if (input == 3) {
				menuInicio();
			}
		}
	} while (input != 3);
}

void Vista::menuPantalon() {
	int input;
	fraseGenerica();
	cout << "PASO 2.c: El pantalon a cotizar, ¿Es Chupin?:" << endl;
	cout << "1) Si" << endl;
	cout << "2) No" << endl;
	cout << "-------------------------------------------------------------------" << endl;
	do {
		cin >> input;
		if (cin.fail())
		{
			cout << "--------------------------------------------------" << endl;
			cout << "Input invalido, porfavor ingrese 1, 2 o 3." << endl;
			cout << "--------------------------------------------------" << endl;
			cin.clear();
			cin.ignore(500, '\n');
		}
		else {
			if (input == 1) {
				presentador->actualizarPantalon(true);
				menuCalidad();
			}
			if (input == 2) {
				presentador->actualizarPantalon(false);
				menuCalidad();
			}
			if (input == 3) {
				menuInicio();
			}
		}
	} while (input != 3);
}

void Vista::menuCalidad() {
	int input;
	fraseGenerica();
	cout << "PASO 3: Seleccione la calidad de la prenda:" << endl;
	cout << "1) Premium" << endl;
	cout << "2) Standard" << endl;
	cout << "-------------------------------------------------------------------" << endl;
	do {
		cin >> input;
		if (cin.fail())
		{
			cout << "--------------------------------------------------" << endl;
			cout << "Input invalido, porfavor ingrese 1, 2 o 3." << endl;
			cout << "--------------------------------------------------" << endl;
			cin.clear();
			cin.ignore(500, '\n');
		}
		else {
			if (input == 1) {
				presentador->actualizarCalidad(true);
				menuPrecio();
			}
			if (input == 2) {
				presentador->actualizarCalidad(false);
				menuPrecio();
			}
			if (input == 3) {
				menuInicio();
			}
		}
	} while (input != 3);
}

void Vista::menuPrecio() {
	float input;
	fraseGenerica();
	cout << "PASO 4: Ingrese el precio unitario de la prenda a cotizar:" << endl;
	cout << "- ";
	do {
		cin >> input;
		if (cin.fail())
		{
			cout << "--------------------------------------------------" << endl;
			cout << "Input invalido, porfavor ingrese 1, 2 o 3." << endl;
			cout << "--------------------------------------------------" << endl;
			cin.clear();
			cin.ignore(500, '\n');
		}
		else {
			cout << "-------------------------------------------------------------------" << endl;
			presentador->actualizarPrecio(input);
			if (input == 3) {
				menuInicio();
			}
			else {
				menuCantidad();
			}
		}
	} while (input != 3);
}

void Vista::menuCantidad() {
	int input;
	fraseGenerica();
	cout << "PASO 5: Ingrese la cantidad de unidades a cotizar:" << endl;
	cout << "- ";
	do {
		cin >> input;
		cout << "-------------------------------------------------------------------" << endl;
		if (cin.fail())
		{
			cout << "--------------------------------------------------" << endl;
			cout << "Input invalido, porfavor ingrese 1, 2 o 3." << endl;
			cout << "--------------------------------------------------" << endl;
			cin.clear();
			cin.ignore(500, '\n');
		}
		else {
			presentador->actualizarCantidad(input);
			if (input == 3) {
				menuInicio();
			}
			menuInicio();
		}
	} while (input != 3);	
}

Vista::~Vista()
{
}