import pygame
import random
def randomizer():
     return random.randint(50,350)
pygame.init()
done=True
screen=pygame.display.set_mode((400,600))
FPS=pygame.time.Clock()
x=175
y=510
speed=5
background=pygame.image.load("C:/Users/Пчел/Desktop/Labs/Lab8/Racer/AnimatedStreet.png")
background_music=pygame.mixer.Sound("C:/Users/Пчел/Desktop/Labs/Lab8/Racer/background.wav")
enemy=pygame.sprite.Sprite()
player=pygame.sprite.Sprite()
player.image=pygame.image.load("C:/Users/Пчел/Desktop/Labs/Lab8/Racer/Player.png")
enemy.image=pygame.image.load("C:/Users/Пчел/Desktop/Labs/Lab8/Racer/Enemy.png")
player.rect=player.image.get_rect()
background_music.play(-1)
pygame.display.set_caption("Sad story")
enemies=pygame.sprite.Group()
players=pygame.sprite.Group()
enemies.add(enemy)
players.add(player)
enemy_y=0
enemy_x=randomizer()
enemy.rect=enemy.image.get_rect()
enemy.rect.center=(enemy_x,enemy_y)
while done:
    pygame.draw.rect(screen,'red',enemy.rect,10)
    print(enemy.rect[3])
    if pygame.sprite.spritecollideany(player,enemies):
        done=False
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
    enemy.rect.center=(enemy_x,enemy_y)
    if speed==600 or speed>600:
        speed=0
        enemy_x=randomizer()
        enemy_y=0
        screen.blit(enemy.image,(enemy_x,enemy_y))
    else:
        enemy.rect.move_ip(0,speed)
        speed+=5
    screen.blit(enemy.image,enemy.rect)
    screen.blit(player.image,(x,y))
    pygame.display.flip()
    FPS.tick(60)