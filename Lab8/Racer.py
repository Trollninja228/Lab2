import pygame
import random
def randomizer():
     return random.randint(450,550)
pygame.init()
done=True
screen=pygame.display.set_mode((400,600))
FPS=pygame.time.Clock()
x=175
y=510
background=pygame.image.load("C:/Users/Пчел/Desktop/Labs/Lab8/Racer/AnimatedStreet.png")
background_music=pygame.mixer.Sound("C:/Users/Пчел/Desktop/Labs/Lab8/Racer/background.wav")
player=pygame.image.load("C:/Users/Пчел/Desktop/Labs/Lab8/Racer/Player.png")
enemy=pygame.image.load("C:/Users/Пчел/Desktop/Labs/Lab8/Racer/Enemy.png")
background_music.play(-1)
pygame.display.set_caption("Sad story")
# enemies=pygame.sprite.Group()
# players=pygame.sprite.Group()
# enemies.add(enemy)
# players.add(player)
while done:
    for event in pygame.event.get():
        if event.type==pygame.QUIT:
            done=False
    key=pygame.key.get_pressed()
    if key[pygame.K_a]:
        if not x-10==0 and not x-10<0:
            x-=10
    if key[pygame.K_d]:
        if not x+55==400 and not x+55>400:
            x+=10
    screen.blit(background,(0,0))
    screen.blit(player,(x,y))
    pygame.display.flip()
    FPS.tick(60)