import sys
import random
import pygame

pygame.init()

# Resolucion y confg. de graficos.

X,Y = 1940,1000
Screen = pygame.display.set_mode((X,Y))
pygame.display.set_caption("Bubble Sort Race")

c_Negro = (0,0,0)
c_Blanco = (255,255,255)
c_Verde = (0,128,0)
c_Rojo = (255,0,0)
c_Azul = (0,0,255)
Colores = [(random.randint(50,200),random.randint(50,200),random.randint(50,200))for _ in range(10)]

Fuente = pygame.font.SysFont("Comic Sans",24)

# Class def

class JuegoBubbleSort:
    def __init__(self):
        self.lista = random.sample(range(1,11),10)
        self.pasos = 0
        self.Tiempo_int = pygame.time.get_ticks()
        self.Seleccionado =  None

    def d_Lista(self):
        Screen.fill(c_Negro)
        X_Bloque = 60
        Espacio  = 10
        
        for i,num in enumerate(self.lista):
            x = 600 + i * (X_Bloque+Espacio)
            y = Y//2
            color =  Colores[num-1]
            if i ==  self.Seleccionado:
                pygame.draw.rect(Screen,c_Verde,(x,y,X_Bloque,num*20),0)
            else:
                pygame.draw.rect(Screen,color,(x,y,X_Bloque,num*20),0)
            texto =  Fuente.render(str(num),True,c_Blanco)
            Screen.blit(texto,(x+20,y-30))
        
        t_actual = (pygame.time.get_ticks()-self.Tiempo_int)//1000
        texto_p = Fuente.render(f"Pasos: {self.pasos}",True,c_Blanco)
        texto_t = Fuente.render(f"Tiempo: {t_actual}",True,c_Blanco)
        Screen.blit(texto_p,(20,20))
        Screen.blit(texto_t,(20,50))

        instrucciones = Fuente.render("Haz click en 2 bloques adyacentes para intercambiarlos",True,c_Blanco)
        Screen.blit(instrucciones,(650,Y-50))

    def intercambiar(self,i,j):
        if abs(i-j) == 1:
            self.lista[i], self.lista[j] = self.lista[j],self.lista[i]
            self.pasos += 1
            return True
        return False
    def Verificar_Orden(self):
        return self.lista == sorted(self.lista)
    
def Main():
    juego = JuegoBubbleSort()
    reloj =  pygame.time.Clock()
    ejecutando = True

    while ejecutando:
        loadingScreen = pygame.image.load('assets/a.gif')
        Screen.blit(loadingScreen,(800,800))
        for evento in pygame.event.get():
            if evento.type == pygame.QUIT:
                ejecutando = False
            if evento.type == pygame.MOUSEBUTTONUP:
                x,y = pygame.mouse.get_pos()
                for i in range(len(juego.lista)):
                    x_bloque = 600 + i * 70
                    y_bloque = Y//2
                    
                    if x_bloque <= x <= x_bloque + 60 and y_bloque <= y <= y_bloque + 200:
                        if juego.Seleccionado is None:
                            juego.Seleccionado = i
                        else:
                            if juego.intercambiar(juego.Seleccionado, i):
                                if juego.Verificar_Orden():
                                    tiempo_final = (pygame.time.get_ticks()-juego.Tiempo_int)//1000
                                    mensaje = Fuente.render(f"Ganaste en {juego.pasos} pasos y {tiempo_final}'s",True,c_Verde)
                                    Screen.blit(mensaje,(X//2-200,Y//2-100))
                                    pygame.display.flip()
                                    pygame.time.wait(3000)
                                    juego = JuegoBubbleSort
                            juego.Seleccionado = None
        
        juego.d_Lista()
        pygame.display.flip()
        reloj.tick(60)        
    pygame.quit()
    sys.exit()

if __name__ == "__main__":
    Main()  
            

            