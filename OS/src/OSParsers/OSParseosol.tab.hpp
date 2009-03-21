/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
     INTEGER = 260,
     DOUBLE = 261,
     QUOTE = 262,
     GREATERTHAN = 263,
     ENDOFELEMENT = 264,
     OSOLSTART = 265,
     OSOLSTARTEMPTY = 266,
     OSOLATTRIBUTETEXT = 267,
     OSOLEND = 268,
     LOCATIONTYPEATT = 269,
     TRANSPORTTYPEATT = 270,
     NUMBEROFOTHEROPTIONSATT = 271,
     NUMBEROFJOBIDSATT = 272,
     NUMBEROFPATHSATT = 273,
     NUMBEROFPATHPAIRSATT = 274,
     FROMATT = 275,
     TOATT = 276,
     MAKECOPYATT = 277,
     SOLVERATT = 278,
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
     NUMBEROFVARATT = 291,
     NUMBEROFOBJATT = 292,
     NUMBEROFCONATT = 293,
     NAMEATT = 294,
     IDXATT = 295,
     SOSIDXATT = 296,
     VALUEATT = 297,
     UNITATT = 298,
     DESCRIPTIONATT = 299,
     LBVALUEATT = 300,
     UBVALUEATT = 301,
     LBDUALVALUEATT = 302,
     UBDUALVALUEATT = 303,
     GENERALSTART = 304,
     GENERALEND = 305,
     SYSTEMSTART = 306,
     SYSTEMEND = 307,
     SERVICESTART = 308,
     SERVICEEND = 309,
     JOBSTART = 310,
     JOBEND = 311,
     OPTIMIZATIONSTART = 312,
     OPTIMIZATIONEND = 313,
     SERVICEURISTART = 314,
     SERVICEURIEND = 315,
     SERVICENAMESTART = 316,
     SERVICENAMEEND = 317,
     INSTANCENAMESTART = 318,
     INSTANCENAMEEND = 319,
     INSTANCELOCATIONSTART = 320,
     INSTANCELOCATIONEND = 321,
     JOBIDSTART = 322,
     JOBIDEND = 323,
     SOLVERTOINVOKESTART = 324,
     SOLVERTOINVOKEEND = 325,
     LICENSESTART = 326,
     LICENSEEND = 327,
     USERNAMESTART = 328,
     USERNAMEEND = 329,
     PASSWORDSTART = 330,
     PASSWORDEND = 331,
     CONTACTSTART = 332,
     CONTACTEND = 333,
     OTHEROPTIONSSTART = 334,
     OTHEROPTIONSEND = 335,
     OTHERSTART = 336,
     OTHEREND = 337,
     MINDISKSPACESTART = 338,
     MINDISKSPACEEND = 339,
     MINMEMORYSIZESTART = 340,
     MINMEMORYSIZEEND = 341,
     MINCPUSPEEDSTART = 342,
     MINCPUSPEEDEND = 343,
     MINCPUNUMBERSTART = 344,
     MINCPUNUMBEREND = 345,
     SERVICETYPESTART = 346,
     SERVICETYPEEND = 347,
     MAXTIMESTART = 348,
     MAXTIMEEND = 349,
     REQUESTEDSTARTTIMESTART = 350,
     REQUESTEDSTARTTIMEEND = 351,
     DEPENDENCIESSTART = 352,
     DEPENDENCIESEND = 353,
     REQUIREDDIRECTORIESSTART = 354,
     REQUIREDDIRECTORIESEND = 355,
     REQUIREDFILESSTART = 356,
     REQUIREDFILESEND = 357,
     PATHSTART = 358,
     PATHEND = 359,
     PATHPAIRSTART = 360,
     PATHPAIREND = 361,
     DIRECTORIESTOMAKESTART = 362,
     DIRECTORIESTOMAKEEND = 363,
     FILESTOMAKESTART = 364,
     FILESTOMAKEEND = 365,
     DIRECTORIESTODELETESTART = 366,
     DIRECTORIESTODELETEEND = 367,
     FILESTODELETESTART = 368,
     FILESTODELETEEND = 369,
     INPUTDIRECTORIESTOMOVESTART = 370,
     INPUTDIRECTORIESTOMOVEEND = 371,
     INPUTFILESTOMOVESTART = 372,
     INPUTFILESTOMOVEEND = 373,
     OUTPUTDIRECTORIESTOMOVESTART = 374,
     OUTPUTDIRECTORIESTOMOVEEND = 375,
     OUTPUTFILESTOMOVESTART = 376,
     OUTPUTFILESTOMOVEEND = 377,
     PROCESSESTOKILLSTART = 378,
     PROCESSESTOKILLEND = 379,
     PROCESSSTART = 380,
     PROCESSEND = 381,
     VARIABLESSTART = 382,
     VARIABLESEND = 383,
     INITIALVARIABLEVALUESSTART = 384,
     INITIALVARIABLEVALUESEND = 385,
     VARSTART = 386,
     VAREND = 387,
     INITIALVARIABLEVALUESSTRINGSTART = 388,
     INITIALVARIABLEVALUESSTRINGEND = 389,
     INITIALBASISSTATUSSTART = 390,
     INITIALBASISSTATUSEND = 391,
     INTEGERVARIABLEBRANCHINGWEIGHTSSTART = 392,
     INTEGERVARIABLEBRANCHINGWEIGHTSEND = 393,
     SOSVARIABLEBRANCHINGWEIGHTSSTART = 394,
     SOSVARIABLEBRANCHINGWEIGHTSEND = 395,
     SOSSTART = 396,
     SOSEND = 397,
     OBJECTIVESSTART = 398,
     OBJECTIVESEND = 399,
     INITIALOBJECTIVEVALUESSTART = 400,
     INITIALOBJECTIVEVALUESEND = 401,
     OBJSTART = 402,
     OBJEND = 403,
     INITIALOBJECTIVEBOUNDSSTART = 404,
     INITIALOBJECTIVEBOUNDSEND = 405,
     CONSTRAINTSSTART = 406,
     CONSTRAINTSEND = 407,
     INITIALCONSTRAINTVALUESSTART = 408,
     INITIALCONSTRAINTVALUESEND = 409,
     CONSTART = 410,
     CONEND = 411,
     INITIALDUALVALUESSTART = 412,
     INITIALDUALVALUESEND = 413,
     SOLVEROPTIONSSTART = 414,
     SOLVEROPTIONSEND = 415,
     SOLVEROPTIONSTART = 416,
     SOLVEROPTIONEND = 417,
     DUMMY = 418
   };
