import pygame
pygame.init()
done = True
screen=pygame.display.set_mode((800,800))
x=0
y=0
clock=pygame.time.Clock()
angle=1
clock=pygame.image.load("Clock2.PNG")
body=pygame.image.load("Body.png")
left=pygame.image.load("Left_hand.png")
right=pygame.image.load("Right_hand.png")
while done:
    for event in pygame.event.get():
        pass
    if event.type==pygame.QUIT:
        done = False
    screen.fill((0,0,0))
    screen.blit(clock,(x,y))
    screen.blit(body,(180,180))
    screen.blit(left,(142,246))
    screen.blit(right,(170,240))
    pygame.display.flip()