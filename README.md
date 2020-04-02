# !!!
## THIS PROJECT WAS MOVED TO github.com/hazer-hazer/knotge

# KnotGE
Knot Game Engine


## Framework

### Object control system

Knot is using Node Object-control system.
It means that every game logic element is a Node or its child.
For example:
> Node (Scene)
> > Node2D (Player)
> > > Sprite
> > > CollisionShape2D

### Object
Object is main class that should be inherited by every game-cycle.
Vector2 and another helpers do not need to be inherited.

Object inherits EventHandler, because every game-cycle object can have events.


### Node
Node is the main class as a part of scene tree.

### Input
Input is a usefull class that works with all events like mouse events, keyboard event and etc.
It inherit EventHandler so it can emit events as function.
In game logic when you want to do something when event is emitted
you can just push event to Input like that:
```
input.on("EVENT_NAME", [-CAPTURED VARIABLES-](){
	// The code
});
```
Input automatically emits all events that have any functions in its stack.

## Future notes
- Using emscripten for converting engine code to WebAsm
- Particles preprocess

## Dev Notes

[Engine cycle]
* Input
* Game Logic
* Camera updating
* Objects updating (movement, states and etc.)
* GUI updating
* Audio
* Rendering

## Ideas
- Add CommandLine Node or whatever for ease creating IO in game with text

## Helpful links

Engine structure:
- https://www.gamasutra.com/blogs/MichaelKissner/20151027/257369/Writing_a_Game_Engine_from_Scratch__Part_1_Messaging.php

Particle system:
- https://github.com/SFML/SFML/wiki/Source:-Particle-System-for-SFML-2

