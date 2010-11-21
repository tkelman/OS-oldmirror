/* $Id: OSColGenApp.h 3038 2009-11-07 11:43:44Z kmartin $ */
/** @file OSBlockBearcatSolver.h
 * 
 *
 * @author  Gus Gassmann, Jun Ma, Kipp Martin, 
 * @version 1.0, 21/July/2008
 * @since   OS1.1
 *
 * \remarks
 * Copyright (C) 2005-2008, Gus Gassmann, Jun Ma, Kipp Martin,
 * Dalhousie University,  Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */

#ifndef OSCOLGENAPP_H
#define OSCOLGENAPP_H

// --------------------------------------------------------------------- //
#include "OSDataStructures.h"
#include "OSDefaultSolver.h" 
#include "OSrLReader.h"
#include "OSOption.h"
#include "OSInstance.h"
#include "OSoLReader.h"

#include "OSRouteSolver.h"


#include<map>
// --------------------------------------------------------------------- //
/*!
 * \class 
 * OSColGenApp
 * 
 *
 */
// --------------------------------------------------------------------- //
class OSColGenApp {
public:
	

	OSInstance *m_osinstanceMaster;
	OSOption *m_osoption;
	OSResult *m_osresult;
	
	OSRouteSolver *m_osrouteSolver;
	
	
	/** kipp -- document */
	void solveRestrictedMasterRelaxation();
	
	void getInitialRestrictedMaster( );
	
	void getOptions( OSOption *osoption);
	
	/**
	 * RETURN VALUES: 
	 * int numNewRows -- number of new rows generated
	 * int* numNonz -- number of nonzeros in each row
	 * double** colIdx -- vectors column indexes of new rows
	 * double** values -- vectors of matrix coefficient values of new rows
	 * double* rowLB -- vector of row lower bounds
	 * double* rowUB -- vector of row upper bounds
	 * 
	 * INPUT:
	 * double* thetaVar -- the vector of primal master values
	 * int numThetaVar -- size of master primal vector
	 */
	void getCuts(const  double* thetaVar, const int numThetaVar,
			int &numNewRows, int*  &numNonz, int** &colIdx,
			double** &values, double* &rowLB, double* &rowUB) ;	
	
	/**
	 * RETURN VALUES: 
	 * int numNewColumns -- number of new columns generated
	 * int* numNonz -- number of nonzeros in each column
	 * double* cost -- the objective function coefficient on each new column
	 * double** rowIdx -- vectors row indexes of new columns
	 * double** values -- vectors of matrix coefficient values of new columns
	 * double lowerBound -- the lowerBound
	 * 
	 * INPUT:
	 * double* yA -- the vector of dual values on the coupling constraints
	 * int numARows -- size of the yA dual vector
	 * double* yB -- the vector of dual values on the tour breaking constaints
	 * int numBRows -- size of the yA dual vector
	 */
	void getColumns(const  double* yA, const int numARows,
			const  double* yB, const int numBRows,
			int &numNewColumns, int* &numNonz, double* &cost, 
			int** &rowIdx, double** &values, double &lowerBound) ;
	
	/**
	 *
	 * Default Constructor. 
	 */	
	OSColGenApp();
	
	/**
	 *
	 * Second Constructor. 
	 */	
	OSColGenApp( OSOption *osption);
	

	/**
	 *
	 * Default destructor. 
	 */	
	~OSColGenApp();	

	//
};//end class OSColGenApp

#endif

