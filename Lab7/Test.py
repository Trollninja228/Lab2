import pygame
import sys
import math

pygame.init()

# Set up the display
screen = pygame.display.set_mode((800, 600))
clock = pygame.time.Clock()

# Define the rectangle
rect_width = 100
rect_height = 200
rect = pygame.Rect(0, 0, rect_width, rect_height)
rect.center = (400, 300)  # Center of the screen
color = (0, 255, 0)

angle = 0

# Main game loop
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # Clear the screen
    screen.fill((0, 0, 0))

    # Calculate the new position of the rectangle after rotation
    angle_rad = math.radians(angle)
    rotated_x = rect.centerx + math.cos(angle_rad) * (rect.width / 2)
    rotated_y = rect.centery - math.sin(angle_rad) * (rect.height / 2)

    # Create the rotated rectangle
    rotated_rect = pygame.Rect(0, 0, rect.width, rect.height)
    rotated_rect.center = (rotated_x, rotated_y)

    # Draw the rotated rectangle onto the screen
    pygame.draw.rect(screen, color, rotated_rect)

    angle += 1
    if angle >= 360:
        angle = 0

    pygame.display.flip()
    clock.tick(60)

pygame.quit()
sys.exit()
