import pygame
import datetime
pygame.init()
done = True
screen = pygame.display.set_mode((800, 800))
clock = pygame.time.Clock()
now = datetime.datetime.now()
x = 0
y = 0
angle_m =6 * (now.minute + now.second / 60)
angle_s =6 * now.second
clock_img = pygame.image.load("Clock2.PNG")
body_img = pygame.image.load("Body.png")
left_hand_img = pygame.image.load("Left_hand.png")
right_hand_img = pygame.image.load("Right_hand.png")
left_hand_rect = left_hand_img.get_rect()
center = (400, 400)
start_time = datetime.datetime.now()
start_time=start_time.replace(minute=0)
start_time=start_time.replace(second=0)
while done:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            done = False

    screen.fill((0, 0, 0))
    now = datetime.datetime.now()
    elapsed_time = (now - start_time).total_seconds()+530
    angle_m = (elapsed_time % 3600) / 10
    angle_s = (elapsed_time % 60) * 6
    r_left = pygame.transform.rotate(left_hand_img, -angle_s)
    r_rect_left = r_left.get_rect(center=center)
    r_right = pygame.transform.rotate(right_hand_img, -angle_m)
    r_rect_right = r_right.get_rect(center=center)
    screen.blit(clock_img, (x, y))
    screen.blit(body_img, (180, 180))
    screen.blit(r_left, r_rect_left)
    screen.blit(r_right, r_rect_right)
    pygame.display.flip()
    clock.tick(60)
