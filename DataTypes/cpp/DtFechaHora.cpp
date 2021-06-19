#include "../DtFechaHora.h"
#include <time.h>
#include <stdio.h>


DtFechaHora::DtFechaHora(int anio, int mes, int dia, int hora, int minuto) {
	
	this->dia = dia;
	this->mes = mes;
	this->anio = anio;
	this->hora = hora;
	this->minuto = minuto;
}

int DtFechaHora::getDia() {
	return this->dia;
}

int DtFechaHora::getMes() {
	return this->mes;
}

int DtFechaHora::getAnio() {
	return this->anio;
}

int DtFechaHora::getHora() {
	return this->hora;
}

int DtFechaHora::getMinuto() {
	return this->minuto;
}
