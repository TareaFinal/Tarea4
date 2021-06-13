#include "../ControladorUsuarios.h"
#include "../DataTypes/DtEstadistica.h"
#include "../DataTypes/DtVideojuego.h"
#include "../DataTypes/DtCategoria.h"
#include "../DataTypes/DtJugador.h"
#include "../IControladorUsuarios.h"
#include <string>
#include <set>
#include "../jugador.h"
#include "../Videojuego.h"
#include "../suscripcion.h"
#include "../usuario.h"
using namespace std;



static ControladorUsuarios ControladorUsuarios::getInstancia() {
    if (instancia == NULL) {
        instancia = new ControladorUsuarios();
    }    

    return instancia;
}

string ControladorUsuarios::getUsuarioEnSesion() {
    return emailUsuarioEnSesion;
}

set<string> ControladorUsuarios::getVideojuegoJugador(string email) {
    set<DtVideojuego> videojuegos;
    set<string> nombresVideojuegos;
    Usuario* usuario = NULL;

    usuarios::iterator user;
    for (user = s1.begin(); user != s1.end(); user++) {
        if ((*user).getEmail() == email) {
            usuario = user;
            break;
        }
    }

    if (*usuario != NULL) {
        videojuegos = (*usuario).videojuegosSuscripto();

        videojuegos::iterator it;
        for (it = s1.begin(); it != s1.end(); it++) {
            nombresVideojuegos.insert((*it).getNombre());
        }
    }

    return nombresVideojuegos;
}

void ControladorUsuarios::registrarUsuario(string email, string contrasenia) {
    if (email.find('@') == string::npos || email.find('.') == string::npos) {
        throw "Formato incorrecto de email, necesita contener '@' y '.'. Por ejemplo: example@email.ex";
    }

    mail = email;
    contra = contrasenia;
}

void ControladorUsuarios::darEmpresa(string nombre){
    empresa = nombre;
}

void ControladorUsuarios::darDatosJugador(string nick, string descripcion) {
    nickname = nick;
    desc = descripcion;
}

void ControladorUsuarios::confirmarAltaUsuario() {
    if (empresa == '' && (nickname != '' && desc != '')) {
        usuarios.insert(new Jugador(mail, contra, nickname, desc));
    }else if (empresa != '') {
        usuarios.insert(new Desarrollador(mail, contra, empresa));
    }else {
        throw "Datos insuficientes para realizar la operacion";
    }
}

set<DtVideojuego> ControladorUsuarios::obtenerVideojuegosJugador(string email) {
    set<DtVideojuego> videojuegos;
    Usuario* usuario = NULL;

    usuarios::iterator user;
    for (user = s1.begin(); user != s1.end(); user++) {
        if ((*user).getEmail() == email) {
            usuario = user;
            break;
        }
    }

    if (*usuario != NULL) {
        videojuegos = (*usuario).videojuegosSuscripto();
    }

    return videojuegos;
}

void ControladorUsuarios::desvincularSuscripciones(set<Jugador> js, Videojuego v) {
   for (Jugador j : js) {
       desvincularSuscripcion(j.getEmail(), v);
   }
}

Suscripcion buscarSuscripcion(Videojuego v) {
    Usuario* usuario = NULL;

    usuarios::iterator user;
    for (user = s1.begin(); user != s1.end(); user++) {
        if ((*user).getEmail() == emailUsuarioEnSesion) {
            usuario = user;
            break;
        }
    }

    if (*usuario != NULL) {
        set<Suscripcion*> sus= (*usuario).getSuscripciones();

        sus::iterator it;
        for (it = s1.begin(); it != s1.end(); it++) {
            if ((*it).getVideojuego() == v) {
                return *it;
            }
        }
    }
}

void ControladorUsuarios::desvincularSuscripcion(string email, Videojuego v) {
    Usuario* usuario = NULL;

    usuarios::iterator user;
    for (user = s1.begin(); user != s1.end(); user++) {
        if ((*user).getEmail() == email) {
            usuario = user;
            break;
        }
    }

    if (*usuario != NULL) {
        videojuegos = (*usuario).desvincularSub(v);
    }

}

void ControladorUsuarios::agregarSusAJugador(string email, Suscripcion s) {
    Usuario* usuario = NULL;

    usuarios::iterator user;
    for (user = s1.begin(); user != s1.end(); user++) {
        if ((*user).getEmail() == email) {
            usuario = user;
            break;
        }
    }
    
    if (*usuario != NULL) {
        (*usuario).agregarSuscripcion(s);
    }
}

set<Jugador> ControladorUsuarios::darJugadores(set<DtJugador> dtJugadores) {
    set<Jugador> jugadores;
    Usuario* usuario = NULL;

    for (DtJugador dtJ : dtJugadores) {
        string email = dtJ.getEmail();
        
        usuarios::iterator user;
        for (user = s1.begin(); user != s1.end(); user++) {
            if ((*user).getEmail() == email) {
                usuario = user;
                break;
            }     
        }

        jugadores.insert(*usuario);
    }

    return jugadores;
}


