CC = g++
CFLAGS = -W -Wall -g
SRCS = ./*.cpp
OBJS = $(SRCS:.cpp=.o)

All: MazeSolver
	@echo "Finished!"

MazeSolver: $(OBJS)	
	$(CC) -o MazeSolver $(OBJS) $(CFLAGS)

$(OBJS): $(SRCS)
	$(CC) -c $(SRCS) $(CFLAGS)

clean:
	rm $(OBJS) MazeSolver


