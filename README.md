# Keezboard research

This repository contains some code that I use
to do some research towards the dutch board/card
game 'keezen'.

Its written in C and can be compiled using the
following gcc command

```
gcc keez.c -o keez
```

The main thing I want to research is how effective
different strategies are in terms of
- Choosing what card to play
- Choosing what pawns to swap
- Choosing what pawns to run

I then use monte carlo simulations to see the 
effectiveness of one strategy against another.