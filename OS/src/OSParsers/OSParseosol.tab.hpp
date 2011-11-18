
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ATTRIBUTETEXT = 258,
     ELEMENTTEXT = 259,
     ITEMTEXT = 260,
     INTEGER = 261,
     DOUBLE = 262,
     QUOTE = 263,
     TWOQUOTES = 264,
     GREATERTHAN = 265,
     ENDOFELEMENT = 266,
     OSOLSTART = 267,
     OSOLSTARTEMPTY = 268,
     OSOLATTRIBUTETEXT = 269,
     OSOLEND = 270,
     NUMBEROFOTHEROPTIONSATT = 271,
     NUMBEROFENUMERATIONSATT = 272,
     NUMBEROFJOBIDSATT = 273,
     NUMBEROFPATHSATT = 274,
     NUMBEROFPATHPAIRSATT = 275,
     FROMATT = 276,
     TOATT = 277,
     MAKECOPYATT = 278,
     CATEGORYATT = 279,
     TYPEATT = 280,
     GROUPWEIGHTATT = 281,
     NUMBEROFPROCESSESATT = 282,
     NUMBEROFSOLVEROPTIONSATT = 283,
     NUMBEROFSOSATT = 284,
     NUMBEROFVARIABLESATT = 285,
     NUMBEROFOBJECTIVESATT = 286,
     NUMBEROFCONSTRAINTSATT = 287,
     NUMBEROFOTHERVARIABLEOPTIONSATT = 288,
     NUMBEROFOTHEROBJECTIVEOPTIONSATT = 289,
     NUMBEROFOTHERCONSTRAINTOPTIONSATT = 290,
     NUMBEROFITEMSATT = 291,
     NUMBEROFVARATT = 292,
     NUMBEROFOBJATT = 293,
     NUMBEROFCONATT = 294,
     NUMBEROFELATT = 295,
     NAMEATT = 296,
     IDXATT = 297,
     SOSIDXATT = 298,
     VALUEATT = 299,
     UNITATT = 300,
     DESCRIPTIONATT = 301,
     EMPTYTYPEATT = 302,
     EMPTYNAMEATT = 303,
     EMPTYCATEGORYATT = 304,
     EMPTYDESCRIPTIONATT = 305,
     EMPTYUNITATT = 306,
     EMPTYVALUEATT = 307,
     EMPTYLBVALUEATT = 308,
     EMPTYUBVALUEATT = 309,
     LBVALUEATT = 310,
     UBVALUEATT = 311,
     EMPTYLBDUALVALUEATT = 312,
     EMPTYUBDUALVALUEATT = 313,
     LBDUALVALUEATT = 314,
     UBDUALVALUEATT = 315,
     SOLVERATT = 316,
     EMPTYSOLVERATT = 317,
     WEIGHTATT = 318,
     EMPTYWEIGHTATT = 319,
     TRANSPORTTYPEATT = 320,
     LOCATIONTYPEATT = 321,
     HEADERSTART = 322,
     HEADEREND = 323,
     GENERALSTART = 324,
     GENERALEND = 325,
     SYSTEMSTART = 326,
     SYSTEMEND = 327,
     SERVICESTART = 328,
     SERVICEEND = 329,
     JOBSTART = 330,
     JOBEND = 331,
     OPTIMIZATIONSTART = 332,
     OPTIMIZATIONEND = 333,
     FILENAMESTART = 334,
     FILENAMEEND = 335,
     FILENAMEEMPTY = 336,
     FILENAMESTARTANDEND = 337,
     FILESOURCESTART = 338,
     FILESOURCEEND = 339,
     FILESOURCEEMPTY = 340,
     FILESOURCESTARTANDEND = 341,
     FILEDESCRIPTIONSTART = 342,
     FILEDESCRIPTIONEND = 343,
     FILEDESCRIPTIONEMPTY = 344,
     FILEDESCRIPTIONSTARTANDEND = 345,
     FILECREATORSTART = 346,
     FILECREATOREND = 347,
     FILECREATOREMPTY = 348,
     FILECREATORSTARTANDEND = 349,
     FILELICENCESTART = 350,
     FILELICENCEEND = 351,
     FILELICENCEEMPTY = 352,
     FILELICENCESTARTANDEND = 353,
     SERVICEURISTART = 354,
     SERVICEURIEND = 355,
     SERVICENAMESTART = 356,
     SERVICENAMEEND = 357,
     INSTANCENAMESTART = 358,
     INSTANCENAMEEND = 359,
     INSTANCELOCATIONSTART = 360,
     INSTANCELOCATIONEND = 361,
     JOBIDSTART = 362,
     JOBIDEND = 363,
     SOLVERTOINVOKESTART = 364,
     SOLVERTOINVOKEEND = 365,
     LICENSESTART = 366,
     LICENSEEND = 367,
     USERNAMESTART = 368,
     USERNAMEEND = 369,
     PASSWORDSTART = 370,
     PASSWORDEND = 371,
     CONTACTSTART = 372,
     CONTACTEND = 373,
     OTHEROPTIONSSTART = 374,
     OTHEROPTIONSEND = 375,
     OTHERSTART = 376,
     OTHEREND = 377,
     MINDISKSPACESTART = 378,
     MINDISKSPACEEND = 379,
     MINMEMORYSTART = 380,
     MINMEMORYEND = 381,
     MINCPUSPEEDSTART = 382,
     MINCPUSPEEDEND = 383,
     MINCPUNUMBERSTART = 384,
     MINCPUNUMBEREND = 385,
     SERVICETYPESTART = 386,
     SERVICETYPEEND = 387,
     MAXTIMESTART = 388,
     MAXTIMEEND = 389,
     REQUESTEDSTARTTIMESTART = 390,
     REQUESTEDSTARTTIMEEND = 391,
     DEPENDENCIESSTART = 392,
     DEPENDENCIESEND = 393,
     REQUIREDDIRECTORIESSTART = 394,
     REQUIREDDIRECTORIESEND = 395,
     REQUIREDFILESSTART = 396,
     REQUIREDFILESEND = 397,
     PATHSTART = 398,
     PATHEND = 399,
     PATHPAIRSTART = 400,
     PATHPAIREND = 401,
     DIRECTORIESTOMAKESTART = 402,
     DIRECTORIESTOMAKEEND = 403,
     FILESTOMAKESTART = 404,
     FILESTOMAKEEND = 405,
     DIRECTORIESTODELETESTART = 406,
     DIRECTORIESTODELETEEND = 407,
     FILESTODELETESTART = 408,
     FILESTODELETEEND = 409,
     INPUTDIRECTORIESTOMOVESTART = 410,
     INPUTDIRECTORIESTOMOVEEND = 411,
     INPUTFILESTOMOVESTART = 412,
     INPUTFILESTOMOVEEND = 413,
     OUTPUTDIRECTORIESTOMOVESTART = 414,
     OUTPUTDIRECTORIESTOMOVEEND = 415,
     OUTPUTFILESTOMOVESTART = 416,
     OUTPUTFILESTOMOVEEND = 417,
     PROCESSESTOKILLSTART = 418,
     PROCESSESTOKILLEND = 419,
     PROCESSSTART = 420,
     PROCESSEND = 421,
     VARIABLESSTART = 422,
     VARIABLESEND = 423,
     INITIALVARIABLEVALUESSTART = 424,
     INITIALVARIABLEVALUESEND = 425,
     VARSTART = 426,
     VAREND = 427,
     INITIALVARIABLEVALUESSTRINGSTART = 428,
     INITIALVARIABLEVALUESSTRINGEND = 429,
     INITIALBASISSTATUSSTART = 430,
     INITIALBASISSTATUSEND = 431,
     BASICSTART = 432,
     BASICEND = 433,
     ATUPPERSTART = 434,
     ATUPPEREND = 435,
     ATLOWERSTART = 436,
     ATLOWEREND = 437,
     SUPERBASICSTART = 438,
     SUPERBASICEND = 439,
     ISFREESTART = 440,
     ISFREEEND = 441,
     UNKNOWNSTART = 442,
     UNKNOWNEND = 443,
     INTEGERVARIABLEBRANCHINGWEIGHTSSTART = 444,
     INTEGERVARIABLEBRANCHINGWEIGHTSEND = 445,
     SOSVARIABLEBRANCHINGWEIGHTSSTART = 446,
     SOSVARIABLEBRANCHINGWEIGHTSEND = 447,
     SOSSTART = 448,
     SOSEND = 449,
     OBJECTIVESSTART = 450,
     OBJECTIVESEND = 451,
     INITIALOBJECTIVEVALUESSTART = 452,
     INITIALOBJECTIVEVALUESEND = 453,
     OBJSTART = 454,
     OBJEND = 455,
     INITIALOBJECTIVEBOUNDSSTART = 456,
     INITIALOBJECTIVEBOUNDSEND = 457,
     CONSTRAINTSSTART = 458,
     CONSTRAINTSEND = 459,
     INITIALCONSTRAINTVALUESSTART = 460,
     INITIALCONSTRAINTVALUESEND = 461,
     CONSTART = 462,
     CONEND = 463,
     INITIALDUALVALUESSTART = 464,
     INITIALDUALVALUESEND = 465,
     SOLVEROPTIONSSTART = 466,
     SOLVEROPTIONSEND = 467,
     SOLVEROPTIONSTART = 468,
     SOLVEROPTIONEND = 469,
     ENUMERATIONSTART = 470,
     ENUMERATIONEND = 471,
     ITEMEMPTY = 472,
     ITEMSTART = 473,
     ITEMEND = 474,
     ITEMSTARTANDEND = 475,
     BASE64START = 476,
     BASE64END = 477,
     INCRATT = 478,
     MULTATT = 479,
     SIZEOFATT = 480,
     ELSTART = 481,
     ELEND = 482,
     DUMMY = 483
   };
