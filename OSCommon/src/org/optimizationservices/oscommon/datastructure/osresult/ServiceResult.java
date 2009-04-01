/**
 * @(#)ServiceOption 1.0 03/14/2009
 *
 * Copyright (c) 2009
 */
package org.optimizationservices.oscommon.datastructure.osresult;


/**
*
* <p>A data structure class that corresponds to an xml element in the OSrL schema.  
*  
* </p>
* @author Gus Gassmann, Jun Ma, Kipp Martin
* @version 1.0, 03/14/2009
* @since OS 2.0
*/
public class ServiceResult{
	
	public String type = "solver";
	
	public OtherResults otherOptions = null;

}//class ServiceResult
