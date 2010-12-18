/* $Id: OSNodeApp.h 3038 2009-11-07 11:43:44Z kmartin $ */
/** @file OSNodeApp.h
 * 
 *
 *
 * @author  Horand Gassmann, Jun Ma, Kipp Martin, 
 * @version 1.0, 19/07/2010
 * @since   OS2.2
 *
 * \remarks
 * Copyright (C) 2005-2010, Jun Ma, Horand Gassmann, Kipp Martin,
 * Northwestern University, Dalhousie University and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */

#ifndef OSNODE_H
#define OSNODE_H


// --------------------------------------------------------------------- //
/*!
 * \class 
 * OSNode
 * 
 *
 */
// --------------------------------------------------------------------- //

class OSNode {
	public:
	
	/** rowIdx is a vector of row indexes for which we are setting
	 * the upper and lower bounds
	 */
	int* rowIdx
	
	/** rowIdxNumNonz is the number of non-zero elements in rowIndex */
	int rowIdxNumNonz
	
	/** rowUB is a vector of row upper bounds */
	double* rowUB
	
	/** rowLB is a vector of row lower bounds */
	double* rowUB
	
	/** lpValue is the LP relaxation for the node */
	double lpValue
	
	/** thetaNumNonz is the number of non-zero elements in the
	 * theta variable solution at this node */
	int thetaNumNonz
	
	/** theta is a vector of primal solution
	 * variable indexes
	 */
	int* thetaIdx
	
	/** theta is a vector of primal solutions 
	 * this is used for branching and creating new
	 * children nodes
	 */
	double* theta
	
	
};//end class OSNode

#endif