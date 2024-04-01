CXX := ccache g++
CXXFLAGS := -Wall -Wextra -O3 -march=native -std=c++23 -flto
LDFLAGS := -flto=auto -fuse-ld=mold
LIBS := -lboost_program_options
SRC := src/timers.cpp src/cdwn.cpp src/convert.cpp
OBJ := $(SRC:src/%.cpp=obj/%.o)
EXE := cdwn
PREFIX := /usr/local/bin

.PHONY: clean install compdb

build: $(EXE)

$(EXE): $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $^ $(LIBS)

obj/%.o: src/%.cpp
	@mkdir -p obj
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf obj $(EXE)

install: $(EXE)
	install -D $(EXE) $(PREFIX)/$(EXE)

compdb:
	bear -- $(MAKE) clean all
