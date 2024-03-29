/*******************************************************************************
* File Name: UART_PC_BOOT.c
* Version 1.20
*
* Description:
*  This file provides the source code to the API for the bootloader
*  communication support in SCB Component.
*
* Note:
*
********************************************************************************
* Copyright 2013-2013-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "UART_PC.h"

#if(UART_PC_SCB_MODE_I2C_INC)
    #include "UART_PC_I2C.h"
#endif /* (UART_PC_SCB_MODE_I2C_INC) */

#if(UART_PC_SCB_MODE_EZI2C_INC)
    #include "UART_PC_EZI2C.h"
#endif /* (UART_PC_SCB_MODE_EZI2C_INC) */

#if(UART_PC_SCB_MODE_SPI_INC || UART_PC_SCB_MODE_UART_INC)
    #include "UART_PC_SPI_UART.h"
#endif /* (UART_PC_SCB_MODE_SPI_INC || UART_PC_SCB_MODE_UART_INC) */


#if defined(CYDEV_BOOTLOADER_IO_COMP) && ((CYDEV_BOOTLOADER_IO_COMP == CyBtldr_UART_PC) || \
                                          (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Custom_Interface))

/*******************************************************************************
* Function Name: UART_PC_CyBtldrCommStart
********************************************************************************
*
* Summary:
*  Calls the CyBtldrCommStart function of the bootloader communication
*  component for the selected mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void UART_PC_CyBtldrCommStart(void)
{
    #if(UART_PC_SCB_MODE_UNCONFIG_CONST_CFG)
        if(UART_PC_SCB_MODE_I2C_RUNTM_CFG)
        {
            UART_PC_I2CCyBtldrCommStart();
        }
        else if(UART_PC_SCB_MODE_SPI_RUNTM_CFG)
        {
            UART_PC_SpiCyBtldrCommStart();
        }
        else if(UART_PC_SCB_MODE_UART_RUNTM_CFG)
        {
            UART_PC_UartCyBtldrCommStart();
        }
        else if(UART_PC_SCB_MODE_EZI2C_RUNTM_CFG)
        {
             UART_PC_EzI2CCyBtldrCommStart();
        }
        else
        {
            /* Unknown mode: do nothing */
        }
    #elif(UART_PC_SCB_MODE_I2C_CONST_CFG)
        UART_PC_I2CCyBtldrCommStart();

    #elif(UART_PC_SCB_MODE_SPI_CONST_CFG)
        UART_PC_SpiCyBtldrCommStart();

    #elif(UART_PC_SCB_MODE_UART_CONST_CFG)
        UART_PC_UartCyBtldrCommStart();

    #elif(UART_PC_SCB_MODE_EZI2C_CONST_CFG)
        UART_PC_EzI2CCyBtldrCommStart();

    #else
        /* Do nothing */

    #endif /* (UART_PC_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: UART_PC_CyBtldrCommStop
