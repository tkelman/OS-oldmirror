/** @file OSInstance.cpp
 * \brief This file defines the OSInstance class along with its supporting classes..
 *
 * @author  Robert Fourer,  Jun Ma, Kipp Martin, 
 * @version 1.0, 10/05/2005
 * @since   OS1.0
 *
 * \remarks
 * Copyright (C) 2005, Robert Fourer, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 *  
 */

#include "OSInstance.h"
#include "MathUtil.h"
#include "CommonUtil.h"
#include "ErrorClass.h"
#include "OSParameters.h"
#include<iostream> 
#include<sstream>

#define DEBUG
 
using namespace std;

OSInstance::OSInstance(): 
	m_sInstanceName(""),
	m_sInstanceSource(""),	
	m_sInstanceDescription(""),
	m_bProcessVariables(false),
	m_iVariableNumber(-1),
	m_iNumberOfBinaryVariables( 0),
	m_iNumberOfIntegerVariables( 0),
	m_iNumberOfNonlinearVariables( 0),
	m_msVariableNames(NULL),
	m_mdVariableInitialValues(NULL),
	m_msVariableInitialStringValues(NULL),
	m_mcVariableTypes(NULL),
	m_mdVariableLowerBounds(NULL),
	m_mdVariableUpperBounds(NULL),
	m_bProcessObjectives(false),
	m_iObjectiveNumber(-1),
	m_msObjectiveNames(NULL),
	m_msMaxOrMins(NULL),
	m_miNumberOfObjCoef(NULL),
	m_miNonLinearVarsReverseMap( NULL),
	m_mdObjectiveConstants(NULL),
	m_mdObjectiveWeights(NULL),
	m_mdConstraintFunctionValues( NULL),
	m_mdObjectiveFunctionValues( NULL),
	m_mdObjGradient(NULL),
	m_iHighestTaylorCoeffOrder(-1),
	m_bCppADFunIsCreated( false),
	m_LagrangianExpTree(NULL),
	m_bLagrangianExpTreeCreated( false),
	m_LagrangianSparseHessian( NULL),
	m_bLagrangianSparseHessianCreated( false),
	m_bCppADTapesBuilt( false),
	m_bAllNonlinearVariablesIndex( false),
	m_mObjectiveCoefficients(NULL),
	m_bGetDenseObjectives(false),
	m_mmdDenseObjectiveCoefficients(NULL),
	m_bProcessConstraints(false),
	m_iConstraintNumber(-1),
	m_msConstraintNames(NULL),
	m_mdConstraintLowerBounds(NULL),
	m_mdConstraintUpperBounds(NULL),
	m_mcConstraintTypes(NULL),
 	m_mdConstraintConstants( NULL),
	m_bDuplicateExpressionTreesMap( false),
	m_bNonLinearStructuresInitialized( false),
	m_bQTermsAdded( false),
	m_bSparseJacobianCalculated( false),
	m_iJacValueSize( 0),
	m_miJacStart( NULL),
	m_miJacIndex( NULL),
	m_mdJacValue( NULL),
	m_miJacNumConTerms( NULL),
	m_sparseJacMatrix( NULL),
	m_bProcessLinearConstraintCoefficients(false),
	m_iLinearConstraintCoefficientNumber(-1),
	m_bColumnMajor(true),
	m_linearConstraintCoefficientsInColumnMajor(NULL),
	m_linearConstraintCoefficientsInRowMajor(NULL),
	m_bProcessQuadraticTerms(false),
	m_iQuadraticTermNumber(-1),
	m_quadraticTerms(0),
	m_iNonlinearExpressionNumber( -1),
	m_bProcessExpressionTrees( false),
	m_iConstraintNumberNonlinear( 0),
	m_iObjectiveNumberNonlinear( 0),
	m_iHighestOrderEvaluated( -1)
{    
	#ifdef DEBUG
	cout << "Inside OSInstance Constructor" << endl;
	#endif
	this->instanceHeader = new InstanceHeader();
	this->instanceData = new InstanceData();
}  

OSInstance::~OSInstance(){
	#ifdef DEBUG
	cout << "OSInstance Destructor Called" << endl;
	#endif
	std::map<int, OSExpressionTree*>::iterator posMapExpTree;
	// delete  the temporary arrays
	delete[] m_msVariableNames;
	m_msVariableNames = NULL;
	delete[] m_mdVariableInitialValues;
	m_mdVariableInitialValues = NULL ;
	delete[] m_msVariableInitialStringValues;
	m_msVariableInitialStringValues = NULL;
	delete[] m_mcVariableTypes;
	m_mcVariableTypes = NULL;
	delete[] m_msObjectiveNames;
	m_msObjectiveNames = NULL;
	delete[] m_msMaxOrMins;
	m_msMaxOrMins = NULL;
	delete[] m_miNumberOfObjCoef;
	m_miNumberOfObjCoef = NULL;
	delete[] m_mdObjectiveConstants; 
	m_mdObjectiveConstants = NULL;
	delete[] m_mdObjectiveWeights;
	m_mdObjectiveWeights = NULL;
	delete[] m_mObjectiveCoefficients;
	m_mObjectiveCoefficients = NULL;
	delete[] m_miNonLinearVarsReverseMap;
	m_miNonLinearVarsReverseMap = NULL;
	int i;
	if(instanceData->objectives->numberOfObjectives > 0 && m_mObjectiveCoefficients != NULL){
		for(i = 0; i < instanceData->objectives->numberOfObjectives; i++){
			delete m_mObjectiveCoefficients[i];
			m_mObjectiveCoefficients[i] = NULL;
		}
		m_mObjectiveCoefficients = NULL;
	}
	if(instanceData->objectives->numberOfObjectives > 0 && m_mmdDenseObjectiveCoefficients != NULL){
		for(i = 0; i < instanceData->objectives->numberOfObjectives; i++){
			delete[] m_mmdDenseObjectiveCoefficients[i];
			m_mmdDenseObjectiveCoefficients[i] = NULL;
		}
		m_mmdDenseObjectiveCoefficients = NULL;
	}
	delete[] m_msConstraintNames;
	m_msConstraintNames = NULL;
	delete[] m_mcConstraintTypes;
	m_mcConstraintTypes = NULL;
	delete[]  m_mdConstraintConstants;
	 m_mdConstraintConstants = NULL;
	delete[] m_mdConstraintLowerBounds;
	m_mdConstraintLowerBounds = NULL;
	delete[] m_mdConstraintUpperBounds;
	m_mdConstraintUpperBounds = NULL;
	delete[] m_mdVariableLowerBounds;
	m_mdVariableLowerBounds = NULL;
	delete[] m_mdVariableUpperBounds;
	m_mdVariableUpperBounds = NULL;
	std::cout << "Do garbage collection for the nonlinear API" << std::endl;
	// garbage collection for the gradient
	if(m_bNonLinearStructuresInitialized == true ){
		delete[] m_mdObjectiveFunctionValues;
		m_mdObjectiveFunctionValues = NULL;	
		delete[] m_mdConstraintFunctionValues;
		m_mdConstraintFunctionValues = NULL;
		delete[] m_mdObjGradient;
		m_mdObjGradient = NULL;	
	}
	if(m_bSparseJacobianCalculated == true){
		delete[] m_miJacStart;
		m_miJacStart = NULL;
		delete[] m_miJacIndex;
		m_miJacIndex = NULL;
		delete[] m_mdJacValue;
		m_mdJacValue = NULL;
		delete[] m_miJacNumConTerms;
		m_miJacNumConTerms = NULL;
	}
	if( m_bLagrangianExpTreeCreated == true){
		delete m_LagrangianExpTree;
		m_LagrangianExpTree = NULL;
	}
	if( m_bLagrangianSparseHessianCreated == true){
		delete m_LagrangianSparseHessian;
		m_LagrangianSparseHessian = NULL;
	}
	if( m_bSparseJacobianCalculated == true){
		delete m_sparseJacMatrix;
		m_sparseJacMatrix = NULL;
	}
	//
	// delete the new expression trees that got created
	// however they already got deleted if we have a lagrangian Hessian
	if( m_bLagrangianExpTreeCreated == false){
		if( (m_bProcessExpressionTrees == true) && (m_bDuplicateExpressionTreesMap == false)  ) {
			for(posMapExpTree = m_mapExpressionTrees.begin(); posMapExpTree != m_mapExpressionTrees.end(); ++posMapExpTree){
				std::cout << "Deleting an expression tree from the map for row  " << posMapExpTree->first  << std::endl;
				delete m_mapExpressionTrees[ posMapExpTree->first ];
			}
		}
		if( m_bDuplicateExpressionTreesMap == true)   {
			for(posMapExpTree = m_mapExpressionTreesMod.begin(); posMapExpTree != m_mapExpressionTreesMod.end(); ++posMapExpTree){
				std::cout << "Deleting an expression tree from m_mapExpressionTreesMod" << std::endl;
				delete m_mapExpressionTreesMod[ posMapExpTree->first ];
			}
		}
	}
	//
	// delete the two children of OSInstance
	//delete instanceHeader object
	delete instanceHeader;
	instanceHeader = NULL;
	//delete instanceData object
	delete instanceData;
	instanceData = NULL;
}//OSInstance Destructor

InstanceHeader::InstanceHeader():
	description(""),
	name(""),
	source("")

{ 
	#ifdef DEBUG
	cout << "Inside the InstanceHeader Constructor" << endl;
	#endif
} 


InstanceHeader::~InstanceHeader(){
	#ifdef DEBUG  
	cout << "Inside the InstanceHeader Destructor" << endl;
	#endif
} 

Variable::Variable():
	name(""),
	init(OSNAN),
	lb(0.0),
	ub(OSINFINITY), 
	type('C'), 
	initString("")
{  
	#ifdef DEBUG
	cout << "Inside the Variable Constructor" << endl;
	#endif 
} 

Variable::~Variable(){  
	#ifdef DEBUG
	cout << "Inside the Variable Destructor" << endl; 
	#endif
} 

Variables::Variables(){  
	#ifdef DEBUG
	cout << "Inside the Variables Constructor" << endl; 
	#endif 
	numberOfVariables = 0;
	var = NULL; 
}

Variables::~Variables(){ 
	#ifdef DEBUG 
	cout << "Inside the Variables Destructor" << endl;
	#endif
	if(numberOfVariables > 0 && var != NULL){
		for(int i = 0; i < numberOfVariables; i++){
			delete var[i];
			var[i] = NULL;
		}
	}
	delete[] var;
	var = NULL; 
}  

ObjCoef::ObjCoef():
	idx(-1),
	value(0.0)  
{  
	#ifdef DEBUG
	cout << "Inside the Coef Constructor" << endl;
	#endif 
}

ObjCoef::~ObjCoef(){ 
	#ifdef DEBUG
	cout << "Inside the ObjCoef Desructor" << endl;  
	#endif
}

Objective::Objective():
	maxOrMin("min"),
	constant(0.0),
	weight(1.0),
	name("") , 
	numberOfObjCoef(0),
	coef(NULL)
{ 
 
	#ifdef DEBUG
	cout << "Inside the Objective Constructor" << endl;
	#endif
}

Objective::~Objective(){
	#ifdef DEBUG  
	cout << "Inside the Objective Destructor" << endl;
	#endif
	if(numberOfObjCoef > 0 && coef != NULL){
		for(int i = 0; i < numberOfObjCoef; i++){
			delete coef[i];
			coef[i] = NULL;
		}
	}
	delete[] coef;
	coef = NULL;
}  

Objectives::Objectives()
{  
	#ifdef DEBUG
	cout << "Inside the Objectives Constructor" << endl; 
	#endif
	numberOfObjectives = 0;
	obj = NULL;
} 

Objectives::~Objectives(){ 
	#ifdef DEBUG 
	cout << "Inside the Objectives Destructor" << endl;
	#endif
	if(numberOfObjectives > 0 && obj != NULL){
		for(int i = 0; i < numberOfObjectives; i++){
			delete obj[i];
			obj[i] = NULL;
		}
	}
	delete[] obj;
	obj = NULL;
}

Constraint::Constraint():
	name(""),
	constant(0.0),
	lb(-OSINFINITY),
	ub(OSINFINITY)

{
	#ifdef DEBUG  
	cout << "Inside the Constraint Constructor" << endl;
	#endif
} 

Constraint::~Constraint(){  
	#ifdef DEBUG
	cout << "Inside the Constraint Destructor" << endl;
	#endif
} 

Constraints::Constraints():
	numberOfConstraints(0),
	con(NULL)
{
	#ifdef DEBUG
	cout << "Inside the Constraints Constructor" << endl;
	#endif
} 

Constraints::~Constraints(){  
	#ifdef DEBUG
	cout << "Inside the Constraints Destructor" << endl;
	#endif
	if(numberOfConstraints > 0 && con != NULL){
		for(int i = 0; i < numberOfConstraints; i++){
			delete con[i];
			con[i] = NULL;
		}
	}
	delete[] con;
	con = NULL;
} 



LinearConstraintCoefficients::LinearConstraintCoefficients():
	numberOfValues(0) 
{ 
	#ifdef DEBUG 
	cout << "Inside the LinearConstraintCoefficients Constructor" << endl; 
	#endif
	start = new IntVector();
	rowIdx = new IntVector();
	colIdx = new IntVector();
	value = new DoubleVector();
} 


LinearConstraintCoefficients::~LinearConstraintCoefficients(){  
	#ifdef DEBUG
	cout << "Inside the LinearConstraintCoefficients Destructor" << endl; 
	#endif
	delete start;
	start = NULL;
	delete rowIdx;
	rowIdx = NULL;
	delete colIdx;
	colIdx = NULL;
	delete value;
	value = NULL;
}

QuadraticTerm::QuadraticTerm():

	idx(0),   
	idxOne(-1),
	idxTwo(-1),
	coef(0.0)

{
	#ifdef DEBUG  
	cout << "Inside the QuadraticTerm Constructor" << endl;
	#endif
} 


QuadraticTerm::~QuadraticTerm(){  
	#ifdef DEBUG
	cout << "Inside the QuadraticTerm Destructor" << endl;
	#endif
}



QuadraticCoefficients::QuadraticCoefficients():
	qTerm(NULL), 
	numberOfQuadraticTerms(0)  
{ 
	#ifdef DEBUG 
	cout << "Inside the QuadraticCoefficients Constructor" << endl;
	#endif
}//end QuadraticCoefficients() 


QuadraticCoefficients::~QuadraticCoefficients(){
	#ifdef DEBUG  
	cout << "Inside the QuadraticCoefficients Destructor" << endl;
	#endif
	if(numberOfQuadraticTerms > 0 && qTerm != NULL){
		for(int i = 0; i < numberOfQuadraticTerms; i++){
			delete qTerm[i];
			qTerm[i] = NULL;
		}
	}
	delete[] qTerm;
	qTerm = NULL;  
}//end ~QuadraticCoefficients()  


Nl::Nl(){
	idx = 0;
	osExpressionTree = NULL;
	m_bDeleteExpressionTree = true;
}//end Nl
 
 
Nl::~Nl(){
	#ifdef DEBUG  
	cout << "Inside the Nl Destructor" << endl;
	#endif
	// don't delete the expression tree if we created a map of the expression
	// trees, otherwise we would destroy twice
	if( m_bDeleteExpressionTree == true) delete osExpressionTree;
	osExpressionTree = NULL;
}//end ~Nl



