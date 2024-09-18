from kivy.app import App
from kivy.uix.boxlayout import BoxLayout
from kivy.core.window import Window
from kivy.uix.image import Image
#ids 
# tot,calc,sai,qt1,qt2,limp,pag
# 1 camisa gucci, 
# 2 calça versace, 
# 3 moletom the noth, 
# 4 sapato offwithe, 
# 5 bone nike, 
# 6 óculos juliette

class Tela (BoxLayout):
    def __init__(self, **kwargs):
        super().__init__(**kwargs)
        self.produ= {'camisa':0,'calça':0,'moletom':0,'sapato':0,'bone':0,'oculos':0}
        self.total = 0
        self.desconto = 0
        self.juros = 0

    def calcula_total(self):
        try:   
            qtd1= self.ids.qt1.text
            qtd2= self.ids.qt2.text
            qtd3= self.ids.qt3.text
            qtd4= self.ids.qt4.text
            qtd5= self.ids.qt5.text
            qtd6= self.ids.qt6.text
            
        
            total1 = self.produ['camisa']*int(qtd1)
            total2 = self.produ['calça']*int(qtd2)
            total3 = self.produ['moletom']*int(qtd3)
            total4 = self.produ['sapato']*int(qtd4)
            total5 = self.produ['bone']*int(qtd5)
            total6 = self.produ['oculos']*int(qtd6)

            self.total = total1+total2+total3+total4+total5+total6
            desconto = self.desconto *self.total
            juros = self.juros*self.total
            
            while self.total!=0:
                self.total -=desconto
                self.total += juros
                break
            self.ids.tot.text = f'O valor da compra do senhor(a) {self.ids.nome.text} totalizou: R$ {str(round(self.total,2))}'

        except ValueError:
            self.ids.tot.text = 'Digite uma quantidade valida'
             
        print(f'{round(self.juros,2)}:{round(self.desconto,2)}')

    def marca_produto(self,produto,ativo,valor):
        if ativo:
            self.produ[produto] = valor
            print(self.produ)
        else:
            self.produ[produto] = 0
            print(self.produ)

    def desconto_pagamento(self):
        selecionado = self.ids.pag.text
        self.desconto=0
        self.juros = 0
        if selecionado == 'Dinheiro(á vista)':
            self.desconto = 0.05
        if selecionado == 'Pix(á vista)':
            self.desconto = 0.10
        if selecionado == 'Cartão(á vista)':
            self.desconto = 0.08 
        if selecionado == 'Cartão(2x com juros)':
            self.juros = 0.02
        print(f'juros {self.juros}: porcentagem {self.desconto}')

    def limpa(self):
        self.ids.tot.text = ''
        self.ids.qt1.text = '0'
        self.ids.qt2.text = '0'
        self.ids.qt3.text = '0'
        self.ids.qt4.text = '0'
        self.ids.qt5.text = '0'
        self.ids.qt6.text = '0'
        self.ids.nome.text = 'Digite seu nome.'
        self.ids.box1.active = False
        self.ids.box2.active = False
        self.ids.box3.active = False
        self.ids.box4.active = False
        self.ids.box5.active = False
        self.ids.box6.active = False
        self.ids.pag.text = 'Escolha a forma de pagamento'
        print('chamado')

    def sair(self):
        ListaApp.get_running_app().stop()
        print('chamado')
        
class ListaApp(App):
    def build(self):
        self.title = "Loja Goosebumps"
        Window.size = (600,500)
        
        return Tela()

ListaApp().run()