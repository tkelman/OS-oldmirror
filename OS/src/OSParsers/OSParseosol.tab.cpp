/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Using locations.  */
#define YYLSP_NEEDED 1

/* Substitute the variable and function names.  */
#define yyparse osolparse
#define yylex   osollex
#define yyerror osolerror
#define yylval  osollval
#define yychar  osolchar
#define yydebug osoldebug
#define yynerrs osolnerrs
#define yylloc osollloc

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
     OSOLATTRIBUTETEXT = 266,
     OSOLEND = 267,
     LOCATIONTYPEATT = 268,
     TRANSPORTTYPEATT = 269,
     NUMBEROFOTHEROPTIONSATT = 270,
     NUMBEROFJOBIDSATT = 271,
     NUMBEROFPATHSATT = 272,
     NUMBEROFPATHPAIRSATT = 273,
     FROMATT = 274,
     TOATT = 275,
     MAKECOPYATT = 276,
     SOLVERATT = 277,
     CATEGORYATT = 278,
     TYPEATT = 279,
     NUMBEROFPROCESSESATT = 280,
     NUMBEROFSOLVEROPTIONSATT = 281,
     NUMBEROFVARIABLESATT = 282,
     NUMBEROFOBJECTIVESATT = 283,
     NUMBEROFCONSTRAINTSATT = 284,
     NUMBEROFOTHERVARIABLEOPTIONSATT = 285,
     NUMBEROFOTHEROBJECTIVEOPTIONSATT = 286,
     NUMBEROFOTHERCONSTRAINTOPTIONSATT = 287,
     NUMBEROFVARATT = 288,
     NUMBEROFOBJATT = 289,
     NUMBEROFCONATT = 290,
     NAMEATT = 291,
     IDXATT = 292,
     VALUEATT = 293,
     UNITATT = 294,
     DESCRIPTIONATT = 295,
     LBVALUEATT = 296,
     UBVALUEATT = 297,
     GENERALSTART = 298,
     GENERALEND = 299,
     SYSTEMSTART = 300,
     SYSTEMEND = 301,
     SERVICESTART = 302,
     SERVICEEND = 303,
     JOBSTART = 304,
     JOBEND = 305,
     OPTIMIZATIONSTART = 306,
     OPTIMIZATIONEND = 307,
     SERVICEURISTART = 308,
     SERVICEURIEND = 309,
     SERVICENAMESTART = 310,
     SERVICENAMEEND = 311,
     INSTANCENAMESTART = 312,
     INSTANCENAMEEND = 313,
     INSTANCELOCATIONSTART = 314,
     INSTANCELOCATIONEND = 315,
     JOBIDSTART = 316,
     JOBIDEND = 317,
     SOLVERTOINVOKESTART = 318,
     SOLVERTOINVOKEEND = 319,
     LICENSESTART = 320,
     LICENSEEND = 321,
     USERNAMESTART = 322,
     USERNAMEEND = 323,
     PASSWORDSTART = 324,
     PASSWORDEND = 325,
     CONTACTSTART = 326,
     CONTACTEND = 327,
     OTHEROPTIONSSTART = 328,
     OTHEROPTIONSEND = 329,
     OTHERSTART = 330,
     OTHEREND = 331,
     MINDISKSPACESTART = 332,
     MINDISKSPACEEND = 333,
     MINMEMORYSIZESTART = 334,
     MINMEMORYSIZEEND = 335,
     MINCPUSPEEDSTART = 336,
     MINCPUSPEEDEND = 337,
     MINCPUNUMBERSTART = 338,
     MINCPUNUMBEREND = 339,
     SERVICETYPESTART = 340,
     SERVICETYPEEND = 341,
     MAXTIMESTART = 342,
     MAXTIMEEND = 343,
     SCHEDULEDSTARTTIMESTART = 344,
     SCHEDULEDSTARTTIMEEND = 345,
     DEPENDENCIESSTART = 346,
     DEPENDENCIESEND = 347,
     REQUIREDDIRECTORIESSTART = 348,
     REQUIREDDIRECTORIESEND = 349,
     REQUIREDFILESSTART = 350,
     REQUIREDFILESEND = 351,
     PATHSTART = 352,
     PATHEND = 353,
     PATHPAIRSTART = 354,
     PATHPAIREND = 355,
     DIRECTORIESTOMAKESTART = 356,
     DIRECTORIESTOMAKEEND = 357,
     FILESTOCREATESTART = 358,
     FILESTOCREATEEND = 359,
     DIRECTORIESTODELETESTART = 360,
     DIRECTORIESTODELETEEND = 361,
     FILESTODELETESTART = 362,
     FILESTODELETEEND = 363,
     INPUTDIRECTORIESTOMOVESTART = 364,
     INPUTDIRECTORIESTOMOVEEND = 365,
     INPUTFILESTOMOVESTART = 366,
     INPUTFILESTOMOVEEND = 367,
     OUTPUTDIRECTORIESTOMOVESTART = 368,
     OUTPUTDIRECTORIESTOMOVEEND = 369,
     OUTPUTFILESTOMOVESTART = 370,
     OUTPUTFILESTOMOVEEND = 371,
     PROCESSESTOKILLSTART = 372,
     PROCESSESTOKILLEND = 373,
     PROCESSSTART = 374,
     PROCESSEND = 375,
     VARIABLESSTART = 376,
     VARIABLESEND = 377,
     INITIALVARIABLEVALUESSTART = 378,
     INITIALVARIABLEVALUESEND = 379,
     VARSTART = 380,
     VAREND = 381,
     INITIALVARIABLEVALUESSTRINGSTART = 382,
     INITIALVARIABLEVALUESSTRINGEND = 383,
     OBJECTIVESSTART = 384,
     OBJECTIVESEND = 385,
     INITIALOBJECTIVEVALUESSTART = 386,
     INITIALOBJECTIVEVALUESEND = 387,
     OBJSTART = 388,
     OBJEND = 389,
     INITIALOBJECTIVEBOUNDSSTART = 390,
     INITIALOBJECTIVEBOUNDSEND = 391,
     CONSTRAINTSSTART = 392,
     CONSTRAINTSEND = 393,
     INITIALCONSTRAINTVALUESSTART = 394,
     INITIALCONSTRAINTVALUESEND = 395,
     CONSTART = 396,
     CONEND = 397,
     INITIALDUALVALUESSTART = 398,
     INITIALDUALVALUESEND = 399,
     SOLVEROPTIONSSTART = 400,
     SOLVEROPTIONSEND = 401,
     SOLVEROPTIONSTART = 402,
     SOLVEROPTIONEND = 403,
     DUMMY = 404
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
#define OSOLATTRIBUTETEXT 266
#define OSOLEND 267
#define LOCATIONTYPEATT 268
#define TRANSPORTTYPEATT 269
#define NUMBEROFOTHEROPTIONSATT 270
#define NUMBEROFJOBIDSATT 271
#define NUMBEROFPATHSATT 272
#define NUMBEROFPATHPAIRSATT 273
#define FROMATT 274
#define TOATT 275
#define MAKECOPYATT 276
#define SOLVERATT 277
#define CATEGORYATT 278
#define TYPEATT 279
#define NUMBEROFPROCESSESATT 280
#define NUMBEROFSOLVEROPTIONSATT 281
#define NUMBEROFVARIABLESATT 282
#define NUMBEROFOBJECTIVESATT 283
#define NUMBEROFCONSTRAINTSATT 284
#define NUMBEROFOTHERVARIABLEOPTIONSATT 285
#define NUMBEROFOTHEROBJECTIVEOPTIONSATT 286
#define NUMBEROFOTHERCONSTRAINTOPTIONSATT 287
#define NUMBEROFVARATT 288
#define NUMBEROFOBJATT 289
#define NUMBEROFCONATT 290
#define NAMEATT 291
#define IDXATT 292
#define VALUEATT 293
#define UNITATT 294
#define DESCRIPTIONATT 295
#define LBVALUEATT 296
#define UBVALUEATT 297
#define GENERALSTART 298
#define GENERALEND 299
#define SYSTEMSTART 300
#define SYSTEMEND 301
#define SERVICESTART 302
#define SERVICEEND 303
#define JOBSTART 304
#define JOBEND 305
#define OPTIMIZATIONSTART 306
#define OPTIMIZATIONEND 307
#define SERVICEURISTART 308
#define SERVICEURIEND 309
#define SERVICENAMESTART 310
#define SERVICENAMEEND 311
#define INSTANCENAMESTART 312
#define INSTANCENAMEEND 313
#define INSTANCELOCATIONSTART 314
#define INSTANCELOCATIONEND 315
#define JOBIDSTART 316
#define JOBIDEND 317
#define SOLVERTOINVOKESTART 318
#define SOLVERTOINVOKEEND 319
#define LICENSESTART 320
#define LICENSEEND 321
#define USERNAMESTART 322
#define USERNAMEEND 323
#define PASSWORDSTART 324
#define PASSWORDEND 325
#define CONTACTSTART 326
#define CONTACTEND 327
#define OTHEROPTIONSSTART 328
#define OTHEROPTIONSEND 329
#define OTHERSTART 330
#define OTHEREND 331
#define MINDISKSPACESTART 332
#define MINDISKSPACEEND 333
#define MINMEMORYSIZESTART 334
#define MINMEMORYSIZEEND 335
#define MINCPUSPEEDSTART 336
#define MINCPUSPEEDEND 337
#define MINCPUNUMBERSTART 338
#define MINCPUNUMBEREND 339
#define SERVICETYPESTART 340
#define SERVICETYPEEND 341
#define MAXTIMESTART 342
#define MAXTIMEEND 343
#define SCHEDULEDSTARTTIMESTART 344
#define SCHEDULEDSTARTTIMEEND 345
#define DEPENDENCIESSTART 346
#define DEPENDENCIESEND 347
#define REQUIREDDIRECTORIESSTART 348
#define REQUIREDDIRECTORIESEND 349
#define REQUIREDFILESSTART 350
#define REQUIREDFILESEND 351
#define PATHSTART 352
#define PATHEND 353
#define PATHPAIRSTART 354
#define PATHPAIREND 355
#define DIRECTORIESTOMAKESTART 356
#define DIRECTORIESTOMAKEEND 357
#define FILESTOCREATESTART 358
#define FILESTOCREATEEND 359
#define DIRECTORIESTODELETESTART 360
#define DIRECTORIESTODELETEEND 361
#define FILESTODELETESTART 362
#define FILESTODELETEEND 363
#define INPUTDIRECTORIESTOMOVESTART 364
#define INPUTDIRECTORIESTOMOVEEND 365
#define INPUTFILESTOMOVESTART 366
#define INPUTFILESTOMOVEEND 367
#define OUTPUTDIRECTORIESTOMOVESTART 368
#define OUTPUTDIRECTORIESTOMOVEEND 369
#define OUTPUTFILESTOMOVESTART 370
#define OUTPUTFILESTOMOVEEND 371
#define PROCESSESTOKILLSTART 372
#define PROCESSESTOKILLEND 373
#define PROCESSSTART 374
#define PROCESSEND 375
#define VARIABLESSTART 376
#define VARIABLESEND 377
#define INITIALVARIABLEVALUESSTART 378
#define INITIALVARIABLEVALUESEND 379
#define VARSTART 380
#define VAREND 381
#define INITIALVARIABLEVALUESSTRINGSTART 382
#define INITIALVARIABLEVALUESSTRINGEND 383
#define OBJECTIVESSTART 384
#define OBJECTIVESEND 385
#define INITIALOBJECTIVEVALUESSTART 386
#define INITIALOBJECTIVEVALUESEND 387
#define OBJSTART 388
#define OBJEND 389
#define INITIALOBJECTIVEBOUNDSSTART 390
#define INITIALOBJECTIVEBOUNDSEND 391
#define CONSTRAINTSSTART 392
#define CONSTRAINTSEND 393
#define INITIALCONSTRAINTVALUESSTART 394
#define INITIALCONSTRAINTVALUESEND 395
#define CONSTART 396
#define CONEND 397
#define INITIALDUALVALUESSTART 398
#define INITIALDUALVALUESEND 399
#define SOLVEROPTIONSSTART 400
#define SOLVEROPTIONSEND 401
#define SOLVEROPTIONSTART 402
#define SOLVEROPTIONEND 403
#define DUMMY 404




/* Copy the first part of user declarations.  */




#include "OSDataStructures.h"
#include "OSMathUtil.h"
#include "OSParameters.h"
#include "OSConfig.h"
#include "OSErrorClass.h"
#include "OSOption.h"
#include "OSoLParserData.h"
#include <iostream>
#include <sstream>
#include <stdio.h>


typedef struct yy_buffer_state *YY_BUFFER_STATE;
YY_BUFFER_STATE osol_scan_string (const char *yy_str , void* yyscanner  );
int osollex_init(void** ptr_yy_globals);
int osollex_destroy (void* yyscanner );
int osolget_lineno( void* yyscanner);
char *osolget_text (void* yyscanner );
void osolset_lineno (int line_number , void* yyscanner );
void osolset_extra (OSoLParserData* parserData , void* yyscanner );
void  yygetOSOption(const char *ch, OSOption* m_osoption, OSoLParserData *m_parserData ) throw(ErrorClass);




/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE

{
	double dval;
	int ival;
	char* sval;
}
/* Line 193 of yacc.c.  */

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


/* Copy the second part of user declarations.  */



void osolerror(YYLTYPE* type, OSOption *osoption,  OSoLParserData *parserData, const char* errormsg ) ;
int osollex(YYSTYPE* lvalp,  YYLTYPE* llocp, void* scanner);

#define scanner parserData->scanner


/* Line 216 of yacc.c.  */


