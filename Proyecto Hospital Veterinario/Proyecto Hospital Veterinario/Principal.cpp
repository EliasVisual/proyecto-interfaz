#include <iostream>
#include <string>
#include "ContenedorEspecialidad.h"
#include "ContenedorDoctor.h"
#include "ContenedorMascota.h"
#include "ContenedorCita.h"
#include "ContenedorDueño.h"
#include "Interfaz.h"

using namespace std;

int main() {
    int opcion, opSA, canEs, canDoc, canMas, edad, canDue, opSCC, hora, opcSBL;
    string esp, nom, iden, contacto, pago, idMascota, raza, sexo, nombre, dia, motivo, codigo,cod;
    Especialidad* espec = NULL;
    ContenedorEspecialidad* COE = NULL;
    Doctor* doct = NULL;
    ContenedorDoctor* COD = NULL;
    Dueno* due = NULL;
    Mascota* masc = NULL;
    Citas* cit = NULL;
    ContenedorMascota* COM = NULL;
    ContenedorDueno* CONDUE = NULL;
    ContenedorCitas* COCIT = NULL;
    //Veterinaria* vet = new Veterinaria();

    do {
        opcion = Interfaz::menuPrincipal();

        switch (opcion) {
        case 1: {
            do {
                opSA = Interfaz::submenuAdministracion();

                switch (opSA) {
                case 1: {
                    Interfaz::creaEspecialidad();
                }
                      break;

                case 2: {
                    Interfaz::creaDoctor(COD, COE);

                }
                      break;
                case 3: {
                    Interfaz::creaDueno(CONDUE);

                }
                      break;

                case 4: {
                    Interfaz::creaMascota(CONDUE, COM);

                }
                      break;

                case 5: {
                    cout << "Volviendo al menu principal..." << endl;
                }
                      break;

                default: {
                    cout << "Opción inválida. Por favor, intente de nuevo." << endl;
                }
                       break;
                };

            } while (opSA != 5);

        }
              break;

        case 2: {
            do {
                opSCC = Interfaz::submenuControlCitas();

                switch (opSCC) {

                case 1: {
                    cout << "Ingrese el ID del dueno: " << endl;
                    cin >> contacto;

                    due = CONDUE->getDueno(contacto);

                    if (due == NULL) {
                        cout << "Dueno no encontrado." << endl;
                        break;
                    }

                    if (due->getContenedorMascota() == NULL) {
                        cout << "El dueno no tiene mascotas registradas." << endl;
                        break;
                    }

                    cout << "Mascotas registradas para el dueno " << due->getNombre() << ":" << endl;
                    cout << due->getContenedorMascota()->toString() << endl;

                    cout << "Ingrese el ID de la mascota para la cita: " << endl;
                    cin >> idMascota;

                    masc = due->getContenedorMascota()->getMascota(idMascota);
                    if (masc == NULL) {
                        cout << "Mascota no encontrada." << endl;
                        break;
                    }

                    cout << "Ingrese la especialidad deseada: " << endl;
                    cin >> esp;

                    if (!COE->yaExisteEspecialidad(esp)) {
                        cout << "Especialidad no encontrada." << endl;
                        break;
                    }

                    espec= COE->getEspecialidad(esp);

                    cout << "Doctores disponibles en la especialidad " << esp << ":" << endl;
                    cout << COE->toStringEsp(esp) << endl;

                    cout << "Ingrese el ID del doctor para la cita: " << endl;
                    cin >> iden;

                    doct = COD->getDoctor(iden);

                    if (doct == NULL) {
                        cout << "Doctor no encontrado." << endl;
                        break;
                    }

                    // Mostrar el horario semanal del doctor
                    cout << "Horario disponible del doctor " << doct->getNombre() << ":" << endl;
                    cout << "Hora  | Lunes  | Martes | Miercoles | Jueves | Viernes | Sabado" << endl;
                    cout << "------------------------------------------------------------" << endl;
                   /* string horari = COCIT->mostrarHorario(doct->getIden());
                    cout << horari;*/
                    //cout << COCIT->mostrarHorario(doct->getIden()) << endl;

                    cout << "Ingrese el dia:" << endl;
                    cin >> dia;
                    cout << "Ingrese la hora:" << endl;
                    cin >> hora;
                    cout << "Ingresar el motivo de la cita" << endl;
                    cin >> motivo;
                    cout << "Establezca el codigo de la cita" << endl;
                    cin >> codigo;
                    cout << "El codigo de la cita es: " << codigo << endl;

                    cit = new Citas(codigo, motivo, dia, hora, due, masc, doct, espec);

                    if (COCIT->ingresarCita(*cit)) {
                        cout << "Cita agendada correctamente." << endl;
                    }
                    else {
                        cout << "No se pudo agendar la cita" << endl;
                    }

                }
                      break;

                case 2: {
                    cout << " 2 - Cancelar cita" << endl;
                    cout << "Ingrese el ID del dueño: " << endl;
                    cin >> contacto;
                    cout << "Doctores que tiene una cita agendada con ese dueno" << endl;
                    cout << COCIT->toStringDueDoc(contacto) << endl;                       //revisar método
                    cout << "Ingrese la identificacion del doctor que desea" << endl;
                    cin >> iden;
                    cout << "Estas son las citas que tienen" << endl;
                    cout << COCIT->toStringCitaDueDoc(contacto, iden) << endl;             //revisar método
                    cout << "Ingrese el codigo de la cita que desea cancelar" << endl;
                    cin >> cod;
                    
                    if (COCIT->eliminarCita(cod)) {
                        cout << "Se cancelo correctamente la cita" << endl;
                    }
                    else {
                        cout << "No se pudo concelar la cita" << endl;
                    }

                }
                      break;

                case 3: {
                    cout << " 3 - Mostrar Calendario de Citas por Doctor" << endl;
                    cout << "Ingrese la identificacion del doctor" << endl;
                    cin >> iden;
                    doct = COD->getDoctor(iden);
                    if (doct == NULL) {
                        cout << "Doctor no encontrado" << endl;
                    }
                    else {
                        cout << endl;
                        cout << "Calendario de citas del doctor con ID " << iden << ":" << endl;
                        cout << "Hora  | Lunes  | Martes | Miercoles | Jueves | Viernes | Sabado" << endl;
                        cout << "------------------------------------------------------------" << endl;
                        cout << COCIT->mostrarHorario(doct->getIden()) << endl;
                    }
                }
                      break;

                case 4: {
                    cout << "Ingrese el ID del dueño: " << endl;
                    cin >> contacto;
                    due = CONDUE->getDueno(contacto);

                    if (due == NULL) {
                        cout << "Dueño no encontrado." << endl;
                        break;
                    }

                    if (due->getContenedorMascota() == NULL) {
                        cout << "El dueño no tiene mascotas registradas." << endl;
                        break;
                    }

                    cout << "Mascotas registradas para el dueño " << due->getNombre() << ":" << endl;
                    cout << due->getContenedorMascota()->toString() << endl;

                    cout << "Ingrese el ID de la mascota para ver la cita: " << endl;
                    cin >> idMascota;

                    masc = due->getContenedorMascota()->getMascota(idMascota);
                    if (masc == NULL) {
                        cout << "Mascota no encontrada." << endl;
                        break;
                    }

                    cout << COCIT->toStringCitaMascota(masc->getIden()) << endl;  //revisar método

                }
                      break;

                case 5: {
                    cout << "Volviendo al menu principal..." << endl;

                }
                      break;

                default: {
                    cout << "Opción inválida. Por favor, intente de nuevo." << endl;
                }
                       break;

                };


            } while (opSCC != 5);

        }
              break;

        case 3: {
            do {

                opcSBL = Interfaz::submenuBusqueListados();

                switch (opcSBL) {

                case 1: {
                    cout << " 1 - Mostrar listado de Especialidades" << endl;
                    cout << COE->toStringSoloEsp() << endl;
                }
                      break;
                case 2: {
                    cout << " 2 - Mostrar Listado de Doctores por Especialidad" << endl;
                    cout << COE->toString() << endl;
                }
                      break;
                case 3: {
                    cout << " 3 - Mostrar Dueños con sus Mascotas" << endl;
                    cout << CONDUE->toString() << endl;
                }
                      break;
                case 4: {
                    cout << " 4 - Mostrar Pacientes por Doctor" << endl;
                    cout << "Ingrese el identificador del Doctor" << endl;
                    cin >> iden;
                    cout << "Ingrese el identificador del paciente" << endl;
                    cin >> idMascota;
                    cout << COCIT->toStringMascDoc(iden, idMascota);
                }
                      break;
                case 5: {
                    cout << "Volviendo al menu principal..." << endl;
                }
                      break;

                default: {
                    cout << "Opción inválida. Por favor, intente de nuevo." << endl;
                }
                       break;

                };

            } while (opcSBL != 5);

        }
              break;

        default: {
            cout << "Opción inválida.Por favor, intente de nuevo." << endl;
        }
               break;

        };

    } while (opcion != 4);


	return 0;
}