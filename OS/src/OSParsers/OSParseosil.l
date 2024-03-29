/* $Id$ */
/** @file parseosil.l
 * 
 * @author  Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin, 
 *
 * \remarks
 * Copyright (C) 2005-2013, Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */
%{

#include <iostream>
#include "OSDataStructures.h"
#include "OSMathUtil.h"
#include "OSConfig.h"

#ifdef HAVE_CSTDIO
# include <cstdio>
#else
# ifdef HAVE_STDIO_H
#  include <stdio.h>
# else
#  error "don't have header file for stdio"
# endif
#endif

#ifdef HAVE_CTIME
# include <ctime>
#else
# ifdef HAVE_TIME_H
#  include <time.h>
# else
#  error "don't have header file for time"
# endif
#endif

#ifdef HAVE_CMATH
# include <cmath>
#else
# ifdef HAVE_MATH_H
#  include <math.h>
# else
#  error "don't have header file for math"
# endif
#endif

#include <sstream>  
#include "OSiLParserData.h"
#include "OSErrorClass.h"
#include "OSParseosil.tab.hpp"
#include "OSInstance.h"


//#define OSILPARSERDEBUG

#ifdef OSILPARSERDEBUG
	#define YY_PRINT  printf("%s", yytext);
#else     
	#define YY_PRINT ;
#endif


#ifdef WIN_
  #define YY_NO_UNISTD_H
  #include <io.h>
  #include <process.h>
  #ifdef USE_OLD_UNISTD
     #include<sys/unistd.h>
  #endif
#endif

using std::cout;
using std::endl;
using std::ostringstream;

%}

%option prefix="osil"
%option noyywrap
%option reentrant
%option bison-bridge
%option bison-locations
%option yylineno
%option nounput
%x osilattributetext
%x doublequoteattributetext
%x singlequoteattributetext
%x startelement
%x elementtext
%x comment
%x xmldeclaration

%{
#define YY_EXTRA_TYPE OSiLParserData*
%} 
 