#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
    YYLTYPE yyls;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   717

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  150
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  480
/* YYNRULES -- Number of rules.  */
#define YYNRULES  711
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1185

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   404

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     8,    11,    13,    16,    22,    23,    26,
      28,    32,    34,    35,    38,    40,    42,    44,    46,    48,
      50,    52,    54,    56,    58,    60,    63,    65,    67,    70,
      71,    76,    79,    81,    83,    86,    87,    92,    95,    97,
      99,   102,   103,   108,   112,   114,   115,   116,   121,   123,
     127,   128,   130,   133,   135,   137,   140,   141,   146,   149,
     151,   153,   156,   157,   162,   165,   167,   169,   172,   173,
     178,   181,   183,   185,   188,   189,   194,   197,   199,   201,
     204,   205,   210,   214,   216,   217,   218,   223,   225,   229,
     230,   232,   237,   239,   244,   247,   248,   251,   252,   257,
     258,   261,   263,   265,   267,   268,   273,   274,   279,   280,
     285,   287,   290,   291,   294,   296,   300,   302,   303,   306,
     308,   310,   312,   314,   316,   320,   322,   323,   324,   329,
     331,   334,   338,   342,   346,   348,   349,   350,   355,   357,
     360,   364,   368,   372,   374,   375,   376,   381,   383,   386,
     390,   394,   397,   399,   401,   404,   405,   410,   415,   417,
     422,   425,   426,   429,   430,   435,   436,   439,   441,   443,
     445,   446,   451,   452,   457,   458,   463,   465,   468,   469,
     472,   474,   478,   480,   481,   484,   486,   488,   491,   493,
     495,   498,   499,   504,   509,   511,   516,   519,   520,   523,
     524,   529,   530,   533,   535,   537,   539,   540,   545,   546,
     551,   552,   557,   559,   562,   565,   567,   571,   573,   574,
     577,   579,   581,   583,   585,   587,   589,   591,   593,   595,
     597,   599,   601,   603,   605,   607,   611,   613,   614,   615,
     620,   622,   625,   629,   633,   636,   638,   640,   643,   644,
     649,   655,   657,   662,   663,   666,   667,   673,   679,   681,
     686,   687,   690,   691,   697,   703,   705,   710,   711,   714,
     715,   721,   727,   729,   734,   735,   738,   739,   745,   751,
     753,   758,   759,   762,   763,   769,   775,   777,   782,   783,
     786,   790,   792,   793,   796,   798,   800,   802,   803,   808,
     809,   814,   815,   820,   823,   825,   831,   833,   838,   839,
     842,   846,   848,   849,   852,   854,   856,   858,   859,   864,
     865,   870,   871,   876,   879,   881,   887,   889,   894,   895,
     898,   902,   904,   905,   908,   910,   912,   914,   915,   920,
     921,   926,   927,   932,   935,   937,   943,   945,   950,   951,
     954,   958,   960,   961,   964,   966,   968,   970,   971,   976,
     977,   982,   983,   988,   991,   993,   999,  1001,  1006,  1007,
    1010,  1011,  1017,  1023,  1025,  1030,  1031,  1034,  1035,  1041,
    1047,  1049,  1054,  1055,  1058,  1059,  1065,  1070,  1072,  1077,
    1080,  1081,  1084,  1085,  1090,  1091,  1094,  1096,  1098,  1100,
    1101,  1106,  1107,  1112,  1113,  1118,  1120,  1123,  1124,  1128,
    1130,  1131,  1134,  1136,  1138,  1140,  1145,  1150,  1155,  1159,
    1161,  1166,  1167,  1171,  1173,  1174,  1179,  1185,  1187,  1188,
    1194,  1199,  1200,  1203,  1207,  1209,  1210,  1213,  1215,  1217,
    1222,  1223,  1228,  1231,  1233,  1234,  1240,  1245,  1246,  1249,
    1253,  1255,  1256,  1259,  1261,  1263,  1268,  1269,  1274,  1277,
    1279,  1280,  1283,  1287,  1289,  1290,  1293,  1295,  1297,  1299,
    1301,  1303,  1305,  1307,  1312,  1313,  1318,  1319,  1324,  1325,
    1330,  1331,  1336,  1337,  1342,  1343,  1348,  1352,  1353,  1356,
    1360,  1362,  1363,  1366,  1368,  1370,  1372,  1374,  1379,  1380,
    1385,  1386,  1391,  1392,  1397,  1400,  1402,  1403,  1407,  1409,
    1410,  1415,  1421,  1423,  1424,  1430,  1435,  1436,  1439,  1443,
    1445,  1446,  1449,  1451,  1453,  1458,  1459,  1464,  1467,  1469,
    1470,  1476,  1481,  1482,  1485,  1489,  1491,  1492,  1495,  1497,
    1499,  1501,  1506,  1507,  1512,  1513,  1518,  1521,  1523,  1524,
    1527,  1531,  1533,  1534,  1537,  1539,  1541,  1543,  1545,  1547,
    1549,  1551,  1556,  1557,  1562,  1563,  1568,  1569,  1574,  1575,
    1580,  1581,  1586,  1587,  1592,  1596,  1597,  1600,  1604,  1606,
    1607,  1610,  1612,  1614,  1616,  1618,  1623,  1624,  1629,  1630,
    1635,  1636,  1641,  1644,  1646,  1647,  1651,  1653,  1654,  1659,
    1665,  1667,  1668,  1674,  1679,  1680,  1683,  1687,  1689,  1690,
    1693,  1695,  1697,  1702,  1703,  1708,  1711,  1713,  1714,  1720,
    1725,  1726,  1729,  1733,  1735,  1736,  1739,  1741,  1743,  1745,
    1750,  1751,  1756,  1757,  1762,  1765,  1767,  1768,  1771,  1775,
    1777,  1778,  1781,  1783,  1785,  1787,  1789,  1791,  1793,  1795,
    1800,  1801,  1806,  1807,  1812,  1813,  1818,  1819,  1824,  1825,
    1830,  1831,  1836,  1840,  1841,  1844,  1848,  1850,  1851,  1854,
    1856,  1858,  1860,  1862,  1867,  1868,  1873,  1874,  1879,  1880,
    1885,  1888,  1890,  1891,  1897,  1899,  1904,  1905,  1908,  1909,
    1914,  1915,  1918,  1920,  1922,  1924,  1926,  1928,  1930,  1931,
    1936,  1937,  1942,  1943,  1948,  1949,  1954,  1955,  1960,  1961,
    1966,  1969
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     151,     0,    -1,   152,     8,   153,    12,    -1,   152,     9,
      -1,    10,    -1,    10,    11,    -1,   154,   219,   259,   284,
     422,    -1,    -1,   155,   156,    -1,    43,    -1,     8,   157,
      44,    -1,     9,    -1,    -1,   157,   158,    -1,   159,    -1,
     163,    -1,   167,    -1,   171,    -1,   177,    -1,   181,    -1,
     185,    -1,   189,    -1,   193,    -1,   197,    -1,   203,    -1,
     160,   161,    -1,    53,    -1,     9,    -1,     8,    54,    -1,
      -1,     8,     4,   162,    54,    -1,   164,   165,    -1,    55,
      -1,     9,    -1,     8,    56,    -1,    -1,     8,     4,   166,
      56,    -1,   168,   169,    -1,    57,    -1,     9,    -1,     8,
      58,    -1,    -1,     8,     4,   170,    58,    -1,   172,   173,
     175,    -1,    59,    -1,    -1,    -1,    13,     3,   174,     7,
      -1,     9,    -1,     8,   176,    60,    -1,    -1,     4,    -1,
     178,   179,    -1,    61,    -1,     9,    -1,     8,    62,    -1,
      -1,     8,     4,   180,    62,    -1,   182,   183,    -1,    63,
      -1,     9,    -1,     8,    64,    -1,    -1,     8,     4,   184,
      64,    -1,   186,   187,    -1,    65,    -1,     9,    -1,     8,
      66,    -1,    -1,     8,     4,   188,    66,    -1,   190,   191,
      -1,    67,    -1,     9,    -1,     8,    68,    -1,    -1,     8,
       4,   192,    68,    -1,   194,   195,    -1,    69,    -1,     9,
      -1,     8,    70,    -1,    -1,     8,     4,   196,    70,    -1,
     198,   199,   201,    -1,    71,    -1,    -1,    -1,    14,     3,
     200,     7,    -1,     9,    -1,     8,   202,    72,    -1,    -1,
       4,    -1,   204,   205,     8,   206,    -1,    73,    -1,    15,
       7,     5,     7,    -1,   207,    74,    -1,    -1,   207,   208,
      -1,    -1,    75,   209,   210,   218,    -1,    -1,   210,   211,
      -1,   212,    -1,   214,    -1,   216,    -1,    -1,    36,     3,
     213,     7,    -1,    -1,    38,     3,   215,     7,    -1,    -1,
      40,     3,   217,     7,    -1,     9,    -1,     8,    76,    -1,
      -1,   220,   221,    -1,    45,    -1,     8,   222,    46,    -1,
       9,    -1,    -1,   222,   223,    -1,   224,    -1,   229,    -1,
     234,    -1,   239,    -1,   243,    -1,   225,   226,   228,    -1,
      77,    -1,    -1,    -1,    39,     3,   227,     7,    -1,     9,
      -1,     8,    78,    -1,     8,     6,    78,    -1,     8,     5,
      78,    -1,   230,   231,   233,    -1,    79,    -1,    -1,    -1,
      39,     3,   232,     7,    -1,     9,    -1,     8,    80,    -1,
       8,     6,    80,    -1,     8,     5,    80,    -1,   235,   236,
     238,    -1,    81,    -1,    -1,    -1,    39,     3,   237,     7,
      -1,     9,    -1,     8,    82,    -1,     8,     6,    82,    -1,
       8,     5,    82,    -1,   240,   241,    -1,    83,    -1,     9,
      -1,     8,    84,    -1,    -1,     8,     5,   242,    84,    -1,
     244,   245,     8,   246,    -1,    73,    -1,    15,     7,     5,
       7,    -1,   247,    74,    -1,    -1,   247,   248,    -1,    -1,
      75,   249,   250,   258,    -1,    -1,   250,   251,    -1,   252,
      -1,   254,    -1,   256,    -1,    -1,    36,     3,   253,     7,
      -1,    -1,    38,     3,   255,     7,    -1,    -1,    40,     3,
     257,     7,    -1,     9,    -1,     8,    76,    -1,    -1,   260,
     261,    -1,    47,    -1,     8,   262,    48,    -1,     9,    -1,
      -1,   262,   263,    -1,   264,    -1,   268,    -1,   265,   266,
      -1,    85,    -1,     9,    -1,     8,    86,    -1,    -1,     8,
       4,   267,    86,    -1,   269,   270,     8,   271,    -1,    73,
      -1,    15,     7,     5,     7,    -1,   272,    74,    -1,    -1,
     272,   273,    -1,    -1,    75,   274,   275,   283,    -1,    -1,
     275,   276,    -1,   277,    -1,   279,    -1,   281,    -1,    -1,
      36,     3,   278,     7,    -1,    -1,    38,     3,   280,     7,
      -1,    -1,    40,     3,   282,     7,    -1,     9,    -1,     8,
      76,    -1,   285,   286,    -1,    49,    -1,     8,   287,    50,
      -1,     9,    -1,    -1,   287,   288,    -1,   289,    -1,   294,
      -1,   298,    -1,   304,    -1,   310,    -1,   316,    -1,   322,
      -1,   328,    -1,   343,    -1,   358,    -1,   373,    -1,   388,
      -1,   394,    -1,   400,    -1,   406,    -1,   290,   291,   293,
      -1,    87,    -1,    -1,    -1,    39,     3,   292,     7,    -1,
       9,    -1,     8,    88,    -1,     8,     6,    88,    -1,     8,
       5,    88,    -1,   295,   296,    -1,    89,    -1,     9,    -1,
       8,    90,    -1,    -1,     8,     4,   297,    90,    -1,   299,
     300,     8,   301,    92,    -1,    91,    -1,    16,     7,     5,
       7,    -1,    -1,   301,   302,    -1,    -1,    61,     8,     4,
     303,    62,    -1,   305,   306,     8,   307,    94,    -1,    93,
      -1,    17,     7,     5,     7,    -1,    -1,   307,   308,    -1,
      -1,    97,     8,     4,   309,    98,    -1,   311,   312,     8,
     313,    96,    -1,    95,    -1,    17,     7,     5,     7,    -1,
      -1,   313,   314,    -1,    -1,    97,     8,     4,   315,    98,
      -1,   317,   318,     8,   319,   102,    -1,   101,    -1,    17,
       7,     5,     7,    -1,    -1,   319,   320,    -1,    -1,    97,
       8,     4,   321,    98,    -1,   323,   324,     8,   325,   104,
      -1,   103,    -1,    17,     7,     5,     7,    -1,    -1,   325,
     326,    -1,    -1,    97,     8,     4,   327,    98,    -1,   329,
     330,     8,   331,   110,    -1,   109,    -1,    18,     7,     5,
       7,    -1,    -1,   331,   332,    -1,   333,   334,   342,    -1,
      99,    -1,    -1,   334,   335,    -1,   336,    -1,   338,    -1,
     340,    -1,    -1,    19,     3,   337,     7,    -1,    -1,    20,
       3,   339,     7,    -1,    -1,    21,     3,   341,     7,    -1,
       8,   100,    -1,     9,    -1,   344,   345,     8,   346,   112,
      -1,   111,    -1,    18,     7,     5,     7,    -1,    -1,   346,
     347,    -1,   348,   349,   357,    -1,    99,    -1,    -1,   349,
     350,    -1,   351,    -1,   353,    -1,   355,    -1,    -1,    19,
       3,   352,     7,    -1,    -1,    20,     3,   354,     7,    -1,
      -1,    21,     3,   356,     7,    -1,     8,   100,    -1,     9,
      -1,   359,   360,     8,   361,   114,    -1,   113,    -1,    18,
       7,     5,     7,    -1,    -1,   361,   362,    -1,   363,   364,
     372,    -1,    99,    -1,    -1,   364,   365,    -1,   366,    -1,
     368,    -1,   370,    -1,    -1,    19,     3,   367,     7,    -1,
      -1,    20,     3,   369,     7,    -1,    -1,    21,     3,   371,
       7,    -1,     8,   100,    -1,     9,    -1,   374,   375,     8,
     376,   116,    -1,   115,    -1,    18,     7,     5,     7,    -1,
      -1,   376,   377,    -1,   378,   379,   387,    -1,    99,    -1,
      -1,   379,   380,    -1,   381,    -1,   383,    -1,   385,    -1,
      -1,    19,     3,   382,     7,    -1,    -1,    20,     3,   384,
       7,    -1,    -1,    21,     3,   386,     7,    -1,     8,   100,
      -1,     9,    -1,   389,   390,     8,   391,   108,    -1,   107,
      -1,    17,     7,     5,     7,    -1,    -1,   391,   392,    -1,
      -1,    97,     8,     4,   393,    98,    -1,   395,   396,     8,
     397,   106,    -1,   105,    -1,    17,     7,     5,     7,    -1,
      -1,   397,   398,    -1,    -1,    97,     8,     4,   399,    98,
      -1,   401,   402,     8,   403,   118,    -1,   117,    -1,    25,
       7,     5,     7,    -1,    -1,   403,   404,    -1,    -1,   119,
       8,     4,   405,   120,    -1,   407,   408,     8,   409,    -1,
      73,    -1,    15,     7,     5,     7,    -1,   410,    74,    -1,
      -1,   410,   411,    -1,    -1,    75,   412,   413,   421,    -1,
      -1,   413,   414,    -1,   415,    -1,   417,    -1,   419,    -1,
      -1,    36,     3,   416,     7,    -1,    -1,    38,     3,   418,
       7,    -1,    -1,    40,     3,   420,     7,    -1,     9,    -1,
       8,    76,    -1,    -1,   423,   424,   429,    -1,    51,    -1,
      -1,   424,   425,    -1,   426,    -1,   427,    -1,   428,    -1,
      27,     7,     5,     7,    -1,    29,     7,     5,     7,    -1,
      28,     7,     5,     7,    -1,     8,   430,    52,    -1,     9,
      -1,   431,   489,   549,   609,    -1,    -1,   432,   433,   434,
      -1,   121,    -1,    -1,    30,     7,     5,     7,    -1,     8,
     435,   446,   457,   122,    -1,     9,    -1,    -1,   123,   436,
       8,   437,   124,    -1,    33,     7,     5,     7,    -1,    -1,
     437,   438,    -1,   439,   440,   445,    -1,   125,    -1,    -1,
     440,   441,    -1,   442,    -1,   443,    -1,    37,     7,     5,
       7,    -1,    -1,    38,     3,   444,     7,    -1,     8,   126,
      -1,     9,    -1,    -1,   127,   447,     8,   448,   128,    -1,
      33,     7,     5,     7,    -1,    -1,   448,   449,    -1,   450,
     451,   456,    -1,   125,    -1,    -1,   451,   452,    -1,   453,
      -1,   454,    -1,    37,     7,     5,     7,    -1,    -1,    38,
       3,   455,     7,    -1,     8,   126,    -1,     9,    -1,    -1,
     457,   458,    -1,   459,   460,   475,    -1,    75,    -1,    -1,
     460,   461,    -1,   462,    -1,   463,    -1,   465,    -1,   467,
      -1,   469,    -1,   471,    -1,   473,    -1,    33,     7,     5,
       7,    -1,    -1,    36,     3,   464,     7,    -1,    -1,    38,
       3,   466,     7,    -1,    -1,    22,     3,   468,     7,    -1,
      -1,    23,     3,   470,     7,    -1,    -1,    24,     3,   472,
       7,    -1,    -1,    40,     3,   474,     7,    -1,     8,   476,
      76,    -1,    -1,   476,   477,    -1,   478,   479,   488,    -1,
     125,    -1,    -1,   479,   480,    -1,   481,    -1,   482,    -1,
     484,    -1,   486,    -1,    37,     7,     5,     7,    -1,    -1,
      38,     3,   483,     7,    -1,    -1,    41,     3,   485,     7,
      -1,    -1,    42,     3,   487,     7,    -1,     8,   126,    -1,
       9,    -1,    -1,   490,   491,   492,    -1,   129,    -1,    -1,
      31,     7,     5,     7,    -1,     8,   493,   504,   517,   130,
      -1,     9,    -1,    -1,   131,   494,     8,   495,   132,    -1,
      34,     7,     5,     7,    -1,    -1,   495,   496,    -1,   497,
     498,   503,    -1,   133,    -1,    -1,   498,   499,    -1,   500,
      -1,   501,    -1,    37,     7,     5,     7,    -1,    -1,    38,
       3,   502,     7,    -1,     8,   134,    -1,     9,    -1,    -1,
     135,   505,     8,   506,   136,    -1,    34,     7,     5,     7,
      -1,    -1,   506,   507,    -1,   508,   509,   516,    -1,   133,
      -1,    -1,   509,   510,    -1,   511,    -1,   512,    -1,   514,
      -1,    37,     7,     5,     7,    -1,    -1,    41,     3,   513,
       7,    -1,    -1,    42,     3,   515,     7,    -1,     8,   134,
      -1,     9,    -1,    -1,   517,   518,    -1,   519,   520,   535,
      -1,    75,    -1,    -1,   520,   521,    -1,   522,    -1,   523,
      -1,   525,    -1,   527,    -1,   529,    -1,   531,    -1,   533,
      -1,    34,     7,     5,     7,    -1,    -1,    36,     3,   524,
       7,    -1,    -1,    38,     3,   526,     7,    -1,    -1,    22,
       3,   528,     7,    -1,    -1,    23,     3,   530,     7,    -1,
      -1,    24,     3,   532,     7,    -1,    -1,    40,     3,   534,
       7,    -1,     8,   536,    76,    -1,    -1,   536,   537,    -1,
     538,   539,   548,    -1,   133,    -1,    -1,   539,   540,    -1,
     541,    -1,   542,    -1,   544,    -1,   546,    -1,    37,     7,
       5,     7,    -1,    -1,    38,     3,   543,     7,    -1,    -1,
      41,     3,   545,     7,    -1,    -1,    42,     3,   547,     7,
      -1,     8,   126,    -1,     9,    -1,    -1,   550,   551,   552,
      -1,   137,    -1,    -1,    32,     7,     5,     7,    -1,     8,
     553,   564,   577,   138,    -1,     9,    -1,    -1,   139,   554,
       8,   555,   140,    -1,    35,     7,     5,     7,    -1,    -1,
     555,   556,    -1,   557,   558,   563,    -1,   141,    -1,    -1,
     558,   559,    -1,   560,    -1,   561,    -1,    37,     7,     5,
       7,    -1,    -1,    38,     3,   562,     7,    -1,     8,   142,
      -1,     9,    -1,    -1,   143,   565,     8,   566,   144,    -1,
      35,     7,     5,     7,    -1,    -1,   566,   567,    -1,   568,
     569,   576,    -1,   141,    -1,    -1,   569,   570,    -1,   571,
      -1,   572,    -1,   574,    -1,    37,     7,     5,     7,    -1,
      -1,    41,     3,   573,     7,    -1,    -1,    42,     3,   575,
       7,    -1,     8,   142,    -1,     9,    -1,    -1,   577,   578,
      -1,   579,   580,   595,    -1,    75,    -1,    -1,   580,   581,
      -1,   582,    -1,   583,    -1,   585,    -1,   587,    -1,   589,
      -1,   591,    -1,   593,    -1,    35,     7,     5,     7,    -1,
      -1,    36,     3,   584,     7,    -1,    -1,    38,     3,   586,
       7,    -1,    -1,    22,     3,   588,     7,    -1,    -1,    23,
       3,   590,     7,    -1,    -1,    24,     3,   592,     7,    -1,
      -1,    40,     3,   594,     7,    -1,     8,   596,    76,    -1,
      -1,   596,   597,    -1,   598,   599,   608,    -1,   141,    -1,
      -1,   599,   600,    -1,   601,    -1,   602,    -1,   604,    -1,
     606,    -1,    37,     7,     5,     7,    -1,    -1,    38,     3,
     603,     7,    -1,    -1,    41,     3,   605,     7,    -1,    -1,
      42,     3,   607,     7,    -1,     8,   142,    -1,     9,    -1,
      -1,   610,   611,     8,   612,   146,    -1,   145,    -1,    26,
       7,     5,     7,    -1,    -1,   612,   613,    -1,    -1,   147,
     614,   615,   629,    -1,    -1,   615,   616,    -1,   617,    -1,
     619,    -1,   621,    -1,   623,    -1,   625,    -1,   627,    -1,
      -1,    36,     3,   618,     7,    -1,    -1,    38,     3,   620,
       7,    -1,    -1,    22,     3,   622,     7,    -1,    -1,    23,
       3,   624,     7,    -1,    -1,    24,     3,   626,     7,    -1,
      -1,    40,     3,   628,     7,    -1,     8,   148,    -1,     9,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   128,   128,   129,   131,   132,   134,   136,   136,   138,
     149,   150,   152,   152,   154,   154,   154,   154,   154,   155,
     155,   155,   155,   155,   155,   158,   160,   169,   170,   171,
     171,   174,   176,   185,   186,   187,   187,   190,   192,   201,
     202,   203,   203,   206,   208,   219,   220,   219,   227,   228,
     230,   230,   233,   235,   244,   245,   246,   246,   249,   251,
     260,   261,   262,   262,   265,   267,   276,   277,   278,   278,
     281,   283,   292,   293,   294,   294,   297,   299,   308,   309,
     310,   310,   313,   315,   326,   327,   326,   335,   336,   338,
     338,   341,   343,   353,   361,   366,   366,   369,   368,   384,
     384,   386,   386,   386,   389,   388,   400,   399,   411,   410,
     421,   421,   424,   424,   426,   437,   438,   440,   440,   442,
     442,   442,   442,   442,   444,   446,   457,   458,   457,   466,
     467,   468,   473,   480,   482,   493,   494,   493,   502,   503,
     504,   509,   517,   519,   530,   531,   530,   541,   542,   543,
     548,   556,   558,   567,   568,   570,   569,   577,   579,   589,
     597,   602,   602,   605,   604,   619,   619,   621,   621,   621,
     624,   623,   635,   634,   647,   646,   657,   657,   660,   660,
     662,   673,   674,   676,   676,   678,   678,   680,   682,   692,
     693,   695,   694,   704,   706,   716,   724,   729,   729,   732,
     731,   746,   746,   748,   748,   748,   751,   750,   762,   761,
     773,   772,   783,   783,   786,   788,   798,   799,   801,   801,
     803,   803,   803,   803,   803,   804,   804,   804,   804,   804,
     805,   805,   805,   805,   805,   808,   810,   821,   822,   821,
     831,   832,   833,   838,   845,   847,   857,   858,   859,   859,
     861,   863,   873,   880,   880,   883,   882,   895,   898,   908,
     915,   915,   917,   917,   929,   932,   942,   949,   949,   951,
     951,   963,   966,   975,   982,   982,   985,   984,   996,   999,
    1009,  1016,  1016,  1019,  1018,  1030,  1033,  1043,  1052,  1052,
    1054,  1066,  1072,  1072,  1074,  1074,  1074,  1077,  1076,  1088,
    1087,  1099,  1098,  1110,  1110,  1113,  1116,  1126,  1134,  1134,
    1136,  1148,  1154,  1154,  1156,  1156,  1156,  1159,  1158,  1170,
    1169,  1181,  1180,  1192,  1192,  1195,  1198,  1208,  1217,  1217,
    1219,  1231,  1237,  1237,  1239,  1239,  1239,  1242,  1241,  1253,
    1252,  1264,  1263,  1275,  1275,  1278,  1281,  1291,  1299,  1299,
    1301,  1313,  1319,  1319,  1321,  1321,  1321,  1324,  1323,  1335,
    1334,  1346,  1345,  1357,  1357,  1360,  1363,  1373,  1380,  1380,
    1383,  1382,  1394,  1397,  1407,  1414,  1414,  1417,  1416,  1428,
    1432,  1442,  1449,  1449,  1452,  1451,  1463,  1465,  1475,  1483,
    1488,  1488,  1491,  1490,  1505,  1505,  1507,  1507,  1507,  1510,
    1509,  1521,  1520,  1532,  1531,  1542,  1542,  1545,  1545,  1547,
    1557,  1557,  1559,  1559,  1559,  1561,  1567,  1573,  1579,  1579,
    1581,  1583,  1583,  1585,  1589,  1589,  1598,  1599,  1601,  1601,
    1603,  1613,  1613,  1615,  1623,  1628,  1628,  1630,  1630,  1632,
    1646,  1645,  1658,  1658,  1661,  1661,  1664,  1674,  1674,  1676,
    1684,  1689,  1689,  1691,  1691,  1693,  1707,  1706,  1714,  1714,
    1719,  1719,  1721,  1723,  1728,  1728,  1731,  1732,  1733,  1734,
    1735,  1736,  1737,  1739,  1753,  1752,  1761,  1760,  1769,  1768,
    1777,  1776,  1785,  1784,  1793,  1792,  1801,  1818,  1818,  1820,
    1830,  1835,  1835,  1838,  1839,  1840,  1841,  1843,  1857,  1856,
    1865,  1864,  1873,  1872,  1880,  1880,  1884,  1884,  1886,  1890,
    1890,  1899,  1900,  1902,  1902,  1905,  1915,  1915,  1917,  1925,
    1930,  1930,  1932,  1932,  1934,  1949,  1948,  1961,  1961,  1964,
    1964,  1967,  1977,  1977,  1979,  1988,  1993,  1993,  1995,  1995,
    1995,  1997,  2011,  2010,  2024,  2023,  2036,  2036,  2040,  2040,
    2042,  2044,  2049,  2049,  2052,  2053,  2054,  2055,  2056,  2057,
    2058,  2060,  2074,  2073,  2083,  2082,  2092,  2091,  2101,  2100,
    2110,  2109,  2119,  2118,  2128,  2145,  2145,  2147,  2157,  2162,
    2162,  2165,  2166,  2167,  2168,  2170,  2185,  2184,  2194,  2193,
    2203,  2202,  2211,  2211,  2214,  2214,  2216,  2220,  2220,  2229,
    2231,  2233,  2233,  2236,  2246,  2246,  2248,  2256,  2261,  2261,
    2263,  2263,  2265,  2280,  2279,  2292,  2292,  2295,  2295,  2298,
    2308,  2308,  2310,  2319,  2324,  2324,  2326,  2326,  2326,  2328,
    2342,  2341,  2355,  2354,  2368,  2368,  2371,  2371,  2373,  2375,
    2380,  2380,  2383,  2384,  2385,  2386,  2387,  2388,  2389,  2391,
    2405,  2404,  2413,  2412,  2421,  2420,  2429,  2428,  2437,  2436,
    2445,  2444,  2453,  2470,  2470,  2472,  2482,  2487,  2487,  2490,
    2491,  2492,  2493,  2495,  2510,  2509,  2519,  2518,  2527,  2526,
    2534,  2534,  2537,  2537,  2542,  2552,  2560,  2560,  2563,  2562,
    2580,  2580,  2583,  2584,  2585,  2586,  2587,  2588,  2592,  2591,
    2603,  2602,  2614,  2613,  2625,  2624,  2636,  2635,  2647,  2646,
    2658,  2658
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ATTRIBUTETEXT", "ELEMENTTEXT",
  "INTEGER", "DOUBLE", "QUOTE", "GREATERTHAN", "ENDOFELEMENT", "OSOLSTART",
  "OSOLATTRIBUTETEXT", "OSOLEND", "LOCATIONTYPEATT", "TRANSPORTTYPEATT",
  "NUMBEROFOTHEROPTIONSATT", "NUMBEROFJOBIDSATT", "NUMBEROFPATHSATT",
  "NUMBEROFPATHPAIRSATT", "FROMATT", "TOATT", "MAKECOPYATT", "SOLVERATT",
  "CATEGORYATT", "TYPEATT", "NUMBEROFPROCESSESATT",
  "NUMBEROFSOLVEROPTIONSATT", "NUMBEROFVARIABLESATT",
  "NUMBEROFOBJECTIVESATT", "NUMBEROFCONSTRAINTSATT",
  "NUMBEROFOTHERVARIABLEOPTIONSATT", "NUMBEROFOTHEROBJECTIVEOPTIONSATT",
  "NUMBEROFOTHERCONSTRAINTOPTIONSATT", "NUMBEROFVARATT", "NUMBEROFOBJATT",
  "NUMBEROFCONATT", "NAMEATT", "IDXATT", "VALUEATT", "UNITATT",
  "DESCRIPTIONATT", "LBVALUEATT", "UBVALUEATT", "GENERALSTART",
  "GENERALEND", "SYSTEMSTART", "SYSTEMEND", "SERVICESTART", "SERVICEEND",
  "JOBSTART", "JOBEND", "OPTIMIZATIONSTART", "OPTIMIZATIONEND",
  "SERVICEURISTART", "SERVICEURIEND", "SERVICENAMESTART", "SERVICENAMEEND",
  "INSTANCENAMESTART", "INSTANCENAMEEND", "INSTANCELOCATIONSTART",
  "INSTANCELOCATIONEND", "JOBIDSTART", "JOBIDEND", "SOLVERTOINVOKESTART",
  "SOLVERTOINVOKEEND", "LICENSESTART", "LICENSEEND", "USERNAMESTART",
  "USERNAMEEND", "PASSWORDSTART", "PASSWORDEND", "CONTACTSTART",
  "CONTACTEND", "OTHEROPTIONSSTART", "OTHEROPTIONSEND", "OTHERSTART",
  "OTHEREND", "MINDISKSPACESTART", "MINDISKSPACEEND", "MINMEMORYSIZESTART",
  "MINMEMORYSIZEEND", "MINCPUSPEEDSTART", "MINCPUSPEEDEND",
  "MINCPUNUMBERSTART", "MINCPUNUMBEREND", "SERVICETYPESTART",
  "SERVICETYPEEND", "MAXTIMESTART", "MAXTIMEEND",
  "SCHEDULEDSTARTTIMESTART", "SCHEDULEDSTARTTIMEEND", "DEPENDENCIESSTART",
  "DEPENDENCIESEND", "REQUIREDDIRECTORIESSTART", "REQUIREDDIRECTORIESEND",
  "REQUIREDFILESSTART", "REQUIREDFILESEND", "PATHSTART", "PATHEND",
  "PATHPAIRSTART", "PATHPAIREND", "DIRECTORIESTOMAKESTART",
  "DIRECTORIESTOMAKEEND", "FILESTOCREATESTART", "FILESTOCREATEEND",
  "DIRECTORIESTODELETESTART", "DIRECTORIESTODELETEEND",
  "FILESTODELETESTART", "FILESTODELETEEND", "INPUTDIRECTORIESTOMOVESTART",
  "INPUTDIRECTORIESTOMOVEEND", "INPUTFILESTOMOVESTART",
  "INPUTFILESTOMOVEEND", "OUTPUTDIRECTORIESTOMOVESTART",
  "OUTPUTDIRECTORIESTOMOVEEND", "OUTPUTFILESTOMOVESTART",
  "OUTPUTFILESTOMOVEEND", "PROCESSESTOKILLSTART", "PROCESSESTOKILLEND",
  "PROCESSSTART", "PROCESSEND", "VARIABLESSTART", "VARIABLESEND",
  "INITIALVARIABLEVALUESSTART", "INITIALVARIABLEVALUESEND", "VARSTART",
  "VAREND", "INITIALVARIABLEVALUESSTRINGSTART",
  "INITIALVARIABLEVALUESSTRINGEND", "OBJECTIVESSTART", "OBJECTIVESEND",
  "INITIALOBJECTIVEVALUESSTART", "INITIALOBJECTIVEVALUESEND", "OBJSTART",
  "OBJEND", "INITIALOBJECTIVEBOUNDSSTART", "INITIALOBJECTIVEBOUNDSEND",
  "CONSTRAINTSSTART", "CONSTRAINTSEND", "INITIALCONSTRAINTVALUESSTART",
  "INITIALCONSTRAINTVALUESEND", "CONSTART", "CONEND",
  "INITIALDUALVALUESSTART", "INITIALDUALVALUESEND", "SOLVEROPTIONSSTART",
  "SOLVEROPTIONSEND", "SOLVEROPTIONSTART", "SOLVEROPTIONEND", "DUMMY",
  "$accept", "osoldoc", "osolstart", "osolcontent", "osolgeneral",
  "generalhead", "generalbody", "generalcontent", "generaloption",
  "serviceURI", "serviceURIhead", "serviceURIbody", "@1", "servicename",
  "servicenamehead", "servicenamebody", "@2", "instancename",
  "instancenamehead", "instancenamebody", "@3", "instancelocation",
  "instancelocationhead", "locationtypeatt", "@4", "instancelocationbody",
  "instancelocationtext", "jobid", "jobidhead", "jobidbody", "@5",
  "solvertoinvoke", "solvertoinvokehead", "solvertoinvokebody", "@6",
  "license", "licensehead", "licensebody", "@7", "username",
  "usernamehead", "usernamebody", "@8", "password", "passwordhead",
  "passwordbody", "@9", "contact", "contacthead", "transporttypeatt",
  "@10", "contactbody", "contacttext", "othergeneraloptions",
  "othergeneraloptionshead", "numberofothergeneraloptions",
  "othergeneraloptionsbody", "othergeneraloptionslist",
  "othergeneraloption", "@11", "othergeneralattributes",
  "othergeneralattribute", "generaloptionnameatt", "@12",
  "generaloptionvalueatt", "@13", "generaloptiondescriptionatt", "@14",
  "othergeneraloptionend", "osolsystem", "systemhead", "systembody",
  "systemcontent", "systemoption", "mindiskspace", "mindiskspacehead",
  "mindiskspaceunit", "@15", "mindiskspacebody", "minmemorysize",
  "minmemorysizehead", "minmemoryunit", "@16", "minmemorysizebody",
  "mincpuspeed", "mincpuspeedhead", "mincpuspeedunit", "@17",
  "mincpuspeedbody", "mincpunumber", "mincpunumberhead",
  "mincpunumberbody", "@18", "othersystemoptions",
  "othersystemoptionshead", "numberofothersystemoptions",
  "othersystemoptionsbody", "othersystemoptionslist", "othersystemoption",
  "@19", "othersystemattributes", "othersystemattribute",
  "systemoptionnameatt", "@20", "systemoptionvalueatt", "@21",
  "systemoptiondescriptionatt", "@22", "othersystemoptionend",
  "osolservice", "servicehead", "servicebody", "servicecontent",
  "serviceoption", "servicetype", "servicetypehead", "servicetypebody",
  "@23", "otherserviceoptions", "otherserviceoptionshead",
  "numberofotherserviceoptions", "otherserviceoptionsbody",
  "otherserviceoptionslist", "otherserviceoption", "@24",
  "otherserviceattributes", "otherserviceattribute",
  "serviceoptionnameatt", "@25", "serviceoptionvalueatt", "@26",
  "serviceoptiondescriptionatt", "@27", "otherserviceoptionsend",
  "osoljob", "jobhead", "jobbody", "jobcontent", "joboption", "maxtime",
  "maxtimehead", "maxtimeunit", "@28", "maxtimebody", "scheduledstarttime",
  "starttimehead", "starttimebody", "@29", "dependencies",
  "dependencieshead", "numberofjobidsatt", "dependencieslist",
  "dependencyjobid", "@30", "requireddirectories",
  "requireddirectorieshead", "numberofreqdirpathsatt", "reqdirpathlist",
  "reqdirpath", "@31", "requiredfiles", "requiredfileshead",
  "numberofreqfilespathsatt", "reqfilespathlist", "reqfilepath", "@32",
  "directoriestomake", "directoriestomakehead",
  "numberofdirtomakepathsatt", "dirtomakepathlist", "dirtomakepath", "@33",
  "filestocreate", "filestocreatehead", "numberoffilestomakepathsatt",
  "filestomakepathlist", "filestomakepath", "@34",
  "inputdirectoriestomove", "inputdirectoriestomovehead",
  "numberofindirtomovepathpairsatt", "indirtomovepathpairlist",
  "indirtomovepathpair", "indirtomovepathpairhead",
  "indirtomovepathpairattlist", "indirtomovepathpairatt",
  "indirtomovefromatt", "@35", "indirtomovetoatt", "@36",
  "indirtomovemakecopyatt", "@37", "indirtomovepathpairend",
  "inputfilestomove", "inputfilestomovehead",
  "numberofinfilestomovepathpairsatt", "infilestomovepathpairlist",
  "infilestomovepathpair", "infilestomovepathpairhead",
  "infilestomovepathpairattlist", "infilestomovepathpairatt",
  "infilestomovefromatt", "@38", "infilestomovetoatt", "@39",
  "infilestomovemakecopyatt", "@40", "infilestomovepathpairend",
  "outputdirectoriestomove", "outputdirectoriestomovehead",
  "numberofoutdirtomovepathpairsatt", "outdirtomovepathpairlist",
  "outdirtomovepathpair", "outdirtomovepathpairhead",
  "outdirtomovepathpairattlist", "outdirtomovepathpairatt",
  "outdirtomovefromatt", "@41", "outdirtomovetoatt", "@42",
  "outdirtomovemakecopyatt", "@43", "outdirtomovepathpairend",
  "outputfilestomove", "outputfilestomovehead",
  "numberofoutfilestomovepathpairsatt", "outfilestomovepathpairlist",
  "outfilestomovepathpair", "outfilestomovepathpairhead",
  "outfilestomovepathpairattlist", "outfilestomovepathpairatt",
  "outfilestomovefromatt", "@44", "outfilestomovetoatt", "@45",
  "outfilestomovemakecopyatt", "@46", "outfilestomovepathpairend",
  "filestodelete", "filestodeletehead", "numberoffilestodeletepathsatt",
  "filestodeletepathlist", "filestodeletepath", "@47",
  "directoriestodelete", "directoriestodeletehead",
  "numberofdirtodeletepathsatt", "dirtodeletepathlist", "dirtodeletepath",
  "@48", "processestokill", "processestokillhead",
  "numberofprocesstokillatt", "processestokilllist", "processtokill",
  "@49", "otherjoboptions", "otherjoboptionshead",
  "numberofotherjoboptions", "otherjoboptionsbody", "otherjoboptionslist",
  "otherjoboption", "@50", "otherjobattributes", "otherjobattribute",
  "joboptionnameatt", "@51", "joboptionvalueatt", "@52",
  "joboptiondescriptionatt", "@53", "otherjoboptionsend",
  "osoloptimization", "optimizationhead", "optimizationattlist",
  "optimizationatt", "optimizationnvar", "optimizationncon",
  "optimizationnobj", "optimizationbody", "optimizationcontent",
  "variables", "variablesstart", "numberofothervariablesatt",
  "restofvariables", "initialvariablevalues", "numberofvar", "varlist",
  "initvarvalue", "varstart", "initvarvalueattlist", "initvarvalueatt",
  "initvarvalueidxatt", "initvarvaluevalueatt", "@54", "initvarvalueend",
  "initialvariablevaluesstring", "numberofvarstr", "varstrlist",
  "initvarstrvalue", "varstrstart", "initvarstrvalueattlist",
  "initvarstrvalueatt", "initvarstrvalueidxatt", "initvarstrvaluevalueatt",
  "@55", "initvarstrvalueend", "othervariableoptionlist",
  "othervariableoption", "othervariableoptionstart",
  "othervariableoptionsattlist", "othervariableoptionsatt",
  "othervariableoptionnumberofvar", "othervariableoptionname", "@56",
  "othervariableoptionvalue", "@57", "othervariableoptionsolver", "@58",
  "othervariableoptioncategory", "@59", "othervariableoptiontype", "@60",
  "othervariableoptiondescription", "@61", "restofothervariableoption",
  "othervariableoptionsvarlist", "othervariableoptionsvar",
  "othervariableoptionsvarstart", "othervaroptionattlist",
  "othervaroptionatt", "othervaroptionidx", "othervaroptionvalue", "@62",
  "othervaroptionlbvalue", "@63", "othervaroptionubvalue", "@64",
  "othervaroptionend", "objectives", "objectivesstart",
  "numberofotherobjectivesatt", "restofobjectives",
  "initialobjectivevalues", "numberofobjval", "objvaluelist",
  "initobjvalue", "objvaluestart", "initobjvalueattlist",
  "initobjvalueatt", "initobjvalueidxatt", "initobjvaluevalueatt", "@65",
  "initobjvalueend", "initialobjectivebounds", "numberofobjbounds",
  "objboundlist", "initobjbound", "objboundstart", "initobjboundattlist",
  "initobjboundatt", "initobjboundidxatt", "initobjvaluelowerboundatt",
  "@66", "initobjvalueupperboundatt", "@67", "initobjboundend",
  "otherobjectiveoptionlist", "otherobjectiveoption",
  "otherobjectiveoptionstart", "otherobjectiveoptionsattlist",
  "otherobjectiveoptionsatt", "otherobjectiveoptionnumberofvar",
  "otherobjectiveoptionname", "@68", "otherobjectiveoptionvalue", "@69",
  "otherobjectiveoptionsolver", "@70", "otherobjectiveoptioncategory",
  "@71", "otherobjectiveoptiontype", "@72",
  "otherobjectiveoptiondescription", "@73", "restofotherobjectiveoption",
  "otherobjectiveoptionsvarlist", "otherobjectiveoptionsvar",
  "otherobjectiveoptionsvarstart", "otherobjoptionattlist",
  "otherobjoptionatt", "otherobjoptionidx", "otherobjoptionvalue", "@74",
  "otherobjoptionlbvalue", "@75", "otherobjoptionubvalue", "@76",
  "otherobjoptionend", "constraints", "constraintsstart",
  "numberofotherconstraintsatt", "restofconstraints",
  "initialconstraintvalues", "numberofconval", "conlist", "initconvalue",
  "constart", "initconvalueattlist", "initconvalueatt",
  "initconvalueidxatt", "initconvaluevalueatt", "@77", "initconvalueend",
  "initialdualvalues", "numberofduals", "duallist", "initdualvalue",
  "dualstart", "initdualvalueattlist", "initdualvalueatt",
  "initdualvalueidxatt", "initdualvaluelowerboundatt", "@78",
  "initdualvalueupperboundatt", "@79", "initdualvalueend",
  "otherconstraintoptionlist", "otherconstraintoption",
  "otherconstraintoptionstart", "otherconstraintoptionsattlist",
  "otherconstraintoptionsatt", "otherconstraintoptionnumberofvar",
  "otherconstraintoptionname", "@80", "otherconstraintoptionvalue", "@81",
  "otherconstraintoptionsolver", "@82", "otherconstraintoptioncategory",
  "@83", "otherconstraintoptiontype", "@84",
  "otherconstraintoptiondescription", "@85", "restofotherconstraintoption",
  "otherconstraintoptionsvarlist", "otherconstraintoptionsvar",
  "otherconstraintoptionsvarstart", "otherconoptionattlist",
  "otherconoptionatt", "otherconoptionidx", "otherconoptionvalue", "@86",
  "otherconoptionlbvalue", "@87", "otherconoptionubvalue", "@88",
  "otherconoptionend", "solveroptions", "solveroptionsstart",
  "numberofsolveroptionsatt", "solveroptionlist", "solveroption", "@89",
  "solveroptionattlist", "solveroptionatt", "solveroptionname", "@90",
  "solveroptionvalue", "@91", "solveroptionsolver", "@92",
  "solveroptioncategory", "@93", "solveroptiontype", "@94",
  "solveroptiondescription", "@95", "solveroptionend", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   150,   151,   151,   152,   152,   153,   154,   154,   155,
     156,   156,   157,   157,   158,   158,   158,   158,   158,   158,
     158,   158,   158,   158,   158,   159,   160,   161,   161,   162,
     161,   163,   164,   165,   165,   166,   165,   167,   168,   169,
     169,   170,   169,   171,   172,   173,   174,   173,   175,   175,
     176,   176,   177,   178,   179,   179,   180,   179,   181,   182,
     183,   183,   184,   183,   185,   186,   187,   187,   188,   187,
     189,   190,   191,   191,   192,   191,   193,   194,   195,   195,
     196,   195,   197,   198,   199,   200,   199,   201,   201,   202,
     202,   203,   204,   205,   206,   207,   207,   209,   208,   210,
     210,   211,   211,   211,   213,   212,   215,   214,   217,   216,
     218,   218,   219,   219,   220,   221,   221,   222,   222,   223,
     223,   223,   223,   223,   224,   225,   226,   227,   226,   228,
     228,   228,   228,   229,   230,   231,   232,   231,   233,   233,
     233,   233,   234,   235,   236,   237,   236,   238,   238,   238,
     238,   239,   240,   241,   241,   242,   241,   243,   244,   245,
     246,   247,   247,   249,   248,   250,   250,   251,   251,   251,
     253,   252,   255,   254,   257,   256,   258,   258,   259,   259,
     260,   261,   261,   262,   262,   263,   263,   264,   265,   266,
     266,   267,   266,   268,   269,   270,   271,   272,   272,   274,
     273,   275,   275,   276,   276,   276,   278,   277,   280,   279,
     282,   281,   283,   283,   284,   285,   286,   286,   287,   287,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   289,   290,   291,   292,   291,
     293,   293,   293,   293,   294,   295,   296,   296,   297,   296,
     298,   299,   300,   301,   301,   303,   302,   304,   305,   306,
     307,   307,   309,   308,   310,   311,   312,   313,   313,   315,
     314,   316,   317,   318,   319,   319,   321,   320,   322,   323,
     324,   325,   325,   327,   326,   328,   329,   330,   331,   331,
     332,   333,   334,   334,   335,   335,   335,   337,   336,   339,
     338,   341,   340,   342,   342,   343,   344,   345,   346,   346,
     347,   348,   349,   349,   350,   350,   350,   352,   351,   354,
     353,   356,   355,   357,   357,   358,   359,   360,   361,   361,
     362,   363,   364,   364,   365,   365,   365,   367,   366,   369,
     368,   371,   370,   372,   372,   373,   374,   375,   376,   376,
     377,   378,   379,   379,   380,   380,   380,   382,   381,   384,
     383,   386,   385,   387,   387,   388,   389,   390,   391,   391,
     393,   392,   394,   395,   396,   397,   397,   399,   398,   400,
     401,   402,   403,   403,   405,   404,   406,   407,   408,   409,
     410,   410,   412,   411,   413,   413,   414,   414,   414,   416,
     415,   418,   417,   420,   419,   421,   421,   422,   422,   423,
     424,   424,   425,   425,   425,   426,   427,   428,   429,   429,
     430,   431,   431,   432,   433,   433,   434,   434,   435,   435,
     436,   437,   437,   438,   439,   440,   440,   441,   441,   442,
     444,   443,   445,   445,   446,   446,   447,   448,   448,   449,
     450,   451,   451,   452,   452,   453,   455,   454,   456,   456,
     457,   457,   458,   459,   460,   460,   461,   461,   461,   461,
     461,   461,   461,   462,   464,   463,   466,   465,   468,   467,
     470,   469,   472,   471,   474,   473,   475,   476,   476,   477,
     478,   479,   479,   480,   480,   480,   480,   481,   483,   482,
     485,   484,   487,   486,   488,   488,   489,   489,   490,   491,
     491,   492,   492,   493,   493,   494,   495,   495,   496,   497,
     498,   498,   499,   499,   500,   502,   501,   503,   503,   504,
     504,   505,   506,   506,   507,   508,   509,   509,   510,   510,
     510,   511,   513,   512,   515,   514,   516,   516,   517,   517,
     518,   519,   520,   520,   521,   521,   521,   521,   521,   521,
     521,   522,   524,   523,   526,   525,   528,   527,   530,   529,
     532,   531,   534,   533,   535,   536,   536,   537,   538,   539,
     539,   540,   540,   540,   540,   541,   543,   542,   545,   544,
     547,   546,   548,   548,   549,   549,   550,   551,   551,   552,
     552,   553,   553,   554,   555,   555,   556,   557,   558,   558,
     559,   559,   560,   562,   561,   563,   563,   564,   564,   565,
     566,   566,   567,   568,   569,   569,   570,   570,   570,   571,
     573,   572,   575,   574,   576,   576,   577,   577,   578,   579,
     580,   580,   581,   581,   581,   581,   581,   581,   581,   582,
     584,   583,   586,   585,   588,   587,   590,   589,   592,   591,
     594,   593,   595,   596,   596,   597,   598,   599,   599,   600,
     600,   600,   600,   601,   603,   602,   605,   604,   607,   606,
     608,   608,   609,   609,   610,   611,   612,   612,   614,   613,
     615,   615,   616,   616,   616,   616,   616,   616,   618,   617,
     620,   619,   622,   621,   624,   623,   626,   625,   628,   627,
     629,   629
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     2,     1,     2,     5,     0,     2,     1,
       3,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     1,     2,     0,
       4,     2,     1,     1,     2,     0,     4,     2,     1,     1,
       2,     0,     4,     3,     1,     0,     0,     4,     1,     3,
       0,     1,     2,     1,     1,     2,     0,     4,     2,     1,
       1,     2,     0,     4,     2,     1,     1,     2,     0,     4,
       2,     1,     1,     2,     0,     4,     2,     1,     1,     2,
       0,     4,     3,     1,     0,     0,     4,     1,     3,     0,
       1,     4,     1,     4,     2,     0,     2,     0,     4,     0,
       2,     1,     1,     1,     0,     4,     0,     4,     0,     4,
       1,     2,     0,     2,     1,     3,     1,     0,     2,     1,
       1,     1,     1,     1,     3,     1,     0,     0,     4,     1,
       2,     3,     3,     3,     1,     0,     0,     4,     1,     2,
       3,     3,     3,     1,     0,     0,     4,     1,     2,     3,
       3,     2,     1,     1,     2,     0,     4,     4,     1,     4,
       2,     0,     2,     0,     4,     0,     2,     1,     1,     1,
       0,     4,     0,     4,     0,     4,     1,     2,     0,     2,
       1,     3,     1,     0,     2,     1,     1,     2,     1,     1,
       2,     0,     4,     4,     1,     4,     2,     0,     2,     0,
       4,     0,     2,     1,     1,     1,     0,     4,     0,     4,
       0,     4,     1,     2,     2,     1,     3,     1,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     0,     0,     4,
       1,     2,     3,     3,     2,     1,     1,     2,     0,     4,
       5,     1,     4,     0,     2,     0,     5,     5,     1,     4,
       0,     2,     0,     5,     5,     1,     4,     0,     2,     0,
       5,     5,     1,     4,     0,     2,     0,     5,     5,     1,
       4,     0,     2,     0,     5,     5,     1,     4,     0,     2,
       3,     1,     0,     2,     1,     1,     1,     0,     4,     0,
       4,     0,     4,     2,     1,     5,     1,     4,     0,     2,
       3,     1,     0,     2,     1,     1,     1,     0,     4,     0,
       4,     0,     4,     2,     1,     5,     1,     4,     0,     2,
       3,     1,     0,     2,     1,     1,     1,     0,     4,     0,
       4,     0,     4,     2,     1,     5,     1,     4,     0,     2,
       3,     1,     0,     2,     1,     1,     1,     0,     4,     0,
       4,     0,     4,     2,     1,     5,     1,     4,     0,     2,
       0,     5,     5,     1,     4,     0,     2,     0,     5,     5,
       1,     4,     0,     2,     0,     5,     4,     1,     4,     2,
       0,     2,     0,     4,     0,     2,     1,     1,     1,     0,
       4,     0,     4,     0,     4,     1,     2,     0,     3,     1,
       0,     2,     1,     1,     1,     4,     4,     4,     3,     1,
       4,     0,     3,     1,     0,     4,     5,     1,     0,     5,
       4,     0,     2,     3,     1,     0,     2,     1,     1,     4,
       0,     4,     2,     1,     0,     5,     4,     0,     2,     3,
       1,     0,     2,     1,     1,     4,     0,     4,     2,     1,
       0,     2,     3,     1,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     4,     0,     4,     0,     4,     0,     4,
       0,     4,     0,     4,     0,     4,     3,     0,     2,     3,
       1,     0,     2,     1,     1,     1,     1,     4,     0,     4,
       0,     4,     0,     4,     2,     1,     0,     3,     1,     0,
       4,     5,     1,     0,     5,     4,     0,     2,     3,     1,
       0,     2,     1,     1,     4,     0,     4,     2,     1,     0,
       5,     4,     0,     2,     3,     1,     0,     2,     1,     1,
       1,     4,     0,     4,     0,     4,     2,     1,     0,     2,
       3,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     4,     0,     4,     0,     4,     0,     4,     0,     4,
       0,     4,     0,     4,     3,     0,     2,     3,     1,     0,
       2,     1,     1,     1,     1,     4,     0,     4,     0,     4,
       0,     4,     2,     1,     0,     3,     1,     0,     4,     5,
       1,     0,     5,     4,     0,     2,     3,     1,     0,     2,
       1,     1,     4,     0,     4,     2,     1,     0,     5,     4,
       0,     2,     3,     1,     0,     2,     1,     1,     1,     4,
       0,     4,     0,     4,     2,     1,     0,     2,     3,     1,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     4,
       0,     4,     0,     4,     0,     4,     0,     4,     0,     4,
       0,     4,     3,     0,     2,     3,     1,     0,     2,     1,
       1,     1,     1,     4,     0,     4,     0,     4,     0,     4,
       2,     1,     0,     5,     1,     4,     0,     2,     0,     4,
       0,     2,     1,     1,     1,     1,     1,     1,     0,     4,
       0,     4,     0,     4,     0,     4,     0,     4,     0,     4,
       2,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     4,     0,     0,     5,     1,     7,     3,     9,     0,
     112,     0,     2,   114,   178,     0,    12,    11,     8,   180,
       0,     0,   117,   116,   113,     0,   215,   407,     0,   183,
     182,   179,     0,    10,    26,    32,    38,    44,    53,    59,
      65,    71,    77,    83,    92,    13,    14,     0,    15,     0,
      16,     0,    17,    45,    18,     0,    19,     0,    20,     0,
      21,     0,    22,     0,    23,    84,    24,     0,   409,     6,
     410,   218,   217,   214,     0,   115,   158,   125,   134,   143,
     152,   118,   119,   126,   120,   135,   121,   144,   122,     0,
     123,     0,     0,    27,    25,     0,    33,    31,     0,    39,
      37,     0,     0,     0,    54,    52,     0,    60,    58,     0,
      66,    64,     0,    72,    70,     0,    78,    76,     0,     0,
       0,     0,     0,     0,   181,   194,   188,   184,   185,     0,
     186,     0,     0,     0,     0,     0,     0,     0,     0,   153,
     151,     0,     0,    29,    28,    35,    34,    41,    40,    46,
      50,    48,    43,    56,    55,    62,    61,    68,    67,    74,
      73,    80,    79,    85,    89,    87,    82,     0,    95,   421,
     419,     0,     0,     0,   411,   412,   413,   414,   408,   216,
     387,   236,   245,   251,   258,   265,   272,   279,   373,   366,
     286,   306,   326,   346,   380,   219,   220,   237,   221,     0,
     222,     0,   223,     0,   224,     0,   225,     0,   226,     0,
     227,     0,   228,     0,   229,     0,   230,     0,   231,     0,
     232,     0,   233,     0,   234,     0,     0,   189,   187,     0,
       0,   127,     0,   129,   124,   136,     0,   138,   133,   145,
       0,   147,   142,   155,   154,     0,   161,     0,     0,     0,
       0,    51,     0,     0,     0,     0,     0,     0,     0,    90,
       0,     0,    91,     0,   423,     0,   506,   424,     0,     0,
       0,     0,     0,     0,   246,   244,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   191,   190,     0,   197,     0,     0,     0,   130,
       0,     0,     0,   139,     0,     0,     0,   148,     0,     0,
     157,     0,    30,    36,    42,    47,    49,    57,    63,    69,
      75,    81,    86,    88,    93,    94,    97,    96,   418,   508,
     594,   509,     0,     0,     0,     0,     0,   238,     0,   240,
     235,   248,   247,     0,   253,     0,   260,     0,   267,     0,
     274,     0,   281,     0,   288,     0,   308,     0,   328,     0,
     348,     0,   368,     0,   375,     0,   382,     0,   390,     0,
       0,   193,     0,   128,   132,   131,   137,   141,   140,   146,
     150,   149,   156,   159,   160,   163,   162,    99,   596,   682,
     597,     0,     0,     0,   428,   427,   422,   415,   417,   416,
       0,     0,     0,   241,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     386,     0,   192,   195,   196,   199,   198,   165,     0,   684,
     420,     0,     0,     0,     0,   513,   512,   507,     0,     0,
     444,   239,   243,   242,   249,   252,     0,   250,   254,   259,
     257,     0,   261,   266,   264,     0,   268,   273,     0,   271,
     275,   280,     0,   278,   282,   287,   291,   285,   289,   292,
     307,   311,   305,   309,   312,   327,   331,   325,   329,   332,
     347,   351,   345,   349,   352,   367,     0,   365,   369,   374,
       0,   372,   376,   381,   379,     0,   383,   388,   389,   392,
     391,   201,     0,     0,   110,     0,     0,     0,   100,   101,
     102,   103,    98,     0,     0,     0,   601,   600,   595,     0,
       0,   529,   425,     0,     0,     0,   460,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   394,
       0,     0,   176,     0,     0,     0,   166,   167,   168,   169,
     164,   111,   104,   106,   108,     0,   686,     0,     0,   617,
     510,     0,     0,     0,   548,     0,   431,     0,     0,     0,
     255,   262,   269,   276,   283,     0,   304,     0,     0,     0,
     293,   294,   295,   296,   290,     0,   324,     0,     0,     0,
     313,   314,   315,   316,   310,     0,   344,     0,     0,     0,
     333,   334,   335,   336,   330,     0,   364,     0,     0,     0,
     353,   354,   355,   356,   350,   370,   377,   384,     0,     0,
     212,     0,     0,     0,   202,   203,   204,   205,   200,   177,
     170,   172,   174,     0,     0,     0,     0,     0,   598,     0,
       0,     0,   636,     0,   516,     0,     0,     0,     0,     0,
       0,   447,   463,   426,   461,   464,     0,     0,     0,     0,
       0,   303,   297,   299,   301,   323,   317,   319,   321,   343,
     337,   339,   341,   363,   357,   359,   361,     0,     0,     0,
       0,   405,     0,     0,     0,   395,   396,   397,   398,   393,
     213,   206,   208,   210,     0,     0,     0,   105,   107,   109,
     685,   683,   688,   687,     0,   604,     0,     0,     0,     0,
       0,     0,   532,   551,   511,   549,   552,   430,   429,   434,
     432,   435,     0,     0,     0,   256,   263,   270,   277,   284,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   371,   378,   385,   406,   399,   401,   403,     0,
       0,     0,   171,   173,   175,   690,     0,     0,     0,   620,
     639,   599,   637,   640,   515,   514,   519,   517,   520,     0,
       0,     0,     0,   446,   450,   445,   448,   451,   487,     0,
       0,     0,     0,     0,     0,     0,   465,   466,   467,   468,
     469,   470,   471,   472,   462,   298,   300,   302,   318,   320,
     322,   338,   340,   342,   358,   360,   362,     0,     0,     0,
     207,   209,   211,     0,   603,   602,   607,   605,   608,     0,
       0,     0,     0,   531,   535,   530,   533,   536,   575,     0,
       0,     0,     0,     0,     0,     0,   553,   554,   555,   556,
     557,   558,   559,   560,   550,     0,   443,     0,     0,   436,
     437,   438,   433,     0,     0,   478,   480,   482,     0,   474,
     476,   484,   400,   402,   404,     0,   711,     0,     0,     0,
       0,     0,     0,   691,   692,   693,   694,   695,   696,   697,
     689,     0,   619,   623,   618,   621,   624,   663,     0,     0,
       0,     0,     0,     0,     0,   641,   642,   643,   644,   645,
     646,   647,   648,   638,     0,   528,     0,     0,   521,   522,
     523,   518,     0,     0,   566,   568,   570,     0,   562,   564,
     572,   442,     0,   440,     0,   459,     0,     0,   452,   453,
     454,   449,   486,   490,   488,   491,     0,     0,     0,     0,
       0,     0,     0,   710,   702,   704,   706,   698,   700,   708,
       0,   616,     0,     0,   609,   610,   611,   606,     0,     0,
     654,   656,   658,     0,   650,   652,   660,   527,     0,   525,
       0,   547,     0,     0,     0,   537,   538,   539,   540,   534,
     574,   578,   576,   579,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   458,     0,   456,     0,   479,   481,   483,
     473,   475,   477,   485,     0,     0,     0,     0,     0,     0,
     615,     0,   613,     0,   635,     0,     0,     0,   625,   626,
     627,   628,   622,   662,   666,   664,   667,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   546,     0,   542,   544,
       0,   567,   569,   571,   561,   563,   565,   573,   439,   441,
       0,     0,     0,   505,     0,     0,     0,     0,   492,   493,
     494,   495,   496,   489,   703,   705,   707,   699,   701,   709,
       0,     0,   634,     0,   630,   632,     0,   655,   657,   659,
     649,   651,   653,   661,   524,   526,     0,     0,     0,     0,
     593,     0,     0,     0,     0,   580,   581,   582,   583,   584,
     577,   455,   457,   504,     0,   498,   500,   502,   612,   614,
       0,     0,     0,     0,   681,     0,     0,     0,     0,   668,
     669,   670,   671,   672,   665,   541,   543,   545,   592,     0,
     586,   588,   590,     0,     0,     0,     0,   629,   631,   633,
     680,     0,   674,   676,   678,     0,     0,     0,     0,   497,
     499,   501,   503,     0,     0,     0,     0,   585,   587,   589,
     591,   673,   675,   677,   679
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     9,    10,    11,    18,    25,    45,    46,
      47,    94,   247,    48,    49,    97,   248,    50,    51,   100,
     249,    52,    53,   102,   250,   152,   252,    54,    55,   105,
     253,    56,    57,   108,   254,    58,    59,   111,   255,    60,
      61,   114,   256,    62,    63,   117,   257,    64,    65,   119,
     258,   166,   260,    66,    67,   121,   262,   263,   337,   397,
     448,   528,   529,   653,   530,   654,   531,   655,   532,    14,
      15,    24,    32,    81,    82,    83,   133,   306,   234,    84,
      85,   135,   310,   238,    86,    87,   137,   314,   242,    88,
      89,   140,   318,    90,    91,   142,   320,   321,   396,   447,
     522,   566,   567,   714,   568,   715,   569,   716,   570,    20,
      21,    31,    74,   127,   128,   129,   228,   379,   130,   131,
     230,   381,   382,   446,   521,   560,   644,   645,   769,   646,
     770,   647,   771,   648,    27,    28,    73,   123,   195,   196,
     197,   272,   410,   350,   198,   199,   275,   414,   200,   201,
     277,   416,   468,   676,   202,   203,   279,   418,   472,   677,
     204,   205,   281,   420,   476,   678,   206,   207,   283,   422,
     480,   679,   208,   209,   285,   424,   484,   680,   210,   211,
     287,   426,   488,   489,   552,   600,   601,   750,   602,   751,
     603,   752,   604,   212,   213,   289,   428,   493,   494,   553,
     610,   611,   753,   612,   754,   613,   755,   614,   214,   215,
     291,   430,   498,   499,   554,   620,   621,   756,   622,   757,
     623,   758,   624,   216,   217,   293,   432,   503,   504,   555,
     630,   631,   759,   632,   760,   633,   761,   634,   218,   219,
     295,   434,   508,   697,   220,   221,   297,   436,   512,   698,
     222,   223,   299,   438,   516,   699,   224,   225,   301,   440,
     441,   520,   559,   638,   705,   706,   827,   707,   828,   708,
     829,   709,    69,    70,   122,   174,   175,   176,   177,   178,
     265,   266,   267,   343,   406,   460,   544,   669,   740,   741,
     792,   869,   870,   871,  1012,   872,   546,   588,   743,   796,
     797,   873,   948,   949,   950,  1071,   951,   589,   674,   675,
     744,   806,   807,   808,   960,   809,   961,   810,   956,   811,
     957,   812,   958,   813,   962,   814,   874,   954,   955,  1016,
    1078,  1079,  1080,  1154,  1081,  1155,  1082,  1156,  1083,   340,
     341,   402,   457,   541,   582,   730,   787,   788,   842,   928,
     929,   930,  1055,   931,   584,   666,   790,   846,   847,   932,
     995,   996,   997,  1107,   998,  1108,   999,   667,   735,   736,
     791,   856,   857,   858,  1008,   859,  1009,   860,  1004,   861,
    1005,   862,  1006,   863,  1010,   864,   933,  1002,  1003,  1060,
    1115,  1116,  1117,  1166,  1118,  1167,  1119,  1168,  1120,   399,
     400,   453,   538,   579,   660,   777,   837,   838,   901,   974,
     975,   976,  1091,   977,   662,   727,   840,   905,   906,   978,
    1038,  1039,  1040,  1131,  1041,  1132,  1042,   728,   782,   783,
     841,   915,   916,   917,  1051,   918,  1052,   919,  1047,   920,
    1048,   921,  1049,   922,  1053,   923,   979,  1045,  1046,  1096,
    1139,  1140,  1141,  1174,  1142,  1175,  1143,  1176,  1144,   450,
     451,   534,   657,   723,   775,   833,   893,   894,  1027,   895,
    1028,   896,  1024,   897,  1025,   898,  1026,   899,  1029,   900
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -77
static const yytype_int16 yypact[] =
{
      17,    20,    33,   110,   -77,   -77,    -8,   -77,   -77,    13,
      24,   141,   -77,   -77,    -6,   217,   -77,   -77,   -77,   -77,
       0,   223,   -77,   -77,   -77,   193,   -77,    47,   231,   -77,
     -77,   -77,   -20,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   234,   -77,   267,
     -77,   279,   -77,    38,   -77,   281,   -77,   283,   -77,   285,
     -77,   287,   -77,   289,   -77,    51,   -77,    90,   -77,   -77,
     -77,   -77,   -77,   -77,   -18,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,    72,   -77,   116,   -77,   121,   -77,   291,
     -77,   147,    18,   -77,   -77,    25,   -77,   -77,    15,   -77,
     -77,   164,   293,    14,   -77,   -77,    16,   -77,   -77,    12,
     -77,   -77,    11,   -77,   -77,     7,   -77,   -77,   173,   295,
     162,   176,    88,   -49,   -77,   -77,   -77,   -77,   -77,   297,
     -77,   171,   185,   299,   200,   301,   214,   303,    -1,   -77,
     -77,   187,   188,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     209,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   229,   -77,   -77,   242,   -77,    98,
     -77,   244,   246,   248,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   218,   -77,   305,
     -77,   205,   -77,   252,   -77,   255,   -77,   260,   -77,   310,
     -77,   243,   -77,   247,   -77,   318,   -77,   321,   -77,   329,
     -77,   330,   -77,   224,   -77,   333,     1,   -77,   -77,   256,
     251,   -77,     4,   -77,   -77,   -77,     8,   -77,   -77,   -77,
       2,   -77,   -77,   -77,   -77,   344,   -77,   296,   298,   294,
     346,   -77,   300,   302,   292,   304,   290,   306,   348,   -77,
     307,   350,   -77,   241,   -77,   311,   222,   331,   354,   357,
     360,   363,   309,    -4,   -77,   -77,   361,   359,   362,   364,
     366,   367,   370,   372,   371,   373,   375,   376,   378,   379,
     381,   382,   384,   385,   387,   388,   390,   391,   393,   394,
     396,   397,   -77,   -77,   369,   -77,   399,   308,   314,   -77,
     400,   315,   324,   -77,   401,   316,   319,   -77,   325,   403,
     -77,   245,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     274,   340,   405,   313,   406,   407,   408,   -77,    -3,   -77,
     -77,   -77,   -77,   411,   -77,   412,   -77,   413,   -77,   414,
     -77,   415,   -77,   416,   -77,   417,   -77,   418,   -77,   419,
     -77,   420,   -77,   421,   -77,   422,   -77,   423,   -77,   343,
     424,   -77,   249,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   238,
     398,   425,   317,   428,   266,   -77,   -77,   -77,   -77,   -77,
     427,   347,   349,   -77,   351,   429,    45,   431,    54,   432,
     232,   433,    42,   435,     6,   436,   -62,   437,   -76,   438,
     -67,   439,   -71,   440,   -58,   441,    -2,   442,   212,   443,
     -77,   258,   -77,   -77,   -77,   -77,   -77,   -77,   166,   -77,
     -77,   426,   444,   326,   448,   323,   -77,   -77,   449,   430,
     328,   -77,   -77,   -77,   -77,   -77,   450,   -77,   -77,   -77,
     -77,   451,   -77,   -77,   -77,   452,   -77,   -77,   453,   -77,
     -77,   -77,   454,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   456,   -77,   -77,   -77,
     457,   -77,   -77,   -77,   -77,   458,   -77,   -77,   -77,   -77,
     -77,   -77,   169,   392,   -77,   464,   466,   467,   -77,   -77,
     -77,   -77,   -77,   465,   463,   468,   335,   -77,   -77,   469,
     445,   322,   -77,   470,   472,   455,   -77,   471,   474,   477,
     478,   479,   215,   259,   262,   265,   480,   481,   482,   -77,
     174,   434,   -77,   484,   486,   487,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   488,   -77,   485,   459,   352,
     -77,   489,   483,   473,   -77,   492,   -77,   491,   493,   -32,
     -77,   -77,   -77,   -77,   -77,   402,   -77,   496,   497,   500,
     -77,   -77,   -77,   -77,   -77,   404,   -77,   502,   503,   505,
     -77,   -77,   -77,   -77,   -77,   409,   -77,   508,   509,   510,
     -77,   -77,   -77,   -77,   -77,   446,   -77,   511,   512,   513,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   182,   447,
     -77,   514,   515,   516,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   517,   518,   519,   520,   191,   -77,   521,
     522,   494,   -77,   526,   -77,   525,   527,   -41,   529,   216,
     528,   -77,   -77,   -77,   -77,   -77,   460,   461,   462,   475,
     476,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   490,   495,   498,
     499,   -77,   531,   534,   535,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   532,   533,   536,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   537,   -77,   538,   539,   -63,   541,
     210,   544,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   543,   -16,   123,   -77,   -77,   -77,   -77,   -77,
     545,   546,   547,   548,   549,   550,   551,   554,   555,   556,
     557,   558,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   559,
     560,   561,   -77,   -77,   -77,   -77,   562,   204,   565,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   564,
      75,   130,   105,   -77,   -77,   -77,   -77,   -77,   -77,   569,
     573,   574,   571,   576,   577,   578,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   575,   579,   580,
     -77,   -77,   -77,   149,   -77,   -77,   -77,   -77,   -77,   582,
      97,   157,   190,   -77,   -77,   -77,   -77,   -77,   -77,   581,
     587,   588,   585,   591,   592,   593,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   395,   -77,   590,   595,   -77,
     -77,   -77,   -77,   192,   -55,   -77,   -77,   -77,   594,   -77,
     -77,   -77,   -77,   -77,   -77,   501,   -77,   597,   598,   599,
     600,   601,   602,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   207,   -77,   -77,   -77,   -77,   -77,   -77,   603,   604,
     605,   606,   607,   608,   609,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   386,   -77,   610,   611,   -77,   -77,
     -77,   -77,    93,   -59,   -77,   -77,   -77,   614,   -77,   -77,
     -77,   -77,   615,   -77,   504,   -77,   616,   612,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   617,   618,   619,   620,
     621,   622,   624,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     506,   -77,   625,   613,   -77,   -77,   -77,   -77,    99,   -70,
     -77,   -77,   -77,   628,   -77,   -77,   -77,   -77,   629,   -77,
     410,   -77,   630,   632,   633,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   631,   634,   635,   636,   637,   638,
     639,   640,   643,   -77,   646,   -77,    83,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   645,   647,   648,   649,   650,   651,
     -77,   654,   -77,   523,   -77,   653,   658,   659,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   656,   657,   660,
     661,   662,   663,   664,   665,   666,   -77,   669,   -77,   -77,
      85,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     668,   670,   540,   -77,   671,   673,   676,   677,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     674,   675,   -77,   678,   -77,   -77,    91,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   679,   680,   681,   563,
     -77,   683,   682,   688,   689,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   690,   -77,   -77,   -77,   -77,   -77,
     686,   687,   691,   542,   -77,   692,   693,   694,   697,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   696,
     -77,   -77,   -77,   695,   698,   699,   700,   -77,   -77,   -77,
     -77,   703,   -77,   -77,   -77,   702,   704,   705,   706,   -77,
     -77,   -77,   -77,   707,   708,   709,   710,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     351,   179,   411,   412,   243,   302,  1043,   315,   316,   307,
     308,   161,   780,   311,   312,   159,   157,  1000,   153,   147,
     155,   952,   143,   491,   180,    12,    75,     1,   501,   145,
     124,     4,   496,     5,   733,     8,   492,   486,   181,   506,
     182,    19,   183,   672,   184,   502,   185,   497,   487,    26,
     507,   101,   186,    76,   187,   125,   188,    77,   189,    78,
     190,    79,   191,    80,   192,   118,   193,   126,   194,    13,
     953,  1044,   144,   148,  1001,   781,   154,   162,   158,   160,
     156,   146,   309,   244,   317,   413,   352,   303,   313,   734,
     673,  1072,  1073,  1109,  1110,   510,   169,   170,    68,  1133,
    1134,   990,   991,   482,   511,   120,   466,  1033,  1034,   794,
     483,   132,   795,   865,   866,   171,   172,   173,     6,     7,
    1074,  1075,  1111,  1112,  1076,  1077,  1113,  1114,  1135,  1136,
     992,   798,  1137,  1138,   993,   994,  1035,   467,   848,   478,
    1036,  1037,   867,   868,   479,   799,   800,   801,   470,    16,
      17,   471,   849,   850,   851,   134,   802,   885,   886,   803,
     136,   804,   141,   805,   852,   907,   853,   149,   854,   167,
     855,   887,   888,   889,   523,   524,   163,   561,   562,   908,
     909,   910,   639,   640,   168,   890,   229,   891,   231,   892,
     700,   701,   911,   912,   245,   913,   246,   914,   924,   925,
     944,   945,   525,   235,   526,   563,   527,   564,   844,   565,
     641,   845,   642,   251,   643,   970,   971,   239,   702,   264,
     703,   276,   704,   595,   596,    22,    23,   926,   927,   946,
     947,    29,    30,   259,   597,   598,   599,    33,   903,    71,
      72,   904,    92,    93,   972,   973,    34,   261,    35,   298,
      36,   268,    37,   269,    38,   270,    39,   271,    40,   305,
      41,   286,    42,   304,    43,   288,    44,   605,   606,   278,
     615,   616,   280,   625,   626,    95,    96,   282,   607,   608,
     609,   617,   618,   619,   627,   628,   629,    98,    99,   103,
     104,   106,   107,   109,   110,   112,   113,   115,   116,   138,
     139,   150,   151,   164,   165,   226,   227,   232,   233,   236,
     237,   240,   241,   273,   274,   335,   336,   348,   349,   394,
     395,   404,   405,   444,   445,   455,   456,   284,   474,   475,
     514,   515,   518,   519,   536,   537,   290,   721,   722,   292,
     738,   739,   785,   786,   835,   836,   294,   296,   300,   319,
     322,   339,   324,   325,   323,   332,   328,   334,   330,   344,
     326,   342,   345,   338,   327,   346,   347,   354,   353,   355,
     329,   401,   356,   357,   380,   358,   331,   359,   361,   333,
     360,   362,   363,   449,   364,   365,   384,   366,   367,   459,
     368,   369,   385,   370,   371,   387,   372,   373,   390,   374,
     375,   391,   376,   377,   388,   378,   383,   386,   389,   392,
     393,   398,   403,   407,   408,   409,   415,   417,   419,   421,
     423,   425,   427,   429,   431,   433,   435,   437,   439,   442,
     452,   443,   454,   458,   461,   462,   465,   463,   469,   473,
     477,   464,   481,   485,   490,   495,   500,   505,   509,   513,
     517,   535,   533,   539,   540,   545,   542,   583,   547,   548,
     549,   550,   551,   543,   556,   557,   558,   572,   571,   573,
     574,   576,   575,   577,   578,   590,   580,   585,   591,   581,
     586,   592,   593,   594,   635,   636,   637,   650,   587,   651,
     652,   664,   658,   656,   659,   661,   663,   668,   670,   682,
     683,   671,   681,   684,   685,   686,   687,   665,   688,   689,
     649,   690,   691,   692,   694,   695,   696,   711,   712,   713,
     987,   941,   745,   710,   717,   718,   719,   720,   724,   726,
     725,   729,   731,   742,   766,   732,   737,   767,   768,   772,
     773,     0,   776,   774,  1056,   778,   693,   779,   784,   789,
     793,     0,   815,   816,   817,   818,   819,   820,   821,   746,
     747,   822,   823,   824,   825,   826,   830,   831,   832,   834,
     839,   843,   875,   748,   749,   765,   876,   877,   878,   879,
     880,   881,   882,     0,   934,     0,   883,   884,   762,   902,
     935,   936,   937,   763,   938,   939,   940,   942,   943,   959,
     964,   965,   966,   967,   968,   969,   980,   981,   982,     0,
     984,   985,   986,   983,   989,  1015,  1032,   988,   764,  1007,
    1011,     0,     0,  1014,  1017,  1018,  1019,  1020,  1021,  1022,
    1013,  1023,  1031,  1050,  1054,  1058,  1059,  1057,  1061,     0,
       0,  1062,  1063,  1064,  1065,  1066,  1067,  1068,  1030,   963,
    1069,  1070,  1084,     0,  1085,  1086,  1087,  1088,  1089,  1090,
    1093,  1094,  1095,  1097,  1098,  1092,  1123,  1099,  1100,  1101,
    1102,  1103,  1104,  1105,  1106,  1121,  1125,  1122,  1124,  1126,
    1127,  1128,  1129,  1130,  1160,  1150,  1145,  1146,  1147,  1148,
    1149,  1151,  1152,  1157,  1158,  1153,  1162,  1163,  1159,  1161,
    1164,  1165,  1169,     0,     0,  1170,  1171,  1172,  1173,  1177,
       0,  1178,  1179,  1180,  1181,  1182,  1183,  1184
};

