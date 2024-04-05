import pygame
import random
pygame.init()
WIDTH=720
HEIGHT=720
FPS=pygame.time.Clock()
screen=pygame.display.set_mode((WIDTH,HEIGHT))
done=True
cell=30
class Point:
    def __init__(self,x,y):
        self.x=x
        self.y=y
    def generate():
        return Point(random.randint(0,WIDTH//cell-1)*cell,random.randint(0,HEIGHT//cell-1)*cell)
class Snake:
    def __init__(self):
        self.body=[Point.generate()]
        self.dx=1
        self.dy=0
    def draw(self):
        head=self.body[0]
        pygame.draw.rect(screen,'green',(head.x,head.y,cell,cell))
        for segment in self.body[1:]:
            pygame.draw.rect(screen,'yellow',(segment.x,segment.y,cell,cell))
    def move(self):
        for i in range(len(self.body)-1,0,-1):
            if not i==1:
                if self.body[i].x==self.body[0].x and self.body[i].y==self.body[0].y:
                    pygame.draw.circle(screen,'red',(360,360),100,10)
            self.body[i].x=self.body[i-1].x
            self.body[i].y=self.body[i-1].y
        self.body[0].x+=self.dx*cell
        self.body[0].y+=self.dy*cell
        self.body[0].x %= WIDTH
        self.body[0].y %= HEIGHT
    def grow(self):
        self.body.insert(0, Point(self.body[0].x, self.body[0].y))
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
    def regenerate(self):
        self.pos=Point.generate()
        self.x=0
        self.y=0
snake=Snake()
food=Food()
snake.grow()
while done:
    if food.pos.x==snake.body[0].x and food.pos.y==snake.body[0].y:
        food.regenerate()
        snake.grow()
    for event in pygame.event.get():
        if event.type==pygame.QUIT:
            done=False
    if event.type==pygame.KEYDOWN:
        if event.key == pygame.K_RIGHT:
            if not snake.dx==-1:
                snake.dx=1
                snake.dy=0
        elif event.key == pygame.K_LEFT:
            if not snake.dx==1:
                snake.dx=-1
                snake.dy=0
        elif event.key == pygame.K_UP:
            if not snake.dy==1:
                snake.dx=0
                snake.dy=-1
        elif event.key == pygame.K_DOWN:
            if not snake.dy==-1:
                snake.dx=0
                snake.dy=1
    screen.fill((0,0,0))
    draw_grid()
    snake.draw()
    food.draw()
    snake.move()
    pygame.display.flip()
    FPS.tick(10)