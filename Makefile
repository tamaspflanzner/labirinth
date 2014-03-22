APPS = main
OBJ = Point.o Rectangle.o Wall.o WallFactory.o $(APPS).o
SRC = Point.cpp Rectangle.cpp Wall.cpp WallFactory.cpp $(APPS).cpp

CFLAGS = $(C_OPTS) -I/usr/include
LIBS = -L/usr/X11R6/lib -lX11 -lglut -lGL -lGLU -lm -lpthread
  
application:$(APPS)

clean:
	rm -f $(APPS) *.raw *.o core a.out

realclean:	clean
	rm -f *~ *.bak *.BAK

.SUFFIXES: cpp o
.cpp.o:
	$(CXX) -c $(CFLAGS) $<

$(APPS): $(OBJ) 
	$(CXX) -o $(APPS) $(CFLAGS) $(OBJ) $(LIBS)

depend:
	makedepend -- $(CFLAGS) $(SRC)

