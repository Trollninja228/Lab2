import pygame
pygame.init()
image=pygame.image.load("icon.ico")
screen=pygame.display.set_mode((1366,768))
done = False
x=30
y=60
clock=pygame.time.Clock()
while not done:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            done=True
    if event.type == pygame.KEYDOWN:
        if event.key == pygame.K_DOWN:
            y+=7
        if event.key == pygame.K_UP:
            y-=7
        if event.key == pygame.K_RIGHT:
            x+=7
        if event.key == pygame.K_LEFT:
            x-=7
        screen.fill((0,0,0))
        screen.blit(image,(x,y))
        pygame.display.flip()
        clock.tick(60)