********************************************************************************
*
* Summary:
*  Calls CyBtldrCommStop function function of the bootloader communication
*  component for selected mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void UART_PC_CyBtldrCommStop(void)
{
    #if(UART_PC_SCB_MODE_UNCONFIG_CONST_CFG)
        if(UART_PC_SCB_MODE_I2C_RUNTM_CFG)
        {
            UART_PC_I2CCyBtldrCommStop();
        }
        else if(UART_PC_SCB_MODE_SPI_RUNTM_CFG)
        {
            UART_PC_SpiCyBtldrCommStop();
        }
        else if(UART_PC_SCB_MODE_UART_RUNTM_CFG)
        {
            UART_PC_UartCyBtldrCommStop();
        }
        else if(UART_PC_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            UART_PC_EzI2CCyBtldrCommStop();
        }
        else
        {
            /* Unknown mode: do nothing */
        }
    #elif(UART_PC_SCB_MODE_I2C_CONST_CFG)
        UART_PC_I2CCyBtldrCommStop();

    #elif(UART_PC_SCB_MODE_SPI_CONST_CFG)
        UART_PC_SpiCyBtldrCommStop();

    #elif(UART_PC_SCB_MODE_UART_CONST_CFG)
        UART_PC_UartCyBtldrCommStop();

    #elif(UART_PC_SCB_MODE_EZI2C_CONST_CFG)
        UART_PC_EzI2CCyBtldrCommStop();

    #else
        /* Do nothing */

    #endif /* (UART_PC_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: UART_PC_CyBtldrCommReset
********************************************************************************
*
* Summary:
*  Calls the CyBtldrCommReset function of the bootloader communication
*  component for the selected mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void UART_PC_CyBtldrCommReset(void)
{
    #if(UART_PC_SCB_MODE_UNCONFIG_CONST_CFG)
        if(UART_PC_SCB_MODE_I2C_RUNTM_CFG)
        {
            UART_PC_I2CCyBtldrCommReset();
        }
        else if(UART_PC_SCB_MODE_SPI_RUNTM_CFG)
        {
            UART_PC_SpiCyBtldrCommReset();
        }
        else if(UART_PC_SCB_MODE_UART_RUNTM_CFG)
        {
            UART_PC_UartCyBtldrCommReset();
        }
        else if(UART_PC_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            UART_PC_EzI2CCyBtldrCommReset();
        }
        else
        {
            /* Unknown mode: do nothing */
        }
    #elif(UART_PC_SCB_MODE_I2C_CONST_CFG)
        UART_PC_I2CCyBtldrCommReset();

    #elif(UART_PC_SCB_MODE_SPI_CONST_CFG)
        UART_PC_SpiCyBtldrCommReset();

    #elif(UART_PC_SCB_MODE_UART_CONST_CFG)
        UART_PC_UartCyBtldrCommReset();

    #elif(UART_PC_SCB_MODE_EZI2C_CONST_CFG)
        UART_PC_EzI2CCyBtldrCommReset();

    #else
        /* Do nothing */

    #endif /* (UART_PC_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: UART_PC_CyBtldrCommRead
********************************************************************************
*
* Summary:
*  Calls the CyBtldrCommRead function of the bootloader communication
*  component for the selected mode.
*
* Parameters:
*  pData:    Pointer to storage for the block of data to be read from the
*            bootloader host
*  size:     Number of bytes to be read.
*  count:    Pointer to the variable to write the number of bytes actually
*            read.
*  timeOut:  Number of units in 10 ms to wait before returning because of a
*            timeout.
*
* Return:
*  Returns CYRET_SUCCESS if no problem was encountered or returns the value
*  that best describes the problem.
*
*******************************************************************************/
cystatus UART_PC_CyBtldrCommRead(uint8 pData[], uint16 size, uint16 * count, uint8 timeOut)
{
    cystatus status;

    #if(UART_PC_SCB_MODE_UNCONFIG_CONST_CFG)
        if(UART_PC_SCB_MODE_I2C_RUNTM_CFG)
        {
            status = UART_PC_I2CCyBtldrCommRead(pData, size, count, timeOut);
        }
        else if(UART_PC_SCB_MODE_SPI_RUNTM_CFG)
        {
            status = UART_PC_SpiCyBtldrCommRead(pData, size, count, timeOut);
        }
        else if(UART_PC_SCB_MODE_UART_RUNTM_CFG)
        {
            status = UART_PC_UartCyBtldrCommRead(pData, size, count, timeOut);
        }
        else if(UART_PC_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            status = UART_PC_EzI2CCyBtldrCommRead(pData, size, count, timeOut);
        }
        else
        {
            status = CYRET_INVALID_STATE; /* Unknown mode: return status */
        }

    #elif(UART_PC_SCB_MODE_I2C_CONST_CFG)
        status = UART_PC_I2CCyBtldrCommRead(pData, size, count, timeOut);

    #elif(UART_PC_SCB_MODE_SPI_CONST_CFG)
        status = UART_PC_SpiCyBtldrCommRead(pData, size, count, timeOut);

    #elif(UART_PC_SCB_MODE_UART_CONST_CFG)
        status = UART_PC_UartCyBtldrCommRead(pData, size, count, timeOut);

    #elif(UART_PC_SCB_MODE_EZI2C_CONST_CFG)
        status = UART_PC_EzI2CCyBtldrCommRead(pData, size, count, timeOut);

    #else
        status = CYRET_INVALID_STATE; /* Unknown mode: return status */

    #endif /* (UART_PC_SCB_MODE_UNCONFIG_CONST_CFG) */

    return(status);
}


/*******************************************************************************
* Function Name: UART_PC_CyBtldrCommWrite
********************************************************************************
*
* Summary:
*  Calls the CyBtldrCommWrite  function of the bootloader communication
*  component for the selected mode.
*
* Parameters:
*  pData:    Pointer to the block of data to be written to the bootloader host.
*  size:     Number of bytes to be written.
*  count:    Pointer to the variable to write the number of bytes actually
*            written.
*  timeOut:  Number of units in 10 ms to wait before returning because of a
*            timeout.
*
* Return:
*  Returns CYRET_SUCCESS if no problem was encountered or returns the value
*  that best describes the problem.
*
*******************************************************************************/
cystatus UART_PC_CyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut)
{
    cystatus status;

    #if(UART_PC_SCB_MODE_UNCONFIG_CONST_CFG)
        if(UART_PC_SCB_MODE_I2C_RUNTM_CFG)
        {
            status = UART_PC_I2CCyBtldrCommWrite(pData, size, count, timeOut);
        }
        else if(UART_PC_SCB_MODE_SPI_RUNTM_CFG)
        {
            status = UART_PC_SpiCyBtldrCommWrite(pData, size, count, timeOut);
        }
        else if(UART_PC_SCB_MODE_UART_RUNTM_CFG)
        {
            status = UART_PC_UartCyBtldrCommWrite(pData, size, count, timeOut);
        }
        else if(UART_PC_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            status = UART_PC_EzI2CCyBtldrCommWrite(pData, size, count, timeOut);
        }
        else
        {
            status = CYRET_INVALID_STATE; /* Unknown mode */
        }
    #elif(UART_PC_SCB_MODE_I2C_CONST_CFG)
        status = UART_PC_I2CCyBtldrCommWrite(pData, size, count, timeOut);

    #elif(UART_PC_SCB_MODE_SPI_CONST_CFG)
        status = UART_PC_SpiCyBtldrCommWrite(pData, size, count, timeOut);

    #elif(UART_PC_SCB_MODE_UART_CONST_CFG)
        status = UART_PC_UartCyBtldrCommWrite(pData, size, count, timeOut);

    #elif(UART_PC_SCB_MODE_EZI2C_CONST_CFG)
        status = UART_PC_EzI2CCyBtldrCommWrite(pData, size, count, timeOut);

    #else
        status = CYRET_INVALID_STATE; /* Unknown mode */

    #endif /* (UART_PC_SCB_MODE_UNCONFIG_CONST_CFG) */

    return(status);
}

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && ((CYDEV_BOOTLOADER_IO_COMP == CyBtldr_UART_PC) || \
                                                    (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Custom_Interface)) */


/* [] END OF FILE */