NonlinearExpressions::NonlinearExpressions():
	nl(NULL), 
	numberOfNonlinearExpressions(0)  
{ 
	#ifdef DEBUG 
	cout << "Inside the NonlinearExpressions Constructor" << endl;
	#endif
}//end NonlinearExpressions() 

NonlinearExpressions::~NonlinearExpressions(){
	#ifdef DEBUG  
	cout << "Inside the NonlinearExpressions Destructor" << endl;
	cout << "NUMBER OF NONLINEAR EXPRESSIONS = " << numberOfNonlinearExpressions << endl;
	#endif
	if(numberOfNonlinearExpressions > 0 && nl != NULL){
		for(int i = 0; i < numberOfNonlinearExpressions; i++){
			cout << "DESTROYING EXPRESSION " << nl[ i]->idx << endl;
			delete nl[i];
			nl[i] = NULL;
		}
	}
	delete[] nl;
	nl = NULL;  
}//end ~NonlinearExpressions()  



InstanceData::InstanceData(){ 
	#ifdef DEBUG 
	cout << "Inside the InstanceData Constructor" << endl;
	#endif 
	variables = new Variables();
	objectives = new Objectives();
	constraints = new Constraints();
	linearConstraintCoefficients = new LinearConstraintCoefficients();
	quadraticCoefficients = new QuadraticCoefficients();
	nonlinearExpressions = new NonlinearExpressions();
	
} 

InstanceData::~InstanceData(){  
	#ifdef DEBUG
	cout << "Inside the InstanceData Destructor" << endl; 
	#endif
	delete variables;
	variables = NULL;
	delete objectives;
	objectives = NULL;
	delete constraints;
	constraints = NULL;
	delete linearConstraintCoefficients;
	linearConstraintCoefficients = NULL;
	delete quadraticCoefficients;
	quadraticCoefficients = NULL;
	delete nonlinearExpressions;
	nonlinearExpressions = NULL;
	
} 

string OSInstance::getInstanceName(){
	if(  m_sInstanceName.length() <= 0){
		m_sInstanceName = instanceHeader->name;
	}
	return m_sInstanceName;
}//getInstanceName


string OSInstance::getInstanceSource(){
	if( m_sInstanceSource.length() <= 0){
		m_sInstanceSource = instanceHeader->source;
	}
	return m_sInstanceSource;
}//getInstanceSource

string OSInstance::getInstanceDescription(){
	if(m_sInstanceDescription.length() <= 0){
		m_sInstanceDescription = instanceHeader->description;
	}
	return m_sInstanceDescription;
}//getInstanceDescription

int OSInstance::getVariableNumber(){
	if(m_iVariableNumber == -1){
		m_iVariableNumber = instanceData->variables->numberOfVariables;
	}
	return m_iVariableNumber;
}//getVariableNumber

int OSInstance::getNumberOfNonlinearExpressions(){
	if(m_iNonlinearExpressionNumber == -1){
		m_iNonlinearExpressionNumber = instanceData->nonlinearExpressions->numberOfNonlinearExpressions;
	}
	return m_iNonlinearExpressionNumber;
}//getNumberOfNonlinearExpressions



bool OSInstance::processVariables() {
	if(m_bProcessVariables) return true;
	m_bProcessVariables = true;
	string vartype ="CBIS";
	int i = 0;
	int n = instanceData->variables->numberOfVariables;
	try{
		if(instanceData->variables->var == NULL) throw ErrorClass("no variables defined");
		if(instanceData->variables->var[0]->name.length() > 0 || instanceData->variables->var[n-1]->name.length() > 0){
			m_msVariableNames = new string[n];
			for(i = 0; i < n; i++) m_msVariableNames[i] = instanceData->variables->var[i]->name;
		}

		if(CommonUtil::ISOSNAN(instanceData->variables->var[ 0]->init) == false ){ 
			m_mdVariableInitialValues = new double[n];
			for(i = 0; i < n; i++) m_mdVariableInitialValues[i] = instanceData->variables->var[i]->init;
		}
		if((instanceData->variables->var[0]->initString.length() > 0)){
			m_msVariableInitialStringValues = new string[n];
			for(i = 0; i < n; i++) m_msVariableInitialStringValues[i] = instanceData->variables->var[i]->initString;
		}
		m_mcVariableTypes = new char[n];
		m_mdVariableLowerBounds = new double[n];
		m_mdVariableUpperBounds = new double[n];
		for(i = 0; i < n; i++){
			if(vartype.find(instanceData->variables->var[i]->type) == string::npos) throw ErrorClass("wrong variable type");
			m_mcVariableTypes[i] = instanceData->variables->var[i]->type;
			if(m_mcVariableTypes[i] == 'B') m_iNumberOfBinaryVariables++;
			if(m_mcVariableTypes[i] == 'I') m_iNumberOfIntegerVariables++;
			m_mdVariableLowerBounds[i] = instanceData->variables->var[i]->lb;
			m_mdVariableUpperBounds[i] = instanceData->variables->var[i]->ub;
		}
		return true;
	} //end try
	catch(const ErrorClass& eclass){
		throw ErrorClass( eclass.errormsg);
	} 
}//processVariables
	
string* OSInstance::getVariableNames() {
	processVariables();
	return m_msVariableNames;
}//getVariableNames	

double* OSInstance::getVariableInitialValues() {
	processVariables();
	return m_mdVariableInitialValues;
}//getVariableInitialValues

string* OSInstance::getVariableInitialStringValues() {
	processVariables();
	return m_msVariableInitialStringValues;
}//getVariableInitialStringValues

char* OSInstance::getVariableTypes() {
	processVariables();
	return m_mcVariableTypes;
}//getVariableTypes

int OSInstance::getNumberOfIntegerVariables() {
	processVariables();
	return m_iNumberOfIntegerVariables;
}//getNumberOfIntegerVariables

int OSInstance::getNumberOfBinaryVariables() {
	processVariables();
	return m_iNumberOfBinaryVariables;
}//getNumberOfBinaryVariables

double* OSInstance::getVariableLowerBounds() {
	processVariables();
	return m_mdVariableLowerBounds;
}//getVariableLowerBounds

double* OSInstance::getVariableUpperBounds() {
	processVariables();
	return m_mdVariableUpperBounds;
}//getVariableUpperBounds

int OSInstance::getObjectiveNumber(){
	if(m_iObjectiveNumber == -1){
		m_iObjectiveNumber = instanceData->objectives->numberOfObjectives;
	}
	return m_iObjectiveNumber;
}//getObjectiveNumber


bool OSInstance::processObjectives() {
	if(m_bProcessObjectives) return true;
	m_bProcessObjectives = true;
	int i = 0;
	int j = 0;
	if(instanceData == NULL || instanceData->objectives == NULL || instanceData->objectives->obj == NULL || instanceData->objectives->numberOfObjectives == 0) return true;
	int n = instanceData->objectives->numberOfObjectives;
	try{
		if(instanceData->objectives->obj[0]->name.length() > 0 || instanceData->objectives->obj[n-1]->name.length() > 0){
			m_msObjectiveNames = new string[n];
			for(i = 0; i < n; i++) m_msObjectiveNames[i] = instanceData->objectives->obj[i]->name;
		}
		m_msMaxOrMins = new string[n];
		m_miNumberOfObjCoef = new int[n];
		m_mdObjectiveConstants = new double[n];
		m_mdObjectiveWeights = new double[n];
		m_mObjectiveCoefficients = new SparseVector*[n];
		for(i = 0; i < n; i++) m_mObjectiveCoefficients[i] = new SparseVector(instanceData->objectives->obj[ j]->numberOfObjCoef);
		//for(i = 0; i < n; i++){
		//	m_mObjectiveCoefficients[i] = new SparseVector();
		//	m_mObjectiveCoefficients[i]->number = instanceData->objectives->obj[ j]->numberOfObjCoef;
		//}
		for(i = 0; i < n; i++){
			if((instanceData->objectives->obj[i]->maxOrMin.compare("max") != 0) && (instanceData->objectives->obj[i]->maxOrMin.compare("min") != 0 )) throw ErrorClass("wrong objective maxOrMin");
			m_msMaxOrMins[i] = instanceData->objectives->obj[i]->maxOrMin;
			m_miNumberOfObjCoef[i] = instanceData->objectives->obj[i]->numberOfObjCoef;
			m_mdObjectiveConstants[i] = instanceData->objectives->obj[i]->constant;
			m_mdObjectiveWeights[i] = instanceData->objectives->obj[i]->weight;
			if(instanceData->objectives->obj[i]->coef == NULL && m_miNumberOfObjCoef[i] != 0){
				throw ErrorClass("objective coefficient number inconsistent with objective coefficient array");
			}
			if(instanceData->objectives->obj[i]->coef != NULL){
				for(j = 0; j < m_mObjectiveCoefficients[i]->number; j++){
					m_mObjectiveCoefficients[i]->indexes[j] = instanceData->objectives->obj[i]->coef[j]->idx;
					m_mObjectiveCoefficients[i]->values[j] = instanceData->objectives->obj[i]->coef[j]->value;			
				}
			}
		} 		
		return true;
	}
	catch(const ErrorClass& eclass){
		throw ErrorClass( eclass.errormsg);
	}
}//processObjectives

string* OSInstance::getObjectiveNames() {
	processObjectives();
	return m_msObjectiveNames;
}//getObjectiveNames

string* OSInstance::getObjectiveMaxOrMins() {
	processObjectives();
	return m_msMaxOrMins;
}//getObjectiveMaxOrMins

int* OSInstance::getObjectiveCoefficientNumbers(){
		processObjectives();
		return m_miNumberOfObjCoef;
	}//getObjectiveCoefficientNumbers

double* OSInstance::getObjectiveConstants() {
	processObjectives();
	return m_mdObjectiveConstants;
}//getObjectiveConstants

double* OSInstance::getObjectiveWeights() {
	processObjectives();
	return m_mdObjectiveWeights;
}//getObjectiveWeights

SparseVector** OSInstance::getObjectiveCoefficients() {
	processObjectives();
	return m_mObjectiveCoefficients;
}//getObjectiveCoefficients


double** OSInstance::getDenseObjectiveCoefficients() {
	if(m_bGetDenseObjectives) return m_mmdDenseObjectiveCoefficients;
	m_bGetDenseObjectives = true;
	if(instanceData->objectives->obj == NULL || instanceData->objectives->numberOfObjectives == 0) return m_mmdDenseObjectiveCoefficients;
	int m = instanceData->objectives->numberOfObjectives;
	int n = instanceData->variables->numberOfVariables;
	m_mmdDenseObjectiveCoefficients = new double*[m];
	int i, j, numobjcoef;
	SparseVector *sparsevec;
	for(i = 0; i < m; i++){
		sparsevec = this->getObjectiveCoefficients()[i];
		m_mmdDenseObjectiveCoefficients[ i] = new double[n];
		for(j = 0; j < n; j++){
			m_mmdDenseObjectiveCoefficients[ i][j] = 0.0;
		}
		sparsevec =  this->getObjectiveCoefficients()[i];
		numobjcoef = sparsevec->number;
		for(j = 0; j < numobjcoef; j++){
			m_mmdDenseObjectiveCoefficients[i][ sparsevec->indexes[ j]]
			= sparsevec->values[ j];
		}
	}
	return m_mmdDenseObjectiveCoefficients;
}//getDenseObjectiveCoefficients

int OSInstance::getConstraintNumber(){
	if(m_iConstraintNumber == -1){
		m_iConstraintNumber = instanceData->constraints->numberOfConstraints;
	}
	return m_iConstraintNumber;
}//getConstraintNumber

bool OSInstance::processConstraints() {
	if(m_bProcessConstraints) return true;
	m_bProcessConstraints = true;
	int i = 0;
	ostringstream outStr;
	if(instanceData == NULL || instanceData->constraints == NULL || instanceData->constraints->con == NULL || instanceData->constraints->numberOfConstraints == 0) return true;
	int n = instanceData->constraints->numberOfConstraints;
	try{
		if(instanceData->constraints->con[0]->name.length() > 0 || instanceData->constraints->con[n-1]->name.length() > 0){
			m_msConstraintNames = new string[n];
			for(i = 0; i < n; i++) m_msConstraintNames[i] = instanceData->constraints->con[i]->name;
		}
		m_mdConstraintLowerBounds = new double[n];
		m_mdConstraintUpperBounds = new double[n];
		m_mdConstraintConstants = new double[n];
		m_mcConstraintTypes = new char[n];
		for(i = 0; i < n; i++){
			m_mdConstraintLowerBounds[i] = instanceData->constraints->con[i]->lb;
			m_mdConstraintUpperBounds[i] = instanceData->constraints->con[i]->ub;
			m_mdConstraintConstants[i] = instanceData->constraints->con[i]->constant;
			if(m_mdConstraintLowerBounds[i] == OSINFINITY || m_mdConstraintUpperBounds[i] == -OSINFINITY) {
				throw ErrorClass( outStr.str() );
			}
			else if(m_mdConstraintLowerBounds[i] > m_mdConstraintUpperBounds[i]) {
				outStr << "Constraint  " ;
				outStr << i;
				outStr << " is infeasible";
				throw ErrorClass( outStr.str());
			}
			else if(m_mdConstraintLowerBounds[i] == -OSINFINITY && m_mdConstraintUpperBounds[i] == OSINFINITY)
				m_mcConstraintTypes[i] = 'U';
			else if(m_mdConstraintLowerBounds[i] == m_mdConstraintUpperBounds[i]) 
				m_mcConstraintTypes[i] = 'E';
			else if(m_mdConstraintLowerBounds[i] == -OSINFINITY)
				m_mcConstraintTypes[i] = 'L';
			else if(m_mdConstraintUpperBounds[i] == OSINFINITY)
				m_mcConstraintTypes[i] = 'G';
			else m_mcConstraintTypes[i] = 'R';
		}
		return true;
	}
	catch(const ErrorClass& eclass){
		throw ErrorClass( eclass.errormsg);
	}
}//processConstraints


string* OSInstance::getConstraintNames() {
	processConstraints();
	return m_msConstraintNames;
}//getConstraintNames


double* OSInstance::getConstraintLowerBounds() {
	processConstraints();
	return m_mdConstraintLowerBounds;
}//getConstraintLowerBounds

char* OSInstance::getConstraintTypes() {
	processConstraints();
	return m_mcConstraintTypes;
}//getConstraintTypes

double* OSInstance::getConstraintUpperBounds() {
	processConstraints();
	return m_mdConstraintUpperBounds;
}//getConstraintUpperBounds

int OSInstance::getLinearConstraintCoefficientNumber(){
	if(m_iLinearConstraintCoefficientNumber == -1){
		m_iLinearConstraintCoefficientNumber = instanceData->linearConstraintCoefficients->numberOfValues;
	}
	return m_iLinearConstraintCoefficientNumber; 
}//getLinearConstraintCoefficientNumber

