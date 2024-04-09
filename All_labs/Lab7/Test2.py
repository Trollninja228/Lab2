import pygame
pygame.init()
pygame.display.set_mode((200, 200))
pygame.mixer.init()
song1=pygame.mixer.Sound("C:/Users/Пчел/Desktop/Labs/Lab7/Music/Bedroom Prod, Frogmarionne feat. Yours Buttercup (YB) - ПЕШКИ.mp3")
song2=pygame.mixer.Sound("C:/Users/Пчел/Desktop/Labs/Lab7/Music/cloudfield - Fantasy (ft. Reichuu).mp3")
song3=pygame.mixer.Sound("C:/Users/Пчел/Desktop/Labs/Lab7/Music/Восход, Archmage Eternal, MrLololoshka feat. Размечталась, PryAnnya - Верный путь OST _Голос Времени_.mp3")
def play_song(song_file):
    pygame.mixer.music.load(song_file)
    pygame.mixer.music.play(-1)

# Функция для остановки воспроизведения песни
def stop_song():
    pygame.mixer.music.stop()

# Запуск песни
play_song("C:/Users/Пчел/Desktop/Labs/Lab7/Music/Bedroom Prod, Frogmarionne feat. Yours Buttercup (YB) - ПЕШКИ.mp3")

# Основной игровой цикл
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
        elif event.type == pygame.KEYDOWN:
            # Переключение между песнями при нажатии клавиши
            if event.key == pygame.K_1:
                stop_song()  # Остановка текущей песни
                play_song("C:/Users/Пчел/Desktop/Labs/Lab7/Music/Bedroom Prod, Frogmarionne feat. Yours Buttercup (YB) - ПЕШКИ.mp3")  # Воспроизведение новой песни
            if event.key == pygame.K_2:
                stop_song()  # Остановка текущей песни
                play_song("C:/Users/Пчел/Desktop/Labs/Lab7/Music/cloudfield - Fantasy (ft. Reichuu).mp3")  # Воспроизведение новой песни

pygame.quit()
