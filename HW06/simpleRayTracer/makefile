# define variables
HDRDIR  = ./

# set options for this machine
# specify which compilers to use for c and linking
CC	= nvcc
LD	= nvcc

# compiler flags to be used (set to compile with debugging on)
CFLAGS = -I$(HDRDIR) -O3 --use_fast_math -arch=sm_60 -dc -Ddfloat=double -DdfloatString=’"%lg"’

# link flags to be used 
LDFLAGS	= -O3 -arch=sm_60

# libraries to be linked in
LIBS	=  -lm 

# types of files we are going to construct rules for
.SUFFIXES: .c .cu

# rule for .c files
HDR = simpleRayTracer.h

%.o:%.cu $(HDR)
	$(CC) $(CFLAGS) -o $*.o -c $*.cu

# list of objects to be compiled
SOBJS = src/sensor.o src/simpleRayTracer.o src/render.o src/utils.o src/grid.o src/saveppm.o src/sceneSetup.o src/readPlyModel.o src/intersectionTests.o src/shape.o src/projectionTests.o src/boundingBoxes.o src/sphereDynamics.o

all: simpleRayTracer

simpleRayTracer:$(SOBJS)
	$(LD) $(LDFLAGS) -o simpleRayTracer $(SOBJS) $(LIBS)

# what to do if user types "make clean"
clean :
	rm -r $(SOBJS) simpleRayTracer 

realclean :
	rm -r $(SOBJS) simpleRayTracer images/*.ppm images/*.png images/*.mp4 


