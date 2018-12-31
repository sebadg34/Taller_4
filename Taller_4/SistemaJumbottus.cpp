#include "pch.h"
#include "SistemaJumbottus.h"
#include <chrono>  // para medir el tiempo de ejecucion
#include <Windows.h>
SistemaJumbottus::SistemaJumbottus()
{
	bono = 0;
	perdida_total = 0;
	tiempo_secuencial = 0;
	Menu();
}


SistemaJumbottus::~SistemaJumbottus()
{
}

void SistemaJumbottus::Menu()
{
	system("CLS");//Limpiar consola
	string opcion; //Auxiliar para menu
	string pause;
	bool menu = true;

	while (menu) {

		cout << "*************************************************************************************" << endl;
		cout << "*************************************************************************************" << endl;
		cout << "[1] solucion secuencial" << endl;
		cout << "[2] solucion paralelistica (khe)" << endl;
		cout << "[3] genera el sagrado bono" << endl;
		cout << "[4]  Salir" << endl;

		getline(cin, opcion);
		try { //Validar respuesta del menuasd
			std::stoi(opcion);
		}
		catch (const std::exception) {
			system("CLS");//Limpiar consola

			cout << "Porfavor escriba una opcion valida ([1],[2],etc)" << endl;
			cout << "*************************************************************************************" << endl;

			continue;
		}
		int opcionVerificada = std::stoi(opcion);

		switch (opcionVerificada) {

		case 1:
			system("CLS");//Limpiar consola
			
			
			
			solucion_secuencial();
			cout << "****************************************" << endl;
			cout <<"LA PERDIDA TOTAL FUE DE: $"<<perdida_total << endl;
			
			
			

			
				
			break;
		case 2:
			system("CLS");//Limpiar consola
			solucion_en_paralelo();
			break;
		case 3:
			system("CLS");//Limpiar consola
			Bono_Programador();
			break;

		case 4:

			menu = false;
			getline(cin, pause);
			break;


		}


	}




}

int SistemaJumbottus::solucion_en_paralelo()
{
	return 0;
}

int SistemaJumbottus::solucion_secuencial()
{
	//empieza la medicion de  tiempo de ejecucion.
	auto start = std::chrono::high_resolution_clock::now();

	int productosRobados = 0;
	string cantidad_inicial;
	string cantidad_final;
	string tamaño;


	std::ifstream archivoStocks;
	archivoStocks.open("Stock.txt", ifstream::in);
	string nombreProducto;
	string linea;

	if (!archivoStocks.is_open()) {
		cout << "Txt de stocks no cargadas" << endl;

	}
	else {
		cout << "txt de Stocks cargada..." << endl;
	
		while (getline(archivoStocks, linea)) {


			stringstream ss(linea); //extrae linea
			

			getline(ss, nombreProducto, ',');
			getline(ss, cantidad_inicial, ',');
			getline(ss, cantidad_final, ',');
			getline(ss, tamaño, ',');

			int cantidad_robada = stoi(cantidad_final) -leerVentas_secuencial(nombreProducto);/*devuelve cantidad de ventas, la diferencia entre estos
																									da la cantidad de productos robados.*/
			int monto_robado;

			//comprobar el monto robado mendiante el tamaño del producto.
			if (tamaño == "chico") {
				monto_robado = cantidad_robada * 10;
			}
			else {
				monto_robado = cantidad_robada * 50;
			}
			perdida_total += monto_robado;//sumo cantidad de perdidas para el resultado final.
			//despliego en pantalla lo pedido.
			cout << "PRODUCTO: " << nombreProducto << "||" << "CANTIDAD ROBADA: " << cantidad_robada << "||" << "MONTO ROBADO: $" << monto_robado << endl;

		}
	}

	auto finish = std::chrono::high_resolution_clock::now();
	
	
	std::chrono::duration<double> elapsed = finish - start;
	tiempo_secuencial = elapsed.count();//seteo la variable tiempo con el tiempo calculado anteriormente.
	cout << "************************************************************" << endl;
	std::cout << "TIEMPO DE EJECUCION: " << elapsed.count() << "s\n";
	return 0;
}

int SistemaJumbottus::Bono_Programador()
{
	return 0;
}


int SistemaJumbottus::leerVentas_secuencial(string producto)
{
	int contador = 0;
	std::ifstream archivoVentas;
	archivoVentas.open("Ventas.txt", ifstream::in);
	string nombreProducto;
	string linea;

	
	if (!archivoVentas.is_open()) {
		cout << "Txt ventas no cargadas" << endl;
		
	}
	else {
		
		while (getline(archivoVentas, linea)) {


			stringstream ss(linea); //extrae linea
			getline(ss, nombreProducto, ',');
			if (nombreProducto == producto) {
				contador++;
			}


			




		}
	}
	return contador;
}

int SistemaJumbottus::leerVentas_paralelismo(string producto)
{
	return 0;
}

