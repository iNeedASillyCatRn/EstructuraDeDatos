import random
import os
import time

def  Limpiar_P():
    os.system('cls' if os.name == 'nt' else 'clear')

def crear_tab(f,c):
    t_parejas = (f*c)//2
    elementos = list(range(1,t_parejas+1)) *2
    random.shuffle(elementos)

    tablero = []
    for i in range(f):
        fila = elementos[i*c: (i+2)*c]
        tablero.append(fila)
    return tablero

def mostrar_Tab(t,r,f,c):
    print("   "+"  ".join(str(i+1) for i in range(c)))
    print("  "+"+---"*c+"+")

    for i in range(f):
        print(f"{i+1} |", end="")
        for j in range(c):
            if (i,j) in r:
                print(f" {t[i][j]} |",end="")
            else:
                print("   |", end="")
        print("\n  "+"+---"*c+"+")

def Juego_memoria():
    filas = 4
    columnas = 4
    tablero = crear_tab(filas,columnas)
    reveladas = set()
    temporales = []
    intentos = 0

    while len(reveladas) < filas*columnas:
        Limpiar_P()
        mostrar_Tab(tablero,reveladas.union(temporales),filas,columnas)
        print(f"Intentos {intentos}")

        if len(temporales) == 2:
            x1,y1 = temporales[0]
            x2,y2 = temporales[1]

            if tablero[x1,y1] == tablero[x2,y2]:
                reveladas.add(temporales[0])
                reveladas.add(temporales[1])
                print("Encontraste la pareja!")
            else:
                print("No es una pareja!")
            time.sleep(2)
            temporales = []

        try:
            print("\nSelecciona una casilla (fila, columna)")
            entrada = input("> ").strip().split(",")
            if len(entrada) != 2:
                raise ValueError
            
        
