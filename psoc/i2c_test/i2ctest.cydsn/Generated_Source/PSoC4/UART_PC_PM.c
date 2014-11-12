/*******************************************************************************
* File Name: UART_PC_PM.c
* Version 1.20
*
* Description:
*  This file provides the source code to the Power Management support for
*  the SCB Component.
*
* Note:
*
********************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "UART_PC.h"
#include "UART_PC_PVT.h"

#if(UART_PC_SCB_MODE_I2C_INC)
    #include "UART_PC_I2C_PVT.h"
#endif /* (UART_PC_SCB_MODE_I2C_INC) */

#if(UART_PC_SCB_MODE_EZI2C_INC)
    #include "UART_PC_EZI2C_PVT.h"
#endif /* (UART_PC_SCB_MODE_EZI2C_INC) */

#if(UART_PC_SCB_MODE_SPI_INC || UART_PC_SCB_MODE_UART_INC)
    #include "UART_PC_SPI_UART_PVT.h"
#endif /* (UART_PC_SCB_MODE_SPI_INC || UART_PC_SCB_MODE_UART_INC) */


/***************************************
*   Backup Structure declaration
***************************************/

#if(UART_PC_SCB_MODE_UNCONFIG_CONST_CFG || \
   (UART_PC_SCB_MODE_I2C_CONST_CFG   && (!UART_PC_I2C_WAKE_ENABLE_CONST))   || \
   (UART_PC_SCB_MODE_EZI2C_CONST_CFG && (!UART_PC_EZI2C_WAKE_ENABLE_CONST)) || \
   (UART_PC_SCB_MODE_SPI_CONST_CFG   && (!UART_PC_SPI_WAKE_ENABLE_CONST))   || \
   (UART_PC_SCB_MODE_UART_CONST_CFG  && (!UART_PC_UART_WAKE_ENABLE_CONST)))

    UART_PC_BACKUP_STRUCT UART_PC_backup =
    {
        0u, /* enableState */
    };
#endif


/*******************************************************************************
* Function Name: UART_PC_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component to enter Deep Sleep.
*  The “Enable wakeup from Sleep Mode” selection has an influence on
*  this function implementation.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void UART_PC_Sleep(void)
{
#if(UART_PC_SCB_MODE_UNCONFIG_CONST_CFG)

    if(UART_PC_SCB_WAKE_ENABLE_CHECK)
    {
        if(UART_PC_SCB_MODE_I2C_RUNTM_CFG)
        {
            UART_PC_I2CSaveConfig();
        }
        else if(UART_PC_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            UART_PC_EzI2CSaveConfig();
        }
    #if(!UART_PC_CY_SCBIP_V1_I2C_ONLY)
        else if(UART_PC_SCB_MODE_SPI_RUNTM_CFG)
        {
            UART_PC_SpiSaveConfig();
        }
        else if(UART_PC_SCB_MODE_UART_RUNTM_CFG)
        {
            UART_PC_UartSaveConfig();
        }
    #endif /* (!UART_PC_CY_SCBIP_V1_I2C_ONLY) */
        else
        {
            /* Unknown mode: do nothing */
        }
    }
    else
    {
        UART_PC_backup.enableState = (uint8) UART_PC_GET_CTRL_ENABLED;

        if(0u != UART_PC_backup.enableState)
        {
            UART_PC_Stop();
        }
    }

#else

    #if (UART_PC_SCB_MODE_I2C_CONST_CFG && UART_PC_I2C_WAKE_ENABLE_CONST)
        UART_PC_I2CSaveConfig();

    #elif (UART_PC_SCB_MODE_EZI2C_CONST_CFG && UART_PC_EZI2C_WAKE_ENABLE_CONST)
        UART_PC_EzI2CSaveConfig();

    #elif (UART_PC_SCB_MODE_SPI_CONST_CFG && UART_PC_SPI_WAKE_ENABLE_CONST)
        UART_PC_SpiSaveConfig();

    #elif (UART_PC_SCB_MODE_UART_CONST_CFG && UART_PC_UART_WAKE_ENABLE_CONST)
        UART_PC_UartSaveConfig();

    #else

        UART_PC_backup.enableState = (uint8) UART_PC_GET_CTRL_ENABLED;

        if(0u != UART_PC_backup.enableState)
        {
            UART_PC_Stop();
        }

    #endif /* defined (UART_PC_SCB_MODE_I2C_CONST_CFG) && (UART_PC_I2C_WAKE_ENABLE_CONST) */

#endif /* (UART_PC_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: UART_PC_Wakeup
********************************************************************************
*
* Summary:
*  Prepares the component for the Active mode operation after exiting Deep Sleep.
*  The “Enable wakeup from Sleep Mode” option has an influence on this function
*  implementation.
*  This function should not be called after exiting Sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void UART_PC_Wakeup(void)
{
#if(UART_PC_SCB_MODE_UNCONFIG_CONST_CFG)

    if(UART_PC_SCB_WAKE_ENABLE_CHECK)
    {
        if(UART_PC_SCB_MODE_I2C_RUNTM_CFG)
        {
            UART_PC_I2CRestoreConfig();
        }
        else if(UART_PC_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            UART_PC_EzI2CRestoreConfig();
        }
    #if(!UART_PC_CY_SCBIP_V1_I2C_ONLY)
        else if(UART_PC_SCB_MODE_SPI_RUNTM_CFG)
        {
            UART_PC_SpiRestoreConfig();
        }
        else if(UART_PC_SCB_MODE_UART_RUNTM_CFG)
        {
            UART_PC_UartRestoreConfig();
        }
    #endif /* (!UART_PC_CY_SCBIP_V1_I2C_ONLY) */
        else
        {
            /* Unknown mode: do nothing */
        }
    }
    else
    {
        if(0u != UART_PC_backup.enableState)
        {
            UART_PC_Enable();
        }
    }

#else

    #if (UART_PC_SCB_MODE_I2C_CONST_CFG  && UART_PC_I2C_WAKE_ENABLE_CONST)
        UART_PC_I2CRestoreConfig();

    #elif (UART_PC_SCB_MODE_EZI2C_CONST_CFG && UART_PC_EZI2C_WAKE_ENABLE_CONST)
        UART_PC_EzI2CRestoreConfig();

    #elif (UART_PC_SCB_MODE_SPI_CONST_CFG && UART_PC_SPI_WAKE_ENABLE_CONST)
        UART_PC_SpiRestoreConfig();

    #elif (UART_PC_SCB_MODE_UART_CONST_CFG && UART_PC_UART_WAKE_ENABLE_CONST)
        UART_PC_UartRestoreConfig();

    #else

        if(0u != UART_PC_backup.enableState)
        {
            UART_PC_Enable();
        }

    #endif /* (UART_PC_I2C_WAKE_ENABLE_CONST) */

#endif /* (UART_PC_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/* [] END OF FILE */
