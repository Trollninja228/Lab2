import pygame
pygame.init()
done = True
screen=pygame.display.set_mode((800,800))
x=0
y=0
clock=pygame.time.Clock()
angle=0
clock=pygame.image.load("Clock2.PNG")
body=pygame.image.load("Body.png")
left=pygame.image.load("Left_hand.png")
right=pygame.image.load("Right_hand.png")
left_r=left.get_rect()
center=(400,400)
while done:
    for event in pygame.event.get():
        pass
    if event.type==pygame.QUIT:
        done = False
    screen.fill((0,0,0))
    r_left=pygame.transform.rotate(left,-angle)
    r_rect_left=r_left.get_rect(center=center)
    r_right=pygame.transform.rotate(right,-angle)
    r_rect_right=r_right.get_rect(center=center)
    screen.blit(clock,(x,y))
    screen.blit(body,(180,180))
    screen.blit(r_left,r_rect_left)
    screen.blit(r_right,r_rect_right)
    angle+=1
    pygame.display.flip()