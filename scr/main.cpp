#include "../fabrica.h"
#include "../IControladorVideojuegos.h"
#include "../IControladorPartidas.h"
#include "../IControladorUsuarios.h"
#include <iostream>
#include <set>

using namespace std;

bool isNumber(const string& str)
{
    for (char const &c : str) {
        if (isdigit(c) == 0) return false;
    }
    return true;
}

int main(int argc, char** argv) {
    Fabrica *fabrica = Fabrica::getInstancia();
    iControladorVideojuegos *ctrlVideojuegos = fabrica->getControladorVideojuegos();
    iControladorPartidas *ctrlPartidas = fabrica->getControladorPartidas();
    iControladorUsuarios *ctrlUsuarios = fabrica->getControladorUsuarios();
    
    int n = 4;
    while (n != 0) {
        cout << "1: Alta de usuario" << endl;
        cout << "2: Iniciar sesion" << endl;
        cout << "3: Cargar datos de prueba" << endl;
        cout << "0: Salir" << endl;

        string x = "";
        cin >> x;

        isNumber(x) ? n = stoi(x) : n = 4;
        switch(n) {
            case 1: {
                string email = "", contra = "123";
                bool formatoEmailErroneo = true;
                while (formatoEmailErroneo) {
                    cout << "Ingrese el email: " << endl;
                    cin >> email;
                    if (email.find('@') == string::npos || email.find('.') == string::npos) {
                        cout << "El formato del email debe ser example@email.ex" << endl;
                    }else {
                        formatoEmailErroneo = false;
                    }
                }

                cout << "Ingrese la contrasenia: " << endl;
                cin >> contra;

                cout << "Email: " << email << endl << "Contra: " << contra << endl;

                /*try {
                    (*ctrlUsuarios).registrarUsuario(email, contra);
                }catch (Exception e) {}
                */
                cout << "El usuario es desarrollador?" << endl << "1: Si" << endl << "2: No" << endl;

                int n;
                string x = "";
                cin >> x;

                isNumber(x) ? n = stoi(x) : n = 4;
                switch(n) {
                    case 1: {
                        string empresa = "Autonomo";
                        cout << "Ingresa la empresa: " << endl;
                        cin >> empresa;

                        cout << "Empresa: " << empresa << endl;
                        /*try {
                           (*ctrlUsuarios).darEmpresa(empresa);
                        }catch (Exception e) {}
                        */
                    }
                    break;
                    case 2: {
                        string nick = "", descripcion = "";
                        while(nick == "") {
                            cout << "Ingrese el nickname del jugador: " << endl;
                            cin >> nick;
                        }

                        cout << "Ingrese una descripcion: " << endl;
                        cin >> descripcion; 

                        cout << "Nickname: " << nick << endl << "Descripcion: " << descripcion << endl;
                        /*try {
                           (*ctrlUsuarios).darDatosJugador(nick, descripcion);
                        }catch (Exception e) {}
                        */
                    }
                    break;
                    default: {cout << "Ingrese una de las opciones listadas!" << endl;}
                }

                /*try {
                    (*ctrlUsuarios).confirmarAltaUsuario();
                }catch (Exception e) {}
                */
            } 
            break;
            case 2: {
                bool existeUsuario = false;
                while (!existeUsuario) {
                    string email = "", contra = "123";
                    bool formatoEmailErroneo = true;
                    while (formatoEmailErroneo) {
                        cout << "Ingrese el email: " << endl;
                        cin >> email;
                        if (email.find('@') == string::npos || email.find('.') == string::npos) {
                            cout << "El formato del email debe ser example@email.ex" << endl;
                        }else {
                            formatoEmailErroneo = false;
                        }
                    }

                    cout << "Ingrese la contrasenia: " << endl;
                    cin >> contra;

                    cout << "Email: " << email << endl << "Contra: " << contra << endl;

                    existeUsuario = true;/*(*ctrlUsuarios).iniciarSesion(email, contra);

                    if (!existeUsuario) {
                        cout << "El email o la contrasenia son incorrectos" << endl;
                    }*/
                }

                string tipoUser = "j";//(*ctrlUsuarios).getTipoUsuario();

                if (tipoUser == "j") {
                    int n = 9;
                    while (n != 8) {
                        cout << "1: Suscribirse a videojuego" << endl;
                        cout << "2: Asignar puntaje a videojuego" << endl;
                        cout << "3: Iniciar partida" << endl;
                        cout << "4: Abandonar partida multijugador" << endl;
                        cout << "5: Finalizar partida" << endl;
                        cout << "6: Ver información de videojuego" << endl;
                        cout << "7: Modificar fecha del sistema" << endl;
                        cout << "8: Salir" << endl;

                        string x = "";
                        cin >> x;

                        isNumber(x) ? n = stoi(x) : n = 9;
                        switch (n) {
                        case 1: {
                           // set<DtVideojuego*> videojuegos = (*ctrlVideojuegos).obtenerVideojuegos();

                           // set<DtVideojuego*>::iterator it;
                            /*for (it = videojuegos.begin(); it != videojuegos.end(); it++) {
                                cout << (*it) << endl;
                            }

                            bool nombreValido = false;
                            string nombreVideojuego = "";
                            while (!nombreValido) {
                                cout << "Ingrese el nombre del videojuego al que quiere suscribirse: " << endl;
                                cin >> nombreVideojuego;

                                set<DtVideojuego>::iterator it;
                                for (it = videojuegos.begin(); it != videojuegos.end(); it++) {
                                    if ((*it).getNombre() == nombreVideojuego) {
                                        nombreValido = true;
                                        break;
                                    }
                                }
                            }

                            cout << "Ingrese el tipo de suscripcion: " << endl << "1: Vitalicia" << endl << "2: Temporal" << endl;
                            string x = "";
                            cin >> x;

                            isNumber(x) ? n = stoi(x) : n = 3; */

                            //if (n )

                            //(*ctrlVideojuegos).ingresarNombre(metpago, (*ctrlUsuarios).getFechaSistema(), validez, (*ctrlUsuarios).getUsuarioEnSesion(), nombreVideojuego);
                        }
                        break;
                        case 2: {

                        }
                        break;
                        case 3: {

                        }
                        break;
                        case 4: {

                        }
                        break;
                        case 5: {

                        }
                        break;
                        case 6: {

                        }
                        break;
                        case 7: {

                        }
                        break;
                        case 8: {
                            n = 8;
                        }
                        break;
                        default: {cout << "Ingrese una de las opciones listadas!" << endl;}
                        break;
                        }
                    }
                }else if (tipoUser == "d") {
                    int n = 9;
                    while (n != 8) {
                        cout << "1: Agregar categoría" << endl;
                        cout << "2: Publicar videojuego" << endl;
                        cout << "3: Eliminar videojuego" << endl;
                        cout << "4: Seleccionar estadísticas" << endl;
                        cout << "5: Consultar estadísticas" << endl;
                        cout << "6: Ver información de videojuego" << endl;
                        cout << "7: Modificar fecha del sistema" << endl;
                        cout << "8: Salir" << endl;

                        string x = "";
                        cin >> x;

                        isNumber(x) ? n = stoi(x) : n = 9;
                        switch (n) {
                        case 1: {

                        }
                        break;
                        case 2: {

                        }
                        break;
                        case 3: {

                        }
                        break;
                        case 4: {

                        }
                        break;
                        case 5: {

                        }
                        break;
                        case 6: {

                        }
                        break;
                        case 7: {

                        }
                        break;
                        case 8: {
                            n = 8;
                        }
                        break;
                        default: {cout << "Ingrese una de las opciones listadas!" << endl;}
                        break;
                        }
                    }
                }
            }
            break;
            case 3: {cout << "3" << endl;}
            break;
            case 0: {n = 0;}
            break;
            default: {cout << "Ingrese una de las opciones listadas!" << endl;}
            break;
        }

    }
    return 0;
}
