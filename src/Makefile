# Makefile for SUSIEX

include	SUSIEVER.MAK
#include	DEEJVER.MAK
#include	SSLUNVER.MAK

SRCDIR_MK = ../srcdir.mk
SRC_DIR = ../src
-include $(SRCDIR_MK)

CC	=	GCC
AS	=	has060
AP	=	ap

ifndef LD
LD	=	hlk
endif

CFLAGS	=	-c -O -g -funsigned-char -fno-inline-functions -fcombine-regs
LDFLAGS	=	
ASFLAGS	=	-w -m68000
APFLAGS	=	-H

LIBS	=	-ldos -lfloat

U8TOSJ	=	u8tosj
CP_P	=	cp -p
STRIP	=	strip -p
ZIP	=	zip -9

SSE_121A_LZH	= SSE_121A.LZH
SRC_ZIP		= src.zip
SUSIEX_ZIP	= susiex.zip

#x		:	test2.x susie.x Calibrate.x deej.x SSLUN.x
all: susie.x

%.o	:	%.c
	$(CC) $(CFLAGS) $<

%.o	:	%.ap
	$(AP) $(APFLAGS) $< $(basename $<).has
	$(AS) $(ASFLAGS) $(basename $<).has -s SUSIEVERH=$(SUSIEVERH) -s SUSIEVERM=$(SUSIEVERM) -s SUSIEVERL=$(SUSIEVERL) -s SUSIEVERR=$(SUSIEVERr)
	rm -f $(basename $<).has %AP*.*

test2.x		:	test2.o	devdrv.o
	$(LD) $(LDFLAGS) $(LIBS) $^ -o $@
susie.x		:	pstart.o sddhed.o sdd.o devdrv.o keep.o susie.o
	$(LD) $(LDFLAGS) $^ -o $@
Calibrate.x	:	Calibrate.o
	$(LD) $(LDFLAGS) $^ -o $@
deej.x		:	pstart.o deej.o
	$(LD) $(LDFLAGS) $^ -o $@
SSLUN.x		:	SSLUN.o
	$(LD) $(LDFLAGS) $(LIBS) $^ -o $@


test2.o		:	test2.c		devdrv.h
devdrv.o	:	devdrv.ap	devdrv.mac
sddhed.o	:	sddhed.ap	devdrv.mac sdd.mac sddcall.mac
sdd.o		:	sdd.ap		devdrv.mac sdd.mac sddcall.mac           SUSIEVER.MAK
keep.o		:	keep.ap		devdrv.mac sdd.mac sddcall.mac
susie.o		:	susie.ap	devdrv.mac sdd.mac sddcall.mac susie.mac SUSIEVER.MAK
pstart.o	:	pstart.ap

Calibrate.o	:	Calibrate.has	sddcall.mac
	$(AS) $(ASFLAGS) $< > err.err

deej.o		:	deej.ap	devdrv.mac deej.mac DEEJVER.MAK
	$(AP) $(APFLAGS) $< $(basename $<).has
	$(AS) $(ASFLAGS) $(basename $<).has -s DEEJVERH=$(DEEJVERH) -s DEEJVERM=$(DEEJVERM) -s DEEJVERL=$(DEEJVERL) -s DEEJVERR=$(DEEJVERr) > err.err
	rm $(basename $<).has err.err %AP*.*

SSLUN.o		:	SSLUN.c		sddcall.mac SSLUNVER.MAK
	$(CC) $(CFLAGS) $< -DSSLUNVERH=$(SSLUNVERH) -DSSLUNVERM=$(SSLUNVERM) -DSSLUNVERL=$(SSLUNVERL) -DSSLUNVERR=$(SSLUNVERr) > err.err

doc		:	susie.doc

susie.doc	:	susie.ntf
	ntf -t -kl 2 $^ > $@


archive: $(SUSIEX_ZIP)

$(SUSIEX_ZIP): $(SSE_121A_LZH) $(SRC_ZIP) susie.x CHANGELOG.txt README.txt
	$(STRIP) susie.x
	rm -f $@
	$(ZIP) $@ $^

$(SSE_121A_LZH):
	$(CP_P) $(SRC_DIR)/../archives/$@ $@

$(SRC_ZIP): devdrv.ap DevDrv.def devdrv.mac gorry.mac keep.ap keep.def \
            Makefile pstart.ap pstart.def sdd.ap sdd.def sdd.mac sddcall.mac \
            sddhed.ap sddhed.def susie.ap susie.def susie.mac SUSIEVER.MAK
	rm -f $@
	$(ZIP) $@ $^

CHANGELOG.txt: $(SRC_DIR)/../CHANGELOG.md
	$(U8TOSJ) < $^ >! $@

README.txt: $(SRC_DIR)/../README.md
	$(U8TOSJ) < $^ >! $@

