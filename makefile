CXX       := g++
CXX_FLAGS := -ggdb

BUILD     := build
SRC     := src
INCLUDE := include

LIBRARIES   :=
EXECUTABLE  := main


all: $(BUILD)/$(EXECUTABLE)

run: clean all
	clear
	./$(BUILD)/$(EXECUTABLE)

$(BUILD)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) $^ -o $@ $(LIBRARIES)

clean:
	-rm $(BUILD)/*