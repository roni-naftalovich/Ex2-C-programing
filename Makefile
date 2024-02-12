CC = gcc
AR = ar
OBJECTS_MAIN = my_graph.o
OBJECTS_MAIN_KN = my_Knapsack.o
OBJECTS_LIB_MY_MAT = my_mat.o
FLAGS = -Wall -g

all: mymat.a my_graph my_Knapsack
mymat.a:$(OBJECTS_LIB_MY_MAT)
	$(AR) -rcs mymat.a $(OBJECTS_LIB_MY_MAT)
my_graph: $(OBJECTS_MAIN) mymat.a
	$(CC) $(FLAGS) -o my_graph $(OBJECTS_MAIN) mymat.a
my_Knapsack: $(OBJECTS_MAIN_KN) mymat.a
	$(CC) $(FLAGS) -o my_Knapsack $(OBJECTS_MAIN_KN) mymat.a
my_mat.o: my_mat.c my_mat.h
	$(CC) $(FLAGS) -c my_mat.c
my_graph.o: my_graph.c my_mat.h
	$(CC) $(FLAGS) -c my_graph.c
my_Knapsack.o: my_Knapsack.c my_mat.h
	$(CC) $(FLAGS) -c my_Knapsack.c
clean:
	rm -f *.o *.a my_graph my_Knapsack