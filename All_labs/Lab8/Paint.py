import pygame
pygame.init()

# Определение переменных и инициализация окна
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
tool=1
rad_of_er=5
color='orange'

def calc_rect(x1, x2, y1, y2):
    return pygame.Rect(min(x1, x2), min(y1, y2), abs(x1 - x2), abs(y1 - y2))

def calc_circle(x1, y1, x2, y2):
    centerX = (x1 + x2) / 2
    centerY = (y1 + y2) / 2
    radius = min(abs(x1 - x2) / 2, abs(y1 - y2) / 2)
    return centerX, centerY, radius

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
            baseLayer.blit(screen, (0, 0))  # Сохраняем текущий слой в baseLayer
        if event.type==pygame.KEYDOWN:
            if event.key==pygame.K_1:
                tool=1
            if event.key==pygame.K_2:
                tool=2
            if event.key==pygame.K_3:
                tool=3
            if event.key==pygame.K_KP_PLUS:
                rad_of_er+=2
            if event.key==pygame.K_KP_MINUS:
                rad_of_er+=-2
            if event.key==pygame.K_r:
                color="red"
            if event.key==pygame.K_b:
                color="blue"
            if event.key==pygame.K_g:
                color="green"
            if event.key==pygame.K_o:
                color="orange"
    if LMBpressed:
        if tool==3:
            pygame.draw.circle(screen, 'black',(curvX,curvY), rad_of_er)  # Ластик
        elif tool==1:
            screen.blit(baseLayer, (0, 0))  # Отрисовываем сохранённый слой на экране
            rect = calc_rect(prevX, curvX, prevY, curvY)
            pygame.draw.rect(screen, color, rect, 2)  # Рисуем прямоугольник на экране
        elif tool==2:
            screen.blit(baseLayer, (0, 0))  # Отрисовываем сохранённый слой на экране
            circle_coords = calc_circle(prevX, prevY, curvX, curvY)
            pygame.draw.circle(screen, color, (circle_coords[0], circle_coords[1]), circle_coords[2])  # Рисуем круг
    pygame.display.flip()  # Обновляем экран
