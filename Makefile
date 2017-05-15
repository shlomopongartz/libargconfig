
CPPFLAGS += -I inc/argconfig
CFLAGS += -g -std=gnu99
ARFLAGS = r

ifneq ($(V), 1)
Q=@
MAKEFLAGS += --no-print-directory
ARFLAGS += -c
else
NQ=:
endif

%.o: %.c
	@$(NQ) echo "  CC     $<"
	$(Q)$(COMPILE.c) $< -o $@

libargconfig.a: $(patsubst %.c, %.o, $(wildcard src/*.c))
	@$(NQ) echo "  AR     $<"
	$(Q)ar $(ARFLAGS) $@ $^
	@$(NQ) echo "  RANLIB $<"
	$(Q)ranlib $@

clean:
	@$(NQ) echo "  CLEAN  libargconfig"
	$(Q)rm -rf src/*.o *.a
