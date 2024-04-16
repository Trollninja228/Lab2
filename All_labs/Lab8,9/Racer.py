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
n_coins=0
background=pygame.image.load("C:/Users/Пчел/Desktop/Labs/All_Labs/Lab8,9/Racer/AnimatedStreet.png")
background_music="C:/Users/Пчел/Desktop/Labs/All_Labs/Lab8,9/Racer/background.wav"
crash="C:/Users/Пчел/Desktop/Labs/All_Labs/Lab8,9/Racer/wasted.mp3"
pygame.mixer.music.load(background_music)
pygame.mixer.music.play(-1)

pygame.display.set_caption("Sad story")
class Enemy(pygame.sprite.Sprite):
    def __init__(self):
        super().__init__()
        self.image=pygame.image.load("C:/Users/Пчел/Desktop/Labs/All_Labs/Lab8,9/Racer/Enemy.png")
        self.rect=self.image.get_rect()
        self.rect.center=(randomizer(),0)
    def move(self):
        global score
        self.rect.move_ip(0,speed)
        if(self.rect.top>600):
            score+=1
            self.rect.top=0
            self.rect.center=(randomizer(),0)
class Coin(pygame.sprite.Sprite):
    def __init__(self):
        super().__init__()
        self.out=False
        self.image=pygame.image.load("C:/Users/Пчел/Desktop/Labs/All_Labs/Lab8,9/Racer/coin.png")
        self.rect=self.image.get_rect()
        self.rect.center=(randomizer(),0)
    def move(self):
        global score
        if not self.out:
            self.rect.move_ip(0,speed)
        if(self.rect.top>700):
            self.out=True
            if random.randint(0,100)==99:
                self.rect.center=(randomizer(),0)
                self.out=False
    def regenerate(self):
        self.rect.center=(randomizer(),0)
class Player(pygame.sprite.Sprite):
    def __init__(self):
        super().__init__()
        self.image=pygame.image.load("C:/Users/Пчел/Desktop/Labs/All_Labs/Lab8,9/Racer/Player.png")
        self.rect=self.image.get_rect()
        self.rect.center=(x,y)
    def move(self):
        key=pygame.key.get_pressed()
        if not self.rect.left<0:
            if key[pygame.K_a]:
                self.rect.move_ip(-speed,0)
        if not self.rect.right>400:
            if key[pygame.K_d]:
                self.rect.move_ip(speed,0)
        if not self.rect.top<0:
            if key[pygame.K_w]:
                self.rect.move_ip(0,-speed)
        if not self.rect.bottom>600:
            if key[pygame.K_s]:
                self.rect.move_ip(0,speed)
enemies=pygame.sprite.Group()
players=pygame.sprite.Group()
buffs=pygame.sprite.Group()
coin=Coin()
enemy=Enemy()
player=Player()
enemies.add(enemy)
players.add(player)
buffs.add(coin)
while done:
    for event in pygame.event.get():
        if event.type==pygame.QUIT:
            done=False
    screen.blit(background,(0,0))
    Score=font.render(str(score),True,'black')
    t_n_coins=font.render(str(n_coins),True,'yellow')
    screen.blit(Score,(10,10))
    screen.blit(t_n_coins,(300,10))
    player.move()
    enemy.move()
    coin.move()  # Перемещение монеты перед отрисовкой
    screen.blit(player.image,player.rect)
    screen.blit(enemy.image,enemy.rect)
    screen.blit(coin.image,coin.rect)  # Отрисовка монеты после ее перемещения
    if pygame.sprite.spritecollideany(coin,players):
        coin.regenerate()
        n_coins+=1
    if pygame.sprite.spritecollideany(player,enemies):
        pygame.mixer.music.stop()
        pygame.mixer.music.load(crash)
        pygame.mixer.music.play()
        screen.fill('red')
        screen.blit(game_over,(60,250))
        pygame.display.flip()

        FPS.tick(1)
        done=False
    pygame.display.flip()
    FPS.tick(60)
