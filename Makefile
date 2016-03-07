
CPPFLAGS += -I inc/argconfig
CFLAGS += -g -std=gnu99

libargconfig.a: $(patsubst %.c, %.o, $(wildcard src/*.c))
	ar ru $@ $^
	ranlib $@

clean:
	rm -rf src/*.o *.a
