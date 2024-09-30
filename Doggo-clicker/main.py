import pygame, sys, os

doggo_pos_x = 250
doggo_pos_y = 150

width = 1200
height = 720

class Game:
    def __init__(self):
        self.doggos = 0
        self.doggos_per_click = 1
        self.doggos_per_second = 1
        self.doggo = pygame.Rect(doggo_pos_x,doggo_pos_y,300,300)# desenha um retangulo onde sera o objeto do doggo
        self.doggo.center = (width//2,height//2)
        self.doggo_color = "#522920" # string de cor

        self.initial_time = pygame.time.get_ticks()

        self.clicked = False
        self.sound_isPlaying = False

        self.num_up_1 = 0
        self.num_up_2 = 0
        self.num_up_3 = 0

        self.upgrade_value = [10,200,1000]

        self.upgrade1_purchasable = False
        self.upgrade2_purchasable = False
        self.upgrade3_purchasable = False

        self.actual_upgrade = 0

        self.buy_button_up = pygame.Rect(0,0,0,0)
        self.buy_button_up_2 = pygame.Rect(0,0,0,0)
        self.buy_button_up_3 = pygame.Rect(0,0,0,0)
        self.buy_button_up_4 = pygame.Rect(0,0,0,0)
        self.buy_button_up_5 = pygame.Rect(0,0,0,0)
        self.buy_button_up_6 = pygame.Rect(0,0,0,0)

        self.sousage_body = pygame.Rect(0,0,0,0)

        self.text_box = pygame.Rect(0,0,0,0)

        self.menu_button = pygame.Rect(200,height/2,40,40)

        self.menu = False

        self.upgrade_state = [0,0,0]
        self.upgrades_descriptions = ["Au! menta seu ganho de doggos em 2, legal né?!","Doggos por segundo? que bagunça!","Salsicha ao resgate! ele tem um segredo..."]
        self.upgrade_was_buyed = [0,0,0]
        
    def load_sound(self,sound_name):
        sound_path = os.path.join('sounds', sound_name)
        return pygame.mixer.Sound(sound_path)

    def load_sprite(self,image_name):
        image_path = os.path.join('sprites', image_name)
        return pygame.image.load(image_path).convert_alpha()

    def click_button(self):
        global sprite_list
        global sprite_image
        
        self.mouse_pos = pygame.mouse.get_pos()
        # comportamento doggo
        if self.doggo.collidepoint(self.mouse_pos):
            if event.type == pygame.MOUSEBUTTONDOWN and self.clicked == False:
                self.clicked = True
                self.doggos += self.doggos_per_click
                sprite_image= sprite_list[1+self.actual_upgrade]

                if self.sound_isPlaying == False:
                    self.sound_isPlaying = True
                    som.play()
                print(self.doggos)
                print(self.doggos_per_second)

            elif event.type == pygame.MOUSEBUTTONUP and self.clicked == True :
                self.clicked = False  
                sprite_image= sprite_list[self.actual_upgrade]
                self.sound_isPlaying = False
                
        screen.blit(sprite_image, self.doggo)

    def draw_menu_button(self,x):
        self.menu_button = pygame.Rect(x,height/2,40,40)
        self.txt_up_menu = text_font.render("=",True,"#DEF6D3")

        self.txt_centralized = self.txt_up_menu.get_rect()
        self.txt_centralized.center = self.menu_button.center
        self.txt_centralized.y -=4

        pygame.draw.rect(screen,"#332F2D",self.menu_button)
        screen.blit(self.txt_up_menu,self.txt_centralized)

    def drawn_score(self):
        self.display_doggos = text_font.render(f"Doggos:{self.doggos:.2f}",True,"#332F2D")
        self.text = self.display_doggos.get_rect()
        self.text.center=(width//2,80)
        screen.blit(self.display_doggos,self.text)
       
    def draw_upgrade_tab(self):
        self.tab = pygame.Rect(0,0,200,height)
        pygame.draw.rect(screen,"#332F2D",self.tab)

    def draw_buy_button(self,x,y,c1,c2,buy_button):
        buy_button.x = self.tab.x + x
        buy_button.y = self.tab.y + y
        buy_button.width = 170
        buy_button.height = 50

        txt = ui_text_menu.render("Comprar",True,c1)
        txt_center = txt.get_rect()
        txt_center.center = buy_button.center
        pygame.draw.rect(screen,c2, buy_button)
        screen.blit(txt,txt_center)

    def draw_upgrade_description(self,x,y,text,reference):
        text_box = pygame.Rect(reference.x+x,reference.y+y,350,30)
        txt = ui_text_menu.render(text,True,"#3A4546")
        txt_center = txt.get_rect()
        txt_center.center = text_box.center
        pygame.draw.rect(screen,"#B0744A",text_box,border_radius=5)
        screen.blit(txt,txt_center)

    def draw_price(self,i,x,y):
        price = str(self.upgrade_value[i])
        self.price = pygame.Rect(self.buy_button_up.x+x,self.buy_button_up.y+y,40,20)
        self.text_price = ui_text_menu.render(price,True,"#332F2D")
        screen.blit(self.text_price,self.price)

    def draw_upgrade_3(self,x,y,l,c):
        self.sousage_body = pygame.Rect(x+200,y+150,l*self.num_up_3,c) # x+200 y + 150 c 95
        pygame.draw.rect(screen,"#b88065",self.sousage_body)
        screen.blit(sprite_list_up3[0],(x,y))# x y
        screen.blit(sprite_list_up3[1],(x+l*self.num_up_3+200,y+150))#x+200+100*num_up_3,y+150
        
    def upgrade_1(self):
        self.num_up_1 = self.num_up_1 + 1
        self.doggos -= self.upgrade_value[0]
        self.doggos_per_click = self.doggos_per_click+2
        self.upgrade_value[0] = (self.upgrade_value[0]+self.num_up_1*2)    

    def upgrade_2(self):
        actual_time = pygame.time.get_ticks()
        if (actual_time - self.initial_time) >= 500:
            self.doggos=self.doggos+(self.doggos_per_second*self.num_up_2)
            self.initial_time = actual_time
                   
    def upgrade_3(self):
        # criar cachorro slacicha que aumenta com a quantidade de upgrades 
        # ele da um bonus ao doggos_per_secoond de 0.5x quantidade de salsicha
        self.upgrade_was_buyed[2] = 1
        bonus = 0.21*self.num_up_3
        self.doggos_per_second = self.doggos_per_second+bonus   

    def buy_verification(self,d,up):
        match(up):
            case 1:
                if d >= self.upgrade_value[0]: 
                    self.draw_buy_button(10,10,"#DEF6D3","#0B9548",self.buy_button_up)
                    return True
            case 2:
                if d >= self.upgrade_value[1]: 
                    self.draw_buy_button(10,70,"#DEF6D3","#0B9548",self.buy_button_up_2)
                    return True
            case 4:
                if d >= self.upgrade_value[2]: 
                    self.draw_buy_button(10,130,"#DEF6D3","#0B9548",self.buy_button_up_3)
                    return True
        return False

    def buy_upgrades(self):
        if self.buy_button_up.collidepoint(pygame.mouse.get_pos()):
            if self.buy_verification(self.doggos,self.upgrade_state[0]):
                if event.type == pygame.MOUSEBUTTONDOWN and self.clicked == False:
                    self.clicked = True
                    self.upgrade_1()
                    if self.upgrade_was_buyed[0] == 0:
                        self.upgrade_was_buyed[0] = 1
                        self.actual_upgrade = 2

                elif event.type == pygame.MOUSEBUTTONUP and self.clicked == True :
                    self.clicked = False
            self.draw_upgrade_description(140,40,self.upgrades_descriptions[0],self.buy_button_up)

        if self.buy_button_up_2.collidepoint(pygame.mouse.get_pos()):
            if self.buy_verification(self.doggos,self.upgrade_state[1]):
                if event.type == pygame.MOUSEBUTTONDOWN and self.clicked == False:
                    self.clicked = True
                    self.num_up_2+=1
                    self.doggos -= self.upgrade_value[1]
                    self.upgrade_value[1] = (self.upgrade_value[1]+self.num_up_2*2) 
                    if self.upgrade_was_buyed[1] == 0:
                        self.upgrade_was_buyed[1] = 1
                        self.actual_upgrade = 4
                    
                elif event.type == pygame.MOUSEBUTTONUP and self.clicked == True :
                    self.clicked = False 
            self.draw_upgrade_description(140,40,self.upgrades_descriptions[1],self.buy_button_up_2)

        if self.buy_button_up_3.collidepoint(pygame.mouse.get_pos()):
            if self.buy_verification(self.doggos,self.upgrade_state[2]):
                if event.type == pygame.MOUSEBUTTONDOWN and self.clicked == False:
                    self.clicked = True
                    self.num_up_3+=1
                    self.doggos -= self.upgrade_value[2]
                    self.upgrade_3()
                    self.upgrade_value[2] = (self.upgrade_value[2]+self.num_up_3*2) 
                    if self.upgrade_was_buyed[2] == 0:
                        self.upgrade_was_buyed[2] = 1
                        self.actual_upgrade = 4
                    
                elif event.type == pygame.MOUSEBUTTONUP and self.clicked == True :
                    self.clicked = False 
            self.draw_upgrade_description(140,40,self.upgrades_descriptions[2],self.buy_button_up_3) 
        
    def up_menu(self):
        if self.menu_button.collidepoint(self.mouse_pos):
            if event.type == pygame.MOUSEBUTTONDOWN:
                self.menu = not self.menu 
                print(self.menu)
        if self.menu:
            self.draw_menu_button(200)
        else:
            self.draw_menu_button(0)

    def upgrades_manager(self):
        if self.doggos >5:
                self.upgrade1_purchasable = True
                self.upgrade_state[0] = 1     
        if self.doggos >200:
                self.upgrade2_purchasable = True
                self.upgrade_state[1] = 2 
        if self.doggos >800:
                self.upgrade3_purchasable = True
                self.upgrade_state[2] = 4

        if self.upgrade1_purchasable == True:
            self.draw_buy_button(10,10,"#332F2D","#DEF6D3",self.buy_button_up)
            self.draw_price(0,145,20)                
        if self.upgrade2_purchasable == True:
            self.draw_buy_button(10,70,"#332F2D","#DEF6D3",self.buy_button_up_2)
            self.draw_price(1,140,80)
        if self.upgrade3_purchasable == True:
            self.draw_buy_button(10,130,"#332F2D","#DEF6D3",self.buy_button_up_3)
            self.draw_price(2,135,140)
            
    def render(self):
        if self.upgrade_was_buyed[2] ==1:
            if self.num_up_3<=1:
                self.draw_upgrade_3(800,300,50,95)  
            if self.num_up_3<=36:
                self.draw_upgrade_3(-800,150,50,95) 
                self.draw_upgrade_3(800,300,50,95)
            if self.num_up_3>=36:
                self.draw_upgrade_3(-2000,20,50,95)
                self.draw_upgrade_3(-800,150,50,95) 
                self.draw_upgrade_3(800,300,50,95)
                
        self.drawn_score()
        self.click_button()
        self.up_menu()
        if self.menu:
            self.draw_upgrade_tab()
            self.upgrades_manager()
            self.buy_upgrades()

        if self.num_up_2 > 0:
            self.upgrade_2()
        


# inicializa o pygame        
pygame.init()
pygame.mixer.init()

# inicializa a classe game e o screen de pygame
game = Game()
screen = pygame.display.set_mode(size = (width,height))
pygame.display.set_caption("DoggoClicker")

# carrega sons e sprites
som = game.load_sound('doggo_sound.wav')

sprite_list = [game.load_sprite("doggo1.png"),game.load_sprite("doggo2.png"),game.load_sprite("doggo3.png"),game.load_sprite("doggo4.png"),
               game.load_sprite("doggo5.png"),game.load_sprite("doggo6.png")]
sprite_image = sprite_list[game.actual_upgrade]

sprite_list_up3 = [game.load_sprite("sousage1.png"),game.load_sprite("sousage2.png")]
spr_h , spr_w = sprite_list_up3[0].get_size()


# define tamanho e tipo dos textos
text_font = pygame.font.Font(None,40)
ui_text_menu = pygame.font.Font(None,20)

title = text_font.render("DoggoClicker",True,"#332F2D")
title_rect = title.get_rect()
title_rect.center = (width//2,30)

# define clock
clock = pygame.time.Clock()

# run time do pygame
while True:
    screen.fill("#DEF6D3")
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit
    screen.blit(title, title_rect)

    game.render()

    pygame.display.update()
    clock.tick(120)