static const yytype_int16 yycheck[] =
{
       4,    50,     5,     6,     5,     4,    76,     5,     6,     5,
       6,     4,    75,     5,     6,     4,     4,    76,     4,     4,
       4,    76,     4,    99,    73,    12,    46,    10,    99,     4,
      48,    11,    99,     0,    75,    43,   112,    99,    87,    97,
      89,    47,    91,    75,    93,   116,    95,   114,   110,    49,
     108,    13,   101,    73,   103,    73,   105,    77,   107,    79,
     109,    81,   111,    83,   113,    14,   115,    85,   117,    45,
     125,   141,    54,    58,   133,   138,    62,    70,    66,    68,
      64,    56,    78,    84,    82,    88,    90,    86,    80,   130,
     122,     8,     9,     8,     9,    97,     8,     9,    51,     8,
       9,     8,     9,    97,   106,    15,    61,     8,     9,   125,
     104,    39,   128,     8,     9,    27,    28,    29,     8,     9,
      37,    38,    37,    38,    41,    42,    41,    42,    37,    38,
      37,     8,    41,    42,    41,    42,    37,    92,     8,    97,
      41,    42,    37,    38,   102,    22,    23,    24,    94,     8,
       9,    97,    22,    23,    24,    39,    33,     8,     9,    36,
      39,    38,    15,    40,    34,     8,    36,     3,    38,     7,
      40,    22,    23,    24,     8,     9,     3,     8,     9,    22,
      23,    24,     8,     9,     8,    36,    15,    38,     3,    40,
       8,     9,    35,    36,     7,    38,     8,    40,     8,     9,
       8,     9,    36,     3,    38,    36,    40,    38,   133,    40,
      36,   136,    38,     4,    40,     8,     9,     3,    36,   121,
      38,    16,    40,     8,     9,     8,     9,    37,    38,    37,
      38,     8,     9,     4,    19,    20,    21,    44,   141,     8,
       9,   144,     8,     9,    37,    38,    53,     5,    55,    25,
      57,     7,    59,     7,    61,     7,    63,    39,    65,     8,
      67,    18,    69,     7,    71,    18,    73,     8,     9,    17,
       8,     9,    17,     8,     9,     8,     9,    17,    19,    20,
      21,    19,    20,    21,    19,    20,    21,     8,     9,     8,
       9,     8,     9,     8,     9,     8,     9,     8,     9,     8,
       9,     8,     9,     8,     9,     8,     9,     8,     9,     8,
       9,     8,     9,     8,     9,    74,    75,     8,     9,    74,
      75,     8,     9,    74,    75,     8,     9,    17,    96,    97,
     118,   119,    74,    75,     8,     9,    18,   146,   147,    18,
     124,   125,   132,   133,   140,   141,    17,    17,    15,     5,
      54,   129,    58,     7,    56,     7,    64,     7,    68,     5,
      60,    30,     5,    52,    62,     5,     3,     8,     7,     7,
      66,    31,     8,     7,     5,     8,    70,     7,     7,    72,
       8,     8,     7,   145,     8,     7,    78,     8,     7,   123,
       8,     7,    78,     8,     7,    80,     8,     7,    82,     8,
       7,    82,     8,     7,    80,     8,     7,     7,     7,    84,
       7,   137,     7,     7,     7,     7,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,    86,
      32,     7,     7,     5,     7,    88,     7,    88,     7,     7,
       7,    90,     7,     7,     7,     7,     7,     7,     7,     7,
       7,     7,    26,     5,   131,   127,     7,   135,     8,     8,
       8,     8,     8,    33,     8,     8,     8,     3,    76,     3,
       3,     8,     7,     5,   139,     4,     7,     7,     4,    34,
       8,     4,     4,     4,     4,     4,     4,     3,    33,     3,
       3,     8,     7,     5,    35,   143,     7,     5,     7,     3,
       3,     8,   100,     3,   100,     3,     3,    34,     3,   100,
      76,     3,     3,     3,     3,     3,     3,     3,     3,     3,
     134,   126,    62,    76,     7,     7,     7,     7,     7,    35,
       8,     5,     7,     5,     3,     8,     7,     3,     3,     7,
       7,    -1,     5,     7,   134,     7,   100,     8,     7,     5,
       7,    -1,     7,     7,     7,     7,     7,     7,     7,    98,
      98,     7,     7,     7,     7,     7,     7,     7,     7,     7,
       5,     7,     3,    98,    98,    76,     3,     3,     7,     3,
       3,     3,     7,    -1,     3,    -1,     7,     7,    98,     7,
       3,     3,     7,    98,     3,     3,     3,     7,     3,     5,
       3,     3,     3,     3,     3,     3,     3,     3,     3,    -1,
       3,     3,     3,     7,     3,     3,     3,     7,   120,     5,
       5,    -1,    -1,     7,     7,     7,     7,     7,     7,     7,
     126,     7,     7,     5,     5,     3,     3,     7,     7,    -1,
      -1,     7,     7,     7,     7,     7,     7,     7,   142,   148,
       7,     5,     7,    -1,     7,     7,     7,     7,     7,     5,
       7,     3,     3,     7,     7,   142,   126,     7,     7,     7,
       7,     7,     7,     7,     5,     7,     3,     7,     7,     3,
       3,     7,     7,     5,   142,     3,     7,     7,     7,   126,
       7,     3,     3,     7,     7,     5,     3,     3,     7,     7,
       3,     5,     7,    -1,    -1,     7,     7,     7,     5,     7,
      -1,     7,     7,     7,     7,     7,     7,     7
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    10,   151,   152,    11,     0,     8,     9,    43,   153,
     154,   155,    12,    45,   219,   220,     8,     9,   156,    47,
     259,   260,     8,     9,   221,   157,    49,   284,   285,     8,
       9,   261,   222,    44,    53,    55,    57,    59,    61,    63,
      65,    67,    69,    71,    73,   158,   159,   160,   163,   164,
     167,   168,   171,   172,   177,   178,   181,   182,   185,   186,
     189,   190,   193,   194,   197,   198,   203,   204,    51,   422,
     423,     8,     9,   286,   262,    46,    73,    77,    79,    81,
      83,   223,   224,   225,   229,   230,   234,   235,   239,   240,
     243,   244,     8,     9,   161,     8,     9,   165,     8,     9,
     169,    13,   173,     8,     9,   179,     8,     9,   183,     8,
       9,   187,     8,     9,   191,     8,     9,   195,    14,   199,
      15,   205,   424,   287,    48,    73,    85,   263,   264,   265,
     268,   269,    39,   226,    39,   231,    39,   236,     8,     9,
     241,    15,   245,     4,    54,     4,    56,     4,    58,     3,
       8,     9,   175,     4,    62,     4,    64,     4,    66,     4,
      68,     4,    70,     3,     8,     9,   201,     7,     8,     8,
       9,    27,    28,    29,   425,   426,   427,   428,   429,    50,
      73,    87,    89,    91,    93,    95,   101,   103,   105,   107,
     109,   111,   113,   115,   117,   288,   289,   290,   294,   295,
     298,   299,   304,   305,   310,   311,   316,   317,   322,   323,
     328,   329,   343,   344,   358,   359,   373,   374,   388,   389,
     394,   395,   400,   401,   406,   407,     8,     9,   266,    15,
     270,     3,     8,     9,   228,     3,     8,     9,   233,     3,
       8,     9,   238,     5,    84,     7,     8,   162,   166,   170,
     174,     4,   176,   180,   184,   188,   192,   196,   200,     4,
     202,     5,   206,   207,   121,   430,   431,   432,     7,     7,
       7,    39,   291,     8,     9,   296,    16,   300,    17,   306,
      17,   312,    17,   318,    17,   324,    18,   330,    18,   345,
      18,   360,    18,   375,    17,   390,    17,   396,    25,   402,
      15,   408,     4,    86,     7,     8,   227,     5,     6,    78,
     232,     5,     6,    80,   237,     5,     6,    82,   242,     5,
     246,   247,    54,    56,    58,     7,    60,    62,    64,    66,
      68,    70,     7,    72,     7,    74,    75,   208,    52,   129,
     489,   490,    30,   433,     5,     5,     5,     3,     8,     9,
     293,     4,    90,     7,     8,     7,     8,     7,     8,     7,
       8,     7,     8,     7,     8,     7,     8,     7,     8,     7,
       8,     7,     8,     7,     8,     7,     8,     7,     8,   267,
       5,   271,   272,     7,    78,    78,     7,    80,    80,     7,
      82,    82,    84,     7,    74,    75,   248,   209,   137,   549,
     550,    31,   491,     7,     8,     9,   434,     7,     7,     7,
     292,     5,     6,    88,   297,     5,   301,     5,   307,     5,
     313,     5,   319,     5,   325,     5,   331,     5,   346,     5,
     361,     5,   376,     5,   391,     5,   397,     5,   403,     5,
     409,   410,    86,     7,    74,    75,   273,   249,   210,   145,
     609,   610,    32,   551,     7,     8,     9,   492,     5,   123,
     435,     7,    88,    88,    90,     7,    61,    92,   302,     7,
      94,    97,   308,     7,    96,    97,   314,     7,    97,   102,
     320,     7,    97,   104,   326,     7,    99,   110,   332,   333,
       7,    99,   112,   347,   348,     7,    99,   114,   362,   363,
       7,    99,   116,   377,   378,     7,    97,   108,   392,     7,
      97,   106,   398,     7,   118,   119,   404,     7,    74,    75,
     411,   274,   250,     8,     9,    36,    38,    40,   211,   212,
     214,   216,   218,    26,   611,     7,     8,     9,   552,     5,
     131,   493,     7,    33,   436,   127,   446,     8,     8,     8,
       8,     8,   334,   349,   364,   379,     8,     8,     8,   412,
     275,     8,     9,    36,    38,    40,   251,   252,   254,   256,
     258,    76,     3,     3,     3,     7,     8,     5,   139,   553,
       7,    34,   494,   135,   504,     7,     8,    33,   447,   457,
       4,     4,     4,     4,     4,     8,     9,    19,    20,    21,
     335,   336,   338,   340,   342,     8,     9,    19,    20,    21,
     350,   351,   353,   355,   357,     8,     9,    19,    20,    21,
     365,   366,   368,   370,   372,     8,     9,    19,    20,    21,
     380,   381,   383,   385,   387,     4,     4,     4,   413,     8,
       9,    36,    38,    40,   276,   277,   279,   281,   283,    76,
       3,     3,     3,   213,   215,   217,     5,   612,     7,    35,
     554,   143,   564,     7,     8,    34,   505,   517,     5,   437,
       7,     8,    75,   122,   458,   459,   303,   309,   315,   321,
     327,   100,     3,     3,     3,   100,     3,     3,     3,   100,
       3,     3,     3,   100,     3,     3,     3,   393,   399,   405,
       8,     9,    36,    38,    40,   414,   415,   417,   419,   421,
      76,     3,     3,     3,   253,   255,   257,     7,     7,     7,
       7,   146,   147,   613,     7,     8,    35,   565,   577,     5,
     495,     7,     8,    75,   130,   518,   519,     7,   124,   125,
     438,   439,     5,   448,   460,    62,    98,    98,    98,    98,
     337,   339,   341,   352,   354,   356,   367,   369,   371,   382,
     384,   386,    98,    98,   120,    76,     3,     3,     3,   278,
     280,   282,     7,     7,     7,   614,     5,   555,     7,     8,
      75,   138,   578,   579,     7,   132,   133,   496,   497,     5,
     506,   520,   440,     7,   125,   128,   449,   450,     8,    22,
      23,    24,    33,    36,    38,    40,   461,   462,   463,   465,
     467,   469,   471,   473,   475,     7,     7,     7,     7,     7,
       7,     7,     7,     7,     7,     7,     7,   416,   418,   420,
       7,     7,     7,   615,     7,   140,   141,   556,   557,     5,
     566,   580,   498,     7,   133,   136,   507,   508,     8,    22,
      23,    24,    34,    36,    38,    40,   521,   522,   523,   525,
     527,   529,   531,   533,   535,     8,     9,    37,    38,   441,
     442,   443,   445,   451,   476,     3,     3,     3,     7,     3,
       3,     3,     7,     7,     7,     8,     9,    22,    23,    24,
      36,    38,    40,   616,   617,   619,   621,   623,   625,   627,
     629,   558,     7,   141,   144,   567,   568,     8,    22,    23,
      24,    35,    36,    38,    40,   581,   582,   583,   585,   587,
     589,   591,   593,   595,     8,     9,    37,    38,   499,   500,
     501,   503,   509,   536,     3,     3,     3,     7,     3,     3,
       3,   126,     7,     3,     8,     9,    37,    38,   452,   453,
     454,   456,    76,   125,   477,   478,   468,   470,   472,     5,
     464,   466,   474,   148,     3,     3,     3,     3,     3,     3,
       8,     9,    37,    38,   559,   560,   561,   563,   569,   596,
       3,     3,     3,     7,     3,     3,     3,   134,     7,     3,
       8,     9,    37,    41,    42,   510,   511,   512,   514,   516,
      76,   133,   537,   538,   528,   530,   532,     5,   524,   526,
     534,     5,   444,   126,     7,     3,   479,     7,     7,     7,
       7,     7,     7,     7,   622,   624,   626,   618,   620,   628,
     142,     7,     3,     8,     9,    37,    41,    42,   570,   571,
     572,   574,   576,    76,   141,   597,   598,   588,   590,   592,
       5,   584,   586,   594,     5,   502,   134,     7,     3,     3,
     539,     7,     7,     7,     7,     7,     7,     7,     7,     7,
       5,   455,     8,     9,    37,    38,    41,    42,   480,   481,
     482,   484,   486,   488,     7,     7,     7,     7,     7,     7,
       5,   562,   142,     7,     3,     3,   599,     7,     7,     7,
       7,     7,     7,     7,     7,     7,     5,   513,   515,     8,
       9,    37,    38,    41,    42,   540,   541,   542,   544,   546,
     548,     7,     7,   126,     7,     3,     3,     3,     7,     7,
       5,   573,   575,     8,     9,    37,    38,    41,    42,   600,
     601,   602,   604,   606,   608,     7,     7,     7,   126,     7,
       3,     3,     3,     5,   483,   485,   487,     7,     7,     7,
     142,     7,     3,     3,     3,     5,   543,   545,   547,     7,
       7,     7,     7,     5,   603,   605,   607,     7,     7,     7,
       7,     7,     7,     7,     7
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (&yylloc, osoption, parserData, YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (&yylval, &yylloc, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval, &yylloc, scanner)
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location, osoption, parserData); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, OSOption *osoption, OSoLParserData *parserData)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, osoption, parserData)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    OSOption *osoption;
    OSoLParserData *parserData;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
  YYUSE (osoption);
  YYUSE (parserData);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, OSOption *osoption, OSoLParserData *parserData)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp, osoption, parserData)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    OSOption *osoption;
    OSoLParserData *parserData;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, osoption, parserData);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, OSOption *osoption, OSoLParserData *parserData)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule, osoption, parserData)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
    OSOption *osoption;
    OSoLParserData *parserData;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       , osoption, parserData);
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule, osoption, parserData); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, OSOption *osoption, OSoLParserData *parserData)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp, osoption, parserData)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
    OSOption *osoption;
    OSoLParserData *parserData;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (osoption);
  YYUSE (parserData);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (OSOption *osoption, OSoLParserData *parserData);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */






