import pygame
pygame.init()

prevX = -1
prevY = -1
curvX = -1
curvY = -1
LMBpressed = False
WIDTH = 800
HEIGHT = 480
baseLayer = pygame.Surface((WIDTH, HEIGHT))
screen = pygame.display.set_mode((WIDTH, HEIGHT))
done = True

def calc_rect(x1, x2, y1, y2):
    return pygame.Rect(min(x1, x2), min(y1, y2), abs(x1 - x2), abs(y1 - y2))
def calc_circle(x1,y1,x2,y2):
    centerX=abs(x1+x2)/2
    centerY=abs(y1+y2)/2
    radius=x2/2
    return [centerX,centerY,radius]
while done:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            done = False
        if event.type == pygame.MOUSEBUTTONDOWN and event.button == 1:
            LMBpressed = True
            prevX = event.pos[0]
            prevY = event.pos[1]
            curvX = event.pos[0]
            curvY = event.pos[1]
        if event.type == pygame.MOUSEMOTION:
            if LMBpressed:
                curvX = event.pos[0]
                curvY = event.pos[1]
        if event.type == pygame.MOUSEBUTTONUP and event.button == 1:
            LMBpressed = False
            curvX = event.pos[0]
            curvY = event.pos[1]
            baseLayer.blit(baseLayer, (0, 0))  # Сохраняем текущий слой в baseLayer

    if LMBpressed:
        screen.blit(baseLayer, (0, 0))  # Отрисовываем сохранённый слой на экране
        pygame.draw.rect(screen, 'magenta', calc_rect(prevX, curvX, prevY, curvY), 2)
        pygame.draw.circle(screen, 'orange', (calc_circle(prevX, curvX, prevY, curvY)[0],calc_circle(prevX, curvX, prevY, curvY)[1]),calc_circle(prevX, curvX, prevY, curvY)[2])
        
    pygame.display.flip()
