/*******************************************************************************
* File Name: SPIS_1_SCB_IRQ.c  
* Version 1.70
*
*  Description:
*   API for controlling the state of an interrupt.
*
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/


#include <cydevice_trm.h>
#include <CyLib.h>
#include <SPIS_1_SCB_IRQ.h>

#if !defined(SPIS_1_SCB_IRQ__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START SPIS_1_SCB_IRQ_intc` */

/* `#END` */

extern cyisraddress CyRamVectors[CYINT_IRQ_BASE + CY_NUM_INTERRUPTS];

/* Declared in startup, used to set unused interrupts to. */
CY_ISR_PROTO(IntDefaultHandler);


/*******************************************************************************
* Function Name: SPIS_1_SCB_IRQ_Start
********************************************************************************
*
* Summary:
*  Set up the interrupt and enable it.
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
void SPIS_1_SCB_IRQ_Start(void)
{
    /* For all we know the interrupt is active. */
    SPIS_1_SCB_IRQ_Disable();

    /* Set the ISR to point to the SPIS_1_SCB_IRQ Interrupt. */
    SPIS_1_SCB_IRQ_SetVector(&SPIS_1_SCB_IRQ_Interrupt);

    /* Set the priority. */
    SPIS_1_SCB_IRQ_SetPriority((uint8)SPIS_1_SCB_IRQ_INTC_PRIOR_NUMBER);

    /* Enable it. */
    SPIS_1_SCB_IRQ_Enable();
}


/*******************************************************************************
* Function Name: SPIS_1_SCB_IRQ_StartEx
********************************************************************************
*
* Summary:
*  Set up the interrupt and enable it.
*
* Parameters:  
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void SPIS_1_SCB_IRQ_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    SPIS_1_SCB_IRQ_Disable();

    /* Set the ISR to point to the SPIS_1_SCB_IRQ Interrupt. */
    SPIS_1_SCB_IRQ_SetVector(address);

    /* Set the priority. */
    SPIS_1_SCB_IRQ_SetPriority((uint8)SPIS_1_SCB_IRQ_INTC_PRIOR_NUMBER);

    /* Enable it. */
    SPIS_1_SCB_IRQ_Enable();
}


/*******************************************************************************
* Function Name: SPIS_1_SCB_IRQ_Stop
********************************************************************************
*
* Summary:
*   Disables and removes the interrupt.
*
* Parameters:  
*
* Return:
*   None
*
*******************************************************************************/
void SPIS_1_SCB_IRQ_Stop(void)
{
    /* Disable this interrupt. */
    SPIS_1_SCB_IRQ_Disable();

    /* Set the ISR to point to the passive one. */
    SPIS_1_SCB_IRQ_SetVector(&IntDefaultHandler);
}


/*******************************************************************************
* Function Name: SPIS_1_SCB_IRQ_Interrupt
********************************************************************************
*
* Summary:
*   The default Interrupt Service Routine for SPIS_1_SCB_IRQ.
*
*   Add custom code between the coments to keep the next version of this file
*   from over writting your code.
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
CY_ISR(SPIS_1_SCB_IRQ_Interrupt)
{
    /*  Place your Interrupt code here. */
    /* `#START SPIS_1_SCB_IRQ_Interrupt` */

    /* `#END` */
}


/*******************************************************************************
* Function Name: SPIS_1_SCB_IRQ_SetVector
********************************************************************************
*
* Summary:
*   Change the ISR vector for the Interrupt. Note calling SPIS_1_SCB_IRQ_Start
*   will override any effect this method would have had. To set the vector 
*   before the component has been started use SPIS_1_SCB_IRQ_StartEx instead.
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void SPIS_1_SCB_IRQ_SetVector(cyisraddress address)
{
    CyRamVectors[CYINT_IRQ_BASE + SPIS_1_SCB_IRQ__INTC_NUMBER] = address;
}


/*******************************************************************************
* Function Name: SPIS_1_SCB_IRQ_GetVector
********************************************************************************
*
* Summary:
*   Gets the "address" of the current ISR vector for the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   Address of the ISR in the interrupt vector table.
*
*******************************************************************************/
cyisraddress SPIS_1_SCB_IRQ_GetVector(void)
{
    return CyRamVectors[CYINT_IRQ_BASE + SPIS_1_SCB_IRQ__INTC_NUMBER];
}


