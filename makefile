CXX := g++
CXXFLAGS := -std=c++11 -Wall -Wextra

TARGETNAME := wieselcat

BINPATH := bin
BUILDPATH := build
SRCPATH := . ./noise

TARGET := $(BINPATH)/$(TARGETNAME)

SRC := $(foreach x, $(SRCPATH), $(wildcard $(addprefix $(x)/*,.cpp)))
OBJ := $(subst ./,,$(addprefix $(BUILDPATH)/, $(addsuffix .o, $(basename $(SRC)))))
OBJPATHS := $(sort $(dir $(OBJ)))


default: makedirs $(TARGET)

#$(info $(sort $(dir $(OBJ))))
#$(info SRC is $(SRC))
#$(info OBJ is $(OBJ))

$(TARGET): $(OBJ)
	@echo "building $(notdir $@)"; $(CXX) $(CXXFLAGS) $^ -o $@

$(BUILDPATH)/%.o: ./%.cpp
	@echo "compiling $@"; $(CXX) -c $(CXXFLAGS) $^ -o $@

.PHONY: makedirs
makedirs:
	@mkdir -p $(OBJPATHS) $(BINPATH)

.PHONY: clean
clean:
	@rm -r -f $(BINPATH)/* $(BUILDPATH)/*
