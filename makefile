FLAGS ?= -O2 -DOPTIMIZE --std=c++20
CXX ?= g++
INCLUDEDIR=-I./include

FLAGS += $(INCLUDEDIR)

CXXSRC=src/person.cpp src/main_share.cpp src/paper.cpp src/main_array.cpp src/research_tean.cpp src/main_var3.cpp
SOBJ=person.o main_share.o
AOBJ=person.o main_array.o
VOBJ=person.o research_team.o paper.o main_var3.o

CXXOBJ = person.o research_team.o paper.o main_var3.o main_array.o main_share.o

DEPS=$(CXXOBJ:.o=.d)

NODEPS=clean

all: variant3.bin array.bin share.bin

variant3.bin : $(VOBJ) 
	$(CXX) $(FLAGS) $^ -o $@

array.bin : $(AOBJ) 
	$(CXX) $(FLAGS) $^ -o $@

share.bin : $(SOBJ) 
	$(CXX) $(FLAGS) $^ -o $@

%.o : src/%.cpp
	$(CXX) $(FLAGS) -c $< -o $@ 

%.d : src/%.cpp
	$(CXX) -E $(FLAGS) -c $< -MM -MT $(@:.d=.o) > $@


ifeq (0,$(words $(findstring $(MAKECMDGOALS),$(NODEPS))))
include	$(DEPS)
endif

.PHONY : clean
clean: 
	@rm -rf *.o *.bin *.d

