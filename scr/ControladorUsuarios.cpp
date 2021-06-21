#include "../ControladorUsuarios.h"

ControladorUsuarios *ControladorUsuarios::instancia = NULL;

ControladorUsuarios *ControladorUsuarios::getInstancia() {
	if (instancia == NULL)
		instancia = new ControladorUsuarios();

	return instancia;	
}

ControladorUsuarios::ControladorUsuarios() {
	
}

string ControladorUsuarios::getUsuarioEnSesion() {
	return emailUsuarioEnSesion;
}

string ControladorUsuarios::getNickJugadorEnSesion() {
	Usuario* usuario = NULL;

    set<Usuario*>::iterator user;
    for (user = this->usuarios.begin(); user != this->usuarios.end(); user++) {
        if ((*user)->getEmail() == this->emailUsuarioEnSesion) {
            usuario = *user;
            break;
        }
    }
 
    Jugador* jugador = dynamic_cast<Jugador*> (usuario);
    
    return jugador->getNick();
}


set<string> ControladorUsuarios::getVideojuegoJugador(string email) {
	vector<DtVideojuego> videojuegos;
    set<string> nombresVideojuegos;
    Usuario* usuario = NULL;

    set<Usuario*>::iterator user;
    for (user = this->usuarios.begin(); user != this->usuarios.end(); user++) {
        if ((*user)->getEmail() == email) {
            usuario = *user;
            break;
        }
    }

    if (usuario != NULL) {
    	Jugador* jugador = dynamic_cast<Jugador*> (usuario);
        //videojuegos = jugador->videojuegosSuscripto();   ///////////////////////////////////////////////////////////////////////////////////////

        vector<DtVideojuego>::iterator it;
        for (it = videojuegos.begin(); it != videojuegos.end(); it++) {
            string nombre = it->getNombre();
			nombresVideojuegos.insert(nombre);
        }
    }
    return nombresVideojuegos;
}

bool ControladorUsuarios::registrarUsuario(string email, string contrasenia) {
	if (email.find('@') == string::npos || email.find('.') == string::npos) {
        throw "Formato incorrecto de email, necesita contener '@' y '.'. Por ejemplo: example@email.ex";
    }

	set<Usuario*>::iterator user;
    for (user = usuarios.begin(); user != usuarios.end(); user++) {
    	if ((*user) != NULL) {
        	if ((*user)->getEmail() == email) {
        		return false;
			}
		}
    }

    mail = email;
    contra = contrasenia;
    
    return true;
}

void ControladorUsuarios::darEmpresa(string nombre) {
	this->empresa = nombre;
}

bool ControladorUsuarios::darDatosJugador(string nick, string descripcion) {
	set<Usuario*>::iterator user;
    for (user = usuarios.begin(); user != usuarios.end(); user++) {
        Jugador* jugador = dynamic_cast<Jugador*> (*user);
        
        if (jugador != NULL) {
        	if (jugador->getNick() == nick) {
        		return false;
			}
		
    	}
	}	
	this->nickname = nick;
    this->desc = descripcion;
    
    return true;
}

void ControladorUsuarios::confirmarAltaUsuario() {
	if ((empresa == "") && (nickname != "")) {
        usuarios.insert(new Jugador(this->mail, this->contra, this->nickname, this->desc));
    }else if (empresa != "") {
        usuarios.insert(new Desarrollador(this->mail, this->contra, this->empresa));
    }else {
        throw "Datos insuficientes para realizar la operacion";
    }
    
    this->empresa = "";
    this->mail = "";
    this->contra = "";
    this->desc = "";
    this->nickname = "";
}

vector<DtVideojuego*> ControladorUsuarios::obtenerVideojuegosJugador(string email) {
	vector<DtVideojuego*> videojuegos;
    Usuario* usuario = NULL;

    set<Usuario*>::iterator user;
    for (user = usuarios.begin(); user != usuarios.end(); user++) {
        if ((*user)->getEmail() == email) {
            usuario = *user;
            break;
        }
    }

    if (usuario != NULL) {
        Jugador* jugador = dynamic_cast<Jugador*> (usuario);
        videojuegos = jugador->videojuegosSuscripto();
    }

    return videojuegos;
}

void ControladorUsuarios::desvincularSuscripciones(set<Jugador*> &js, Videojuego *v) {
	for (Jugador *j : js) {
       this->desvincularSuscripcion(j->getEmail(), v);
   }
}

void ControladorUsuarios::desvincularSuscripcion(string email, Videojuego *v) {
	Usuario* usuario = NULL;

    set<Usuario*>::iterator user;
    for (user = this->usuarios.begin(); user != this->usuarios.end(); user++) {
        if ((*user)->getEmail() == emailUsuarioEnSesion) {
            usuario = *user;
            break;
        }
    }

    if (usuario != NULL) {
    	Jugador* jugador = dynamic_cast<Jugador*> (usuario);
        jugador->desvincularSub(v);
    }
}

