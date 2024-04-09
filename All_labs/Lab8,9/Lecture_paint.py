import pygame
pygame.init()
prevX=-1
prevY=-1
curvX=-1
curvY=-1
LMBpressed=False
WIDTH=800
HEIGHT=480
baseLayear=pygame.Surface((WIDTH,HEIGHT))
screen=pygame.display.set_mode((WIDTH,HEIGHT))
done=True
def calculate_rect(x1,x2,y1,y2):
    return pygame.Rect(min(x1,x2),min(y1,y2), abs(x1-x2),abs(y1-y2))
while done:
    for event in pygame.event.get():
        if event.type==pygame.QUIT:
            done=False
    if event.type==pygame.MOUSEBUTTONDOWN and event.button==1:
        LMBpressed=True
        prevX=event.pos[0]
        prevY=event.pos[1]
        curvX=event.pos[0]
        curvY=event.pos[1]
    if event.type==pygame.MOUSEMOTION:
        if LMBpressed:
            curvX=event.pos[0]
            curvY=event.pos[1]
    if event.type==pygame.MOUSEBUTTONUP and event.button==1:
        LMBpressed=False
        curvX=event.pos[0]
        curvY=event.pos[1]
        baseLayear.blit(baseLayear,(0,0))
    #CTRL+/
    # if LMBpressed:
    #     screen.fill((0,0,0))
    if LMBpressed:
        screen.blit(baseLayear,(0,0))
        pygame.draw.rect(screen,('magenta'),calculate_rect(prevX,curvX,prevY,curvY),2)
    pygame.display.flip()