#ifndef ECERRORSGDV_H
#define ECERRORSGDV_H

#include "EcError.h"

/**
 * \brief Class EcErrorSGDV.
 * 
 * The class EcErrorSGDV create exeptions when an error occurs on the EcSlaveSGDV.  
 */
class EcErrorSGDV: public EcError
{
public:
    enum 
    {
	ECAT_ERROR,
	FAIL_EC_INIT,
	FAIL_EC_CONFIG_INIT,
	FAIL_SWITCHING_STATE_INIT,
	FAIL_SWITCHING_STATE_PRE_OP,
	FAIL_SWITCHING_STATE_SAFE_OP,
	FAIL_SWITCHING_STATE_OPERATIONAL,
	FAIL_CREATING_DRIVER,	
	FAIL_OUTPUT_LABEL,
	FAIL_OPENING_OUTPUT,
	FAIL_WRITING,
	FAIL_INPUT_LABEL,
	FAIL_OPENING_INPUT,
	FAIL_READING,
	XML_STRUCTURE_ERROR,
	XML_NOT_FOUND_ERROR,
	XML_TYPE_ERROR,
	OUTPUT_OBJECTS_ERROR,
	INPUT_OBJECTS_ERROR,
	WRONG_ENTRY_ERROR,
	FUNCTION_NOT_ALLOWED_ERROR,
    };
    
    /**
    * \brief Constructor
    *   
    */
    EcErrorSGDV (int errorcode, unsigned int nslave, std::string name);
    
    /**
    * \brief Get string identifying exception
    *	   
    */
    const char* what() const throw();



private:
  int slave_nr;
  std::string slave_name;
};

#endif