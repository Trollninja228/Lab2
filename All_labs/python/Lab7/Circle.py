import pygame
pygame.init()
mx=1366
my=768
screen=pygame.display.set_mode((mx,my))
done = False
x=100
y=40
clock=pygame.time.Clock()
screen.fill((255,255,255))
pygame.draw.circle(screen,(255,0,0),(x,y),25)
pygame.display.flip()
while not done:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            done=True
    if event.type == pygame.KEYDOWN:
        if event.key == pygame.K_DOWN:
            if not y+25==my:
                y+=1
        if event.key == pygame.K_UP:
            if not y-25==0:
                y-=1
        if event.key == pygame.K_RIGHT:
            if not x+25==mx:
                x+=1
        if event.key == pygame.K_LEFT:
            if not x-25==0:
                x-=1
        screen.fill((255,255,255))
        pygame.draw.circle(screen,(255,0,0),(x,y),25)
        pygame.display.flip()
        clock.tick(200)