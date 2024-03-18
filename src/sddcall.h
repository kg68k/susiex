/*
 *	SUSIE CALL Macro
 *	Copyright (C)1994 GORRY.
 *	$Id: sddcall.h,v 1.5 1997/09/10 01:48:15 GORRY Exp GORRY $
 */


#ifndef	__SDDCALL_H__
#define	__SDDCALL_H__


/************************************************************************/


#include	<iocslib.h>


/************************************************************************/


#define	SDDCALL( callno, drv, prbuf )	IOCTRLFDCTL( (drv), 'SU', ((prbuf)->pr0=callno, (void *)(prbuf)) )


/************************************************************************/


struct prbuf	{
	unsigned int	pr0;
	unsigned int	pr1;
	unsigned int	pr2;
	unsigned int	pr3;
	unsigned int	pr4;
	unsigned int	pr5;
	unsigned int	pr6;
	unsigned int	pr7;
};

struct prtag	{
	unsigned int	tag;
	unsigned int	param;
};


/************************************************************************/


#define	AskReleaseSDD		(-2)
#define	ReleaseSDD		(-1)
#define	AskSDD			(0)
#define	CalibrateSDD		(1)
#define	AskSDDVersion		(2)
#define	SetForceEjectSDD	(3)
#define	SetForceProtectSDD	(4)
#define	SetSpecialOptionSDD	(5)
#define	GetSpecialOptionSDD	(6)


/************************************************************************/


#define	SDD_FormatType_X68000	0
#define	SDD_FormatType_PC9801	1
#define	SDD_FormatType_FMTOWNS	2
#define	SDD_FormatType_IBMMO	3
#define	SDD_FormatType_IBMFDISK	4
#define	SDD_FormatType_ZIP	5
#define	SDD_FormatType_2HD	6
#define	SDD_FormatType_End1	6
#define	SDD_FormatType_ISO9660	16
#define	SDD_FormatType_End2	16
#define	SDD_FormatType_ERROR3	(-4)
#define	SDD_FormatType_Audio	(-3)
#define	SDD_FormatType_ERROR2	(-2)
#define	SDD_FormatType_ERROR	(-1)


/************************************************************************/


#endif	/* __SDDCALL_H__ */


