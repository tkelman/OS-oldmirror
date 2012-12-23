/* $Id: OSOutput.h 3172 2012-11-12 04:59:24Z Gassmann $ */
/** @file OSOutput.h
 *
 *
 * @author  Horand Gassmann, Jun Ma, Kipp Martin
 *
 * \remarks
 * Copyright (C) 2012, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 */
#ifndef OSOUTPUT_H
#define OSOUTPUT_H

#include "OSConfig.h"
#include "OSParameters.h"
#include "OSIpReferenced.hpp"
#include "OSIpSmartPtr.hpp"

#include <string>
#include <vector>

#ifdef HAVE_CSTDIO
# include <cstdio>
#else
# ifdef HAVE_STDIO_H
#  include <stdio.h>
# else
#  error "don't have header file for stdio"
# endif
#endif

/**
 *  Enumeration for the different verbosity levels that can be used in producing output.
 *  The last three levels are used only in debug mode.
 */
enum ENUM_OUTPUT_LEVEL
{
     ENUM_OUTPUT_LEVEL_always = 0,
     ENUM_OUTPUT_LEVEL_error,
     ENUM_OUTPUT_LEVEL_summary,
     ENUM_OUTPUT_LEVEL_warning,
     ENUM_OUTPUT_LEVEL_info,
     ENUM_OUTPUT_LEVEL_debug,
     ENUM_OUTPUT_LEVEL_trace,
     ENUM_OUTPUT_LEVEL_detailed_trace,

     ENUM_OUTPUT_LEVEL_NUMBER_OF_LEVELS    // insert other values above this one...
};

#define DEFAULT_OUTPUT_LEVEL ENUM_OUTPUT_LEVEL_error

/**
 *  Enumeration for the different areas that can produce output.
 *  The last entry ENUM_OUTPUT_AREA_NUMBER_OF_AREAS
 *  gives a convenient way to count them and to allocate space
 */
enum ENUM_OUTPUT_AREA
{
     ENUM_OUTPUT_AREA_main = 0,
     ENUM_OUTPUT_AREA_OSAgent,
     ENUM_OUTPUT_AREA_Command_line_parser,
     ENUM_OUTPUT_AREA_OSiL_parser,
     ENUM_OUTPUT_AREA_OSoL_parser,
     ENUM_OUTPUT_AREA_OSrL_parser,
     ENUM_OUTPUT_AREA_OSInstance,
     ENUM_OUTPUT_AREA_OSOption,
     ENUM_OUTPUT_AREA_OSResult,
     ENUM_OUTPUT_AREA_OSiLwriter,
     ENUM_OUTPUT_AREA_OSoLwriter,
     ENUM_OUTPUT_AREA_OSrLwriter,
     ENUM_OUTPUT_AREA_OSModelInterfaces,
     ENUM_OUTPUT_AREA_OSSolverInterfaces,
     ENUM_OUTPUT_AREA_OSUtils,

     ENUM_OUTPUT_AREA_NUMBER_OF_AREAS    // insert other values above this one...
};

/*! \class OSOutputChannel
 * \brief a class that holds information about one output channel
 * (file, device, stream, peripheral, etc.)
 */
class OSOutputChannel
{
private:
    /**
     *  used to give a name to the file or device
     */
    std::string name;

    /**
     *  holds a pointer to the file or device
     */
    FILE* file;

    /** 
     *  vector of integers indicating the level for each area
     */
    int printLevel[ENUM_OUTPUT_AREA_NUMBER_OF_AREAS];


public:
    /** 
     *  Constructor. 
     *  @param name holds the name of the file or device
     *  that applies to this output device in all code areas 
     */
    OSOutputChannel(std::string name);

    /** 
     *  Destructor
     */
    ~OSOutputChannel();

    /** 
     *  Get the name of the output channel
     */
    std::string Name();

    /** 
     *  Set the print level for a particular area 
     *  @param area holds the area of the code to which this option is to be applied
     *  @param level holds a valid print level
     *  @return whether the set() was successful
     */
    bool setPrintLevel(ENUM_OUTPUT_AREA area, ENUM_OUTPUT_LEVEL level);

    /** Set the print level for all areas 
     *  @param level holds a valid print level
     *  @return whether the set() was successful
     */
    bool setAllPrintLevels(ENUM_OUTPUT_LEVEL level);

    /** Set different print levels for all areas 
     *  @param level holds an array of valid print levels
     *  @param dim holds the number of entries in the array level
     *  @return whether the set() was successful
     */
    bool setAllPrintLevels(ENUM_OUTPUT_LEVEL* level, int dim);

