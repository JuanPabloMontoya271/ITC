#include "search.h"

int search::busquedaBin(int lista[], int n, int clave)
{
	int central, bajo, alto, valorCentral;
	bajo = 0;
	//n = lista.length;
	alto = n - 1;
	while (bajo <= alto) {
		central = (bajo + alto) / 2;
		valorCentral = lista[central];
		if (clave == valorCentral)
			return central;
		else if (clave < valorCentral)
			alto = central - 1;
		else
			bajo = central + 1;
	}
	return -1;
}

