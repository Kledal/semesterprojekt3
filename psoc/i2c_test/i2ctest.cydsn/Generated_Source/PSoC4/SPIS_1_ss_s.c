/*******************************************************************************
* File Name: SPIS_1_ss_s.c  
* Version 1.90
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "SPIS_1_ss_s.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        SPIS_1_ss_s_PC =   (SPIS_1_ss_s_PC & \
                                (uint32)(~(uint32)(SPIS_1_ss_s_DRIVE_MODE_IND_MASK << (SPIS_1_ss_s_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (SPIS_1_ss_s_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: SPIS_1_ss_s_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None 
*  
*******************************************************************************/
void SPIS_1_ss_s_Write(uint8 value) 
{
    uint8 drVal = (uint8)(SPIS_1_ss_s_DR & (uint8)(~SPIS_1_ss_s_MASK));
    drVal = (drVal | ((uint8)(value << SPIS_1_ss_s_SHIFT) & SPIS_1_ss_s_MASK));
    SPIS_1_ss_s_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: SPIS_1_ss_s_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to this drive mode.
*
* Return: 
*  None
*
*******************************************************************************/
void SPIS_1_ss_s_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(SPIS_1_ss_s__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: SPIS_1_ss_s_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro SPIS_1_ss_s_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 SPIS_1_ss_s_Read(void) 
{
    return (uint8)((SPIS_1_ss_s_PS & SPIS_1_ss_s_MASK) >> SPIS_1_ss_s_SHIFT);
}


/*******************************************************************************
* Function Name: SPIS_1_ss_s_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 SPIS_1_ss_s_ReadDataReg(void) 
{
    return (uint8)((SPIS_1_ss_s_DR & SPIS_1_ss_s_MASK) >> SPIS_1_ss_s_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(SPIS_1_ss_s_INTSTAT) 

    /*******************************************************************************
    * Function Name: SPIS_1_ss_s_ClearInterrupt
    ********************************************************************************
    *
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 SPIS_1_ss_s_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(SPIS_1_ss_s_INTSTAT & SPIS_1_ss_s_MASK);
		SPIS_1_ss_s_INTSTAT = maskedStatus;
        return maskedStatus >> SPIS_1_ss_s_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
