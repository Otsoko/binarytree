CXX=gcc
#CXXFLAGS=-Isrc -Wall -O3 -c
CXXFLAGS=-Isrc -Wall -g -c
OBJDIR=lib
OBJ=$(OBJDIR)/binarytree.o $(OBJDIR)/main.o
EXE=binarytree

.PHONY: all clean

all: $(EXE)

binarytree: $(OBJ)
	$(CXX) -o $@ $^

$(OBJDIR)/%.o: src/%.c | $(OBJDIR)
	$(CXX) $(CXXFLAGS) $< -o $@

$(OBJDIR):
	mkdir -p $@

clean:
	rm -rf $(OBJDIR) $(EXE)
