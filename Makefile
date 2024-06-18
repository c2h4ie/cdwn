CXX := g++
CXXFLAGS += -march=native -std=c++2c
SRC_DIR := src
BUILD_DIR := build
OUT := cdwn
PREFIX := /usr/local/bin

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

$(OUT): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

.PHONY: clean install
clean:
	rm -rf $(BUILD_DIR) $(OUT)

install: $(EXE)
	install -D $(EXE) $(PREFIX)/$(EXE)

