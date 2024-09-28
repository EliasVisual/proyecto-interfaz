#include "Interfaz.h"
#include<Windows.h>

int Interfaz::menuPrincipal() {
    int opcion;
    system("cls");
    cout << "*****************************************************" << endl;
    cout << "******** BIENVENIDOS AL HOSPITAL VETERINARIO ********" << endl;
    cout << "*****************************************************" << endl;

    cout << endl;

    cout << "********* MENU PRINCIPAL *********" << endl;
    cout << " 1- Submenu Administracion" << endl;
    cout << " 2- Submenu Control de Citas" << endl;
    cout << " 3- Submenu Busquedas y Listados" << endl;
    cout << "************************************" << endl;
    cout << "Ingrese la opcion:" << endl;
    cin >> opcion;

    return opcion;
}

//case 1
int Interfaz::submenuAdministracion() {
    int opSA;
    system("cls");
    cout << "********* SUBMENU ADMINISTRACION *********" << endl;
    cout << " (1) - Ingresar Especialidad" << endl;
    cout << " (2) - Ingresar Doctor (por especialidad)" << endl;
    cout << " (3) - Ingresar Dueno" << endl;
    cout << " (4) - Ingresar Mascota (por dueno)" << endl;
    cout << " (5) - Regresar al Menu Principal" << endl;
    cout << "************************************" << endl;
    cout << "Ingrese la opcion:" << endl;
    cin >> opSA;
    return opSA;
}

void Interfaz::creaEspecialidad(){
    int canEs;
    string esp;
    Especialidad* espec = NULL;
    ContenedorEspecialidad* COE;
    cout << "1 - Ingresar Especialidad" << endl;
    cout << "Indique la cantidad de especialidades que desea agregar: " << endl;
    cin >> canEs;
    COE = new ContenedorEspecialidad(canEs);

    for (int i = 0; i < canEs; i++) {
        cout << "Ingrese la especialidad #" << i + 1 << ": " << endl;
        cin >> esp;

        espec = new Especialidad(esp);

        if (COE->ingresarEspecialidad(*espec)) {
            cout << "Especialidad ingresada correctamente en el contenedor." << endl;
        }
        else {
            cout << "No se pudo ingresar la especialidad en el contenedor, ya existe." << endl;
        }
    }
    Sleep(4000);
}

void Interfaz::creaDoctor(ContenedorDoctor* COD, ContenedorEspecialidad* COE) {
    string esp,nom,iden;
    int canDoc;
    Doctor* doct = NULL;
    Especialidad* espec = NULL;
    cout << "2 - Ingresar Doctor (por especialidad)" << endl;
    cout << "Digite la especialidad a la que desea agregar el doctor: " << endl;
    cin >> esp;

    if (COE->yaExisteEspecialidad(esp)) {
        cout << "Indique la cantidad de doctores que desea agregar a la especialidad: " << esp << endl;
        cin >> canDoc;

        espec = COE->getEspecialidad(esp);
        COD = new ContenedorDoctor(canDoc);
        espec->setContenedorDoctor(COD);
        for (int i = 0; i < canDoc; i++) {
            cout << "Ingrese el nombre del doctor #" << i + 1 << ": " << endl;
            cin >> nom;
            cout << "Ingrese la identificacion del doctor #" << i + 1 << ": " << endl;
            cin >> iden;

            doct = new Doctor(nom, iden);

            if (COD->ingresarDoctor(*doct)) {
                cout << "Doctor ingresado correctamente en la especialidad " << esp << endl;

            }
            else {
                cout << "No se pudo ingresar el doctor en la especialidad, ya existe o no hay espacio." << endl;
            }
        }
    }
    else {
        cout << "La especialidad no existe." << endl;
    }

}

