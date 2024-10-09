import pygame

pygame.init()
pygame.mixer.init()

song1 = "C:/Users/Пчел/Desktop/Labs/All_labs/python/Lab7/Music/Bedroom Prod, Frogmarionne feat. Yours Buttercup (YB) - ПЕШКИ.mp3"
song2 = "C:/Users/Пчел/Desktop/Labs/All_labs/python/Lab7/Music/cloudfield - Fantasy (ft. Reichuu).mp3"
song3 = "C:/Users/Пчел/Desktop/Labs/All_labs/python/Lab7/Music/Восход, Archmage Eternal, MrLololoshka feat. Размечталась, PryAnnya - Верный путь OST _Голос Времени_.mp3"

pygame.display.set_mode((100, 100))
running = True
pause=False
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
        elif event.type == pygame.KEYDOWN:
            if event.key==pygame.K_SPACE:
                if pause==False:
                    pause=True
                    pygame.mixer.music.pause()
                else:
                    pause=False
                    pygame.mixer.music.unpause()
            if event.key == pygame.K_1:
                pygame.mixer.music.stop()
                pygame.mixer.music.load(song1)
                pygame.mixer.music.play()
            elif event.key == pygame.K_2:
                pygame.mixer.music.stop()
                pygame.mixer.music.load(song2)
                pygame.mixer.music.play()
            elif event.key == pygame.K_3:
                pygame.mixer.music.stop()
                pygame.mixer.music.load(song3)
                pygame.mixer.music.play()

pygame.quit()
