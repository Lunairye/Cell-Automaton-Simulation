# Cell Automaton Simulator

This project is a simple Cellular automaton simulator, 
it follows the rules of Conway's Game of Life by default:

- Any live cell with fewer than 2 neighbours will die next turn
- Any live cell with 2 or 3 neighbours will live
- Any live cell with more than 3 neighbours will die next turn
- Any dead cell with exactly 3 neighbours will become alive next turn


Currently there is no implemented way of changing this behaviour
however in src/automaton.cpp the logic for Conway's Game of Life can be found in the function named Default and so if desired the logic can be changed.
A slight quirk with this is that getNeighbours only returns all neighbours on the grid
For example a corner only has 3 adjacent cells and so getNeighbours only returns a vector of size 3.
