/****************************************************************************/
// Eclipse SUMO, Simulation of Urban MObility; see https://eclipse.org/sumo
// Copyright (C) 2001-2018 German Aerospace Center (DLR) and others.
// This program and the accompanying materials
// are made available under the terms of the Eclipse Public License v2.0
// which accompanies this distribution, and is available at
// http://www.eclipse.org/legal/epl-v20.html
/****************************************************************************/
/// @file    NIXMLTypesHandler.h
/// @author  Daniel Krajzewicz
/// @author  Jakob Erdmann
/// @author  Michael Behrisch
/// @date    Tue, 20 Nov 2001
/// @version $Id$
///
// Importer for edge type information stored in XML
/****************************************************************************/
#ifndef NIXMLTypesHandler_h
#define NIXMLTypesHandler_h


// ===========================================================================
// included modules
// ===========================================================================
#ifdef _MSC_VER
#include <windows_config.h>
#else
#include <config.h>
#endif

#include <utils/xml/SUMOSAXHandler.h>


// ===========================================================================
// class declarations
// ===========================================================================
class NBTypeCont;


// ===========================================================================
// class definitions
// ===========================================================================
/**
 * @class NIXMLTypesHandler
 * @brief Importer for edge type information stored in XML
 *
 * This SAX-handler parses edge type information and stores it in the given
 *  container.
 */
class NIXMLTypesHandler : public SUMOSAXHandler {
public:
    /** @brief Constructor
     *
     * @param[in, filled] tc The type container to fill
     */
    NIXMLTypesHandler(NBTypeCont& tc);


    /// @brief Destructor
    ~NIXMLTypesHandler();


protected:
    /// @name inherited from GenericSAXHandler
    //@{

    /** @brief Called on the opening of a tag; Parses edge type information
     *
     * Tries to parse a type. If the type can be parsed, it is stored within
     *  "myTypeCont". Otherwise an error is generated. No exception is thrown
     *  so that the parsing continues and further errors can be reported.
     *
     * @param[in] element ID of the currently opened element
     * @param[in] attrs Attributes within the currently opened element
     * @exception ProcessError If something fails (not used herein)
     * @note policy is to throw no exception in order to allow further processing
     */
    void myStartElement(int element,
                        const SUMOSAXAttributes& attrs);
    //@}


private:
    /// @brief The type container to fill
    NBTypeCont& myTypeCont;

    /// @brief The currently parsed type
    std::string myCurrentTypeID;


private:
    /** @brief invalid copy constructor */
    NIXMLTypesHandler(const NIXMLTypesHandler& s);

    /** @brief invalid assignment operator */
    NIXMLTypesHandler& operator=(const NIXMLTypesHandler& s);


};


#endif

/****************************************************************************/

