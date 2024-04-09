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

    if LMBpressed:
        screen.blit(baseLayer, (0, 0))  # Отрисовываем сохранённый слой на экране
        rect = calc_rect(prevX, curvX, prevY, curvY)
        circle_coords = calc_circle(prevX, prevY, curvX, curvY)
        pygame.draw.rect(screen, 'magenta', rect, 2)  # Рисуем прямоугольник на экране
        pygame.draw.circle(screen, 'orange', (circle_coords[0], circle_coords[1]), circle_coords[2])  # Рисуем круг
    pygame.display.flip()  # Обновляем экран