#endif
/* Tokens.  */
#define ATTRIBUTETEXT 258
#define ELEMENTTEXT 259
#define ITEMTEXT 260
#define INTEGER 261
#define DOUBLE 262
#define QUOTE 263
#define TWOQUOTES 264
#define GREATERTHAN 265
#define ENDOFELEMENT 266
#define OSOLSTART 267
#define OSOLSTARTEMPTY 268
#define OSOLATTRIBUTETEXT 269
#define OSOLEND 270
#define NUMBEROFOTHEROPTIONSATT 271
#define NUMBEROFENUMERATIONSATT 272
#define NUMBEROFJOBIDSATT 273
#define NUMBEROFPATHSATT 274
#define NUMBEROFPATHPAIRSATT 275
#define FROMATT 276
#define TOATT 277
#define MAKECOPYATT 278
#define CATEGORYATT 279
#define TYPEATT 280
#define GROUPWEIGHTATT 281
#define NUMBEROFPROCESSESATT 282
#define NUMBEROFSOLVEROPTIONSATT 283
#define NUMBEROFSOSATT 284
#define NUMBEROFVARIABLESATT 285
#define NUMBEROFOBJECTIVESATT 286
#define NUMBEROFCONSTRAINTSATT 287
#define NUMBEROFOTHERVARIABLEOPTIONSATT 288
#define NUMBEROFOTHEROBJECTIVEOPTIONSATT 289
#define NUMBEROFOTHERCONSTRAINTOPTIONSATT 290
#define NUMBEROFITEMSATT 291
#define NUMBEROFVARATT 292
#define NUMBEROFOBJATT 293
#define NUMBEROFCONATT 294
#define NUMBEROFELATT 295
#define NAMEATT 296
#define IDXATT 297
#define SOSIDXATT 298
#define VALUEATT 299
#define UNITATT 300
#define DESCRIPTIONATT 301
#define EMPTYTYPEATT 302
#define EMPTYNAMEATT 303
#define EMPTYCATEGORYATT 304
#define EMPTYDESCRIPTIONATT 305
#define EMPTYUNITATT 306
#define EMPTYVALUEATT 307
#define EMPTYLBVALUEATT 308
#define EMPTYUBVALUEATT 309
#define LBVALUEATT 310
#define UBVALUEATT 311
#define EMPTYLBDUALVALUEATT 312
#define EMPTYUBDUALVALUEATT 313
#define LBDUALVALUEATT 314
#define UBDUALVALUEATT 315
#define SOLVERATT 316
#define EMPTYSOLVERATT 317
#define WEIGHTATT 318
#define EMPTYWEIGHTATT 319
#define TRANSPORTTYPEATT 320
#define LOCATIONTYPEATT 321
#define HEADERSTART 322
#define HEADEREND 323
#define GENERALSTART 324
#define GENERALEND 325
#define SYSTEMSTART 326
#define SYSTEMEND 327
#define SERVICESTART 328
#define SERVICEEND 329
#define JOBSTART 330
#define JOBEND 331
#define OPTIMIZATIONSTART 332
#define OPTIMIZATIONEND 333
#define FILENAMESTART 334
#define FILENAMEEND 335
#define FILENAMEEMPTY 336
#define FILENAMESTARTANDEND 337
#define FILESOURCESTART 338
#define FILESOURCEEND 339
#define FILESOURCEEMPTY 340
#define FILESOURCESTARTANDEND 341
#define FILEDESCRIPTIONSTART 342
#define FILEDESCRIPTIONEND 343
#define FILEDESCRIPTIONEMPTY 344
#define FILEDESCRIPTIONSTARTANDEND 345
#define FILECREATORSTART 346
#define FILECREATOREND 347
#define FILECREATOREMPTY 348
#define FILECREATORSTARTANDEND 349
#define FILELICENCESTART 350
#define FILELICENCEEND 351
#define FILELICENCEEMPTY 352
#define FILELICENCESTARTANDEND 353
#define SERVICEURISTART 354
#define SERVICEURIEND 355
#define SERVICENAMESTART 356
#define SERVICENAMEEND 357
#define INSTANCENAMESTART 358
#define INSTANCENAMEEND 359
#define INSTANCELOCATIONSTART 360
#define INSTANCELOCATIONEND 361
#define JOBIDSTART 362
#define JOBIDEND 363
#define SOLVERTOINVOKESTART 364
#define SOLVERTOINVOKEEND 365
#define LICENSESTART 366
#define LICENSEEND 367
#define USERNAMESTART 368
#define USERNAMEEND 369
#define PASSWORDSTART 370
#define PASSWORDEND 371
#define CONTACTSTART 372
#define CONTACTEND 373
#define OTHEROPTIONSSTART 374
#define OTHEROPTIONSEND 375
#define OTHERSTART 376
#define OTHEREND 377
#define MINDISKSPACESTART 378
#define MINDISKSPACEEND 379
#define MINMEMORYSTART 380
#define MINMEMORYEND 381
#define MINCPUSPEEDSTART 382
#define MINCPUSPEEDEND 383
#define MINCPUNUMBERSTART 384
#define MINCPUNUMBEREND 385
#define SERVICETYPESTART 386
#define SERVICETYPEEND 387
#define MAXTIMESTART 388
#define MAXTIMEEND 389
#define REQUESTEDSTARTTIMESTART 390
#define REQUESTEDSTARTTIMEEND 391
#define DEPENDENCIESSTART 392
#define DEPENDENCIESEND 393
#define REQUIREDDIRECTORIESSTART 394
#define REQUIREDDIRECTORIESEND 395
#define REQUIREDFILESSTART 396
#define REQUIREDFILESEND 397
#define PATHSTART 398
#define PATHEND 399
#define PATHPAIRSTART 400
#define PATHPAIREND 401
#define DIRECTORIESTOMAKESTART 402
#define DIRECTORIESTOMAKEEND 403
#define FILESTOMAKESTART 404
#define FILESTOMAKEEND 405
#define DIRECTORIESTODELETESTART 406
#define DIRECTORIESTODELETEEND 407
#define FILESTODELETESTART 408
#define FILESTODELETEEND 409
#define INPUTDIRECTORIESTOMOVESTART 410
#define INPUTDIRECTORIESTOMOVEEND 411
#define INPUTFILESTOMOVESTART 412
#define INPUTFILESTOMOVEEND 413
#define OUTPUTDIRECTORIESTOMOVESTART 414
#define OUTPUTDIRECTORIESTOMOVEEND 415
#define OUTPUTFILESTOMOVESTART 416
#define OUTPUTFILESTOMOVEEND 417
#define PROCESSESTOKILLSTART 418
#define PROCESSESTOKILLEND 419
#define PROCESSSTART 420
#define PROCESSEND 421
#define VARIABLESSTART 422
#define VARIABLESEND 423
#define INITIALVARIABLEVALUESSTART 424
#define INITIALVARIABLEVALUESEND 425
#define VARSTART 426
#define VAREND 427
#define INITIALVARIABLEVALUESSTRINGSTART 428
#define INITIALVARIABLEVALUESSTRINGEND 429
#define INITIALBASISSTATUSSTART 430
#define INITIALBASISSTATUSEND 431
#define BASICSTART 432
#define BASICEND 433
#define ATUPPERSTART 434
#define ATUPPEREND 435
#define ATLOWERSTART 436
#define ATLOWEREND 437
#define SUPERBASICSTART 438
#define SUPERBASICEND 439
#define ISFREESTART 440
#define ISFREEEND 441
#define UNKNOWNSTART 442
#define UNKNOWNEND 443
#define INTEGERVARIABLEBRANCHINGWEIGHTSSTART 444
#define INTEGERVARIABLEBRANCHINGWEIGHTSEND 445
#define SOSVARIABLEBRANCHINGWEIGHTSSTART 446
#define SOSVARIABLEBRANCHINGWEIGHTSEND 447
#define SOSSTART 448
#define SOSEND 449
#define OBJECTIVESSTART 450
#define OBJECTIVESEND 451
#define INITIALOBJECTIVEVALUESSTART 452
#define INITIALOBJECTIVEVALUESEND 453
#define OBJSTART 454
#define OBJEND 455
#define INITIALOBJECTIVEBOUNDSSTART 456
#define INITIALOBJECTIVEBOUNDSEND 457
#define CONSTRAINTSSTART 458
#define CONSTRAINTSEND 459
#define INITIALCONSTRAINTVALUESSTART 460
#define INITIALCONSTRAINTVALUESEND 461
#define CONSTART 462
#define CONEND 463
#define INITIALDUALVALUESSTART 464
#define INITIALDUALVALUESEND 465
#define SOLVEROPTIONSSTART 466
#define SOLVEROPTIONSEND 467
#define SOLVEROPTIONSTART 468
#define SOLVEROPTIONEND 469
#define ENUMERATIONSTART 470
#define ENUMERATIONEND 471
#define ITEMEMPTY 472
#define ITEMSTART 473
#define ITEMEND 474
#define ITEMSTARTANDEND 475
#define BASE64START 476
#define BASE64END 477
#define INCRATT 478
#define MULTATT 479
#define SIZEOFATT 480
#define ELSTART 481
#define ELEND 482
#define DUMMY 483




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{


	double dval;
	int ival;
	char* sval;



} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif



#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif



