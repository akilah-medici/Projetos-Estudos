from datetime import datetime, time
from tkinter import *
from tkinter import ttk
import pygame


pygame.init()
pygame.mixer.init()
som = pygame.mixer.Sound("audio.mp3") 

som_tocando = False
alarme = None
alarme_ativado = False

def desativar_alarme():
    global alarme_ativado
    alarme_ativado=False
    som.stop()
    alarme_status.config(text="Alarme desativado!")


def definir_alarme():
    alarme_status.config(text="Alarme configurado!")
    global alarme, alarme_ativado
    alarme_ativado = True
    
    h = set_horas.get()
    m = set_minutos.get()
    alarme = time(int(h),int(m))
    verifica_alarme() 
    
def tocar_som():
    global som_tocando, alarme_ativado
    if not som_tocando and alarme_ativado == True: 
        som_tocando = True
        som.play()
        root.after(int(som.get_length() * 1000), parar_som)  # Para o som após sua duração

def parar_som():
    global som_tocando
    som.stop()
    som_tocando = False

def atualizar_texto():
    hora_atual = datetime.now().strftime("%H:%M:%S")# ultil.iza a biblioteca date time para salvar o horario atual
    
    horario.config(text = hora_atual)# dentro do label em horario, limpa ele e insere o novo horario
    
    root.after(1000, atualizar_texto)# chama a propria função apos 1 segundo para atualização do label

def verifica_alarme():
    hora_atual = datetime.now()
    if hora_atual.hour == alarme.hour and hora_atual.minute == alarme.minute and alarme_ativado == True:
        alarme_status.config(text = "Alarme ativado!")
        tocar_som() 
    root.after(1000, verifica_alarme)



root = Tk()# objeto da aplicação
frm = ttk.Frame(root, padding=100)# cria o espaço retangualar onde os widgets vão estar, padding define o tamanho e root sera o objeto pai de frame
frm.grid()# cria a grid dentro de frame
root.title("Relógio")
horas_alarme =[0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 
               11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 
               21, 22, 23]
minutos_alarme = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 
                  11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 
                  21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 
                  31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 
                  41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 
                  51, 52, 53, 54, 55, 56, 57, 58, 59]

set_horas = ttk.Combobox(root, values=horas_alarme)
set_horas.grid(column= 30,row=0)

set_minutos = ttk.Combobox(root, values=minutos_alarme)
set_minutos.grid(column= 40,row=0)

ttk.Button(frm, text="Sair", command=root.destroy).grid(column=30, row=40)

botao_desliga = ttk.Button(frm, text="Desligar Alarme", command=desativar_alarme)
botao_desliga.grid(column=20, row=40)

botao_alarme = ttk.Button(frm, text="Configurar alarme",command=definir_alarme)
botao_alarme.grid(column=10, row=40)

horario = ttk.Label(frm, text="")
alarme_status = ttk.Label(frm,text="")
alarme_status.grid(column=20, row=10)
horario.grid(column=10, row=10)# define a grid do label, nao pode ser colocado junto da inicialização do label na variavel, pois a função retorna None, e faz com que a variavel fique em None

atualizar_texto()

root.mainloop()