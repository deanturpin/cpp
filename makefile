objects = $(patsubst %.cpp, tmp/%.o, $(wildcard *.cpp))

all: tmp
	@echo > output.md
	$(MAKE) --silent -j $(shell nproc) $(objects)

CXX ?= g++-9

CXXFLAGS ?= --std=c++2a --all-warnings --extra-warnings -Wno-address \
	-Werror -Wshadow -Wfloat-equal -Weffc++ -Wdelete-non-virtual-dtor \
	-Warray-bounds -Wattribute-alias -Wformat-overflow -Wformat-truncation \
	-Wmissing-attributes -Wstringop-truncation \
	-Wdeprecated-copy -Wclass-conversion \
	-O1

tmp/%.o: %.cpp
	$(CXX) $(FLAGS) -o $@ $< -lstdc++fs -lpthread
	@echo '```' >> output.md
	./$@ >> output.md
	@echo '```' >> output.md

tmp:
	mkdir -p $@

clean:
	rm -rf tmp *.bin *.out
