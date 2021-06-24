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
    
    
 /*   // Ingreso de desarrollador
    ctrlUsuarios->registrarUsuario("desarrollador@mail.com", "123");
	ctrlUsuarios->darEmpresa("EA Sports");
	ctrlUsuarios->confirmarAltaUsuario();
	
	//Ingreso de jugadores
	ctrlUsuarios->registrarUsuario("gamer@mail.com", "123");
	ctrlUsuarios->darDatosJugador("gamer", "");
	ctrlUsuarios->confirmarAltaUsuario();
	
	ctrlUsuarios->registrarUsuario("jugador@mail.com", "123");
	ctrlUsuarios->darDatosJugador("jugador", "");
	ctrlUsuarios->confirmarAltaUsuario();
   
    // Ingreso de Categorias
    ctrlVideojuegos->ingresarCategoria("Xbox One", "plataforma", "");
    ctrlVideojuegos->ingresarCategoria("PS4", "plataforma", "");
    ctrlVideojuegos->ingresarCategoria("E", "genero", "");
	ctrlVideojuegos->ingresarCategoria("Deporte", "genero", "");

	DtCategoria* generoPrueba = NULL;
	DtCategoria* plataformaPrueba = NULL;
	
	ctrlUsuarios->iniciarSesion("desarrollador@mail.com", "123");
	ctrlVideojuegos->setearDatosVideojuego("KingdomRush", "", 1, 2, 7, 14);
	
	vector<DtCategoria*> categoriasDatosAIngresar;
	vector<DtCategoria*> categoriasDatos = ctrlVideojuegos->solicitarCategorias();	
	vector<DtCategoria*>::iterator it;
	for (it = categoriasDatos.begin(); it != categoriasDatos.end(); it++) {
		if ((*it)->getNombre() == "Xbox One") {
			plataformaPrueba = *it;
		}
		if ((*it)->getNombre() == "Deporte") {
		 	generoPrueba = *it;
		}
		if ((*it)->getNombre() == "PS4" || (*it)->getNombre() == "E") {
			categoriasDatosAIngresar.push_back(*it);
		}
	}
	ctrlVideojuegos->asignarGenero(generoPrueba);
	ctrlVideojuegos->asignarPlataforma(plataformaPrueba);
	ctrlVideojuegos->asignarCategorias(categoriasDatosAIngresar);
	ctrlVideojuegos->publicarVideojuego();
	
	
		ctrlUsuarios->setFechaSistema(new DtFechaHora(2021, 6, 1, 9, 0));
		ctrlUsuarios->iniciarSesion("gamer@mail.com", "123");
		ctrlVideojuegos->altaSuscripcion("KingdomRush", "temporal", "paypal", 3);
		
		ctrlUsuarios->iniciarSesion("jugador@mail.com", "123");
		ctrlVideojuegos->altaSuscripcion("KingdomRush", "temporal", "paypal", 3);
		ctrlVideojuegos->asignarPuntajeAVideojuego("KingdomRush", 3);
	
	*/
    bool yaCargados = false;
    int n = 4;
	system("clear");
	cout << "--- Tarea 4 - Programacion 4 ---" << endl;
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
            	system("clear");
                string email = "", contra = "123";
                bool formatoEmailErroneo = true, emailValido = false;
                while (formatoEmailErroneo || !emailValido) {
                    cout << "Ingrese el email: " << endl;
                    cin >> email;
					while (formatoEmailErroneo){
						if (email.find('@') == string::npos || email.find('.') == string::npos) {
							cout << "El formato del email debe ser example@email.ex" << endl;
							cout << "Ingrese el email: " << endl;
                    		cin >> email;
						}else {
							formatoEmailErroneo = false;
						}
					}
                    
                    cout << "Ingrese la contrasenia: " << endl;
                	cin >> contra;

                	//cout << "Email: " << email << endl << "Contra: " << contra << endl;
	
               	 	
                    emailValido = ctrlUsuarios->registrarUsuario(email, contra);
					
                }

                cout << "El usuario es desarrollador?" << endl << "1: Si" << endl << "2: No" << endl;

                int n;
                string x = "";
                cin >> x;
				string empresa = "Autonomo";
				string nick = "", descripcion = "";

                isNumber(x) ? n = stoi(x) : n = 4;
                switch(n) {
                    case 1: {
                    	system("clear");
                        cout << "Ingresa la empresa: " << endl;
                        cin >> empresa;

                        cout << "Empresa: " << empresa << endl;
                           ctrlUsuarios->darEmpresa(empresa);
                        
                    }
                    break;
                    case 2: {
                    	system("clear");
                        bool esValido = false;
                        while(!esValido) {
                            cout << "Ingrese el nickname del jugador: (sin espacios) " << endl;
                            cin >> nick;
                            
							cout << "Ingrese una descripcion: " << endl;
                        	cin >> descripcion; 

                        	cout << "Nickname: " << nick << endl << "Descripcion: " << descripcion << endl;
                        	
							esValido = ctrlUsuarios->darDatosJugador(nick, descripcion);
                        
                        }

                    }
                    break;
                    default: {cout << "Ingrese una de las opciones listadas!" << endl;}
                }

				string confirmar="";
				system("clear");
				cout << "-----~~~~~*****///\\\\\\*****~~~~~-----" << endl;
				cout << "Datos:" << endl;
                cout << "Email: "<< email << endl;
				if(empresa == "Autonomo"){
					cout << "Nickname: "<< nick << endl;
					cout << "Descripcion: " << descripcion << endl;
				}else{
					cout << "Empresa: "<< empresa << endl;
				}
				cout << "Desea confirmar los datos?" << endl << "1: Si" << endl << "2: No" << endl << "-------------------" << endl;
				cin >>confirmar;
				if (confirmar=="1")	{ 
					ctrlUsuarios->confirmarAltaUsuario();
					system("clear");
					cout << "---Usuario Registrado---" << endl;
            	}else{
            		system("clear");
					cout << "---Usuario no Registrado---" << endl;
				}                

            } 
            break;
            case 2: {
            	system("clear");
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

                    existeUsuario = ctrlUsuarios->iniciarSesion(email, contra);

                    if (!existeUsuario) {
                        cout << "El email o la contrasenia son incorrectos" << endl;
                    }
                }

                string tipoUser = ctrlUsuarios->getTipoUsuario();
                
                cout << tipoUser << endl;

                if (tipoUser == "j") {
					system("clear");
					cout << "---Sesion Iniciada---" << endl;
                    int n = 9;
                    while (n != 8) {
                        cout << "1: Suscribirse a videojuego" << endl;
                        cout << "2: Asignar puntaje a videojuego" << endl;
                        cout << "3: Iniciar partida" << endl;
                        cout << "4: Abandonar partida multijugador" << endl;
                        cout << "5: Finalizar partida" << endl;
                        cout << "6: Ver informacion de videojuego" << endl;
                        cout << "7: Modificar fecha del sistema" << endl;
                        cout << "8: Salir" << endl;

                        string x = "";
                        cin >> x;

                        isNumber(x) ? n = stoi(x) : n = 9;
                        switch (n) {
                        case 1: {
                        	system("clear");
                        	string tipo, metPago, nombreVideojuego = "";
                        	int validez;
                        	cout << "Videojuegos a los que NO está suscripto: " << endl;
                           	vector<DtVideojuego> videojuegos = ctrlVideojuegos->solicitarVideojuegos();
							vector<DtVideojuego*> videojuegosSuscripto = ctrlVideojuegos->solicitarVideojuegosSuscripto();
							vector<DtVideojuego> videojuegosNoSus;
                           	vector<DtVideojuego>::iterator it;
                           	vector<DtVideojuego*>::iterator its;
                           	bool imprime;
                            for (it = videojuegos.begin(); it != videojuegos.end(); it++) {
                            	imprime=true;
                            	for (its = videojuegosSuscripto.begin(); its != videojuegosSuscripto.end(); its++) {
                            		if ((*its)->getNombre()==it->getNombre()){
										imprime=false;

									}
								}
								if (imprime){
									cout << &(*it) << endl;
								}
                            }

							//vector<DtVideojuego*>::iterator its;
							cout << "Videojuegos a los que está suscripto: " << endl;
                            //for (its = videojuegosSuscripto.begin(); its != videojuegosSuscripto.end(); it++) {
							for (auto its : videojuegosSuscripto){
                                cout << &(*its) << endl;
                            }
                            bool nombreValido = false;
                            while (!nombreValido) {
                                cout << "Ingrese el nombre del videojuego al que quiere suscribirse: " << endl;
                                cin >> nombreVideojuego;

                                vector<DtVideojuego>::iterator it;
                                for (it = videojuegos.begin(); it != videojuegos.end(); it++) {
                                    if ((*it).getNombre() == nombreVideojuego) {
                                        nombreValido = true;
                                        break;
                                    }
                                }
                                
                            }
                            bool finalizar=false;    
                            bool suscripto=false;
							
							//vector<DtVideojuego*>::iterator it;
                            //for (it = videojuegosSuscripto.begin(); it != videojuegosSuscripto.end(); it++) {
							for (auto it : videojuegosSuscripto) {
                                if ((*it).getNombre() == nombreVideojuego) {
                                    suscripto = true;
                                    break;
                                }
                            }
							
							if (suscripto){
								if (ctrlVideojuegos->esTemporal(nombreVideojuego)){
									cout << "Usted tiene una sucripcion temporal para este videojuego. " << endl << "1: Cancelar la suscripcion. " << endl <<"2: Salir. "<< endl;
									string x = "";
									cin >> x;
									isNumber(x) ? n = stoi(x) : n = 2;
									bool termine = true;
									while (termine){
										switch (n) {
											case 1: {  
												ctrlVideojuegos->cancelarSuscripcion(nombreVideojuego);
												finalizar = true;
												termine = false;
												system("clear");
												cout << "Sucripcion cancelada." << endl;
												break;
											}
											case 2: {  
												finalizar = true;
												termine = false;
												break;
											}
											default:
											cout << "Ingrese un numero valido" << endl;
										}
									}
								}
								else{
									system("clear");
									cout << "Usted tiene una sucripcion vitalicia para este juego. "<< endl;
									finalizar = true;
								}
							}
							//else{
							//	finalizar=true;
							//}

							if (!finalizar){
							
								while (true) {
									cout << "Ingrese el tipo de suscripcion: " << endl << "1: Vitalicia" << endl << "2: Temporal" << endl;
	                            	string x = "";
	                            	cin >> x;
	
	                            	isNumber(x) ? n = stoi(x) : n = 3;
	                            	if (n == 1) {
										tipo = "vitalicia";
										//break;
									}else if (n == 2) {
										tipo = "temporal";
										while (true) {
											cout << "Seleccione la duracion de la suscripcion: " << endl << "1: Un mes" << endl << "2: Tres meses" << endl << "3: Un Anio" << endl;
	                            			cin >> x;	
	                            			
	                            			isNumber(x) ? n = stoi(x) : n = 4;
	                            			if (n == 1) {
	                            				validez = 1;
	                            				break;
											}else if (n == 2) {
												validez = 2;
												break;
											}else if (n == 3) {
												validez = 3;
												break;
											}else {
												cout << "Ingrese una opcion valida!" << endl;
											}
										}
									}else {
										cout << "Ingrese una opcion valida!" << endl;
									}
									while (true) {
										cout << "Ingrese el metodo de pago: " << endl << "1: Tarejeta de credito" << endl << "2: Paypal" << endl; 
										cin >> x;
		
										isNumber(x) ? n = stoi(x) : n = 3;
										if (n == 1) {
											metPago = "tarjeta";
											break;
										}else if (n == 2) {
											metPago = "paypal";
											break;
										}else {
											cout << "Ingrese una opcion valida!" << endl;
										}
									}
	
									ctrlVideojuegos->altaSuscripcion(nombreVideojuego, tipo, metPago, validez);
								
									system("clear");
								
									cout << "Suscripcion registrada correctamente." << endl;
									cout << "\n";
									break;
								}
							}
						}
                        break;
                        case 2: {
                        	system("clear");
                        	int n = 0, puntaje;
							vector<DtVideojuego> videojuegos = ctrlVideojuegos->solicitarVideojuegos();

                           vector<DtVideojuego>::iterator it;
                            for (it = videojuegos.begin(); it != videojuegos.end(); it++) {
                                cout << "Nombre: " << it->getNombre()  << endl << "Descripcion: " << it->getDescripcion() << endl << "****************************" << endl;
                            }

                            bool nombreValido = false;
                            string nombreVideojuego = "";
                            while (!nombreValido) {
                                cout << "Ingrese el nombre del videojuego al que quiere puntuar: " << endl;
                                cin >> nombreVideojuego;

                                vector<DtVideojuego>::iterator it;
                                for (it = videojuegos.begin(); it != videojuegos.end(); it++) {
                                    if ((*it).getNombre() == nombreVideojuego) {
                                        nombreValido = true;
                                        break;
                                    }
                                }
                            }
                            
                            while (true) {
                            	cout << "Ingrese el puntaje que desea darle al videojuego: " << endl;
                            	string x = "";
                            	cin >> x;
	
    	                        isNumber(x) ? n = stoi(x) : n = 3; 
            	                if (n > 0 && n <= 5) {
            	    				puntaje = n;
                	            	break;
								}else {
									cout << "Ingrese un puntaje entre 1 y 5" << endl;
								}
							}
            				
            				ctrlVideojuegos->asignarPuntajeAVideojuego(nombreVideojuego, puntaje);
            				system("clear");
            				
            				
                        }
                        break;
                        case 3: {
                        	system("clear");
                        	int n;
        					string emailUsuario = ctrlUsuarios->getUsuarioEnSesion();  
        					//cout << emailUsuario << endl;
							vector<DtVideojuego*> videojuegos = ctrlUsuarios->obtenerVideojuegosJugador(emailUsuario);
							cout << "Videojuegos a los que esta suscrito: " << endl;
	                        vector<DtVideojuego*>::iterator it;
                            for (it = videojuegos.begin(); it != videojuegos.end(); it++) {
                                cout << (*it)->getNombre() << endl;
                            }

                            bool nombreValido = false;
                            string nombreVideojuego = "";
                            while (!nombreValido) {
                                cout << "Ingrese el nombre del videojuego para la partida: " << endl;
                                cin >> nombreVideojuego;

                            	vector<DtVideojuego*>::iterator it;
                                for (it = videojuegos.begin(); it != videojuegos.end(); it++) {
                                    if ((*it)->getNombre() == nombreVideojuego) {
                                        nombreValido = true;
                                        break;
                                    }
                                }
                            } 
                            
                            ctrlPartidas->SeleccionarVideojuego(nombreVideojuego);
							 
                            cout << "Desea continuar una partida o iniciar una nueva?" << endl << "1: Continuar" << endl << "2: Iniciar nueva partida" << endl;
                            string x = "";
                            
                            while (true) {
                            	cin >> x;
	
    	                    	isNumber(x) ? n = stoi(x) : n = 3; 
    	                    	if (n == 1) {
    	                    		vector<DtPartida*> partidas = ctrlPartidas->ObtenerAnteriores();
    	                    		
    	                    		vector<DtPartida*>::iterator it;
    	                    		for (it = partidas.begin(); it != partidas.end(); it++) {
    	                    			DtPartidaMultijugador* pm = dynamic_cast<DtPartidaMultijugador*>(*it);
										DtPartidaIndividual* pi = dynamic_cast<DtPartidaIndividual*>(*it);
								
										if (pm != NULL) {cout << &(*pm) << endl;}
										else if (pi != NULL) {cout << &(*pi) << endl;}
									}
									
									cout << "Ingrese el id de la partida que desea continuar: " << endl;
									bool esValido = false;
									while (!esValido) {
										cin >> x;
										
										isNumber(x) ? n = stoi(x) : n = -1;
										if (n != -1) {
											vector<DtPartida*>::iterator it;
											for (it = partidas.begin(); it != partidas.end(); it++) {
    	                    					if ((*it)->getIdPartida() == n) {
    	                    						esValido = true;
												}
											}
										}
										
										if (!esValido) {
											cout << "Ingrese un id valido" << endl;
										}
									}	
									
									ctrlPartidas->seleccionarPartida(n);	
								} else if (n == 2) {
									cout << "Nueva partida individual o multijugador:" << endl << "1: Individual" << endl << "2: Multijugador" << endl;
									
									while (true) {
										cin >> x;
									
										isNumber(x) ? n = stoi(x) : n = 3;
										if (n == 1) {
											ctrlPartidas->setTipoPartida("individual");
											break;
										}else if (n == 2) {
											ctrlPartidas->setTipoPartida("multijugador");
											cout << "La partida sera transmitida en vivo?" << endl << "1: Si" << endl << "2: No" << endl;
											
											while (true) {
												cin >> x;
										
												isNumber(x) ? n = stoi(x) : n = 3;
												if (n == 1) {
													ctrlPartidas->Transmitida(true);
													break;
												}else if (n == 2) {
													ctrlPartidas->Transmitida(false);
													break;
												}else {
													cout << "Ingrese una opcion valida!" << endl;
												}
											}
											
											vector<DtJugador> jugadores = ctrlPartidas->obtenerJugadoresSuscriptos(); 
											
											vector<DtJugador>::iterator it;
                            				for (it = jugadores.begin(); it != jugadores.end(); it++) {
                                				cout << it->getNickname() << endl;
                            				}
                            				
                            				vector<string> jugadoresQParticipan;
                            				
                            				while (true) {
                            					cout << "1: Agregar un jugador" << endl << "2: Terminar" << endl;
                            					cin >> x;
									
												isNumber(x) ? n = stoi(x) : n = 3;
                            					if (n == 1) {
                            						bool esValido = false;
                            						cout << "Ingrese el Nickname: " << endl;
                            						cin >> x;
                            						
													vector<DtJugador>::iterator it;
													for (it = jugadores.begin(); it != jugadores.end(); it++) {
    	                    							if (it->getNickname() == x) {
    	                    								jugadoresQParticipan.push_back(x);
    	                    								esValido = true;
														}
													}
												
													if (!esValido) {
														cout << "Nickname invalido" << endl;
													}
												}else if (n == 2) {
													break;
												}else {
													cout << "Ingrese una opcion valida!" << endl;
												}
											}
											
											ctrlPartidas->seleccionarJugadores(jugadoresQParticipan); 
											break;
										}else {
											cout << "Ingrese una opcion valida" << endl;	
										}
									}
								}else { 
									cout << "Ingrese una opcion valida" << endl;
								}
								break;
							}
							
							ctrlPartidas->iniciarPartida();
                        }
                        break;
                        case 4: {
                        	system("clear");
							vector<DtPartida*> partidas = ctrlPartidas->ObtenerPartidasActivas();
							
							vector<DtPartida*>::iterator it;
							for (it = partidas.begin(); it != partidas.end(); it++) {
								DtPartidaMultijugador* pm = dynamic_cast<DtPartidaMultijugador*>(*it);
								DtPartidaIndividual* pi = dynamic_cast<DtPartidaIndividual*>(*it);
								
								if (pm != NULL) {cout << &(*pm) << endl;}
								else if (pi != NULL) {cout << &(*pi) << endl;}
							}
							cout << "Ingrese el id de la partida a abandonar: " << endl;
							bool esValido = false;
							string x;
							int n;
							while (!esValido) {
								cin >> x;
										
								isNumber(x) ? n = stoi(x) : n = -1;
								if (n != -1) {
									vector<DtPartida*>::iterator it;
									for (it = partidas.begin(); it != partidas.end(); it++) {
    	                   		 		if ((*it)->getIdPartida() == n) {
    	                    				esValido = true;
										}
									}
								}
								
								if (!esValido) { cout << "Ingrese un id valido!" << endl; }
							}
							
							ctrlPartidas->AbandonarPartidaActiva(n);
							system("clear");
							cout << "Partida abandonada." << endl;
                        }
                        break;
                        case 5: {
                        	system("clear");
							vector<DtPartida*> partidas = ctrlPartidas->ListarPartidasNoFinalizadas();
							
							vector<DtPartida*>::iterator it;
							for (it = partidas.begin(); it != partidas.end(); it++) {
								DtPartidaMultijugador* pm = dynamic_cast<DtPartidaMultijugador*>(*it);
								DtPartidaIndividual* pi = dynamic_cast<DtPartidaIndividual*>(*it);
								
								if (pm != NULL) {cout << &(*pm) << endl;}
								else if (pi != NULL) {cout << &(*pi) << endl;}
								
							}
							
							cout << "Ingrese el id de la partida a finalizar: " << endl;
							bool esValido = false;
							string x;
							int n;
							while (!esValido) {
								cin >> x;
										
								isNumber(x) ? n = stoi(x) : n = -1;
								if (n != -1) {
									vector<DtPartida*>::iterator it;
									for (it = partidas.begin(); it != partidas.end(); it++) {
    	                   		 		if ((*it)->getIdPartida() == n) {
    	                    				esValido = true;
										}
									}
								}
								
								if (!esValido) { cout << "Ingrese un id valido!" << endl; }
							}
							
							ctrlPartidas->ingreseIdPartida(n);
							ctrlPartidas->finalizarPartida();
                        }
                        break;
                        case 6: {
                        	system("clear");
							vector<DtVideojuego> videojuegos = ctrlVideojuegos->solicitarVideojuegos();

                           	vector<DtVideojuego>::iterator it;
                            for (it = videojuegos.begin(); it != videojuegos.end(); it++) {
                                cout << it->getNombre() << endl;
                            }

                            bool nombreValido = false;
                            string nombreVideojuego = "";
                            while (!nombreValido) {
                                cout << endl << "Ingrese el nombre del videojuego que quiere consultar: " << endl;
                                cin >> nombreVideojuego;

                                vector<DtVideojuego>::iterator it;
                                for (it = videojuegos.begin(); it != videojuegos.end(); it++) {
                                    if ((*it).getNombre() == nombreVideojuego) {
                                    	cout << &(*it) << endl;
                                        nombreValido = true;
                                        break;
                                    }
                                }
                            }
                        }
                        break;
                        case 7: {
                        	if (false){//ctrlPartidas->hayActivas()) {
                        		cout << "No se puede cambiar la fecha del sistema mientras hay partidas activas!" << endl;
							}else {
								system("clear");
                        		int dia, mes, anio, hora, minuto;
                        		string x = "";
                        		int n;
                        	
                        		cout<< "Ingrese el anio:" << endl;
                        		while (true) {
                            		cin >> x;
		
    		                        isNumber(x) ? n = stoi(x) : n = -1;
            	            		if (n < 0) {
										cout << "Ingrese un anio valido" << endl;
									}else {
										anio = n;
										break;
									}
								}
							
								cout<< "Ingrese el mes:" << endl;
								while (true) {
                            		cin >> x;
		
    		                        isNumber(x) ? n = stoi(x) : n = -1;
            	            		if (n < 1 || n > 12) {
										cout << "Ingrese un mes valido" << endl;
									}else {
										mes = n;
										break;
									}
								}
							
								cout<< "Ingrese el dia:" << endl;
								while (true) {
                    	        	cin >> x;
		
    		                        isNumber(x) ? n = stoi(x) : n = -1;
    	                    		if (n < 1 || n > 31) {
										cout << "Ingrese un dia valido" << endl;
									}else {
										dia = n;
										break;
									}
								}
							
								cout<< "Ingrese la hora:" << endl;
								while (true) {
                            		cin >> x;
	
    	                       		isNumber(x) ? n = stoi(x) : n = -1;
                        			if (n < 0 || n > 23) {
										cout << "Ingrese una hora valido" << endl;
									}else {
										hora = n;
										break;
									}
								}
								
								cout<< "Ingrese el minuto:" << endl;
								while (true) {
               		             	cin >> x;
		
    		                        isNumber(x) ? n = stoi(x) : n = -1;
            	            		if (n < 0 || n > 59) {
										cout << "Ingrese una hora valido" << endl;
									}else {
										minuto = n;
										break;
									}
								}
                	        	
                    	    	cout << to_string(dia) + "/" + to_string(mes) + "/" + to_string(anio) + " - " + to_string(hora) + ":" + to_string(minuto) << endl;
                        		DtFechaHora *nuevaFecha = new DtFechaHora(anio, mes, dia, hora, minuto);
								ctrlUsuarios->setFechaSistema(nuevaFecha);
							}	
                        }
                        break;
                        case 8: {
                            n = 8;
                            system("clear");
                        }
                        break;
                        default: {cout << "Ingrese una de las opciones listadas!" << endl;}
                        break;
                        }
                    }
                }else if (tipoUser == "d") {
                    int n = 9;
					system("clear");
					cout << "---Sesion Iniciada---" << endl;
                    while (n != 8) {
                        cout << "1: Agregar categoria" << endl;
                        cout << "2: Publicar videojuego" << endl;
                        cout << "3: Eliminar videojuego" << endl;
                        cout << "4: Seleccionar estadisticas" << endl;
                        cout << "5: Consultar estadisticas" << endl;
                        cout << "6: Ver informacion de videojuego" << endl;
                        cout << "7: Modificar fecha del sistema" << endl;
                        cout << "8: Salir" << endl;

                        string x = "";
                        cin >> x;

                        isNumber(x) ? n = stoi(x) : n = 9;
                        switch (n) {
                        case 1: {
                        	system("clear");
							string nombre, desc, tipo, seguro;
							vector<DtCategoria*> cat = ctrlVideojuegos->solicitarCategorias();
							vector<DtCategoria*>::iterator it;
							for (it = cat.begin(); it != cat.end(); it++){
								cout << (*it)->getNombre() << endl << "--------------------" << endl;
							}
		                	cout << "Ingrese el nombre de la categoria:" << endl;
		                	cin >> nombre;
		                	
		                	cout << "Ingrese la descripcion de la categoria:" << endl;
		                	cin >> desc;
		                	
		                	cout << "Ingrese el tipo de la categoria: (Tipos: genero, plataforma, otro)" << endl;
		                	cin >> tipo;
		                	
		                	cout << "Nombre: " << nombre << endl << "Descripcion: " << desc << endl << "Tipo: " << tipo << endl;
		                	
		                	cout << "Esta seguro que quiere ingresar esta categoria?" << endl << "1: Si" << endl << "2: No" << endl;
		                	cin >> seguro;
		                	int n;
		                	
		                	isNumber(x) ? n = stoi(x) : n = -1;
		                	if (n == 1) {
		                		ctrlVideojuegos->ingresarCategoria(nombre, tipo, desc);
							}else if (n == 2) {
								cout << "Datos no ingresados" << endl;
							}else {
								cout << "Opcion invalida";
							}
		                
                        }
                        break;
                        case 2: {
                        	system("clear");
							string nombre, descripcion, precioMes, precioTri, precioAnio, precioVit;
							int n;
							bool nombreBien = false;
							cout << "Cual es el nombre del videojuego? (ingrese un nombre sin espacios por favor)" << endl;
							cin >> nombre;
							
							cout << "Ingrese una descripcion:" << endl;
							cin >> descripcion;
							
							cout << "Ingrese el precio por un mes de suscripcion:" << endl;
							while (true) {
								cin >> precioMes;
							
								isNumber(precioMes) ? n = stoi(precioMes) : n = -1;
								if (n < 0) {
									cout << "Ingrese un precio valido!" << endl;
								}else {
									break;
								}
							}
							
							cout << "Ingrese el precio por tres meses de suscripcion:" << endl;
							while (true) {
								cin >> precioTri;
							
								isNumber(precioTri) ? n = stoi(precioTri) : n = -1;
								if (n < 0) {
									cout << "Ingrese un precio valido!" << endl;
								}else {
									break;
								}
							}
							
							cout << "Ingrese el precio por un anio de suscripcion:" << endl;
							while (true) {
								cin >> precioAnio;
							
								isNumber(precioTri) ? n = stoi(precioTri) : n = -1;
								if (n < 0) {
									cout << "Ingrese un precio valido!" << endl;
								}else {
									break;
								}
							}
							
							cout << "Ingrese el precio por una suscripcion vitalicia:" << endl;
							while (true) {
								cin >> precioVit;
							
								isNumber(precioVit) ? n = stoi(precioVit) : n = -1;
								if (n < 0) {
									cout << "Ingrese un precio valido!" << endl;
								}else {
									break;
								}
							}
							
							cout << "--------------------" << endl;
							ctrlVideojuegos->setearDatosVideojuego(nombre, descripcion, stof(precioMes), stof(precioTri), stof(precioAnio), stof(precioVit));
							
							vector<DtCategoria*> categorias = ctrlVideojuegos->solicitarCategorias();
							
							vector<DtCategoria*>::iterator it;
							for (it = categorias.begin(); it != categorias.end(); it++) {
								if ((*it)->getTipo() == "genero") {
									cout << (*it)->getNombre() << endl;
								}
							}
							bool esValido = false;
							string genero, plataforma;
							cout << "Seleccione el genero principal del videojuego:" << endl;
							DtCategoria* gen = NULL;
							DtCategoria* plat = NULL;
							while (!esValido) {
								cin >> genero;
							
								for (it = categorias.begin(); it != categorias.end(); it++) {
									if ((*it)->getTipo() == "genero" && (*it)->getNombre() == genero) {
										esValido = true;
										gen = *it;
										break;
									}
								}
								
								if (!esValido) {
									cout << "Ingrese un genero valido!" << endl;
								}
							}
							cout << "--------------------" << endl;
							
							ctrlVideojuegos->asignarGenero(gen);
							
							for (it = categorias.begin(); it != categorias.end(); it++) {
								if ((*it)->getTipo() == "plataforma") {
									cout << (*it)->getNombre() << endl;
								}
							}
							
							esValido = false;
							cout << "Seleccione la plataforma de estreno del videojuego:" << endl;
							while (!esValido) {
								cin >> plataforma;
							
								for (it = categorias.begin(); it != categorias.end(); it++) {
									if ((*it)->getTipo() == "plataforma" && (*it)->getNombre() == plataforma) {
										esValido = true;
										plat = *it;
										break;
									}
								}
								
								if (!esValido) {
									cout << "Ingrese una plataforma valida!" << endl;
								}
							}
							
							ctrlVideojuegos->asignarPlataforma(plat);
							

							for (it = categorias.begin(); it != categorias.end(); it++) {
									cout << (*it) << endl;
							}
							
							esValido = false;
							bool salir = false;
							vector<DtCategoria*> cats;
							string cat;
							while (n != 2) {
								cout << "Agregar otra categoria:" << endl << "1: Si" << endl << "2: No" << endl;
								cin >> cat;
							
								isNumber(cat) ? n = stoi(cat) : n = -1;
								if (n == 1) {
									cout << "Ingrese el nombre: " << endl;
									cin >> cat;
									
									for (it = categorias.begin(); it != categorias.end(); it++) {
										if ((*it)->getNombre() == cat) {
											esValido = true;
											cats.push_back(*it);
											break;
										}	
									}	
								}else if (n != 2) {
									cout << "Ingrese una categoria valida!" << endl;
								}
							}
							ctrlVideojuegos->asignarCategorias(cats);

							vector<DtCategoria*>::iterator itn;
							cout << "voy a listar las categorias:" << endl;
							for (itn = categorias.begin(); itn != categorias.end(); itn++) {
									cout << (*itn) << endl;
							}
							n = 0;
							cout << "-----~~~~~*****///\\\\\\*****~~~~~-----" <<endl
							<< "Datos:" << endl
							<< "Nombre: " << nombre << endl
							<< "Descripcion: " << descripcion << endl
							<< "-----Costo Suscripciones-----" << endl
							<< "Suscripcion por 1 mes: " << precioMes << endl
							<< "Suscripcion por 3 meses: " << precioTri << endl
							<< "Suscripcion por 12 meses: " << precioAnio << endl
							<< "Suscripcion vitalicia: " << precioVit << endl
							<< "-----Categorias-----" << endl
							<< &(*gen) << endl
							<< &(*plat) << endl;
							for (it = cats.begin(); it != cats.end(); it++){
								cout << (*it) << endl;
							}
							cout << "Esta seguro de dar de alta al nuevo videojuego?" << endl
							<< "1: Si" << endl << "2: Cancelar" << endl;
							cin >> n;
							if ( n == 1){
								ctrlVideojuegos->publicarVideojuego();
								system("clear");
								cout << "***Videojuego ingresado***" << endl;
							}else{
								system("clear");
								cout << "***Videojuego no ingresado***" << endl;
							}
                        }
                        break;
                        case 3: {
                        	system("clear");
                        	vector<string> juegos = ctrlVideojuegos->obtenerVideojuegosDesFinalizados();
                        	
                        	cout << "Los videojuegos que se muestran a continuacion tienen todas sus partidas finalizadas." << endl;
							
							vector<string>::iterator it;
							for (it = juegos.begin(); it != juegos.end(); it++) {	
								cout << *it << endl;
							}
							cout << "\n";
						
							cout << "Ingrese el nombre del videojuego a eliminar: " << endl;
							bool esValido = false;
							string nombre;
							while (!esValido) {
								cin >> nombre;
								
								vector<string>::iterator it;
								for (it = juegos.begin(); it != juegos.end(); it++) {
									if (*it == nombre) {
										esValido = true;
										break;
									}
								}
								
								if (!esValido) {
									cout << "Ingrese un nombre valido!" << endl;
								}
							}
							
							
							cout << "Esta seguro que quiere eliminar " + nombre + "?" << endl << "1: Si" << endl << "2: Cancelar" << endl;
							string x;
							int n;
							while (true) {
								cin >> x;
							
								isNumber(x) ? n = stoi(x) : n = -1;
								if (n == 1) {
									ctrlVideojuegos->eliminarVideojuego(nombre);
									ctrlVideojuegos->confirmarEliminacion();  
									break;
								}else if (n != 2) {
									cout << "Ingrese una opcion valida!" << endl;
								}
							}

                        }
                        break;
                        case 4: {
                        	system("clear");
                        		string x;
							int n;
							vector<DtEstadistica> est;
							vector<DtEstadistica> estadisticas = ctrlVideojuegos->listarEstadisticas();
							
							vector<DtEstadistica>::iterator it;
							for (it = estadisticas.begin(); it != estadisticas.end(); it++){
								cout << &it << endl;
							}
							
							bool esValido = false, salir = false;
							while (!salir) {
								cout << "Ingrese el nombre de la estadistica:" << endl;
								cin >> x;
							
								for (it = estadisticas.begin(); it != estadisticas.end(); it++){
									if (it->getNombre() == x) {
										esValido = true;
										est.push_back(*it);
										break;
									}
								}
								
								if (!esValido) {cout << "Ingrese un nombre valido!" << endl;}
								
								cout << "1: Seleccionar otra estadistica" << endl << "2: Salir" << endl;
								cin >> x;
								
								isNumber(x) ? n = stoi(x) : n = -1;
								if (n == 2) {
									salir = true;
								}else if (n != 1) {
									cout << "Ingrese una opcion valida!" << endl;
								}
							}
							
							ctrlVideojuegos->seleccionarEstadisticas(est); 
							
                        }
                        break;
                        case 5: {
                        	system("clear");
                        	vector<DtVideojuego> juegos = ctrlVideojuegos->obtenerVideojuegosDes();
							
							vector<DtVideojuego>::iterator it;
							for (it = juegos.begin(); it != juegos.end(); it++) {
								cout << &it << endl;
							}
							
							cout << "Seleccione el videojuego: " << endl;
							bool esValido = false;
							string nombre;
							while (!esValido) {
								cin >> nombre;
								

								for (it = juegos.begin(); it != juegos.end(); it++) {
									if (it->getNombre() == nombre) {
										esValido = true;
										break;
									}
								}
								
								if (!esValido) {
									cout << "Ingrese un nombre valido!" << endl;
								}
							}
							
							vector<string> result = ctrlVideojuegos->consultarEstadisticas(nombre);
							
							vector<string>::iterator its;
							for (its = result.begin(); its != result.end(); its++){
								cout << *its << endl;
							}
                        }
                        break;
                        case 6: {
                        	system("clear");
                        	vector<DtVideojuego> videojuegos = ctrlVideojuegos->solicitarVideojuegos();

                           	vector<DtVideojuego>::iterator it;
                            for (it = videojuegos.begin(); it != videojuegos.end(); it++) {
                                cout << it->getNombre() << endl;
                            }

                            bool nombreValido = false;
                            string nombreVideojuego = "";
                            while (!nombreValido) {
                                cout << "Ingrese el nombre del videojuego: " << endl;
                                cin >> nombreVideojuego;

                                vector<DtVideojuego>::iterator it;
                                for (it = videojuegos.begin(); it != videojuegos.end(); it++) {
                                    if ((*it).getNombre() == nombreVideojuego) {
                                    	cout << &(*it) << endl;
                                        nombreValido = true;
                                        break;
                                    }
                                }
                                
                        	}
                    	}	
                        break;
                        case 7: {
                        	system("clear");
							int dia, mes, anio, hora, minuto;
                        	string x = "";
                        	int n;
                        	
                        	cout<< "Ingrese el anio:" << endl;
                        	while (true) {
                            	cin >> x;
	
    	                        isNumber(x) ? n = stoi(x) : n = -1;
                        		if (n < 0) {
									cout << "Ingrese un anio valido" << endl;
								}else {
									anio = n;
									break;
								}
							}
							
							cout<< "Ingrese el mes:" << endl;
							while (true) {
                            	cin >> x;
	
    	                        isNumber(x) ? n = stoi(x) : n = -1;
                        		if (n < 1 || n > 12) {
									cout << "Ingrese un mes valido" << endl;
								}else {
									mes = n;
									break;
								}
							}
							
							cout<< "Ingrese el dia:" << endl;
							while (true) {
                            	cin >> x;
	
    	                        isNumber(x) ? n = stoi(x) : n = -1;
                        		if (n < 1 || n > 31) {
									cout << "Ingrese un dia valido" << endl;
								}else {
									dia = n;
									break;
								}
							}
							
							cout<< "Ingrese la hora:" << endl;
							while (true) {
                            	cin >> x;
	
    	                        isNumber(x) ? n = stoi(x) : n = -1;
                        		if (n < 0 || n > 23) {
									cout << "Ingrese una hora valido" << endl;
								}else {
									hora = n;
									break;
								}
							}
							
							cout<< "Ingrese el minuto:" << endl;
							while (true) {
                            	cin >> x;
	
    	                        isNumber(x) ? n = stoi(x) : n = -1;
                        		if (n < 0 || n > 59) {
									cout << "Ingrese una hora valido" << endl;
								}else {
									minuto = n;
									break;
								}
							}
                        	
                        	cout << to_string(dia) + "/" + to_string(mes) + "/" + to_string(anio) + " - " + to_string(hora) + ":" + to_string(minuto) << endl;
                        	DtFechaHora *fechaSist = new DtFechaHora(anio, mes, dia, hora, minuto);
							ctrlUsuarios->setFechaSistema(fechaSist);
								
                        }
                        break;
                        case 8: {
                            n = 8;
                            system("clear");
                        }
                        break;
                        default: {cout << "Ingrese una de las opciones listadas!" << endl;}
                        break;
                        }
                    }
                }
            }
            break;
            case 3: {
				if (!yaCargados){
					system("clear");
					DtCategoria* gen = NULL; 
					DtCategoria* plat = NULL;
					vector<string> jugadoresQParticipan;
					
					//Abandona partida multijugador(*ctrlUsuarios).iniciarSesion("ea@mail.com", "123");
					
					//Ingreso de desarrolladores
					ctrlUsuarios->registrarUsuario("ironhide@mail.com", "123");
					ctrlUsuarios->darEmpresa("Ironhide Game Studio");
					ctrlUsuarios->confirmarAltaUsuario();
					
					ctrlUsuarios->registrarUsuario("epic@mail.com", "123");
					ctrlUsuarios->darEmpresa("Epic Games");
					ctrlUsuarios->confirmarAltaUsuario();
					
					ctrlUsuarios->registrarUsuario("mojang@mail.com", "123");
					ctrlUsuarios->darEmpresa("Mojang Studios");
					ctrlUsuarios->confirmarAltaUsuario();
					
					ctrlUsuarios->registrarUsuario("ea@mail.com", "123");
					ctrlUsuarios->darEmpresa("EA Sports");
					ctrlUsuarios->confirmarAltaUsuario();
					
					//Ingreso de jugadores
					ctrlUsuarios->registrarUsuario("gamer@mail.com", "123");
					ctrlUsuarios->darDatosJugador("gamer", "");
					ctrlUsuarios->confirmarAltaUsuario();
					
					ctrlUsuarios->registrarUsuario("ari@mail.com", "123");
					ctrlUsuarios->darDatosJugador("ari", "");
					ctrlUsuarios->confirmarAltaUsuario();
					
					ctrlUsuarios->registrarUsuario("ibai@mail.com", "123");
					ctrlUsuarios->darDatosJugador("ibai", "");
					ctrlUsuarios->confirmarAltaUsuario();
					
					ctrlUsuarios->registrarUsuario("camila@mail.com", "123");
					ctrlUsuarios->darDatosJugador("camila", "");
					ctrlUsuarios->confirmarAltaUsuario();
					
					//Ingreso de categorias
					ctrlVideojuegos->ingresarCategoria("PC", "plataforma", "");
					ctrlVideojuegos->ingresarCategoria("PS4", "plataforma", "");
					ctrlVideojuegos->ingresarCategoria("Xbox One", "plataforma", "");
					ctrlVideojuegos->ingresarCategoria("Deporte", "genero", "");
					ctrlVideojuegos->ingresarCategoria("Supervivencia", "genero", "");
					ctrlVideojuegos->ingresarCategoria("Estrategia", "genero", "");
					ctrlVideojuegos->ingresarCategoria("Teen", "otro", "Su contenido esta dirigido a jovenes de 13 anios en adelante");
					ctrlVideojuegos->ingresarCategoria("E", "otro", "Su contenido esta dirigido para todo publico");
					ctrlVideojuegos->ingresarCategoria("Accion", "genero", "");
					ctrlVideojuegos->ingresarCategoria("Aventura", "genero", "");
					ctrlVideojuegos->ingresarCategoria("Switch", "plataforma", "");
					ctrlVideojuegos->ingresarCategoria("Xbox X", "plataforma", "");
					ctrlVideojuegos->ingresarCategoria("PS5", "plataforma", "");
					
					//Ingreso de videojuegos
					vector<DtCategoria*> cats;
					ctrlUsuarios->iniciarSesion("ironhide@mail.com", "123");
					ctrlVideojuegos->setearDatosVideojuego("KingdomRush", "", 1, 2, 7, 14);
					vector<DtCategoria*> categorias1 = ctrlVideojuegos->solicitarCategorias();	
					vector<DtCategoria*>::iterator it;
					for (it = categorias1.begin(); it != categorias1.end(); it++) {
						if ((*it)->getNombre() == "PC") {
							plat = *it;
						}
						if ((*it)->getNombre() == "Estrategia") {
							gen = *it;
						}
						if ((*it)->getNombre() == "PS4" || (*it)->getNombre() == "E") {
							cats.push_back(*it);
						}
					}
					ctrlVideojuegos->asignarGenero(gen);
					ctrlVideojuegos->asignarPlataforma(plat);
					ctrlVideojuegos->asignarCategorias(cats);
					ctrlVideojuegos->publicarVideojuego();
					cats.clear();
					
					/**************************************************************************/
					
					ctrlUsuarios->iniciarSesion("epic@mail.com", "123");
					ctrlVideojuegos->setearDatosVideojuego("Fortnite", "", 3, 8, 30, 60);
					vector<DtCategoria*> categorias2 = ctrlVideojuegos->solicitarCategorias();	
		//			vector<DtCategoria*>::iterator it;
					for (it = categorias2.begin(); it != categorias2.end(); it++) {
						if ((*it)->getNombre() == "PC") {
							plat = *it;
						}
						if ((*it)->getNombre() == "Supervivencia") {
							gen = *it;
						}
						if ((*it)->getNombre() == "PS4" || (*it)->getNombre() == "Xbox One" || (*it)->getNombre() == "Teen") {
							cats.push_back(*it);
						}
					}
					ctrlVideojuegos->asignarGenero(gen);
					ctrlVideojuegos->asignarPlataforma(plat);
					ctrlVideojuegos->asignarCategorias(cats);
					ctrlVideojuegos->publicarVideojuego();
					cats.clear();
					
					/**************************************************************************/
					
					ctrlUsuarios->iniciarSesion("mojang@mail.com", "123");
					ctrlVideojuegos->setearDatosVideojuego("Minecraft", "", 2, 5, 20, 40);
					vector<DtCategoria*> categorias3 = ctrlVideojuegos->solicitarCategorias();	
		//			vector<DtCategoria>::iterator it;
					for (it = categorias3.begin(); it != categorias3.end(); it++) {
						if ((*it)->getNombre() == "PC") {
							plat = *it;
						}
						if ((*it)->getNombre() == "Supervivencia") {
							gen = *it;
						}
						if ((*it)->getNombre() == "E") {
							cats.push_back(*it);
						}
					}
					ctrlVideojuegos->asignarGenero(gen);
					ctrlVideojuegos->asignarPlataforma(plat);
					ctrlVideojuegos->asignarCategorias(cats);
					ctrlVideojuegos->publicarVideojuego();
					cats.clear();
					
					/**************************************************************************/
					
					ctrlUsuarios->iniciarSesion("ea@mail.com", "123");
					ctrlVideojuegos->setearDatosVideojuego("FIFA_21", "", 3, 8, 28, 50);
					vector<DtCategoria*> categorias4 = ctrlVideojuegos->solicitarCategorias();	
		//			vector<DtCategoria>::iterator it;
					for (it = categorias4.begin(); it != categorias4.end(); it++) {
						if ((*it)->getNombre() == "PC") {
							plat = *it;
						}
						if ((*it)->getNombre() == "Deporte") {
							gen = *it;
						}
						if ((*it)->getNombre() == "PS4" || (*it)->getNombre() == "Xbox One" || (*it)->getNombre() == "E") {
							cats.push_back(*it);
						}
					}
					ctrlVideojuegos->asignarGenero(gen);
					ctrlVideojuegos->asignarPlataforma(plat);
					ctrlVideojuegos->asignarCategorias(cats);
					ctrlVideojuegos->publicarVideojuego();
					
					
					//Ingreso de suscripciones
					ctrlUsuarios->setFechaSistema(new DtFechaHora(2021, 6, 1, 9, 0));
					ctrlUsuarios->iniciarSesion("gamer@mail.com", "123");
					ctrlVideojuegos->altaSuscripcion("KingdomRush", "temporal", "paypal", 2);
					
					ctrlUsuarios->setFechaSistema(new DtFechaHora(2021, 6, 2, 11, 0));
					ctrlUsuarios->iniciarSesion("gamer@mail.com", "123");
					ctrlVideojuegos->altaSuscripcion("Fortnite", "temporal", "tarjeta", 2);
					
					ctrlUsuarios->setFechaSistema(new DtFechaHora(2021, 6, 4, 9, 0));
					ctrlUsuarios->iniciarSesion("ari@mail.com", "123");
					ctrlVideojuegos->altaSuscripcion("Fortnite", "temporal", "paypal", 1);
					
					ctrlUsuarios->setFechaSistema(new DtFechaHora(2021, 6, 11, 9, 0));
					ctrlUsuarios->iniciarSesion("ari@mail.com", "123");
					ctrlVideojuegos->altaSuscripcion("Minecraft", "temporal", "tarjeta", 3);
					
					ctrlUsuarios->setFechaSistema(new DtFechaHora(2021, 6, 3, 7, 0));
					ctrlUsuarios->iniciarSesion("ibai@mail.com", "123");
					ctrlVideojuegos->altaSuscripcion("Fortnite", "temporal", "tarjeta", 1);
					
					ctrlUsuarios->setFechaSistema(new DtFechaHora(2020, 12, 21, 15, 0));
					ctrlUsuarios->iniciarSesion("ibai@mail.com", "123");
					ctrlVideojuegos->altaSuscripcion("Minecraft", "vitalicia", "tarjeta", 0);
					
					//Ingreso de puntajes
					ctrlUsuarios->iniciarSesion("gamer@mail.com", "123");
					ctrlVideojuegos->asignarPuntajeAVideojuego("KingdomRush", 4);
					
					ctrlUsuarios->iniciarSesion("gamer@mail.com", "123");
					ctrlVideojuegos->asignarPuntajeAVideojuego("Fortnite", 5);
					
					ctrlUsuarios->iniciarSesion("ari@mail.com", "123");
					ctrlVideojuegos->asignarPuntajeAVideojuego("Fortnite", 5);
					
					ctrlUsuarios->iniciarSesion("ari@mail.com", "123");
					ctrlVideojuegos->asignarPuntajeAVideojuego("Minecraft", 3);
					
					
					//Ingreso de partidas individuales
					int id;
					ctrlUsuarios->setFechaSistema(new DtFechaHora(2021, 6, 2, 9, 0));
					ctrlUsuarios->iniciarSesion("gamer@mail.com", "123");
					ctrlPartidas->SeleccionarVideojuego("KingdomRush");
					ctrlPartidas->setTipoPartida("individual");
					ctrlPartidas->iniciarPartida();
					
					ctrlUsuarios->setFechaSistema(new DtFechaHora(2021, 6, 2, 10, 0));
					vector<DtPartida*> partidasNoFinalizadasGamer1 = ctrlPartidas->ListarPartidasNoFinalizadas();			
					vector<DtPartida*>::iterator itp;
					for (itp = partidasNoFinalizadasGamer1.begin(); itp != partidasNoFinalizadasGamer1.end(); itp++) {
						if ((*itp)->getVideojuego() == "KingdomRush") {
							id = (*itp)->getIdPartida();
							ctrlPartidas->ingreseIdPartida((*itp)->getIdPartida());
							ctrlPartidas->finalizarPartida();
							break;
						}
					}
					
					/***************************************************************************/
					
					ctrlUsuarios->setFechaSistema(new DtFechaHora(2021, 6, 3, 15, 0));
					ctrlUsuarios->iniciarSesion("gamer@mail.com", "123");
					ctrlPartidas->SeleccionarVideojuego("KingdomRush");
					ctrlPartidas->setTipoPartida("individual");
					ctrlPartidas->seleccionarPartida(id);
					ctrlPartidas->iniciarPartida();
					ctrlUsuarios->setFechaSistema(new DtFechaHora(2021, 6, 3, 16, 0));
					
					vector<DtPartida*> partidasNoFinalizadasGamer2 = ctrlPartidas->ListarPartidasNoFinalizadas();
					
					for (itp = partidasNoFinalizadasGamer2.begin(); itp != partidasNoFinalizadasGamer2.end(); itp++) {
						if ((*itp)->getVideojuego() == "KingdomRush") {
							ctrlPartidas->ingreseIdPartida((*itp)->getIdPartida());
							ctrlPartidas->finalizarPartida();
							break;
						}
					}
					
					/***************************************************************************/
					
					ctrlUsuarios->setFechaSistema(new DtFechaHora(2021, 6, 12, 16, 0));
					ctrlUsuarios->iniciarSesion("ari@mail.com", "123");
					ctrlPartidas->SeleccionarVideojuego("Minecraft");
					ctrlPartidas->setTipoPartida("individual");
					ctrlPartidas->iniciarPartida();
					
			
					//Ingreso de partidas multijugador
					
					ctrlUsuarios->setFechaSistema(new DtFechaHora(2021, 6, 5, 17, 0));
					ctrlUsuarios->iniciarSesion("gamer@mail.com", "123");
					ctrlPartidas->SeleccionarVideojuego("Fortnite");
					ctrlPartidas->setTipoPartida("multijugador");
					ctrlPartidas->Transmitida(true);
					jugadoresQParticipan.push_back("ari");
					jugadoresQParticipan.push_back("ibai");
					ctrlPartidas->seleccionarJugadores(jugadoresQParticipan); 
					ctrlPartidas->iniciarPartida();
					
					
					
					ctrlUsuarios->iniciarSesion("ari@mail.com", "123");
					vector<DtPartida*> partidasActivasAri1 = ctrlPartidas->ObtenerPartidasActivas();
					ctrlUsuarios->setFechaSistema(new DtFechaHora(2021, 6, 5, 18, 0));			
					for (itp = partidasActivasAri1.begin(); itp != partidasActivasAri1.end(); itp++) {
						if ((*itp)->getVideojuego() == "Fortnite") {
							ctrlPartidas->AbandonarPartidaActiva((*itp)->getIdPartida());
						}
					}
					
					ctrlUsuarios->iniciarSesion("gamer@mail.com", "123");
					ctrlUsuarios->setFechaSistema(new DtFechaHora(2021, 6, 5, 19, 0));
					vector<DtPartida*> partidasNoFinalizadasAri2 = ctrlPartidas->ListarPartidasNoFinalizadas();			
					
					for (itp = partidasNoFinalizadasAri2.begin(); itp != partidasNoFinalizadasAri2.end(); it++) {
						if ((*itp)->getVideojuego() == "Fortnite") {
							ctrlPartidas->ingreseIdPartida((*itp)->getIdPartida());
							ctrlPartidas->finalizarPartida();
							break;
						}
					}
					
					/***************************************************************************/
					
					jugadoresQParticipan.clear();
					ctrlUsuarios->setFechaSistema(new DtFechaHora(2021, 6, 6, 17, 0));
					ctrlUsuarios->iniciarSesion("gamer@mail.com", "123");
					ctrlPartidas->SeleccionarVideojuego("Fortnite");
					ctrlPartidas->setTipoPartida("multijugador");
					ctrlPartidas->Transmitida(true);
					jugadoresQParticipan.push_back("ari");
					jugadoresQParticipan.push_back("ibai");
					ctrlPartidas->seleccionarJugadores(jugadoresQParticipan); 
					ctrlPartidas->iniciarPartida();
					
					//Abandona partida multijugador
					ctrlUsuarios->iniciarSesion("ari@mail.com", "123");
					vector<DtPartida*> partidasActivasAri2 = ctrlPartidas->ObtenerPartidasActivas();
					ctrlUsuarios->setFechaSistema(new DtFechaHora(2021, 6, 6, 17, 30));
					for (itp = partidasActivasAri2.begin(); itp != partidasActivasAri2.end(); itp++) {
						if ((*itp)->getVideojuego() == "Fortnite") {
							ctrlPartidas->AbandonarPartidaActiva((*itp)->getIdPartida());
						}
					}
					
					ctrlUsuarios->iniciarSesion("gamer@mail.com", "123");
					ctrlUsuarios->setFechaSistema(new DtFechaHora(2021, 6, 6, 19, 0));
					vector<DtPartida*> partidasNoFinalizadasAri3 = ctrlPartidas->ListarPartidasNoFinalizadas();			
					for (itp = partidasNoFinalizadasAri3.begin(); itp != partidasNoFinalizadasAri3.end(); itp++) {
						if ((*itp)->getVideojuego() == "Fortnite") {
							ctrlPartidas->ingreseIdPartida((*itp)->getIdPartida());
							ctrlPartidas->finalizarPartida();
							break;
						}
					}
					
					/***************************************************************************/
					
					jugadoresQParticipan.clear();
					ctrlUsuarios->setFechaSistema(new DtFechaHora(2021, 6, 12, 20, 0));
					ctrlUsuarios->iniciarSesion("ari@mail.com", "123");
					ctrlPartidas->SeleccionarVideojuego("Minecraft");
					ctrlPartidas->Transmitida(false);
					jugadoresQParticipan.push_back("ibai");
					ctrlPartidas->seleccionarJugadores(jugadoresQParticipan); 
					ctrlPartidas->iniciarPartida();

					yaCargados = true;				
					system("clear");
					cout << "Datos ingresados correctamente." << endl;
				}else {
					system("clear");
					cout << "Datos ya cargados." << endl;
				}
			}
            break;
            case 0: {n = 0;}
            break;
            default: {cout << "Ingrese una de las opciones listadas!" << endl;}
            break;
        }

    }
    return 0;
}
