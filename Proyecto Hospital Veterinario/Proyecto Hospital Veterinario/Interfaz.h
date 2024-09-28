#pragma once
#include "ContenedorEspecialidad.h"
#include "ContenedorDoctor.h"
#include "ContenedorMascota.h"
#include "ContenedorCita.h"
#include "ContenedorDueño.h"

class Interfaz {
public:
	static int menuPrincipal();

	//case 1
	static int submenuAdministracion();
	static void creaEspecialidad();
	static void creaDoctor(ContenedorDoctor*, ContenedorEspecialidad*);
	static void creaDueno(ContenedorDueno*);
	static void creaMascota(ContenedorDueno*, ContenedorMascota*);

	//case 2
	static int submenuControlCitas();


	//case 3 
	static int submenuBusqueListados();




};
