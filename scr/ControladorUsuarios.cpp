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
    //??    

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
    usuario* = NULL;

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

void ControladorUsuarios::desvincularSuscripcion(string email, Videojuego v) {
    usuario* = NULL;

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

Suscripcion ControladorUsuarios::buscarSuscripcion(Videojuego v) {}

void ControladorUsuarios::agregarSusAJugador(string email, Suscripcion s) {
    usuario* = NULL;

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
    *usuario = NULL;

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


