EXENAME = testscene

OBJS = testscene.o rgbapixel.o png.o image.o scene.o

CXX = clang++
CXXFLAGS = -std=c++1y -stdlib=libc++ -c -g -O0 -w
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lpng -lc++abi -lpthread

all : $(EXENAME)

$(EXENAME) : $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

testscene.o : testscene.cpp scene.h
	$(CXX) $(CXXFLAGS) testscene.cpp

png.o : png.cpp png.h
	$(CXX) $(CXXFLAGS) png.cpp

rgbapixel.o : rgbapixel.cpp rgbapixel.h
	$(CXX) $(CXXFLAGS) rgbapixel.cpp

image.o : image.cpp png.h
	$(CXX) $(CXXFLAGS) image.cpp

scene.o: scene.cpp image.h
	$(CXX) $(CXXFLAGS) scene.cpp


clean :
	-rm -f *.o $(EXENAME) out.png
