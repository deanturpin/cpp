# Build objects for each cpp
all:
	make $(patsubst %.cpp, %.o, $(wildcard *.cpp))

%.o: %.cpp
	clang++ -g -Wall -Wextra -pedantic -pedantic-errors -std=gnu++14 -lpthread -o $@ $<

wait:
	while :; do inotifywait -qe modify *.cpp; make; done

clean:
	rm -f *.o

tidy:
	$(foreach file, $(wildcard *.cpp), clang-format -i $(file) || true;)

# coverage:
#	for file in *.o; do kcov /tmp/results ./$file; done
