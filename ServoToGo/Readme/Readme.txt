ServoToGo xPC Target Driver Files

Created and tested in MATLAB R13 (6.5.0)

These files must reside inside "C:\ServoToGo\" for the driver to work (because of how I defined the #include files in the TLC files).  In MATLAB, add "C:\ServoToGo\" to the path.  Also, *copy* GLOBAL_VARS.C and STGMEMBS.C to your working directory.  These 2 files must be present in your current working directory for this to work. I hope to fix this minor flaw in the future.

These are S-Functions defining the Simulink blocks (generated from C codes below):
	adstgmodel2.dll - A/D
	dastgmodel2.dll - D/A
	distgmodel2.dll - Digital Input
	dostgmodel2.dll - Digital Output
	encstgmodel2.dll - Encoder
	initstgmodel2.dll - Initialization

These are C files uses to compile the S-Functions:
	IRQ_DEFS.H
	LOCDEFS.H
	MS-OR-BC.H
	OFFSETS.H
	OMNISEM.H
	PORTIO.H
	STG_COMN.H
	STGDEFS.H
	STGMEMBS.H
	adstgmodel2.c - if modified, run "mex adstgmodel2.c" to compile
	dastgmodel2.c - if modified, run "mex dastgmodel2.c" to compile
	distgmodel2.c - if modified, run "mex distgmodel2.c" to compile
	dostgmodel2.c - if modified, run "mex dostgmodel2.c" to compile
	encstgmodel2.c - if modified, run "mex encstgmodel2.c" to compile
	initstgmodel2.c - if modified, run "mex initstgmodel2.c" to compile
	GLOBAL_VARS.C   - **copy this to your working directory**
	STGMEMBS.C      - **copy this to your working directory**

These are m-files linked to the behaviors of the Simulink blocks:
	maddastgmodel2.m
	mdiostgmodel2.m
	mencstgmodel2.m
	minitstgmodel2.m
	slblocks.m       - this enables ServoToGo blocks to show up in the
	                   Simulink library.

These are TLC files used when compiling a target model.  These files are the core part of the driver:
	adstgmodel2.tlc
	dastgmodel2.tlc
	distgmodel2.tlc
	dostgmodel2.tlc
	encstgmodel2.tlc
	initstgmodel2.tlc

This is the ServoToGo Simulink libraries:
	ServoToGo.mdl