bool OSInstance::processLinearConstraintCoefficients() {
	if(m_bProcessLinearConstraintCoefficients) return true;
	m_bProcessLinearConstraintCoefficients = true;
	try{
		int n = instanceData->linearConstraintCoefficients->numberOfValues;
		//value array
		if((instanceData->linearConstraintCoefficients->value == NULL ) || (n == 0) ) return true;
		//index array
		if((instanceData->linearConstraintCoefficients->colIdx != NULL && instanceData->linearConstraintCoefficients->colIdx->el != NULL) 
		&& (instanceData->linearConstraintCoefficients->rowIdx != NULL && instanceData->linearConstraintCoefficients->rowIdx->el != NULL))
			throw ErrorClass("ambiguous linear constraint coefficient major");
		else if(instanceData->linearConstraintCoefficients->value->el == NULL) return true;
		else{
			if(instanceData->linearConstraintCoefficients->rowIdx->el != NULL){
				m_bColumnMajor = true;
				m_linearConstraintCoefficientsInColumnMajor = new SparseMatrix();
				m_linearConstraintCoefficientsInColumnMajor->isColumnMajor = true;
				m_linearConstraintCoefficientsInColumnMajor->valueSize = n;
				m_linearConstraintCoefficientsInColumnMajor->startSize = instanceData->variables->numberOfVariables + 1;
			}
			else{ 
				m_bColumnMajor = false;	
				m_linearConstraintCoefficientsInRowMajor = new SparseMatrix();
				m_linearConstraintCoefficientsInRowMajor->isColumnMajor = false;
				m_linearConstraintCoefficientsInRowMajor->valueSize = n;
				m_linearConstraintCoefficientsInRowMajor->startSize = instanceData->constraints->numberOfConstraints + 1;
			}
		}			
		if(m_bColumnMajor == true){
			m_linearConstraintCoefficientsInColumnMajor->values = instanceData->linearConstraintCoefficients->value->el;
			m_linearConstraintCoefficientsInColumnMajor->indexes = instanceData->linearConstraintCoefficients->rowIdx->el;
			m_linearConstraintCoefficientsInColumnMajor->starts = instanceData->linearConstraintCoefficients->start->el;			
		}
		else{
			m_linearConstraintCoefficientsInRowMajor->values = instanceData->linearConstraintCoefficients->value->el;
			m_linearConstraintCoefficientsInRowMajor->indexes = instanceData->linearConstraintCoefficients->colIdx->el;
			m_linearConstraintCoefficientsInRowMajor->starts = instanceData->linearConstraintCoefficients->start->el;						
		}
		return true;
	}
	catch(const ErrorClass& eclass){
		throw ErrorClass( eclass.errormsg);
	}
}//processLinearConstraintCoefficients

bool OSInstance::getLinearConstraintCoefficientMajor() {
	processLinearConstraintCoefficients();	
	return m_bColumnMajor; 		
}//getLinearConstraintCoefficientMajor

SparseMatrix* OSInstance::getLinearConstraintCoefficientsInColumnMajor() {
	processLinearConstraintCoefficients();
	if(m_linearConstraintCoefficientsInColumnMajor != NULL) return m_linearConstraintCoefficientsInColumnMajor;
	if(!m_bColumnMajor){
		if(m_linearConstraintCoefficientsInRowMajor == NULL) return NULL;
		m_linearConstraintCoefficientsInColumnMajor = 
			MathUtil::convertLinearConstraintCoefficientMatrixToTheOtherMajor(false,
					  m_linearConstraintCoefficientsInRowMajor->startSize,
					  m_linearConstraintCoefficientsInRowMajor->valueSize,
					  m_linearConstraintCoefficientsInRowMajor->starts,
					  m_linearConstraintCoefficientsInRowMajor->indexes,
					  m_linearConstraintCoefficientsInRowMajor->values,
					  getVariableNumber());
	}
	return m_linearConstraintCoefficientsInColumnMajor; 		
}//getLinearConstraintCoefficientsInColumnMajor

SparseMatrix* OSInstance::getLinearConstraintCoefficientsInRowMajor() {
	processLinearConstraintCoefficients();
	if(m_linearConstraintCoefficientsInRowMajor != NULL) return m_linearConstraintCoefficientsInRowMajor;
	if(m_bColumnMajor){
		if(m_linearConstraintCoefficientsInColumnMajor == NULL) return NULL;
		m_linearConstraintCoefficientsInRowMajor = 
		MathUtil::convertLinearConstraintCoefficientMatrixToTheOtherMajor(true,
				  m_linearConstraintCoefficientsInColumnMajor->startSize,
				  m_linearConstraintCoefficientsInColumnMajor->valueSize,
				  m_linearConstraintCoefficientsInColumnMajor->starts,
				  m_linearConstraintCoefficientsInColumnMajor->indexes,
				  m_linearConstraintCoefficientsInColumnMajor->values,
				  getConstraintNumber());
	}
	return m_linearConstraintCoefficientsInRowMajor; 
}//getLinearConstraintCoefficientsInRowMajor


int OSInstance::getNumberOfQuadraticTerms(){
	if(m_iQuadraticTermNumber == -1){
	// if m_iQuadraticTermNumber == -1 then the parser did not find any q terms so 
	// must new the object
		if(instanceData->quadraticCoefficients == NULL)instanceData->quadraticCoefficients = new QuadraticCoefficients();
		m_iQuadraticTermNumber = instanceData->quadraticCoefficients->numberOfQuadraticTerms;
	}
	return m_iQuadraticTermNumber;
}//getNumberOfQuadraticTerms

QuadraticTerms* OSInstance::getQuadraticTerms() {
	if(m_bProcessQuadraticTerms) return m_quadraticTerms;
	m_bProcessQuadraticTerms = true;
	if(instanceData->quadraticCoefficients->qTerm == 0) return 0;
	try{
		int i = 0;
		QuadraticCoefficients* quadraticCoefs = instanceData->quadraticCoefficients;
		int n = quadraticCoefs->numberOfQuadraticTerms;
		if(!quadraticCoefs->qTerm  && n != 0) 
			throw ErrorClass("quadratic term number inconsistent with quadratic term array");		
		m_quadraticTerms = new QuadraticTerms();
		m_quadraticTerms->rowIndexes = new int[n];
		m_quadraticTerms->varOneIndexes = new int[n];
		m_quadraticTerms->varTwoIndexes = new int[n];
		m_quadraticTerms->coefficients = new double[n];
		for(i = 0; i < n; i++){
			m_quadraticTerms->rowIndexes[i] = quadraticCoefs->qTerm[i]->idx;
			m_quadraticTerms->varOneIndexes[i] = quadraticCoefs->qTerm[i]->idxOne;
			m_quadraticTerms->varTwoIndexes[i] = quadraticCoefs->qTerm[i]->idxTwo;
			m_quadraticTerms->coefficients[i] = quadraticCoefs->qTerm[i]->coef;
		} 
		return m_quadraticTerms;
	}
	catch(const ErrorClass& eclass){
		throw ErrorClass( eclass.errormsg);
	} 
}//getQuadraticTerms

int OSInstance::getNumberOfNonlinearConstraints(){
	if( m_bProcessExpressionTrees == false ){
		getAllNonlinearExpressionTrees();
		return m_iConstraintNumberNonlinear;
	}
	else return m_iConstraintNumberNonlinear;
}//getNumberOfNonlinearConstraints

int OSInstance::getNumberOfNonlinearObjectives(){
	if( m_bProcessExpressionTrees == false ){
		getAllNonlinearExpressionTrees();
		return m_iObjectiveNumberNonlinear;
	}
	else return m_iObjectiveNumberNonlinear;
}//getNumberOfNonlinearObjectivess


OSExpressionTree* OSInstance::getNonlinearExpressionTree(int rowIdx){
	if( m_bProcessExpressionTrees == false ){
		getAllNonlinearExpressionTrees();
		return m_mapExpressionTrees[ rowIdx];
	}
	else{
		//if( m_mapExpressionTrees.find( rowIdx) != m_mapExpressionTrees.end()) return NULL;
		//else return m_mapExpressionTrees[ rowIdx];
		if( m_mapExpressionTrees.find( rowIdx) != m_mapExpressionTrees.end()) return m_mapExpressionTrees[ rowIdx];
		else return NULL ;
		// check to make sure rowIdx has a nonlinear term and is in the map
		/** define an iterator for the expression trees map allExpTrees */
		//std::map<int, OSExpressionTree*>::iterator pos;
		///for(pos = m_mapExpressionTrees.begin(); pos != m_mapExpressionTrees.end(); ++pos){
		//	if(pos->first == rowIdx)return m_mapExpressionTrees[ rowIdx];
		//}
		// if we are rowIdx has no nonlinar terms so return a null
		//return NULL;
	}  
}// getNonlinearExpresssionTree for a specific index

std::map<int, OSExpressionTree*> OSInstance::getAllNonlinearExpressionTrees(){
	if(m_bProcessExpressionTrees == true) return m_mapExpressionTrees;
	std::map<int, int> foundIdx;
	std::map<int, int>::iterator pos;
	OSnLNodePlus *nlNodePlus;
	OSExpressionTree *expTree;
	m_iObjectiveNumberNonlinear = 0;
	m_iConstraintNumberNonlinear = 0;
	int i;
	int index;
	// kipp -- what should we return if instanceData->nonlinearExpressions->numberOfNonlinearExpressions is zero
	for(i = 0; i < instanceData->nonlinearExpressions->numberOfNonlinearExpressions; i++){
		index = instanceData->nonlinearExpressions->nl[ i]->idx;
		//if(foundIdx.find( index) != foundIdx.end() ){ 
		if(foundIdx[ index] > 0 ){ 
			nlNodePlus = new OSnLNodePlus();
			expTree = new OSExpressionTree();
			// set left child to old index and right child to new one
			nlNodePlus->m_mChildren[ 0] = m_mapExpressionTrees[ index]->m_treeRoot;
			nlNodePlus->m_mChildren[ 1] = instanceData->nonlinearExpressions->nl[ i]->osExpressionTree->m_treeRoot;
			m_mapExpressionTrees[ index] = expTree;
			m_mapExpressionTrees[ index]->m_treeRoot = nlNodePlus;
		}
		else{
			// we have a new index
			m_mapExpressionTrees[ index] = instanceData->nonlinearExpressions->nl[ i]->osExpressionTree;
			m_mapExpressionTrees[ index]->m_treeRoot = instanceData->nonlinearExpressions->nl[ i]->osExpressionTree->m_treeRoot;
		}
		foundIdx[ index]++;	
	}
	// count the number of constraints and objective functions with nonlinear terms.
	for(pos = foundIdx.begin(); pos != foundIdx.end(); ++pos){
		if(pos->first == -1) {
			m_iObjectiveNumberNonlinear++;
		}
		else m_iConstraintNumberNonlinear++;
	}
	foundIdx.clear();
	m_bProcessExpressionTrees = true;
	// important -- tell the nl nodes not to destroy the OSExpression Objects
	if( instanceData->nonlinearExpressions->numberOfNonlinearExpressions > 0 && instanceData->nonlinearExpressions->nl != NULL){
		for(int i = 0; i < instanceData->nonlinearExpressions->numberOfNonlinearExpressions; i++){
			instanceData->nonlinearExpressions->nl[i]->m_bDeleteExpressionTree = false;
		}
	}
	return m_mapExpressionTrees;
}// getAllNonlinearExpresssionTrees

std::map<int, OSExpressionTree*> OSInstance::getAllNonlinearExpressionTreesMod(){
	return m_mapExpressionTreesMod;
}// getAllNonlinearExpresssionTrees

/*
std::map<int, std::vector<OSnLNode*> > OSInstance::getAllNonlinearExpressionTreesInPostfix(){
	std::map<int, int> foundIdx;
	std::map<int, int>::iterator pos;
	OSnLNodePlus *nlNodePlus;
	std::vector<OSnLNode*> vPostFixTmp;
	m_iObjectiveNumberNonlinear = 0;
	m_iConstraintNumberNonlinear = 0;
	int i, j;
	int index;
	for(i = 0; i < instanceData->nonlinearExpressions->numberOfNonlinearExpressions; i++){
		index = instanceData->nonlinearExpressions->nl[ i]->idx;
		cout << "INDEX = " << index << endl;
		cout << "VALUE = " << foundIdx[ index] << endl;
		vPostFixTmp = instanceData->nonlinearExpressions->nl[ i]->osExpressionTree->getPostfix();
		for(j = 0; j < vPostFixTmp.size(); j++){
			m_mapExpressionTreesInPostfix[ index].push_back( vPostFixTmp[j] );
		}
		if(foundIdx[ index] > 0){ 
			nlNodePlus = new OSnLNodePlus();
			m_mapExpressionTreesInPostfix[ index].push_back( nlNodePlus );
		}
		foundIdx[ index]++;	
	}
	// count the number of constraints and objective functions with nonlinear terms.
	for(pos = foundIdx.begin(); pos != foundIdx.end(); ++pos){
		cout << "POSITION " << pos->first << endl;
		if(pos->first == -1) {
			m_iObjectiveNumberNonlinear++;
		}
		else m_iConstraintNumberNonlinear++;
	}
	m_bProcessExpressionTreesInPostfix = true;
	return m_mapExpressionTreesInPostfix;
}// getAllNonlinearExpresssionTreesInPostfix
*/


/*
std::vector<OSnLNode*> OSInstance::getNonlinearExpressionTreeInPostfix(int rowIdx){
	if( m_bProcessExpressionTreesInPostfix == false ){
		getAllNonlinearExpressionTreesInPostfix();
		return m_mapExpressionTreesInPostfix[ rowIdx];
	}
	else return m_mapExpressionTreesInPostfix[ rowIdx];
}// getNonlinearExpresssionTreeInPostfix
*/

// the set() methods

bool OSInstance::setInstanceSource(string source){
	instanceHeader->source = source;
	return true;
}//setInstanceSource

bool OSInstance::setInstanceDescription(string description){
	instanceHeader->description = description;
	return true;
}//setInstanceDescription


bool OSInstance::setInstanceName(string name){
	 instanceHeader->name = name;
	 return true;
}//setInstanceName


bool OSInstance::setVariableNumber(int number){
	// this method assume osinstance->instanceData->variables is not null
	if(number <= 0) return false;
	if(instanceData->variables->numberOfVariables != -1  && instanceData->variables->numberOfVariables != number){
		delete[] instanceData->variables->var;
		instanceData->variables->var = NULL;
	} 
	instanceData->variables->numberOfVariables = number;
	if(instanceData->variables->var == NULL){
		instanceData->variables->var = new Variable*[number];
	}
	return true;
}//setVariableNumber


bool OSInstance::addVariable(int index, string name, double lowerBound, double upperBound, char type, double init, string initString){
	instanceData->variables->var[index] = new Variable();
	if(index < 0 || instanceData->variables->numberOfVariables <= 0 || index >= instanceData->variables->numberOfVariables) return false;
	instanceData->variables->var[index]->name = name;
	//if(lowerBound != -OSINFINITY && lowerBound != -OSDBL_MAX)instanceData->variables->var[index]->lb = lowerBound;
	instanceData->variables->var[index]->lb = lowerBound;
	if(upperBound != OSINFINITY && upperBound != OSDBL_MAX)instanceData->variables->var[index]->ub = upperBound;
	instanceData->variables->var[index]->type = type;
	if(init != OSNAN) instanceData->variables->var[index]->init = init;
	instanceData->variables->var[index]->initString = initString;
	return true;
}//addVariable


