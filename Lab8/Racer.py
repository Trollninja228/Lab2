import pygame
import random
def randomizer():
     return random.randint(50,350)
pygame.init()
done=True
screen=pygame.display.set_mode((400,600))
FPS=pygame.time.Clock()
font = pygame.font.SysFont("Times New Roman", 60)
game_over=font.render("WASTED",True,'black')
x=175
y=550
speed=10
score=0
background=pygame.image.load("C:/Users/Пчел/Desktop/Labs/Lab8/Racer/AnimatedStreet.png")
background_music="C:/Users/Пчел/Desktop/Labs/Lab8/Racer/background.wav"
crash="C:/Users/Пчел/Desktop/Labs/Lab8/Racer/wasted.mp3"
pygame.mixer.music.load(background_music)
pygame.mixer.music.play(-1)
pygame.display.set_caption("Sad story")
class Enemy(pygame.sprite.Sprite):
    def __init__(self):
        super().__init__()
        self.image=pygame.image.load("C:/Users/Пчел/Desktop/Labs/Lab8/Racer/Enemy.png")
        self.rect=self.image.get_rect()
        self.rect.center=(randomizer(),0)
    def move(self):
        global score
        self.rect.move_ip(0,speed)
        if(self.rect.top>600):
            score+=1
            self.rect.top=0
            self.rect.center=(randomizer(),0)
class Player(pygame.sprite.Sprite):
    def __init__(self):
        super().__init__()
        self.image=pygame.image.load("C:/Users/Пчел/Desktop/Labs/Lab8/Racer/Player.png")
        self.rect=self.image.get_rect()
        self.rect.center=(x,y)
    def move(self):
        if not self.rect.left==0:
            if not self.rect.right==400:
                key=pygame.key.get_pressed()
                if key[pygame.K_a]:
                    self.rect.move_ip(-speed,0)
                if key[pygame.K_d]:
                    self.rect.move_ip(speed,0)
enemies=pygame.sprite.Group()
players=pygame.sprite.Group()
enemy=Enemy()
player=Player()
enemies.add(enemy)
players.add(player)
while done:
    for event in pygame.event.get():
        if event.type==pygame.QUIT:
            done=False
    screen.blit(background,(0,0))
    Score=font.render(str(score),True,'black')
    screen.blit(Score,(10,10))
    player.move()
    enemy.move()
    screen.blit(player.image,player.rect)
    screen.blit(enemy.image,enemy.rect)
    if pygame.sprite.spritecollideany(player,enemies):
        pygame.mixer.music.stop()
        pygame.mixer.music.load(crash)
        pygame.mixer.music.play()
        screen.fill('red')
        screen.blit(game_over,(60,250))
        pygame.display.flip()
        FPS.tick(1)
        FPS.tick(2)
        done=False
    pygame.display.flip()
    FPS.tick(60)