#ifndef ECSLAVE_H
#define ECSLAVE_H

#include "EcError.h"
// #include <iostream>
// #include <sstream>
#include <vector>
#include <stdint.h>

extern "C"
{
#include <soem/ethercattype.h>
#include <soem/nicdrv.h>
#include <soem/ethercatbase.h>
#include <soem/ethercatmain.h>
#include <soem/ethercatconfig.h>
#include <soem/ethercatdc.h>
#include <soem/ethercatcoe.h>
#include <soem/ethercatprint.h>
}

#include <boost/signals2/signal.hpp>


typedef struct
{
   uint16_t   index;
   uint8_t    subindex;
   uint8_t    size;
   int      param;
   std::string   name;
   std::string   description;
} CoEparameter;

typedef struct
{
   uint16_t   idn;
   uint8_t    elementflags;
   uint8_t    size;
   int        param;
   std::string   name;
   std::string   description;
} SoEparameter;


namespace cpp4ec
{
/**
* \brief Class EcSlave
* 
* The EcSlave is a base class designed as a template for ethercat slaves.  
*/  
class EcSlave
{
public:
    /**
    * \brief Destructor
    *   
    */
    virtual ~EcSlave();
    
    /**
    * \brief Get the slave name
    *   
    */
    const std::string& getName() const;

    /**
    * \brief Configures the slave
    *   
    */
    virtual bool configure();
    
    /**
    * \brief Starts the slave
    *   
    */
    virtual void start();
    
    /**
    * \brief Updates the slave
    *   
    */
    virtual void update()=0;
    
    /**
    * \brief Stops the slave
    *   
    */
    virtual void stop();

    /**
    * \brief Requests the slave state
    *   
    */
    virtual bool requestState( ec_state state);
    
    /**
    * \brief Checks the slave state
    *   
    */
    virtual bool checkState( ec_state state);
    
    /**
    * \brief Gets the slave state
    *   
    */
    virtual ec_state getState();
    
    /**
    * \brief Set the Distributed clock
    *   
    */
    virtual void setDC(bool active, unsigned int sync0Time, unsigned int sync0Shift);
    
    /**
    * \brief Set PDO buffer
    *   
    */
    virtual void setPDOBuffer(char * input, char * output);

    /**
    * \brief Update Master outputs
    *
    */
    boost::signals2::signal<void ()> updateMaster;


protected:
    EcSlave(ec_slavet* mem_loc);/**<  The constructor */

    ec_slavet* m_datap; /**<  A pointer to the soem slave information */
    std::string m_name; /**<  The slave name */
    unsigned int m_slave_nr; /**<  The slave number */
};
}
#endif