bool OSInstance::setVariables(int number, string *names, double *lowerBounds, 
	double *upperBounds, char *types, double *inits, string *initsString){
	if(number <= 0) return false;
	if(instanceData->variables == NULL) instanceData->variables = new Variables();
	instanceData->variables->numberOfVariables = number;
	instanceData->variables->var = new Variable*[number];
	int i;
	for(i = 0; i < number; i++){
		instanceData->variables->var[ i] = new Variable();
	}
	if(names  != NULL){
		for(i = 0; i < number; i++) instanceData->variables->var[i]->name = names[i];   			
	}
	if(lowerBounds != NULL){
		for(i = 0; i < number; i++){
			if(lowerBounds[i] != -OSINFINITY && lowerBounds[i] != -OSDBL_MAX)instanceData->variables->var[i]->lb = lowerBounds[i];  
		}
	}
	if(upperBounds != NULL){
		for(i = 0; i < number; i++){
			if(upperBounds[i] != OSINFINITY && upperBounds[i] != OSDBL_MAX)instanceData->variables->var[i]->ub = upperBounds[i]; 
		}
	}
	if(types != NULL){
		for(i = 0; i < number; i++){
			instanceData->variables->var[i]->type = types[i];
			if(types[i] != 'C' && types[i] != 'B' && types[i] != 'I' && types[i] != 'S') types[i] = 'C';
		}
	}
	if(inits != NULL){
		for(i = 0; i < number; i++) instanceData->variables->var[i]->init = inits[i];   			
	}
	if(initsString != NULL){
		for(i = 0; i < number; i++) instanceData->variables->var[i]->initString = initsString[i];   			
	}
	return true;
}//setVariables

// begin checking again with Jun Ma

bool OSInstance::setObjectiveNumber(int number){
	if(number < 0) return false;
	if(instanceData->objectives == NULL) instanceData->objectives = new Objectives();
	if(number == 0){
		instanceData->objectives->numberOfObjectives = 0;
		instanceData->objectives->obj = 0;
		return true;
	}
	instanceData->objectives->numberOfObjectives = number;
	instanceData->objectives->obj = new Objective*[number];  			
	return true;
}//setObjectiveNumber

bool OSInstance::addObjective(int index, string name, string maxOrMin, double constant, double weight, SparseVector *objectiveCoefficients){
	if(index >= 0 || instanceData->objectives->numberOfObjectives <= 0 || abs(index) > instanceData->objectives->numberOfObjectives) return false;
	int arrayIndex = abs(index) -1;
	if(instanceData->objectives->obj == NULL) return false;
	instanceData->objectives->obj[arrayIndex] = new Objective();
	instanceData->objectives->obj[arrayIndex]->name = name;
	if( (maxOrMin != "max") && (maxOrMin != "min") ) return false;
	else instanceData->objectives->obj[arrayIndex]->maxOrMin = maxOrMin;
	instanceData->objectives->obj[arrayIndex]->constant = constant;
	instanceData->objectives->obj[arrayIndex]->weight = weight;
	int n = objectiveCoefficients->number;   		
	instanceData->objectives->obj[arrayIndex]->numberOfObjCoef = n;
	if(n == 0){
		instanceData->objectives->obj[arrayIndex]->coef = 0;
	}
	else{
		int i = 0;
		instanceData->objectives->obj[arrayIndex]->coef = new ObjCoef*[n];
		for(i = 0; i < n; i++) instanceData->objectives->obj[arrayIndex]->coef[i] = new ObjCoef();
		for(i = 0; i < n; i++){
			instanceData->objectives->obj[arrayIndex]->coef[i]->idx = objectiveCoefficients->indexes[i];
			instanceData->objectives->obj[arrayIndex]->coef[i]->value = objectiveCoefficients->values[i];   
		}   			
	}
	return true;
}//addObjective

bool OSInstance::setObjectives(int number, string *names, string *maxOrMins, double *constants, double *weights, SparseVector **objectiveCoefficients){
	if(number < 0) return false;
	if(number == 0){
		instanceData->objectives = new Objectives();
		instanceData->objectives->numberOfObjectives = 0;
		instanceData->objectives->obj = NULL;
		return true;
	}
	
	instanceData->objectives->numberOfObjectives = number;
	instanceData->objectives->obj = new Objective*[number];
	int i = 0;
	for(int i = 0; i < number; i++)instanceData->objectives->obj[i] = new Objective();
	int j = 0;
	if(names != NULL){
		for(i = 0; i < number; i++) instanceData->objectives->obj[i]->name = names[i];   			
	}	
	if(maxOrMins != NULL){
		for(i = 0; i < number; i++){
			if(maxOrMins[i] == "" || (maxOrMins[i].compare("max") != 0 && maxOrMins[i].compare("min") !=0)) return false;
			instanceData->objectives->obj[i]->maxOrMin = maxOrMins[i];   			
		}
	}
	if(constants != NULL){
		for(i = 0; i < number; i++) instanceData->objectives->obj[i]->constant = constants[i];   			
	}
	if(weights != NULL){
		for(i = 0; i < number; i++) instanceData->objectives->obj[i]->weight = weights[i];   			
	}
	if(objectiveCoefficients != NULL){
		for(i = 0; i < number; i++){
			int n = (&objectiveCoefficients[i] == NULL || objectiveCoefficients[i]->indexes == NULL)?0:objectiveCoefficients[i]->number;   		
			instanceData->objectives->obj[i]->numberOfObjCoef = n;
			if(n == 0){
				instanceData->objectives->obj[i]->coef = NULL;
			}
			else{
				instanceData->objectives->obj[i]->coef = new ObjCoef*[n];
				for(j = 0; j < n; j++){
					instanceData->objectives->obj[i]->coef[j] = new ObjCoef();
					instanceData->objectives->obj[i]->coef[j]->idx  = objectiveCoefficients[i]->indexes[j];
					instanceData->objectives->obj[i]->coef[j]->value = objectiveCoefficients[i]->values[j];   			
				}   			
			}   			   				
		}
	}
	return true;
}//setObjectives


bool OSInstance::setConstraintNumber(int number){
	if(number < 0) return false;
	if(instanceData->constraints == NULL) instanceData->constraints = new Constraints();
	if(number == 0){
		instanceData->constraints = new Constraints();
		instanceData->constraints->numberOfConstraints = 0;
		instanceData->constraints->con = 0;
		return true;
	}
	instanceData->constraints->numberOfConstraints = number;
	if(instanceData->constraints->con == 0 ){
		instanceData->constraints->con = new Constraint*[number];
	}
	return true;
}//setConstraintNumber

bool OSInstance::addConstraint(int index, string name, double lowerBound, double upperBound, double constant) {
	instanceData->constraints->con[ index] = new Constraint();
	if(index < 0 || instanceData->constraints->numberOfConstraints <= 0 || index >= instanceData->constraints->numberOfConstraints) return false;
	instanceData->constraints->con[ index]->name = name;
	if(lowerBound != -OSINFINITY && lowerBound != -OSDBL_MAX) instanceData->constraints->con[ index]->lb = lowerBound;
	if(upperBound != OSINFINITY && upperBound != OSDBL_MAX)instanceData->constraints->con[ index]->ub = upperBound;
	instanceData->constraints->con[ index]->constant = constant;
	return true;
}//addConstraint


bool OSInstance::setConstraints(int number, string* names, double* lowerBounds, double* upperBounds, double* constants){
	if(number < 0) return false;
	m_bProcessConstraints = false;
	m_bProcessConstraints = false;
	if(number == 0){
		instanceData->constraints = new Constraints();
		instanceData->constraints->numberOfConstraints = 0;
		instanceData->constraints->con = NULL;
		return true;
	}
	instanceData->constraints->numberOfConstraints = number;
	instanceData->constraints->con = new Constraint*[number];
	int i = 0;
	for(i = 0; i < number; i++){
		instanceData->constraints->con[i] = new Constraint();
	}
	if(names != NULL){
		for(i = 0; i < number; i++) instanceData->constraints->con[i]->name = names[i];   			
	}
	if(lowerBounds != NULL){
		for(i = 0; i < number; i++){
			if(lowerBounds[i] != -OSINFINITY && lowerBounds[i] != -OSDBL_MAX)instanceData->constraints->con[i]->lb = lowerBounds[i]; 
		}
	}
	if(upperBounds != NULL){
		for(i = 0; i < number; i++){
			if(upperBounds[i] != OSINFINITY && upperBounds[i] != OSDBL_MAX)instanceData->constraints->con[i]->ub = upperBounds[i]; 
		}
	}   
	if(constants != NULL){
		for(i = 0; i < number; i++) instanceData->constraints->con[i]->constant = constants[i];   			
	}
	return true;
}//setConstraints

bool OSInstance::setLinearConstraintCoefficients(int numberOfValues, bool isColumnMajor, 
		double* values, int valuesBegin, int valuesEnd, 
		int* indexes, int indexesBegin, int indexesEnd,   			
		int* starts, int startsBegin, int startsEnd){
		if(numberOfValues < 0) return false;
	if(instanceData->linearConstraintCoefficients == NULL) instanceData->linearConstraintCoefficients = new LinearConstraintCoefficients() ;
	if(numberOfValues == 0) return true;
	if((values == 0 ) ||
	   (valuesBegin < 0 || (valuesEnd - valuesBegin + 1) != numberOfValues) ||
	   (indexes == 0) ||
	   (indexesBegin < 0 || (indexesEnd - indexesBegin + 1) != numberOfValues) ||
	   (starts == 0 ) ||
	   (startsBegin < 0  || startsBegin >= startsEnd)) return false;
	instanceData->linearConstraintCoefficients->numberOfValues = numberOfValues;
	int i = 0;
	//starts
	if(instanceData->linearConstraintCoefficients->start == NULL) instanceData->linearConstraintCoefficients->start = new IntVector();
	if(startsBegin == 0 ){
		instanceData->linearConstraintCoefficients->start->el = starts;
	}
	else{
		instanceData->linearConstraintCoefficients->start->el = new int[startsEnd - startsBegin + 1];
		int k = 0;
		for(i = startsBegin; i <= startsEnd; i++){
			instanceData->linearConstraintCoefficients->start->el[k] = starts[i];
			k++;
		}
	}		 
	//values
	if(instanceData->linearConstraintCoefficients->value == NULL) instanceData->linearConstraintCoefficients->value = new DoubleVector();
	if(valuesBegin == 0 ){
		instanceData->linearConstraintCoefficients->value->el = values;
	}
	else{
		instanceData->linearConstraintCoefficients->value->el = new double[numberOfValues];
		int k = 0;
		for(i = valuesBegin; i <= valuesEnd; i++){
			instanceData->linearConstraintCoefficients->value->el[k] = values[i];
			k++;
		}
	}
	//indexes
	if(instanceData->linearConstraintCoefficients->rowIdx == NULL) instanceData->linearConstraintCoefficients->rowIdx = new IntVector();
	if(instanceData->linearConstraintCoefficients->colIdx == NULL) instanceData->linearConstraintCoefficients->colIdx = new IntVector();
	if(isColumnMajor){
		if(indexesBegin == 0 ){
			instanceData->linearConstraintCoefficients->rowIdx->el = indexes;
		}
		else{
			instanceData->linearConstraintCoefficients->rowIdx->el = new int[numberOfValues];
			int k = 0;
			for(i = indexesBegin; i <= indexesEnd; i++){
				instanceData->linearConstraintCoefficients->rowIdx->el[k] = indexes[i];
				k++;
			}
		}
	} 
	else{
		if(indexesBegin == 0 ){
			instanceData->linearConstraintCoefficients->colIdx->el = indexes;
		}
		else{
			instanceData->linearConstraintCoefficients->colIdx->el = new int[numberOfValues];
			int k = 0;
			for(i = indexesBegin; i <= indexesEnd; i++){
				instanceData->linearConstraintCoefficients->colIdx->el[k] = indexes[i];
				k++;
			}
		}
	}
	return true;
}//setLinearConstraintCoefficients

bool OSInstance::setQuadraticTerms(int number, 
		int* rowIndexes, int* varOneIndexes, int* varTwoIndexes, double* coefficients,
		int begin, int end){
	if(number < 0) return false;
	if(number == 0){
		instanceData->quadraticCoefficients = 0;
		return true;
	}
	if( ((end - begin + 1) != number) ||
	   (rowIndexes == 0) ||   		   
	   (varOneIndexes == 0) ||
	   (varTwoIndexes == 0) ||
	   (coefficients == 0) ) return false;
	instanceData->quadraticCoefficients = new QuadraticCoefficients();
	instanceData->quadraticCoefficients->numberOfQuadraticTerms = number;
	int i = 0;
	instanceData->quadraticCoefficients->qTerm = new QuadraticTerm*[number];
	for(i = 0; i < number; i++) instanceData->quadraticCoefficients->qTerm[i] = new QuadraticTerm();
	// Kipp: check logic below -- looks weird what is the k for???
	int k = 0;
	for(i = begin; i <= end; i++){
			instanceData->quadraticCoefficients->qTerm[k]->idx = rowIndexes[i];
			instanceData->quadraticCoefficients->qTerm[k]->idxOne = varOneIndexes[i];
			instanceData->quadraticCoefficients->qTerm[k]->idxTwo = varTwoIndexes[i];
			instanceData->quadraticCoefficients->qTerm[k]->coef = coefficients[i];
			k++;
	}
	return true;
}//setQuadraticTerms

bool OSInstance::setQuadraticTermsInNonlinearExpressions(int numQPTerms, int* rowIndexes, int* varOneIndexes, int* varTwoIndexes, double* coefficients){
		instanceData->nonlinearExpressions->numberOfNonlinearExpressions = numQPTerms;
		instanceData->nonlinearExpressions->nl = new Nl*[ numQPTerms ];
		// define the vectors
		OSnLNode *nlNodePoint;
		OSnLNodeVariable *nlNodeVariablePoint;
		OSnLNodeNumber *nlNodeNumberPoint;
		OSnLNodeMax *nlNodeMaxPoint;
		std::vector<OSnLNode*> nlNodeVec;
		//
		//
		int i;
		for(i = 0; i < numQPTerms; i++){
			instanceData->nonlinearExpressions->nl[ i] = new Nl();
			instanceData->nonlinearExpressions->nl[ i]->idx = rowIndexes[ i];
			instanceData->nonlinearExpressions->nl[ i]->osExpressionTree = new OSExpressionTree();
		// create a variable nl node for x0
		nlNodeVariablePoint = new OSnLNodeVariable();
		nlNodeVariablePoint->idx = varOneIndexes[ i];
		// give this variable the coefficient
		nlNodeVariablePoint->coef = coefficients[ i];
		nlNodeVec.push_back( nlNodeVariablePoint);
		// create the nl node for x1
		nlNodeVariablePoint = new OSnLNodeVariable();
		nlNodeVariablePoint->idx = varTwoIndexes[ i];
		nlNodeVec.push_back( nlNodeVariablePoint);
		// create the nl node for *
		nlNodePoint = new OSnLNodeTimes();
		nlNodeVec.push_back( nlNodePoint);
		// the vectors are in postfix format
		// now the expression tree
		instanceData->nonlinearExpressions->nl[ i]->osExpressionTree->m_treeRoot =
			nlNodeVec[ 0]->createExpressionTreeFromPostfix( nlNodeVec);
		nlNodeVec.clear();
		}
	return true;
}//setQuadraticTermsInNonlinearExpressions

