/*******************************************************************************
* File Name: .h
* Version 1.10
*
* Description:
*  This private file provides constants and parameter values for the
*  SCB Component in I2C mode.
*  Please do not use this file or its content in your project.
*
* Note:
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_PVT_SPIS_1_H)
#define CY_SCB_PVT_SPIS_1_H

#include "SPIS_1.h"


/***************************************
*     Private Function Prototypes
***************************************/

/* APIs to service INTR_I2C_EC register */
#define SPIS_1_SetI2CExtClkInterruptMode(interruptMask) SPIS_1_WRITE_INTR_I2C_EC_MASK(interruptMask)
#define SPIS_1_ClearI2CExtClkInterruptSource(interruptMask) SPIS_1_CLEAR_INTR_I2C_EC(interruptMask)
#define SPIS_1_GetI2CExtClkInterruptSource()                (SPIS_1_INTR_I2C_EC_REG)
#define SPIS_1_GetI2CExtClkInterruptMode()                  (SPIS_1_INTR_I2C_EC_MASK_REG)
#define SPIS_1_GetI2CExtClkInterruptSourceMasked()          (SPIS_1_INTR_I2C_EC_MASKED_REG)

/* APIs to service INTR_SPI_EC register */
#define SPIS_1_SetSpiExtClkInterruptMode(interruptMask) SPIS_1_WRITE_INTR_SPI_EC_MASK(interruptMask)
#define SPIS_1_ClearSpiExtClkInterruptSource(interruptMask) SPIS_1_CLEAR_INTR_SPI_EC(interruptMask)
#define SPIS_1_GetExtSpiClkInterruptSource()                 (SPIS_1_INTR_SPI_EC_REG)
#define SPIS_1_GetExtSpiClkInterruptMode()                   (SPIS_1_INTR_SPI_EC_MASK_REG)
#define SPIS_1_GetExtSpiClkInterruptSourceMasked()           (SPIS_1_INTR_SPI_EC_MASKED_REG)

#if(SPIS_1_SCB_MODE_UNCONFIG_CONST_CFG)
    extern void SPIS_1_SetPins(uint32 mode, uint32 subMode, uint32 uartTxRx);
#endif /* (SPIS_1_SCB_MODE_UNCONFIG_CONST_CFG) */

void SPIS_1_DisableTxPinsInputBuffer(void);
void SPIS_1_EnableTxPinsInputBuffer(void);


/**********************************
*     Vars with External Linkage
**********************************/

extern cyisraddress SPIS_1_customIntrHandler;
extern SPIS_1_BACKUP_STRUCT SPIS_1_backup;

#if(SPIS_1_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Common config vars */
    extern uint8 SPIS_1_scbMode;
    extern uint8 SPIS_1_scbEnableWake;
    extern uint8 SPIS_1_scbEnableIntr;

    /* I2C config vars */
    extern uint8 SPIS_1_mode;
    extern uint8 SPIS_1_acceptAddr;

    /* SPI/UART config vars */
    extern volatile uint8 * SPIS_1_rxBuffer;
    extern uint8   SPIS_1_rxDataBits;
    extern uint32  SPIS_1_rxBufferSize;

    extern volatile uint8 * SPIS_1_txBuffer;
    extern uint8   SPIS_1_txDataBits;
    extern uint32  SPIS_1_txBufferSize;

    /* EZI2C config vars */
    extern uint8 SPIS_1_numberOfAddr;
    extern uint8 SPIS_1_subAddrSize;
#endif /* (SPIS_1_SCB_MODE_UNCONFIG_CONST_CFG) */

#endif /* (CY_SCB_PVT_SPIS_1_H) */


/* [] END OF FILE */
