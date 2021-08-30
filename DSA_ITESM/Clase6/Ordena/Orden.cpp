#include "Orden.h"

void Orden::ordIntercambio(int a[], int n)
{
	int i, j, aux; /* se realizan n-1 pasadas, a[o] ... a[n-2] */
	for (i = 0; i <= n - 2; i++)/* coloca mínimo de a[i+1]...a[n-1] en a[i] */
		for (j = i + 1; j <= n - 1; j++)
			if (a[i] > a[j])
			{
				aux = a[i];
				a[i] = a[j];
				a[j] = aux;
			}
}

void Orden::burbuja(int a[], int n) {
	bool interruptor = true;
	int tmp = 0;
	for (int pasada = 0; pasada < n - 1 && interruptor; pasada++) {
		interruptor = false; // no se han hecho intercambios
		for (int j = 0; j < n - 1 - pasada; j++) {
			if (a[j + 1] < a[j]) {
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
				interruptor = true;
			}
		}
	}
}

void Orden::ordSeleccion(int a[], int n)
{
	int indiceMenor, i, j;
	int aux;
	for (i = 0; i < n - 1; i++) // ordenar a[0]..a[n-2] y a[n-1] en cada pasada
	{
		indiceMenor = i; // comienzo de la exploración en índice i
		for (j = i + 1; j < n; j++) // j explora la sublista a[i+1]..a[n-1]
			if (a[j] < a[indiceMenor])
				indiceMenor = j;
		if (i != indiceMenor) // sitúa el elemento mas pequeño en a[i]
		{
			aux = a[i];
			a[i] = a[indiceMenor];
			a[indiceMenor] = aux;
		}
	}
}

void Orden::ordInsercion(int a[], int n)
{
	int i, j, aux;
	for (i = 1; i < n; i++) // El índice j explora sublista a[i-1]..a[0] buscando posición correcta del elemento destino, para asignarlo en a[j]
	{
		j = i;
		aux = a[i]; // se localiza el punto de inserción explorando hacia abajo
		while (j > 0 && aux < a[j - 1]) // desplazar elementos hacia arriba para hacer espacio
		{
			a[j] = a[j - 1];
			j--;
		}
		a[j] = aux;
	}
}
