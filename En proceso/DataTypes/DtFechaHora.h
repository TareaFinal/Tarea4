#ifndef DTFECHAHORA
#define DTFECHAHORA

class DtFechaHora {
	private:
		int dia;
		int mes;
		int anio;
		int hora;
		int minuto;
	public:
		DtFechaHora();
		int getDia();
		int getMes();
		int getAnio();
		int getHora();
		int getMinuto();

};

#endif