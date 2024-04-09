import pygame
import random
pygame.init()
WIDTH=720
HEIGHT=720
FPS=pygame.time.Clock()
screen=pygame.display.set_mode((WIDTH,HEIGHT))
done=True
class Point:
    def __init__(self,x,y):
        self.x=x
        self.y=y
    def generate():
        return Point(random.randint(0,WIDTH//cell-1)*cell,random.randint(0,HEIGHT//cell-1)*cell)
class Snake:
    def __init__(self):
        self.body=[Point.generate()]
    def draw(self):
        head=self.body[0]
        pygame.draw.rect(screen,'green',(head.x,head.y,cell,cell))
        for segment in self.body[1:]:
            pygame.rect(screen,'yellow',(segment.x,segment.y,cell,cell))
cell=30
def draw_grid():
    for i in range(0,720,cell):
        for j in range(0,720,cell):
            pygame.draw.rect(screen,'gray',(i,j,cell,cell),1)
class Food:
    def __init__(self):
        self.pos=Point.generate()
        self.x=0
        self.y=0
    def draw(self):
        pygame.draw.rect(screen,'red',(self.pos.x,self.pos.y,cell,cell))
snake=Snake()
food=Food()
while done:
    for event in pygame.event.get():
        if event.type==pygame.QUIT:
            done=False
    draw_grid()
    snake.draw()
    food.draw()
    pygame.display.flip()
    FPS.tick(60)