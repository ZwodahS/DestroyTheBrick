vpath %.cpp z_framework/zf_common/
vpath %.cpp z_framework/zf_sfml/
vpath %.cpp game/
vpath %.cpp game/screens/
vpath %.cpp game/boards/
vpath %.o obj/

BIN=destroy
CXX=g++
SFML=-framework sfml-graphics -framework sfml-window -framework sfml-system
OBJDIR=obj

# search framework for .cpp
zf_framework = $(shell cd z_framework ; for F in `ls -d */` ;  do cd $$F ; ls *.cpp ; cd .. ; done)
zf_frameworkobjs = $(patsubst %, $(OBJDIR)/%,$(zf_framework:.cpp=.o))

# game code
game = $(shell cd game; ls *.cpp ; for F in `ls -d */` ; do cd $$F; ls *.cpp ;cd ..; done)
gameobjs = $(patsubst %,$(OBJDIR)/%,$(game:.cpp=.o))


main=obj/main.o

all: $(BIN)

$(BIN) : $(main) $(zf_frameworkobjs) $(gameobjs)
	$(CXX) -o $(BIN) $(OBJDIR)/* $(SFML)

$(OBJDIR)/%.o : %.cpp
	$(CXX) -c -o $@ $^

obj/main.o : main.cpp 
	$(CXX) -c -o $@ $^

clean:
	rm obj/*.o
	rm $(BIN)

remake:
	make clean
	make all

debug:
	@echo $(zf_sfml)

.PHONY: clean remake debug
