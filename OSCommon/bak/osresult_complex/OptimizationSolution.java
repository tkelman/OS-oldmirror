/**
 * @(#)OptimizationSolution 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.datastructure.osresult;

/**
*
* <p>A data structure class that corresponds to an xml element in the OSrL schema.  
*  
* </p>
* @author Robert Fourer, Jun Ma, Kipp Martin
* @version 1.0, 03/14/2004
* @since OS 1.0
*/
public class OptimizationSolution {
	
	public int objectiveIdx = 0;
	
	public OptimizationSolutionStatus status = new OptimizationSolutionStatus();
	
	public String message = "";
	
	public VariableSolution variables = null;
	
	public ObjectiveSolution objectives = null;
	
	public ConstraintSolution constraints = null;
	
	public OtherOptimizationResult[] other = null;
	
	
	
}//OptimizationSolution


