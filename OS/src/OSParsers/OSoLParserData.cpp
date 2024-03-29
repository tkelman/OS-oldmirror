/* $Id$ */
/** @file OSoLParserData.cpp
 *
 * @author  Horand Gassmann, Jun Ma, Kipp Martin,
 *
 * \remarks
 * Copyright (C) 2005-2011, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 */
#include "OSoLParserData.h"

OSoLParserData::~OSoLParserData()
{

}//~OSoLParserData


OSoLParserData::OSoLParserData() :
    osolgeneralPresent(false),
    osolsystemPresent(false),
    osolservicePresent(false),
    osoljobPresent(false),
    osoloptimizationPresent(false),

    serviceURIPresent(false),
    serviceNamePresent(false),
    instanceNamePresent(false),
    instanceLocationPresent(false),
    instanceLocationTypeattON(false),
    jobIDPresent(false),
    solverToInvokePresent(false),
    licensePresent(false),
    usernamePresent(false),
    passwordPresent(false),
    contactPresent(false),
    transportTypeattON(false),
    otherGeneralOptionsPresent(false),
    numberOfOtherGeneralOptions(0),

    minDiskSpacePresent(false),
    minDiskSpaceUnitPresent(false),
    minMemoryPresent(false),
    minMemoryUnitPresent(false),
    minCPUSpeedPresent(false),
    minCPUSpeedUnitPresent(false),
    minCPUNumberPresent(false),
    otherSystemOptionsPresent(false),
    numberOfOtherSystemOptions(0),

    serviceTypePresent(false),
    otherServiceOptionsPresent(false),
    numberOfOtherServiceOptions(0),

    maxTimePresent(false),
    maxTimeUnit(""),
    maxTimeUnitPresent(false),
    maxTimeValue(0.0),
    requestedStartTimePresent(false),
    requestedStartTime(""),
    dependenciesPresent(false),
    numberOfDependencies(0),
    requiredDirectoriesPresent(false),
    numberOfRequiredDirectories(0),
    requiredFilesPresent(false),
    numberOfRequiredFiles(0),
    directoriesToMakePresent(false),
    numberOfDirectoriesToMake(0),
    filesToMakePresent(false),
    numberOfFilesToMake(0),
    pathPairFrom(""),
    pathPairTo(""),
    pathPairFromPresent(false),
    pathPairToPresent(false),
    pathPairMakeCopyPresent(false),
    pathPairMakeCopy(false),
    inputDirectoriesToMovePresent(false),
    numberOfInputDirectoriesToMove(0),
    inputFilesToMovePresent(false),
    numberOfInputFilesToMove(0),
    outputDirectoriesToMovePresent(false),
    numberOfOutputDirectoriesToMove(0),
    outputFilesToMovePresent(false),
    numberOfOutputFilesToMove(0),
    directoriesToDeletePresent(false),
    numberOfDirectoriesToDelete(0),
    filesToDeletePresent(false),
    numberOfFilesToDelete(0),
    processesToKillPresent(false),
    numberOfProcessesToKill(0),
    otherJobOptionsPresent(false),
    numberOfOtherJobOptions(0),
    numberOfPathPairs(0),

    numberOfVariables(0),
    numberOfVariablesPresent(false),
    numberOfObjectives(0),
    numberOfObjectivesPresent(false),
    numberOfConstraints(0),
    numberOfConstraintsPresent(false),
    variablesPresent(false),
    objectivesPresent(false),
    constraintsPresent(false),
    solverOptionsPresent(false),
    idxAttributePresent(false),
    valAttributePresent(false),
    lbValAttributePresent(false),
    ubValAttributePresent(false),
    numberOfOtherVariableOptions(0),
    initialVariableValuesPresent(false),
    numberOfVar(0),
    initialVariableValuesStringPresent(false),
    numberOfVarStr(0),
    initialBasisStatusPresent(false),
    numberOfBasVar(0),
    sosIdxAttributePresent(false),
    groupWeightAttributePresent(false),
    numberOfVarAttributePresent(false),
    numberOfObjAttributePresent(false),
    numberOfConAttributePresent(false),
    numberOfEnumerationsAttributePresent(false),
    numberOfIntWt(0),
    numberOfSOS(0),
    currentSOS(0),
    sosIdx(0),
    numberOfSOSVar(0),
    numberOfObj(0),
    numberOfOtherObjectiveOptions(0),
    initialObjectiveValuesPresent(false),
    numberOfObjValues(0),
    initialObjectiveBoundsPresent(false),
    numberOfObjBounds(0),
    numberOfCon(0),
    numberOfOtherConstraintOptions(0),
    initialConstraintValuesPresent(false),
    initialDualVariableValuesPresent(false),
    numberOfDuals(0),
    numberOfSolverOptions(0),
    groupWeight(0.0),
    lbDualValue(0.0),
    ubDualValue(0.0),
    numberOfEnumerations(0),
    otherOptionType(0),

    otherOptionNumberPresent(false),
    otherOptionNamePresent(false),
    otherOptionValuePresent(false),
    otherOptionSolverPresent(false),
    otherOptionCategoryPresent(false),
    otherOptionTypePresent(false),
    otherOptionDescriptionPresent(false),
    numberOfItemsPresent(false),
    numberOfItems(0),

    solverOptionNamePresent(false),
    solverOptionValuePresent(false),
    solverOptionSolverPresent(false),
    solverOptionCategoryPresent(false),
    solverOptionTypePresent(false),
    solverOptionDescriptionPresent(false),
    itemContent(""),

    categoryAttributePresent(false),
    categoryAttribute(""),
    typeAttributePresent(false),
    typeAttribute(""),
    varTypeAttributePresent(false),
    varTypeAttribute(""),
    objTypeAttributePresent(false),
    objTypeAttribute(""),
    conTypeAttributePresent(false),
    conTypeAttribute(""),
    enumTypeAttributePresent(false),
    enumTypeAttribute(""),
    nameAttributePresent(false),
    nameAttribute(""),
    valueAttributePresent(false),
    valueAttribute(""),
    lbValueAttributePresent(false),
    lbValueAttribute(""),
    ubValueAttributePresent(false),
    ubValueAttribute(""),
    descriptionAttributePresent(false),
    descriptionAttribute(""),
    solverAttributePresent(false),
    solverAttribute(""),
    unitAttributePresent(false),
    unitAttribute(""),
    idxAttribute(0),

    jobDependencies(NULL),
    paths(NULL),
    fromPaths(NULL),
    toPaths(NULL),
    processesToKill(NULL),

    valueString(NULL),
    lbValueString(NULL),
    ubValueString(NULL),
    itemList(NULL),

    makeCopy(NULL),
    idxArray(NULL),

    valArray(NULL),
    lbValArray(NULL),
    ubValArray(NULL),

    namArray(NULL),

    tempInt(0),
    numberOf(0),
    kounter(0),
    iOther(0),
    iOption(0),
    tempVal(0.0),
    tempStr(""),

    statusType(""),
    statusDescription(""),
    errorText(NULL)
{

}//OSoLParserData

