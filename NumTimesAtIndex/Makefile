MPI_HOME=/directory/mpich
MPI_INCL=$(MPI_HOME)/include
MPI_LIB=$(MPI_HOME)/lib
CC = gcc
CXX = g++
#CC=$(MPI_HOME)/bin/mpicc
#DEBUG=
DEBUG = -DDEBUG -g
PROG=main
OBJS=

# Define C compiler options
#CFLAGS        = -Wall -c -g

# Define C++ compiler options
#CCCFLAGS      = -Wall -ansi -c -g

INCLUDE = -I./ -I$(GLUIDIR)/include -I$(GLDIR)/include -I$(XLIBDIR)
#-I/usr/X11R6/include \
#        -I./include \
#        -I$(MPI_INCL)

# Define C/C++ pre-processor options
CPPFLAGS=-std=c++11 $(INCLUDE) -Os $(DEBUG) 

# Define location of GLUT directory (/usr/local for UTSC)
GLUTDIR       = /usr

# Define location of OpenGL directory (/usr/local for UTSC)
GLDIR         = /usr

# Note the GLUI directory is in the same as the GL and GLUT directories,
# not in the X11R6 directory anymore
# Define location of GLUI directory
GLUIDIR       = /usr

# And also note the different library names for the glu, gl, and glut libraries
# Define location of OpenGL and GLU libraries along with their lib names
GL_LIBS       = -L/lib -lglu32 -lopengl32 

# Define location of Glut libraries along with glut lib name
#GLUT_LIBS     = -L/lib -lglut32 -lglut
GLUT_LIBS     = -L/lib 

# Define location of GLUI libraries along with glui lib name
#GLUI_LIBS     = -L/lib -lglui
GLUI_LIBS     = -L/lib

# Define location of the X11 Windows directory (for X11 Windows header files)
XLIBDIR       = /usr/include

# Define location of X Windows libraries,  and the X11 library names
#XLIBS         = -L/usr/X11R6/lib -lX11 -lXi -lXmu
XLIBS         = -L/usr/X11R6/lib -lX11 -lXi

# Define the location of the destination directory for the executable file
DEST	      = .

# Define flags that should be passed to the linker
LDFLAGS	      =

# Define libraries to be linked with
LIBS          = $(GLUI_LIBS) $(GL_LIBS) $(GLUT_LIBS) -lm $(XLIBS) -ldl

#LIBS_AFTER = -lm -lGL -lGLU -lglut
LIBS_AFTER = -lm -lGL 

# Define linker
LINKER	      = g++

# Define all object files to be the same as CPPSRCS but with all the .cpp and .c suffixes replaced with .o
#OBJ           = $(CPPSRCS:.cpp=.o) $(CSRCS:.c=.o)
# Define all C source files here
#CSRCS         =
# Define all C++ source files here
#CPPSRCS       = a2.cpp textures.cpp ui.cpp

# Define name of target executable
PROGRAM	          = main

.cpp.o:
	@echo "******************************************************"
	@echo "* Compiling $@"
	$(CXX) $(CPPFLAGS) -c $< -o $@

default: all

all: depend $(OBJS)
	@echo "******************************************************"
	@echo "* Main Compilation"
	$(CXX) $(CPPFLAGS) $(LIBS) $(OBJS) $(PROG).cpp -o $(PROGRAM) $(LIBS_AFTER)


clean:
	@echo "******************************************************"
	@echo "* Cleaning"
	rm -Rf $(PROG) $(OBJS) core .depend
	touch .depend

depend:
	@rm .depend
	@touch .depend
	@echo "******************************************************"
	@echo "* Making Dependencies"
	makedepend $(CFLAGS) $(OBJS:.o=.cpp)

test: depend $(OBJS)
	@echo "******************************************************"
	@echo "* Regression Test Compilation"
	$(CXX) $(CFLAGS) $(LIBS) $(OBJS) Test.cpp -o Test

include .depend
# DO NOT DELETE THIS LINE -- mkdep uses it.
