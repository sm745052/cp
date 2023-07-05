# using dp to solve gametheory type questions where each player plays optimally

Best way is to make cases what A will take. The for each case check what all cases B can take. and count no of draws, wins and loss.. if there is a move for A where B looses, take that move.
else if there is a move for A where there is a draw then take that. else regardless of move, A will lose.
