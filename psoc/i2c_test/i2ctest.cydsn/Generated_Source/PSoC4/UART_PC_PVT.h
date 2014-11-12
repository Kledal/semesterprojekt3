/*******************************************************************************
* File Name: .h
* Version 1.20
*
* Description:
*  This private file provides constants and parameter values for the
*  SCB Component.
*  Please do not use this file or its content in your project.
*
* Note:
*
********************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_PVT_UART_PC_H)
#define CY_SCB_PVT_UART_PC_H

#include "UART_PC.h"


/***************************************
*     Private Function Prototypes
***************************************/

/* APIs to service INTR_I2C_EC register */
#define UART_PC_SetI2CExtClkInterruptMode(interruptMask) UART_PC_WRITE_INTR_I2C_EC_MASK(interruptMask)
#define UART_PC_ClearI2CExtClkInterruptSource(interruptMask) UART_PC_CLEAR_INTR_I2C_EC(interruptMask)
#define UART_PC_GetI2CExtClkInterruptSource()                (UART_PC_INTR_I2C_EC_REG)
#define UART_PC_GetI2CExtClkInterruptMode()                  (UART_PC_INTR_I2C_EC_MASK_REG)
#define UART_PC_GetI2CExtClkInterruptSourceMasked()          (UART_PC_INTR_I2C_EC_MASKED_REG)

#if(!UART_PC_CY_SCBIP_V1_I2C_ONLY)
/* APIs to service INTR_SPI_EC register */
#define UART_PC_SetSpiExtClkInterruptMode(interruptMask) UART_PC_WRITE_INTR_SPI_EC_MASK(interruptMask)
#define UART_PC_ClearSpiExtClkInterruptSource(interruptMask) UART_PC_CLEAR_INTR_SPI_EC(interruptMask)
#define UART_PC_GetExtSpiClkInterruptSource()                 (UART_PC_INTR_SPI_EC_REG)
#define UART_PC_GetExtSpiClkInterruptMode()                   (UART_PC_INTR_SPI_EC_MASK_REG)
#define UART_PC_GetExtSpiClkInterruptSourceMasked()           (UART_PC_INTR_SPI_EC_MASKED_REG)
#endif /* (!UART_PC_CY_SCBIP_V1_I2C_ONLY) */

#if(UART_PC_SCB_MODE_UNCONFIG_CONST_CFG)
    extern void UART_PC_SetPins(uint32 mode, uint32 subMode, uint32 uartTxRx);
#endif /* (UART_PC_SCB_MODE_UNCONFIG_CONST_CFG) */


/***************************************
*     Vars with External Linkage
***************************************/

#if !defined (CY_REMOVE_UART_PC_CUSTOM_INTR_HANDLER)
    extern cyisraddress UART_PC_customIntrHandler;
#endif /* !defined (CY_REMOVE_UART_PC_CUSTOM_INTR_HANDLER) */

extern UART_PC_BACKUP_STRUCT UART_PC_backup;

#if(UART_PC_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Common config vars */
    extern uint8 UART_PC_scbMode;
    extern uint8 UART_PC_scbEnableWake;
    extern uint8 UART_PC_scbEnableIntr;

    /* I2C config vars */
    extern uint8 UART_PC_mode;
    extern uint8 UART_PC_acceptAddr;

    /* SPI/UART config vars */
    extern volatile uint8 * UART_PC_rxBuffer;
    extern uint8   UART_PC_rxDataBits;
    extern uint32  UART_PC_rxBufferSize;

    extern volatile uint8 * UART_PC_txBuffer;
    extern uint8   UART_PC_txDataBits;
    extern uint32  UART_PC_txBufferSize;

    /* EZI2C config vars */
    extern uint8 UART_PC_numberOfAddr;
    extern uint8 UART_PC_subAddrSize;
#endif /* (UART_PC_SCB_MODE_UNCONFIG_CONST_CFG) */


/***************************************
*  Conditional Macro
****************************************/

#if(UART_PC_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Define run time operation mode */
    #define UART_PC_SCB_MODE_I2C_RUNTM_CFG     (UART_PC_SCB_MODE_I2C      == UART_PC_scbMode)
    #define UART_PC_SCB_MODE_SPI_RUNTM_CFG     (UART_PC_SCB_MODE_SPI      == UART_PC_scbMode)
    #define UART_PC_SCB_MODE_UART_RUNTM_CFG    (UART_PC_SCB_MODE_UART     == UART_PC_scbMode)
    #define UART_PC_SCB_MODE_EZI2C_RUNTM_CFG   (UART_PC_SCB_MODE_EZI2C    == UART_PC_scbMode)
    #define UART_PC_SCB_MODE_UNCONFIG_RUNTM_CFG \
                                                        (UART_PC_SCB_MODE_UNCONFIG == UART_PC_scbMode)

    /* Define wakeup enable */
    #define UART_PC_SCB_WAKE_ENABLE_CHECK        (0u != UART_PC_scbEnableWake)
#endif /* (UART_PC_SCB_MODE_UNCONFIG_CONST_CFG) */

#endif /* (CY_SCB_PVT_UART_PC_H) */


/* [] END OF FILE */
