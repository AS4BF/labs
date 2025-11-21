FLAGS ?= -O2 --std=c++20
CXX ?= g++

INCLUDEDIR=-I./include -I../Interface/include/
FLAGS += $(INCLUDEDIR)

SRCDIR=src
OBJDIR=build
CXXSRC=$(SRCDIR)/person.cpp

CXXOBJ:=$(addprefix $(OBJDIR)/,$(CXXSRC:.cpp=.o))
DEPS=$(CXXOBJ:.o=.d)


$(CXXOBJ):$(OBJDIR)/%.o : %.cpp
	@mkdir -p $(@D)
	$(CXX) $(FLAGS) -c $< -o $@

$(DEPS):$(OBJDIR)/%.d : %.cpp
	@mkdir -p $(@D)
	$(CXX) -E $(FLAGS) $< -MM -MT $(@:.d=.o)> $@

ifeq (0,$(words $(findstring $(MAKECMDGOALS),$(NODEPS))))
include $(DEPS)
endif

.PHONY : clean
clean:
	@rm -rf $(OBJDIR)/$(SRCDIR)/*.o $(OBJDIR)/$(SRCDIR)/*.d