xmlwhitespace ([ \t\n\r])
equality ([ \t\n\r])*=([ \t\n\r])*
quote [\" | \']  
greater_than (>)
aninteger (-?[0-9]+)
adouble (-?((([0-9]+)|([0-9]*\.[0-9]*))([eE][-+]?[0-9]+)?|INF))


%% 
 
{xmlwhitespace}*

 /* General patterns matched in more than one element */

{quote} {YY_PRINT;  yylval->sval = yytext; return(QUOTE);}
({xmlwhitespace}*{greater_than}) {YY_PRINT; return(GREATERTHAN);}
{aninteger}  {YY_PRINT; yylval->ival = atoi(yytext); return(INTEGER);}

{adouble} {YY_PRINT; 
char *yytextEnd;
yylval->dval = os_strtod_wrap( yytext, &yytextEnd);
	if( (unsigned)(yytextEnd - yytext) != strlen( yytext)){
		std::ostringstream outStr;
		outStr << "encountered a spurious character in the lexer" << endl;
		outStr << "The first character is: ";
		outStr <<  yytext;
		outStr << endl;
		outStr << "See line number: " << yylineno << endl;  
		throw ErrorClass( outStr.str());
	}
return(DOUBLE);}



({xmlwhitespace}*\/>) {YY_PRINT;  return(ENDOFELEMENT);}


({xmlwhitespace}+numberOfVariables{equality}) {YY_PRINT; return(NUMBEROFVARIABLESATT);}
({xmlwhitespace}+numberOfConstraints{equality}) {YY_PRINT; return(NUMBEROFCONSTRAINTSATT);}
({xmlwhitespace}+numberOfObjectives{equality}) {YY_PRINT; return(NUMBEROFOBJECTIVESATT);}
({xmlwhitespace}+numberOfQuadraticTerms{equality}) {YY_PRINT; return(NUMBEROFQTERMSATT);}
({xmlwhitespace}+numberOfNonlinearExpressions{equality}) {YY_PRINT; return(NUMBEROFNONLINEAREXPRESSIONS);}
({xmlwhitespace}+numberOfStages{equality}) {YY_PRINT; return(NUMBEROFSTAGESATT);}


({xmlwhitespace}+idx{equality}) {YY_PRINT;   return(IDXATT);}
({xmlwhitespace}+idxOne{equality}) {YY_PRINT;   return(IDXONEATT);}
({xmlwhitespace}+idxTwo{equality}) {YY_PRINT;   return(IDXTWOATT);}
({xmlwhitespace}+coef{equality}) {YY_PRINT;   return(COEFATT);}
({xmlwhitespace}+value{equality}) {YY_PRINT;  return(VALUEATT);}
({xmlwhitespace}+startIdx{equality}) {YY_PRINT; return(STARTIDXATT);}
({xmlwhitespace}+horizon{equality}) {YY_PRINT; return(HORIZONATT);}
({xmlwhitespace}+start{equality}) {YY_PRINT; return(STARTATT);}

({xmlwhitespace}+id{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(IDATT);}
({xmlwhitespace}+id{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(IDATT);}
({xmlwhitespace}+type{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(TYPEATT);}
({xmlwhitespace}+type{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(TYPEATT);}
({xmlwhitespace}+name{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(NAMEATT);}
({xmlwhitespace}+name{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(NAMEATT);}

 /* patterns for <quadraticCoefficients> */
{xmlwhitespace}*\<\/osil{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(OSILEND);}
{xmlwhitespace}*\<\/instanceData{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(INSTANCEDATAEND);}
{xmlwhitespace}*\<instanceData{xmlwhitespace}*\/\>{xmlwhitespace}* {YY_PRINT; return(INSTANCEDATASTARTEND);}
{xmlwhitespace}*\<quadraticCoefficients {YY_PRINT; return(QUADRATICCOEFFICIENTSSTART);}
{xmlwhitespace}*\<\/quadraticCoefficients{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(QUADRATICCOEFFICIENTSEND);}
{xmlwhitespace}*\<qTerm {YY_PRINT; return(QTERMSTART);}
{xmlwhitespace}*\<\/qTerm{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(QTERMEND);}

 /* patterns for <nonlinearExpressions> */
{xmlwhitespace}*\<nonlinearExpressions {YY_PRINT;  return(NONLINEAREXPRESSIONSSTART);}
{xmlwhitespace}*\<\/nonlinearExpressions{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(NONLINEAREXPRESSIONSEND);}
{xmlwhitespace}*\<nl {YY_PRINT; return(NLSTART);}
{xmlwhitespace}*\<\/nl{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(NLEND);}
{xmlwhitespace}*\<times{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(TIMESSTART);}
{xmlwhitespace}*\<\/times{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(TIMESEND);}
{xmlwhitespace}*\<divide{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(DIVIDESTART);}
{xmlwhitespace}*\<\/divide{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(DIVIDEEND);}
{xmlwhitespace}*\<plus{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(PLUSSTART);}
{xmlwhitespace}*\<\/plus{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(PLUSEND);}
{xmlwhitespace}*\<minus{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MINUSSTART);}
{xmlwhitespace}*\<\/minus{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MINUSEND);}
{xmlwhitespace}*\<negate{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(NEGATESTART);}
{xmlwhitespace}*\<\/negate{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(NEGATEEND);}
{xmlwhitespace}*\<power{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(POWERSTART);}
{xmlwhitespace}*\<\/power{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(POWEREND);}
{xmlwhitespace}*\<ln{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(LNSTART);}
{xmlwhitespace}*\<\/ln{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(LNEND);}
{xmlwhitespace}*\<squareRoot{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(SQRTSTART);}
{xmlwhitespace}*\<\/squareRoot{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(SQRTEND);}
{xmlwhitespace}*\<square{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(SQUARESTART);}
{xmlwhitespace}*\<\/square{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(SQUAREEND);}
{xmlwhitespace}*\<sin{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(SINSTART);}
{xmlwhitespace}*\<\/sin{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(SINEND);}
{xmlwhitespace}*\<cos{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(COSSTART);}
{xmlwhitespace}*\<\/cos{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(COSEND);}
{xmlwhitespace}*\<exp{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(EXPSTART);}
{xmlwhitespace}*\<\/exp{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(EXPEND);}
{xmlwhitespace}*\<abs{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(ABSSTART);}
{xmlwhitespace}*\<\/abs{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(ABSEND);}
{xmlwhitespace}*\<erf{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(ERFSTART);}
{xmlwhitespace}*\<\/erf{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(ERFEND);}
{xmlwhitespace}*\<if{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(IFSTART);}
{xmlwhitespace}*\<\/if{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(IFEND);}
{xmlwhitespace}*\<max{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MAXSTART);}
{xmlwhitespace}*\<\/max{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MAXEND);}
{xmlwhitespace}*\<min{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MINSTART);}
{xmlwhitespace}*\<\/min{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MINEND);}
{xmlwhitespace}*\<sum{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(SUMSTART);}
{xmlwhitespace}*\<\/sum{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(SUMEND);}
{xmlwhitespace}*\<allDiff{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(ALLDIFFSTART);}
{xmlwhitespace}*\<\/allDiff{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(ALLDIFFEND);}
{xmlwhitespace}*\<product{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(PRODUCTSTART);}
{xmlwhitespace}*\<\/product{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(PRODUCTEND);}

{xmlwhitespace}*\<number {YY_PRINT; return(NUMBERSTART);}
{xmlwhitespace}*\<\/number{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(NUMBEREND);}
{xmlwhitespace}*\<E {YY_PRINT; return(ESTART);}
{xmlwhitespace}*\<\/E{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(EEND);}
{xmlwhitespace}*\<PI {YY_PRINT; return(PISTART);}
{xmlwhitespace}*\<\/PI{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(PIEND);}
{xmlwhitespace}*\<variable {YY_PRINT;  return(VARIABLESTART);}
{xmlwhitespace}*\<\/variable{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(VARIABLEEND);}

 /* patterns for <timeDomain> element */
{xmlwhitespace}*\<timeDomain {YY_PRINT; return(TIMEDOMAINSTART);}
{xmlwhitespace}*\<\/timeDomain{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(TIMEDOMAINEND);}
{xmlwhitespace}*\<stages {YY_PRINT; return(STAGESSTART);}
{xmlwhitespace}*\<\/stages{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(STAGESEND);}
{xmlwhitespace}*\<stage {YY_PRINT; return(STAGESTART);}
{xmlwhitespace}*\<\/stage{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(STAGEEND);}
{xmlwhitespace}*\<variables {YY_PRINT; return(VARIABLESSTART);}
{xmlwhitespace}*\<\/variables{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(VARIABLESEND);}
{xmlwhitespace}*\<constraints {YY_PRINT; return(CONSTRAINTSSTART);}
{xmlwhitespace}*\<\/constraints{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(CONSTRAINTSEND);}
{xmlwhitespace}*\<objectives {YY_PRINT; return(OBJECTIVESSTART);}
{xmlwhitespace}*\<\/objectives{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(OBJECTIVESEND);}
{xmlwhitespace}*\<var {YY_PRINT; return(VARSTART);}
{xmlwhitespace}*\<\/var{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(VAREND);}
{xmlwhitespace}*\<con {YY_PRINT; return(CONSTART);}
{xmlwhitespace}*\<\/con{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(CONEND);}
{xmlwhitespace}*\<obj {YY_PRINT; return(OBJSTART);}
{xmlwhitespace}*\<\/obj{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(OBJEND);}
{xmlwhitespace}*\<interval {YY_PRINT; return(INTERVALSTART);}
{xmlwhitespace}*\<\/interval{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(INTERVALEND);}


 /* patterns for <parametersAndStochasticElements> 
{xmlwhitespace}*\<parametersAndStochasticElements {YY_PRINT; return(PARAMETERSSTART);}
{xmlwhitespace}*\<\/parametersAndStochasticElements{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(PARAMETERSEND);}
{xmlwhitespace}*\<param {YY_PRINT; return(PARAMSTART);}
{xmlwhitespace}*\<\/param{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(PARAMEND);}
*/

 "<!--" BEGIN comment;
 <comment>. |
 <comment>\n ;
 <comment>"-->" BEGIN 0;
 
  "<?" BEGIN xmldeclaration;
 <xmldeclaration>. |
 <xmldeclaration>\n ;
 <xmldeclaration>"?>" BEGIN 0;
 

<doublequoteattributetext>[^\"]* {YY_PRINT;  BEGIN 0; /*yylval->sval = strdup(yytext);*/ yylval->sval = yytext; return(ATTRIBUTETEXT);}
<singlequoteattributetext>[^\']* {YY_PRINT;  BEGIN 0; /*yylval->sval = strdup(yytext);*/ yylval->sval = yytext; return(ATTRIBUTETEXT);}

. {  
	std::string error;
	std::ostringstream outStr;
	outStr << "encountered a spurious character in the lexer" << endl;
	outStr << "The first character is: ";
	outStr <<  yytext;
	outStr << endl;
	outStr << "See line number: " << yylineno << endl;  
	error = outStr.str();
	throw ErrorClass( error);
}

%%

