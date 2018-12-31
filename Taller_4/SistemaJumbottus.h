#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <windows.h>
#include <mmsystem.h>
#include <math.h>

using namespace std;
class SistemaJumbottus
{
public:
	double tiempo_secuencial;
	int bono;//variable para almacenar el bono
	int perdida_total;
	SistemaJumbottus();
	~SistemaJumbottus();
	void Menu();//menu del sistema
	int solucion_en_paralelo();//solucion en paralelo
	int solucion_secuencial();//solucion secuencial
	int Bono_Programador();//calcula el bono del programador.
	int leerVentas_secuencial(string producto); //Envia nombre de un producto, lee cada venta y devuelve el valor de las cantidades de ventas de ese producto.
	int leerVentas_paralelismo(string producto); //Envia nombre de un producto, lee cada venta y devuelve el valor de las cantidades de ventas de ese producto.
};

