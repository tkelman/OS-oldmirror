/**    
 *
 *
 * @author  Robert Fourer, Jun Ma, Kipp Martin, 
 * @version 1.0, 10/05/2005
 * @since   OS1.0
 */ 
   
 
#include<stdlib.h>
#include <OsiSolverInterface.hpp>   
#include <CoinMessageHandler.hpp> 
#include <CoinPackedMatrix.hpp> 
#include <cppad/cppad.hpp> // the CppAD package http://www.coin-or.org/CppAD/
#include <string>
#include "OSMatlab.h"
  
using std::cout;   
using std::endl;
 

#include "OSResult.h" 
#include "OSiLReader.h"        
#include "OSiLWriter.h" 
#include "OSrLReader.h"        
#include "OSrLWriter.h"      
#include "OSInstance.h"  
#include "FileUtil.h"  
#include "OSConfig.h" 
#include "CoinSolver.h"
#include "DefaultSolver.h"  
#include "WSUtil.h" 
#include "OSSolverAgent.h"   
#include "OShL.h"     
#include "ErrorClass.h"
#include "OSmps2osil.h"   
#include "Base64.h"
#ifdef COIN_HAS_ASL
#include "OSnl2osil.h"
#endif
#ifdef COIN_HAS_LINDO    
#include "LindoSolver.h"
#endif  

#ifdef COIN_HAS_IPOPT    
#include "IpoptSolver.h"
#endif 
 
#include "CoinHelperFunctions.hpp"
#include <time.h>
#include <sstream>

double getObjVal(std::string osrl);
  
#include "OsiClpSolverInterface.hpp" 

