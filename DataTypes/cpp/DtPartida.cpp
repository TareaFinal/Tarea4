#include "../DtPartida.h"

int DtPartida::getIdPartida(){
    return this->idPartida;
};
DtFechaHora DtPartida::getDuracion(){
    return this->duracion;
};
DtFechaHora DtPartida::getFechaInicio(){
    return this->fechaInicio;
};
string DtPartida::getNicknameCreador(){
    return this->nicknameCreador;
};
string DtPartida::getVideojuego(){
    return this->videojuego;
};
/*bool smaller(const DtPartida& left, const DtPartida& right)
{
    return left.idPartida < t.getIdPartida();
}
std::set<DtPartida, std::function<bool(const DtPartida&, const DtPartida&)>> newSet(std::function<bool(const DtPartida&, const DtPartida&)>(smaller));
//bool DtPartida::operator <(const DtPartida& t) {
    
}
*/