bool OSInstance::initializeNonLinearStructures( ){
	std::map<int, OSExpressionTree*>::iterator posMapExpTree;
	if( m_bNonLinearStructuresInitialized == true) return true;
	if( m_bProcessVariables == false) processVariables();
	if( m_bProcessObjectives == false) processObjectives();
	if( m_bProcessConstraints == false) processConstraints();
	m_iVariableNumber = instanceData->variables->numberOfVariables;
	m_iConstraintNumber = instanceData->constraints->numberOfConstraints;
	m_iObjectiveNumber = instanceData->objectives->numberOfObjectives;
	// get all of the expression trees
	if( m_bProcessExpressionTrees == false) getAllNonlinearExpressionTrees();
	// before proceeding get a copy of the map of the Expression Trees
	if( m_bDuplicateExpressionTreesMap == false) duplicateExpressionTreesMap();
	// now create all of the variable maps for each expression tree
	for(posMapExpTree = m_mapExpressionTreesMod.begin(); posMapExpTree != m_mapExpressionTreesMod.end(); ++posMapExpTree){	
		(posMapExpTree->second)->getVariableIndiciesMap() ;
	}
	// add the quadratic terms if necessary
	if(getNumberOfQuadraticTerms() > 0) addQTermsToExressionTree();
	// now get the map of all nonlinear variables
	getAllNonlinearVariablesIndexMap( );
	getDenseObjectiveCoefficients();
	m_mdConstraintFunctionValues = new double[ this->instanceData->constraints->numberOfConstraints];
	m_mdObjectiveFunctionValues = new double[ this->instanceData->objectives->numberOfObjectives];
	m_mdObjGradient = new double[ this->instanceData->variables->numberOfVariables];
	m_bNonLinearStructuresInitialized = true;
	return true;
}

SparseJacobianMatrix *OSInstance::getJacobianSparsityPattern( ){
	// if already called return the sparse Jacobian
	if( m_bSparseJacobianCalculated == true) return m_sparseJacMatrix;
	// make sure the data structures have been inialized
	getLinearConstraintCoefficientMajor();
	if( m_bNonLinearStructuresInitialized == false) initializeNonLinearStructures( );
	try{
		if( m_bColumnMajor == true){
			 getSparseJacobianFromColumnMajor( );
		}
		else {
			throw ErrorClass("cannot handle row major linear + nonlinear");
			//getSparseJacobianFromRowMajor( );
			//kipp -- implement getSparseJacobianFromRowMajor
		}
	}
	catch(const ErrorClass& eclass){
		throw ErrorClass(  eclass.errormsg); 
	}
	// now fill in the arrays of the sparseJacMatrix
	m_sparseJacMatrix = new SparseJacobianMatrix();
	// we point to memory already created so don't 
	// destroy during garbage collection
	m_sparseJacMatrix->bDeleteArrays = false;
	m_sparseJacMatrix->valueSize = 	m_iJacValueSize;
	m_sparseJacMatrix->starts = m_miJacStart;
	m_sparseJacMatrix->conVals = m_miJacNumConTerms;
	m_sparseJacMatrix->indexes = m_miJacIndex;
	m_sparseJacMatrix->values = m_mdJacValue;
	m_bSparseJacobianCalculated = true;
	return m_sparseJacMatrix;
}//getJacobianSparsityPatter

bool OSInstance::addQTermsToExressionTree(){
	int i, k, idx;
	// get the number of qTerms
	int numQTerms = instanceData->quadraticCoefficients->numberOfQuadraticTerms;	
	if(numQTerms <= 0 || m_bQTermsAdded == true) return true;
	OSnLNodeVariable* nlNodeVariableOne;
	OSnLNodeVariable* nlNodeVariableTwo;
	OSnLNodeTimes* nlNodeTimes;
	OSnLNodePlus* nlNodePlus;
	OSExpressionTree* expTree;
	getQuadraticTerms();	
	std::cout << "PROCESSING QUADRATIC TERMS" << std::endl;
	for(i = 0; i < numQTerms; i++){
		idx = m_quadraticTerms->rowIndexes[ i];
		std::cout << "PROCESSING QTERM  = "  << i <<std::endl;
		// see if row idx is in the expression tree
		if( m_mapExpressionTreesMod.find( idx) != m_mapExpressionTreesMod.end() ) {
			// row idx is in the expression tree
			// add the qTerm in row idx  to the expression tree	
			// define two new OSnLVariable nodes, an OSnLnodeTimes, and OSnLnodePlus 
			nlNodeVariableOne = new OSnLNodeVariable();
			nlNodeVariableOne->idx = m_quadraticTerms->varOneIndexes[ i];
			// see if the variable indexed by nlNodeVariableOne->idx is in the expression tree for row idx
			// if not, add to mapVarIdx
			expTree = m_mapExpressionTreesMod[ idx];
			if(  expTree->m_bIndexMapGenerated == false) expTree->getVariableIndiciesMap();
			if( (*expTree->mapVarIdx).find( nlNodeVariableOne->idx) == (*expTree->mapVarIdx).end()  ){
				// add to map
				k = (*expTree->mapVarIdx).size();
				(*expTree->mapVarIdx)[ nlNodeVariableOne->idx] =  k + 1;
				std::cout << "ADDED THE FOLLOWING VAIRABLE TO THE MAP" <<  nlNodeVariableOne->idx << std::endl;
			}
			nlNodeVariableOne->coef = m_quadraticTerms->coefficients[ i];
			nlNodeVariableTwo = new OSnLNodeVariable();
			nlNodeVariableTwo->idx = m_quadraticTerms->varTwoIndexes[ i];
			// see if the variable indexed by nlNodeVariableTwo->idx is in the expression tree for row idx
			// if not, add to mapVarIdx
			if( (*expTree->mapVarIdx).find( nlNodeVariableTwo->idx) == (*expTree->mapVarIdx).end()  ){
				// add to map
				k = (*expTree->mapVarIdx).size();
				(*expTree->mapVarIdx)[ nlNodeVariableTwo->idx] =  k + 1;
				std::cout << "ADDED THE FOLLOWING VAIRABLE TO THE MAP" <<  nlNodeVariableTwo->idx << std::endl;
			}
			nlNodeVariableTwo->coef = 1.;
			// now multiply the two new variable nodes together
			nlNodeTimes = new OSnLNodeTimes();
			nlNodeTimes->m_mChildren[ 0] = nlNodeVariableOne;
			nlNodeTimes->m_mChildren[ 1] = nlNodeVariableTwo;		
			// now add the result to the expression tree
			nlNodePlus = new OSnLNodePlus();
			nlNodePlus->m_mChildren[ 0] = m_mapExpressionTreesMod[ idx ]->m_treeRoot;
			nlNodePlus->m_mChildren[ 1] = nlNodeTimes;
			expTree = new OSExpressionTree();
			expTree->m_treeRoot = nlNodePlus ;
			expTree->mapVarIdx = m_mapExpressionTreesMod[ idx]->mapVarIdx;
			m_mapExpressionTreesMod[ idx ]  = expTree;	
		}
		else{
			// create the quadratic expression to add to the expression tree
			nlNodeVariableOne = new OSnLNodeVariable();
			nlNodeVariableOne->idx = m_quadraticTerms->varOneIndexes[ i];
			nlNodeVariableOne->coef = m_quadraticTerms->coefficients[ i];
			nlNodeVariableTwo = new OSnLNodeVariable();
			nlNodeVariableTwo->idx = m_quadraticTerms->varTwoIndexes[ i];
			nlNodeVariableTwo->coef = 1.;
			// now multiply the two new variable nodes together
			nlNodeTimes = new OSnLNodeTimes();
			nlNodeTimes->m_mChildren[ 0] = nlNodeVariableOne;
			nlNodeTimes->m_mChildren[ 1] = nlNodeVariableTwo;
			// create a new expression tree corresponding to row idx.
			expTree = new OSExpressionTree();						
			expTree->m_treeRoot = nlNodeTimes ;
			expTree->mapVarIdx = expTree->getVariableIndiciesMap();		
			m_mapExpressionTreesMod[ idx ]  = expTree;
			if(idx < 0){
				m_iObjectiveNumberNonlinear++;
				m_bProcessExpressionTrees = true;
			}
			else{
				m_iConstraintNumberNonlinear++;
				m_bProcessExpressionTrees = true;
			}
			std::cout << "NUMBER OF EXPRESSION TREES = "  << m_mapExpressionTreesMod.size() <<std::endl;
			std::cout << "NUMBER OF NONLINEAR OBJECTIVES = "  << getNumberOfNonlinearObjectives() <<std::endl;
		} 
		// if there were no nonlinear terms make this the expression tree
		if(m_iNonlinearExpressionNumber <= 0) m_mapExpressionTrees = m_mapExpressionTreesMod;
		m_bQTermsAdded =true;
	}
	return true;
}

double OSInstance::calculateFunctionValue(int idx, double *x, bool functionEvaluated){
	try{

		int i, j;
		double dvalue = 0;
		if( m_bNonLinearStructuresInitialized == false) initializeNonLinearStructures( );
		// if we have not filled in the Sparse Jacobian matrix do so now
		if( m_bSparseJacobianCalculated == false) getJacobianSparsityPattern();
		
		//
		//
//		// test code	
//		getLagrangianHessianSparsityPattern();
//		std::vector<double> vdFunVals( m_mapExpressionTreesMod.size());
//		std::vector<double> vdX( m_iNumberOfNonlinearVariables);
//		if( m_iNumberOfNonlinearVariables > 0){
//	        if( m_bCppADFunIsCreated == false)  createCppADFun( x);
//			std::map<int, int>::iterator posVarIndexMap;
//			std::map<int, OSExpressionTree*>::iterator posMapExpTree;
//			// get the current iterate data
//			i = 0;
//			for(posVarIndexMap = m_mapAllNonlinearVariablesIndex.begin(); posVarIndexMap != m_mapAllNonlinearVariablesIndex.end(); ++posVarIndexMap){
//				vdX[ i++] = x[ posVarIndexMap->first] ;
//			}		
//			vdFunVals = forwardAD(0, vdX);
//		}
//		//
//		// end test code
		//
		if(idx >= 0){ // we have a constraint
			// make sure the index idx is valid
			if( getConstraintNumber() <= idx  ) throw 
			ErrorClass("constraint index not valid in OSInstance::calculateFunctionValue");
			if( functionEvaluated == true) return *(m_mdConstraintFunctionValues + idx);
			// get the nonlinear part
			if( m_mapExpressionTreesMod.find( idx) != m_mapExpressionTreesMod.end() ){
				dvalue = m_mapExpressionTreesMod[ idx]->calculateFunction( x,  functionEvaluated);
				//dvalue = vdFunVals[ idx + 1];
			}
			// now the linear part
			// be careful, loop over only the constant terms in sparseJacMatrix
			i = m_sparseJacMatrix->starts[ idx];
			j = m_sparseJacMatrix->starts[ idx + 1 ];
			//while ( i <  j &&  (i - m_sparseJacMatrix->starts[ idx])  < m_sparseJacMatrix->conVals[ idx] ){
			while ( (i - m_sparseJacMatrix->starts[ idx])  < m_sparseJacMatrix->conVals[ idx] ){
				//std::cout << "m_sparseJacMatrix->values[ i] " << m_sparseJacMatrix->values[ i] << std::endl;
				//std::cout << "m_sparseJacMatrix->indexes[ i] " << m_sparseJacMatrix->indexes[ i] << std::endl;
				dvalue += m_sparseJacMatrix->values[ i]*x[ m_sparseJacMatrix->indexes[ i] ];
				i++;
			}	
			// add in the constraint function constant
			dvalue += m_mdConstraintConstants[ idx ];
			return dvalue;
		}
		else{ // we have an objective function
			// make sure the index idx is valid
			if( getObjectiveNumber() <= ( abs( idx) - 1) ) throw 
			ErrorClass("objective function index not valid in OSInstance::calculateFunctionValue");
			if( functionEvaluated == true) return *(m_mdObjectiveFunctionValues + ( abs( idx) - 1));
			// get the nonlinear part
			if( m_mapExpressionTreesMod.find( idx) != m_mapExpressionTreesMod.end() ){
				dvalue = m_mapExpressionTreesMod[ idx]->calculateFunction( x,  functionEvaluated);
			}
			// get linear part
			SparseVector **objCoef = getObjectiveCoefficients();
			SparseVector *obj = objCoef[ abs( idx) - 1];
			for(i = 0; i < obj->number; i++){
				dvalue += x[ obj->indexes[i]]*(obj->values[ i]);
			}
			// add in the objective function constant
			dvalue += m_mdObjectiveConstants[ abs( idx) - 1 ];
			// get the coefficients for objective function idx
			*(m_mdObjectiveFunctionValues + ( abs( idx) - 1)) = dvalue;
			return *(m_mdObjectiveFunctionValues + ( abs( idx) - 1));
		}
	}
	catch(const ErrorClass& eclass){
		throw ErrorClass( eclass.errormsg);
	} 
}//calculateFunctionValue


double *OSInstance::calculateAllConstraintFunctionValues( double* x, double objLambda, double *conLambda,
	int objIdx, bool new_x, int highestOrder){
			
	// kipp -- put in check to make sure objIdx is valid
	if( new_x == false && (highestOrder <= m_iHighestOrderEvaluated)  ) {
		return  m_mdConstraintFunctionValues;
	}
	std::cout << "HIGHEST ORDER EVALUATED =  " <<  m_iHighestOrderEvaluated <<  std::endl;
	std::cout << "new_x =  " <<  new_x <<  std::endl;
	// if here, we need to do an evaluation
	getIterateResults(x, objLambda, conLambda, objIdx,  highestOrder);
 	return m_mdConstraintFunctionValues;
	// kipp put some code in to execute the code below if we don't want AD to do the
	// function evaluations	
	m_iHighestOrderEvaluated = -1;
	if( m_bNonLinearStructuresInitialized == false) initializeNonLinearStructures( );
	int idx, numConstraints;
	numConstraints = getConstraintNumber();
	// loop over all constraints
	for(idx = 0; idx < numConstraints; idx++){
		// calculateFunctionValue will define *(m_mdConstraintFunctionValues + idx)
		//std::cout << "Index =  "  << idx  << std::endl;
		m_mdConstraintFunctionValues[ idx]  = calculateFunctionValue(idx, x, false);	
		//std::cout << "m_mdConstraintFunctionValues[ idx]  !!!!!!!"  << m_mdConstraintFunctionValues[ idx] << std::endl;
	}
	return m_mdConstraintFunctionValues;
}//calculateAllConstraintFunctionValues

double OSInstance::calculateObjectiveFunctionValue(double* x, double objLambda, double *conLambda,
		int objIdx, bool new_x, int highestOrder){
	try{
		if( new_x == false && (highestOrder <= m_iHighestOrderEvaluated)  ) {
			return m_mdObjectiveFunctionValues[ abs( objIdx) - 1];
		}
		std::cout << "HIGHEST ORDER EVALUATED =  " <<  m_iHighestOrderEvaluated <<  std::endl;
		std::cout << "new_x =  " <<  new_x <<  std::endl;
		// if here, we need to do an evaluation
		getIterateResults(x, objLambda, conLambda, objIdx,  highestOrder);
		return m_mdObjectiveFunctionValues[ abs( objIdx) - 1];
	}
	catch(const ErrorClass& eclass){
		throw ErrorClass( eclass.errormsg);
	} 
}//calculateObjectiveFunctionValue

double *OSInstance::calculateAllObjectiveFunctionValues( double* x, bool allFunctionsEvaluated){
	m_iHighestOrderEvaluated = -1;
	if(allFunctionsEvaluated == true) return m_mdObjectiveFunctionValues;
	if( m_bNonLinearStructuresInitialized == false) initializeNonLinearStructures( );
	int idx, numObjectives;
	numObjectives = getObjectiveNumber();
	// loop over all objectives
	for(idx = 0; idx < numObjectives; idx++){
		// calculateFunctionValue will define *(m_mdObjectiveFunctionValues + ( abs( idx) - 1))
		calculateFunctionValue(-idx - 1, x, false);	
	}
	return m_mdObjectiveFunctionValues;
}//calculateAllObjectiveFunctionValues

