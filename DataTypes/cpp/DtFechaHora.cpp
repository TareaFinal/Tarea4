#include "../DtFechaHora.h"
#include <time.h>
#include <stdio.h>


DtFechaHora::DtFechaHora() {
	
	time_t ahora = time(NULL);
  	struct tm *ahoralocal = localtime(&ahora);	
	
	this->dia = ahoralocal->tm_mday;
	this->mes = ahoralocal->tm_mon + 1;
	this->anio = ahoralocal->tm_year + 1900;
	this->hora = ahoralocal->tm_hour;
	this->minuto = ahoralocal->tm_min;
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