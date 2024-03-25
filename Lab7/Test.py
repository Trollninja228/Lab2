import pygame
import math

pygame.init()

# Установка дисплея
screen = pygame.display.set_mode((800, 600))
clock = pygame.time.Clock()

# Загрузка изображения стрелки
arrow_image = pygame.image.load("Left_hand.png")
arrow_rect = arrow_image.get_rect()

# Определение параметров центра экрана
center = (400, 300)

angle = 0

# Главный игровой цикл
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # Очистка экрана
    screen.fill((0, 0, 0))

    # Поворот изображения стрелки
    rotated_arrow = pygame.transform.rotate(arrow_image, -angle)
    rotated_rect = rotated_arrow.get_rect(center=center)

    # Отрисовка повернутой стрелки
    screen.blit(rotated_arrow, rotated_rect)

    angle += 1
    if angle >= 360:
        angle = 0

    pygame.display.flip()
    clock.tick(60)

