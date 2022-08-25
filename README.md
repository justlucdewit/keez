# Keezboard research

This repository contains some code that I use
to do some research towards the dutch board/card
game 'keezen'.

Its written in C and can be compiled using the
following gcc command

```
gcc keez.c -o keez
```

### Research
The main thing I want to research is how effective
different strategies are in terms of
- Choosing what card to play
- Choosing what pawns to swap
- Choosing what pawns to run

I then use monte carlo simulations to see the 
effectiveness of one strategy against another.

### Strategies
The main bunch of strategies that I want to test
are notated with 3 letters denoting each individual
part of the strategies:
1) what card to play
2) what pawn to run with
3) what pawns to swap with

**What card to play**
There are a bunch of ways to choose what card to play
the following table includes the tactics i will research:
| name | explanation                                                   |
|------|---------------------------------------------------------------|
| A    | Choose first playable card                                    |
| B    | Choose last playable card                                     |
| C    | Choose card with highest value (A 1 2 3 4 5 6 7 8 9 10 J Q K) |
| D    | Choose card with lowest value (A 1 2 3 4 5 6 7 8 9 10 J Q K)  |
| E    | Choose card with highest value (4 J K Q 10 9 8 6 5 3 2 1 A 7) |
| F    | Choose card with lowest value (4 J K Q 10 9 8 6 5 3 2 1 A 7)  |

**What pawn to run with**
There are a bunch of ways to choose what pawn to run with
the following table includes the tactics i will research:
| name | explanation                                                   |
|------|---------------------------------------------------------------|
| A    | Choose pawn closest to home                                   |
| B    | Choose pawn closest to end                                    |
| C    | Choose pawn closest to oponent                                |
| D    | Choose pawn closest to an oponent in front                    |
| E    | Choose pawn closest to an oponont in back                     |
| F    | Choose pawn with closest distance to teammate in front        |
| G    | Choose pawn with closest distance to teammate in back         |
| H    | Choose random pawn                                            |

**What pawn to swap with**
There are a bunch of ways to choose what pawn to swap with
the following table includes the tactics i will research:
| name | explanation                                                     |
|------|-----------------------------------------------------------------|
| A    | Swap with random opponent and closest teammate to home          |
| B    | Swap with random opponent and closest teammate to end           |
| C    | Swap with random opponent and random teammate                   |
| D    | Swap with opponent closest to home and closest teammate to home |
| E    | Swap with opponent closest to home and closest teammate to end  |
| F    | Swap with opponent closest to home and random teammate          |
| G    | Swap with opponent closest to end and closest teammate to home  |
| H    | Swap with opponent closest to end and closest teammate to end   |
| I    | Swap with opponent closest to end and random teammate           |

Currently there are 6 card tactics, 8 running tactics, and 9 swapping tactics, 
meaning there are in total 6 * 8 * 9 = 432 different strategies.

A Strategy with the name DEA will have the properties:
- D = Choose card with lowest value (A 1 2 3 4 5 6 7 8 9 10 J Q K)
- E = Choose pawn closest to an oponont in back
- A = Swap with random opponent and closest teammate to home 