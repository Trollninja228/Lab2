import pygame
pygame.init()
pygame.mixer.init()
song1=pygame.mixer.Sound("C:/Users/Пчел/Desktop/Labs/Lab7/Music/Bedroom Prod, Frogmarionne feat. Yours Buttercup (YB) - ПЕШКИ.mp3")
song2=pygame.mixer.Sound("C:/Users/Пчел/Desktop/Labs/Lab7/Music/cloudfield - Fantasy (ft. Reichuu).mp3")
song3=pygame.mixer.Sound("C:/Users/Пчел/Desktop/Labs/Lab7/Music/Восход, Archmage Eternal, MrLololoshka feat. Размечталась, PryAnnya - Верный путь OST _Голос Времени_.mp3")
def play_sound(sound):
    sound.play()
pygame.display.set_mode((0, 0))
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
        elif event.type == pygame.KEYDOWN:
            if event.key == pygame.K_1:
                pygame.mixer.music.stop()
                play_sound(song1)
            if event.key == pygame.K_2:
                pygame.mixer.music.stop()
                play_sound(song2)
            if event.key == pygame.K_3:
                pygame.mixer.music.stop()
                play_sound(song3)
pygame.quit()
