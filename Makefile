EE_OBJS	= vuESIN.o vuESINMicro.o
EE_BIN = vuESIN.elf
EE_LIBS = -lkernel
EE_DVP = dvp-as

all: $(EE_BIN)

%.o: %.vsm
	$(EE_DVP) $< -o $@

clean:
	rm -f $(EE_BIN) $(EE_OBJS) 

run: $(EE_BIN)
	ps2client execee host:$(EE_BIN)

reset:
	ps2client reset
	ps2client netdump

include $(PS2SDK)/samples/Makefile.pref
include $(PS2SDK)/samples/Makefile.eeglobal