SparseJacobianMatrix *OSInstance::calculateAllConstraintFunctionGradients(double* x, double objLambda, double *conLambda,
		int objIdx, bool new_x, int highestOrder){
	try{
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "INSIDE CALCULATEALLCONSTRAINTFUNCTIONGRADIENT" << std::endl;
		for(int i = 0; i < m_sparseJacMatrix->valueSize; i++){
			std::cout << "x[ i] =  " << x[i] << std::endl;
		}
		std::cout << "new_x =  " <<  new_x  << std::endl;
		std::cout << "highestOrder =  " <<  highestOrder  << std::endl;
		std::cout << "highestOrderEvaluated =  " <<  m_iHighestOrderEvaluated << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		// kipp -- put in check to make sure objIdx is valid
		if( new_x == false && (highestOrder <= m_iHighestOrderEvaluated)  ) {
			return m_sparseJacMatrix;
		}
		// if here, we need to do an evaluation
		getIterateResults(x, objLambda, conLambda, objIdx,  highestOrder);
//		int idx, j;
//		int jstart, jend;
//		std::map<int, int>::iterator posVarIdx;
//		std::map<int, OSExpressionTree*>::iterator posMapExpTree;
//		std::vector<double> jac;
//		// loop over the constraints that have a nonlinear term and get their gradients
//		for(posMapExpTree = m_mapExpressionTreesMod.begin(); posMapExpTree != m_mapExpressionTreesMod.end(); ++posMapExpTree){
//			idx = posMapExpTree->first;
//			// we are considering only constraints, not objective function
//			if(idx >= 0){
//				m_mapExpressionTreesMod[ idx]->getVariableIndiciesMap(); 
//				//jac = m_mapExpressionTreesMod[ idx]->calculateGradientReTape(x, allFunctionsEvaluated);
//				jac = m_mapExpressionTreesMod[ idx]->calculateGradient(x, new_x);
//				// check size
//				jstart = m_miJacStart[ idx] + m_miJacNumConTerms[ idx];
//				jend = m_miJacStart[ idx + 1 ];
//				if( jac.size() != (jend - jstart)) throw 
//				ErrorClass("number of partials not consistent");
//				j = 0;
//				for(posVarIdx = (*m_mapExpressionTreesMod[ idx]->mapVarIdx).begin(); posVarIdx 
//					!= (*m_mapExpressionTreesMod[ idx]->mapVarIdx).end(); ++posVarIdx){
//					//if(m_miJacIndex[ jstart] != posVarIdx->first) throw ErrorClass("error calculating Jacobian matrix");
//					m_mdJacValue[ jstart] = jac[ j];
//					//std::cout << "Constraint  Partial = " <<  jac[ j] << std::endl;
//					jstart++;
//					j++;
//				}
//			}
//		}
	}
	catch(const ErrorClass& eclass){
		throw ErrorClass( eclass.errormsg);
	} 
	return m_sparseJacMatrix;
}//calculateAllConstraintFunctionGradients	

double *OSInstance::calculateObjectiveFunctionGradient(double* x, double objLambda, double *conLambda,
		int objIdx, bool new_x, int highestOrder){
	try{
		int i;
		// kipp -- put in check to make sure objIdx is valid
		
		// kipp don't don't do this at every iteration --  make more efficient
		
		for(i = 0; i < m_iVariableNumber; i++){
			*(m_mdObjGradient + i) = m_mmdDenseObjectiveCoefficients[ abs( objIdx) - 1][i]; 
		}
		// fix above
		if( new_x == false && (highestOrder <= m_iHighestOrderEvaluated)  ) {
			return m_mdObjGradient;
		}
		// if here, we need to do an evaluation
		getIterateResults(x, objLambda, conLambda, objIdx,  highestOrder);
		
//		int idx = objIdx;
//		m_iHighestOrderEvaluated = -1;
//		// make sure the index idx is valid
//		if(idx >= 0 || getObjectiveNumber() <= ( abs( idx) - 1)  ) throw 
//			ErrorClass("obj index not valid in OSInstance::calculateObjectiveFunctionGradient");
//		//if( gradientEvaluated == true) return m_mdObjGradient;
//		int i;
//		int numVar = getVariableNumber();
//		std::map<int, int>::iterator posVarIdx;
//		std::vector<double> jac;
//		// get the values from the ObjCoef object
//		int objIdx = (abs( idx) - 1);
//		for(i = 0; i < numVar; i++){
//			*(m_mdObjGradient + i) = m_mmdDenseObjectiveCoefficients[ objIdx][i];
//		}
//		// get the gradient
//		if( m_mapExpressionTreesMod.find( idx) != m_mapExpressionTreesMod.end() ){
//			//jac = m_mapExpressionTreesMod[ idx]->calculateGradientReTape(x, functionEvaluated);
//			jac = m_mapExpressionTreesMod[ idx]->calculateGradientReTape(x, false);
//			i = 0;
//			for(posVarIdx = (*m_mapExpressionTreesMod[ idx]->mapVarIdx).begin(); posVarIdx 
//			!= (*m_mapExpressionTreesMod[ idx]->mapVarIdx).end(); ++posVarIdx){
//				*(m_mdObjGradient + posVarIdx->first) += jac[ i];	
//				//std::cout << "Objective  Partial = " <<  jac[ i] << std::endl;
//				i++;
//			}
//		}
	}
	catch(const ErrorClass& eclass){
		throw ErrorClass( eclass.errormsg);
	} 
	return m_mdObjGradient;
}				

bool OSInstance::getSparseJacobianFromRowMajor( ){
	// Kipp -- todo
	return true;
}//getSparseJacobianFromRowMajor

bool OSInstance::getSparseJacobianFromColumnMajor( ){
	// we assume column major matrix
	if( m_bColumnMajor == false) return false;
	int iNumRowStarts = getConstraintNumber() + 1;	
	int i,j, iTemp;
	int iNumVariableStarts = getVariableNumber() ;
	int *start;
	int *index;
	double *value;
	if(this->instanceData->linearConstraintCoefficients->numberOfValues > 0){
		start = this->instanceData->linearConstraintCoefficients->start->el;
		index = this->instanceData->linearConstraintCoefficients->rowIdx->el;
		value = this->instanceData->linearConstraintCoefficients->value->el;
	}
	m_miJacStart = new int[ iNumRowStarts];
	m_miJacNumConTerms = new int[ getConstraintNumber()];
	OSnLNodePlus *nlNodePlus;
	OSnLNodeVariable *nlNodeVariable;
	OSExpressionTree *expTree = NULL;
	// now initialize starts and variable index maps 
	for ( i = 0; i < iNumRowStarts; i++){			
		m_miJacStart [ i ] = 0;
		// map the variables  in the nonlinear rows
		if( m_mapExpressionTreesMod.find( i) != m_mapExpressionTreesMod.end() ){
			// the following is equivalent to  m_treeRoot->getVariableIndexMap( i);
			m_mapExpressionTreesMod[ i]->getVariableIndiciesMap();
			
		}
	}
	// only execute the following code if there are linear constraint coefficients
	if(this->instanceData->linearConstraintCoefficients->numberOfValues > 0){
		// i is indexing columns (variables) and j is indexing row numbers 
		for (i = 0; i < iNumVariableStarts; i++){	
			for (j = start[i]; j < start[ i + 1 ]; j++){
				// index[ j] is a row index, we have just found an occurance of row index[j]
				// therefore we increase by 1 (or push back) the start of the row indexed by index[j] + 1, 
				// i.e. the start of the next row
				// check to see if variable i is linear/constant in the row index[ j] 
				// if so, increment m_miJacStart[ index[j] + 1]
				//
				if( (m_mapExpressionTreesMod.find( index[ j]) != m_mapExpressionTreesMod.end() ) &&
					( (*m_mapExpressionTreesMod[ index[ j]]->mapVarIdx).find( i) != (*m_mapExpressionTreesMod[ index[ j]]->mapVarIdx).end()) ){
					// variable i is appears in the expression tree for row index[ j]
					// add the coefficient corresponding to variable i in row index[ j] to the expression tree	
					// define a new OSnLVariable and OSnLnodePlus 
					nlNodeVariable = new OSnLNodeVariable();
					nlNodeVariable->coef = value[ j];
					nlNodeVariable->idx = i;
					nlNodePlus = new OSnLNodePlus();
					nlNodePlus->m_mChildren[ 0] = m_mapExpressionTreesMod[ index[ j] ]->m_treeRoot;
					nlNodePlus->m_mChildren[ 1] = nlNodeVariable;
					expTree = new OSExpressionTree();
					expTree->m_treeRoot = nlNodePlus ;
					expTree->mapVarIdx = m_mapExpressionTreesMod[ index[ j]]->mapVarIdx;
					m_mapExpressionTreesMod[ index[ j] ]  = expTree;	
					//std::cout << m_mapExpressionTreesMod[ index[ j] ]->m_treeRoot->getNonlinearExpressionInXML() << std::endl;	
					//std::cout << m_mapExpressionTrees[ index[ j] ]->m_treeRoot->getNonlinearExpressionInXML() << std::endl;
				}
				else{ 
					m_miJacStart[ index[j] + 1] ++;
				}				
			}
		}
	}
	// at this point, m_miJacStart[ i] holds the number of columns with a linear/constant nonzero in row i - 1
	// we are not done with the start indicies, if we are here, and we
	// knew the correct starting point of row i -1, the correct starting point
	// for row i is m_miJacStart[i] + m_miJacStart [i - 1]
	m_miJacStart[0] = 0;
	for (i = 1; i < iNumRowStarts; i++ ){
		m_miJacNumConTerms[ i - 1] = m_miJacStart[i];
		if( m_mapExpressionTreesMod.find( i - 1) != m_mapExpressionTreesMod.end() ){
			m_miJacStart[i] += (m_miJacStart[i - 1] + (*m_mapExpressionTreesMod[ i - 1]->mapVarIdx).size() );
		}
		else{
			m_miJacStart[i] += m_miJacStart[i - 1];
		}	
	}
	// dimension miIndex and mdValue here
	m_iJacValueSize = 	m_miJacStart[ iNumRowStarts - 1];
	m_miJacIndex = new int[  m_iJacValueSize];
	m_mdJacValue = new double[ m_iJacValueSize ];
	// now get the values of the constant terms if there are any
	if(this->instanceData->linearConstraintCoefficients->numberOfValues > 0){
		// loop over variables	
		for (i = 0; i < iNumVariableStarts; i++){
			// get row indices and values of the A matrix
			// kipp -- should we have a check to see if start[i+1] > start[i]
			for (j = start[i]; j < start[ i + 1 ]; j++){
				// store this variable index in every row where the variable appears
				// however, don't store this as constant term if it appears in mapVarIdx
				if( (m_mapExpressionTreesMod.find( index[ j]) == m_mapExpressionTreesMod.end() ) ||
					( (*m_mapExpressionTreesMod[ index[ j]]->mapVarIdx).find( i) == (*m_mapExpressionTreesMod[ index[ j]]->mapVarIdx).end()) ){
					iTemp = m_miJacStart[ index[j]];
					m_miJacIndex[ iTemp] = i;
					m_mdJacValue[ iTemp] = value[j];
					m_miJacStart[ index[j]]++;	
				}		
			}			
		} 
	}
	//
	std::map<int, int>::iterator posVarIdx;
	// m_miJacStart[ i] is now equal to the correct m_miJacStart[ i] + m_miJacNumConTerms[ i], so readjust
	for (i = 0; i < iNumRowStarts - 1; i++ ){
		m_miJacStart[ i] = m_miJacStart [ i] - m_miJacNumConTerms[ i] ;	
		iTemp = m_miJacStart[ i] + m_miJacNumConTerms[ i];
		// if the row is in the list of expression trees read in idicies and values
		if( m_mapExpressionTreesMod.find( i) != m_mapExpressionTreesMod.end() ){
			for(posVarIdx = (*m_mapExpressionTreesMod[ i]->mapVarIdx).begin(); posVarIdx 
			!= (*m_mapExpressionTreesMod[ i]->mapVarIdx).end(); ++posVarIdx){
				m_miJacIndex[ iTemp] = posVarIdx->first;
				m_mdJacValue[ iTemp] = 0;
				iTemp++;
			}
		}
	}
	#ifdef DEBUG
	std::cout << "HERE ARE ROW STARTS:" << std::endl;
	for (i = 0; i < iNumRowStarts; i++ ){
		std::cout <<  m_miJacStart[ i] << "  ";	
	}
	std::cout << std::endl << std::endl;
	std::cout << "HERE ARE VARIABLE INDICIES:" << std::endl;
	for (i = 0; i < m_miJacStart[ iNumRowStarts - 1]; i++ ){
		std::cout <<  m_miJacIndex[ i] << "  ";	
	}
	std::cout << std::endl << std::endl;
	std::cout << "HERE ARE VALUES:" << std::endl;
	for (i = 0; i < m_miJacStart[ iNumRowStarts - 1]; i++ ){
		std::cout <<  m_mdJacValue[ i] << "  ";	
	}
	std::cout << std::endl << std::endl;

	std::cout << "HERE ARE NUMBER OF CONSTANT TERMS:" << std::endl;
	for (i = 0; i < iNumRowStarts - 1; i++ ){
		std::cout <<  m_miJacNumConTerms[ i ] << "  ";	
	}
	std::cout << std::endl << std::endl;
	#endif
	return true;
}//getSparseJacobianFromColumnMajor

OSExpressionTree* OSInstance::getLagrangianExpTree( ){
	if( m_bLagrangianExpTreeCreated == true) return m_LagrangianExpTree;
	// we calculate the Lagrangian for all the objectives and constraints
	// with nonlinear terms
	// first initialize everything for nonlinear work
	getJacobianSparsityPattern( );	
	std::map<int, OSExpressionTree*>::iterator posMapExpTree;
	OSnLNodeTimes* nlNodeTimes = NULL;
	OSnLNodeVariable* nlNodeVariable = NULL;
	OSnLNodeSum* nlNodeSum = NULL;
	int numChildren = 0;
	int rowIdx;
	// create the sum node
	nlNodeSum = new OSnLNodeSum();
	nlNodeSum->inumberOfChildren = m_mapExpressionTreesMod.size();
	nlNodeSum->m_mChildren = new OSnLNode*[ nlNodeSum->inumberOfChildren];
	// create and expression tree for the sum node
	m_LagrangianExpTree = new OSExpressionTree();
	m_LagrangianExpTree->m_treeRoot = nlNodeSum;
	// now create the children of the sum node
	for(posMapExpTree = m_mapExpressionTreesMod.begin(); posMapExpTree != m_mapExpressionTreesMod.end(); ++posMapExpTree){
		// this variable is the Lagrange multiplier
		nlNodeVariable = new OSnLNodeVariable();
		nlNodeVariable->coef = 1.;
		// get the correct index --
		// for rowIdx = 0, ..., m - 1 set idx = numVar + rowIdx
		rowIdx = posMapExpTree->first;
		if(rowIdx >= 0){
			nlNodeVariable->idx = instanceData->variables->numberOfVariables + rowIdx;
		}
		else{
			nlNodeVariable->idx = instanceData->variables->numberOfVariables + 
			instanceData->constraints->numberOfConstraints + (abs(rowIdx) - 1);
		}
		// now create a times multiply the new variable times the root of the expression tree
		nlNodeTimes = new OSnLNodeTimes();
		nlNodeTimes->m_mChildren[ 0] = nlNodeVariable;
		nlNodeTimes->m_mChildren[ 1] = m_mapExpressionTreesMod[ posMapExpTree->first ]->m_treeRoot;	
		// the times node is the new child
		nlNodeSum->m_mChildren[ numChildren] = nlNodeTimes;
		numChildren++;
	}	
	// get a variable index map for the expression tree
	m_LagrangianExpTree->getVariableIndiciesMap();
	// print out the XML for this puppy
	//std::cout << "Here comes the Lagrangian Tree" << std::endl;
	//std::cout << m_LagrangianExpTree->m_treeRoot->getNonlinearExpressionInXML() << std::endl;
	//
	m_bLagrangianExpTreeCreated = true;
	return m_LagrangianExpTree;
}//getLagrangianExpTree