#endif
/* Tokens.  */
#define ATTRIBUTETEXT 258
#define ELEMENTTEXT 259
#define INTEGER 260
#define DOUBLE 261
#define QUOTE 262
#define GREATERTHAN 263
#define ENDOFELEMENT 264
#define OSOLSTART 265
#define OSOLSTARTEMPTY 266
#define OSOLATTRIBUTETEXT 267
#define OSOLEND 268
#define LOCATIONTYPEATT 269
#define TRANSPORTTYPEATT 270
#define NUMBEROFOTHEROPTIONSATT 271
#define NUMBEROFJOBIDSATT 272
#define NUMBEROFPATHSATT 273
#define NUMBEROFPATHPAIRSATT 274
#define FROMATT 275
#define TOATT 276
#define MAKECOPYATT 277
#define SOLVERATT 278
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
#define NUMBEROFVARATT 291
#define NUMBEROFOBJATT 292
#define NUMBEROFCONATT 293
#define NAMEATT 294
#define IDXATT 295
#define SOSIDXATT 296
#define VALUEATT 297
#define UNITATT 298
#define DESCRIPTIONATT 299
#define LBVALUEATT 300
#define UBVALUEATT 301
#define LBDUALVALUEATT 302
#define UBDUALVALUEATT 303
#define GENERALSTART 304
#define GENERALEND 305
#define SYSTEMSTART 306
#define SYSTEMEND 307
#define SERVICESTART 308
#define SERVICEEND 309
#define JOBSTART 310
#define JOBEND 311
#define OPTIMIZATIONSTART 312
#define OPTIMIZATIONEND 313
#define SERVICEURISTART 314
#define SERVICEURIEND 315
#define SERVICENAMESTART 316
#define SERVICENAMEEND 317
#define INSTANCENAMESTART 318
#define INSTANCENAMEEND 319
#define INSTANCELOCATIONSTART 320
#define INSTANCELOCATIONEND 321
#define JOBIDSTART 322
#define JOBIDEND 323
#define SOLVERTOINVOKESTART 324
#define SOLVERTOINVOKEEND 325
#define LICENSESTART 326
#define LICENSEEND 327
#define USERNAMESTART 328
#define USERNAMEEND 329
#define PASSWORDSTART 330
#define PASSWORDEND 331
#define CONTACTSTART 332
#define CONTACTEND 333
#define OTHEROPTIONSSTART 334
#define OTHEROPTIONSEND 335
#define OTHERSTART 336
#define OTHEREND 337
#define MINDISKSPACESTART 338
#define MINDISKSPACEEND 339
#define MINMEMORYSIZESTART 340
#define MINMEMORYSIZEEND 341
#define MINCPUSPEEDSTART 342
#define MINCPUSPEEDEND 343
#define MINCPUNUMBERSTART 344
#define MINCPUNUMBEREND 345
#define SERVICETYPESTART 346
#define SERVICETYPEEND 347
#define MAXTIMESTART 348
#define MAXTIMEEND 349
#define REQUESTEDSTARTTIMESTART 350
#define REQUESTEDSTARTTIMEEND 351
#define DEPENDENCIESSTART 352
#define DEPENDENCIESEND 353
#define REQUIREDDIRECTORIESSTART 354
#define REQUIREDDIRECTORIESEND 355
#define REQUIREDFILESSTART 356
#define REQUIREDFILESEND 357
#define PATHSTART 358
#define PATHEND 359
#define PATHPAIRSTART 360
#define PATHPAIREND 361
#define DIRECTORIESTOMAKESTART 362
#define DIRECTORIESTOMAKEEND 363
#define FILESTOMAKESTART 364
#define FILESTOMAKEEND 365
#define DIRECTORIESTODELETESTART 366
#define DIRECTORIESTODELETEEND 367
#define FILESTODELETESTART 368
#define FILESTODELETEEND 369
#define INPUTDIRECTORIESTOMOVESTART 370
#define INPUTDIRECTORIESTOMOVEEND 371
#define INPUTFILESTOMOVESTART 372
#define INPUTFILESTOMOVEEND 373
#define OUTPUTDIRECTORIESTOMOVESTART 374
#define OUTPUTDIRECTORIESTOMOVEEND 375
#define OUTPUTFILESTOMOVESTART 376
#define OUTPUTFILESTOMOVEEND 377
#define PROCESSESTOKILLSTART 378
#define PROCESSESTOKILLEND 379
#define PROCESSSTART 380
#define PROCESSEND 381
#define VARIABLESSTART 382
#define VARIABLESEND 383
#define INITIALVARIABLEVALUESSTART 384
#define INITIALVARIABLEVALUESEND 385
#define VARSTART 386
#define VAREND 387
#define INITIALVARIABLEVALUESSTRINGSTART 388
#define INITIALVARIABLEVALUESSTRINGEND 389
#define INITIALBASISSTATUSSTART 390
#define INITIALBASISSTATUSEND 391
#define INTEGERVARIABLEBRANCHINGWEIGHTSSTART 392
#define INTEGERVARIABLEBRANCHINGWEIGHTSEND 393
#define SOSVARIABLEBRANCHINGWEIGHTSSTART 394
#define SOSVARIABLEBRANCHINGWEIGHTSEND 395
#define SOSSTART 396
#define SOSEND 397
#define OBJECTIVESSTART 398
#define OBJECTIVESEND 399
#define INITIALOBJECTIVEVALUESSTART 400
#define INITIALOBJECTIVEVALUESEND 401
#define OBJSTART 402
#define OBJEND 403
#define INITIALOBJECTIVEBOUNDSSTART 404
#define INITIALOBJECTIVEBOUNDSEND 405
#define CONSTRAINTSSTART 406
#define CONSTRAINTSEND 407
#define INITIALCONSTRAINTVALUESSTART 408
#define INITIALCONSTRAINTVALUESEND 409
#define CONSTART 410
#define CONEND 411
#define INITIALDUALVALUESSTART 412
#define INITIALDUALVALUESEND 413
#define SOLVEROPTIONSSTART 414
#define SOLVEROPTIONSEND 415
#define SOLVEROPTIONSTART 416
#define SOLVEROPTIONEND 417
#define DUMMY 418




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE

{
	double dval;
	int ival;
	char* sval;
}
/* Line 1529 of yacc.c.  */

	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
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


