import pygame, sys

class Game:
    def __init__(self):
        self.doggos = 0
        self.doggos_per_click = 1
        self.doggo = pygame.Rect(400,400,300,300)
        self.doggo_color = "#522920"
        self.clicked = False
    def click_button(self):
        self.mouse_pos = pygame.mouse.get_pos()
        if self.cookie.collidepoint(self.mouse_pos):
            print("colidiu")
        pygame.draw.rect(screen,self.doggo_color,self.doggo,border_radius=150)    

pygame.init()

width = 800
height = 600

game = Game()

screen = pygame.display.set_mode(size = (width,height))
pygame.display.set_caption("DoggoClicker")
text_font = pygame.font.Font(None,50)
title = text_font.render("DoggoClicker",True,"#000000")
clock = pygame.time.Clock()

while True:
    screen.fill("#ffffff")
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit
    screen.blit(title, (270,15))
    pygame.display.update()
    clock.tick(60)