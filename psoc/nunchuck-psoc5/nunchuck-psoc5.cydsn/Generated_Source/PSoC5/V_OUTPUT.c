/*******************************************************************************
* File Name: V_OUTPUT.c  
* Version 2.0
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "V_OUTPUT.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 V_OUTPUT__PORT == 15 && ((V_OUTPUT__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: V_OUTPUT_Write
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
void V_OUTPUT_Write(uint8 value) 
{
    uint8 staticBits = (V_OUTPUT_DR & (uint8)(~V_OUTPUT_MASK));
    V_OUTPUT_DR = staticBits | ((uint8)(value << V_OUTPUT_SHIFT) & V_OUTPUT_MASK);
}


/*******************************************************************************
* Function Name: V_OUTPUT_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  V_OUTPUT_DM_STRONG     Strong Drive 
*  V_OUTPUT_DM_OD_HI      Open Drain, Drives High 
*  V_OUTPUT_DM_OD_LO      Open Drain, Drives Low 
*  V_OUTPUT_DM_RES_UP     Resistive Pull Up 
*  V_OUTPUT_DM_RES_DWN    Resistive Pull Down 
*  V_OUTPUT_DM_RES_UPDWN  Resistive Pull Up/Down 
*  V_OUTPUT_DM_DIG_HIZ    High Impedance Digital 
*  V_OUTPUT_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void V_OUTPUT_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(V_OUTPUT_0, mode);
}


/*******************************************************************************
* Function Name: V_OUTPUT_Read
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
*  Macro V_OUTPUT_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 V_OUTPUT_Read(void) 
{
    return (V_OUTPUT_PS & V_OUTPUT_MASK) >> V_OUTPUT_SHIFT;
}


/*******************************************************************************
* Function Name: V_OUTPUT_ReadDataReg
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
uint8 V_OUTPUT_ReadDataReg(void) 
{
    return (V_OUTPUT_DR & V_OUTPUT_MASK) >> V_OUTPUT_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(V_OUTPUT_INTSTAT) 

    /*******************************************************************************
    * Function Name: V_OUTPUT_ClearInterrupt
    ********************************************************************************
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
    uint8 V_OUTPUT_ClearInterrupt(void) 
    {
        return (V_OUTPUT_INTSTAT & V_OUTPUT_MASK) >> V_OUTPUT_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
