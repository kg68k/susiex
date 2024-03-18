
include	SUSIEVER.MAK
include	DEEJVER.MAK
include	SSLUNVER.MAK

CC	=	GCC
LD	=	GCC
AS	=	HAS
AP	=	AP

CFLAGS	=	-c -O -g -funsigned-char -fno-inline-functions -fcombine-regs
LDFLAGS	=	
ASFLAGS	=	-w -m68000
APFLAGS	=	-H

LIBS	=	-ldos -lfloat

x		:	test2.x susie.x Calibrate.x deej.x SSLUN.x

%.o	:	%.c
	$(CC) $(CFLAGS) $<

%.o	:	%.ap
	$(AP) $(APFLAGS) $< $(basename $<).has
	$(AS) $(ASFLAGS) $(basename $<).has -s SUSIEVERH=$(SUSIEVERH) -s SUSIEVERM=$(SUSIEVERM) -s SUSIEVERL=$(SUSIEVERL) -s SUSIEVERR=$(SUSIEVERr) > err.err
	rm $(basename $<).has err.err %AP*.*

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


rcs		:	UPDATE.LOG
		ci -l -tnul Makefile *.MAK *.ap *.c *.def *.h *.mac *.ntf TECH.DOC verup.doc< UPDATE.LOG

arc		:	SSE_$(SUSIEVERN).LZH

SSE_$(SUSIEVERN).LZH	:	susie.x deej.x SSLUN.x susie.doc verup.doc 使用規定.DOC SOURCE.LZH
	lha u $@ $^

SOURCE.LZH	:	Makefile SUSIEVER.MAK DEEJVER.MAK SSLUNVER.MAK \
			devdrv.ap keep.ap pstart.ap sdd.ap sddhed.ap susie.ap \
			deej.ap \
			SSLUN.c \
			test2.c \
			keep.def pstart.def sdd.def sddhed.def devdrv.def susie.def \
			devdrv.h \
			devdrv.mac sdd.mac sddcall.mac susie.mac sddcall.h \
			deej.mac \
			susie.ntf \
			TECH.DOC \
			Calibrate.has \
			Calibrate.x
	lha u $@ $^


