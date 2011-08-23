#ifndef _ALLPCIREGS_r10b_H_
#define _ALLPCIREGS_r10b_H_

#include "test.h"


/**
 * The purpose of this class resides in the constructor
 */
class AllPciRegs_r10b : public Test
{
public:
    AllPciRegs_r10b(int fd);
    virtual ~AllPciRegs_r10b();


protected:
    virtual bool RunCoreTest();


private:
    /**
     * Report bit position of val which is not like expectedVal
     * @param val Pass value to search against for inequality
     * @param expectedVal Pass the value to compare against for correctness
     * @return INT_MAX if they are equal, otherwise the bit position that isn't
     */
    int ReportOffendingBitPos(ULONGLONG val, ULONGLONG expectedVal);

    /**
     * Validate the specified PCI hdr register RO bits report correct values if
     * and only if they are not vendor specific.
     * @param reg Pass the register to validate
     * @return true when it validates, otherwise it's an error
     */
    bool ValidatePciHdrRegisterROAttribute(PciSpc reg);

    /**
     * Validate the specified capabilities registers' RO bits report correct
     * values if and only if they are not vendor specific.
     * @param reg Pass the register to validate
     * @return true when it validates, otherwise it's an error
     */
    bool ValidatePciCapRegisterROAttribute(PciSpc reg);

    /**
     * Validate all the registers have default values being reported for
     * the RO bits which are not vendor specific.
     */
    bool ValidateDefaultValues();

    /**
     * Validate all the registers hare RO after attempting to write to them.
     */
    bool ValidateROBitsAfterWriting();
};


#endif