int main(int argC, char* argV[])
{
	using CppAD::NearEqual;
	bool ok;
	double check;
	sqrt(4);
	std::cout << "HELLO WORLD  " << sqrt(-5.21405e-08) << std::endl;
	return 0;
	cout << "START UNIT TEST" << endl;
	// define the classes
	FileUtil *fileUtil = NULL;  
	#ifdef COIN_HAS_ASL
	OSnl2osil *nl2osil = NULL;
	#endif 
	OSmps2osil *mps2osil = NULL;
	DefaultSolver *m_Solver  = NULL;
	// end classes    
	std::string osilFileName;
	std::string ipOptFileName;
	std::string nlFileName; 
	std::string lindoFileName;
	std::string cbcFileName;
	std::string mpsFileName;     
	std::string parserTestOSiLFileName;
	std::string osil;
	// get the input files
	 const char dirsep =  CoinFindDirSeparator();
  	// Set directory containing mps data files.
  	std::string dataDir;
    dataDir = dirsep == '/' ? "../data/" : "..\\data\\";
	std::string osol = "<osol></osoL>";
	osilFileName =  dataDir + "parincLinear.osil";
	//ipOptFileName =  dataDir +   "HS071_NLP.osil";
	//ipOptFileName =  dataDir + "aircrafta.osil";
	//ipOptFileName =  dataDir + "markowitz.osil";
	//ipOptFileName =  dataDir + "rosenbrock.osil";
	//ipOptFileName =  dataDir + "blockqp1.osil";
	ipOptFileName =  dataDir + "avion2.osil";
	lindoFileName = dataDir + "lindoapiaddins.osil";
	//lindoFileName = dataDir + "blockqp1.osil";
	//lindoFileName = dataDir + "aircrafta.osil";
	nlFileName = dataDir + "hs71.nl";
	mpsFileName =  dataDir + "parinc.mps";
	parserTestOSiLFileName = dataDir + "parincLinear.osil"; 
	fileUtil = new FileUtil();
	// solve using using the osil file
	#ifdef COIN_HAS_IPOPT
	cout << "create a new IPOPT Solver for OSiL string solution" << endl;
	SmartPtr<IpoptSolver> ipoptSolver  = new IpoptSolver();	
	try{
		ok = true;
		OSiLReader *osilreader = NULL;
		ipOptFileName =  dataDir + "avion2.osil";
		osil = fileUtil->getFileAsString( &ipOptFileName[0]);
		cout << "IPOPT Solver created for OSiL string solution" << endl;
		ipoptSolver->osol = osol;
		osilreader = new OSiLReader(); 
		ipoptSolver->osinstance = osilreader->readOSiL( &osil);
		cout << "call the IPOPT Solver" << endl;	
		ipoptSolver->solve();
		cout << "Here is the IPOPT solver solution for avion2" << endl;
		check = 9.46801e+07;
		ok &= NearEqual(getObjVal( ipoptSolver->osrl) , check,  1e-10 , 1e-10);
		if(ok == false) throw ErrorClass(" Fail unit test with Ipopt on avion2");
		delete osilreader;
		osilreader = NULL;
		// solve another problem
		// a problem with all nonlinear terms no linear terms
		ipOptFileName =  dataDir + "HS071_NLP.osil";
		osil = fileUtil->getFileAsString( &ipOptFileName[0]);
		cout << "IPOPT Solver created for OSiL string solution" << endl;
		ipoptSolver->osol = osol;
		osilreader = new OSiLReader(); 
		ipoptSolver->osinstance = osilreader->readOSiL( &osil);
		OSiLWriter osilwriter;
		cout << osilwriter.writeOSiL( ipoptSolver->osinstance) << endl;
		cout << "call the IPOPT Solver" << endl;
		ipoptSolver->solve();
		cout << "Here is the IPOPT solver solution for HS071_NLP" << endl;
		check = 17.014;
		ok &= NearEqual(getObjVal( ipoptSolver->osrl) , check,  1e-10 , 1e-10);
		if(ok == false) throw ErrorClass(" Fail unit test with Ipopt on HS071_NLP");
		delete osilreader;
		osilreader = NULL;
		// solve another problem
		// a problem with both quadratic terms and general nonlinear terms
		ipOptFileName =  dataDir + "rosenbrockmod.osil";
		osil = fileUtil->getFileAsString( &ipOptFileName[0]);
		cout << "IPOPT Solver created for OSiL string solution" << endl;
		ipoptSolver->osol = osol;
		osilreader = new OSiLReader(); 
		ipoptSolver->osinstance = osilreader->readOSiL( &osil);
		cout << "call the IPOPT Solver" << endl;
		ipoptSolver->solve();
		cout << "Here is the IPOPT solver solution for rosenbrockmod" << endl;
		check = 6.7279;
		ok &= NearEqual(getObjVal( ipoptSolver->osrl) , check,  1e-10 , 1e-10);
		if(ok == false) throw ErrorClass(" Fail unit test with Ipopt on rosenbrock");
		delete osilreader;
		osilreader = NULL;
		// solve another problem
		// a problem that is a pure quadratic
		ipOptFileName =  dataDir + "parincQuadratic.osil";
		osil = fileUtil->getFileAsString( &ipOptFileName[0]);
		cout << "IPOPT Solver created for OSiL string solution" << endl;
		ipoptSolver->osol = osol;
		osilreader = new OSiLReader(); 
		ipoptSolver->osinstance = osilreader->readOSiL( &osil);
		cout << "call the IPOPT Solver" << endl;
		ipoptSolver->solve();
		cout << "Here is the IPOPT solver solution for rosenbrockmod" << endl;
		check = 49920.5;
		ok &= NearEqual(getObjVal( ipoptSolver->osrl) , check,  1e-10 , 1e-10);
		if(ok == false) throw ErrorClass(" Fail unit test with Ipopt on parincQuadradic");
		delete osilreader;
		osilreader = NULL;	
		// solve another problem
		// try a pure linear program
		ipOptFileName =  dataDir + "parincLinear.osil";
		osil = fileUtil->getFileAsString( &ipOptFileName[0]);
		cout << "IPOPT Solver created for OSiL string solution" << endl;
		ipoptSolver->osol = osol;
		osilreader = new OSiLReader(); 
		ipoptSolver->osinstance = osilreader->readOSiL( &osil);
		cout << "call the IPOPT Solver" << endl;
		ipoptSolver->solve();
		cout << "Here is the IPOPT solver solution for parincLinear" << endl;
		check = 7668;
		ok &= NearEqual(getObjVal( ipoptSolver->osrl) , check,  1e-1 , 1e-1);
		if(ok == false) throw ErrorClass(" Fail unit test with Ipopt on parincLinear");
		delete osilreader;
		osilreader = NULL;			
		// not we do not delete ipoptSolver -- this is a smart pointer
		//delete m_Solver;
		//m_Solver = NULL;			
		// not we do not delete ipoptSolver -- this is a smart pointer
		//delete m_Solver;
		//m_Solver = NULL;	
	}
	catch(const ErrorClass& eclass){
		cout << endl << endl << endl;
		cout << "Sorry Unit Test Failed Testing the Ipopt Solver:"  + eclass.errormsg<< endl;
		return 0;
	}
	#endif
	try{
		ok = true; 
		cbcFileName = dataDir + "parincLinear.osil";
		osil = fileUtil->getFileAsString( &cbcFileName[0]);
		m_Solver = new CoinSolver();
		m_Solver->m_sSolverName = "cbc";
		m_Solver->osil = osil;
		m_Solver->osol = osol;  
		m_Solver->osinstance = NULL; 
		cout << "call the COIN - Cbc Solver for parincLinear" << endl;
		m_Solver->solve();
		cout << "Here is the COIN Cbc solver solution for parincLinear" << endl;
		cout << m_Solver->osrl << endl;
		check = 7668;
		ok &= NearEqual(getObjVal( m_Solver->osrl) , check,  1e-1 , 1e-1);
		if(ok == false) throw ErrorClass(" Fail unit test with Cbc on parincLinear");
		delete m_Solver;
		m_Solver = NULL;
		cout << "solution using an OSiL string a success" << endl;
		// now solve another problem -- try an integer program
		// this problem is also stored in base64 binary
		cbcFileName = dataDir + "p0033.osil";
		osil = fileUtil->getFileAsString( &cbcFileName[0]);
		m_Solver = new CoinSolver();
		m_Solver->m_sSolverName = "cbc";
		m_Solver->osil = osil;
		m_Solver->osol = osol;  
		m_Solver->osinstance = NULL; 
		cout << "call the COIN - Cbc Solver for p0033" << endl;
		m_Solver->solve();
		cout << "Here is the COIN Cbc solver solution for p0033" << endl;
		//cout << m_Solver->osrl << endl;
		check = 3089;
		ok &= NearEqual(getObjVal( m_Solver->osrl) , check,  1e-1 , 1e-1);
		if(ok == false) throw ErrorClass(" Fail unit test with Cbc on p0033");
		delete m_Solver;
		m_Solver = NULL;
	}
	catch(const ErrorClass& eclass){
		cout << "OSrL =  " <<  m_Solver->osrl <<  endl;
		cout << endl << endl << endl;
		cout << "Sorry Unit Test Failed Testing the Cbc Solver" << endl;
		return 0;
	}
	#ifdef COIN_HAS_LINDO
	try{
		osil = fileUtil->getFileAsString( &lindoFileName[0]);
		cout << "create a new LINDO Solver for OSiL string solution" << endl;
		m_Solver = new LindoSolver();	
		m_Solver->osil = osil;
		m_Solver->osol = osol;
		m_Solver->osinstance = NULL;
		cout << "call the LINDO Solver" << endl;
		m_Solver->solve();
		cout << "Here is the LINDO solver solution" << endl;
		cout << m_Solver->osrl << endl;
		check = 99;
		ok &= NearEqual(getObjVal( m_Solver->osrl) , check,  1e-10 , 1e-10);
		if(ok == false) throw ErrorClass(" Fail unit test with LINDO on lindoapiaddins");
		m_Solver->osinstance = NULL;
		delete m_Solver;
		m_Solver = NULL;
		// now solve the rosenbrock problem from the OSiL paper
		lindoFileName = dataDir + "rosenbrockmod.osil";
		osil = fileUtil->getFileAsString( &lindoFileName[0]);
		m_Solver = new LindoSolver();	
		m_Solver->osil = osil;
		m_Solver->osol = osol;
		m_Solver->osinstance = NULL;
		cout << "call the LINDO Solver" << endl;
		m_Solver->solve();
		cout << "Here is the LINDO solver solution" << endl;
		cout << m_Solver->osrl << endl;
		check = 6.7279;
		ok &= NearEqual(getObjVal( m_Solver->osrl) , check,  1e-10 , 1e-10);
		if(ok == false) throw ErrorClass(" Fail unit test with LINDO on parincQuadratic");
		m_Solver->osinstance = NULL;
		delete m_Solver;
		m_Solver = NULL;
		// now solve a pure quadratic
		lindoFileName = dataDir + "parincQuadratic.osil";
		osil = fileUtil->getFileAsString( &lindoFileName[0]);
		m_Solver = new LindoSolver();	
		m_Solver->osil = osil;
		m_Solver->osol = osol;
		m_Solver->osinstance = NULL;
		cout << "call the LINDO Solver" << endl;
		m_Solver->solve();
		cout << "Here is the LINDO solver solution" << endl;
		cout << m_Solver->osrl << endl;
		check = 49920.5;
		ok &= NearEqual(getObjVal( m_Solver->osrl) , check,  1e-10 , 1e-10);
		if(ok == false) throw ErrorClass(" Fail unit test with LINDO on parincQuadratic");
		m_Solver->osinstance = NULL;
		delete m_Solver;
		m_Solver = NULL;
		
	}
	catch(const ErrorClass& eclass){
		//cout << "OSrL =  " <<  m_Solver->osrl <<  endl;
		cout << endl << endl << endl;
		cout << "Sorry Unit Test Failed Testing the Lindo Solver" << endl;
		return 0;
	}
	#endif
	// end solving using the osil file
	// now solve with an OSInstance created from an MPS file
	try{
		cout << endl;
		cout << "START MPS TESTING" << endl << endl;
		cout << "create a COIN Solver for MPS - OSInstance solution" << endl;
		m_Solver = new CoinSolver();
		m_Solver->m_sSolverName = "cbc";
		mps2osil = new OSmps2osil( mpsFileName);
		mps2osil->createOSInstance() ;
		m_Solver->osinstance = mps2osil->osinstance;
		m_Solver->osol = osol;
		cout << "call COIN Solve" << endl;
		m_Solver->solve();
		cout << "Here is the COIN solver solution" << endl;
		cout << m_Solver->osrl << endl;
		m_Solver->osinstance = NULL;
		delete m_Solver;
		m_Solver = NULL;
		delete mps2osil; 
		mps2osil = NULL;
		cout << endl;
		cout << "DONE WITH MPS TESTING" << endl;
	}
	catch(const ErrorClass& eclass){
		cout << "OSrL =  " <<  m_Solver->osrl <<  endl;
		cout << endl << endl << endl;
		cout << "Sorry Unit Test Failed Testing the Lindo Solver" << endl;
		return 0;
	}
	// now solve with an OSInstance created from an AMPL nl file
	try{
		cout << endl;
		cout << "START AMPL TESTING" << endl << endl;
#ifdef COIN_HAS_ASL
#ifdef COIN_HAS_LINDO
		cout << "create a LINDO Solver for AMPL nl - OSInstance solution" << endl;
		m_Solver = new LindoSolver();
		nl2osil = new OSnl2osil( nlFileName); 
		nl2osil->createOSInstance() ;
		m_Solver->osinstance = nl2osil->osinstance;	
		m_Solver->osol = osol;
		cout << "call LINDO Solve" << endl;
	  
		m_Solver->solve();
		cout << "Here is the LINDO solver solution" << endl;
		cout << m_Solver->osrl << endl;
		m_Solver->osinstance = NULL;
		delete m_Solver;
		m_Solver = NULL;
		cout << "call delete nl2osil" << endl;
		delete nl2osil;
		nl2osil = NULL;	 
#endif
		cout << "create a COIN Solver for AMPL nl - OSInstance solution" << endl;
		/*m_Solver = new CoinSolver();
		m_Solver->m_sSolverName = "cbc";
		nl2osil = new OSnl2osil( nlFileName);
		nl2osil->createOSInstance() ;
		m_Solver->osinstance = nl2osil->osinstance;
		m_Solver->osol = osol;
		cout << "call COIN Solve" << endl;
		m_Solver->solve();
		cout << "Here is the COIN solver solution" << endl;
		cout << m_Solver->osrl << endl;
		m_Solver->osinstance = NULL;
		delete m_Solver;
		m_Solver = NULL;
		delete nl2osil;
		nl2osil = NULL;	   
		cout << endl;
		*/
#endif
		cout << "END AMPL TESTING" << endl << endl;
	}	
		catch(const ErrorClass& eclass){
		cout << "OSrL =  " <<  m_Solver->osrl <<  endl;
		cout << endl << endl << endl;
		cout << "Sorry Unit Test Failed Testing with AMPL" << endl;
		return 0;
	}
	//
	// Now test the b64 feature
	//
	try{
		cout << endl;
		cout << endl;
		cout << "TESTING BASE 64 WITH A COIN SOLVER"<< endl;
		cout << endl;
		OSiLWriter osilwriter;
		osilwriter.m_bWriteBase64 = true;
		m_Solver = new CoinSolver();
		m_Solver->m_sSolverName = "cbc";
		mps2osil = new OSmps2osil( mpsFileName);
		m_Solver->osinstance = NULL;
		m_Solver->osol = osol;
		mps2osil->createOSInstance() ;
		m_Solver->osil = osilwriter.writeOSiL( mps2osil->osinstance) ;
		std::cout << m_Solver->osil << std::endl;
		// extra code
		std::string outputfile = mpsFileName+"_osil";
		char* testfile = &outputfile[0];
		//
		//
		//fileUtil->writeFileFromString(testfile,  m_Solver->osil);
		//	
		// end extra code
		m_Solver->solve();
		cout << endl << endl;
		cout << "COIN solution of a OSiL string in b64 format" << endl;
		cout << m_Solver->osrl;
		m_Solver->osinstance = NULL;
		delete m_Solver;
		m_Solver = NULL;
		delete mps2osil;
		mps2osil = NULL;
	}	
	catch(const ErrorClass& eclass){
		cout << endl << endl;
		cout << eclass.errormsg <<  endl << endl;
		cout << "OSrL =  " <<  m_Solver->osrl <<  endl;
		cout << endl << endl << endl;
		cout << "Sorry Unit Test Failed Testing Use of Base 64" << endl;
		return 0;

	}  
	//
	// Now just test the OSiL parser
	try{ 
		cout << endl;
		clock_t start, finish;
		double duration;
		OSiLWriter *osilwriter = NULL;
		osilwriter = new OSiLWriter();
		//delete fileUtil;
		//fileUtil = NULL;
		//fileUtil = new FileUtil();
		cout << "TEST PARSING A MODEL" << endl;
		cout << "FIRST READ THE FILE INTO A STRING" << endl;
		start = clock();
		osil = fileUtil->getFileAsString( &parserTestOSiLFileName[0]);
		finish = clock();
		duration = (double) (finish - start) / CLOCKS_PER_SEC;
		cout << "Reading the file into a string took (seconds): "<< duration << endl;
		OSiLReader *osilreader = NULL;
		osilreader = new OSiLReader(); 
		start = clock();
		cout << "PARSE THE OSIL STRING INTO AN OSINSTNACE OBJECT" << endl;
		osilreader->readOSiL( &osil);
		//cout << osilwriter->writeOSiL( osilreader->readOSiL( &osil)) << endl;
		delete osilreader;
		osilreader = 0;
		finish = clock();
		duration = (double) (finish - start) / CLOCKS_PER_SEC;
		cout << "Parsing took (seconds): "<< duration << endl;

	}	
		catch(const ErrorClass& eclass){
		cout << endl << endl << endl;
		cout << eclass.errormsg << endl;
		cout << "Sorry Unit Test Failed Testing An OSiL Parser" << endl;
		return 0;
	}	
	
	//
	// Now just test the OSrL parser
	try{ 
		cout << endl;
		clock_t start, finish;
		double duration;
		OSrLWriter *osrlwriter = NULL;
		osrlwriter = new OSrLWriter();
		OSrLReader *osrlreader = NULL;
		osrlreader = new OSrLReader();
		OSResult *osresult = NULL;
		osresult = new OSResult(); 
		cout << "TEST PARSING AN OSrL FILE" << endl;
		cout << "FIRST READ THE OSrL FILE INTO A STRING" << endl;
		parserTestOSiLFileName = dataDir + "parincLinear.osrl"; 
		start = clock();
		std::string osrl = fileUtil->getFileAsString( &parserTestOSiLFileName[0]);
		finish = clock();
		duration = (double) (finish - start) / CLOCKS_PER_SEC;
		cout << "Reading the file into a string took (seconds): "<< duration << endl;
		start = clock();
		cout << "PARSE THE OSRL STRING INTO AN OSRESULT OBJECT" << endl;
		osresult = osrlreader->readOSrL( osrl);
		cout << osrlwriter->writeOSrL( osresult) << endl;
		delete osrlwriter;
		osrlwriter = NULL;
		delete osrlreader;
		osrlreader = NULL;
		delete osresult;
		osresult = NULL;
		finish = clock();
		duration = (double) (finish - start) / CLOCKS_PER_SEC;
		cout << "Parsing took (seconds): "<< duration << endl;

	}	
		catch(const ErrorClass& eclass){
		cout << endl << endl << endl;
		cout << eclass.errormsg << endl;
		cout << "Sorry Unit Test Failed Testing An OSrL Parser" << endl;
		return 0;
	}
	// now test postfix and prefix routines
	try{
		std::string expTreeTest =  dataDir + "rosenbrockmod.osil";
		osil = fileUtil->getFileAsString( &expTreeTest[0]);
		OSInstance *osinstance = NULL;
		osinstance = new OSInstance();
		OSiLReader *osilreader = NULL;
		osilreader = new OSiLReader();
		//create an osinstance
		osinstance = osilreader->readOSiL( &osil);
		OSExpressionTree* expTree = osinstance->getNonlinearExpressionTree( -1);
		std::vector<OSnLNode*> postfixVec;
		postfixVec = expTree->m_treeRoot->getPostfixFromExpressionTree();
		int n = postfixVec.size();
		std::string *nodeNames1 = new std::string[ n];
		std::string *nodeNames2 = new std::string[ n];
		for (int i = 0 ; i < n; i++){
			//std::cout << postfixVec[i]->snodeName << std::endl;
			nodeNames1[i] = postfixVec[i]->snodeName;
		}
		// now create back the expression tree 
		expTree->m_treeRoot = postfixVec[ n - 1]->createExpressionTreeFromPostfix( postfixVec);
		// now get in prefix
		std::vector<OSnLNode*> prefixVec;
		prefixVec = expTree->m_treeRoot->getPrefixFromExpressionTree();
		// now create back the expression tree
		expTree->m_treeRoot = prefixVec[ 0]->createExpressionTreeFromPrefix( prefixVec);
		// now get postfix vector again and compare with original
		postfixVec = expTree->m_treeRoot->getPostfixFromExpressionTree();
		if(postfixVec.size() != n) throw ErrorClass(" Problem with creating expression trees");
		std::cout << std::endl << std::endl;
		for (int i = 0 ; i < n; i++){
			//std::cout << postfixVec[i]->snodeName << std::endl;
			nodeNames2[i] = postfixVec[i]->snodeName;
			if( nodeNames1[i] != nodeNames2[ i]) throw ErrorClass(" Problem with creating expression trees");
		}		
		//delete osinstance;
		osinstance = NULL;
		delete osilreader;
		osilreader = NULL;
		
	}
	catch(const ErrorClass& eclass){
		cout << endl << endl << endl;
		cout << eclass.errormsg << endl;
		cout << "Sorry Unit Test Failed Testing Prefix and Postfix routines" << endl;
		return 0;
	}
	// now test the nonlinear operators
	
	try{
		ok = true;
		std::cout << "Test nonlinear operators" << std::endl;
		std::string operatorTest =  dataDir + "testOperators.osil";
		//std::string operatorTest =  dataDir + "parincLinear.osil";
		//std::string operatorTest =  dataDir + "osilrosenbrockmodsum.osil";
		osil = fileUtil->getFileAsString( &operatorTest[0]);
		OSInstance *osinstance = NULL;
		osinstance = new OSInstance();
		OSiLReader *osilreader = NULL;
		osilreader = new OSiLReader();
		OSiLWriter *osilwriter = NULL;
		osilwriter = new OSiLWriter();
		osinstance = osilreader->readOSiL( &osil);
		OSExpressionTree* expTree = osinstance->getNonlinearExpressionTree( -1);
		std::vector<OSnLNode*> postfixVec;
		postfixVec = expTree->m_treeRoot->getPostfixFromExpressionTree();
		int n = postfixVec.size();
		std::string *nodeNames1 = new std::string[ n];
		std::string *nodeNames2 = new std::string[ n];
		for (int i = 0 ; i < n; i++){
			std::cout << postfixVec[i]->snodeName << std::endl;
			nodeNames1[i] = postfixVec[i]->snodeName;
		}
		std::cout << std::endl << std::endl;
		std::cout << osilwriter->writeOSiL( osinstance) << std::endl;
		// now test value
		double *x = NULL;
		x = new double[2];
		x[0] = 1;
		x[1] = 2;
		double parserTestVal = expTree->m_treeRoot->calculateFunction( x);
		std::cout << "ParserTest Val = " << parserTestVal << std::endl;
		check = 11;
		ok &= NearEqual(expTree->m_treeRoot->calculateFunction( x) , check,  1e-10 , 1e-10);
		if(ok == false) throw ErrorClass(" Problem evaluating expression tree");
		osinstance = NULL;
		delete osilreader;
		osilreader = NULL;
		delete osilwriter;
		osilwriter = NULL;
		//create an osinstance
	}
	catch(const ErrorClass& eclass){
		cout << endl << endl << endl;
		cout << eclass.errormsg << endl;
		cout << "Sorry Unit Test Failed Nonlinear Operator Tests" << endl;
		return 0;
	}
	// 
	// now solve on a remote server
	/*
	try{
		//return 0;
		OSSolverAgent* osagent = NULL;
		//osagent = new OSSolverAgent("128.135.130.17/axis/OSSolverService");
		//osagent = new OSSolverAgent("gsbkip.chicagogsb.edu:80/os/ossolver/COINSolverService.jws");
		//osagent = new OSSolverAgent("localhost/os/ossolver/COINSolverService.jws");
		//osagent = new OSSolverAgent("localhost/axis/OSSolverService");
		osagent = new OSSolverAgent("http://127.0.0.1:8080/os/ossolver/CoinSolverService.jws");
		//osagent = new OSSolverAgent("128.135.130.17:8080/os/ossolver/CoinSolverService.jws");
		//osagent = new OSSolverAgent("127.0.0.1:8080/web-services-examples/ted/VrptsSolverService.jws");
		cout << "Place remote synchronous call" << endl;
		nl2osil = new OSnl2osil( nlFileName);
		nl2osil->createOSInstance() ;
		OSiLWriter *osilwriter = NULL;
		osilwriter = new OSiLWriter();
		osil = osilwriter->writeOSiL( nl2osil->osinstance) ;
		string osrl = osagent->solve(osil, osol);
		cout << "READ THE OSrL and WRITE IT AGAIN" << endl;
		cout << osrl  << endl;
		OSrLReader *osrlreader = NULL;
		OSResult *osresult = NULL;
		osrlreader = new OSrLReader();
		osresult = osrlreader->readOSrL( osrl);
		OSrLWriter *osrlwriter;
		if(osresult != NULL){
			osrlwriter = new OSrLWriter();
			osrl = osrlwriter->writeOSrL( osresult);
		}
		cout << osrl << endl;
		//
		delete nl2osil;
		nl2osil = NULL;
		delete osilwriter;
		osilwriter = NULL;
	}	
		catch(const ErrorClass& eclass){
		cout <<  eclass.errormsg <<  endl;
	}	
	*/
	cout << endl << endl << endl;
	cout << "Congratulations: you passed the unit Test" << endl;
	return 0;	
}

double getObjVal( std::string osrl){
	std::string sObjVal;
	double dObjVal;
	int pos2;
	int pos1 = osrl.find( "<obj ");
	if(pos1 != std::string::npos){
		// get the end of the obj start tag
		pos1 = osrl.find(">", pos1 + 1);
		if(pos1 != std::string::npos){
			// get the start of obj end tag
			pos2 = osrl.find( "</obj", pos1 + 1);
			if( pos2 != std::string::npos){
				// get the substrind
				sObjVal = osrl.substr( pos1 + 1, pos2 - pos1 - 1);
				//std::cout << "HERE IS THE OBJECTIVE FUNCTION VALUE SUBSTRING  " << sObjVal<< std::endl; 
				return dObjVal = atof( sObjVal.c_str() ); 
			}
			else return OSNAN;
		}
		else return OSNAN;
	}
	else return OSNAN;
}
