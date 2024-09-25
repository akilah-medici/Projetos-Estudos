import pygame, sys, os

doggo_pos_x = 250
doggo_pos_y = 150

width = 1200
height = 720

class Game:
    def __init__(self):
        self.doggos = 0
        self.doggos_per_click = 100
        self.doggos_per_second = 1
        self.doggo = pygame.Rect(doggo_pos_x,doggo_pos_y,300,300)# desenha um retangulo onde sera o objeto do doggo
        self.doggo.center = (width//2,height//2)
        self.doggo_color = "#522920" # string de cor

        self.initial_time = pygame.time.get_ticks()

        self.clicked = False
        self.sound_isPlaying = False

        self.num_up_1 = 0
        self.num_up_2 = 0
        self.upgrade_value = [10,200,1000]

        self.upgrade1_purchasable = False
        self.upgrade2_purchasable = False
        self.upgrade3_purchasable = False

        self.actual_upgrade = 0

        self.buy_button_up = pygame.Rect(0, 0, 170, 50)
        self.buy_button_up_2 = pygame.Rect(0, 0, 170, 50)
        self.buy_button_up_3 = pygame.Rect(0,0,0,0)
        self.buy_button_up_4 = pygame.Rect(0,0,0,0)
        self.buy_button_up_5 = pygame.Rect(0,0,0,0)
        self.buy_button_up_6 = pygame.Rect(0,0,0,0)

        self.menu_button = pygame.Rect(200,height/2,40,40)

        self.menu = False

        self.upgrade_state = [0,0,0]
        
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
        self.txt_up_menu = text_font.render("=",True,"#ffffff")

        self.txt_centralized = self.txt_up_menu.get_rect()
        self.txt_centralized.center = self.menu_button.center
        self.txt_centralized.y -=4

        pygame.draw.rect(screen,"#000000",self.menu_button)
        screen.blit(self.txt_up_menu,self.txt_centralized)

    def drawn_score(self):
        self.display_cookies = text_font.render(f"Doggos:{str(self.doggos)}",True,"#000000")
        self.text = self.display_cookies.get_rect()
        self.text.center=(width//2,80)
        screen.blit(self.display_cookies,self.text)
       
    def draw_upgrade_tab(self):
        self.tab = pygame.Rect(0,0,200,height)
        pygame.draw.rect(screen,"#000000",self.tab)

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
    
    def draw_price(self,i,x,y):
        price = str(self.upgrade_value[i])
        self.price = pygame.Rect(self.buy_button_up.x+x,self.buy_button_up.y+y,40,20)
        self.text_price = ui_text_menu.render(price,True,"#000000")
        screen.blit(self.text_price,self.price)

    def upgrade_1(self):
        self.num_up_1 = self.num_up_1 + 1
        self.doggos -= self.upgrade_value[0]
        self.actual_upgrade = 2
        self.doggos_per_click = self.doggos_per_click+2
        self.upgrade_value[0] = (self.upgrade_value[0]+self.num_up_1*2)    

        '''print("Upgrade 1 comprado")
        print(f"doggos per click : {self.doggos_per_click}")
        print(f"total upgrades: {self.num_up_1}")
        print(f"up1 price : {self.upgrade_value[0]}")
        print(f"actual upgrades: {self.actual_upgrade}")'''

    def upgrade_2(self):
        actual_time = pygame.time.get_ticks()
        if (actual_time - self.initial_time) >= 1000:
            self.doggos=self.doggos+(self.doggos_per_second*self.num_up_2)
            self.initial_time = actual_time
                   
    def buy_verification(self,d,up):
        match(up):
            case 1:
                if d >= self.upgrade_value[0]: 
                    self.draw_buy_button(10,10,"#ffffff","#00ff00",self.buy_button_up)
                    return True
            case 2:
                if d >= self.upgrade_value[1]: 
                    self.draw_buy_button(10,70,"#ffffff","#00ff00",self.buy_button_up_2)
                    return True
        return False

    def buy_upgrades(self):
        if self.buy_button_up.collidepoint(pygame.mouse.get_pos()):
            if self.buy_verification(self.doggos,self.upgrade_state[0]):
                if event.type == pygame.MOUSEBUTTONDOWN and self.clicked == False:
                    self.clicked = True
                    self.upgrade_1()

                elif event.type == pygame.MOUSEBUTTONUP and self.clicked == True :
                    self.clicked = False

        if self.buy_button_up_2.collidepoint(pygame.mouse.get_pos()):
            if self.buy_verification(self.doggos,self.upgrade_state[1]):
                if event.type == pygame.MOUSEBUTTONDOWN and self.clicked == False:
                    self.clicked = True
                    self.num_up_2+=1
                    self.upgrade_value[1] = (self.upgrade_value[1]+self.num_up_2*2) 
                    self.doggos -= self.upgrade_value[1]

                elif event.type == pygame.MOUSEBUTTONUP and self.clicked == True :
                    self.clicked = False 
        
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
        if self.doggos >= 5:
                self.upgrade1_purchasable = True
                self.upgrade_state[0] = 1

        if self.doggos >= 200:
                self.upgrade2_purchasable = True
                self.upgrade_state[1] = 2

        if self.upgrade1_purchasable == True:
            self.draw_buy_button(10,10,"#000000","#ffffff",self.buy_button_up)
            self.draw_price(0,140,20)
                        
        if self.upgrade2_purchasable == True:
            self.draw_buy_button(10,70,"#000000","#ffffff",self.buy_button_up_2)
            self.draw_price(1,140,80)
            
    def render(self):
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

sprite_list = [game.load_sprite("doggo1.png"),game.load_sprite("doggo2.png"),game.load_sprite("doggo3.png"),game.load_sprite("doggo4.png")]
sprite_image = sprite_list[game.actual_upgrade]

# define tamanho e tipo dos textos
text_font = pygame.font.Font(None,40)
ui_text_menu = pygame.font.Font(None,20)

title = text_font.render("DoggoClicker",True,"#000000")
title_rect = title.get_rect()
title_rect.center = (width//2,30)

# define clock
clock = pygame.time.Clock()

# run time do pygame
while True:
    screen.fill("#ffffff")
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit
    screen.blit(title, title_rect)

    game.render()

    pygame.display.update()
    clock.tick(60)

    '''def draw_buy_button_2(self,x,y,c):
        self.buy_button_up_2 = pygame.Rect(self.tab.x+x,self.tab.y+y,170,50)
        txt = ui_text_menu.render("Comprar",True,c)
        txt_center = txt.get_rect()
        txt_center.center = self.buy_button_up.center
        screen.blit(txt,txt_center)'''