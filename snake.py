from pygame.locals import *
import pygame

class Player:
    x = 10
    y = 10
    speed = 1
    
    def moveRight(self):
        self.x = self.x + self.speed
    def moveLeft(self):
        self.x = self.x + self.speed
    def moveUp(self):
        self.y = self.y - self.speed
    def moveDown(self):
        self.y = self.y + self.speed

class App:
    windowWidth = 800
    windowHeight = 600
    player = 0
    
    def __init__(self):
        self._running = True
        self._display_surf = None
        self._image_surf = None
        self.player = player()
    def on_init(self):
        pygame.init()
        self._display_surf = pygame.display.set_mode((self.windowWidth, self.windowHeight),
        pygame.display.set_caption('Sup guys dis is a simple snek gaem'))
