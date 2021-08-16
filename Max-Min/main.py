#Juan Pablo Montoya Números mayores y menores


def menor(a,b):
    return (a, False) if a<=b else (b, True)
def mayor(a,b):
    return (a, False) if a>=b else (b, True)

def main(array = ["a", "b", "c", "d"]):
    letra_mayor=""
    letra_menor=""
    maximo = 0
    minimo = float("inf")
    for valor in array:
        mensaje = "Ingrese un valor para "+valor+ ": "
        x = float(input(mensaje))
        minimo, ret_menor = menor(minimo, x)
        maximo, ret_mayor = mayor(maximo, x)
        letra_mayor = valor if ret_menor else letra_mayor
        letra_menor = valor if ret_mayor else letra_menor

    return (maximo, minimo, letra_mayor, letra_menor)
a,b,c,d = main()
print(f"minimo: {c}: {b}, maximo : {d}: {a}")