std::map<int, int> OSInstance::getAllNonlinearVariablesIndexMap( ){
	if(m_bAllNonlinearVariablesIndex == true) return m_mapAllNonlinearVariablesIndex;
	//loop over the map of expression tree and get a unique listing of all variables
	// put these in the map m_mapAllNonlinearVariablesIndex
	std::map<int, OSExpressionTree*>::iterator posMapExpTree;
	std::map<int, int>::iterator posVarIdx;
	OSExpressionTree *expTree;
	for(posMapExpTree = m_mapExpressionTreesMod.begin(); posMapExpTree != m_mapExpressionTreesMod.end(); ++posMapExpTree){
		// get the index map for the expression tree
		expTree = posMapExpTree->second;
		if(expTree->m_bIndexMapGenerated == false)expTree->getVariableIndiciesMap();
		for(posVarIdx = (*expTree->mapVarIdx).begin(); posVarIdx != (*expTree->mapVarIdx).end(); ++posVarIdx){
			if( m_mapAllNonlinearVariablesIndex.find( posVarIdx->first) == m_mapAllNonlinearVariablesIndex.end() ){
			// add the variable to the Lagragian map
			m_mapAllNonlinearVariablesIndex[ posVarIdx->first] = 1;
			}
		}
	}
	m_miNonLinearVarsReverseMap = new int[m_mapAllNonlinearVariablesIndex.size()];
	// now order appropriately
	int kount = 0;
	//std::cout << "HERE IS THE LAGRANGIANN VARIABLE MAPPING" << std::endl;
	for(posVarIdx = m_mapAllNonlinearVariablesIndex.begin(); posVarIdx !=m_mapAllNonlinearVariablesIndex.end(); ++posVarIdx){
		posVarIdx->second = kount;
		m_miNonLinearVarsReverseMap[ kount] = posVarIdx->first;
		kount++;
		#ifdef DEBUG
		std::cout <<  "POSITION FIRST =  "  << posVarIdx->first ;
		std::cout <<  "   POSITION SECOND = "  << posVarIdx->second << std::endl;
		#endif
	}
	m_iNumberOfNonlinearVariables = kount;
	//std::cout <<  "NUMBER OF NONLINEAR VARIABLES =  "  << kount ;
	m_bAllNonlinearVariablesIndex = true;
	return m_mapAllNonlinearVariablesIndex;
}//getAllNonlinearVariablesIndexMap 	

SparseHessianMatrix* OSInstance::getLagrangianHessianSparsityPattern( ){
	// fill in the nonzeros in the sparse Hessian
	if( m_bLagrangianSparseHessianCreated == true) return m_LagrangianSparseHessian;
	if( m_bNonLinearStructuresInitialized == false) initializeNonLinearStructures( );
	// get the number of primal variables in the expression tree
	// the number of lagrangian variables is equal to m_mapExpressionTreesMod.size()s
	if( m_bAllNonlinearVariablesIndex == false) getAllNonlinearVariablesIndexMap( );
	if( m_bNonLinearStructuresInitialized == false) initializeNonLinearStructures( );
	int numVars =  m_mapAllNonlinearVariablesIndex.size();
	std::map<int, int>::iterator posMap1, posMap2;	

	// now that we have the dimension create SparseHessianMatrix (upper triangular)
	m_LagrangianSparseHessian = new SparseHessianMatrix();
	m_LagrangianSparseHessian->bDeleteArrays = true;
	m_LagrangianSparseHessian->hessDimension = numVars*(numVars + 1)/2;
	m_LagrangianSparseHessian->hessRowIdx = new int[m_LagrangianSparseHessian->hessDimension];
	m_LagrangianSparseHessian->hessColIdx = new int[m_LagrangianSparseHessian->hessDimension];
	m_LagrangianSparseHessian->hessValues = new double[m_LagrangianSparseHessian->hessDimension];
	//std::cout << "HESSIAN DIMENSION = " << m_LagrangianSparseHessian->hessDimension << std::endl;
	int i = 0;
	for(posMap1 = m_mapAllNonlinearVariablesIndex.begin(); posMap1 != m_mapAllNonlinearVariablesIndex.end(); ++posMap1){
		//std::cout << "posMap1->first  " << posMap1->first << std::endl;
		if(posMap1->first > numVars) break;
		for(posMap2 = posMap1; posMap2 != m_mapAllNonlinearVariablesIndex.end(); ++posMap2){
			//std::cout << "posMap2->first  " << posMap2->first << std::endl;
			if(posMap2->first <= numVars){
				*(m_LagrangianSparseHessian->hessRowIdx + i) = posMap1->first;
				*(m_LagrangianSparseHessian->hessColIdx + i) = posMap2->first;
				i++;
			}
			else{
				break;
			}
		}	
	}
	//std::cout << "HESSIAN SPARSITY PATTERN" << std::endl;
	for(i = 0; i < m_LagrangianSparseHessian->hessDimension; i++){
		//std::cout <<  "Row Index = " << *(m_LagrangianSparseHessian->hessRowIdx + i) << std::endl;
		//std::cout <<  "Column Index = " << *(m_LagrangianSparseHessian->hessColIdx + i) << std::endl;
	}
	m_bLagrangianSparseHessianCreated = true;
	return m_LagrangianSparseHessian;
}//getLagrangianHessianSparsityPattern


SparseHessianMatrix *OSInstance::calculateLagrangianHessian( double* x, double* conMultipliers, 
	double* objMultipliers, bool allFunctionsEvaluated, bool LagrangianHessianEvaluated){
	if( LagrangianHessianEvaluated == true) return m_LagrangianSparseHessian;
	if( m_bNonLinearStructuresInitialized == false) initializeNonLinearStructures( );
	if( m_bLagrangianSparseHessianCreated == false)	getLagrangianHessianSparsityPattern();
	// initialize everything
	int i, j;
	std::map<int, int>::iterator posVarIndexMap;
	std::map<int, OSExpressionTree*>::iterator posMapExpTree;
	// vdX -- vector of primal variables
	std::vector<double> vdX( m_iNumberOfNonlinearVariables);	
	// vdLamda -- vector of Lagrange multiplies
	std::vector<double> vdLambda( m_mapExpressionTreesMod.size());
	// vdw is the first and second derivative vector
	std::vector<double> vdw( 2*m_iNumberOfNonlinearVariables);
	i = 0;
	// get the current iterate data
	for(posVarIndexMap = m_mapAllNonlinearVariablesIndex.begin(); posVarIndexMap != m_mapAllNonlinearVariablesIndex.end(); ++posVarIndexMap){
			vdX[ i++] = x[ posVarIndexMap->first] ;
	}
	if(m_bCppADFunIsCreated == false) {
		createCppADFun( vdX);
	}
	//Kipp -- come back and put check in see if m_iHighestTaylorCoeffOrder >= 0, if so, don't execute
	this->forwardAD(0, vdX);	
	//  get the Lagrange multipliers
	i = 0;
	for(posMapExpTree = m_mapExpressionTreesMod.begin(); posMapExpTree != m_mapExpressionTreesMod.end(); ++posMapExpTree){	
		if( posMapExpTree->first >= 0){
			vdLambda[i++] = conMultipliers[ posMapExpTree->first];
		}
		else{
			vdLambda[ i++] =  objMultipliers[ abs(posMapExpTree->first) - 1] ;
		}
	}
	int hessValuesIdx = 0;
	// loop over components of x
	// initialize to 0
	for(i = 0; i < m_iNumberOfNonlinearVariables; i++){
		vdX[ i] = 0;
	}
	for(i = 0; i < m_iNumberOfNonlinearVariables; i++){
		vdX[i] = 1.;                
		this->forwardAD(1, vdX);     
		vdw = this->reverseAD(2, vdLambda);   // derivtative of partial
		for(j = i; j < m_iNumberOfNonlinearVariables; j++){
			m_LagrangianSparseHessian->hessValues[ hessValuesIdx++] =  vdw[  j*2 + 1];
		}
		vdX[i] = 0.;
	}
	return m_LagrangianSparseHessian;
}//calculateLagrangianHessian

//SparseHessianMatrix *OSInstance::calculateLagrangianHessian( double* x, double* conMultipliers, 
//	double* objMultipliers, bool allFunctionsEvaluated, bool LagrangianHessianEvaluated){
//	if( LagrangianHessianEvaluated == true) return m_LagrangianSparseHessian;
//	if( m_bNonLinearStructuresInitialized == false) initializeNonLinearStructures( );
//	// initialize everything
//	int i, j;
//	std::map<int, int>::iterator posVarIndexMap;
//	std::map<int, OSExpressionTree*>::iterator posMapExpTree;
//	std::vector<double> m_vdx( m_iNumberOfNonlinearVariables);	
//	std::vector<double> m_vw( m_mapExpressionTreesMod.size());
//	std::vector<double> m_vdw( 2*m_iNumberOfNonlinearVariables);	
//	if( m_bCppADTapesBuilt == false){
//		// this loop is only done once
//		// if we have not filled in the Sparse Jacobian matrix do so now
//		if( m_bSparseJacobianCalculated == false) getJacobianSparsityPattern();
//		// get an index map of all of the nonlinear variables in the Hessian of the  Lagrangian
//		// this method call will define m_iNumberOfNonlinearVariables
//		if( m_bAllNonlinearVariablesIndex == false) getAllNonlinearVariablesIndexMap( );
//		// fill in the nonzeros in the sparse Hessian
//		if( m_bLagrangianSparseHessianCreated == false)	getLagrangianHessianSparsityPattern();
//		// put in code to call CppAD and get the Hessian
//		// for each row with a nonlinear term, build a CppAD representation of the  Expression tree
//		// get the data
//		// push the primal variables
//		
//		for(posVarIndexMap = m_mapAllNonlinearVariablesIndex.begin(); posVarIndexMap != m_mapAllNonlinearVariablesIndex.end(); ++posVarIndexMap){
//			m_vX.push_back( x[ posVarIndexMap->first] );
//			// also initialize the m_vIter
//			m_vXITER.push_back(0.0); 
//		}
//		// declare the independent variables and start recording
//		CppAD::Independent( m_vX);
//		// For expression tree, record the operations for CppAD
//		for(posMapExpTree = m_mapExpressionTreesMod.begin(); posMapExpTree != m_mapExpressionTreesMod.end(); ++posMapExpTree){	
//			m_vFG.push_back( (posMapExpTree->second)->m_treeRoot->constructCppADTape(&m_mapAllNonlinearVariablesIndex, &m_vX) );
//		}	
//		//create the function and stop recording
//		F = new CppAD::ADFun<double>(m_vX, m_vFG);
//		//(*F).Dependent( m_vFG);
//		// allocate necessary vector memory
//		//m_vdx.reserve( m_iNumberOfNonlinearVariables );
//		// initialize to zero
//		for(i = 0; i < m_iNumberOfNonlinearVariables; i++) m_vdx[i] = 0.;
//		//m_vw.reserve( m_mapExpressionTreesMod.size() );
//		//m_vdw.reserve( 2*m_iNumberOfNonlinearVariables );	
//		//m_vXITER.reserve( m_iNumberOfNonlinearVariables);
//		m_vH.reserve( m_iNumberOfNonlinearVariables * m_iNumberOfNonlinearVariables );
//		m_bCppADTapesBuilt = true;
//	}
//	// get the current iterate data
//	i = 0;
//	if(allFunctionsEvaluated == false){
//		//std::cout << "SIZE OF MAP " << m_mapAllNonlinearVariablesIndex.size() <<  std::endl;
//		for(posVarIndexMap = m_mapAllNonlinearVariablesIndex.begin(); posVarIndexMap != m_mapAllNonlinearVariablesIndex.end(); ++posVarIndexMap){
//			m_vXITER[ i++] = x[ posVarIndexMap->first] ;
//			//m_vXITER.push_back( x[ posVarIndexMap->first]);
//		}
//		(*F).Forward(0, m_vXITER);
//		
//	}
//	//  get the Lagrange multipliers
//	i = 0;
//	for(posMapExpTree = m_mapExpressionTreesMod.begin(); posMapExpTree != m_mapExpressionTreesMod.end(); ++posMapExpTree){	
//		if( posMapExpTree->first >= 0){
//			m_vw[i++] = conMultipliers[ posMapExpTree->first];
//		}
//		else{
//			m_vw[ i++] =  objMultipliers[ abs(posMapExpTree->first) - 1] ;
//		}
//	}
//	// loop over components of x
//	for(i = 0; i < m_iNumberOfNonlinearVariables; i++){
//		m_vdx[i] = 1.;                   // m_vdx is i-th elementary vector
//		//std::cout << "do a forward calcuation for variable " << i << std::endl;
//		//std::cout << "size is  " << m_vdx.size() << std::endl;
//		(*F).Forward(1, m_vdx);          // partial w.r.t dx
//		//(*F).Forward(1, dx);          // partial w.r.t dx
//		//std::cout << "do a reverse calculation for variable " << i << std::endl;
//		m_vdw = (*F).Reverse(2, m_vw);   // deritavtive of partial
//		for(j = 0; j < m_iNumberOfNonlinearVariables; j++){
//			m_vH[ i * m_iNumberOfNonlinearVariables + j ] = m_vdw[ j * 2 + 1 ]; // fill in the Hessian
//		}
//		m_vdx[i] = 0.;   // m_vdx is zero vector
//	}
//	int hessValuesIdx = 0;	
//	for(i = 0; i <  m_iNumberOfNonlinearVariables; i++){
//		for (j  = i; j <  m_iNumberOfNonlinearVariables; j++ ){
//			std::cout << "UPPER TRIANGULAR HESSIAN VALUES   " << m_vH[ i*m_iNumberOfNonlinearVariables + j] << std::endl;
//			m_LagrangianSparseHessian->hessValues[ hessValuesIdx++] =  m_vH[ i*m_iNumberOfNonlinearVariables + j];
//		}
//	}	
//	//m_vXITER.clear();
//	//m_vw.clear();
//	return m_LagrangianSparseHessian;
//}//calculateLagrangianHessianOLDWAY

