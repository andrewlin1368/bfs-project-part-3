# Programming Exercise, Part 3: Querying movies and their performers
Download the input files movies_short.txt and movies.txt, which contain information from
the Internet Movie Database (IMDB: www.imdb.com) and consist of lines containing a
movie title followed by a list of the performers in the movie. The file movies_short.txt has a
snapshot of movies.txt so that you can work with a small file while developing and testing.
The file movies.txt has the complete list of movies and performers.

## TASK 1. 
Add a constructor to LabeledGraph so that client programs can build a graph
from an input file (with the format of the input file provided). You will need to modify both,
the header and the implementation files (LabeledGraph.h and LabeledGraph.cxx). The
name of the input file should be passed as an argument to the constructor so that a
LabeledGraph object can be created using:

LabeledGraph g(“movies_short.txt”);

## TASK 2. 
Write a client program, LabeledGraphQueryClient.cpp, to take queries from
standard input. The user enters a vertex label and gets the list of vertices adjacent to that
vertex (the neighbors). When you run the program, if you type the name of an actor, you
should see the list of the movies in the database in which that actor appeared, or if you
type the name of a movie, you should see the list of actors that appear in that movie.
Notice that you can make use of the index() function to convert a vertex label to an index
for use in graph processing and the label() function to convert an index into a label for use
in the context of the application (such as displaying).