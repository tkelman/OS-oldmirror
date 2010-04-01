
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
     INTEGER = 260,
     DOUBLE = 261,
     QUOTE = 262,
     TWOQUOTES = 263,
     GREATERTHAN = 264,
     ENDOFELEMENT = 265,
     OSOLSTART = 266,
     OSOLSTARTEMPTY = 267,
     OSOLATTRIBUTETEXT = 268,
     OSOLEND = 269,
     LOCATIONTYPEATT = 270,
     TRANSPORTTYPEATT = 271,
     NUMBEROFOTHEROPTIONSATT = 272,
     NUMBEROFJOBIDSATT = 273,
     NUMBEROFPATHSATT = 274,
     NUMBEROFPATHPAIRSATT = 275,
     FROMATT = 276,
     TOATT = 277,
     MAKECOPYATT = 278,
     SOLVERATT = 279,
     CATEGORYATT = 280,
     TYPEATT = 281,
     GROUPWEIGHTATT = 282,
     NUMBEROFPROCESSESATT = 283,
     NUMBEROFSOLVEROPTIONSATT = 284,
     NUMBEROFSOSATT = 285,
     NUMBEROFVARIABLESATT = 286,
     NUMBEROFOBJECTIVESATT = 287,
     NUMBEROFCONSTRAINTSATT = 288,
     NUMBEROFOTHERVARIABLEOPTIONSATT = 289,
     NUMBEROFOTHEROBJECTIVEOPTIONSATT = 290,
     NUMBEROFOTHERCONSTRAINTOPTIONSATT = 291,
     NUMBEROFVARATT = 292,
     NUMBEROFOBJATT = 293,
     NUMBEROFCONATT = 294,
     NAMEATT = 295,
     IDXATT = 296,
     SOSIDXATT = 297,
     VALUEATT = 298,
     UNITATT = 299,
     DESCRIPTIONATT = 300,
     LBVALUEATT = 301,
     UBVALUEATT = 302,
     LBDUALVALUEATT = 303,
     UBDUALVALUEATT = 304,
     GENERALSTART = 305,
     GENERALEND = 306,
     SYSTEMSTART = 307,
     SYSTEMEND = 308,
     SERVICESTART = 309,
     SERVICEEND = 310,
     JOBSTART = 311,
     JOBEND = 312,
     OPTIMIZATIONSTART = 313,
     OPTIMIZATIONEND = 314,
     SERVICEURISTART = 315,
     SERVICEURIEND = 316,
     SERVICENAMESTART = 317,
     SERVICENAMEEND = 318,
     INSTANCENAMESTART = 319,
     INSTANCENAMEEND = 320,
     INSTANCELOCATIONSTART = 321,
     INSTANCELOCATIONEND = 322,
     JOBIDSTART = 323,
     JOBIDEND = 324,
     SOLVERTOINVOKESTART = 325,
     SOLVERTOINVOKEEND = 326,
     LICENSESTART = 327,
     LICENSEEND = 328,
     USERNAMESTART = 329,
     USERNAMEEND = 330,
     PASSWORDSTART = 331,
     PASSWORDEND = 332,
     CONTACTSTART = 333,
     CONTACTEND = 334,
     OTHEROPTIONSSTART = 335,
     OTHEROPTIONSEND = 336,
     OTHERSTART = 337,
     OTHEREND = 338,
     MINDISKSPACESTART = 339,
     MINDISKSPACEEND = 340,
     MINMEMORYSIZESTART = 341,
     MINMEMORYSIZEEND = 342,
     MINCPUSPEEDSTART = 343,
     MINCPUSPEEDEND = 344,
     MINCPUNUMBERSTART = 345,
     MINCPUNUMBEREND = 346,
     SERVICETYPESTART = 347,
     SERVICETYPEEND = 348,
     MAXTIMESTART = 349,
     MAXTIMEEND = 350,
     REQUESTEDSTARTTIMESTART = 351,
     REQUESTEDSTARTTIMEEND = 352,
     DEPENDENCIESSTART = 353,
     DEPENDENCIESEND = 354,
     REQUIREDDIRECTORIESSTART = 355,
     REQUIREDDIRECTORIESEND = 356,
     REQUIREDFILESSTART = 357,
     REQUIREDFILESEND = 358,
     PATHSTART = 359,
     PATHEND = 360,
     PATHPAIRSTART = 361,
     PATHPAIREND = 362,
     DIRECTORIESTOMAKESTART = 363,
     DIRECTORIESTOMAKEEND = 364,
     FILESTOMAKESTART = 365,
     FILESTOMAKEEND = 366,
     DIRECTORIESTODELETESTART = 367,
     DIRECTORIESTODELETEEND = 368,
     FILESTODELETESTART = 369,
     FILESTODELETEEND = 370,
     INPUTDIRECTORIESTOMOVESTART = 371,
     INPUTDIRECTORIESTOMOVEEND = 372,
     INPUTFILESTOMOVESTART = 373,
     INPUTFILESTOMOVEEND = 374,
     OUTPUTDIRECTORIESTOMOVESTART = 375,
     OUTPUTDIRECTORIESTOMOVEEND = 376,
     OUTPUTFILESTOMOVESTART = 377,
     OUTPUTFILESTOMOVEEND = 378,
     PROCESSESTOKILLSTART = 379,
     PROCESSESTOKILLEND = 380,
     PROCESSSTART = 381,
     PROCESSEND = 382,
     VARIABLESSTART = 383,
     VARIABLESEND = 384,
     INITIALVARIABLEVALUESSTART = 385,
     INITIALVARIABLEVALUESEND = 386,
     VARSTART = 387,
     VAREND = 388,
     INITIALVARIABLEVALUESSTRINGSTART = 389,
     INITIALVARIABLEVALUESSTRINGEND = 390,
     INITIALBASISSTATUSSTART = 391,
     INITIALBASISSTATUSEND = 392,
     INTEGERVARIABLEBRANCHINGWEIGHTSSTART = 393,
     INTEGERVARIABLEBRANCHINGWEIGHTSEND = 394,
     SOSVARIABLEBRANCHINGWEIGHTSSTART = 395,
     SOSVARIABLEBRANCHINGWEIGHTSEND = 396,
     SOSSTART = 397,
     SOSEND = 398,
     OBJECTIVESSTART = 399,
     OBJECTIVESEND = 400,
     INITIALOBJECTIVEVALUESSTART = 401,
     INITIALOBJECTIVEVALUESEND = 402,
     OBJSTART = 403,
     OBJEND = 404,
     INITIALOBJECTIVEBOUNDSSTART = 405,
     INITIALOBJECTIVEBOUNDSEND = 406,
     CONSTRAINTSSTART = 407,
     CONSTRAINTSEND = 408,
     INITIALCONSTRAINTVALUESSTART = 409,
     INITIALCONSTRAINTVALUESEND = 410,
     CONSTART = 411,
     CONEND = 412,
     INITIALDUALVALUESSTART = 413,
     INITIALDUALVALUESEND = 414,
     SOLVEROPTIONSSTART = 415,
     SOLVEROPTIONSEND = 416,
     SOLVEROPTIONSTART = 417,
     SOLVEROPTIONEND = 418,
     DUMMY = 419
   };