void Interfaz::creaDueno(ContenedorDueno* CONDUE) {
    int canDue;
    string nom, contacto, pago;
    Dueno* due = NULL;
    cout << "3 - Ingresar Dueno" << endl;
    cout << "Indique la cantidad de duenos que desea agregar: " << endl;
    cin >> canDue;
    CONDUE = new ContenedorDueno(canDue);

    for (int i = 0; i < canDue; i++) {
        cout << "Ingrese el nombre del dueno #" << i + 1 << ": " << endl;
        cin >> nom;

        cout << "Ingrese el ID del dueno #" << i + 1 << ": " << endl;
        cin >> contacto;

        cout << "Ingrese el método de pago del dueño #" << i + 1 << ": " << endl;
        cin >> pago;

        due = new Dueno(nom, contacto, pago);

        if (CONDUE->ingresarDueno(*due)) {
            cout << "Dueno ingresado correctamente al contenedor" << endl;
        }
        else {
            cout << "No se pudo ingresar el dueno en el contenedor, ya existe" << endl;
        }

    }

}

void Interfaz::creaMascota(ContenedorDueno* CONDUE, ContenedorMascota* COM) {
    string contacto,idMascota,esp,raza,sexo,nombre;
    int canMas,edad;
    Dueno* due = NULL;
    Mascota* masc = NULL;
    cout << "4 - Ingresar Mascota (por dueno)" << endl;
    cout << "Ingrese el ID del dueno: " << endl;
    cin >> contacto;

    if (CONDUE->yaExisteDueno(contacto)) {
        cout << "Indique la cantidad de mascotas que desea agregar para el dueno: " << endl;
        cin >> canMas;

        due = CONDUE->getDueno(contacto);
        COM = new ContenedorMascota(canMas);
        due->setContenedora(COM);

        for (int i = 0; i < canMas; i++) {
            cout << "Ingrese los datos de la mascota #" << i + 1 << ":" << endl;

            cout << "Ingrese el ID de la mascota: " << endl;
            cin >> idMascota;

            cout << "Ingrese la especie de la mascota: " << endl;
            cin >> esp;

            cout << "Ingrese la raza de la mascota: " << endl;
            cin >> raza;

            cout << "Ingrese el sexo de la mascota: " << endl;
            cin >> sexo;

            cout << "Ingrese el nombre de la mascota: " << endl;
            cin >> nombre;

            cout << "Ingrese la edad de la mascota: " << endl;
            cin >> edad;

            masc = new Mascota(idMascota, esp, raza, sexo, nombre, edad);

            if (COM->ingresarMascota(*masc)) {
                cout << "Mascota ingresada correctamente al dueno." << endl;
            }
            else {
                cout << "No se pudo ingresar la mascota al dueño, ya existe o no hay espacio." << endl;
            }
        }
    }
    else {
        cout << "El dueno no existe" << endl;
    }
}















//case 2
int Interfaz::submenuControlCitas() {
    int opSCC;
    system("cls");
    cout << "********* SUBMENU CONTROL CITAS *********" << endl;
    cout << " (1) - Sacar Cita" << endl;
    cout << " (2) - Cancelar cita" << endl;
    cout << " (3) - Mostrar Calendario de Citas por Doctor" << endl;
    cout << " (4) - Mostrar Citas por Dueno" << endl;
    cout << " (5) - Regresar al Menu Principal" << endl;
    cout << "************************************" << endl;
    cout << "Ingrese la opcion:" << endl;
    cin >> opSCC;
    return opSCC;
}


//case 3 
int Interfaz::submenuBusqueListados() {
    int opcSBL;
    system("cls");
    cout << "********* SUBMENU BUSQUEDAS Y LISTADOS *********" << endl;
    cout << " (1) - Mostrar listado de Especialidades" << endl;
    cout << " (2) - Mostrar Listado de Doctores por Especialidad" << endl;
    cout << " (3) - Mostrar Dueños con sus Mascotas" << endl;
    cout << " (4) - Mostrar Pacientes por Doctor" << endl;
    cout << " (5) - Regresar al Menú Principal" << endl;
    cout << "************************************" << endl;
    cout << "Ingrese la opcion:" << endl;
    cin >> opcSBL;
    return opcSBL;
}
