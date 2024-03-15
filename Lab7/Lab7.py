import pygame
pygame.init()
done = True
screen=pygame.display.set_mode((800,600))
x=0
y=0
clock=pygame.time.Clock()
angle=1
image=pygame.image.load("mickeyclock.jpeg")
while done:
    for event in pygame.event.get():
        pass
    if event.type==pygame.QUIT:
        done = False
    if event.type==pygame.KEYDOWN:
        if event.key==pygame.K_UP:
            y-=10
        if event.key==pygame.K_DOWN:
            y+=10
        if event.key==pygame.K_RIGHT:
            x+=10
        if event.key==pygame.K_LEFT:
            x-=10
    screen.fill((0,0,0))
    
    clock.tick(60)