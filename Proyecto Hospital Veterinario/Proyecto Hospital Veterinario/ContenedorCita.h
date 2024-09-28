#pragma once
#include "Citas.h"

class ContenedorCitas {
private:
	Citas** vec;
	int can;
	int tam;

public:

	ContenedorCitas(int);
	virtual ~ContenedorCitas();
	bool yaExisteCita(string);
	bool yaExisteCitaHorario(string, int);
	bool ingresarCita(Citas&);
	int posiCita(string);
	bool eliminarCita(string);
	//Citas* getCita(string);
	string toStringCitaMascota(string);
	string toStringCitaDueDoc(string, string);
	string toStringMascDoc(string, string);
	string toString();
	string mostrarHorario(string);
	string toStringDueDoc(string);
	
};