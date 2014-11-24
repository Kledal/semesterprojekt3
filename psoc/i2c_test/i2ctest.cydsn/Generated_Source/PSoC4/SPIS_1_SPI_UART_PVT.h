/*******************************************************************************
* File Name: SPIS_1_SPI_UART_PVT.h
* Version 1.10
*
* Description:
*  This private file provides constants and parameter values for the
*  SCB Component in SPI and UART modes.
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

#if !defined(CY_SCB_SPI_UART_PVT_SPIS_1_H)
#define CY_SCB_SPI_UART_PVT_SPIS_1_H

#include "SPIS_1_SPI_UART.h"


/***************************************
*     Internal Global Vars
***************************************/

#if(SPIS_1_INTERNAL_RX_SW_BUFFER_CONST)
    extern volatile uint32  SPIS_1_rxBufferHead;
    extern volatile uint32  SPIS_1_rxBufferTail;
    extern volatile uint8   SPIS_1_rxBufferOverflow;
#endif /* (SPIS_1_INTERNAL_RX_SW_BUFFER_CONST) */

#if(SPIS_1_INTERNAL_TX_SW_BUFFER_CONST)
    extern volatile uint32  SPIS_1_txBufferHead;
    extern volatile uint32  SPIS_1_txBufferTail;
#endif /* (SPIS_1_INTERNAL_TX_SW_BUFFER_CONST) */

#if(SPIS_1_INTERNAL_RX_SW_BUFFER)
    extern volatile uint16 SPIS_1_rxBufferInternal[SPIS_1_RX_BUFFER_SIZE];
#endif /* (SPIS_1_INTERNAL_RX_SW_BUFFER) */

#if(SPIS_1_INTERNAL_TX_SW_BUFFER)
    extern volatile uint16 SPIS_1_txBufferInternal[SPIS_1_TX_BUFFER_SIZE];
#endif /* (SPIS_1_INTERNAL_TX_SW_BUFFER) */


/***************************************
*     Private Function Prototypes
***************************************/

#if(SPIS_1_SCB_MODE_SPI_CONST_CFG)
    void SPIS_1_SpiInit(void);
#endif /* (SPIS_1_SCB_MODE_SPI_CONST_CFG) */

#if(SPIS_1_SPI_WAKE_ENABLE_CONST)
    void SPIS_1_SpiSaveConfig(void);
    void SPIS_1_SpiRestoreConfig(void);
#endif /* (SPIS_1_SPI_WAKE_ENABLE_CONST) */

#if(SPIS_1_SCB_MODE_UART_CONST_CFG)
    void SPIS_1_UartInit(void);
#endif /* (SPIS_1_SCB_MODE_UART_CONST_CFG) */

#if(SPIS_1_UART_WAKE_ENABLE_CONST)
    void SPIS_1_UartSaveConfig(void);
    void SPIS_1_UartRestoreConfig(void);
#endif /* (SPIS_1_UART_WAKE_ENABLE_CONST) */

/* Interrupt processing */
#define SPIS_1_SpiUartEnableIntRx(intSourceMask)  SPIS_1_SetRxInterruptMode(intSourceMask)
#define SPIS_1_SpiUartEnableIntTx(intSourceMask)  SPIS_1_SetTxInterruptMode(intSourceMask)
uint32 SPIS_1_SpiUartDisableIntRx(void);
uint32 SPIS_1_SpiUartDisableIntTx(void);

#endif /* (CY_SCB_SPI_UART_PVT_SPIS_1_H) */


/* [] END OF FILE */