/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (OSOption *osoption, OSoLParserData *parserData)
#else
int
yyparse (osoption, parserData)
    OSOption *osoption;
    OSoLParserData *parserData;
#endif
#endif
{
  /* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;
/* Location data for the look-ahead symbol.  */
YYLTYPE yylloc;

  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;

  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[2];

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;
#if YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 0;
#endif

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);
	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);
	YYSTACK_RELOCATE (yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 9:

    {	if (parserData->osolgeneralPresent)
	{	osolerror( NULL, osoption, parserData, "only one <general> element allowed");
	}
	else
	{	parserData->osolgeneralPresent = true;
		osoption->general = new GeneralOption();
	}
}
    break;

  case 26:

    {	if (parserData->serviceURIPresent)
	{	osolerror( NULL, osoption, parserData, "only one <serviceURI> element allowed");
	}
	else
	{	parserData->serviceURIPresent = true;
	}
}
    break;

  case 29:

    {osoption->general->serviceURI = (yyvsp[(2) - (2)].sval);}
    break;

  case 32:

    {	if (parserData->serviceNamePresent)
	{	osolerror( NULL, osoption, parserData, "only one <serviceName> element allowed");
	}
	else
	{	parserData->serviceNamePresent = true;
	}
}
    break;

  case 35:

    {osoption->general->serviceName = (yyvsp[(2) - (2)].sval);}
    break;

  case 38:

    {	if (parserData->instanceNamePresent)
	{	osolerror( NULL, osoption, parserData, "only one <instanceName> element allowed");
	}
	else
	{	parserData->instanceNamePresent = true;
	}
}
    break;

  case 41:

    {osoption->general->instanceName = (yyvsp[(2) - (2)].sval);}
    break;

  case 44:

    {	if (parserData->instanceLocationPresent)
	{	osolerror( NULL, osoption, parserData, "only one <instanceLocation> element allowed");
	}
	else
	{	parserData->instanceLocationPresent = true;
		osoption->general->instanceLocation = new InstanceLocationOption();
		osoption->general->instanceLocation->locationType = "local";
	}
}
    break;

  case 46:

    {	if ( (strncmp((yyvsp[(2) - (2)].sval), "local", 5) == 0) || (strncmp((yyvsp[(2) - (2)].sval), "http", 4) == 0) || (strncmp((yyvsp[(2) - (2)].sval), "ftp", 3) == 0) )
		osoption->general->instanceLocation->locationType = (yyvsp[(2) - (2)].sval);
	else
		osolerror( NULL, osoption, parserData, "Not a valid locationType");
}
    break;

  case 51:

    {osoption->general->instanceLocation->value = (yyvsp[(1) - (1)].sval);}
    break;

  case 53:

    {	if (parserData->jobIDPresent)
	{	osolerror( NULL, osoption, parserData, "only one <jobID> element allowed");
	}
	else
	{	parserData->jobIDPresent = true;
	}
}
    break;

  case 56:

    {osoption->general->jobID = (yyvsp[(2) - (2)].sval);}
    break;

  case 59:

    {	if (parserData->solverToInvokePresent)
	{	osolerror( NULL, osoption, parserData, "only one <solverToInvoke> element allowed");
	}
	else
	{	parserData->solverToInvokePresent = true;
	}
}
    break;

  case 62:

    {osoption->general->solverToInvoke = (yyvsp[(2) - (2)].sval);}
    break;

  case 65:

    {	if (parserData->licensePresent)
	{	osolerror( NULL, osoption, parserData, "only one <license> element allowed");
	}
	else
	{	parserData->licensePresent = true;	
	}
}
    break;

  case 68:

    {osoption->general->license = (yyvsp[(2) - (2)].sval);}
    break;

  case 71:

    {	if (parserData->usernamePresent)
	{	osolerror( NULL, osoption, parserData, "only one <userName> element allowed");
	}
	else
	{	parserData->usernamePresent = true;
	}
}
    break;

  case 74:

    {osoption->general->userName = (yyvsp[(2) - (2)].sval);}
    break;

  case 77:

    {	if (parserData->passwordPresent)
	{	osolerror( NULL, osoption, parserData, "only one <password> element allowed");
	}
	else
	{	parserData->passwordPresent = true;
	}
}
    break;

  case 80:

    {osoption->general->password = (yyvsp[(2) - (2)].sval);}
    break;

  case 83:

    {	if (parserData->contactPresent)
	{	osolerror( NULL, osoption, parserData, "only one <contact> element allowed");
	}
	else
	{	parserData->contactPresent = true;
		osoption->general->contact = new ContactOption();
		osoption->general->contact->transportType = "osp";
	}
}
    break;

  case 85:

    {	if ( (strncmp((yyvsp[(2) - (2)].sval),"osp",3) == 0) || (strncmp((yyvsp[(2) - (2)].sval),"smtp",4) == 0) || (strncmp((yyvsp[(2) - (2)].sval),"http", 4) == 0) || 
						     (strncmp((yyvsp[(2) - (2)].sval),"ftp", 3) == 0) || (strncmp((yyvsp[(2) - (2)].sval),"other",5) == 0) )
		osoption->general->contact->transportType = (yyvsp[(2) - (2)].sval);
	else
		osolerror( NULL, osoption, parserData, "Not a valid transport type");
}
    break;

  case 90:

    {osoption->general->contact->value = (yyvsp[(1) - (1)].sval);}
    break;

  case 92:

    {	if (parserData->otherGeneralOptionsPresent)
	{	osolerror( NULL, osoption, parserData, "only one <otherOptions> element allowed");
	}
	else
	{	parserData->otherGeneralOptionsPresent = true;
		osoption->general->otherOptions = new OtherOptions();
	}
}
    break;

  case 93:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror( NULL, osoption, parserData, "Number of <other> elements cannot be negative");
	osoption->general->otherOptions->numberOfOtherOptions = (yyvsp[(3) - (4)].ival);
	osoption->general->otherOptions->other = new OtherOption*[(yyvsp[(3) - (4)].ival)];
	for (int i=0; i < (yyvsp[(3) - (4)].ival); i++) osoption->general->otherOptions->other[i] = new OtherOption();
}
    break;

  case 94:

    {	if (parserData->numberOfOtherGeneralOptions != osoption->general->otherOptions->numberOfOtherOptions)
		osolerror (NULL, osoption, parserData, "wrong number of other options in <general> element");
}
    break;

  case 97:

    {	if (parserData->numberOfOtherGeneralOptions >= osoption->general->otherOptions->numberOfOtherOptions)
		{	osolerror (NULL, osoption, parserData, "too many other options in <general> element");
		};
	}
    break;

  case 98:

    {	if (!parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "name attribute must be present");
	/* reset defaults for the next option */
	parserData->otherOptionNamePresent = false;
	parserData->otherOptionValuePresent = false;
	parserData->otherOptionDescriptionPresent = false;
	parserData->numberOfOtherGeneralOptions++;
}
    break;

  case 104:

    {	if (parserData->otherOptionNamePresent)
	{	osolerror( NULL, osoption, parserData, "only one name attribute allowed");
	}
	else
	{	parserData->otherOptionNamePresent = true;
		osoption->general->otherOptions->other[parserData->numberOfOtherGeneralOptions]->name = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 106:

    {	if (parserData->otherOptionValuePresent)
	{	osolerror( NULL, osoption, parserData, "only one value attribute allowed");
	}
	else
	{	parserData->otherOptionValuePresent = true;
		osoption->general->otherOptions->other[parserData->numberOfOtherGeneralOptions]->value = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 108:

    {	if (parserData->otherOptionDescriptionPresent)
	{	osolerror( NULL, osoption, parserData, "only one description attribute allowed");
	}
	else
	{	parserData->otherOptionDescriptionPresent = true;
		osoption->general->otherOptions->other[parserData->numberOfOtherGeneralOptions]->description = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 114:

    {	if (parserData->osolsystemPresent)
	{	osolerror( NULL, osoption, parserData, "only one <system> element allowed");
	}
	else
	{	parserData->osolsystemPresent = true;
		osoption->system = new SystemOption();
	}
}
    break;

  case 125:

    {	if (parserData->minDiskSpacePresent)
	{	osolerror( NULL, osoption, parserData, "only one <minDiskSpace> element allowed");
	}
	else
	{	parserData-> minDiskSpacePresent = true;
		osoption->system->minDiskSpace = new MinDiskSpace();
		osoption->system->minDiskSpace->unit = "byte";
	}
}
    break;

  case 127:

    {	if ( (strncmp((yyvsp[(2) - (2)].sval),"byte",4) == 0) || (strncmp((yyvsp[(2) - (2)].sval),"kilobyte",8) == 0) || (strncmp((yyvsp[(2) - (2)].sval),"megabyte",8) == 0) || 
						      (strncmp((yyvsp[(2) - (2)].sval),"terabyte",8) == 0) || (strncmp((yyvsp[(2) - (2)].sval),"petabyte",8) == 0) )
		osoption->system->minDiskSpace->unit = (yyvsp[(2) - (2)].sval);
	else
		osolerror( NULL, osoption, parserData, "Not a valid unit");
}
    break;

  case 131:

    {	if ((yyvsp[(2) - (3)].dval) < 0)
		osolerror( NULL, osoption, parserData, "minDiskSpace cannot be negative");
	osoption->system->minDiskSpace->value = (yyvsp[(2) - (3)].dval);
}
    break;

  case 132:

    {	if ((yyvsp[(2) - (3)].ival) < 0)
		osolerror( NULL, osoption, parserData, "minDiskSpace cannot be negative");
	osoption->system->minDiskSpace->value = (yyvsp[(2) - (3)].ival);
}
    break;

  case 134:

    {	if (parserData->minMemorySizePresent)
	{	osolerror( NULL, osoption, parserData, "only one <minMemorySize> element allowed");
	}
	else
	{	parserData-> minMemorySizePresent = true;
		osoption->system->minMemorySize = new MinMemorySize();
		osoption->system->minMemorySize->unit = "byte";
	}
}
    break;

  case 136:

    {	if ( (strncmp((yyvsp[(2) - (2)].sval),"byte",4) == 0) || (strncmp((yyvsp[(2) - (2)].sval),"kilobyte",8) == 0) || (strncmp((yyvsp[(2) - (2)].sval),"megabyte",8) == 0) || 
						      (strncmp((yyvsp[(2) - (2)].sval),"terabyte",8) == 0) || (strncmp((yyvsp[(2) - (2)].sval),"petabyte",8) == 0) )
		osoption->system->minMemorySize->unit = (yyvsp[(2) - (2)].sval);
	else
		osolerror( NULL, osoption, parserData, "Not a valid unit");
}
    break;

  case 140:

    {	if ((yyvsp[(2) - (3)].dval) < 0)
		osolerror( NULL, osoption, parserData, "minMemorySize cannot be negative");
	osoption->system->minMemorySize->value = (yyvsp[(2) - (3)].dval);
}
    break;

  case 141:

    {	if ((yyvsp[(2) - (3)].ival) < 0)
		osolerror( NULL, osoption, parserData, "minMemorySize cannot be negative");
	osoption->system->minMemorySize->value = (yyvsp[(2) - (3)].ival);
}
    break;

  case 143:

    {	if (parserData->minCPUSpeedPresent)
	{	osolerror( NULL, osoption, parserData, "only one <minCPUSpeed> element allowed");
	}
	else
	{	parserData-> minCPUSpeedPresent = true;
		osoption->system->minCPUSpeed = new MinCPUSpeed();
		osoption->system->minCPUSpeed->unit = "hertz";
	}
}
    break;

  case 145:

    {	if ( (strncmp((yyvsp[(2) - (2)].sval),    "hertz",5) == 0) || (strncmp((yyvsp[(2) - (2)].sval),"kilohertz",9) == 0) || (strncmp((yyvsp[(2) - (2)].sval),"megahertz",9) == 0) || 
	     (strncmp((yyvsp[(2) - (2)].sval),"gigahertz",9) == 0) || (strncmp((yyvsp[(2) - (2)].sval),"terahertz",9) == 0) || (strncmp((yyvsp[(2) - (2)].sval),"petahertz",9) == 0) ||
	     (strncmp((yyvsp[(2) - (2)].sval),    "flops",5) == 0) || (strncmp((yyvsp[(2) - (2)].sval),"kiloflops",9) == 0) || (strncmp((yyvsp[(2) - (2)].sval),"megaflops",9) == 0) || 
	     (strncmp((yyvsp[(2) - (2)].sval),"gigaflops",9) == 0) || (strncmp((yyvsp[(2) - (2)].sval),"teraflops",9) == 0) || (strncmp((yyvsp[(2) - (2)].sval),"petahertz",9) == 0) ) 
		osoption->system->minCPUSpeed->unit = (yyvsp[(2) - (2)].sval);
	else
		osolerror( NULL, osoption, parserData, "Not a valid unit");
}
    break;

  case 149:

    {	if ((yyvsp[(2) - (3)].dval) < 0)
		osolerror( NULL, osoption, parserData, "minCPUSpeed cannot be negative");
	osoption->system->minCPUSpeed->value = (yyvsp[(2) - (3)].dval);
}
    break;

  case 150:

    {	if ((yyvsp[(2) - (3)].ival) < 0)
		osolerror( NULL, osoption, parserData, "minCPUSpeed cannot be negative");
	osoption->system->minCPUSpeed->value = (yyvsp[(2) - (3)].ival);
}
    break;

  case 152:

    {	if (parserData->minCPUNumberPresent)
	{	osolerror( NULL, osoption, parserData, "only one <minCPUNumber> element allowed");
	}
	else
	{	parserData->minCPUNumberPresent = true;
	}
}
    break;

  case 155:

    {	if ((yyvsp[(2) - (2)].ival) < 0)
		osolerror( NULL, osoption, parserData, "minCPUNumber cannot be negative");
	osoption->system->minCPUNumber = (yyvsp[(2) - (2)].ival);
}
    break;

  case 158:

    {	if (parserData->otherSystemOptionsPresent)
	{	osolerror( NULL, osoption, parserData, "only one <otherOptions> element allowed");
	}
	else
	{	parserData->otherSystemOptionsPresent = true;
		osoption->system->otherOptions = new OtherOptions();
	}
}
    break;

  case 159:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror( NULL, osoption, parserData, "Number of <other> elements cannot be negative");
	osoption->system->otherOptions->numberOfOtherOptions = (yyvsp[(3) - (4)].ival);
	osoption->system->otherOptions->other = new OtherOption*[(yyvsp[(3) - (4)].ival)];
	for (int i=0; i < (yyvsp[(3) - (4)].ival); i++) osoption->system->otherOptions->other[i] = new OtherOption();
}
    break;

  case 160:

    {	if (parserData->numberOfOtherSystemOptions != osoption->system->otherOptions->numberOfOtherOptions)
		osolerror (NULL, osoption, parserData, "wrong number of other options in <system> element");
}
    break;

  case 163:

    {	if (parserData->numberOfOtherSystemOptions >= osoption->system->otherOptions->numberOfOtherOptions)
		{	osolerror (NULL, osoption, parserData, "too many other options in <system> element");
		};
	}
    break;

  case 164:

    {	if (!parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "name attribute must be present");
	/* reset defaults for the next option */
	parserData->otherOptionNamePresent = false;
	parserData->otherOptionValuePresent = false;
	parserData->otherOptionDescriptionPresent = false;
	parserData->numberOfOtherSystemOptions++;
}
    break;

  case 170:

    {	if (parserData->otherOptionNamePresent)
	{	osolerror( NULL, osoption, parserData, "only one name attribute allowed");
	}
	else
	{	parserData->otherOptionNamePresent = true;
		osoption->system->otherOptions->other[parserData->numberOfOtherSystemOptions]->name = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 172:

    {	if (parserData->otherOptionValuePresent)
	{	osolerror( NULL, osoption, parserData, "only one value attribute allowed");
	}
	else
	{	parserData->otherOptionValuePresent = true;
		osoption->system->otherOptions->other[parserData->numberOfOtherSystemOptions]->value = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 174:

    {	if (parserData->otherOptionDescriptionPresent)
	{	osolerror( NULL, osoption, parserData, "only one description attribute allowed");
	}
	else
	{	parserData->otherOptionDescriptionPresent = true;
		osoption->system->otherOptions->other[parserData->numberOfOtherSystemOptions]->description = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 180:

    {	if (parserData->osolservicePresent)
	{	osolerror( NULL, osoption, parserData, "only one <service> element allowed");
	}
	else
	{	parserData->osolservicePresent = true;
		osoption->service = new ServiceOption();
	}
}
    break;

  case 188:

    {	if (parserData->serviceTypePresent)
	{	osolerror( NULL, osoption, parserData, "only one <type> element allowed");
	}
	else
	{	parserData->serviceTypePresent = true;
		osoption->service->type = "solver";
	}
}
    break;

  case 191:

    {	if ( (strncmp((yyvsp[(2) - (2)].sval),"solver",6) == 0) || (strncmp((yyvsp[(2) - (2)].sval),"analyzer",   8) == 0) || (strncmp((yyvsp[(2) - (2)].sval),"scheduler",9) == 0) ||
							  (strncmp((yyvsp[(2) - (2)].sval),"simulation",10) == 0) || (strncmp((yyvsp[(2) - (2)].sval),"registry", 8) == 0) ||
							  (strncmp((yyvsp[(2) - (2)].sval),"modeler",    7) == 0) || (strncmp((yyvsp[(2) - (2)].sval),"agent",    5) == 0) ) 
		osoption->service->type = (yyvsp[(2) - (2)].sval);
	else
		osolerror( NULL, osoption, parserData, "Not a valid service type");
}
    break;

  case 194:

    {	if (parserData->otherServiceOptionsPresent)
	{	osolerror( NULL, osoption, parserData, "only one <otherOptions> element allowed");
	}
	else
	{	parserData->otherServiceOptionsPresent = true;
		osoption->service->otherOptions = new OtherOptions();
	}
}
    break;

  case 195:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror( NULL, osoption, parserData, "Number of <other> elements cannot be negative");
	osoption->service->otherOptions->numberOfOtherOptions = (yyvsp[(3) - (4)].ival);
	osoption->service->otherOptions->other = new OtherOption*[(yyvsp[(3) - (4)].ival)];
	for (int i=0; i < (yyvsp[(3) - (4)].ival); i++) osoption->service->otherOptions->other[i] = new OtherOption();
}
    break;

  case 196:

    {	if (parserData->numberOfOtherServiceOptions != osoption->service->otherOptions->numberOfOtherOptions)
		osolerror (NULL, osoption, parserData, "wrong number of other options in <service> element");
}
    break;

  case 199:

    {	if (parserData->numberOfOtherServiceOptions >= osoption->service->otherOptions->numberOfOtherOptions)
		{	osolerror (NULL, osoption, parserData, "too many other options in <service> element");
		};
	}
    break;

  case 200:

    {	if (!parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "name attribute must be present");
	/* reset defaults for the next option */
	parserData->otherOptionNamePresent = false;
	parserData->otherOptionValuePresent = false;
	parserData->otherOptionDescriptionPresent = false;
	parserData->numberOfOtherServiceOptions++;
}
    break;

  case 206:

    {	if (parserData->otherOptionNamePresent)
	{	osolerror( NULL, osoption, parserData, "only one name attribute allowed");
	}
	else
	{	parserData->otherOptionNamePresent = true;
		osoption->service->otherOptions->other[parserData->numberOfOtherServiceOptions]->name = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 208:

    {	if (parserData->otherOptionValuePresent)
	{	osolerror( NULL, osoption, parserData, "only one value attribute allowed");
	}
	else
	{	parserData->otherOptionValuePresent = true;
		osoption->service->otherOptions->other[parserData->numberOfOtherServiceOptions]->value = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 210:

    {	if (parserData->otherOptionDescriptionPresent)
	{	osolerror( NULL, osoption, parserData, "only one description attribute allowed");
	}
	else
	{	parserData->otherOptionDescriptionPresent = true;
		osoption->service->otherOptions->other[parserData->numberOfOtherServiceOptions]->description = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 215:

    {	if (parserData->osoljobPresent)
	{	osolerror( NULL, osoption, parserData, "only one <job> element allowed");
	}
	else
	{	parserData->osoljobPresent = true;
		osoption->job = new JobOption();
	}
}
    break;

  case 236:

    {	if (parserData->maxTimePresent)
	{	osolerror( NULL, osoption, parserData, "only one <maxTime> element allowed");
	}
	else
	{	parserData-> maxTimePresent = true;
		osoption->job->maxTime = new MaxTime();
		osoption->job->maxTime->unit = "second"; 
	}
}
    break;

  case 238:

    {	if ( (strncmp((yyvsp[(2) - (2)].sval),"second",6) == 0) || (strncmp((yyvsp[(2) - (2)].sval),"minute",6) == 0) || (strncmp((yyvsp[(2) - (2)].sval),"hour",4) == 0) ||
							  (strncmp((yyvsp[(2) - (2)].sval),"day",   3) == 0) || (strncmp((yyvsp[(2) - (2)].sval),"week",4) == 0) ||
							  (strncmp((yyvsp[(2) - (2)].sval),"month", 5) == 0) || (strncmp((yyvsp[(2) - (2)].sval),"year",4) == 0) ) 
                osoption->job->maxTime->unit = (yyvsp[(2) - (2)].sval);
	else
		osolerror( NULL, osoption, parserData, "Not a valid time unit");
}
    break;

  case 242:

    {	if ((yyvsp[(2) - (3)].dval) < 0)
		osolerror( NULL, osoption, parserData, "maxTime cannot be negative");
	osoption->job->maxTime->value = (yyvsp[(2) - (3)].dval);
}
    break;

  case 243:

    {	if ((yyvsp[(2) - (3)].ival) < 0)
		osolerror( NULL, osoption, parserData, "maxTime cannot be negative");
	osoption->job->maxTime->value = (yyvsp[(2) - (3)].ival);
}
    break;

  case 245:

    {	if (parserData->scheduledStartTimePresent)
	{	osolerror( NULL, osoption, parserData, "only one <scheduledStartTime> element allowed");
	}
	else
	{	parserData->scheduledStartTimePresent = true;
		osoption->job->scheduledStartTime = "1970-01-01T00:00:00-00:00";
	}
}
    break;

  case 248:

    {osoption->job->scheduledStartTime = (yyvsp[(2) - (2)].sval);}
    break;

  case 251:

    {	if (parserData->dependenciesPresent)
	{	osolerror( NULL, osoption, parserData, "only one <dependencies> element allowed");
	}
	else
	{	parserData->dependenciesPresent = true;
		osoption->job->dependencies = new JobDependencies();
	}
}
    break;

  case 252:

    {	if ((yyvsp[(3) - (4)].ival) < 1)
		osolerror( NULL, osoption, parserData, "Number of job IDs must be at least 1");
	osoption->job->dependencies->numberOfJobIDs = (yyvsp[(3) - (4)].ival);
	osoption->job->dependencies->jobID = new std::string[(yyvsp[(3) - (4)].ival)];
}
    break;

  case 255:

    {
	if (parserData->numberOfDependencies >= osoption->job->dependencies->numberOfJobIDs)
	{	osolerror (NULL, osoption, parserData, "too many job IDs in <dependencies> element");
	}
	else
	{	osoption->job->dependencies->jobID[parserData->numberOfDependencies] = (yyvsp[(3) - (3)].sval);
		parserData->numberOfDependencies++;
	};
}
    break;

  case 258:

    {	if (parserData->requiredDirectoriesPresent)
	{	osolerror( NULL, osoption, parserData, "only one <requiredDirectories> element allowed");
	}
	else
	{	parserData->requiredDirectoriesPresent = true;
		osoption->job->requiredDirectories = new DirectoriesAndFiles();
	}
}
    break;

  case 259:

    {	if ((yyvsp[(3) - (4)].ival) < 1)
		osolerror( NULL, osoption, parserData, "Number of paths must be at least 1");
	osoption->job->requiredDirectories->numberOfPaths = (yyvsp[(3) - (4)].ival);
	osoption->job->requiredDirectories->path = new std::string[(yyvsp[(3) - (4)].ival)];
}
    break;

  case 262:

    {
	if (parserData->numberOfRequiredDirectories >= osoption->job->requiredDirectories->numberOfPaths)
	{	osolerror (NULL, osoption, parserData, "too many job IDs in <requiredDirectories> element");
	}
	else
	{	osoption->job->requiredDirectories->path[parserData->numberOfRequiredDirectories] = (yyvsp[(3) - (3)].sval);
		parserData->numberOfRequiredDirectories++;
	};
}
    break;

  case 265:

    {	if (parserData->requiredFilesPresent)
	{	osolerror( NULL, osoption, parserData, "only one <requiredFiles> element allowed");
	}
	else
	{	parserData->requiredFilesPresent = true;
		osoption->job->requiredFiles = new DirectoriesAndFiles();
	}
}
    break;

  case 266:

    {	if ((yyvsp[(3) - (4)].ival) < 1)
		osolerror( NULL, osoption, parserData, "Number of paths must be at least 1");
	osoption->job->requiredFiles->numberOfPaths = (yyvsp[(3) - (4)].ival);
	osoption->job->requiredFiles->path = new std::string[(yyvsp[(3) - (4)].ival)];
}
    break;

  case 269:

    {
	if (parserData->numberOfRequiredFiles >= osoption->job->requiredFiles->numberOfPaths)
	{	osolerror (NULL, osoption, parserData, "too many job IDs in <requiredFiles> element");
	}
	else
	{	osoption->job->requiredFiles->path[parserData->numberOfRequiredFiles] = (yyvsp[(3) - (3)].sval);
		parserData->numberOfRequiredFiles++;
	};
}
    break;

  case 272:

    {	if (parserData->directoriesToMakePresent)
	{	osolerror( NULL, osoption, parserData, "only one <directoriesToMake> element allowed");
	}
	else
	{	parserData->directoriesToMakePresent = true;
		osoption->job->directoriesToMake = new DirectoriesAndFiles();
	}
}
    break;

  case 273:

    {	if ((yyvsp[(3) - (4)].ival) < 1)
		osolerror( NULL, osoption, parserData, "Number of paths must be at least 1");
	osoption->job->directoriesToMake->numberOfPaths = (yyvsp[(3) - (4)].ival);
	osoption->job->directoriesToMake->path = new std::string[(yyvsp[(3) - (4)].ival)];
}
    break;

  case 276:

    {	if (parserData->numberOfDirectoriesToMake >= osoption->job->directoriesToMake->numberOfPaths)
	{	osolerror (NULL, osoption, parserData, "too many job IDs in <directoriesToMake> element");
	}
	else
	{	osoption->job->directoriesToMake->path[parserData->numberOfDirectoriesToMake] = (yyvsp[(3) - (3)].sval);
		parserData->numberOfDirectoriesToMake++;
	};
}
    break;

  case 279:

    {	if (parserData->filesToCreatePresent)
	{	osolerror( NULL, osoption, parserData, "only one <filesToCreate> element allowed");
	}
	else
	{	parserData->filesToCreatePresent = true;
		osoption->job->filesToCreate = new DirectoriesAndFiles();
	}
}
    break;

  case 280:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror( NULL, osoption, parserData, "Number of paths cannot be negative");
	osoption->job->filesToCreate->numberOfPaths = (yyvsp[(3) - (4)].ival);
	osoption->job->filesToCreate->path = new std::string[(yyvsp[(3) - (4)].ival)];
}
    break;

  case 283:

    {	if (parserData->numberOfFilesToCreate >= osoption->job->filesToCreate->numberOfPaths)
	{	osolerror (NULL, osoption, parserData, "too many job IDs in <filesToCreate> element");
	}
	else
	{	osoption->job->filesToCreate->path[parserData->numberOfFilesToCreate] = (yyvsp[(3) - (3)].sval);
		parserData->numberOfFilesToCreate++;
	};
}
    break;

  case 286:

    {	if (parserData->inputDirectoriesToMovePresent)
	{	osolerror( NULL, osoption, parserData, "only one <inputDirectoriesToMove> element allowed");
	}
	else
	{	parserData->inputDirectoriesToMovePresent = true;
		osoption->job->inputDirectoriesToMove = new PathPairs();
	}
}
    break;

  case 287:

    {	if ((yyvsp[(3) - (4)].ival) <= 0)
		osolerror (NULL, osoption, parserData, "Require positive number of directories to move");
	osoption->job->inputDirectoriesToMove->numberOfPathPairs = (yyvsp[(3) - (4)].ival);
	osoption->job->inputDirectoriesToMove->pathPair = new PathPair*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->job->inputDirectoriesToMove->pathPair[i] = new PathPair();
}
    break;

  case 290:

    {	if (!parserData->pathPairFromPresent)
		osolerror (NULL, osoption, parserData, "\"from\" attribute must be present");
	if (!parserData->pathPairToPresent)
		osolerror (NULL, osoption, parserData, "\"to\" attribute must be present");
	/* reset defaults for the next option */
	parserData->pathPairFromPresent= false;
	parserData->pathPairToPresent= false;
	parserData->pathPairMakeCopyPresent= false;
	parserData->numberOfInputDirectoriesToMove++;
}
    break;

  case 291:

    {	if (parserData->numberOfInputDirectoriesToMove >= osoption->job->inputDirectoriesToMove->numberOfPathPairs)
	{	osolerror (NULL, osoption, parserData, "too many path pairs in <inputDirectoriesToMove> element");
	};
}
    break;

  case 297:

    {	if (parserData->pathPairFromPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"from\" attribute allowed");
	}
	else
	{	parserData->pathPairFromPresent = true;
		osoption->job->inputDirectoriesToMove->pathPair[parserData->numberOfInputDirectoriesToMove]->from = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 299:

    {	if (parserData->pathPairToPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"to\" attribute allowed");
	}
	else
	{	parserData->pathPairToPresent = true;
		osoption->job->inputDirectoriesToMove->pathPair[parserData->numberOfInputDirectoriesToMove]->to = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 301:

    {	if (parserData->pathPairMakeCopyPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"makeCopy\" attribute allowed");
	}
	else
	{	parserData->pathPairMakeCopyPresent = true;
		if ((yyvsp[(2) - (2)].sval) == "true")
			osoption->job->inputDirectoriesToMove->pathPair[parserData->numberOfInputDirectoriesToMove]->makeCopy = true;
	}
}
    break;

  case 306:

    {	if (parserData->inputFilesToMovePresent)
	{	osolerror( NULL, osoption, parserData, "only one <inputFilesToMove> element allowed");
	}
	else
	{	parserData->inputFilesToMovePresent = true;
		osoption->job->inputFilesToMove = new PathPairs();
	}
}
    break;

  case 307:

    {	if ((yyvsp[(3) - (4)].ival) <= 0)
		osolerror (NULL, osoption, parserData, "Require positive number of files to move");
	osoption->job->inputFilesToMove->numberOfPathPairs = (yyvsp[(3) - (4)].ival);
	osoption->job->inputFilesToMove->pathPair = new PathPair*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++) osoption->job->inputFilesToMove->pathPair[i] = new PathPair();
}
    break;

  case 310:

    {	if (!parserData->pathPairFromPresent)
		osolerror (NULL, osoption, parserData, "\"from\" attribute must be present");
	if (!parserData->pathPairToPresent)
		osolerror (NULL, osoption, parserData, "\"to\" attribute must be present");
	/* reset defaults for the next option */
	parserData->pathPairFromPresent= false;
	parserData->pathPairToPresent= false;
	parserData->pathPairMakeCopyPresent= false;
	parserData->numberOfInputFilesToMove++;
}
    break;

  case 311:

    {	if (parserData->numberOfInputFilesToMove >= osoption->job->inputFilesToMove->numberOfPathPairs)
	{	osolerror (NULL, osoption, parserData, "too many path pairs in <inputFilesToMove> element");
	};
}
    break;

  case 317:

    {	if (parserData->pathPairFromPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"from\" attribute allowed");
	}
	else
	{	parserData->pathPairFromPresent = true;
		osoption->job->inputFilesToMove->pathPair[parserData->numberOfInputFilesToMove]->from = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 319:

    {	if (parserData->pathPairToPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"to\" attribute allowed");
	}
	else
	{	parserData->pathPairToPresent = true;
		osoption->job->inputFilesToMove->pathPair[parserData->numberOfInputFilesToMove]->to = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 321:

    {	if (parserData->pathPairMakeCopyPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"makeCopy\" attribute allowed");
	}
	else
	{	parserData->pathPairMakeCopyPresent = true;
		if ((yyvsp[(2) - (2)].sval) == "true")
			osoption->job->inputFilesToMove->pathPair[parserData->numberOfInputFilesToMove]->makeCopy = true;
	}
}
    break;

  case 326:

    {	if (parserData->outputDirectoriesToMovePresent)
	{	osolerror( NULL, osoption, parserData, "only one <outputDirectoriesToMove> element allowed");
	}
	else
	{	parserData->outputDirectoriesToMovePresent = true;
		osoption->job->outputDirectoriesToMove = new PathPairs();
	}
}
    break;

  case 327:

    {	if ((yyvsp[(3) - (4)].ival) <= 0)
		osolerror (NULL, osoption, parserData, "Require positive number of directories to move");
	osoption->job->outputDirectoriesToMove->numberOfPathPairs = (yyvsp[(3) - (4)].ival);
	osoption->job->outputDirectoriesToMove->pathPair = new PathPair*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->job->outputDirectoriesToMove->pathPair[i] = new PathPair();
}
    break;

  case 330:

    {	if (!parserData->pathPairFromPresent)
		osolerror (NULL, osoption, parserData, "\"from\" attribute must be present");
	if (!parserData->pathPairToPresent)
		osolerror (NULL, osoption, parserData, "\"to\" attribute must be present");
	/* reset defaults for the next option */
	parserData->pathPairFromPresent= false;
	parserData->pathPairToPresent= false;
	parserData->pathPairMakeCopyPresent= false;
	parserData->numberOfOutputDirectoriesToMove++;
}
    break;

  case 331:

    {	if (parserData->numberOfOutputDirectoriesToMove >= osoption->job->outputDirectoriesToMove->numberOfPathPairs)
	{	osolerror (NULL, osoption, parserData, "too many path pairs in <outputDirectoriesToMove> element");
	};
}
    break;

  case 337:

    {	if (parserData->pathPairFromPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"from\" attribute allowed");
	}
	else
	{	parserData->pathPairFromPresent = true;
		osoption->job->outputDirectoriesToMove->pathPair[parserData->numberOfOutputDirectoriesToMove]->from = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 339:

    {	if (parserData->pathPairToPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"to\" attribute allowed");
	}
	else
	{	parserData->pathPairToPresent = true;
		osoption->job->outputDirectoriesToMove->pathPair[parserData->numberOfOutputDirectoriesToMove]->to = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 341:

    {	if (parserData->pathPairMakeCopyPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"makeCopy\" attribute allowed");
	}
	else
	{	parserData->pathPairMakeCopyPresent = true;
		if ((yyvsp[(2) - (2)].sval) == "true")
			osoption->job->outputDirectoriesToMove->pathPair[parserData->numberOfOutputDirectoriesToMove]->makeCopy = true;
	}
}
    break;

  case 346:

    {	if (parserData->outputFilesToMovePresent)
	{	osolerror( NULL, osoption, parserData, "only one <outputFilesToMove> element allowed");
	}
	else
	{	parserData->outputFilesToMovePresent = true;
		osoption->job->outputFilesToMove = new PathPairs();
	}
}
    break;

  case 347:

    {	if ((yyvsp[(3) - (4)].ival) <= 0)
		osolerror (NULL, osoption, parserData, "Require positive number of files to move");
	osoption->job->outputFilesToMove->numberOfPathPairs = (yyvsp[(3) - (4)].ival);
	osoption->job->outputFilesToMove->pathPair = new PathPair*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->job->outputFilesToMove->pathPair[i] = new PathPair();}
    break;

  case 350:

    {	if (!parserData->pathPairFromPresent)
		osolerror (NULL, osoption, parserData, "\"from\" attribute must be present");
	if (!parserData->pathPairToPresent)
		osolerror (NULL, osoption, parserData, "\"to\" attribute must be present");
	/* reset defaults for the next option */
	parserData->pathPairFromPresent= false;
	parserData->pathPairToPresent= false;
	parserData->pathPairMakeCopyPresent= false;
	parserData->numberOfOutputFilesToMove++;
}
    break;

  case 351:

    {	if (parserData->numberOfOutputFilesToMove >= osoption->job->outputFilesToMove->numberOfPathPairs)
	{	osolerror (NULL, osoption, parserData, "too many path pairs in <outputFilesToMove> element");
	};
}
    break;

  case 357:

    {	if (parserData->pathPairFromPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"from\" attribute allowed");
	}
	else
	{	parserData->pathPairFromPresent = true;
		osoption->job->outputFilesToMove->pathPair[parserData->numberOfOutputFilesToMove]->from = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 359:

    {	if (parserData->pathPairToPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"to\" attribute allowed");
	}
	else
	{	parserData->pathPairToPresent = true;
		osoption->job->outputFilesToMove->pathPair[parserData->numberOfOutputFilesToMove]->to = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 361:

    {	if (parserData->pathPairMakeCopyPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"makeCopy\" attribute allowed");
	}
	else
	{	parserData->pathPairMakeCopyPresent = true;
		if ((yyvsp[(2) - (2)].sval) == "true")
			osoption->job->outputFilesToMove->pathPair[parserData->numberOfOutputFilesToMove]->makeCopy = true;
	}
}
    break;

  case 366:

    {	if (parserData->filesToDeletePresent)
	{	osolerror( NULL, osoption, parserData, "only one <filesToDelete> element allowed");
	}
	else
	{	parserData->filesToDeletePresent = true;
		osoption->job->filesToDelete = new DirectoriesAndFiles();
	}
}
    break;

  case 367:

    {	if ((yyvsp[(3) - (4)].ival) < 1)
		osolerror( NULL, osoption, parserData, "Number of paths must be at least 1");
	osoption->job->filesToDelete->numberOfPaths = (yyvsp[(3) - (4)].ival);
	osoption->job->filesToDelete->path = new std::string[(yyvsp[(3) - (4)].ival)];
}
    break;

  case 370:

    {	if (parserData->numberOfFilesToDelete >= osoption->job->filesToDelete->numberOfPaths)
	{	osolerror (NULL, osoption, parserData, "too many job IDs in <filesToDelete> element");
	}
	else
	{	osoption->job->filesToDelete->path[parserData->numberOfFilesToDelete] = (yyvsp[(3) - (3)].sval);
		parserData->numberOfFilesToDelete++;
	};
}
    break;

  case 373:

    {	if (parserData->directoriesToDeletePresent)
	{	osolerror( NULL, osoption, parserData, "only one <directoriesToDelete> element allowed");
	}
	else
	{	parserData->directoriesToDeletePresent = true;
		osoption->job->directoriesToDelete = new DirectoriesAndFiles();
	}
}
    break;

  case 374:

    {	if ((yyvsp[(3) - (4)].ival) < 1)
		osolerror( NULL, osoption, parserData, "Number of paths must be at least 1");
	osoption->job->directoriesToDelete->numberOfPaths = (yyvsp[(3) - (4)].ival);
	osoption->job->directoriesToDelete->path = new std::string[(yyvsp[(3) - (4)].ival)];
}
    break;

  case 377:

    {	if (parserData->numberOfDirectoriesToDelete >= osoption->job->directoriesToDelete->numberOfPaths)
	{	osolerror (NULL, osoption, parserData, "too many job IDs in <directoriesToDelete> element");
	}
	else
	{	osoption->job->directoriesToDelete->path[parserData->numberOfDirectoriesToDelete] = (yyvsp[(3) - (3)].sval);
		parserData->numberOfDirectoriesToDelete++;
	};
}
    break;

  case 380:

    {	if (parserData->processesToKillPresent)
	{	osolerror( NULL, osoption, parserData, "only one <processesToKill> element allowed");
	}
	else
	{	parserData->processesToKillPresent = true;
		osoption->job->processesToKill = new Processes();
	}
}
    break;

  case 381:

    {	if ((yyvsp[(3) - (4)].ival) < 1)
		osolerror( NULL, osoption, parserData, "Number of job IDs must be at least 1");
	osoption->job->processesToKill->numberOfProcesses = (yyvsp[(3) - (4)].ival);
	osoption->job->processesToKill->process = new std::string[(yyvsp[(3) - (4)].ival)];
}
    break;

  case 384:

    {	if (parserData->numberOfProcessesToKill >= osoption->job->processesToKill->numberOfProcesses)
	{	osolerror (NULL, osoption, parserData, "too many job IDs in <processesToKill> element");
	}
	else
	{	osoption->job->processesToKill->process[parserData->numberOfProcessesToKill] = (yyvsp[(3) - (3)].sval);
		parserData->numberOfProcessesToKill++;
	};
}
    break;

  case 387:

    {	if (parserData->otherJobOptionsPresent)
	{	osolerror( NULL, osoption, parserData, "only one <otherOptions> element allowed");
	}
	else
	{	parserData->otherJobOptionsPresent = true;
		osoption->job->otherOptions = new OtherOptions();
	}
}
    break;

  case 388:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror( NULL, osoption, parserData, "Number of <other> elements cannot be negative");
	osoption->job->otherOptions->numberOfOtherOptions = (yyvsp[(3) - (4)].ival);
	osoption->job->otherOptions->other = new OtherOption*[(yyvsp[(3) - (4)].ival)];
	for (int i=0; i < (yyvsp[(3) - (4)].ival); i++) osoption->job->otherOptions->other[i] = new OtherOption();
}
    break;

  case 389:

    {	if (parserData->numberOfOtherJobOptions != osoption->job->otherOptions->numberOfOtherOptions)
		osolerror (NULL, osoption, parserData, "wrong number of other options in <job> element");
}
    break;

  case 392:

    {	if (parserData->numberOfOtherJobOptions >= osoption->job->otherOptions->numberOfOtherOptions)
		{	osolerror (NULL, osoption, parserData, "too many other options in <job> element");
		};
	}
    break;

  case 393:

    {	if (!parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "name attribute must be present");
	/* reset defaults for the next option */
	parserData->otherOptionNamePresent = false;
	parserData->otherOptionValuePresent = false;
	parserData->otherOptionDescriptionPresent = false;
	parserData->numberOfOtherJobOptions++;
}
    break;

  case 399:

    {	if (parserData->otherOptionNamePresent)
	{	osolerror( NULL, osoption, parserData, "only one name attribute allowed");
	}
	else
	{	parserData->otherOptionNamePresent = true;
		osoption->job->otherOptions->other[parserData->numberOfOtherJobOptions]->name = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 401:

    {	if (parserData->otherOptionValuePresent)
	{	osolerror( NULL, osoption, parserData, "only one value attribute allowed");
	}
	else
	{	parserData->otherOptionValuePresent = true;
		osoption->job->otherOptions->other[parserData->numberOfOtherJobOptions]->value = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 403:

    {	if (parserData->otherOptionDescriptionPresent)
	{	osolerror( NULL, osoption, parserData, "only one description attribute allowed");
	}
	else
	{	parserData->otherOptionDescriptionPresent = true;
		osoption->job->otherOptions->other[parserData->numberOfOtherJobOptions]->description = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 409:

    {	if (parserData->osoloptimizationPresent)
	{	osolerror( NULL, osoption, parserData, "only one <optimization> element allowed");
	}
	else
	{	parserData->osoloptimizationPresent = true;
		osoption->optimization = new OptimizationOption();
	}
}
    break;

  case 415:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror( NULL, osoption, parserData, "Number of variables cannot be negative");
	osoption->optimization->numberOfVariables = (yyvsp[(3) - (4)].ival);
}
    break;

  case 416:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror( NULL, osoption, parserData, "Number of constraints cannot be negative");
	osoption->optimization->numberOfConstraints = (yyvsp[(3) - (4)].ival);
}
    break;

  case 417:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror( NULL, osoption, parserData, "Number of objectives cannot be negative");
	osoption->optimization->numberOfObjectives = (yyvsp[(3) - (4)].ival);
}
    break;

  case 423:

    {	osoption->optimization->variables = new VariableOption();
}
    break;

  case 425:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "number of <other> variable options cannot be negative");
	osoption->optimization->variables->numberOfOtherVariableOptions = (yyvsp[(3) - (4)].ival);
	osoption->optimization->variables->other = new OtherVariableOption*[(yyvsp[(3) - (4)].ival)];
	for (int i= 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->variables->other[i] = new OtherVariableOption();
}
    break;

  case 430:

    {	if ((yyvsp[(3) - (4)].ival) <= 0)
		osolerror (NULL, osoption, parserData, "number of <var> elements must be positive");
	osoption->optimization->variables->initialVariableValues = new InitVariableValues();
	osoption->optimization->variables->initialVariableValues->numberOfVar = (yyvsp[(3) - (4)].ival);
	osoption->optimization->variables->initialVariableValues->var = new InitVarValue*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->variables->initialVariableValues->var[i] = new InitVarValue();
}
    break;

  case 433:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "variable index required");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->numberOfVar++;
}
    break;

  case 434:

    {	if (parserData->numberOfVar >= osoption->optimization->variables->initialVariableValues->numberOfVar)
		osolerror(NULL, osoption, parserData, "too many initial variable values");
}
    break;

  case 439:

    {	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable index allowed");
	parserData->idxAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "variable index must be nonnegative");
	if (parserData->numberOfVariablesPresent)
	{	if ((yyvsp[(3) - (4)].ival) >= parserData->numberOfVariables)
			osolerror (NULL, osoption, parserData, "variable index exceeds upper limit");
	};
	osoption->optimization->variables->initialVariableValues->var[parserData->numberOfVar]->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 440:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable value allowed");
	parserData->valAttributePresent = true;
	if (strncmp((yyvsp[(2) - (2)].sval),"INF",3) == 0)
		osoption->optimization->variables->initialVariableValues->var[parserData->numberOfVar]->value = OSDBL_MAX;
	else if (strncmp((yyvsp[(2) - (2)].sval),"-INF",4) == 0)
		osoption->optimization->variables->initialVariableValues->var[parserData->numberOfVar]->value = -OSDBL_MAX;
	else
		osoption->optimization->variables->initialVariableValues->var[parserData->numberOfVar]->value = os_strtod((yyvsp[(2) - (2)].sval), NULL);
}
    break;

  case 446:

    {	if ((yyvsp[(3) - (4)].ival) <= 0)
		osolerror (NULL, osoption, parserData, "number of <var> elements must be positive");
	osoption->optimization->variables->initialVariableValuesString = new InitVariableValuesString ();
	osoption->optimization->variables->initialVariableValuesString->numberOfVar = (yyvsp[(3) - (4)].ival);
	osoption->optimization->variables->initialVariableValuesString->var = new InitVarValueString*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->variables->initialVariableValuesString->var[i] = new InitVarValueString ();
}
    break;

  case 449:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "variable index required");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->numberOfVarStr++;
}
    break;

  case 450:

    {	if (parserData->numberOfVarStr >= osoption->optimization->variables->initialVariableValuesString->numberOfVar)
		osolerror(NULL, osoption, parserData, "too many initial variable strings");
}
    break;

  case 455:

    {	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable index allowed");
	parserData->idxAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "variable index must be nonnegative");
	if (parserData->numberOfVariablesPresent)
	{	if ((yyvsp[(3) - (4)].ival) >= parserData->numberOfVariables)
			osolerror (NULL, osoption, parserData, "variable index exceeds upper limit");
	};
	osoption->optimization->variables->initialVariableValuesString->var[parserData->numberOfVarStr]->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 456:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable index allowed");
	parserData->valAttributePresent = true;
	osoption->optimization->variables->initialVariableValuesString->var[parserData->numberOfVarStr]->value = (yyvsp[(2) - (2)].sval);
}
    break;

  case 463:

    {	if (parserData->numberOfOtherVariableOptions >= osoption->optimization->variables->numberOfOtherVariableOptions)
		osolerror(NULL, osoption, parserData, "too many <other> variable options");
}
    break;

  case 473:

    { 	if (parserData->otherOptionNumberPresent)
		osolerror (NULL, osoption, parserData, "only one numberOfVar attribute allowed");
	parserData->otherOptionNumberPresent = true;
	parserData->numberOfVar = 0;
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "number of <other> variable options must be nonnegative");
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->numberOfVar = (yyvsp[(3) - (4)].ival);
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->var = new OtherVarOption*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->var[i] = new OtherVarOption();	
}
    break;

  case 474:

    {	if (parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "only one name attribute allowed");
	parserData->otherOptionNamePresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->name = (yyvsp[(2) - (2)].sval);
}
    break;

  case 476:

    {	if (parserData->otherOptionValuePresent)
		osolerror (NULL, osoption, parserData, "only one value attribute allowed");
	parserData->otherOptionValuePresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->value = (yyvsp[(2) - (2)].sval);
}
    break;

  case 478:

    {	if (parserData->otherOptionSolverPresent)
		osolerror (NULL, osoption, parserData, "only one solver attribute allowed");
	parserData->otherOptionSolverPresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->solver = (yyvsp[(2) - (2)].sval);
}
    break;

  case 480:

    {	if (parserData->otherOptionCategoryPresent)
		osolerror (NULL, osoption, parserData, "only one category attribute allowed");
	parserData->otherOptionCategoryPresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->category = (yyvsp[(2) - (2)].sval);
}
    break;

  case 482:

    {	if (parserData->otherOptionTypePresent)
		osolerror (NULL, osoption, parserData, "only one type attribute allowed");
	parserData->otherOptionTypePresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->type = (yyvsp[(2) - (2)].sval);
}
    break;

  case 484:

    {	if (parserData->otherOptionDescriptionPresent)
		osolerror (NULL, osoption, parserData, "only one description attribute allowed");
	parserData->otherOptionDescriptionPresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->description = (yyvsp[(2) - (2)].sval);
}
    break;

  case 486:

    { 	if (parserData->numberOfVar < osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->numberOfVar)
		osolerror(NULL, osoption, parserData, "not enough <var> entries in <other> variable element");
	if (!parserData->otherOptionNumberPresent)
		osolerror (NULL, osoption, parserData, "number attribute required");
	if (!parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "name attribute required");
	parserData->otherOptionNumberPresent = false;
	parserData->otherOptionNamePresent = false;
	parserData->otherOptionValuePresent = false;
	parserData->otherOptionSolverPresent = false;
	parserData->otherOptionCategoryPresent = false;
	parserData->otherOptionTypePresent = false;
	parserData->otherOptionDescriptionPresent = false;
	parserData->numberOfOtherVariableOptions++;
}
    break;

  case 489:

    {	if (!parserData->idxAttributePresent)
		osolerror(NULL, osoption, parserData, "required idx attribute was not found");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->lbvalAttributePresent = false;
	parserData->ubvalAttributePresent = false;
	parserData->numberOfVar++;
}
    break;

  case 490:

    {	if (parserData->numberOfVar >= osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->numberOfVar)
		osolerror(NULL, osoption, parserData, "too many <var> entries in <other> variable element");
}
    break;

  case 497:

    {	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable index allowed");
	parserData->idxAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "variable index must be nonnegative");
	if (parserData->numberOfVariablesPresent)
	{	if ((yyvsp[(3) - (4)].ival) >= parserData->numberOfVariables)
			osolerror (NULL, osoption, parserData, "variable index exceeds upper limit");
	};
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->var[parserData->numberOfVar]->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 498:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable value allowed");
	parserData->valAttributePresent = true;
	osoption->optimization->variables-> other[parserData->numberOfOtherVariableOptions]->var[parserData->numberOfVar]->value = (yyvsp[(2) - (2)].sval);
}
    break;

  case 500:

    {	if (parserData->lbvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one lower bound value allowed");
	parserData->lbvalAttributePresent = true;
	osoption->optimization->variables-> other[parserData->numberOfOtherVariableOptions]->var[parserData->numberOfVar]->lbValue = (yyvsp[(2) - (2)].sval);
}
    break;

  case 502:

    {	if (parserData->ubvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one upper bound value allowed");
	parserData->ubvalAttributePresent = true;
	osoption->optimization->variables-> other[parserData->numberOfOtherVariableOptions]->var[parserData->numberOfVar]->ubValue = (yyvsp[(2) - (2)].sval);
}
    break;

  case 508:

    {	osoption->optimization->objectives = new ObjectiveOption();
}
    break;

  case 510:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "number of <other> objective options cannot be negative");
	osoption->optimization->objectives->numberOfOtherObjectiveOptions = (yyvsp[(3) - (4)].ival);
	osoption->optimization->objectives->other = new OtherObjectiveOption*[(yyvsp[(3) - (4)].ival)];
	for (int i= 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->objectives->other[i] = new OtherObjectiveOption();
}
    break;

  case 515:

    {	if ((yyvsp[(3) - (4)].ival) <= 0)
		osolerror (NULL, osoption, parserData, "number of <obj> elements must be positive");
	osoption->optimization->objectives->initialObjectiveValues = new InitObjectiveValues();
	osoption->optimization->objectives->initialObjectiveValues->numberOfObj = (yyvsp[(3) - (4)].ival);
	osoption->optimization->objectives->initialObjectiveValues->obj = new InitObjValue*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->objectives->initialObjectiveValues->obj[i] = new InitObjValue();
}
    break;

  case 518:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "objective index required");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->numberOfObjValues++;
}
    break;

  case 519:

    {	if (parserData->numberOfObjValues >= osoption->optimization->objectives->initialObjectiveValues->numberOfObj)
		osolerror(NULL, osoption, parserData, "too many initial objective values");
}
    break;

  case 524:

    {	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one objective index allowed");
	parserData->idxAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) >= 0)
		osolerror (NULL, osoption, parserData, "objective index must be negative");
	if (parserData->numberOfObjectivesPresent)
	{	if (-(yyvsp[(3) - (4)].ival) > parserData->numberOfObjectives)
			osolerror (NULL, osoption, parserData, "objective index out of range");
	};
	osoption->optimization->objectives->initialObjectiveValues->obj[parserData->numberOfObjValues]->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 525:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one objective value allowed");
	parserData->valAttributePresent = true;
	if (strncmp((yyvsp[(2) - (2)].sval),"INF",3) == 0)
		osoption->optimization->objectives->initialObjectiveValues->obj[parserData->numberOfObjValues]->value = OSDBL_MAX;
	else if (strncmp((yyvsp[(2) - (2)].sval),"-INF",4) == 0)
		osoption->optimization->objectives->initialObjectiveValues->obj[parserData->numberOfObjValues]->value = -OSDBL_MAX;
	else
		osoption->optimization->objectives->initialObjectiveValues->obj[parserData->numberOfObjValues]->value = os_strtod((yyvsp[(2) - (2)].sval), NULL);
}
    break;

  case 531:

    {	if ((yyvsp[(3) - (4)].ival) <= 0)
		osolerror (NULL, osoption, parserData, "number of <obj> elements must be positive");
	osoption->optimization->objectives->initialObjectiveBounds = new InitObjectiveBounds();
	osoption->optimization->objectives->initialObjectiveBounds->numberOfObj = (yyvsp[(3) - (4)].ival);
	osoption->optimization->objectives->initialObjectiveBounds->obj = new InitObjBound*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->objectives->initialObjectiveBounds->obj[i] = new InitObjBound ();
}
    break;

  case 534:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "objective index required");
	parserData->idxAttributePresent = false;
	parserData->lbvalAttributePresent = false;
	parserData->ubvalAttributePresent = false;
	parserData->numberOfObjBounds++;
}
    break;

  case 535:

    {	if (parserData->numberOfObjBounds >= osoption->optimization->objectives->initialObjectiveBounds->numberOfObj)
		osolerror(NULL, osoption, parserData, "too many initial objective bounds");
}
    break;

  case 541:

    {	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one objective index allowed");
	parserData->idxAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) >= 0)
		osolerror (NULL, osoption, parserData, "objective index must be negative");
	if (parserData->numberOfObjectivesPresent)
	{	if (-(yyvsp[(3) - (4)].ival) > parserData->numberOfObjectives)
			osolerror (NULL, osoption, parserData, "objective index out of range");
	};
	osoption->optimization->objectives->initialObjectiveBounds->obj[parserData->numberOfObjBounds]->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 542:

    {	if (parserData->lbvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one objective lower bound allowed");
	parserData->lbvalAttributePresent = true;
	if (strncmp((yyvsp[(2) - (2)].sval),"INF",3) == 0)
		osoption->optimization->objectives->initialObjectiveBounds->obj[parserData->numberOfObjBounds]->lbValue = OSDBL_MAX;
	else if (strncmp((yyvsp[(2) - (2)].sval),"-INF",4) == 0)
		osoption->optimization->objectives->initialObjectiveBounds->obj[parserData->numberOfObjBounds]->lbValue = -OSDBL_MAX;
	else
		osoption->optimization->objectives->initialObjectiveBounds->obj[parserData->numberOfObjBounds]->lbValue = os_strtod((yyvsp[(2) - (2)].sval), NULL);
}
    break;

  case 544:

    {	if (parserData->ubvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one objective upper bound allowed");
	parserData->ubvalAttributePresent = true;
	if (strncmp((yyvsp[(2) - (2)].sval),"INF",3) == 0)
		osoption->optimization->objectives->initialObjectiveBounds->obj[parserData->numberOfObjBounds]->ubValue = OSDBL_MAX;
	else if (strncmp((yyvsp[(2) - (2)].sval),"-INF",4) == 0)
		osoption->optimization->objectives->initialObjectiveBounds->obj[parserData->numberOfObjBounds]->ubValue = -OSDBL_MAX;
	else
		osoption->optimization->objectives->initialObjectiveBounds->obj[parserData->numberOfObjBounds]->ubValue = os_strtod((yyvsp[(2) - (2)].sval), NULL);
}
    break;

  case 551:

    {	if (parserData->numberOfOtherObjectiveOptions >= osoption->optimization->objectives->numberOfOtherObjectiveOptions)
		osolerror(NULL, osoption, parserData, "too many <other> objective options");
}
    break;

  case 561:

    { 	if (parserData->otherOptionNumberPresent)
		osolerror (NULL, osoption, parserData, "only one numberOfObj attribute allowed");
	parserData->otherOptionNumberPresent = true;
	parserData->numberOfObj = 0;
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "number of <other> objective options must be nonnegative");
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->numberOfObj = (yyvsp[(3) - (4)].ival);
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->obj = new OtherObjOption*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->obj[i] = new OtherObjOption();
}
    break;

  case 562:

    {	if (parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "only one name attribute allowed");
	parserData->otherOptionNamePresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->name = (yyvsp[(2) - (2)].sval);
}
    break;

  case 564:

    {	if (parserData->otherOptionValuePresent)
		osolerror (NULL, osoption, parserData, "only one value attribute allowed");
	parserData->otherOptionValuePresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->value = (yyvsp[(2) - (2)].sval);
}
    break;

  case 566:

    {	if (parserData->otherOptionSolverPresent)
		osolerror (NULL, osoption, parserData, "only one solver attribute allowed");
	parserData->otherOptionSolverPresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->solver = (yyvsp[(2) - (2)].sval);
}
    break;

  case 568:

    {	if (parserData->otherOptionCategoryPresent)
		osolerror (NULL, osoption, parserData, "only one category attribute allowed");
	parserData->otherOptionCategoryPresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->category = (yyvsp[(2) - (2)].sval);
}
    break;

  case 570:

    {	if (parserData->otherOptionTypePresent)
		osolerror (NULL, osoption, parserData, "only one type attribute allowed");
	parserData->otherOptionTypePresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->type = (yyvsp[(2) - (2)].sval);
}
    break;

  case 572:

    {	if (parserData->otherOptionDescriptionPresent)
		osolerror (NULL, osoption, parserData, "only one description attribute allowed");
	parserData->otherOptionDescriptionPresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->description = (yyvsp[(2) - (2)].sval);
}
    break;

  case 574:

    { 	if (parserData->numberOfVar < osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->numberOfObj)
		osolerror(NULL, osoption, parserData, "not enough <obj> entries in <other> variable element");
	if (!parserData->otherOptionNumberPresent)
		osolerror (NULL, osoption, parserData, "number attribute required");
	if (!parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "name attribute required");
	parserData->otherOptionNumberPresent = false;
	parserData->otherOptionNamePresent = false;
	parserData->otherOptionValuePresent = false;
	parserData->otherOptionSolverPresent = false;
	parserData->otherOptionCategoryPresent = false;
	parserData->otherOptionTypePresent = false;
	parserData->otherOptionDescriptionPresent = false;
	parserData->numberOfOtherObjectiveOptions++;
}
    break;

  case 577:

    {	if (!parserData->idxAttributePresent)
		osolerror(NULL, osoption, parserData, "required idx attribute was not found");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->lbvalAttributePresent = false;
	parserData->ubvalAttributePresent = false;
	parserData->numberOfObj++;
}
    break;

  case 578:

    {	if (parserData->numberOfObj >= osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->numberOfObj)
		osolerror(NULL, osoption, parserData, "too many <obj> entries in <other> objective element");
}
    break;

  case 585:

    {	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one objective index allowed");
	parserData->idxAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) >= 0)
		osolerror (NULL, osoption, parserData, "objective index must be negative");
	if (parserData->numberOfObjectivesPresent)
	{	if (-(yyvsp[(3) - (4)].ival) > parserData->numberOfObjectives)
			osolerror (NULL, osoption, parserData, "objecive index exceeds upper limit");
	};
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->obj[parserData->numberOfObj]->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 586:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable value allowed");
	parserData->valAttributePresent = true;
	osoption->optimization->objectives-> other[parserData->numberOfOtherObjectiveOptions]->obj[parserData->numberOfObj]->value = (yyvsp[(2) - (2)].sval);
}
    break;

  case 588:

    {	if (parserData->lbvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one lower bound value allowed");
	parserData->lbvalAttributePresent = true;
	osoption->optimization->objectives-> other[parserData->numberOfOtherObjectiveOptions]->obj[parserData->numberOfObj]->lbValue = (yyvsp[(2) - (2)].sval);
}
    break;

  case 590:

    {	if (parserData->ubvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one upper bound value allowed");
	parserData->ubvalAttributePresent = true;
	osoption->optimization->objectives-> other[parserData->numberOfOtherObjectiveOptions]->obj[parserData->numberOfObj]->ubValue = (yyvsp[(2) - (2)].sval);
}
    break;

  case 596:

    {	osoption->optimization->constraints = new ConstraintOption();
}
    break;

  case 598:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "number of <other> constraint options cannot be negative");
        osoption->optimization->constraints->numberOfOtherConstraintOptions = (yyvsp[(3) - (4)].ival);
	osoption->optimization->constraints->other = new OtherConstraintOption*[(yyvsp[(3) - (4)].ival)];
	for (int i= 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->constraints->other[i] = new OtherConstraintOption();
}
    break;

  case 603:

    {	if ((yyvsp[(3) - (4)].ival) <= 0)
		osolerror (NULL, osoption, parserData, "number of <con> elements must be positive");
	osoption->optimization->constraints->initialConstraintValues = new InitConstraintValues();
	osoption->optimization->constraints->initialConstraintValues->numberOfCon = (yyvsp[(3) - (4)].ival);
	osoption->optimization->constraints->initialConstraintValues->con = new InitConValue*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->constraints->initialConstraintValues->con[i] = new InitConValue();
}
    break;

  case 606:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "variable index required");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->numberOfCon++;
}
    break;

  case 607:

    {	if (parserData->numberOfCon >= osoption->optimization->constraints->initialConstraintValues->numberOfCon)
		osolerror(NULL, osoption, parserData, "too many initial constraint values");
}
    break;

  case 612:

    {	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one constraint index allowed");
	parserData->idxAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "constraint index must be nonnegative");
	if (parserData->numberOfConstraintsPresent)
	{	if ((yyvsp[(3) - (4)].ival) > parserData->numberOfConstraints)
			osolerror (NULL, osoption, parserData, "constraint index out of range");
	};
	osoption->optimization->constraints->initialConstraintValues->con[parserData->numberOfCon]->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 613:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one constraint value allowed");
	parserData->valAttributePresent = true;
	if (strncmp((yyvsp[(2) - (2)].sval),"INF",3) == 0)
		osoption->optimization->constraints->initialConstraintValues->con[parserData->numberOfCon]->value = OSDBL_MAX;
	else if (strncmp((yyvsp[(2) - (2)].sval),"-INF",4) == 0)
		osoption->optimization->constraints->initialConstraintValues->con[parserData->numberOfCon]->value = -OSDBL_MAX;
	else
		osoption->optimization->constraints->initialConstraintValues->con[parserData->numberOfCon]->value = os_strtod((yyvsp[(2) - (2)].sval), NULL);
}
    break;

  case 619:

    {	if ((yyvsp[(3) - (4)].ival) <= 0)
		osolerror (NULL, osoption, parserData, "number of <con> elements must be positive");
	osoption->optimization->constraints->initialDualValues = new InitDualVariableValues();
	osoption->optimization->constraints->initialDualValues->numberOfCon = (yyvsp[(3) - (4)].ival);
	osoption->optimization->constraints->initialDualValues->con = new InitDualVarValue*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->constraints->initialDualValues->con[i] = new InitDualVarValue ();
}
    break;

  case 622:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "constraint index required");
	parserData->idxAttributePresent = false;
	parserData->lbvalAttributePresent = false;
	parserData->ubvalAttributePresent = false;
	parserData->numberOfDuals++;
}
    break;

  case 623:

    {	if (parserData->numberOfDuals >= osoption->optimization->constraints->initialDualValues->numberOfCon)
		osolerror(NULL, osoption, parserData, "too many initial dual variable bounds");
}
    break;

  case 629:

    {	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one constraint index allowed");
	parserData->idxAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "constraint index must be nonnegative");
	if (parserData->numberOfConstraintsPresent)
	{	if ((yyvsp[(3) - (4)].ival) > parserData->numberOfConstraints)
			osolerror (NULL, osoption, parserData, "constraint index out of range");
	};
	osoption->optimization->constraints->initialDualValues->con[parserData->numberOfDuals]->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 630:

    {	if (parserData->lbvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one dual variable lower bound allowed");
	parserData->lbvalAttributePresent = true;
	if (strncmp((yyvsp[(2) - (2)].sval),"INF",3) == 0)
		osoption->optimization->constraints->initialDualValues->con[parserData->numberOfDuals]->lbValue = OSDBL_MAX;
	else if (strncmp((yyvsp[(2) - (2)].sval),"-INF",4) == 0)
		osoption->optimization->constraints->initialDualValues->con[parserData->numberOfDuals]->lbValue = -OSDBL_MAX;
	else
		osoption->optimization->constraints->initialDualValues->con[parserData->numberOfDuals]->lbValue = os_strtod((yyvsp[(2) - (2)].sval), NULL);
}
    break;

  case 632:

    {	if (parserData->ubvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one dual variable upper bound allowed");
	parserData->ubvalAttributePresent = true;
	if (strncmp((yyvsp[(2) - (2)].sval),"INF",3) == 0)
		osoption->optimization->constraints->initialDualValues->con[parserData->numberOfDuals]->ubValue = OSDBL_MAX;
	else if (strncmp((yyvsp[(2) - (2)].sval),"-INF",4) == 0)
		osoption->optimization->constraints->initialDualValues->con[parserData->numberOfDuals]->ubValue = -OSDBL_MAX;
	else
		osoption->optimization->constraints->initialDualValues->con[parserData->numberOfDuals]->ubValue = os_strtod((yyvsp[(2) - (2)].sval), NULL);
}
    break;

  case 639:

    {	if (parserData->numberOfOtherConstraintOptions >= osoption->optimization->constraints->numberOfOtherConstraintOptions)
		osolerror(NULL, osoption, parserData, "too many <other> constraint options");
}
    break;

  case 649:

    { 	if (parserData->otherOptionNumberPresent)
		osolerror (NULL, osoption, parserData, "only one numberOfCon attribute allowed");
	parserData->otherOptionNumberPresent = true;
	parserData->numberOfCon = 0;
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "number of <other> constraint options must be nonnegative");
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->numberOfCon = (yyvsp[(3) - (4)].ival);
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->con = new OtherConOption*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->con[i] = new OtherConOption();
}
    break;

  case 650:

    {	if (parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "only one name attribute allowed");
	parserData->otherOptionNamePresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->name = (yyvsp[(2) - (2)].sval);
}
    break;

  case 652:

    {	if (parserData->otherOptionValuePresent)
		osolerror (NULL, osoption, parserData, "only one value attribute allowed");
	parserData->otherOptionValuePresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->value = (yyvsp[(2) - (2)].sval);
}
    break;

  case 654:

    {	if (parserData->otherOptionSolverPresent)
		osolerror (NULL, osoption, parserData, "only one solver attribute allowed");
	parserData->otherOptionSolverPresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->solver = (yyvsp[(2) - (2)].sval);
}
    break;

  case 656:

    {	if (parserData->otherOptionCategoryPresent)
		osolerror (NULL, osoption, parserData, "only one category attribute allowed");
	parserData->otherOptionCategoryPresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->category = (yyvsp[(2) - (2)].sval);
}
    break;

  case 658:

    {	if (parserData->otherOptionTypePresent)
		osolerror (NULL, osoption, parserData, "only one type attribute allowed");
	parserData->otherOptionTypePresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->type = (yyvsp[(2) - (2)].sval);
}
    break;

  case 660:

    {	if (parserData->otherOptionDescriptionPresent)
		osolerror (NULL, osoption, parserData, "only one description attribute allowed");
	parserData->otherOptionDescriptionPresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->description = (yyvsp[(2) - (2)].sval);
}
    break;

  case 662:

    { 	if (parserData->numberOfCon < osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->numberOfCon)
		osolerror(NULL, osoption, parserData, "not enough <con> entries in <other> constraint element");
	if (!parserData->otherOptionNumberPresent)
		osolerror (NULL, osoption, parserData, "number attribute required");
	if (!parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "name attribute required");
	parserData->otherOptionNumberPresent = false;
	parserData->otherOptionNamePresent = false;
	parserData->otherOptionValuePresent = false;
	parserData->otherOptionSolverPresent = false;
	parserData->otherOptionCategoryPresent = false;
	parserData->otherOptionTypePresent = false;
	parserData->otherOptionDescriptionPresent = false;
	parserData->numberOfOtherConstraintOptions++;
}
    break;

  case 665:

    {	if (!parserData->idxAttributePresent)
		osolerror(NULL, osoption, parserData, "required idx attribute was not found");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->lbvalAttributePresent = false;
	parserData->ubvalAttributePresent = false;
	parserData->numberOfCon++;
}
    break;

  case 666:

    {	if (parserData->numberOfVar >= osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->numberOfVar)
		osolerror(NULL, osoption, parserData, "too many <var> entries in <other> variable element");
}
    break;

  case 673:

    {	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one constraint index allowed");
	parserData->idxAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "constraint index must be nonnegative");
	if (parserData->numberOfConstraintsPresent)
	{	if ((yyvsp[(3) - (4)].ival) >= parserData->numberOfConstraints)
			osolerror (NULL, osoption, parserData, "constraint index exceeds upper limit");
	};
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->con[parserData->numberOfCon]->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 674:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one constraint value allowed");
	parserData->valAttributePresent = true;
	osoption->optimization->constraints-> other[parserData->numberOfOtherConstraintOptions]->con[parserData->numberOfCon]->value = (yyvsp[(2) - (2)].sval);
}
    break;

  case 676:

    {	if (parserData->lbvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one lower bound value allowed");
	parserData->lbvalAttributePresent = true;
	osoption->optimization->constraints-> other[parserData->numberOfOtherConstraintOptions]->con[parserData->numberOfCon]->lbValue = (yyvsp[(2) - (2)].sval);
}
    break;

  case 678:

    {	if (parserData->ubvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one upper bound value allowed");
	parserData->ubvalAttributePresent = true;
	osoption->optimization->constraints-> other[parserData->numberOfOtherConstraintOptions]->con[parserData->numberOfCon]->ubValue = (yyvsp[(2) - (2)].sval);
}
    break;

  case 683:

    {	if (parserData->numberOfSolverOptions != osoption->optimization->solverOptions->numberOfSolverOptions)
		osolerror (NULL, osoption, parserData, "wrong number of solver options in <optimization> element");
}
    break;

  case 684:

    {	if (parserData->solverOptionsPresent)
	{	osolerror( NULL, osoption, parserData, "only one <solverOptions> element allowed");
	}
	else
	{	parserData->solverOptionsPresent = true;
		osoption->optimization->solverOptions = new SolverOptions();
	}
}
    break;

  case 685:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "number of solver options cannot be negative");
	osoption->optimization->solverOptions->numberOfSolverOptions = (yyvsp[(3) - (4)].ival);
	osoption->optimization->solverOptions->solverOption = new SolverOption*[(yyvsp[(3) - (4)].ival)];
	for (int i=0; i < (yyvsp[(3) - (4)].ival); i++) osoption->optimization->solverOptions->solverOption[i] = new SolverOption();
}
    break;

  case 688:

    {	if (parserData->numberOfSolverOptions >= osoption->optimization->solverOptions->numberOfSolverOptions)
	{	osolerror (NULL, osoption, parserData, "too many solver options in <optimization> element");
	};
}
    break;

  case 689:

    {	if (!parserData->solverOptionNamePresent)
		osolerror (NULL, osoption, parserData, "name attribute must be present");
	/* reset defaults for the next option */
	parserData->solverOptionNamePresent = false;
	parserData->solverOptionValuePresent = false;
	parserData->solverOptionSolverPresent = false;
	parserData->solverOptionCategoryPresent = false;
	parserData->solverOptionTypePresent = false;
	parserData->solverOptionDescriptionPresent = false;
	parserData->numberOfSolverOptions++;
}
    break;

  case 698:

    {	if (parserData->solverOptionNamePresent)
	{	osolerror( NULL, osoption, parserData, "only one name attribute allowed");
	}
	else
	{	parserData->solverOptionNamePresent = true;
		osoption->optimization->solverOptions->solverOption[parserData->numberOfSolverOptions]->name = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 700:

    {	if (parserData->solverOptionValuePresent)
	{	osolerror( NULL, osoption, parserData, "only one value attribute allowed");
	}
	else
	{	parserData->solverOptionValuePresent = true;
		osoption->optimization->solverOptions->solverOption[parserData->numberOfSolverOptions]->value = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 702:

    {	if (parserData->solverOptionSolverPresent)
	{	osolerror( NULL, osoption, parserData, "only one solver attribute allowed");
	}
	else
	{	parserData->solverOptionSolverPresent = true;
		osoption->optimization->solverOptions->solverOption[parserData->numberOfSolverOptions]->solver = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 704:

    {	if (parserData->solverOptionCategoryPresent)
	{	osolerror( NULL, osoption, parserData, "only one category attribute allowed");
	}
	else
	{	parserData->solverOptionCategoryPresent = true;
		osoption->optimization->solverOptions->solverOption[parserData->numberOfSolverOptions]->category = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 706:

    {	if (parserData->solverOptionTypePresent)
	{	osolerror( NULL, osoption, parserData, "only one type attribute allowed");
	}
	else
	{	parserData->solverOptionTypePresent = true;
		osoption->optimization->solverOptions->solverOption[parserData->numberOfSolverOptions]->type = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 708:

    {	if (parserData->solverOptionNamePresent)
	{	osolerror( NULL, osoption, parserData, "only one name attribute allowed");
	}
	else
	{	parserData->solverOptionNamePresent = true;
		osoption->optimization->solverOptions->solverOption[parserData->numberOfSolverOptions]->name = (yyvsp[(2) - (2)].sval);
	}
}
    break;


/* Line 1267 of yacc.c.  */

      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (&yylloc, osoption, parserData, YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (&yylloc, osoption, parserData, yymsg);
	  }
	else
	  {
	    yyerror (&yylloc, osoption, parserData, YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }

  yyerror_range[0] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval, &yylloc, osoption, parserData);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[0] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp, osoption, parserData);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the look-ahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, osoption, parserData, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc, osoption, parserData);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp, osoption, parserData);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}





void osolerror(YYLTYPE* mytype, OSOption *osoption, OSoLParserData* parserData, const char* errormsg )
{
	std::ostringstream outStr;
	std::string error = errormsg;
	error = "Input is either not valid or well formed: "  + error;
	outStr << error << std::endl;
	outStr << "See line number: " << osolget_lineno( scanner) << std::endl;
	outStr << "The offending text is: " << osolget_text ( scanner ) << std::endl;
	error = outStr.str();
	//printf("THIS DID NOT GET DESTROYED:   %s\n", parserData->errorText);
	//if( (parserData->errorText != NULL) &&  (strlen(parserData->errorText) > 0) ) free(  parserData->errorText);
	//osollex_destroy( scanner);
	throw ErrorClass( error);
} //end osolerror

void  yygetOSOption(const char *parsestring, OSOption *osoption, OSoLParserData *parserData) throw(ErrorClass){
	try{
		osol_scan_string( parsestring, scanner);
		osolset_lineno (1 , scanner );
		//
		// call the Bison parser
		//
		if(  osolparse( osoption,  parserData) != 0) {
			//osollex_destroy(scanner);
		  	throw ErrorClass(  "Error parsing the OSoL file");
		 }
	}
	catch(const ErrorClass& eclass){
		throw ErrorClass(  eclass.errormsg);
	}
} //end yygetOSOption


