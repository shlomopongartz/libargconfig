
CPPFLAGS += -I inc/argconfig
CFLAGS += -g -std=gnu99

ifneq ($(V), 1)
Q=@
else
NQ=:
endif

%.o: %.c
	@$(NQ) echo "  CC     $<"
	$(Q)$(COMPILE.c) $< -o $@

libargconfig.a: $(patsubst %.c, %.o, $(wildcard src/*.c))
	@$(NQ) echo "  AR     $<"
	$(Q)ar ru $@ $^
	@$(NQ) echo "  RANLIB $<"
	$(Q)ranlib $@

clean:
	@$(NQ) echo "  CLEAN"
	$(Q)rm -rf src/*.o *.a
