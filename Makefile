CC=gcc
AR=ar
OBJECTS_MAIN1=my_graph.o 
OBJECTS_MAIN2=my_knapsack.o
OBJECTS_LIB=my_math.o
FLAGS= -Wall -g

all: my_graph my_knapsack

my_math.a: $(OBJECTS_LIB) 
	$(AR) rcs my_math.a $(OBJECTS_LIB)
	ranlib my_math.a

my_graph: $(OBJECTS_MAIN1) my_math.a
	$(CC) $(FLAGS) -o my_graph $(OBJECTS_MAIN1) my_math.a

my_math.o: $(OBJECTS_LIB)
	$(CC) $(FLAGS) -fPIC -c my_math.c 

my_graph.o: my_graph.c 
	$(CC) $(FLAGS) -c my_graph.c

my_knapsack: $(OBJECTS_MAIN2) 
	$(CC) $(FLAGS) -o my_knapsack $(OBJECTS_MAIN2)

my_knapsack.o: my_knapsack.c 
	$(CC) $(FLAGS) -c my_knapsack.c

clean:
	rm -f *.o *.a my_graph my_knapsack
