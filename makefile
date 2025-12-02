FLAGS ?= -O2 --std=c++20
CXX ?= g++

SRCDIR=src
OBJDIR=./build
CXXOBJ=$(OBJDIR)/main.o $(OBJDIR)/$(SRCDIR)/person.o $(OBJDIR)/$(SRCDIR)/research_team.o $(OBJDIR)/$(SRCDIR)/team.o $(OBJDIR)/$(SRCDIR)/paper.o 
MODULES:=Paper Person Team src


main.env : $(CXXOBJ)
	$(CXX) $(CXXOBJ) -o $@

$(CXXOBJ) : $(MODULES) 


.PHONY : $(MODULES) 
$(MODULES) :
	make -C $@


.PHONY : clean
clean:
	@rm -rf $(OBJDIR)/$(SRCDIR)/*.o $(OBJDIR)/$(SRCDIR)/*.d