Suscripcion *ControladorUsuarios::buscarSuscripcion(Videojuego *v) {
	 Usuario* usuario = NULL;

    set<Usuario*>::iterator user;
    for (user = usuarios.begin(); user != usuarios.end(); user++) {
        if ((*user)->getEmail() == emailUsuarioEnSesion) {
            usuario = *user;
            break;
        }
    }

    if (usuario != NULL) {
    	Jugador* jugador = dynamic_cast<Jugador*> (usuario);
        Suscripcion* sus= jugador->getSuscripcion(v->getNombre());
        return sus;
    } else {
    	return NULL;
	}
}

void ControladorUsuarios::agregarSusAJugador(Suscripcion *s) {
	Usuario* usuario = NULL;

    set<Usuario*>::iterator user;
    for (user = usuarios.begin(); user != usuarios.end(); user++) {
        if ((*user)->getEmail() == emailUsuarioEnSesion) {
            usuario = *user;
            break;
        }
    }
    
    if (usuario != NULL) {
    	Jugador* jugador = dynamic_cast<Jugador*> (usuario);
        jugador->agregarSuscripcion(s);
    }
}
set<Jugador*> ControladorUsuarios::darJugadores(set<DtJugador*> &dtJugadores) {
	set<Jugador*> jugadores;
    Usuario* usuario = NULL;

    for (DtJugador *dtJ : dtJugadores) {
        string email = dtJ->getEmail();
        
        set<Usuario*>::iterator user;
        for (user = usuarios.begin(); user != usuarios.end(); user++) {
            if ((*user)->getEmail() == email) {
                usuario = *user;
                break;
            }     
        }

		Jugador* jugador = dynamic_cast<Jugador*> (usuario);
        jugadores.insert(jugador);
    }

    return jugadores;
}

int ControladorUsuarios::cantidadJugadoresSuscriptosVideojuego(string videojuego) {
	int cant = 0;
	
	set<Usuario*>::iterator user;
    for (user = usuarios.begin(); user != usuarios.end(); user++) {
    	Jugador* jugador = dynamic_cast<Jugador*> (*user);
    	
    	if (jugador != NULL) {
			vector<DtVideojuego*> vdj = jugador->videojuegosSuscripto();
			
			vector<DtVideojuego*>::iterator it;
			for (it = vdj.begin(); it != vdj.end(); it++) {
				if ((*it)->getNombre() == videojuego) {
					cant++;
					break;
				}
			}
		}
    }
    
    return cant;
}

bool ControladorUsuarios::iniciarSesion(string email, string contrasenia) {
    Usuario* usuario = NULL;

    set<Usuario*>::iterator user;
    for (user = usuarios.begin(); user != usuarios.end(); user++) {
        if ((*user)->getEmail() == email && (*user)->getContrasenia() == contrasenia) {
            usuario = *user;
            break;
        }     
    }

    if (usuario != NULL) {
        this->emailUsuarioEnSesion = email;
        return true;
    }else {
        return false;
    }
}

string ControladorUsuarios::getTipoUsuario() {
    Usuario* usuario = NULL;

    set<Usuario*>::iterator user;
    for (user = this->usuarios.begin(); user != this->usuarios.end(); user++) {
        if ((*user)->getEmail() == this->emailUsuarioEnSesion) {
            usuario = *user;
            break;
        }
    }

    if (usuario != NULL) {      
        Jugador* jug = dynamic_cast <Jugador*> (usuario);

        if (jug != NULL) {
            return "j";
        }else {
            return "d";
        }

    }
	return "";
}

void ControladorUsuarios::setFechaSistema(DtFechaHora *fechaSist) {
    systemTime = fechaSist;
}

DtFechaHora *ControladorUsuarios::getFechaSistema() {
    return systemTime;
}

vector<DtJugador> ControladorUsuarios::listarJugadoresSuscriptosVideojuego(string videojuego) {
	vector<DtJugador> jugadores;
	return jugadores;
}


bool ControladorUsuarios::esTemporal(Suscripcion *s) {
	bool esTemporal = false;
	if (s->TipoSuscripcion() == "temporal")
		esTemporal = true;

	return esTemporal;
}

Usuario *ControladorUsuarios::getUsuarioEnSistema() {
	Usuario* usuario = NULL;

    set<Usuario*>::iterator user;
    for (user = this->usuarios.begin(); user != this->usuarios.end(); user++) {
        if ((*user)->getEmail() == this->emailUsuarioEnSesion) {
            usuario = *user;
            break;
        }
    }
    
    return usuario;

}

Desarrollador *ControladorUsuarios::getDesarrolladorEnSesion(){
    Usuario* usuario = NULL;

    set<Usuario*>::iterator user;
    for (user = this->usuarios.begin(); user != this->usuarios.end(); user++) {
        if ((*user)->getEmail() == emailUsuarioEnSesion) {
            usuario = *user;
            break;
        }
    }

    if (usuario != NULL) {      
        Desarrollador* des = dynamic_cast <Desarrollador*> (usuario);
        if (des != NULL){
            return des;
        }
    }
	return NULL;
};

void ControladorUsuarios::registrarStatsDesarrollador(vector<int> stats) {
	Desarrollador* des = getDesarrolladorEnSesion();
	des->registrarStats(stats);
}

vector<int> ControladorUsuarios::getStatsDesarrolladorEnSesion() {
	Desarrollador* des = getDesarrolladorEnSesion();
	return des->getStats();
}


