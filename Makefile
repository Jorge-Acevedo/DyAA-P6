CC=gcc
CXX=g++
RM=rm -f
CFLAGS=-g -O2
LDFLAGS=-g -O2

COMPETICION_SRS= src/competicion.cpp

SRCS=main.cpp $(COMPETICION_SRS) 
OBJS=$(subst .cpp,.o,$(SRCS))

all: main

main: $(OBJS) 
	$(CXX) $(LDFLAGS) -o calendario $(OBJS)

depend: .depend

.depend: $(SRCS)
	rm -f ./.depend
	$(CXX) $(CPPFLAGS) -MM $^ >>./.depend;

clean:
	$(RM) $(OBJS)

dist-clean: clean
	$(RM) *~ .dependtool

include .depend