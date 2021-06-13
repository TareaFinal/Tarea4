#include "../ControladorVideojuegos.h"
#include "DtEstadistica.h"
#include <string>
#include <set>
using namespace std;

ControladorVideojuegos* ControladorVideojuegos::getInstancia(){

    if (instancia == NULL) {
        instancia = new ControladorVideojuegos();
    }    
    return instancia;

};
float ControladorVideojuegos::calcularEstadistica(int estadistica){ //no deberia de ser de la misma clase que el identificador de estadisticas que viene a ser un int? ---- Ag: Si, lo deje porque asi estaba
    bool encontre = false;
    int i = 0;
    int numeroEncontrado;
    while(i < categorias.size() && !encontre) {
        //DtEstadistica e = categorias.;
        //if(categorias){
        //
        //};
        i++;
    }
}; 
float ControladorVideojuegos::calcularHorasJugadas(Videojuego videojuego){

};
set<DtJugador> ControladorVideojuegos::jugadoresSuscriptosAVideojuego(string nombre){

};
void ControladorVideojuegos::eliminarVideojuego(string nombre){

};
set<DtVideojuego> ControladorVideojuegos::obtenerVideojuegos(){

};
void ControladorVideojuegos::confirmarEliminacion(){

};
bool ControladorVideojuegos::ingreseNombreVideojuego(string nombreVideojuego){

};
set<DtEstadistica> ControladorVideojuegos::listarEstadisticas(string nombreVideojuego){

};
bool ControladorVideojuegos::esTemporal(Suscripcion s){

};
Suscripcion ControladorVideojuegos::ingresarNombre(string nombre){

};
void ControladorVideojuegos::ingresarCategoria(DtCategoria cat){

};
