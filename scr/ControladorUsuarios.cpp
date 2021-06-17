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
	if (email.find('@') == string::npos || email.find('.') == string::npos) {
        throw "Formato incorrecto de email, necesita contener '@' y '.'. Por ejemplo: example@email.ex";
    }

    mail = email;
    contra = contrasenia;
}

void ControladorUsuarios::darEmpresa(string nombre) {
	empresa = nombre;
}

void ControladorUsuarios::darDatosJugador(string nick, string descripcion) {
	nickname = nick;
    desc = descripcion;
}

void ControladorUsuarios::confirmarAltaUsuario() {
	if (empresa == "" && (nickname != "" && desc != "")) {
        //usuarios.insert(new Jugador(mail, contra, nickname, desc));
    }else if (empresa != "") {
        usuarios.insert(new Desarrollador(mail, contra, empresa));
    }else {
        throw "Datos insuficientes para realizar la operacion";
    }
}

set<DtVideojuego> *ControladorUsuarios::obtenerVideojuegosJugador(string email) {
	set<DtVideojuego> *videojuegos;
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
        //videojuegos = jugador->videojuegosSuscripto();
    }

    return videojuegos;
}

void ControladorUsuarios::desvincularSuscripciones(set<Jugador*> &js, Videojuego *v) {
	for (Jugador *j : js) {
       desvincularSuscripcion(j->getEmail(), v);
   }
}

void ControladorUsuarios::desvincularSuscripcion(string email, Videojuego *v) {
	Usuario* usuario = NULL;

    set<Usuario*>::iterator user;
    for (user = usuarios.begin(); user != usuarios.end(); user++) {
        if ((*user)->getEmail() == emailUsuarioEnSesion) {
            usuario = *user;
            break;
        }
    }

    if (usuario != NULL) {
        //videojuegos = (*usuario).desvincularSub(*v);
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
        //set<Suscripcion*> *sus= jugador->getSuscripciones();

        /*set<Suscripcion*>::iterator it;
        for (it = sus->begin(); it != sus->end(); it++) {
            if ((*it)->getVideojuego() == v) {
                return *it;
            }
        }*/
    }
    //return NULL;
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