SparseHessianMatrix *OSInstance::calculateLagrangianHessianReTape( double* x, double* conMultipliers, 
	double* objMultipliers, bool allFunctionsEvaluated, bool LagrangianHessianEvaluated){
	if( LagrangianHessianEvaluated == true) return m_LagrangianSparseHessian;
	if( m_bNonLinearStructuresInitialized == false) initializeNonLinearStructures( );
	// initialize everything
	int i, j;
	//std::cout << "START calculateLagrangianHessianReTape" << std::endl;
	CppAD::AD<double> tmpVal;
	std::map<int, int>::iterator posVarIndexMap;
	std::map<int, OSExpressionTree*>::iterator posMapExpTree;
	// if we have not filled in the Sparse Jacobian matrix do so now
	if( m_bSparseJacobianCalculated == false) getJacobianSparsityPattern();
	// get an index map of all of the nonlinear variables in the Hessian of the  Lagrangian
	// this method call will define m_iNumberOfNonlinearVariables
	if( m_bAllNonlinearVariablesIndex == false) getAllNonlinearVariablesIndexMap( );
	// fill in the nonzeros in the sparse Hessian
	if( m_bLagrangianSparseHessianCreated == false)	getLagrangianHessianSparsityPattern();
	// put in code to call CppAD and get the Hessian
	// for each row with a nonlinear term, build a CppAD representation of the  Expression tree
	// get the data
	// push the primal variables
	CppAD::vector< AD<double> > X;
	for(posVarIndexMap = m_mapAllNonlinearVariablesIndex.begin(); posVarIndexMap != m_mapAllNonlinearVariablesIndex.end(); ++posVarIndexMap){
		X.push_back( x[ posVarIndexMap->first] );
	}
	// declare the independent variables and start recording
	CppAD::Independent( X);
	// For expression tree, record the operations for CppAD
	CppAD::vector< AD<double> > L( 1);
	L[ 0] = 0;
	for(posMapExpTree = m_mapExpressionTreesMod.begin(); posMapExpTree != m_mapExpressionTreesMod.end(); ++posMapExpTree){	
		tmpVal = (posMapExpTree->second)->m_treeRoot->constructCppADTape(&m_mapAllNonlinearVariablesIndex, &X);
		//std::cout << "VALUE OF FUNCTION == " << tmpVal << std::endl;
		if( posMapExpTree->first >= 0){
			X.push_back( conMultipliers[ posMapExpTree->first] );
			L[ 0] = L[ 0] + conMultipliers[ posMapExpTree->first]*tmpVal;
		}
		else{
			X.push_back( objMultipliers[ abs(posMapExpTree->first) - 1] );
			L[ 0] = L[ 0] + objMultipliers[ abs(posMapExpTree->first) - 1]*tmpVal;
		}
	}	
	//create the function and stop recording
	CppAD::ADFun<double> G;
	G.Dependent( L);
	m_vXITER.clear();
	// get the current iterate data
	//std::cout <<  "LAGRANGIAN VALUE = " << L[ 0]  << std::endl;	
	std::vector<double> hess( m_iNumberOfNonlinearVariables * m_iNumberOfNonlinearVariables );
	// get the current iterate
	for(posVarIndexMap = m_mapAllNonlinearVariablesIndex.begin(); posVarIndexMap != m_mapAllNonlinearVariablesIndex.end(); ++posVarIndexMap){
		m_vXITER.push_back( x[ posVarIndexMap->first] );
	}
	int hessValuesIdx = 0;
	hess = G.Hessian(m_vXITER, 0);
	for(i = 0; i <  m_iNumberOfNonlinearVariables; i++){
		for (j  = i; j <  m_iNumberOfNonlinearVariables; j++ ){
			//std::cout << "UPPER TRIANGULAR HESSIAN VALUES   " << hess[ i*m_iNumberOfNonlinearVariables + j] << std::endl;
			m_LagrangianSparseHessian->hessValues[ hessValuesIdx++] =  hess[ i*m_iNumberOfNonlinearVariables + j];
		}
	}
	return m_LagrangianSparseHessian;
}//calculateLagrangianHessianReTape



void OSInstance::duplicateExpressionTreesMap(){
	//std::cout << "I AM IN DUPLICATE EXPRSSION TREES MAP" << std::endl;
	if(m_bDuplicateExpressionTreesMap == false){ 
		// first make sure the map was created
		if( m_bProcessExpressionTrees == false) getAllNonlinearExpressionTrees();
		m_mapExpressionTreesMod = m_mapExpressionTrees;
		m_bDuplicateExpressionTreesMap = true;
		return;
	}
	else{
		return;
	}
}//duplicateExpressionTreesMap


/**
 * 
 *revised AD test code
 */
bool OSInstance::createCppADFun(std::vector<double> vdX){
	if( m_bNonLinearStructuresInitialized == false) initializeNonLinearStructures( );
	//if( m_bAllNonlinearVariablesIndex == false) getAllNonlinearVariablesIndexMap( );
	std::map<int, OSExpressionTree*>::iterator posMapExpTree;
	int i;
	size_t n = vdX.size();
	// declare a CppAD vector and fill it in
	CppADvector< AD<double> > vdaX( n );
	for(i = 0; i < n; i++){
		vdaX[ i] = vdX[ i];
	}
	// declare the independent variables and start recording
	CppAD::Independent( vdaX);
	// For expression tree, record the operations for CppAD and put into
	// the range vector m_vFG
	// kipp -- come back and make m_vFG local
	for(posMapExpTree = m_mapExpressionTreesMod.begin(); posMapExpTree != m_mapExpressionTreesMod.end(); ++posMapExpTree){	
		m_vFG.push_back( (posMapExpTree->second)->m_treeRoot->constructCppADTape(&m_mapAllNonlinearVariablesIndex, &vdaX) );
		std::cout << "PUSHING BACK EXPRESSION NUMBER " << posMapExpTree->first << std::endl;
	}	
	//create the function and stop recording
	Fad = new CppAD::ADFun<double>(vdaX, m_vFG);
	std::cout << "range space dimension =  " << m_vFG.size() << std::endl;
	// no forward sweeps done yet
	m_iHighestTaylorCoeffOrder = -1;
	m_bCppADFunIsCreated = true;
	return true;
}//end createCppADFun

std::vector<double> OSInstance::forwardAD(size_t p, std::vector<double> vdX){
	try{
		if(p > (m_iHighestTaylorCoeffOrder + 1) ) throw 
			ErrorClass( "trying to calculate a p order forward when p-1 Taylor coefficient not available");
		// adjust the order of the Taylor coefficient
		m_iHighestTaylorCoeffOrder = p;	
		//for(int i  = 0; i < vdX.size(); i++){
			//std::cout << "ForwardAD Primal Variables " << i   << " " << vdX[ i] << std::endl;
		//}
		return (*Fad).Forward(p, vdX);
	}
	catch(const ErrorClass& eclass){
		throw ErrorClass( eclass.errormsg);
	}  
}//end forwardAD


std::vector<double> OSInstance::reverseAD(size_t p, std::vector<double> vdlambda){
	try{
		if(p != (m_iHighestTaylorCoeffOrder + 1) ) throw 
			ErrorClass( "trying to calculate a p order reverse when p-1 Taylor coefficient not available");
		//for(int i  = 0; i < vdlambda.size(); i++){
		//	std::cout << "ReverseAD Multiplier " << i   << " " << vdlambda[ i] << std::endl;
		//}
		return (*Fad).Reverse(p, vdlambda);
	}
	catch(const ErrorClass& eclass){
		throw ErrorClass( eclass.errormsg);
	}  
}//end forwardAD

bool OSInstance::getIterateResults( double *x, double objMultiplier, double* conMultipliers, int objIdx, int highestOrder){
	// Assume the function is Fad(vdX, vdLambda)
	try{ 
		if( m_bNonLinearStructuresInitialized == false) initializeNonLinearStructures( );
		if( m_bLagrangianSparseHessianCreated == false)  getLagrangianHessianSparsityPattern( );
		// initialize everything
		int i, j, rowNum, objNum, jacIndex;
		int jstart, jend, idx;
		std::vector<double> vdX;
		std::vector<double> vdLambda( m_mapExpressionTreesMod.size());
		OSExpressionTree *expTree = NULL;
		std::map<int, OSExpressionTree*>::iterator posMapExpTree;
		// for sure we must have values for our primal variables	
		for(i = 0; i < m_iVariableNumber; i++){
			if( m_mapAllNonlinearVariablesIndex.find( i) != m_mapAllNonlinearVariablesIndex.end()){
				vdX.push_back( x[ i]);
			}
		}
		// if the dual varaiables are not null we also calculate Hessian
		if( highestOrder == 2){
			if( conMultipliers == NULL) throw ErrorClass("cannot have a null vector of lagrange multipliers when calculating Hessian of Lagrangian");
			i = 0;
			for(posMapExpTree = m_mapExpressionTreesMod.begin(); posMapExpTree != m_mapExpressionTreesMod.end(); ++posMapExpTree){	
				if( posMapExpTree->first >= 0){
					vdLambda[i++] = conMultipliers[ posMapExpTree->first];
				}
				else{
					if(objIdx == posMapExpTree->first) vdLambda[ i++] =  objMultiplier;
					else vdLambda[ i++] =  0.0;
				}
			}
		}
		//kipp -- put in checks on sizes of things. 
		// vdY -- vector of range space
		std::vector<double> vdYval( m_mapExpressionTreesMod.size());
		std::vector<double> vdYjacval( m_mapExpressionTreesMod.size());	
		std::vector<double> vdw( 2*m_iNumberOfNonlinearVariables);
		if( (m_bCppADFunIsCreated == false)  && (m_mapExpressionTreesMod.size() > 0) ) {
			createCppADFun( vdX);
		}
		// get the current iterate data
		// first get the function values
		if( m_mapExpressionTreesMod.size() > 0){
			vdYval = this->forwardAD(0, vdX);	
			m_iHighestOrderEvaluated = 0;
		}
		// now get all function and constraint values using forward result
		for(rowNum = 0; rowNum < m_iConstraintNumber; rowNum++){
			m_mdConstraintFunctionValues[ rowNum] = 0.0;
			if( m_mapExpressionTreesMod.find( rowNum) != m_mapExpressionTreesMod.end() ){
				m_mdConstraintFunctionValues[ rowNum] = vdYval[m_iObjectiveNumber + rowNum];
			}
			// now the linear part
			// be careful, loop over only the constant terms in sparseJacMatrix
			i = m_sparseJacMatrix->starts[ rowNum];
			j = m_sparseJacMatrix->starts[ rowNum + 1 ];
			while ( (i - m_sparseJacMatrix->starts[ rowNum])  < m_sparseJacMatrix->conVals[ rowNum] ){
				m_mdConstraintFunctionValues[ rowNum] += m_sparseJacMatrix->values[ i]*x[ m_sparseJacMatrix->indexes[ i] ];
				i++;
			}	
			// add in the constraint function constant
			m_mdConstraintFunctionValues[ rowNum] += m_mdConstraintConstants[ rowNum ];
			std::cout << "Constraint " << rowNum << " function value =  " << m_mdConstraintFunctionValues[ rowNum] << std::endl;
		}
		// now get the objective function values from the forward result
		for(objNum = 0; objNum < m_iObjectiveNumber; objNum++){
			m_mdObjectiveFunctionValues[ objNum] = 0.0;
			if( m_mapExpressionTreesMod.find( -objNum -1) != m_mapExpressionTreesMod.end() ){
				m_mdObjectiveFunctionValues[ objNum] = vdYval[ objNum];
			}
			for(i = 0; i < m_iVariableNumber; i++){
				m_mdObjectiveFunctionValues[ objNum] += m_mmdDenseObjectiveCoefficients[ objNum][i]*x[ i];
			}
			std::cout << "Objective " << objNum << " function value =  " << m_mdObjectiveFunctionValues[ objNum] << std::endl;
		}		
		/// done calculating function values
		if(highestOrder == 0) return true;
		/// highestOrder is now either 1 or 2
		// now get the Jacobian and Hessian (if vdLambda.size() > 0)
		int hessValuesIdx = 0;
		// loop over components of x
		// initialize to 0
		// kipp -- make more efficient -- make class variable intiailly zero -- do this in initialize nonlinear -- and then just change one component at a time
		for(i = 0; i < m_iNumberOfNonlinearVariables; i++){
			vdX[ i] = 0;
		}
		for(i = 0; i < m_iNumberOfNonlinearVariables; i++){
			vdX[i] = 1.;     
			rowNum = 0;
			if( m_mapExpressionTreesMod.size() > 0){          
				vdYjacval = this->forwardAD(1, vdX);
				m_iHighestOrderEvaluated = 1;
			} 
			// fill in Jacobian here, we have column i 
			// start Jacobian calculation
			for(posMapExpTree = m_mapExpressionTreesMod.begin(); posMapExpTree != m_mapExpressionTreesMod.end(); ++posMapExpTree){
				idx = posMapExpTree->first;
				// we are considering only constraints, not objective function
				if(idx >= 0){
					//figure out original variable this corresponds to
					//then use (*m_mapExpressionTreesMod[ idx]->mapVarIdx) to figure out which variable it is within row idx
					//m_mapAllNonlinearVariablesIndex
					//std::cout << "This is the following variable in the expression tree  " <<  (*m_mapExpressionTreesMod[ idx]->mapVarIdx)[ m_miNonLinearVarsReverseMap[ i]]<< std::endl; 			
					expTree = m_mapExpressionTreesMod[ idx];		
					if( (*expTree->mapVarIdx).find( m_miNonLinearVarsReverseMap[ i]) != (*expTree->mapVarIdx).end()  ){		
						jacIndex = (*m_mapExpressionTreesMod[ idx]->mapVarIdx)[ m_miNonLinearVarsReverseMap[ i]];
						jstart = m_miJacStart[ idx] + m_miJacNumConTerms[ idx];
						// kipp change 1 to number of objective functions
						m_mdJacValue[ jstart + jacIndex] = vdYjacval[m_iObjectiveNumber + rowNum];
					}
					rowNum++;
				}//end Jacobian calculation
				else{
					// see if we have the objective function of interest
					if( objIdx == idx){
						*(m_mdObjGradient + m_miNonLinearVarsReverseMap[ i]) = vdYjacval[ (abs( idx) - 1)] + 
							m_mmdDenseObjectiveCoefficients[  (abs( idx) - 1)][ m_miNonLinearVarsReverseMap[ i]];
					}					
				}//end Obj gradient calculation 
			}			
			// now calculate the Hessian if necessary
			if( highestOrder == 2){ 
				if( m_mapExpressionTreesMod.size() > 0){   
					vdw = reverseAD(2, vdLambda);   // derivtative of partial
					m_iHighestOrderEvaluated = 2;
				}
				for(j = i; j < m_iNumberOfNonlinearVariables; j++){
					m_LagrangianSparseHessian->hessValues[ hessValuesIdx++] =  vdw[  j*2 + 1];
				}
			}//done with Hessian
			//
			//
			vdX[i] = 0.;
		}
		#ifdef DEBUG
		if(highestOrder == true){
			std::cout << "HERE IS HESSIAN OF THE LAGRANGIAN" << std::endl;
			for(i = 0; i < hessValuesIdx; i++){
				std::cout << "reverse 2 " << m_LagrangianSparseHessian->hessValues[ i] << std::endl;
			}
		}
		#endif
		#ifdef DEBUG
		std::cout  << "JACOBIAN DATA " << std::endl;
		for(idx = 0; idx < m_iConstraintNumber; idx++){
			for(int k = *(m_sparseJacMatrix->starts + idx); k < *(m_sparseJacMatrix->starts + idx + 1); k++){
				std::cout << "row idx = " << idx <<  "  col idx = "<< *(m_sparseJacMatrix->indexes + k)
				<< " value = " << *(m_sparseJacMatrix->values + k) << std::endl;
			}
		}
		#endif
	}
	catch(const ErrorClass& eclass){
		throw ErrorClass( eclass.errormsg);
	}  
}//end getIterateResults



bool OSInstance::initForCallBack(){
	initializeNonLinearStructures( );
	getJacobianSparsityPattern();
	getLagrangianHessianSparsityPattern();
	return true;
}


/**
 * end revised AD test code
 */