/*******************************************************************************
* Function Name: SPIS_1_SCB_IRQ_SetPriority
********************************************************************************
*
* Summary:
*   Sets the Priority of the Interrupt. Note calling SPIS_1_SCB_IRQ_Start
*   or SPIS_1_SCB_IRQ_StartEx will override any effect this method would 
*   have had. This method should only be called after SPIS_1_SCB_IRQ_Start or 
*   SPIS_1_SCB_IRQ_StartEx has been called. To set the initial
*   priority for the component use the cydwr file in the tool.
*
* Parameters:
*   priority: Priority of the interrupt. 0 - 3, 0 being the highest.
*
* Return:
*   None
*
*******************************************************************************/
void SPIS_1_SCB_IRQ_SetPriority(uint8 priority)
{
	uint8 interruptState;
    uint32 priorityOffset = ((SPIS_1_SCB_IRQ__INTC_NUMBER % 4u) * 8u) + 6u;
    
	interruptState = CyEnterCriticalSection();
    *SPIS_1_SCB_IRQ_INTC_PRIOR = (*SPIS_1_SCB_IRQ_INTC_PRIOR & (uint32)(~SPIS_1_SCB_IRQ__INTC_PRIOR_MASK)) |
                                    ((uint32)priority << priorityOffset);
	CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: SPIS_1_SCB_IRQ_GetPriority
********************************************************************************
*
* Summary:
*   Gets the Priority of the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   Priority of the interrupt. 0 - 3, 0 being the highest.
*
*******************************************************************************/
uint8 SPIS_1_SCB_IRQ_GetPriority(void)
{
    uint32 priority;
	uint32 priorityOffset = ((SPIS_1_SCB_IRQ__INTC_NUMBER % 4u) * 8u) + 6u;

    priority = (*SPIS_1_SCB_IRQ_INTC_PRIOR & SPIS_1_SCB_IRQ__INTC_PRIOR_MASK) >> priorityOffset;

    return (uint8)priority;
}


/*******************************************************************************
* Function Name: SPIS_1_SCB_IRQ_Enable
********************************************************************************
*
* Summary:
*   Enables the interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void SPIS_1_SCB_IRQ_Enable(void)
{
    /* Enable the general interrupt. */
    *SPIS_1_SCB_IRQ_INTC_SET_EN = SPIS_1_SCB_IRQ__INTC_MASK;
}


/*******************************************************************************
* Function Name: SPIS_1_SCB_IRQ_GetState
********************************************************************************
*
* Summary:
*   Gets the state (enabled, disabled) of the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   1 if enabled, 0 if disabled.
*
*******************************************************************************/
uint8 SPIS_1_SCB_IRQ_GetState(void)
{
    /* Get the state of the general interrupt. */
    return ((*SPIS_1_SCB_IRQ_INTC_SET_EN & (uint32)SPIS_1_SCB_IRQ__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: SPIS_1_SCB_IRQ_Disable
********************************************************************************
*
* Summary:
*   Disables the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void SPIS_1_SCB_IRQ_Disable(void)
{
    /* Disable the general interrupt. */
    *SPIS_1_SCB_IRQ_INTC_CLR_EN = SPIS_1_SCB_IRQ__INTC_MASK;
}


/*******************************************************************************
* Function Name: SPIS_1_SCB_IRQ_SetPending
********************************************************************************
*
* Summary:
*   Causes the Interrupt to enter the pending state, a software method of
*   generating the interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void SPIS_1_SCB_IRQ_SetPending(void)
{
    *SPIS_1_SCB_IRQ_INTC_SET_PD = SPIS_1_SCB_IRQ__INTC_MASK;
}


/*******************************************************************************
* Function Name: SPIS_1_SCB_IRQ_ClearPending
********************************************************************************
*
* Summary:
*   Clears a pending interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void SPIS_1_SCB_IRQ_ClearPending(void)
{
    *SPIS_1_SCB_IRQ_INTC_CLR_PD = SPIS_1_SCB_IRQ__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
