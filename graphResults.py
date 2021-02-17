import matplotlib.pyplot as plt
import sys

movieNames = []
playerScores=[]
numMovies = int(sys.argv[1])
numPlayers = int(sys.argv[2])
for i in range(numMovies):
    movieNames.append(sys.argv[i+3])

for i in range(numPlayers):
    temp = []
    for j in range(numMovies):
        index = i+1
        index = index * numMovies
        index += j + 3
        temp.append(int(sys.argv[index]))
        index = 0
    playerScores.append(temp)

ax=plt.subplot(111)
ticks = range(0,numMovies, 1)
for j in range(len(playerScores)):
    plt.scatter(movieNames,playerScores[j])
plt.xticks(rotation=90)
plt.yticks(range(0,10,1))
plt.gcf().canvas.set_window_title('Pixar Character Quiz Scores')
plt.title('Player Scores By Movie')
plt.xlabel('Movie')
plt.ylabel('Score')
plt.show()