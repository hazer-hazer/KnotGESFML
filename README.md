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