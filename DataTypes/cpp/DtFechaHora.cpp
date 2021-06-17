#include "../DtFechaHora.h"
#include <time.h>
#include <stdio.h>


DtFechaHora::DtFechaHora(int dia, int mes, int anio, int hora, int minuto) {
	/*
	time_t ahora = time(NULL);
  	struct tm *ahoralocal = localtime(&ahora);	
	*/
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