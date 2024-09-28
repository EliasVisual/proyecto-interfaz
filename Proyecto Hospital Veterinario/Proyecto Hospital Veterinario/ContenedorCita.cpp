#include "ContenedorCita.h"



ContenedorCitas::ContenedorCitas(int n){
	vec = new Citas * [n];
	can = 0;
	tam = n;

	for (int i = 0; i < tam; i++)
		vec[i] = NULL;
}

ContenedorCitas:: ~ContenedorCitas(){
	for (int i = 0; i < can; i++) {
		if (vec[i] != NULL)
			delete vec[i];
	}
	delete[] vec;
}

bool ContenedorCitas::yaExisteCita(string cod){
	for (int i = 0; i < can; i++) {
		if (vec[i]!= NULL && vec[i]->getCodigo() == cod)
			return true;
	}
	return false;
}

bool ContenedorCitas::yaExisteCitaHorario(string di, int hor){
	for (int i = 0; i < can; i++) {
		if (vec[i]->getDia() == di && vec[i]->getHora() == hor)
			return true;
	}
	return false;
}


bool ContenedorCitas::ingresarCita(Citas& citn){
	if (yaExisteCita(citn.getCodigo()) == false && yaExisteCitaHorario(citn.getDia(), citn.getHora()) == false) {
		int cantCitas = 0;
		for (int i = 0; i < can; i++) {
			if (vec[i]->getDia() == citn.getDia()) {
				cantCitas++;
			}
		}

		if (cantCitas >= 11) {
			return false;
		}

		if (can < tam) {
			vec[can++] = &citn;
			return true;
		}
		else
			return false;
	}
	else
		return false;

}

int ContenedorCitas::posiCita(string cod) {
	for (int i = 0; i < can; i++)
		if (cod == vec[i]->getCodigo())
			return i;
	return -1;
}

bool ContenedorCitas::eliminarCita(string cod) {
	int posCita;
	if (yaExisteCita(cod) == true) {
		posCita = posiCita(cod);
		for (int i = posCita; i < can; i++)
			vec[i] = vec[i + 1];
		can--;

		return true;
	}
	else
		return false;
}

//Citas* ContenedorCitas::getCita(string cod) {
//	for (int i = 0; i < can; i++) {
//		if()
//	}
//}

string ContenedorCitas::toStringCitaMascota(string idmas) {
	stringstream s;
	for (int i = 0; i < can; i++) {
		if (vec[i]->getMascota()->getIden() == idmas) {
			s << vec[i]->toString() << endl;
		}
	}
	return s.str();
}

string ContenedorCitas::toString(){
	stringstream s;
	for (int i = 0; i < can; i++)
		if (vec[i] != NULL)
			s << vec[i]->toString() << endl;
	return s.str();
}


string ContenedorCitas::toStringMascDoc(string iddoc, string idmasc) {
	stringstream s;
	for (int i = 0; i < can; i++) {
		if (vec[i]->getDoctor()->getIden() == iddoc && vec[i]->getMascota()->getIden() == idmasc)
			s << vec[i]->getMascota()->toString() << endl;
	}
	return s.str();
}

string ContenedorCitas::mostrarHorario(string iden) {
	stringstream s;
	const string diasSemana[6] = { "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado" };

	for (int hora = 8; hora <= 19; hora++) {
		s << hora<<"   ";
		for (int dia = 0; dia < 6; dia++) {
			bool hayCita = false;

			for (int i = 0; i < can; i++) {
				if (vec[i]->getDoctor()->getIden() == iden && vec[i]->getHora() == hora && vec[i]->getDia() == diasSemana[dia]) {
					s << " Cita "; 
					hayCita = true;
					break;
				}
			}

			if (!hayCita) {
				s << " Dispo. "; 
			}
		}
	}

	return s.str();
}


string ContenedorCitas::toStringDueDoc(string idDue) {
	stringstream s;
	for (int i = 0; i < can; i++) {
		if (vec[i]->getDueno()->getContacto() == idDue)
			s << vec[i]->getDoctor()->toString() << endl;
	}
	return s.str();
}

string ContenedorCitas::toStringCitaDueDoc(string idDue, string idDoc) {
	stringstream s;
	for (int i = 0; i < can; i++) {
		if (vec[i]->getDueno()->getContacto() == idDue && vec[i]->getDoctor()->getIden() == idDoc)
			s << vec[i]->toString() << endl;
	}
	return s.str();
}