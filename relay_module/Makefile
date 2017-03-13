CXX      = g++
CXXFLAGS = -Wall -ansi -g
CC       = gcc
CCFLAGS  = -g
OBJS     = example.o relaymodule.o gpio.o common.o
EXECUTABLE = test
$(EXECUTABLE) : $(OBJS)
	$(CXX) -o $@ $(OBJS)

%.o : %.cpp
	$(CXX) -c $(CXXFLAGS) $<

%.o : %.c
	$(CC) -c $(CCFLAGS) $<
clean:
	rm $(OBJS) $(EXECUTABLE) 
