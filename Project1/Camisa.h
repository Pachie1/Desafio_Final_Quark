#ifndef Camisa_H
#define Camisa_H
#include<iostream>
#include"Prenda.h"

using namespace std;

class Camisa : public Prenda
{
public:
	Camisa() {};
	Camisa(bool calidadV, int cantV, bool tManga, bool tCuello);
	const char* getTipoManga();
	const char* getTipoCuello();
	bool getBoolManga();
	bool getBoolCuello();
	void actualizarManga(bool val);
	void actualizarCuello(bool val);
private:
	bool tManga;
	bool tCuello;
};
#endif