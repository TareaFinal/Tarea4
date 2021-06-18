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

set<string> ControladorUsuarios::getVideojuegoJugador(string email) {
	//set<DtVideojuego> *videojuegos;
    set<string> nombresVideojuegos;
    /*Usuario* usuario = NULL;

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

        set<DtVideojuego>::iterator it;
        for (it = videojuegos->begin(); it != videojuegos->end(); it++) {
            string nombre = it->getNombre();
			nombresVideojuegos.insert(nombre);
        }
    }
*/
    return nombresVideojuegos;
}

void ControladorUsuarios::registrarUsuario(string email, string contrasenia) {
	
}

void ControladorUsuarios::darEmpresa(string nombre) {
	
}

void ControladorUsuarios::darDatosJugador(string nick, string descripcion) {
	
}

void ControladorUsuarios::confirmarAltaUsuario() {
	
}

void ControladorUsuarios::obtenerVideojuegosJugador(string email) {
	
}

void ControladorUsuarios::desvincularSuscripciones(set<Jugador*> &js, Videojuego *v) {
	
}

void ControladorUsuarios::desvincularSuscripcion(string email, Videojuego *v) {
	
}

Suscripcion *ControladorUsuarios::buscarSuscripcion(Videojuego *v) {
	return NULL;
}

void ControladorUsuarios::agregarSusAJugador(Suscripcion *s) {
	
}
set<Jugador*> ControladorUsuarios::darJugadores(set<DtJugador*> &dtJugadores) {
	set<Jugador*> jugadores;
	return jugadores;
}

int ControladorUsuarios::cantidadJugadoresSuscriptosVideojuego(string videojuego) {
	return 1;
}

bool ControladorUsuarios::iniciarSesion(string email, string contrasenia) {
    /*Usuario* usuario = NULL;

    usuarios::iterator user;
    for (user = s1.begin(); user != s1.end(); user++) {
        if ((*user).getEmail() == email && (*user).getContrasenia() == contrasenia) {
            usuario = user;
            break;
        }     
    }

    if ((*usuario) != NULL) {
        emailUsuarioEnSesion = email;
        return true;
    }else {*/
    	emailUsuarioEnSesion = email;
        return false;
    //}
}

string ControladorUsuarios::getTipoUsuario() {
    /*Usuario* usuario = NULL;

    usuarios::iterator user;
    for (user = s1.begin(); user != s1.end(); user++) {
        if ((*user).getEmail() == emailUsuarioEnSesion) {
            usuario = user;
            break;
        }
    }

    if (*usuario != NULL) {
        
        Jugador* jug = dynamic_cast <Jugador*> (*usuario);

        if (jug != NULL) {
            return "j";
        }else {
            return "d";
        }

    }*/return "s";

}

void ControladorUsuarios::setFechaSistema(DtFechaHora* fechaSist) {
    systemTime = fechaSist;
}

DtFechaHora* ControladorUsuarios::getFechaSistema() {
    return systemTime;
}

vector<DtJugador> ControladorUsuarios::listarJugadoresSuscriptosVideojuego(string videojuego){
    vector<DtJugador> jugadores;
	return jugadores;
}

bool ControladorUsuarios::altaSuscripcion(string nomJugador, string nomVideo, Suscripcion sus, bool isVitalicia) {
    return true;    
}

bool ControladorUsuarios::esTemporal(Suscripcion *s) {
    return true;
}