    /** Test if the device accepts a particular combination of
     *  print level and area (i.e., if the output should be printed)
     */
    bool isAccepted(ENUM_OUTPUT_AREA area, ENUM_OUTPUT_LEVEL level);

    /** 
     *  Send one string to the output device provided that the output
     *  device "accepts" the output (i.e., the print level applicable
     *  to the area that originated the output exceeds the level of
     *  the print statement
     *
     *  @param area:  the area in which the output string originated
     *  @param level: the print level associated with the string
     *  @param str:   the string that is to be printed
     */
    void OSPrintf(ENUM_OUTPUT_AREA area, ENUM_OUTPUT_LEVEL level, std::string str);

    /** 
     *  Flush output buffer
     */
    void flushBuffer();

    /**
     *  @name Open: open the channel
     *  @return true if successfully opened; false otherwise
     */
    bool Open();
};

/*! \class OSOutput
 *  \brief This class handles all the output from OSSolverService, 
 *  OSAmplClient and other executables derived from them.
 *  Every output statement in the code uses methods in this class,
 *  passing information about the area that originated the request
 *  as well as the print, verbosity or severity level of the message.
 *  The message creates output only if the print level matches the user
 *  specifications.
 *  The main advantage of doing things this way is that multiple output
 *  streams can be maintained, each tailored to a specific need and
 *  containing only output that the user really wants to see.
 *  There can be as many output streams as needed; each one has an
 *  identifying name ("stdout" and "stderr" are reserved names)
 *  and an array of print levels, one for each area.
 *  The class is implemented as a Singleton, which means that two
 *  private methods must be defined in the header but must *never*
 *  be implemented: a copy constructor, and an equality operator.
 */
class OSOutput : public ReferencedObject
{
private:
    OSOutput(const OSOutput&);
    OSOutput& operator =(const OSOutput&);
public:
    /**
     *  Constructor
     */
    OSOutput();

    /**
     *  Destructor
     */
    ~OSOutput();
    
    /** This is the main method to output a string
     *  All output generated by the program should ultimately 
     *  use this method
     *   
     *  @param level:  the print level associated with the string
     *  @param area:   the area of the code in which the output was generated
     *  @param outStr: the string to be output   
     *  @return whether the output operation was successful
     */
    bool OSPrint(ENUM_OUTPUT_AREA area, ENUM_OUTPUT_LEVEL level, std::string outStr);

    /**
     *  Flush all buffers
     */
    void FlushAllBuffers();

    /** Modify all print levels associated with a channel
     *  @param name: The name of the channel ("stdout" and "stderr" are reserved names)
     *  @param level: The array of print levels used for the output to this channel
     *  @param dim: The number of entries in this array 
     *  @return whether the operation was successful
     */
    bool SetPrintLevel(std::string name, ENUM_OUTPUT_LEVEL* level, int dim);

    /** Modify one particular print level associated with a channel
     *  @param name:  The name of the channel ("stdout" and "stderr" are reserved names)
     *  @param level: The print level to be used for the output to this channel
     *  @param area:  The area of the code to which this print level applies
     *  @return whether the operation was successful
     */
    bool SetPrintLevel(std::string name, ENUM_OUTPUT_LEVEL level, ENUM_OUTPUT_AREA area);

    /** set all print levels associated with a channel to the same value
     *  @param name: The name of the channel ("stdout" and "stderr" are reserved names)
     *  @param level: The global print level used for the output to this channel
     *  @return whether the operation was successful
     */
    bool SetPrintLevel(std::string name, ENUM_OUTPUT_LEVEL level);

    /** Add a channel to the array outputChannel
     *  @param name: The name of the channel ("stdout" and "stderr" are reserved names)
     *  @return the status of the operation:
     *      0: completed successfully
     *      1: channel previously defined
     *      2: out of memory
     *      3: other error condition
     */
    int AddChannel(std::string name);


    /** Delete a channel from the array outputChannel
     *  @param name: The name of the channel 
     *  @return whether the operation was completed successfully
     */
    bool DeleteChannel(std::string name);

    /** Find the position of a channel within the array *outputChannel
     *
     *  @param name: The name of the channel
     *  @return the position if found; -1 otherwise
     */
    int FindChannel(std::string name);

private:
    /**
     *  The number of output channels that have been defined
     */
    int nOfOutputs;

    /**
     *  The array of output channels currently in use
     */
    OSOutputChannel** outputChannel;
};


// osoutput takes care of all output (see ticket 14)
// It is declared here as a global variable 
// so as to minimize the changes to the API

extern const SmartPtr</*const*/ OSOutput> osoutput;

#endif