#endif
/* Tokens.  */
#define ATTRIBUTETEXT 258
#define ELEMENTTEXT 259
#define INTEGER 260
#define DOUBLE 261
#define QUOTE 262
#define TWOQUOTES 263
#define GREATERTHAN 264
#define ENDOFELEMENT 265
#define OSOLSTART 266
#define OSOLSTARTEMPTY 267
#define OSOLATTRIBUTETEXT 268
#define OSOLEND 269
#define LOCATIONTYPEATT 270
#define TRANSPORTTYPEATT 271
#define NUMBEROFOTHEROPTIONSATT 272
#define NUMBEROFJOBIDSATT 273
#define NUMBEROFPATHSATT 274
#define NUMBEROFPATHPAIRSATT 275
#define FROMATT 276
#define TOATT 277
#define MAKECOPYATT 278
#define SOLVERATT 279
#define CATEGORYATT 280
#define TYPEATT 281
#define GROUPWEIGHTATT 282
#define NUMBEROFPROCESSESATT 283
#define NUMBEROFSOLVEROPTIONSATT 284
#define NUMBEROFSOSATT 285
#define NUMBEROFVARIABLESATT 286
#define NUMBEROFOBJECTIVESATT 287
#define NUMBEROFCONSTRAINTSATT 288
#define NUMBEROFOTHERVARIABLEOPTIONSATT 289
#define NUMBEROFOTHEROBJECTIVEOPTIONSATT 290
#define NUMBEROFOTHERCONSTRAINTOPTIONSATT 291
#define NUMBEROFVARATT 292
#define NUMBEROFOBJATT 293
#define NUMBEROFCONATT 294
#define NAMEATT 295
#define IDXATT 296
#define SOSIDXATT 297
#define VALUEATT 298
#define UNITATT 299
#define DESCRIPTIONATT 300
#define LBVALUEATT 301
#define UBVALUEATT 302
#define LBDUALVALUEATT 303
#define UBDUALVALUEATT 304
#define GENERALSTART 305
#define GENERALEND 306
#define SYSTEMSTART 307
#define SYSTEMEND 308
#define SERVICESTART 309
#define SERVICEEND 310
#define JOBSTART 311
#define JOBEND 312
#define OPTIMIZATIONSTART 313
#define OPTIMIZATIONEND 314
#define SERVICEURISTART 315
#define SERVICEURIEND 316
#define SERVICENAMESTART 317
#define SERVICENAMEEND 318
#define INSTANCENAMESTART 319
#define INSTANCENAMEEND 320
#define INSTANCELOCATIONSTART 321
#define INSTANCELOCATIONEND 322
#define JOBIDSTART 323
#define JOBIDEND 324
#define SOLVERTOINVOKESTART 325
#define SOLVERTOINVOKEEND 326
#define LICENSESTART 327
#define LICENSEEND 328
#define USERNAMESTART 329
#define USERNAMEEND 330
#define PASSWORDSTART 331
#define PASSWORDEND 332
#define CONTACTSTART 333
#define CONTACTEND 334
#define OTHEROPTIONSSTART 335
#define OTHEROPTIONSEND 336
#define OTHERSTART 337
#define OTHEREND 338
#define MINDISKSPACESTART 339
#define MINDISKSPACEEND 340
#define MINMEMORYSIZESTART 341
#define MINMEMORYSIZEEND 342
#define MINCPUSPEEDSTART 343
#define MINCPUSPEEDEND 344
#define MINCPUNUMBERSTART 345
#define MINCPUNUMBEREND 346
#define SERVICETYPESTART 347
#define SERVICETYPEEND 348
#define MAXTIMESTART 349
#define MAXTIMEEND 350
#define REQUESTEDSTARTTIMESTART 351
#define REQUESTEDSTARTTIMEEND 352
#define DEPENDENCIESSTART 353
#define DEPENDENCIESEND 354
#define REQUIREDDIRECTORIESSTART 355
#define REQUIREDDIRECTORIESEND 356
#define REQUIREDFILESSTART 357
#define REQUIREDFILESEND 358
#define PATHSTART 359
#define PATHEND 360
#define PATHPAIRSTART 361
#define PATHPAIREND 362
#define DIRECTORIESTOMAKESTART 363
#define DIRECTORIESTOMAKEEND 364
#define FILESTOMAKESTART 365
#define FILESTOMAKEEND 366
#define DIRECTORIESTODELETESTART 367
#define DIRECTORIESTODELETEEND 368
#define FILESTODELETESTART 369
#define FILESTODELETEEND 370
#define INPUTDIRECTORIESTOMOVESTART 371
#define INPUTDIRECTORIESTOMOVEEND 372
#define INPUTFILESTOMOVESTART 373
#define INPUTFILESTOMOVEEND 374
#define OUTPUTDIRECTORIESTOMOVESTART 375
#define OUTPUTDIRECTORIESTOMOVEEND 376
#define OUTPUTFILESTOMOVESTART 377
#define OUTPUTFILESTOMOVEEND 378
#define PROCESSESTOKILLSTART 379
#define PROCESSESTOKILLEND 380
#define PROCESSSTART 381
#define PROCESSEND 382
#define VARIABLESSTART 383
#define VARIABLESEND 384
#define INITIALVARIABLEVALUESSTART 385
#define INITIALVARIABLEVALUESEND 386
#define VARSTART 387
#define VAREND 388
#define INITIALVARIABLEVALUESSTRINGSTART 389
#define INITIALVARIABLEVALUESSTRINGEND 390
#define INITIALBASISSTATUSSTART 391
#define INITIALBASISSTATUSEND 392
#define INTEGERVARIABLEBRANCHINGWEIGHTSSTART 393
#define INTEGERVARIABLEBRANCHINGWEIGHTSEND 394
#define SOSVARIABLEBRANCHINGWEIGHTSSTART 395
#define SOSVARIABLEBRANCHINGWEIGHTSEND 396
#define SOSSTART 397
#define SOSEND 398
#define OBJECTIVESSTART 399
#define OBJECTIVESEND 400
#define INITIALOBJECTIVEVALUESSTART 401
#define INITIALOBJECTIVEVALUESEND 402
#define OBJSTART 403
#define OBJEND 404
#define INITIALOBJECTIVEBOUNDSSTART 405
#define INITIALOBJECTIVEBOUNDSEND 406
#define CONSTRAINTSSTART 407
#define CONSTRAINTSEND 408
#define INITIALCONSTRAINTVALUESSTART 409
#define INITIALCONSTRAINTVALUESEND 410
#define CONSTART 411
#define CONEND 412
#define INITIALDUALVALUESSTART 413
#define INITIALDUALVALUESEND 414
#define SOLVEROPTIONSSTART 415
#define SOLVEROPTIONSEND 416
#define SOLVEROPTIONSTART 417
#define SOLVEROPTIONEND 418
#define DUMMY 419




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



