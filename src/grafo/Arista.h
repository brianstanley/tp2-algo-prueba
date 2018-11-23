const int PESO_ARISTA_NULA = -1;
const int PESO_ARISTA_INICIAL = 0;
const bool ACTIVADA = true;
const bool DESACTIVADA = false;

class Arista{
private:
	bool estadoArista;
	int pesoArista;
public:
	/*
	 * pre: -
	 * post: se crea una instancia de arista DESACTIVADA con un peso PESO_ARISTA_NULA
	 */
	Arista();

	/*
	 * pre: -
	 * post: se setea una arista como ACTIVADA
	 */
	void Activar();

	/*
	 * pre: -
	 * post: se setea una arista como DESACTIVADA
	 */
	void Desctivar();

	/*
	 * pre: -
	 * post: se suma la cantidad pasada por parametro al peso actual de la arista
	 */
	void SumarPeso(int pesoASumar);
};
