from datetime import datetime, time
from tkinter import *
from tkinter import ttk
import pygame

# Inicializa o pygame
pygame.init()

# Carrega o som
pygame.mixer.init()
som = pygame.mixer.Sound("audio.mp3") 

som_tocando = False
def tocar_som():
    global som_tocando
    som_tocando = False
    if som_tocando == False:
        som_tocando = True
        som.play()
        root.after(int(som.get_length()*1000), tocar_som)

        

def atualizar_texto():

    hora_atual = datetime.now().strftime("%H:%M:%S")# ultil.iza a biblioteca date time para salvar o horario atual
    
    horario.config(text = hora_atual)# dentro do label em horario, limpa ele e insere o novo horario
    
    root.after(1000, atualizar_texto)# chama a propria função apos 1 segundo para atualização do label

def verifica_alarme():
    hora_atual = datetime.now()
    if hora_atual.hour == a.hour and hora_atual.minute == a.minute:
        alarme.config(text = "Alarme ativado!")
        tocar_som 
    root.after(1000, verifica_alarme)

root = Tk()# objeto da aplicação
frm = ttk.Frame(root, padding=100)# cria o espaço retangualar onde os widgets vão estar, padding define o tamanho e root sera o objeto pai de frame
frm.grid()# cria a grid dentro de frame

a = time(11,22)
horas_alarme =[0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]

ttk.Button(frm, text="Quit", command=root.destroy).grid(column=10, row=40)
botao = ttk.Button(frm, text="Desligar Alarme", command=tocar_som)
botao.grid(column=20, row=40)

set_horas = ttk.Combobox(root, values=horas_alarme)
set_horas.grid(column= 30,row=0)

horario = ttk.Label(frm, text="")
alarme = ttk.Label(frm,text="")
alarme.grid(column=20, row=10)
horario.grid(column=10, row=10)# define a grid do label, nao pode ser colocado junto da inicialização do label na variavel, pois a função retorna None, e faz com que a variavel fique em None

atualizar_texto()
verifica_alarme()



root.mainloop()












"""while(1):
    hora_atual = datetime.now().time()
    print(f"Horario: {hora_atual.hour}:{hora_atual.minute}")
    sleep(1)
    
def set_Alarme(H,M):
    return time(H,M)
"""
    





'''if hora_atual.hour == alarme.hour and hora_atual.minute == alarme.minute:
        print("ACORDAAAAAAAAA")
        break
'''